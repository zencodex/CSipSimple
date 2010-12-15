/* $Id$ */
/*
 * Copyright (C) 2010 Werner Dittmann
 * This is the pjmedia ZRTP transport module.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <transport_zrtp.h>

/* Code only if ZRTP support */

#include <pjmedia/endpoint.h>
#include <pjlib.h>
#include <pjlib-util.h>
#include <ZsrtpCWrapper.h>

#define THIS_FILE "transport_zrtp.c"

/* Transport functions prototypes */
static pj_status_t transport_get_info(pjmedia_transport *tp,
                                      pjmedia_transport_info *info);
static pj_status_t transport_attach(pjmedia_transport *tp,
                                    void *user_data,
                                    const pj_sockaddr_t *rem_addr,
                                    const pj_sockaddr_t *rem_rtcp,
                                    unsigned addr_len,
                                    void (*rtp_cb)(void*,
                                                   void*,
                                                   pj_ssize_t),
                                    void (*rtcp_cb)(void*,
                                                    void*,
                                                    pj_ssize_t));
static void    transport_detach(pjmedia_transport *tp,
                                void *strm);
static pj_status_t transport_send_rtp(pjmedia_transport *tp,
                                      const void *pkt,
                                      pj_size_t size);
static pj_status_t transport_send_rtcp(pjmedia_transport *tp,
                                       const void *pkt,
                                       pj_size_t size);
static pj_status_t transport_send_rtcp2(pjmedia_transport *tp,
                                        const pj_sockaddr_t *addr,
                                        unsigned addr_len,
                                        const void *pkt,
                                        pj_size_t size);
static pj_status_t transport_media_create(pjmedia_transport *tp,
        pj_pool_t *sdp_pool,
        unsigned options,
        const pjmedia_sdp_session *rem_sdp,
        unsigned media_index);
static pj_status_t transport_encode_sdp(pjmedia_transport *tp,
                                        pj_pool_t *sdp_pool,
                                        pjmedia_sdp_session *local_sdp,
                                        const pjmedia_sdp_session *rem_sdp,
                                        unsigned media_index);
static pj_status_t transport_media_start(pjmedia_transport *tp,
        pj_pool_t *pool,
        const pjmedia_sdp_session *local_sdp,
        const pjmedia_sdp_session *rem_sdp,
        unsigned media_index);
static pj_status_t transport_media_stop(pjmedia_transport *tp);
static pj_status_t transport_simulate_lost(pjmedia_transport *tp,
        pjmedia_dir dir,
        unsigned pct_lost);
static pj_status_t transport_destroy(pjmedia_transport *tp);


/* The transport operations */
static struct pjmedia_transport_op tp_zrtp_op =
{
    &transport_get_info,
    &transport_attach,
    &transport_detach,
    &transport_send_rtp,
    &transport_send_rtcp,
    &transport_send_rtcp2,
    &transport_media_create,
    &transport_encode_sdp,
    &transport_media_start,
    &transport_media_stop,
    &transport_simulate_lost,
    &transport_destroy
};

/* The transport zrtp instance */
struct tp_zrtp
{
    pjmedia_transport base;
    pj_pool_t       *pool;

    /* Stream information. */
    void        *stream_user_data;
    void (*stream_rtp_cb)(void *user_data,
                          void *pkt,
                          pj_ssize_t);
    void (*stream_rtcp_cb)(void *user_data,
                           void *pkt,
                           pj_ssize_t);

    /* Add your own member here.. */
    uint64_t protect;
    uint64_t unprotect;
    int32_t  unprotect_err;
    int32_t refcount;
    pj_timer_entry timeoutEntry;
    pj_mutex_t* zrtpMutex;
    ZsrtpContext* srtpReceive;
    ZsrtpContext* srtpSend;
    void* sendBuffer;
    pj_uint8_t* zrtpBuffer;
    pj_int32_t sendBufferLen;
    pj_uint32_t peerSSRC;       /* stored in host order */
    pj_uint32_t localSSRC;      /* stored in host order */
    pj_char_t* clientIdString;
    pjmedia_transport   *slave_tp;
    zrtp_UserCallbacks* userCallback;
    ZrtpContext* zrtpCtx;
    pj_uint16_t zrtpSeq;
    pj_bool_t enableZrtp;
    pj_bool_t started;
    pj_bool_t close_slave;
};

/* Forward declaration of thethe ZRTP specific callback functions that this
  adapter must implement */
static int32_t zrtp_sendDataZRTP(ZrtpContext* ctx, const uint8_t* data, int32_t length) ;
static int32_t zrtp_activateTimer(ZrtpContext* ctx, int32_t time) ;
static int32_t zrtp_cancelTimer(ZrtpContext* ctx) ;
static void zrtp_sendInfo(ZrtpContext* ctx, int32_t severity, int32_t subCode) ;
static int32_t zrtp_srtpSecretsReady(ZrtpContext* ctx, C_SrtpSecret_t* secrets, int32_t part) ;
static void zrtp_srtpSecretsOff(ZrtpContext* ctx, int32_t part) ;
static void zrtp_rtpSecretsOn(ZrtpContext* ctx, char* c, char* s, int32_t verified) ;
static void zrtp_handleGoClear(ZrtpContext* ctx) ;
static void zrtp_zrtpNegotiationFailed(ZrtpContext* ctx, int32_t severity, int32_t subCode) ;
static void zrtp_zrtpNotSuppOther(ZrtpContext* ctx) ;
static void zrtp_synchEnter(ZrtpContext* ctx) ;
static void zrtp_synchLeave(ZrtpContext* ctx) ;
static void zrtp_zrtpAskEnrollment(ZrtpContext* ctx, char* info) ;
static void zrtp_zrtpInformEnrollment(ZrtpContext* ctx, char* info) ;
static void zrtp_signSAS(ZrtpContext* ctx, char* sas) ;
static int32_t zrtp_checkSASSignature(ZrtpContext* ctx, char* sas) ;

/* The callback function structure for ZRTP */
static zrtp_Callbacks c_callbacks =
{
    &zrtp_sendDataZRTP,
    &zrtp_activateTimer,
    &zrtp_cancelTimer,
    &zrtp_sendInfo,
    &zrtp_srtpSecretsReady,
    &zrtp_srtpSecretsOff,
    &zrtp_rtpSecretsOn,
    &zrtp_handleGoClear,
    &zrtp_zrtpNegotiationFailed,
    &zrtp_zrtpNotSuppOther,
    &zrtp_synchEnter,
    &zrtp_synchLeave,
    &zrtp_zrtpAskEnrollment,
    &zrtp_zrtpInformEnrollment,
    &zrtp_signSAS,
    &zrtp_checkSASSignature
};

static void timer_callback(pj_timer_heap_t *ht, pj_timer_entry *e);

/**
 * The static, singleton Timer implementation
 */
static pj_thread_t* thread_run;
static pj_pool_t* timer_pool;
static pj_timer_heap_t* timer;
static pj_sem_t* timer_sem;
static pj_bool_t timer_running;
static pj_bool_t timer_initialized = 0;
static pj_mutex_t* timer_mutex;

static void timer_stop()
{
    timer_running = 0;
    pj_sem_post(timer_sem);
}

static int timer_thread_run(void* p)
{
    pj_status_t rc;
    pj_time_val tick = {0, 10};

    timer_running = 1;

    while (timer_running)
    {
        if (pj_timer_heap_count(timer) == 0)
        {
            pj_sem_wait(timer_sem);
        }
        else
        {
            rc = pj_thread_sleep(PJ_TIME_VAL_MSEC(tick));
            rc = pj_timer_heap_poll(timer, NULL);
        }
    }
    pj_timer_heap_destroy(timer);
    timer = NULL;
    pj_sem_destroy(timer_sem);
    timer_sem = NULL;
    pj_pool_release(timer_pool);
    timer_pool = NULL;
    timer_initialized = 0;
    return 0;
}

static int timer_initialize()
{
    pj_status_t rc;
    pj_mutex_t* temp_mutex;

    rc = pj_mutex_create_simple(timer_pool, "zrtp_timer", &temp_mutex);
    if (rc != PJ_SUCCESS)
    {
        return rc;
    }

    pj_enter_critical_section();
    if (timer_mutex == NULL)
        timer_mutex = temp_mutex;
    else
        pj_mutex_destroy(temp_mutex);
    pj_leave_critical_section();

    pj_mutex_lock(timer_mutex);

    if (timer_initialized)
    {
        pj_mutex_unlock(timer_mutex);
        return PJ_SUCCESS;
    }

    rc = pj_timer_heap_create(timer_pool, 4, &timer);
    if (rc != PJ_SUCCESS)
    {
        goto ERROR;
    }

    rc = pj_sem_create(timer_pool, "zrtp_timer", 0, 1, &timer_sem);
    if (rc != PJ_SUCCESS)
    {
        goto ERROR;
    }

    rc = pj_thread_create(timer_pool, "zrtp_timer", &timer_thread_run, NULL,
                          PJ_THREAD_DEFAULT_STACK_SIZE, 0, &thread_run);
    if (rc != PJ_SUCCESS)
    {
        goto ERROR;
    }
    timer_initialized = 1;
    pj_mutex_unlock(timer_mutex);
    return PJ_SUCCESS;

ERROR:
    if (timer != NULL)
    {
        pj_timer_heap_destroy(timer);
        timer = NULL;
    }
    if (timer_sem != NULL)
    {
        pj_sem_destroy(timer_sem);
        timer_sem = NULL;
    }
    if (timer_mutex != NULL)
    {
        pj_mutex_unlock(timer_mutex);
        pj_mutex_destroy(timer_mutex);
        timer_mutex = NULL;
    }

    return rc;
}

static int timer_add_entry(pj_timer_entry* entry, pj_time_val* delay)
{
    pj_status_t rc;

    if (timer_initialized && timer != NULL)
    {
        rc = pj_timer_heap_schedule(timer, entry, delay);
        pj_sem_post(timer_sem);
        return rc;
    }
    else
        return PJ_EIGNORED;
}

static int timer_cancel_entry(pj_timer_entry* entry)
{
    if (timer_initialized && timer != NULL)
        return pj_timer_heap_cancel(timer, entry);
    else
        return PJ_EIGNORED;
}
/*
 * End of timer implementation
 */


//                                         1
//                                1234567890123456
static pj_char_t clientId[] =    "PJS ZRTP 1.6.0  ";

/*
 * Create the ZRTP transport.
 */
PJ_DEF(pj_status_t) pjmedia_transport_zrtp_create(pjmedia_endpt *endpt,
        const char *name,
        pjmedia_transport *transport,
        pjmedia_transport **p_tp,
        pj_bool_t close_slave)
{
    pj_pool_t *pool;
    struct tp_zrtp *zrtp;
    pj_status_t rc;

    if (name == NULL)
        name = "tzrtp%p";

    /* Create the pool and initialize the adapter structure */
    pool = pjmedia_endpt_create_pool(endpt, name, 5*1024, 512);
    zrtp = PJ_POOL_ZALLOC_T(pool, struct tp_zrtp);
    zrtp->pool = pool;
    pj_ansi_strncpy(zrtp->base.name, pool->obj_name,
                    sizeof(zrtp->base.name));
    zrtp->base.type = (pjmedia_transport_type)
                      (PJMEDIA_TRANSPORT_TYPE_USER + 2);
    zrtp->base.op = &tp_zrtp_op;

    if (timer_pool == NULL)
    {
        timer_pool = pjmedia_endpt_create_pool(endpt, "zrtp_timer", 256, 256);
        rc = timer_initialize();
        if (rc != PJ_SUCCESS)
        {
            pj_pool_release(timer_pool);
            pj_pool_release(zrtp->pool);
            return rc;
        }
    }

    /* Create the empty wrapper */
    zrtp->zrtpCtx = zrtp_CreateWrapper();

    /* Initialize standard values */
    zrtp->clientIdString = clientId;    /* Set standard name */
    zrtp->zrtpSeq = 1;                  /* TODO: randomize */
    rc = pj_mutex_create_simple(zrtp->pool, "zrtp", &zrtp->zrtpMutex);
    zrtp->zrtpBuffer = pj_pool_zalloc(pool, MAX_ZRTP_SIZE);
    zrtp->sendBuffer = pj_pool_zalloc(pool, MAX_RTP_BUFFER_LEN);

    zrtp->slave_tp = transport;
    zrtp->close_slave = close_slave;

    /* Done */
    zrtp->refcount++;
    *p_tp = &zrtp->base;
    return PJ_SUCCESS;
}

PJ_DECL(pj_status_t) pjmedia_transport_zrtp_initialize(pjmedia_transport *tp,
        const char *zidFilename,
        pj_bool_t autoEnable)
{
    struct tp_zrtp *zrtp = (struct tp_zrtp*)tp;
    PJ_ASSERT_RETURN(tp, PJ_EINVAL);

    zrtp_initializeZrtpEngine(zrtp->zrtpCtx, &c_callbacks, zrtp->clientIdString,
                              zidFilename, zrtp);
    zrtp->enableZrtp = autoEnable;
    return PJ_SUCCESS;
}
static void timer_callback(pj_timer_heap_t *ht, pj_timer_entry *e)
{
    struct tp_zrtp *zrtp = (struct tp_zrtp*)e->user_data;

    zrtp_processTimeout(zrtp->zrtpCtx);
    PJ_UNUSED_ARG(ht);
}

/*
 * Here start with callback functions that support the ZRTP core
 */
static int32_t zrtp_sendDataZRTP(ZrtpContext* ctx, const uint8_t* data, int32_t length)
{
    struct tp_zrtp *zrtp = (struct tp_zrtp*)ctx->userData;
    pj_uint16_t totalLen = length + 12;     /* Fixed number of bytes of ZRTP header */
    pj_uint32_t crc;
    pj_uint8_t* buffer = zrtp->zrtpBuffer;
    pj_uint16_t* pus;
    pj_uint32_t* pui;

    if ((totalLen) > MAX_ZRTP_SIZE)
        return 0;

    /* Get some handy pointers */
    pus = (pj_uint16_t*)buffer;
    pui = (pj_uint32_t*)buffer;

    /* set up fixed ZRTP header */
    *buffer = 0x10;     /* invalid RTP version - refer to ZRTP spec chap 5 */
    *(buffer + 1) = 0;
    pus[1] = pj_htons(zrtp->zrtpSeq++);
    pui[1] = pj_htonl(ZRTP_MAGIC);
    pui[2] = pj_htonl(zrtp->localSSRC);   /* stored in host order */

    /* Copy ZRTP message data behind the header data */
    pj_memcpy(buffer+12, data, length);

    /* Setup and compute ZRTP CRC */
    crc = zrtp_GenerateCksum(buffer, totalLen-CRC_SIZE);

    /* convert and store CRC in ZRTP packet.*/
    crc = zrtp_EndCksum(crc);
    *(uint32_t*)(buffer+totalLen-CRC_SIZE) = pj_htonl(crc);

    /* Send the ZRTP packet using the slave transport */
    return (pjmedia_transport_send_rtp(zrtp->slave_tp, buffer, totalLen) == PJ_SUCCESS) ? 1 : 0;
}

static int32_t zrtp_activateTimer(ZrtpContext* ctx, int32_t time)
{
    pj_time_val timeout;
    struct tp_zrtp *zrtp = (struct tp_zrtp*)ctx->userData;

    timeout.sec = time / 1000;
    timeout.msec = time % 1000;

    pj_timer_entry_init(&zrtp->timeoutEntry, 0, zrtp, &timer_callback);
    timer_add_entry(&zrtp->timeoutEntry, &timeout);

    return 1;
}

static int32_t zrtp_cancelTimer(ZrtpContext* ctx)
{
    struct tp_zrtp *zrtp = (struct tp_zrtp*)ctx->userData;

    timer_cancel_entry(&zrtp->timeoutEntry);

    return 1;
}

static void zrtp_sendInfo(ZrtpContext* ctx, int32_t severity, int32_t subCode)
{
    struct tp_zrtp *zrtp = (struct tp_zrtp*)ctx->userData;

    if (zrtp->userCallback != NULL)
    {
        zrtp->userCallback->zrtp_showMessage(zrtp->userCallback->userData, severity, subCode);
    }

}

static int32_t zrtp_srtpSecretsReady(ZrtpContext* ctx, C_SrtpSecret_t* secrets, int32_t part)
{
    struct tp_zrtp *zrtp = (struct tp_zrtp*)ctx->userData;

    ZsrtpContext* recvCryptoContext;
    ZsrtpContext* senderCryptoContext;

    if (part == ForSender)
    {
        // To encrypt packets: intiator uses initiator keys,
        // responder uses responder keys
        // Create a "half baked" crypto context first and store it. This is
        // the main crypto context for the sending part of the connection.
        if (secrets->role == Initiator)
        {
            senderCryptoContext = zsrtp_CreateWrapper(
                                      0,
                                      0,
                                      0L,                                      // keyderivation << 48,
                                      SrtpEncryptionAESCM,                     // encryption algo
                                      SrtpAuthenticationSha1Hmac,              // authtentication algo
                                      (unsigned char*)secrets->keyInitiator,   // Master Key
                                      secrets->initKeyLen / 8,                 // Master Key length
                                      (unsigned char*)secrets->saltInitiator,  // Master Salt
                                      secrets->initSaltLen / 8,                // Master Salt length
                                      secrets->initKeyLen / 8,                 // encryption keyl
                                      20,                                      // authentication key len
                                      secrets->initSaltLen / 8,                // session salt len
                                      secrets->srtpAuthTagLen / 8);            // authentication tag lenA
        }
        else
        {
            senderCryptoContext = zsrtp_CreateWrapper(
                                      0,
                                      0,
                                      0L,                                      // keyderivation << 48,
                                      SrtpEncryptionAESCM,                     // encryption algo
                                      SrtpAuthenticationSha1Hmac,              // authtentication algo
                                      (unsigned char*)secrets->keyResponder,   // Master Key
                                      secrets->respKeyLen / 8,                 // Master Key length
                                      (unsigned char*)secrets->saltResponder,  // Master Salt
                                      secrets->respSaltLen / 8,                // Master Salt length
                                      secrets->respKeyLen / 8,                 // encryption keyl
                                      20,                                      // authentication key len
                                      secrets->respSaltLen / 8,                // session salt len
                                      secrets->srtpAuthTagLen / 8);            // authentication tag len
        }
        if (senderCryptoContext == NULL)
        {
            return 0;
        }
        // Create a SRTP crypto context for real SSRC sender stream.
        // Note: key derivation can be done at this time only if the
        // key derivation rate is 0 (disabled). For ZRTP this is the
        // case: the key derivation is defined as 2^48
        // which is effectively 0.
        zsrtp_newCryptoContextForSSRC(senderCryptoContext, zrtp->localSSRC, 0, 0L);
        zsrtp_deriveSrtpKeys(senderCryptoContext, 0L);
        zrtp->srtpSend = senderCryptoContext;
    }
    if (part == ForReceiver)
    {
        // To decrypt packets: intiator uses responder keys,
        // responder initiator keys
        // See comment above.
        if (secrets->role == Initiator)
        {
            recvCryptoContext = zsrtp_CreateWrapper(
                                    0,
                                    0,
                                    0L,                                      // keyderivation << 48,
                                    SrtpEncryptionAESCM,                     // encryption algo
                                    SrtpAuthenticationSha1Hmac,              // authtication algo
                                    (unsigned char*)secrets->keyResponder,   // Master Key
                                    secrets->respKeyLen / 8,                 // Master Key length
                                    (unsigned char*)secrets->saltResponder,  // Master Salt
                                    secrets->respSaltLen / 8,                // Master Salt length
                                    secrets->respKeyLen / 8,                 // encryption keyl
                                    20,                                      // authentication key len
                                    secrets->respSaltLen / 8,                // session salt len
                                    secrets->srtpAuthTagLen / 8);            // authentication tag len
        }
        else
        {
            recvCryptoContext = zsrtp_CreateWrapper(
                                    0,
                                    0,
                                    0L,                                      // keyderivation << 48,
                                    SrtpEncryptionAESCM,                     // encryption algo
                                    SrtpAuthenticationSha1Hmac,              // authtication algo
                                    (unsigned char*)secrets->keyInitiator,   // Master Key
                                    secrets->initKeyLen / 8,                 // Master Key length
                                    (unsigned char*)secrets->saltInitiator,  // Master Salt
                                    secrets->initSaltLen / 8,                // Master Salt length
                                    secrets->initKeyLen / 8,                 // encryption keyl
                                    20,                                      // authentication key len
                                    secrets->initSaltLen / 8,                // session salt len
                                    secrets->srtpAuthTagLen / 8);            // authentication tag len
        }
        if (recvCryptoContext == NULL)
        {
            return 0;
        }
        // Create a SRTP crypto context for real SSRC input stream.
        // If the sender didn't provide a SSRC just insert the template
        // into the queue. After we received the first packet the real
        // crypto context will be created.
        //
        // Note: key derivation can be done at this time only if the
        // key derivation rate is 0 (disabled). For ZRTP this is the
        // case: the key derivation is defined as 2^48
        // which is effectively 0.
        if (zrtp->peerSSRC != 0)
        {
            zsrtp_newCryptoContextForSSRC(recvCryptoContext, zrtp->peerSSRC, 0, 0L);
            zsrtp_deriveSrtpKeys(recvCryptoContext, 0L);
            zrtp->srtpReceive = recvCryptoContext;
        }
    }
    return 1;
}

static void zrtp_srtpSecretsOff(ZrtpContext* ctx, int32_t part)
{
    struct tp_zrtp *zrtp = (struct tp_zrtp*)ctx->userData;

    if (part == ForSender)
    {
        zsrtp_DestroyWrapper(zrtp->srtpSend);
        zrtp->srtpSend = NULL;
    }
    if (part == ForReceiver)
    {
        zsrtp_DestroyWrapper(zrtp->srtpReceive);
        zrtp->srtpReceive = NULL;
    }
    if (zrtp->userCallback != NULL)
    {
        zrtp->userCallback->zrtp_secureOff(zrtp->userCallback->userData);
    }
}

static void zrtp_rtpSecretsOn(ZrtpContext* ctx, char* c, char* s, int32_t verified)
{
    struct tp_zrtp *zrtp = (struct tp_zrtp*)ctx->userData;

    if (zrtp->userCallback != NULL)
    {
        zrtp->userCallback->zrtp_secureOn(zrtp->userCallback->userData, c);

        if (strlen(s) > 0)
        {
            zrtp->userCallback->zrtp_showSAS(zrtp->userCallback->userData, s, verified);
        }
    }
}

static void zrtp_handleGoClear(ZrtpContext* ctx)
{
}

static void zrtp_zrtpNegotiationFailed(ZrtpContext* ctx, int32_t severity, int32_t subCode)
{
    struct tp_zrtp *zrtp = (struct tp_zrtp*)ctx->userData;

    if (zrtp->userCallback != NULL)
    {
        zrtp->userCallback->zrtp_zrtpNegotiationFailed(zrtp->userCallback->userData, severity, subCode);
    }

}

static void zrtp_zrtpNotSuppOther(ZrtpContext* ctx)
{
    struct tp_zrtp *zrtp = (struct tp_zrtp*)ctx->userData;

    if (zrtp->userCallback != NULL)
    {
        zrtp->userCallback->zrtp_zrtpNotSuppOther(zrtp->userCallback->userData);
    }

}

static void zrtp_synchEnter(ZrtpContext* ctx)
{
    struct tp_zrtp *zrtp = (struct tp_zrtp*)ctx->userData;
    pj_mutex_lock(zrtp->zrtpMutex);
}

static void zrtp_synchLeave(ZrtpContext* ctx)
{
    struct tp_zrtp *zrtp = (struct tp_zrtp*)ctx->userData;
    pj_mutex_unlock(zrtp->zrtpMutex);
}

static void zrtp_zrtpAskEnrollment(ZrtpContext* ctx, char* info)
{
    struct tp_zrtp *zrtp = (struct tp_zrtp*)ctx->userData;

    if (zrtp->userCallback != NULL)
    {
        zrtp->userCallback->zrtp_zrtpAskEnrollment(zrtp->userCallback->userData, info);
    }
}

static void zrtp_zrtpInformEnrollment(ZrtpContext* ctx, char* info)
{
    struct tp_zrtp *zrtp = (struct tp_zrtp*)ctx->userData;

    if (zrtp->userCallback != NULL)
    {
        zrtp->userCallback->zrtp_zrtpInformEnrollment(zrtp->userCallback->userData, info);
    }
}

static void zrtp_signSAS(ZrtpContext* ctx, char* sas)
{
    struct tp_zrtp *zrtp = (struct tp_zrtp*)ctx->userData;

    if (zrtp->userCallback != NULL)
    {
        zrtp->userCallback->zrtp_signSAS(zrtp->userCallback->userData, sas);
    }
}

static int32_t zrtp_checkSASSignature(ZrtpContext* ctx, char* sas)
{
    struct tp_zrtp *zrtp = (struct tp_zrtp*)ctx->userData;

    if (zrtp->userCallback != NULL)
    {
        return zrtp->userCallback->zrtp_checkSASSignature(zrtp->userCallback->userData, sas);
    }
    return 0;
}

/*
 * Implement the specific ZRTP transport functions
 */
PJ_DECL(void) pjmedia_transport_zrtp_setEnableZrtp(pjmedia_transport *tp, pj_bool_t onOff)
{
    struct tp_zrtp *zrtp = (struct tp_zrtp*)tp;
    pj_assert(tp);

    zrtp->enableZrtp = onOff;
}

PJ_DECL(pj_bool_t) pjmedia_transport_zrtp_isEnableZrtp(pjmedia_transport *tp)
{
    struct tp_zrtp *zrtp = (struct tp_zrtp*)tp;
    PJ_ASSERT_RETURN(tp, PJ_FALSE);

    return zrtp->enableZrtp;

}

PJ_DEF(void) pjmedia_transport_zrtp_setUserCallback(pjmedia_transport *tp, zrtp_UserCallbacks* ucb)
{
    struct tp_zrtp *zrtp = (struct tp_zrtp*)tp;
    pj_assert(tp);

    zrtp->userCallback = ucb;
}

PJ_DEF(void) pjmedia_transport_zrtp_startZrtp(pjmedia_transport *tp)
{
    struct tp_zrtp *zrtp = (struct tp_zrtp*)tp;

    pj_assert(tp && zrtp->zrtpCtx);

    zrtp_startZrtpEngine(zrtp->zrtpCtx);
    zrtp->started = 1;
}

PJ_DEF(void) pjmedia_transport_zrtp_stopZrtp(pjmedia_transport *tp)
{
    struct tp_zrtp *zrtp = (struct tp_zrtp*)tp;

    pj_assert(tp && zrtp->zrtpCtx);

    zrtp_DestroyWrapper(zrtp->zrtpCtx);
    zrtp->zrtpCtx = NULL;
    zrtp->started = 0;
}

PJ_DECL(void) pjmedia_transport_zrtp_setLocalSSRC(pjmedia_transport *tp, uint32_t ssrc)
{
    struct tp_zrtp *zrtp = (struct tp_zrtp*)tp;
    pj_assert(tp);

    zrtp->localSSRC = ssrc;
}

PJ_DECL(ZrtpContext*) pjmedia_transport_zrtp_getZrtpContext(pjmedia_transport *tp)
{
    struct tp_zrtp *zrtp = (struct tp_zrtp*)tp;
    PJ_ASSERT_RETURN(tp, NULL);

    return zrtp->zrtpCtx;
}

/*
 * get_info() is called to get the transport addresses to be put
 * in SDP c= line and a=rtcp line.
 */
static pj_status_t transport_get_info(pjmedia_transport *tp,
                                      pjmedia_transport_info *info)
{
    struct tp_zrtp *zrtp = (struct tp_zrtp*)tp;
    pjmedia_zrtp_info zrtp_info;
    int spc_info_idx;

    PJ_ASSERT_RETURN(tp && info, PJ_EINVAL);
    PJ_ASSERT_RETURN(info->specific_info_cnt <
            PJMEDIA_TRANSPORT_SPECIFIC_INFO_MAXCNT, PJ_ETOOMANY);
             
    zrtp_info.active = zrtp_inState(zrtp->zrtpCtx, SecureState) ? PJ_TRUE : PJ_FALSE;
    
    spc_info_idx = info->specific_info_cnt++;
    info->spc_info[spc_info_idx].type = PJMEDIA_TRANSPORT_TYPE_ZRTP;

    pj_memcpy(&info->spc_info[spc_info_idx].buffer, &zrtp_info, 
              sizeof(zrtp_info));

    return pjmedia_transport_get_info(zrtp->slave_tp, info);
}

/* This is our RTP callback, that is called by the slave transport when it
 * receives RTP packet.
 */
static void transport_rtp_cb(void *user_data, void *pkt, pj_ssize_t size)
{
    struct tp_zrtp *zrtp = (struct tp_zrtp*)user_data;

    pj_uint8_t* buffer = (pj_uint8_t*)pkt;
    int32_t newLen = 0;
    pj_status_t rc = PJ_SUCCESS;

    pj_assert(zrtp && zrtp->stream_rtcp_cb && pkt);

    // check if this could be a real RTP/SRTP packet.
    if ((*buffer & 0xf0) != 0x10)
    {
        //  Could be real RTP, check if we are in secure mode
        if (zrtp->srtpReceive == NULL)
        {
            zrtp->stream_rtp_cb(zrtp->stream_user_data, pkt, size);
        }
        else
        {
            rc = zsrtp_unprotect(zrtp->srtpReceive, pkt, size, &newLen);
            zrtp->unprotect++;
            if (rc == 1)
            {
                zrtp->stream_rtp_cb(zrtp->stream_user_data, pkt,
                                    newLen);
                zrtp->unprotect_err = 0;
            }
            else
            {
                zrtp->unprotect_err = rc;
            }
        }
        if (!zrtp->started && zrtp->enableZrtp)
            pjmedia_transport_zrtp_startZrtp((pjmedia_transport *)zrtp);

        return;
    }

    // We assume all other packets are ZRTP packets here. Process
    // if ZRTP processing is enabled. Because valid RTP packets are
    // already handled we delete any packets here after processing.
    if (zrtp->enableZrtp && zrtp->zrtpCtx != NULL)
    {
        // Get CRC value into crc (see above how to compute the offset)
        pj_uint16_t temp = size - CRC_SIZE;
        pj_uint32_t crc = *(uint32_t*)(buffer + temp);
        crc = pj_ntohl(crc);

        if (!zrtp_CheckCksum(buffer, temp, crc))
        {
            if (zrtp->userCallback != NULL)
                zrtp->userCallback->zrtp_showMessage(zrtp->userCallback->userData, zrtp_Warning, zrtp_WarningCRCmismatch);
            return;
        }

        pj_uint32_t magic = *(pj_uint32_t*)(buffer + 4);
        magic = pj_ntohl(magic);

        // Check if it is really a ZRTP packet, return, no further processing
        if (magic != ZRTP_MAGIC || zrtp->zrtpCtx == NULL)
        {
            return;
        }
        // cover the case if the other party sends _only_ ZRTP packets at the
        // beginning of a session. Start ZRTP in this case as well.
        if (!zrtp->started)
        {
            pjmedia_transport_zrtp_startZrtp((pjmedia_transport *)zrtp);
        }
        // this now points beyond the undefined and length field.
        // We need them, thus adjust
        unsigned char* zrtpMsg = (buffer + 12);

        // store peer's SSRC in host order, used when creating the CryptoContext
        zrtp->peerSSRC = *(pj_uint32_t*)(buffer + 8);
        zrtp->peerSSRC = pj_ntohl(zrtp->peerSSRC);
        zrtp_processZrtpMessage(zrtp->zrtpCtx, zrtpMsg, zrtp->peerSSRC);
    }
}


/* This is our RTCP callback, that is called by the slave transport when it
 * receives RTCP packet.
 */
static void transport_rtcp_cb(void *user_data, void *pkt, pj_ssize_t size)
{
    struct tp_zrtp *zrtp = (struct tp_zrtp*)user_data;

    pj_assert(zrtp && zrtp->stream_rtcp_cb);

    /* Call stream's callback */
    zrtp->stream_rtcp_cb(zrtp->stream_user_data, pkt, size);
}


/*
 * attach() is called by stream to register callbacks that we should
 * call on receipt of RTP and RTCP packets.
 */
static pj_status_t transport_attach(pjmedia_transport *tp,
                                    void *user_data,
                                    const pj_sockaddr_t *rem_addr,
                                    const pj_sockaddr_t *rem_rtcp,
                                    unsigned addr_len,
                                    void (*rtp_cb)(void*,
                                                   void*,
                                                   pj_ssize_t),
                                    void (*rtcp_cb)(void*,
                                                    void*,
                                                    pj_ssize_t))
{
    struct tp_zrtp *zrtp = (struct tp_zrtp*)tp;
    pj_status_t status;

    PJ_ASSERT_RETURN(tp && rem_addr && addr_len, PJ_EINVAL);

    /* In this example, we will save the stream information and callbacks
     * to our structure, and we will register different RTP/RTCP callbacks
     * instead.
     */
    pj_assert(zrtp->stream_user_data == NULL);
    zrtp->stream_user_data = user_data;
    zrtp->stream_rtp_cb = rtp_cb;
    zrtp->stream_rtcp_cb = rtcp_cb;

    status = pjmedia_transport_attach(zrtp->slave_tp, zrtp, rem_addr,
                                      rem_rtcp, addr_len, &transport_rtp_cb,
                                      &transport_rtcp_cb);
    if (status != PJ_SUCCESS)
    {
        zrtp->stream_user_data = NULL;
        zrtp->stream_rtp_cb = NULL;
        zrtp->stream_rtcp_cb = NULL;
        return status;
    }

    return PJ_SUCCESS;
}

/*
 * detach() is called when the media is terminated, and the stream is
 * to be disconnected from us.
 */
static void transport_detach(pjmedia_transport *tp, void *strm)
{
    struct tp_zrtp *zrtp = (struct tp_zrtp*)tp;

    PJ_UNUSED_ARG(strm);
    PJ_ASSERT_ON_FAIL(tp, return);

    if (zrtp->stream_user_data != NULL)
    {
        pjmedia_transport_detach(zrtp->slave_tp, zrtp);
        zrtp->stream_user_data = NULL;
        zrtp->stream_rtp_cb = NULL;
        zrtp->stream_rtcp_cb = NULL;
    }
}


/*
 * send_rtp() is called to send RTP packet. The "pkt" and "size" argument
 * contain both the RTP header and the payload.
 */
static pj_status_t transport_send_rtp(pjmedia_transport *tp,
                                      const void *pkt,
                                      pj_size_t size)
{
    struct tp_zrtp *zrtp = (struct tp_zrtp*)tp;
    pj_uint32_t* pui = (pj_uint32_t*)pkt;
    int32_t newLen = size;
    pj_status_t rc = PJ_SUCCESS;

    PJ_ASSERT_RETURN(tp && pkt, PJ_EINVAL);


    if (!zrtp->started && zrtp->enableZrtp)
    {
        if (zrtp->localSSRC == 0)
            zrtp->localSSRC = pj_ntohl(pui[2]);   /* Learn own SSRC before starting ZRTP */

        pjmedia_transport_zrtp_startZrtp((pjmedia_transport *)zrtp);
    }

    if (zrtp->srtpSend == NULL)
    {
        return pjmedia_transport_send_rtp(zrtp->slave_tp, pkt, size);
    }
    else
    {
        if (size+80 > MAX_RTP_BUFFER_LEN)
            return PJ_ETOOBIG;

        pj_memcpy(zrtp->sendBuffer, pkt, size);
        rc = zsrtp_protect(zrtp->srtpSend, zrtp->sendBuffer, size, &newLen);
        zrtp->protect++;

        if (rc == 1)
            return pjmedia_transport_send_rtp(zrtp->slave_tp, zrtp->sendBuffer, newLen);
        else
            return PJ_EIGNORED;
    }
}


/*
 * send_rtcp() is called to send RTCP packet. The "pkt" and "size" argument
 * contain the RTCP packet.
 */
static pj_status_t transport_send_rtcp(pjmedia_transport *tp,
                                       const void *pkt,
                                       pj_size_t size)
{
    struct tp_zrtp *zrtp = (struct tp_zrtp*)tp;
    PJ_ASSERT_RETURN(tp, PJ_EINVAL);

    /* You may do some processing to the RTCP packet here if you want. */

    /* Send the packet using the slave transport */
    return pjmedia_transport_send_rtcp(zrtp->slave_tp, pkt, size);
}


/*
 * This is another variant of send_rtcp(), with the alternate destination
 * address in the argument.
 */
static pj_status_t transport_send_rtcp2(pjmedia_transport *tp,
                                        const pj_sockaddr_t *addr,
                                        unsigned addr_len,
                                        const void *pkt,
                                        pj_size_t size)
{
    struct tp_zrtp *zrtp = (struct tp_zrtp*)tp;
    PJ_ASSERT_RETURN(tp, PJ_EINVAL);

    return pjmedia_transport_send_rtcp2(zrtp->slave_tp, addr, addr_len,
                                        pkt, size);
}

/*
 * The media_create() is called when the transport is about to be used for
 * a new call.
 */
static pj_status_t transport_media_create(pjmedia_transport *tp,
        pj_pool_t *sdp_pool,
        unsigned options,
        const pjmedia_sdp_session *rem_sdp,
        unsigned media_index)
{
    struct tp_zrtp *zrtp = (struct tp_zrtp*)tp;
    PJ_ASSERT_RETURN(tp, PJ_EINVAL);

    /* if "rem_sdp" is not NULL, it means we are UAS. You may do some
     * inspections on the incoming SDP to verify that the SDP is acceptable
     * for us. If the SDP is not acceptable, we can reject the SDP by
     * returning non-PJ_SUCCESS.
     */
    if (rem_sdp)
    {
        /* Do your stuff.. */
    }

    /* Once we're done with our initialization, pass the call to the
     * slave transports to let it do it's own initialization too.
     */
    return pjmedia_transport_media_create(zrtp->slave_tp, sdp_pool, options,
                                          rem_sdp, media_index);
}

/*
 * The encode_sdp() is called when we're about to send SDP to remote party,
 * either as SDP offer or as SDP answer.
 */
static pj_status_t transport_encode_sdp(pjmedia_transport *tp,
                                        pj_pool_t *sdp_pool,
                                        pjmedia_sdp_session *local_sdp,
                                        const pjmedia_sdp_session *rem_sdp,
                                        unsigned media_index)
{
    struct tp_zrtp *zrtp = (struct tp_zrtp*)tp;
    PJ_ASSERT_RETURN(tp, PJ_EINVAL);

    /* If "rem_sdp" is not NULL, it means we're encoding SDP answer. You may
     * do some more checking on the SDP's once again to make sure that
     * everything is okay before we send SDP.
     */
    if (rem_sdp)
    {
        /* Do checking stuffs here.. */
    }

    /* You may do anything to the local_sdp, e.g. adding new attributes, or
     * even modifying the SDP if you want.
     */
    if (0)
    {
        /* Say we add a proprietary attribute here.. */
        pjmedia_sdp_attr *my_attr;

        my_attr = PJ_POOL_ALLOC_T(sdp_pool, pjmedia_sdp_attr);
        pj_strdup2(sdp_pool, &my_attr->name, "X-zrtp");
        pj_strdup2(sdp_pool, &my_attr->value, "some value");

        pjmedia_sdp_attr_add(&local_sdp->media[media_index]->attr_count,
                             local_sdp->media[media_index]->attr,
                             my_attr);
    }

    /* And then pass the call to slave transport to let it encode its
     * information in the SDP. You may choose to call encode_sdp() to slave
     * first before adding your custom attributes if you want.
     */
    return pjmedia_transport_encode_sdp(zrtp->slave_tp, sdp_pool, local_sdp,
                                        rem_sdp, media_index);
}

/*
 * The media_start() is called once both local and remote SDP have been
 * negotiated successfully, and the media is ready to start. Here we can start
 * committing our processing.
 */
static pj_status_t transport_media_start(pjmedia_transport *tp,
        pj_pool_t *pool,
        const pjmedia_sdp_session *local_sdp,
        const pjmedia_sdp_session *rem_sdp,
        unsigned media_index)
{
    struct tp_zrtp *zrtp = (struct tp_zrtp*)tp;
    PJ_ASSERT_RETURN(tp, PJ_EINVAL);

    /* Do something.. */

    /* And pass the call to the slave transport */
    return pjmedia_transport_media_start(zrtp->slave_tp, pool, local_sdp,
                                         rem_sdp, media_index);
}

/*
 * The media_stop() is called when media has been stopped.
 */
static pj_status_t transport_media_stop(pjmedia_transport *tp)
{
    struct tp_zrtp *zrtp = (struct tp_zrtp*)tp;
    PJ_ASSERT_RETURN(tp, PJ_EINVAL);

    /* Do something.. */
    PJ_LOG(4, (THIS_FILE, "Media stop - encrypted packets: %ld, decrypted packets: %ld",
               zrtp->protect, zrtp->unprotect));

    /* And pass the call to the slave transport */
    return pjmedia_transport_media_stop(zrtp->slave_tp);
}

/*
 * simulate_lost() is called to simulate packet lost
 */
static pj_status_t transport_simulate_lost(pjmedia_transport *tp,
        pjmedia_dir dir,
        unsigned pct_lost)
{
    struct tp_zrtp *zrtp = (struct tp_zrtp*)tp;

    PJ_ASSERT_RETURN(tp, PJ_EINVAL);

    return pjmedia_transport_simulate_lost(zrtp->slave_tp, dir, pct_lost);
}

/*
 * destroy() is called when the transport is no longer needed.
 */
static pj_status_t transport_destroy(pjmedia_transport *tp)
{
    struct tp_zrtp *zrtp = (struct tp_zrtp*)tp;

    PJ_ASSERT_RETURN(tp, PJ_EINVAL);

    PJ_LOG(4, (THIS_FILE, "Destroy - encrypted packets: %ld, decrypted packets: %ld",
               zrtp->protect, zrtp->unprotect));

    /* close the slave transport in case */
    if (zrtp->close_slave && zrtp->slave_tp)
    {
        pjmedia_transport_close(zrtp->slave_tp);
    }
    /* Self destruct.. */
    zrtp_DestroyWrapper(zrtp->zrtpCtx);

    /* In case mutex is being acquired by other thread */
    pj_mutex_lock(zrtp->zrtpMutex);
    pj_mutex_unlock(zrtp->zrtpMutex);
    pj_mutex_destroy(zrtp->zrtpMutex);

    pj_pool_release(zrtp->pool);

    return PJ_SUCCESS;
}




