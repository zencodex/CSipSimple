/**
 * Copyright (C) 2010 Regis Montoya (aka r3gis - www.r3gis.fr)
 * This file is part of pjsip_android.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <pjmedia/codec.h>
#include <pjmedia/alaw_ulaw.h>
#include <pjmedia/endpoint.h>
#include <pjmedia/errno.h>
#include <pjmedia/port.h>
#include <pjmedia/plc.h>
#include <pjmedia/silencedet.h>
#include <pj/pool.h>
#include <pj/string.h>
#include <pj/assert.h>
#include <pj/log.h>

#define PJMEDIA_HAS_WEBRTC_CODEC 1

#if defined(PJMEDIA_HAS_WEBRTC_CODEC) && (PJMEDIA_HAS_WEBRTC_CODEC!=0)

#include <modules/audio_coding/main/interface/audio_coding_module.h>

#define THIS_FILE       "webrtc.c"


using namespace webrtc;

PJ_BEGIN_DECL
PJ_DEF(pj_status_t) pjmedia_codec_webrtc_init(pjmedia_endpt *endpt);
PJ_DEF(pj_status_t) pjmedia_codec_webrtc_deinit(void);
PJ_END_DECL


/* Prototypes for webrtc factory */
static pj_status_t webrtc_test_alloc( pjmedia_codec_factory *factory,
				    const pjmedia_codec_info *id );
static pj_status_t webrtc_default_attr( pjmedia_codec_factory *factory,
				      const pjmedia_codec_info *id,
				      pjmedia_codec_param *attr );
static pj_status_t webrtc_enum_codecs (pjmedia_codec_factory *factory,
				     unsigned *count,
				     pjmedia_codec_info codecs[]);
static pj_status_t webrtc_alloc_codec( pjmedia_codec_factory *factory,
				     const pjmedia_codec_info *id,
				     pjmedia_codec **p_codec);
static pj_status_t webrtc_dealloc_codec( pjmedia_codec_factory *factory,
				       pjmedia_codec *codec );

/* Prototypes for webRTC implementation. */
static pj_status_t  webrtc_init( pjmedia_codec *codec,
			       pj_pool_t *pool );
static pj_status_t  webrtc_open( pjmedia_codec *codec,
			       pjmedia_codec_param *attr );
static pj_status_t  webrtc_close( pjmedia_codec *codec );
static pj_status_t  webrtc_modify(pjmedia_codec *codec,
			        const pjmedia_codec_param *attr );
static pj_status_t  webrtc_parse(pjmedia_codec *codec,
			       void *pkt,
			       pj_size_t pkt_size,
			       const pj_timestamp *timestamp,
			       unsigned *frame_cnt,
			       pjmedia_frame frames[]);
static pj_status_t  webrtc_encode( pjmedia_codec *codec,
				 const struct pjmedia_frame *input,
				 unsigned output_buf_len,
				 struct pjmedia_frame *output);
static pj_status_t  webrtc_decode( pjmedia_codec *codec,
				 const struct pjmedia_frame *input,
				 unsigned output_buf_len,
				 struct pjmedia_frame *output);
static pj_status_t  webrtc_recover( pjmedia_codec *codec,
				  unsigned output_buf_len,
				  struct pjmedia_frame *output);

/* Definition for webrtc codec operations. */
static pjmedia_codec_op webrtc_op =
{
    &webrtc_init,
    &webrtc_open,
    &webrtc_close,
    &webrtc_modify,
    &webrtc_parse,
    &webrtc_encode,
    &webrtc_decode,
    &webrtc_recover
};

/* Definition for webRTC codec factory operations. */
static pjmedia_codec_factory_op webrtc_factory_op =
{
    &webrtc_test_alloc,
    &webrtc_default_attr,
    &webrtc_enum_codecs,
    &webrtc_alloc_codec,
    &webrtc_dealloc_codec
};

/* webRTC factory private data */
static struct webrtc_factory
{
    pjmedia_codec_factory	base;
    pjmedia_endpt	       *endpt;
    pj_pool_t		       *pool;
    pj_mutex_t		       *mutex;
} webrtc_factory;

/* webRTC codec private data. */
struct webrtc_private
{
    pj_pool_t   *pool;        /**< Pool for each instance.    */

    void	*encoder; /**< Encoder state.		    */
    void	*decoder; /**< Decoder state.		    */

    unsigned		 pt;
    pj_bool_t		 plc_enabled;
    pjmedia_plc		*plc;
    pj_bool_t		 vad_enabled; /**< VAD enabled flag.	    */
    pjmedia_silence_det *vad; /**< PJMEDIA VAD engine, NULL if
						 codec has internal VAD.    */
    pj_timestamp	 last_tx;   /**< Timestamp of last transmit.*/
};


PJ_DEF(pj_status_t) pjmedia_codec_webrtc_init(pjmedia_endpt *endpt)
{
    pjmedia_codec_mgr *codec_mgr;
    pj_status_t status;

    if (webrtc_factory.endpt != NULL) {
	/* Already initialized. */
	return PJ_SUCCESS;
    }

    /* Init factory */
    webrtc_factory.base.op = &webrtc_factory_op;
    webrtc_factory.base.factory_data = NULL;
    webrtc_factory.endpt = endpt;

    /* Create pool */
    webrtc_factory.pool = pjmedia_endpt_create_pool(endpt, "webrtc codecs", 4000, 4000);
    if (!webrtc_factory.pool)
	return PJ_ENOMEM;

    /* Create mutex. */
    status = pj_mutex_create_simple(webrtc_factory.pool, "webrtc codecs",
				    &webrtc_factory.mutex);
    if (status != PJ_SUCCESS)
	goto on_error;

    /* Get the codec manager. */
    codec_mgr = pjmedia_endpt_get_codec_mgr(endpt);
    if (!codec_mgr) {
	return PJ_EINVALIDOP;
    }

    /* Register codec factory to endpoint. */
    status = pjmedia_codec_mgr_register_factory(codec_mgr,
						&webrtc_factory.base);
    if (status != PJ_SUCCESS)
	return status;

    return PJ_SUCCESS;

on_error:
    if (webrtc_factory.mutex) {
	pj_mutex_destroy(webrtc_factory.mutex);
	webrtc_factory.mutex = NULL;
    }
    if (webrtc_factory.pool) {
	pj_pool_release(webrtc_factory.pool);
	webrtc_factory.pool = NULL;
    }

    return status;
}

PJ_DEF(pj_status_t) pjmedia_codec_webrtc_deinit(void)
{
    pjmedia_codec_mgr *codec_mgr;
    pj_status_t status;

    if (webrtc_factory.endpt == NULL) {
	/* Not registered. */
	return PJ_SUCCESS;
    }

    /* Lock mutex. */
    pj_mutex_lock(webrtc_factory.mutex);

    /* Get the codec manager. */
    codec_mgr = pjmedia_endpt_get_codec_mgr(webrtc_factory.endpt);
    if (!codec_mgr) {
    	webrtc_factory.endpt = NULL;
		pj_mutex_unlock(webrtc_factory.mutex);
		return PJ_EINVALIDOP;
    }

    /* Unregister webRTC codec factory. */
    status = pjmedia_codec_mgr_unregister_factory(codec_mgr,
						  &webrtc_factory.base);
    webrtc_factory.endpt = NULL;

    /* Destroy mutex. */
    pj_mutex_destroy(webrtc_factory.mutex);
    webrtc_factory.mutex = NULL;


    /* Release pool. */
    pj_pool_release(webrtc_factory.pool);
    webrtc_factory.pool = NULL;

    return status;
}

static pj_status_t webrtc_test_alloc(pjmedia_codec_factory *factory,
				   const pjmedia_codec_info *id )
{
    PJ_UNUSED_ARG(factory);

    /* Check payload type. */
    // TODO

    return PJMEDIA_CODEC_EUNSUP;

    //return PJ_SUCCESS;
}

static pj_status_t webrtc_default_attr (pjmedia_codec_factory *factory,
				      const pjmedia_codec_info *id,
				      pjmedia_codec_param *attr )
{
    PJ_UNUSED_ARG(factory);

    pj_bzero(attr, sizeof(pjmedia_codec_param));

    /*
    attr->info.clock_rate = 8000;
    attr->info.channel_cnt = 1;
    attr->info.avg_bps = G729_BPS;
    attr->info.max_bps = G729_BPS;
    attr->info.pcm_bits_per_sample = 16;
    attr->info.frm_ptime = 10;
    attr->info.pt = PJMEDIA_RTP_PT_G729;
*/

    /* Set default frames per packet to 2 (or 20ms) */
    //attr->setting.frm_per_pkt = 2;
    /*
    attr->setting.frm_per_pkt = 1;
    attr->setting.plc = 1;
    attr->setting.vad = 1;
*/

    /* Signal G729 Annex B is being disabled */
    /*
    attr->setting.dec_fmtp.cnt = 1;
    attr->setting.dec_fmtp.param[0].name = pj_str("annexb");
    attr->setting.dec_fmtp.param[0].val = pj_str("no");
*/
    //attr->setting.enc_fmtp.cnt = 1;
    //attr->setting.enc_fmtp.param[0].name = pj_str("annexb");
    //attr->setting.enc_fmtp.param[0].val = pj_str("no");

    return PJ_SUCCESS;
}

static pj_status_t webrtc_enum_codecs(pjmedia_codec_factory *factory,
				    unsigned *count,
				    pjmedia_codec_info codecs[])
{
    unsigned max;
    unsigned i;
    int numCodecs = 1;

    PJ_UNUSED_ARG(factory);
    PJ_ASSERT_RETURN(codecs && *count > 0, PJ_EINVAL);

    max = *count;


    AudioCodingModule *acmTmp = AudioCodingModule::Create(0);
    struct CodecInst sendCodecTmp;
    numCodecs = acmTmp->NumberOfCodecs();

    PJ_LOG(4, (THIS_FILE, "List of supported codec."));


    for (i = 0, *count = 0; i < numCodecs && *count < max; ++i) {

    	acmTmp->Codec(i, sendCodecTmp);
    	pj_str_t codec_name = pj_str((char*)sendCodecTmp.plname);

    	if ( (pj_stricmp2(&codec_name, "telephone-event") != 0) &&
    			(pj_stricmp2(&codec_name, "cn") != 0) ){
			PJ_LOG(4, (THIS_FILE, "%d %s %d %d %d", i, sendCodecTmp.plname,
					sendCodecTmp.pltype, sendCodecTmp.plfreq, sendCodecTmp.pacsize, sendCodecTmp.rate));

			pj_bzero(&codecs[*count], sizeof(pjmedia_codec_info));
			pj_strdup2(webrtc_factory.pool, &codecs[*count].encoding_name, sendCodecTmp.plname);
			codecs[*count].pt = sendCodecTmp.pltype;
			codecs[*count].type = PJMEDIA_TYPE_AUDIO;
			codecs[*count].clock_rate = sendCodecTmp.plfreq;
			codecs[*count].channel_cnt = sendCodecTmp.channels;

			++*count;
    	}
    }


    AudioCodingModule::Destroy(acmTmp);

    return PJ_SUCCESS;
}

static pj_status_t webrtc_alloc_codec( pjmedia_codec_factory *factory,
				     const pjmedia_codec_info *id,
				     pjmedia_codec **p_codec)
{
    pjmedia_codec *codec = NULL;
    pj_status_t status;
    pj_pool_t *pool;

    PJ_ASSERT_RETURN(factory && id && p_codec, PJ_EINVAL);
    PJ_ASSERT_RETURN(factory==&webrtc_factory.base, PJ_EINVAL);

    /* Lock mutex. */
    pj_mutex_lock(webrtc_factory.mutex);

    /* Allocate new codec if no more is available */
	struct webrtc_private *codec_priv;

  /* Create pool for codec instance */
  pool = pjmedia_endpt_create_pool(webrtc_factory.endpt, "webrtc_codec", 512, 512);

	codec = PJ_POOL_ALLOC_T(pool, pjmedia_codec);
	codec_priv = PJ_POOL_ZALLOC_T(pool, struct webrtc_private);
	if (!codec || !codec_priv) {
	  pj_pool_release(pool);
	    pj_mutex_unlock(webrtc_factory.mutex);
	    return PJ_ENOMEM;
	}

	codec_priv->pool = pool;
	/* Set the payload type */
	codec_priv->pt = id->pt;


	codec->factory = factory;
	codec->op = &webrtc_op;
	codec->codec_data = codec_priv;

    *p_codec = codec;

    /* Unlock mutex. */
    pj_mutex_unlock(webrtc_factory.mutex);

    return PJ_SUCCESS;
}

static pj_status_t webrtc_dealloc_codec(pjmedia_codec_factory *factory,
				      pjmedia_codec *codec )
{
    struct webrtc_private *priv = (struct webrtc_private*) codec->codec_data;
    int i = 0;

    PJ_ASSERT_RETURN(factory && codec, PJ_EINVAL);
    PJ_ASSERT_RETURN(factory==&webrtc_factory.base, PJ_EINVAL);

    /* Close codec, if it's not closed. */
    webrtc_close(codec);

    /* Re-init silence_period */
    pj_set_timestamp32(&priv->last_tx, 0, 0);

    pj_pool_release(priv->pool);

    return PJ_SUCCESS;
}

static pj_status_t webrtc_init( pjmedia_codec *codec, pj_pool_t *pool )
{
    /* There's nothing to do here really */
    PJ_UNUSED_ARG(codec);
    PJ_UNUSED_ARG(pool);

    return PJ_SUCCESS;
}

static pj_status_t webrtc_open(pjmedia_codec *codec,
			     pjmedia_codec_param *attr )
{
    struct webrtc_private *priv = (struct webrtc_private*) codec->codec_data;
    pj_pool_t *pool;

    priv->pt = attr->info.pt;
    pool = priv->pool;

    // TODO --

    return PJ_SUCCESS;
}

static pj_status_t webrtc_close( pjmedia_codec *codec )
{
  //PJ_UNUSED_ARG(codec);
  struct webrtc_private *priv = (struct webrtc_private*) codec->codec_data;


  return PJ_SUCCESS;
}

static pj_status_t  webrtc_modify(pjmedia_codec *codec,
			        const pjmedia_codec_param *attr )
{
    struct webrtc_private *priv = (struct webrtc_private*) codec->codec_data;

    if (attr->info.pt != priv->pt)
	return PJMEDIA_EINVALIDPT;

    return PJ_SUCCESS;
}

static pj_status_t  webrtc_parse( pjmedia_codec *codec,
				void *pkt,
				pj_size_t pkt_size,
				const pj_timestamp *ts,
				unsigned *frame_cnt,
				pjmedia_frame frames[])
{
    unsigned count = 0;

    PJ_UNUSED_ARG(codec);

    PJ_ASSERT_RETURN(ts && frame_cnt && frames, PJ_EINVAL);

    /*
    while (pkt_size >= L_PACKED_G729A  && count < *frame_cnt) {
	frames[count].type = PJMEDIA_FRAME_TYPE_AUDIO;
	frames[count].buf = pkt;
	frames[count].size = L_PACKED_G729A; // L_PACKED_G729AB
	frames[count].timestamp.u64 = ts->u64 + 80 * count;

	pkt = ((char*)pkt) + L_PACKED_G729A;
	pkt_size -= L_PACKED_G729A ;

	++count;
    }
    */

    *frame_cnt = count;
    return PJ_SUCCESS;
}

static pj_status_t  webrtc_encode(pjmedia_codec *codec,
				const struct pjmedia_frame *input,
				unsigned output_buf_len,
				struct pjmedia_frame *output)
{
    struct webrtc_private *priv = (struct webrtc_private*) codec->codec_data;
    pj_int16_t *pcm_in;
    unsigned in_size;
    int nb;

    /*
  pj_assert(priv && input && output);

  pcm_in = (pj_int16_t*)input->buf;
  in_size = input->size;

  PJ_ASSERT_RETURN(in_size % 160 == 0, PJMEDIA_CODEC_EPCMFRMINLEN);
  PJ_ASSERT_RETURN(output_buf_len >= L_PACKED_G729A * in_size/160,
                   PJMEDIA_CODEC_EFRMTOOSHORT);


	output->size = 0;

    while (in_size >= 160)
    {
      g729a_enc_process(priv->encoder,pcm_in, (unsigned char*)output->buf+output->size);

		pcm_in += 80;
		output->size += L_PACKED_G729A;
		in_size -= 160;
    }

    output->type = PJMEDIA_FRAME_TYPE_AUDIO;
    output->timestamp = input->timestamp;
*/
    return PJ_SUCCESS;
}

static pj_status_t  webrtc_decode(pjmedia_codec *codec,
				const struct pjmedia_frame *input,
				unsigned output_buf_len,
				struct pjmedia_frame *output)
{
    struct webrtc_private *priv = (struct webrtc_private*) codec->codec_data;

    pj_assert(priv != NULL);
    PJ_ASSERT_RETURN(input && output, PJ_EINVAL);


    //g729a_dec_process(priv->decoder, (unsigned char*)input->buf, (short*)output->buf, 0);


    output->type = PJMEDIA_FRAME_TYPE_AUDIO;
	  output->size = 160;
    output->timestamp = input->timestamp;


    return PJ_SUCCESS;
}

#if !PLC_DISABLED
static pj_status_t  webrtc_recover( pjmedia_codec *codec,
				  unsigned output_buf_len,
				  struct pjmedia_frame *output)
{
    struct webrtc_private *priv = (struct webrtc_private*) codec->codec_data;

	  PJ_ASSERT_RETURN(priv->plc_enabled, PJ_EINVALIDOP);

    PJ_ASSERT_RETURN(output_buf_len >= 160,
		     PJMEDIA_CODEC_EPCMTOOSHORT);

    //pjmedia_plc_generate(priv->plc, (pj_int16_t*)output->buf);
    output->size = 160;

    return PJ_SUCCESS;
}
#endif

#endif
