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
#include <pjmedia/endpoint.h>
#include <pjmedia/errno.h>
#include <pjmedia/port.h>
#include <pjmedia-codec/types.h>
#include <pj/pool.h>
#include <pj/string.h>
#include <pj/assert.h>
#include <pj/math.h>
#include <pj/log.h>

#define THIS_FILE       "amr_stagefright_dyn.c"

#if defined(PJMEDIA_HAS_AMR_STAGEFRIGHT_CODEC) && (PJMEDIA_HAS_AMR_STAGEFRIGHT_CODEC!=0)

#include <pjmedia-codec/amr_helper.h>
#include <dlfcn.h>
#define AMR_TX_WMF  0
#define AMR_TX_IF2  1
#define AMR_TX_ETS  2

enum Frame_Type_3GPP
{
    AMR_475 = 0,
    AMR_515,
    AMR_59,
    AMR_67,
    AMR_74,
    AMR_795,
    AMR_102,
    AMR_122,
    AMR_SID,
    GSM_EFR_SID,
    TDMA_EFR_SID,
    PDC_EFR_SID,
    FOR_FUTURE_USE1,
    FOR_FUTURE_USE2,
    FOR_FUTURE_USE3,
    AMR_NO_DATA
};

enum Mode { MR475 = 0,
	MR515,
	MR59,
	MR67,
	MR74,
	MR795,
	MR102,
	MR122,

	MRDTX,

	N_MODES /* number of (SPC) modes */

};


typedef enum {
    /*
* One word (2-byte) to indicate type of frame type.
* One word (2-byte) to indicate frame type.
* One word (2-byte) to indicate mode.
* N words (2-byte) containing N bits (bit 0 = 0xff81, bit 1 = 0x007f).
*/
    ETS = 0, /* Both AMR-Narrowband and AMR-Wideband */
    /*
* One word (2-byte) for sync word (good frames: 0x6b21, bad frames: 0x6b20)
* One word (2-byte) for frame length N.
* N words (2-byte) containing N bits (bit 0 = 0x007f, bit 1 = 0x0081).
*/
    ITU, /* AMR-Wideband */
    /*
* AMR-WB MIME/storage format, see RFC 3267 (sections 5.1 and 5.3) for details
*/
    MIME_IETF,

    WMF, /* AMR-Narrowband */

    IF2 /* AMR-Narrowband */

} bitstream_format;




typedef struct amr_settings_t {
    pjmedia_codec_amr_pack_setting enc_setting;
    pjmedia_codec_amr_pack_setting dec_setting;
    pj_int8_t enc_mode;
} amr_settings_t;

/* Prototypes for AMR factory */
static pj_status_t amr_test_alloc( pjmedia_codec_factory *factory,
				    const pjmedia_codec_info *id );
static pj_status_t amr_default_attr( pjmedia_codec_factory *factory,
				      const pjmedia_codec_info *id,
				      pjmedia_codec_param *attr );
static pj_status_t amr_enum_codecs (pjmedia_codec_factory *factory,
				     unsigned *count,
				     pjmedia_codec_info codecs[]);
static pj_status_t amr_alloc_codec( pjmedia_codec_factory *factory,
				     const pjmedia_codec_info *id,
				     pjmedia_codec **p_codec);
static pj_status_t amr_dealloc_codec( pjmedia_codec_factory *factory,
				       pjmedia_codec *codec );

/* Prototypes for AMR implementation. */
static pj_status_t  amr_codec_init( pjmedia_codec *codec,
			       pj_pool_t *pool );
static pj_status_t  amr_codec_open( pjmedia_codec *codec,
			       pjmedia_codec_param *attr );
static pj_status_t  amr_codec_close( pjmedia_codec *codec );
static pj_status_t  amr_codec_modify(pjmedia_codec *codec,
			        const pjmedia_codec_param *attr );
static pj_status_t  amr_codec_parse(pjmedia_codec *codec,
			       void *pkt,
			       pj_size_t pkt_size,
			       const pj_timestamp *timestamp,
			       unsigned *frame_cnt,
			       pjmedia_frame frames[]);
static pj_status_t  amr_codec_encode( pjmedia_codec *codec,
				 const struct pjmedia_frame *input,
				 unsigned output_buf_len,
				 struct pjmedia_frame *output);
static pj_status_t  amr_codec_decode( pjmedia_codec *codec,
				 const struct pjmedia_frame *input,
				 unsigned output_buf_len,
				 struct pjmedia_frame *output);
//#if !PLC_DISABLED
//static pj_status_t  amr_codec_recover( pjmedia_codec *codec,
//				  unsigned output_buf_len,
//				  struct pjmedia_frame *output);
//#endif


enum
{
    PARAM_NB = 0,	/* Index for narrowband parameter.	*/
    PARAM_WB,	/* Index for wideband parameter.	*/
    PARAM_UWB,	/* Index for ultra-wideband parameter	*/
};

/* AMR default parameter */
struct amr_param
{
    int		     enabled;		/* Is this mode enabled?	    */
    int		     pt;		/* Payload type.		    */

    unsigned	     clock_rate;	/* Codec's clock rate.		    */
    unsigned	     channel_count;	/* Codec's channel count.	    */
    unsigned	     samples_per_frame;	/* Codec's samples count.	    */

    unsigned	     def_bitrate;	/* Default bitrate of this codec.   */
    unsigned	     max_bitrate;	/* Maximum bitrate of this codec.   */
    pj_uint8_t	     frm_per_pkt;	/* Default num of frames per packet.*/
    int		     has_native_vad;	/* Codec has internal VAD?	    */
    int		     has_native_plc;	/* Codec has internal PLC?	    */

    pjmedia_codec_fmtp dec_fmtp;	/* Decoder's fmtp params.	    */
};

/* Definition for AMR codec operations. */
static pjmedia_codec_op amr_op =
{
    &amr_codec_init,
    &amr_codec_open,
    &amr_codec_close,
    &amr_codec_modify,
    &amr_codec_parse,
    &amr_codec_encode,
    &amr_codec_decode,
    NULL
   // &amr_codec_recover
};

/* Definition for AMR codec factory operations. */
static pjmedia_codec_factory_op amr_factory_op =
{
    &amr_test_alloc,
    &amr_default_attr,
    &amr_enum_codecs,
    &amr_alloc_codec,
    &amr_dealloc_codec
};

/* AMR factory private data */
static struct amr_factory
{
    pjmedia_codec_factory	base;
    pjmedia_endpt	       *endpt;
    pj_pool_t		       *pool;
    pj_mutex_t		       *mutex;
    pjmedia_codec	     codec_list;
    struct amr_param	    amr_param[1];


} amr_factory;



/* AMR codec private data. */
struct amr_private
{
    int			 param_id;	    /**< Index to amr param.	*/
    amr_settings_t		*codec_setting;	    /**< Specific codec setting.    */
    pj_pool_t		*pool;		    /**< Pool for each instance.    */

    // Handle lib
    void* lib;

    // Methods
    // -- Encoder --
    pj_int16_t (* AMREncodeInit) (
    		void **pEncStructure,
            void **pSidSyncStructure,
            int dtx_enable);

    pj_int16_t (* AMREncodeReset) (
    		void *pEncStructure,
    		void *pSidSyncStructure);

    void (* AMREncodeExit) (
    		void **pEncStructure,
            void **pSidSyncStructure);

    pj_int16_t (* AMREncode) (
        void *pEncState,
        void *pSidSyncState,
        enum Mode mode,
        pj_int16_t *pEncInput,
        pj_uint8_t *pEncOutput,
        enum Frame_Type_3GPP *p3gpp_frame_type,
        pj_int16_t output_format
    );
    // -- Decoder --
    /*
    * This function allocates memory for filter structure and initializes state
    * memory used by the GSM AMR decoder. This function returns zero. It will
    * return negative one if there is an error.
    */
    pj_int16_t (*GSMInitDecode) (
    	void **state_data,
        char *id);
    /*
    * AMRDecode steps into the part of the library that decodes the raw data
    * speech bits for the decoding process. It returns the address offset of
    * the next frame to be decoded.
    */
    pj_int16_t (*AMRDecode) (
		void *state_data,
		enum Frame_Type_3GPP frame_type,
		pj_uint8_t *speech_bits_ptr,
		pj_int16_t *raw_pcm_buffer,
		pj_int16_t input_format
	);

    /*
	* This function resets the state memory used by the GSM AMR decoder. This
	* function returns zero. It will return negative one if there is an error.
	*/
    pj_int16_t (* Speech_Decode_Frame_reset)(void *state_data);
    /*
	* This function frees up the memory used for the state memory of the
	* GSM AMR decoder.
	*/
    void (* GSMDecodeFrameExit)(void **state_data);


    unsigned bps;

    // Enc
    pj_bool_t		 enc_ready;
    void* encState;
    void* encSidState;

    pj_bool_t		 dec_ready;
    void* decState;
};


// Private methods

void * get_lib_handle() {
	return dlopen("libstagefright.so", RTLD_LAZY);
}



/* Parse AMR payload into frames. */
static pj_status_t parse_amr(struct amr_private *codec_data, void *pkt,
			     pj_size_t pkt_size, const pj_timestamp *ts,
			     unsigned *frame_cnt, pjmedia_frame frames[])
{
    amr_settings_t* s = (amr_settings_t*)codec_data->codec_setting;
    pjmedia_codec_amr_pack_setting *setting;
    pj_status_t status;
    pj_uint8_t cmr;

    setting = &s->dec_setting;

    status = pjmedia_codec_amr_parse(pkt, pkt_size, ts, setting, frames,
				     frame_cnt, &cmr);
    if (status != PJ_SUCCESS)
	return status;

    /* Check Change Mode Request. */
    if (((setting->amr_nb && cmr <= 7) || (!setting->amr_nb && cmr <= 8)) &&
	s->enc_mode != cmr)
    {
	struct amr_param *param = &amr_factory.amr_param[codec_data->param_id];

	s->enc_mode = cmr;
	codec_data->bps = s->enc_setting.amr_nb?
				pjmedia_codec_amrnb_bitrates[s->enc_mode] :
				pjmedia_codec_amrwb_bitrates[s->enc_mode];

	PJ_LOG(4,(THIS_FILE, "AMR%s switched encoding mode to: %d (%dbps)",
		  (s->enc_setting.amr_nb?"":"-WB"),
		  s->enc_mode,
		  codec_data->bps));
    }

    return PJ_SUCCESS;
}


PJ_DEF(pj_status_t) pjmedia_codec_amr_init(pjmedia_endpt *endpt)
{
    pjmedia_codec_mgr *codec_mgr;
    pj_status_t status;

    if (amr_factory.endpt != NULL) {
	/* Already initialized. */
	return PJ_SUCCESS;
    }

    /* Init factory */
    amr_factory.base.op = &amr_factory_op;
    amr_factory.base.factory_data = NULL;
    amr_factory.endpt = endpt;

    /* Create pool */
    amr_factory.pool = pjmedia_endpt_create_pool(endpt, "amr codecs", 4000, 4000);
    if (!amr_factory.pool)
	return PJ_ENOMEM;

    /* Init list */
    pj_list_init(&amr_factory.codec_list);

    /* Create mutex. */
    status = pj_mutex_create_simple(amr_factory.pool, "amr codecs",
				    &amr_factory.mutex);
    if (status != PJ_SUCCESS)
	goto on_error;
    PJ_LOG(4, (THIS_FILE, "Init amr"));

    /* Initialize default Speex parameter. */
    amr_factory.amr_param[PARAM_NB].enabled = 1;
    amr_factory.amr_param[PARAM_NB].pt = PJMEDIA_RTP_PT_AMR;
    amr_factory.amr_param[PARAM_NB].clock_rate = 8000;
    amr_factory.amr_param[PARAM_NB].channel_count = 1;
    amr_factory.amr_param[PARAM_NB].samples_per_frame = 160;
    amr_factory.amr_param[PARAM_NB].def_bitrate = 5150 /*7400*/;
    amr_factory.amr_param[PARAM_NB].max_bitrate = 12200;
    amr_factory.amr_param[PARAM_NB].frm_per_pkt = 2;
    amr_factory.amr_param[PARAM_NB].has_native_vad = 1;
    amr_factory.amr_param[PARAM_NB].has_native_plc = 1;
    amr_factory.amr_param[PARAM_NB].dec_fmtp = (pjmedia_codec_fmtp){1, {{{"octet-align", 11}, {"1", 1}}} };

    /* Get the codec manager. */
    codec_mgr = pjmedia_endpt_get_codec_mgr(endpt);
    if (!codec_mgr) {
	return PJ_EINVALIDOP;
    }

    PJ_LOG(4, (THIS_FILE, "Init AMR > DONE"));

    /* Register codec factory to endpoint. */
    status = pjmedia_codec_mgr_register_factory(codec_mgr,
						&amr_factory.base);
    if (status != PJ_SUCCESS)
	return status;

    return PJ_SUCCESS;

on_error:
    if (amr_factory.mutex) {
	pj_mutex_destroy(amr_factory.mutex);
	amr_factory.mutex = NULL;
    }
    if (amr_factory.pool) {
	pj_pool_release(amr_factory.pool);
	amr_factory.pool = NULL;
    }

    return status;
}

/*
 * Unregister AMR codec factory from pjmedia endpoint and deinitialize
 * the AMR codec library.
 */
PJ_DEF(pj_status_t) pjmedia_codec_amr_deinit(void)
{
    pjmedia_codec_mgr *codec_mgr;
    pj_status_t status;

    if (amr_factory.endpt == NULL) {
	/* Not registered. */
	return PJ_SUCCESS;
    }

    /* Lock mutex. */
    pj_mutex_lock(amr_factory.mutex);

    /* Get the codec manager. */
    codec_mgr = pjmedia_endpt_get_codec_mgr(amr_factory.endpt);
    if (!codec_mgr) {
	amr_factory.endpt = NULL;
	pj_mutex_unlock(amr_factory.mutex);
	return PJ_EINVALIDOP;
    }

    /* Unregister amr codec factory. */
    status = pjmedia_codec_mgr_unregister_factory(codec_mgr,
						  &amr_factory.base);
    amr_factory.endpt = NULL;

    /* Destroy mutex. */
    pj_mutex_destroy(amr_factory.mutex);
    amr_factory.mutex = NULL;


    /* Release pool. */
    pj_pool_release(amr_factory.pool);
    amr_factory.pool = NULL;

    return status;
}

/*
 * Check if factory can allocate the specified codec.
 */
static pj_status_t amr_test_alloc(pjmedia_codec_factory *factory,
				   const pjmedia_codec_info *info )
{
    const pj_str_t amr_tag = { "AMR", 3};
    unsigned i;

    PJ_UNUSED_ARG(factory);
    PJ_ASSERT_RETURN(factory==&amr_factory.base, PJ_EINVAL);


    PJ_LOG(4, (THIS_FILE, "Test aloc AMR ...."));


    /* Type MUST be audio. */
    if (info->type != PJMEDIA_TYPE_AUDIO)
	return PJMEDIA_CODEC_EUNSUP;

    /* Check encoding name. */
    if (pj_stricmp(&info->encoding_name, &amr_tag) != 0)
	return PJMEDIA_CODEC_EUNSUP;

    /* Channel count must be one */
    if (info->channel_cnt != 1)
	return PJMEDIA_CODEC_EUNSUP;

    /* Check clock-rate */
    for (i=0; i<PJ_ARRAY_SIZE(amr_factory.amr_param); ++i) {
	if (info->clock_rate == amr_factory.amr_param[i].clock_rate) {
		PJ_LOG(4, (THIS_FILE, "Test OK"));
	    /* Okay, let's AMR! */
	    return PJ_SUCCESS;
	}
    }
    PJ_LOG(1, (THIS_FILE, "Test failed : AMR clock rate not supported"));
    /* Clock rate not supported */
    return PJMEDIA_CODEC_EUNSUP;
}

/*
 * Generate default attribute.
 */
static pj_status_t amr_default_attr( pjmedia_codec_factory *factory,
				      const pjmedia_codec_info *id,
				      pjmedia_codec_param *attr )
{
    PJ_UNUSED_ARG(factory);
    PJ_LOG(4, (THIS_FILE, "AMR default attr"));
    PJ_UNUSED_ARG(factory);
    PJ_ASSERT_RETURN(factory==&amr_factory.base, PJ_EINVAL);


    PJ_LOG(4, (THIS_FILE, "AMR reset attr"));
    pj_bzero(attr, sizeof(pjmedia_codec_param));

    // Choose NB for now (0)
	attr->info.pt = (pj_uint8_t)id->pt;
	attr->info.channel_cnt = amr_factory.amr_param[0].channel_count;
	attr->info.clock_rate = amr_factory.amr_param[0].clock_rate;
	attr->info.avg_bps = amr_factory.amr_param[0].def_bitrate;
	attr->info.max_bps = amr_factory.amr_param[0].max_bitrate;
	attr->info.pcm_bits_per_sample = 16;
	attr->info.frm_ptime =  (pj_uint16_t)
				(amr_factory.amr_param[0].samples_per_frame * 1000 /
						amr_factory.amr_param[0].channel_count /
						amr_factory.amr_param[0].clock_rate);
	attr->setting.frm_per_pkt = amr_factory.amr_param[0].frm_per_pkt;

	/* Default flags. */
	attr->setting.plc = 1;
	attr->setting.penh= 0;
	attr->setting.vad = 1;
	attr->setting.cng = attr->setting.vad;
	attr->setting.dec_fmtp = amr_factory.amr_param[0].dec_fmtp;

    PJ_LOG(4, (THIS_FILE, "AMR default attr DONE"));

    /* Default all other flag bits disabled. */

    return PJ_SUCCESS;
}

/*
 * Enum codecs supported by this factory (for now only support AMR 8kHz).
 */
static pj_status_t amr_enum_codecs(pjmedia_codec_factory *factory,
				    unsigned *count,
				    pjmedia_codec_info codecs[])
{
    unsigned max;
    int i;  /* Must be signed */
    PJ_LOG(4, (THIS_FILE, "AMR enum codecs"));

    PJ_UNUSED_ARG(factory);
    PJ_ASSERT_RETURN(codecs && *count > 0, PJ_EINVAL);

    max = *count;
    *count = 0;

    void *lib_handle = get_lib_handle();
    if(lib_handle == NULL){
    	// No lib available
    	return PJ_SUCCESS;
    }
    dlclose(lib_handle);

    // First of all, check that lib exists

    for (i=PJ_ARRAY_SIZE(amr_factory.amr_param)-1; i>=0 && *count<max; --i) {

        PJ_LOG(4, (THIS_FILE, "AMR add codecs"));
    	if (!amr_factory.amr_param[i].enabled){
    	    continue;
    	}
    	PJ_LOG(4, (THIS_FILE, "Add codec %d", amr_factory.amr_param[i].clock_rate));

    	pj_bzero(&codecs[*count], sizeof(pjmedia_codec_info));
    	codecs[*count].encoding_name = pj_str("AMR");
    	codecs[*count].pt = amr_factory.amr_param[i].pt;
    	codecs[*count].type = PJMEDIA_TYPE_AUDIO;
    	codecs[*count].clock_rate = amr_factory.amr_param[i].clock_rate;
    	codecs[*count].channel_cnt = 1;

    	++*count;
	}

	return PJ_SUCCESS;

}


/*
 * Allocate a new AMR codec instance.
 */
static pj_status_t amr_alloc_codec(pjmedia_codec_factory *factory,
				    const pjmedia_codec_info *id,
				    pjmedia_codec **p_codec)
{
    pjmedia_codec *codec;
    struct amr_private *amr;
    pj_pool_t *pool;

    PJ_LOG(4, (THIS_FILE, "Alloc AMR codec"));

    PJ_ASSERT_RETURN(factory && id && p_codec, PJ_EINVAL);
    PJ_ASSERT_RETURN(factory == &amr_factory.base, PJ_EINVAL);


    pj_mutex_lock(amr_factory.mutex);

    /* Get free nodes, if any. */
    if (!pj_list_empty(&amr_factory.codec_list)) {
		codec = amr_factory.codec_list.next;
		pj_list_erase(codec);
    } else {

		/* Create pool for codec instance */
		pool = pjmedia_endpt_create_pool(amr_factory.endpt, "AMRcodec", 512, 512);
		codec = PJ_POOL_ZALLOC_T(amr_factory.pool, pjmedia_codec);
		PJ_ASSERT_RETURN(codec != NULL, PJ_ENOMEM);
		codec->op = &amr_op;
		codec->factory = factory;
		codec->codec_data = PJ_POOL_ZALLOC_T(pool, struct amr_private);
	    amr = (struct amr_private*) codec->codec_data;
	    amr->pool = pool;
    }

    pj_mutex_unlock(amr_factory.mutex);

    amr->enc_ready = PJ_FALSE;
    amr->dec_ready = PJ_FALSE;

    amr->param_id = PARAM_NB;

    struct amr_param params = amr_factory.amr_param[amr->param_id];
    amr->bps = params.def_bitrate;

    amr->lib = get_lib_handle();
    amr->AMREncodeInit = dlsym(amr->lib, "AMREncodeInit");
    amr->AMREncodeReset = dlsym(amr->lib, "AMREncodeReset");
    amr->AMREncodeExit = dlsym(amr->lib, "AMREncodeExit");
    amr->AMREncode = dlsym(amr->lib, "AMREncode");
    amr->GSMInitDecode = dlsym(amr->lib, "GSMInitDecode");
    amr->AMRDecode = dlsym(amr->lib, "AMRDecode");
    amr->Speech_Decode_Frame_reset = dlsym(amr->lib, "Speech_Decode_Frame_reset");
    amr->GSMDecodeFrameExit = dlsym(amr->lib, "GSMDecodeFrameExit");

    PJ_LOG(4, (THIS_FILE, "Alloc AMR OK"));

    *p_codec = codec;
    return PJ_SUCCESS;
}



/*
 * Free codec.
 */
static pj_status_t amr_dealloc_codec( pjmedia_codec_factory *factory,
				      pjmedia_codec *codec )
{
    struct amr_private *amr;

    PJ_ASSERT_RETURN(factory && codec, PJ_EINVAL);
    PJ_UNUSED_ARG(factory);
    PJ_ASSERT_RETURN(factory == &amr_factory.base, PJ_EINVAL);

    amr = (struct amr_private*) codec->codec_data;

    /* Close codec, if it's not closed. */
    if (amr->enc_ready == PJ_TRUE || amr->dec_ready == PJ_TRUE) {
    	amr_codec_close(codec);
    }

    if(amr->lib != NULL){
    	dlclose(amr->lib);
    }

    pj_pool_release(amr->pool);

    /* Put in the free list. */
    pj_mutex_lock(amr_factory.mutex);
    pj_list_push_front(&amr_factory.codec_list, codec);
    pj_mutex_unlock(amr_factory.mutex);


    return PJ_SUCCESS;
}

/*
 * Init codec.
 */
static pj_status_t amr_codec_init(pjmedia_codec *codec,
				   pj_pool_t *pool )
{
    PJ_LOG(4, (THIS_FILE, "Init amr codec"));
	PJ_UNUSED_ARG(pool);
	PJ_UNUSED_ARG(codec);
    return PJ_SUCCESS;
}


/*
 * Open codec.
 */
static pj_status_t amr_codec_open(pjmedia_codec *codec,
				   pjmedia_codec_param *attr )
{

    pj_status_t status;
    struct amr_private *amr;
    int id, ret = 0;
    struct amr_param params;
    int i;
    pj_pool_t *pool;
	amr_settings_t *s;
	pj_uint8_t octet_align = 0;
	pj_int8_t enc_mode = 7; // Default to 12kbits

    amr = (struct amr_private*) codec->codec_data;
    pool = amr->pool;


    id = amr->param_id;

    PJ_LOG(4, (THIS_FILE, "Opening amr codec"));

    pj_assert(amr != NULL);
    pj_assert(amr->enc_ready == PJ_FALSE &&
    		amr->dec_ready == PJ_FALSE);

    params = amr_factory.amr_param[id];

	/* Check AMR specific attributes */

	for (i = 0; i < attr->setting.dec_fmtp.cnt; ++i) {
	    /* octet-align, one of the parameters that must have same value
	     * in offer & answer (RFC 4867 Section 8.3.1). Just check fmtp
	     * in the decoder side, since it's value is guaranteed to fulfil
	     * above requirement (by SDP negotiator).
	     */
	    const pj_str_t STR_FMTP_OCTET_ALIGN = {"octet-align", 11};

	    if (pj_stricmp(&attr->setting.dec_fmtp.param[i].name,
			   &STR_FMTP_OCTET_ALIGN) == 0)
	    {
		octet_align=(pj_uint8_t)
			    pj_strtoul(&attr->setting.dec_fmtp.param[i].val);
		break;
	    }
	}

	for (i = 0; i < attr->setting.enc_fmtp.cnt; ++i) {
	    /* mode-set, encoding mode is chosen based on local default mode
	     * setting:
	     * - if local default mode is included in the mode-set, use it
	     * - otherwise, find the closest mode to local default mode;
	     *   if there are two closest modes, prefer to use the higher
	     *   one, e.g: local default mode is 4, the mode-set param
	     *   contains '2,3,5,6', then 5 will be chosen.
	     */
	    const pj_str_t STR_FMTP_MODE_SET = {"mode-set", 8};

	    if (pj_stricmp(&attr->setting.enc_fmtp.param[i].name,
			   &STR_FMTP_MODE_SET) == 0)
	    {
		const char *p;
		pj_size_t l;
		pj_int8_t diff = 99;

		p = pj_strbuf(&attr->setting.enc_fmtp.param[i].val);
		l = pj_strlen(&attr->setting.enc_fmtp.param[i].val);

		while (l--) {
		    if ((params.pt==PJMEDIA_RTP_PT_AMR && *p>='0' && *p<='7') ||
		        (params.pt==PJMEDIA_RTP_PT_AMRWB && *p>='0' && *p<='8'))
		    {
			pj_int8_t tmp = (pj_int8_t)(*p - '0' - enc_mode);

			if (PJ_ABS(diff) > PJ_ABS(tmp) ||
			    (PJ_ABS(diff) == PJ_ABS(tmp) && tmp > diff))
			{
			    diff = tmp;
			    if (diff == 0) break;
			}
		    }
		    ++p;
		}

		if (diff == 99)
		    goto on_error;

	    PJ_LOG(4, (THIS_FILE, "Enc mode set from enc_fmtp"));
		enc_mode = (pj_int8_t)(enc_mode + diff);

		break;
	    }
	}
    PJ_LOG(4, (THIS_FILE, "Enc mode set from default"));

    /* Initialize AMR specific settings */
	s = PJ_POOL_ZALLOC_T(pool, amr_settings_t);
	amr->codec_setting = s;

	s->enc_setting.amr_nb = (pj_uint8_t)(params.pt == PJMEDIA_RTP_PT_AMR);
	s->enc_setting.octet_aligned = octet_align;
	s->enc_setting.reorder = PJ_TRUE;
	s->enc_setting.cmr = 15;

	s->dec_setting.amr_nb = (pj_uint8_t)(params.pt == PJMEDIA_RTP_PT_AMR);
	s->dec_setting.octet_aligned = octet_align;
	s->dec_setting.reorder = PJ_TRUE;

	/* Apply encoder mode/bitrate */
	s->enc_mode = enc_mode;

	amr->bps = s->enc_setting.amr_nb?
				pjmedia_codec_amrnb_bitrates[s->enc_mode]:
				pjmedia_codec_amrwb_bitrates[s->enc_mode];


	PJ_LOG(4,(THIS_FILE, "AMR%s encoding mode: %d (%dbps)",
		  (s->enc_setting.amr_nb?"":"-WB"),
		  s->enc_mode,
		  amr->bps));



	/* Bind init coder/decoder */
	// Encoder
    amr->AMREncodeInit(&amr->encState, &amr->encSidState, 0);
    amr->enc_ready = PJ_TRUE;

    //Decoder
    amr->GSMInitDecode(&amr->decState, "PjDecoder");
    amr->dec_ready = PJ_TRUE;


    PJ_LOG(4, (THIS_FILE, "Open amr codec > DONE !!"));
    return PJ_SUCCESS;

    on_error:
        return PJMEDIA_CODEC_EFAILED;
}

/*
 * Close codec.
 */
static pj_status_t amr_codec_close( pjmedia_codec *codec )
{
    struct amr_private *amr;
    amr = (struct amr_private*) codec->codec_data;

    amr->AMREncodeExit(&amr->encState, &amr->encSidState);
    amr->enc_ready = PJ_FALSE;
    amr->GSMDecodeFrameExit(&amr->decState);
    amr->dec_ready = PJ_FALSE;

    PJ_LOG(4, (THIS_FILE, "AMR codec closed"));
    return PJ_SUCCESS;
}

/*
 * Modify codec settings.
 */
static pj_status_t  amr_codec_modify(pjmedia_codec *codec,
				      const pjmedia_codec_param *attr )
{

    return PJ_SUCCESS;
}


/*
 * Encode frame.
 */
#define NO_DATA 15

static pj_status_t amr_codec_encode(pjmedia_codec *codec,
				     const struct pjmedia_frame *input,
				     unsigned output_buf_len,
				     struct pjmedia_frame *output)
{
	struct amr_private *amr;
	amr = (struct amr_private*) codec->codec_data;

    pj_int16_t ret;
    unsigned samples_per_frame, nsamples;
    pj_size_t tx = 0;
    pj_uint8_t pt;
    int i;

    pj_int16_t *pcm_in   = (pj_int16_t*)input->buf;

    uint8_t ToC;
    static uint8_t CMR = NO_DATA /* No interleaving */;
    pj_uint8_t		     SID_FT;

    pj_assert(amr && input && output);

	struct amr_param params = amr_factory.amr_param[amr->param_id];
	pjmedia_codec_amr_pack_setting *setting = &amr->codec_setting->enc_setting;



    if (setting->amr_nb) {
    	SID_FT		= 8;
    }else{
    	SID_FT		= 9;
    }

	nsamples = input->size >> 1;
	samples_per_frame = params.samples_per_frame;
	pt = params.pt;

    PJ_ASSERT_RETURN(nsamples % samples_per_frame == 0,
		     PJMEDIA_CODEC_EPCMFRMINLEN);
    output->size = 0;

    /* Write cursor */
    pj_uint8_t *w = (pj_uint8_t*)output->buf;
    pj_uint8_t w_bitptr = 0;


    /* Code Mode Request, 4 bits */
	*w = (pj_uint8_t)(setting->cmr << 4);
	w_bitptr = 4;
	// Padding if octet aligned
	if (setting->octet_aligned) {
    	++w;
    	w_bitptr = 0;
	}

	/* Speech write cursor */
    pj_uint8_t *w_speech = (pj_uint8_t*)output->buf;
    pj_uint8_t w_speech_bitptr = 0;
    unsigned nframes = nsamples/samples_per_frame;
	if (setting->octet_aligned) {
    	// CMR
    	w_speech += 1;
    	// Frames TOC
    	w_speech += nframes;
    	tx += 1 + nframes;
    }else{
    	unsigned nbits = 4 + nframes * 6;
    	w_speech += nbits / 8;
    	w_speech_bitptr = nbits % 8;
    	tx += nbits / 8;
    	if(w_speech_bitptr > 0){
    		tx += 1;
    	}
    }

    /* Encode the frames */
    while (nsamples >= samples_per_frame) {
		/* Encode */

		unsigned out_size = 0;
		int i = 0;
		pj_uint8_t outbuf[60 + 1];

		//That's fine with pjmedia cause input size is always already the good size
		enum Frame_Type_3GPP frametype;

		out_size = amr->AMREncode(amr->encState, amr->encSidState,
				pjmedia_codec_amr_get_mode(amr->bps),
				pcm_in, outbuf,
				&frametype, AMR_TX_WMF);

		if( out_size < 0 ) {
			//TODO : better conversion of AMR errors to pjmedia errors
			PJ_LOG(1, (THIS_FILE, "Error on encoding frame %d", out_size));
			return PJMEDIA_CODEC_EPCMFRMINLEN;
		}
		PJ_LOG(4, (THIS_FILE, "ENC %d for %d bps type %d/%d", out_size, amr->bps, frametype, outbuf[0]));


		/* TOC header */
		pj_uint8_t TOC, FT, Q;
		pj_bool_t F;

		F = (nsamples != samples_per_frame);
		FT = outbuf[0];
		Q  = 1;
		pj_assert(FT <= SID_FT || FT == 14 || FT == 15);

		TOC = (pj_uint8_t)((F<<5) | (FT<<1) | Q);
		if (w_bitptr == 0) {
		    *w = (pj_uint8_t)(TOC<<2);
		    w_bitptr = 6;
		} else if (w_bitptr == 2) {
		    *w++ |= TOC;
		    w_bitptr = 0;
		} else if (w_bitptr == 4) {
		    *w++ |= TOC>>2;
		    *w = (pj_uint8_t)(TOC<<6);
		    w_bitptr = 2;
		} else if (w_bitptr == 6) {
		    *w++ |= TOC>>4;
		    *w = (pj_uint8_t)(TOC<<4);
		    w_bitptr = 4;
		}
		// Padding if octet aligned
		if (setting->octet_aligned) {
		    ++w;
		    w_bitptr = 0;
		}

		// Copy content of the speech frame (without header = 1)
		if(w_speech_bitptr == 0){
			pj_memcpy(w_speech, &outbuf[1], sizeof(pj_uint8_t) * (out_size - 1));
		}else{
			for(i=1; i < out_size - 1; i++){
				if(w_speech_bitptr == 2){
					*w_speech++ |= (pj_uint8_t)(outbuf[i] >> 2);
					*w_speech = (pj_uint8_t)((outbuf[i] & 0x3) << 6);
				}else if(w_speech_bitptr == 4){
					*w_speech++ |= (pj_uint8_t)(outbuf[i] >> 4);
					*w_speech = (pj_uint8_t)((outbuf[i] & 0xF) << 4);
				}else if(w_speech_bitptr == 6){
					*w_speech++ |= (pj_uint8_t)(outbuf[i] >> 6);
					*w_speech = (pj_uint8_t)((outbuf[i] & 63) << 2);
				}
			}
		}

		pcm_in += samples_per_frame;
		nsamples -= samples_per_frame;
		// speech +2 of ietf header+toc - 1 of decode wmf header
		tx += out_size - 1;
    }



	output->size = tx;
	output->type = PJMEDIA_FRAME_TYPE_AUDIO;
	output->timestamp = input->timestamp;

	return PJ_SUCCESS;
}


/*
 * Get frames in the packet.
 */

static pj_status_t  amr_codec_parse( pjmedia_codec *codec,
				     void *pkt,
				     pj_size_t pkt_size,
				     const pj_timestamp *ts,
				     unsigned *frame_cnt,
				     pjmedia_frame frames[])
{
		struct amr_private *amr;
		amr = (struct amr_private*) codec->codec_data;


	    PJ_ASSERT_RETURN(frame_cnt, PJ_EINVAL);
	    PJ_LOG(4, (THIS_FILE, "DEC : parse amr packet"));
		pj_status_t result = parse_amr(amr, pkt,  pkt_size, ts, frame_cnt, frames);
		PJ_LOG(4, (THIS_FILE, "DEC : Found, %d frames", *frame_cnt));
		return result;
}



static pj_status_t amr_codec_decode(pjmedia_codec *codec,
				     const struct pjmedia_frame *input,
				     unsigned output_buf_len,
				     struct pjmedia_frame *output)
{

	struct amr_private *amr;
	unsigned samples_per_frame;
	pj_uint8_t pt;

	amr = (struct amr_private*) codec->codec_data;

	struct amr_param params = amr_factory.amr_param[amr->param_id];
	samples_per_frame = params.samples_per_frame;
	pt = params.pt;

    PJ_ASSERT_RETURN(output_buf_len >= samples_per_frame << 1,
		     PJMEDIA_CODEC_EPCMTOOSHORT);

    pjmedia_codec_amr_bit_info *info = (pjmedia_codec_amr_bit_info*) &input->bit_info;

    if (input->type == PJMEDIA_FRAME_TYPE_AUDIO) {
    	PJ_LOG(4, (THIS_FILE, "DEC : frame %d with %d", info->frame_type, input->size));
    	/*
		pj_uint8_t inbuf[60 + 1];
		inbuf[0] = ((pj_uint8_t)info->frame_type) & 0x0f;
		pj_uint8_t *inspeech = inbuf;
		inspeech += 1;
		pj_memcpy(inspeech, input->buf, input->size);
		*/
    	unsigned decoded = amr->AMRDecode(amr->decState, info->frame_type, input->buf, output->buf , MIME_IETF);

    	PJ_LOG(4, (THIS_FILE, "DEC : ed : %d", decoded));
    }

//	pj_bzero(output->buf, output->size);
    output->type = PJMEDIA_FRAME_TYPE_AUDIO;
    output->size = samples_per_frame << 1;
    output->timestamp.u64 = input->timestamp.u64;

    return PJ_SUCCESS;
}

/*
 * Recover lost frame.
 */
/*
static pj_status_t  amr_codec_recover(pjmedia_codec *codec,
				      unsigned output_buf_len,
				      struct pjmedia_frame *output)
{

	//TODO : reactivate this
	struct silk_private *silk;
	silk = (struct silk_private*) codec->codec_data;

	SKP_int16 nBytes;
    int ret;
    PJ_ASSERT_RETURN(output, PJ_EINVAL);

    PJ_LOG(5, (THIS_FILE, "Recover silk frame"));

    // Decode
	ret = SKP_Silk_SDK_Decode( silk->psDec, &silk->dec, 1, NULL, 0, output->buf, &nBytes );
	if(ret){
		PJ_LOG(1, (THIS_FILE, "Failed to decode silk frame"));
	}

	output->size = nBytes;
    output->type = PJMEDIA_FRAME_TYPE_AUDIO;

    return PJ_SUCCESS;
}
*/


#endif
