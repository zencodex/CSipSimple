/*
    This file implements the ZRTP SRTP C-to-C++ wrapper.
    Copyright (C) 2010  Werner Dittmann

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#include <CryptoContext.h>
#include <ZsrtpCWrapper.h>
#include <pjmedia/rtp.h>
#include <pjmedia/errno.h>
#include <arpa/inet.h>

ZsrtpContext* zsrtp_CreateWrapper(uint32_t ssrc, int32_t roc,
                                  int64_t  keyDerivRate,
                                  const  int32_t ealg,
                                  const  int32_t aalg,
                                  uint8_t* masterKey,
                                  int32_t  masterKeyLength,
                                  uint8_t* masterSalt,
                                  int32_t  masterSaltLength,
                                  int32_t  ekeyl,
                                  int32_t  akeyl,
                                  int32_t  skeyl,
                                  int32_t  tagLength)
{
    ZsrtpContext* zc = new ZsrtpContext;
    zc->srtp = new CryptoContext(ssrc, roc, keyDerivRate, ealg, aalg,
                                 masterKey, masterKeyLength, masterSalt,
                                 masterSaltLength, ekeyl, akeyl, skeyl,
                                 tagLength);
    return zc;
}

void zsrtp_DestroyWrapper (ZsrtpContext* ctx)
{

    if (ctx == NULL)
        return;

    delete ctx->srtp;
    ctx->srtp = NULL;

    delete ctx;
}

/*
 * Private RTP decoding, copied from rtp.c. Need this because of
 * different padding handling for SRTP.
 */
#define RTP_VERSION   2
static pj_status_t zsrtp_decode_rtp(uint8_t* pkt, int32_t pkt_len,
                                   const pjmedia_rtp_hdr **hdr,
                                   uint8_t** payload,
                                   int32_t *payloadlen)
{
    int offset;


    /* Assume RTP header at the start of packet. We'll verify this later. */
    *hdr = (pjmedia_rtp_hdr*)pkt;

    /* Check RTP header sanity. */
    if ((*hdr)->v != RTP_VERSION) {
        return PJMEDIA_RTP_EINVER;
    }

    /* Payload is located right after header plus CSRC */
    offset = sizeof(pjmedia_rtp_hdr) + ((*hdr)->cc * sizeof(pj_uint32_t));

    /* Adjust offset if RTP extension is used. */
    if ((*hdr)->x) {
        pjmedia_rtp_ext_hdr *ext = (pjmedia_rtp_ext_hdr*)
                                   (((pj_uint8_t*)pkt) + offset);
        offset += ((pj_ntohs(ext->length)+1) * sizeof(pj_uint32_t));
    }

    /* Check that offset is less than packet size */
    if (offset > pkt_len)
        return PJMEDIA_RTP_EINLEN;

    /* Find and set payload. */
    *payload = pkt + offset;
    *payloadlen = pkt_len - offset;

    return PJ_SUCCESS;
}

int32_t zsrtp_protect(ZsrtpContext* ctx, uint8_t* buffer, int32_t length,
                      int32_t* newLength)
{
    CryptoContext* pcc = ctx->srtp;
    const pjmedia_rtp_hdr *hdr;
    uint8_t* payload;
    int32_t payloadlen;
    pj_status_t rc;
    uint16_t seqnum;
    uint32_t ssrc;


    if (pcc == NULL) {
        return 0;
    }
    rc = zsrtp_decode_rtp(buffer, length, &hdr, &payload, &payloadlen);

    seqnum = hdr->seq;
    seqnum = ntohs(seqnum);

    /* Encrypt the packet */
    uint64_t index = ((uint64_t)pcc->getRoc() << 16) | (uint64_t)seqnum;

    ssrc = hdr->ssrc;
    ssrc = ntohl(ssrc);
    pcc->srtpEncrypt(buffer, payload, payloadlen, index, ssrc);

    // NO MKI support yet - here we assume MKI is zero. To build in MKI
    // take MKI length into account when storing the authentication tag.

    /* Compute MAC and store at end of RTP packet data */
    pcc->srtpAuthenticate(buffer, length, pcc->getRoc(), buffer+length);

    *newLength = length + pcc->getTagLength();
    
    /* Update the ROC if necessary */
    if (seqnum == 0xFFFF ) {
        pcc->setRoc(pcc->getRoc() + 1);
    }
    return 1;
}

int32_t zsrtp_unprotect(ZsrtpContext* ctx, uint8_t* buffer, int32_t length,
                        int32_t* newLength)
{
    CryptoContext* pcc = ctx->srtp;
    const pjmedia_rtp_hdr *hdr;
    uint8_t* payload;
    int32_t payloadlen;
    pj_status_t rc;
    uint16_t seqnum;
    uint32_t ssrc;

    if (pcc == NULL) {
        return 0;
    }

    rc = zsrtp_decode_rtp(buffer, length, &hdr, &payload, &payloadlen);

    /*
     * This is the setting of the packet data when we come to this
     * point:
     *
     * length:      complete length of received data
     * buffer:      points to data as received from network
     * hdrSize:     length of header including header extension
     * payloadlen:  length of data excluding hdrSize and padding
     *
     * Because this is an SRTP packet we need to adjust some values here.
     * The SRTP MKI and authentication data is always at the end of a
     * packet. Thus compute the position of this data.
     */

    uint32_t srtpDataIndex = length - (pcc->getTagLength() + pcc->getMkiLength());

    // now adjust length because some RTP functions rely on the fact that
    // total is the full length of data without SRTP data.
    length -= pcc->getTagLength() + pcc->getMkiLength();
    *newLength = length;
    
    // recompute payloadlen by subtracting SRTP data
    payloadlen -= pcc->getTagLength() + pcc->getMkiLength();

    // unused??
    // const uint8* mki = getRawPacket() + srtpDataIndex;
    uint8_t* tag = buffer + srtpDataIndex + pcc->getMkiLength();

    /* Replay control */
    seqnum = hdr->seq;
    seqnum = ntohs(seqnum);
    if (!pcc->checkReplay(seqnum)) {
        return -2;
    }
    /* Guess the index */
    uint64_t guessedIndex = pcc->guessIndex(seqnum);

    uint32_t guessedRoc = guessedIndex >> 16;
    uint8_t* mac = new uint8_t[pcc->getTagLength()];

    pcc->srtpAuthenticate(buffer, length, guessedRoc, mac);
    if (memcmp(tag, mac, pcc->getTagLength()) != 0) {
        delete[] mac;
        return -1;
    }
    delete[] mac;

    /* Decrypt the content */
    ssrc = hdr->ssrc;
    ssrc = ntohl(ssrc);
    pcc->srtpEncrypt(buffer, payload, payloadlen, guessedIndex, ssrc);

    /* Update the Crypto-context */
    pcc->update(seqnum);

    return 1;
}

void zsrtp_newCryptoContextForSSRC(ZsrtpContext* ctx, uint32_t ssrc,
                                   int32_t roc, int64_t keyDerivRate)
{
    CryptoContext* newCrypto = ctx->srtp->newCryptoContextForSSRC(ssrc, 0, 0L);
    ctx->srtp = newCrypto;
}

void zsrtp_deriveSrtpKeys(ZsrtpContext* ctx, uint64_t index)
{
    ctx->srtp->deriveSrtpKeys(index);
}
