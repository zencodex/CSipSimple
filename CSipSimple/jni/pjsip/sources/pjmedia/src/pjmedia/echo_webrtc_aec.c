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


#include <pjmedia/echo.h>
#include <pjmedia/errno.h>
#include <pj/assert.h>
#include <pj/log.h>
#include <pj/pool.h>
#include <pjmedia/frame.h>

#if defined(PJMEDIA_HAS_WEBRTC_AEC) && PJMEDIA_HAS_WEBRTC_AEC != 0

#if defined(PJ_HAS_FLOATING_POINT) && PJ_HAS_FLOATING_POINT == 1
#define WEBRTC_AEC_USE_MOBILE 0
#else
#define WEBRTC_AEC_USE_MOBILE 1
#endif

#ifndef PJMEDIA_WEBRTC_USE_NS
#define PJMEDIA_WEBRTC_USE_NS PJ_FALSE
#endif

#ifndef PJMEDIA_WEBRTC_AEC_AGGRESSIVENESS
    #define PJMEDIA_WEBRTC_AEC_AGGRESSIVENESS kAecNlpModerate
#endif

#ifndef PJMEDIA_WEBRTC_NS_POLICY
    #define PJMEDIA_WEBRTC_NS_POLICY 0
#endif


#define THIS_FILE    "echo_webrtc_aec.c"

#if WEBRTC_AEC_USE_MOBILE == 1
#include <modules/audio_processing/aecm/include/echo_control_mobile.h>
#define W_WebRtcAec_Create WebRtcAecm_Create
#define W_WebRtcAec_Free WebRtcAecm_Free
#define W_WebRtcAec_get_error_code WebRtcAecm_get_error_code
#define W_WebRtcAec_Init(INST, CR) WebRtcAecm_Init(INST, CR)
#define W_WebRtcAec_BufferFarend WebRtcAecm_BufferFarend
#else
#include <modules/audio_processing/aec/include/echo_cancellation.h>
#define W_WebRtcAec_Create WebRtcAec_Create
#define W_WebRtcAec_Free WebRtcAec_Free
#define W_WebRtcAec_get_error_code WebRtcAec_get_error_code
#define W_WebRtcAec_Init(INST, CR) WebRtcAec_Init(INST, CR, CR)
#define W_WebRtcAec_BufferFarend WebRtcAec_BufferFarend
#endif

#include <modules/audio_processing/ns/include/noise_suppression_x.h>

#include "echo_internal.h"



pj_bool_t pjmedia_webrtc_use_ns = PJMEDIA_WEBRTC_USE_NS;

typedef struct webrtc_ec
{
	void*		AEC_inst;
    NsxHandle*	NS_inst;
    unsigned	samples_per_frame;
    unsigned	echo_tail;
    unsigned	echo_skew;
    unsigned   clock_rate;
    unsigned 	blockLen10ms;
    pj_int16_t*	tmp_frame;
    pj_int16_t*	tmp_frame2;
} webrtc_ec;


static void print_webrtc_aec_error(const char* tag, void *AEC_inst) {
	unsigned status = W_WebRtcAec_get_error_code(AEC_inst);
    PJ_LOG(4, (THIS_FILE, "WebRTC AEC ERROR (%s) %d ", tag, status));
}

/*
 * Create the AEC.
 */
PJ_DEF(pj_status_t) webrtc_aec_create(pj_pool_t *pool,
				     unsigned clock_rate,
				     unsigned channel_count,
				     unsigned samples_per_frame,
				     unsigned tail_ms,
				     unsigned options,
				     void **p_echo )
{
	webrtc_ec *echo;
    int sampling_rate;
    int status;

    *p_echo = NULL;

    echo = PJ_POOL_ZALLOC_T(pool, webrtc_ec);
    PJ_ASSERT_RETURN(echo != NULL, PJ_ENOMEM);

    // Alloc memory
    status = W_WebRtcAec_Create(&echo->AEC_inst);
    if(status){
    	return PJ_ENOMEM;
    }
PJ_LOG(4, (THIS_FILE, "Create webRTC AEC with clock rate %d", clock_rate));
    // Init
    status = W_WebRtcAec_Init(echo->AEC_inst,
    		clock_rate);

	if(status != 0) {
        if (echo->AEC_inst) {
            print_webrtc_aec_error("Init", echo->AEC_inst);
            W_WebRtcAec_Free(echo->AEC_inst);
            echo->AEC_inst = NULL;
        }
    	return PJ_EBUG;
    }

	// Set configuration -- sample code for future use
	// For now keep default values
/*
#if WEBRTC_AEC_USE_MOBILE == 1
	AecmConfig aecm_config;
	aecm_config.cngMode = AecmTrue;
	aecm_config.echoMode = 4;

    status = WebRtcAecm_set_config(echo->AEC_inst, aecm_config);
    if(status != 0) {
        print_webrtc_aec_error("Init config", echo->AEC_inst);
        WebRtcAec_Free(echo->AEC_inst);
    	return PJ_EBUG;
    }
#else
    AecConfig aec_config;
    aec_config.nlpMode = PJMEDIA_WEBRTC_AEC_AGGRESSIVENESS;
    aec_config.skewMode = kAecTrue;
    aec_config.metricsMode = kAecFalse;
    aec_config.delay_logging = kAecFalse;

    status = WebRtcAec_set_config(echo->AEC_inst, aec_config);
    if(status != 0) {
        print_webrtc_aec_error("Init config", echo->AEC_inst);
        WebRtcAec_Free(echo->AEC_inst);
    	return PJ_EBUG;
    }
#endif
*/

	if(pjmedia_webrtc_use_ns == PJ_TRUE){
		status = WebRtcNsx_Create(&echo->NS_inst);
		if(status != 0) {
			return PJ_ENOMEM;
		}

		status = WebRtcNsx_Init(echo->NS_inst, clock_rate);
		if(status != 0) {
			if(echo->AEC_inst){
				W_WebRtcAec_Free(echo->AEC_inst);
				echo->AEC_inst = NULL;
			}

			if (echo->NS_inst) {
				PJ_LOG(4, (THIS_FILE, "Could not initialize noise suppressor"));
				WebRtcNsx_Free(echo->NS_inst);
				echo->NS_inst = NULL;
			}
			return PJ_EBUG;
		}

		status = WebRtcNsx_set_policy(echo->NS_inst, PJMEDIA_WEBRTC_NS_POLICY);
		if (status != 0) {
			PJ_LOG(2, (THIS_FILE, "Could not set noise suppressor policy"));
		}
	}else{
		echo->NS_inst = NULL;
	}

    echo->samples_per_frame = samples_per_frame;
    echo->echo_tail = tail_ms;
    echo->echo_skew = 0;
    echo->clock_rate = clock_rate;
    echo->blockLen10ms = (10 * channel_count * clock_rate / 1000);

    /* Create temporary frames for echo cancellation */
    echo->tmp_frame = (pj_int16_t*) pj_pool_zalloc(pool, 2*samples_per_frame);
    PJ_ASSERT_RETURN(echo->tmp_frame != NULL, PJ_ENOMEM);
    echo->tmp_frame2 = (pj_int16_t*) pj_pool_zalloc(pool, 2*samples_per_frame);
    PJ_ASSERT_RETURN(echo->tmp_frame2 != NULL, PJ_ENOMEM);

    /* Done */
    *p_echo = echo;
    return PJ_SUCCESS;

}


/*
 * Destroy AEC
 */
PJ_DEF(pj_status_t) webrtc_aec_destroy(void *state )
{
    webrtc_ec *echo = (webrtc_ec*) state;
    PJ_ASSERT_RETURN(echo, PJ_EINVAL);

    if (echo->AEC_inst) {
    	W_WebRtcAec_Free(echo->AEC_inst);
    	echo->AEC_inst = NULL;
    }
    if (echo->NS_inst) {
        WebRtcNsx_Free(echo->NS_inst);
        echo->NS_inst = NULL;
    }

    return PJ_SUCCESS;
}


/*
 * Reset AEC
 */
PJ_DEF(void) webrtc_aec_reset(void *state )
{
    webrtc_ec *echo = (webrtc_ec*) state;
    pj_assert(echo != NULL);
    int status;
    /* re-initialize the EC */
	status = W_WebRtcAec_Init(echo->AEC_inst, echo->clock_rate);
    if(status != 0) {
        print_webrtc_aec_error("re-Init", echo->AEC_inst);
        return;
    } else {

#if WEBRTC_AEC_USE_MOBILE == 1
    	AecmConfig aecm_config;
    	aecm_config.cngMode = AecmTrue;
    	aecm_config.echoMode = 4;

        status = WebRtcAecm_set_config(echo->AEC_inst, aecm_config);
        if(status != 0) {
            print_webrtc_aec_error("re-Init config", echo->AEC_inst);
            return;
        }
#else
        AecConfig aec_config;
        aec_config.nlpMode = PJMEDIA_WEBRTC_AEC_AGGRESSIVENESS;
        aec_config.skewMode = kAecTrue;
        aec_config.metricsMode = kAecFalse;

        status = WebRtcAec_set_config(echo->AEC_inst, aec_config);
        if(status != 0) {
            print_webrtc_aec_error("re-Init config", echo->AEC_inst);
            return;
        }
#endif
    }
    PJ_LOG(4, (THIS_FILE, "WebRTC AEC reset succeeded"));
}


/*
 * Perform echo cancellation.
 */
PJ_DEF(pj_status_t) webrtc_aec_cancel_echo( void *state,
					   pj_int16_t *rec_frm,
					   const pj_int16_t *play_frm,
					   unsigned options,
					   void *reserved )
{
    webrtc_ec *echo = (webrtc_ec*) state;
    int status;
    unsigned i, tail_factor;

    /* Sanity checks */
    PJ_ASSERT_RETURN(echo && rec_frm && play_frm && options==0 && reserved==NULL, PJ_EINVAL);

	tail_factor = echo->samples_per_frame / echo->blockLen10ms;
    for(i=0; i < echo->samples_per_frame; i+= echo->blockLen10ms) {
    	if(echo->NS_inst){
			/* Noise suppression */
			status = WebRtcNsx_Process(echo->NS_inst,
									  (WebRtc_Word16 *) (&rec_frm[i]),
									  NULL,
									  (WebRtc_Word16 *) (&echo->tmp_frame[i]),
									  NULL);
			if (status != 0) {
				PJ_LOG(1, (THIS_FILE, "Error suppressing noise"));
				return PJ_EBUG;
			}
    	}

		/* Feed farend buffer */
		status = W_WebRtcAec_BufferFarend(echo->AEC_inst, &play_frm[i], echo->blockLen10ms);
		if(status != 0) {
			print_webrtc_aec_error("buffer farend", echo->AEC_inst);
			return PJ_EBUG;
		}


		/* Process echo cancellation */
#if WEBRTC_AEC_USE_MOBILE == 1
		status = WebRtcAecm_Process(echo->AEC_inst,
							(WebRtc_Word16 *) (&rec_frm[i]),
							(echo->NS_inst)?(WebRtc_Word16 *) (&echo->tmp_frame[i]):(WebRtc_Word16 *) (&rec_frm[i]),
							(WebRtc_Word16 *) (&echo->tmp_frame2[i]),
							echo->blockLen10ms,
							echo->echo_tail / tail_factor);
#else
		status = WebRtcAec_Process(echo->AEC_inst,
							(echo->NS_inst)?(WebRtc_Word16 *) (&echo->tmp_frame[i]):(WebRtc_Word16 *) (&rec_frm[i]),
							NULL,
							(WebRtc_Word16 *) (&echo->tmp_frame2[i]),
							NULL,
							echo->blockLen10ms,
							echo->echo_tail / tail_factor,
							echo->echo_skew);
#endif
		if(status != 0){
			print_webrtc_aec_error("Process echo", echo->AEC_inst);
			return;
		}
    }


    /* Copy temporary buffer back to original rec_frm */
    pjmedia_copy_samples(rec_frm, echo->tmp_frame2, echo->samples_per_frame);

    return PJ_SUCCESS;

}


#endif
