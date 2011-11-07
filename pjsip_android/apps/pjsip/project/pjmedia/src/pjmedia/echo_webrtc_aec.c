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

#if defined(PJMEDIA_HAS_WEBRTC_AEC) && PJMEDIA_HAS_WEBRTC_AEC != 0

#if defined(PJ_ANDROID)
#define WEBRTC_AEC_USE_MOBILE 1
#endif

#define PJMEDIA_WEBRTC_USE_NS 0

#ifndef PJMEDIA_WEBRTC_AEC_AGGRESSIVENESS
    #define PJMEDIA_WEBRTC_AEC_AGGRESSIVENESS kAecNlpModerate
#endif

#ifndef PJMEDIA_WEBRTC_NS_POLICY
    #define PJMEDIA_WEBRTC_NS_POLICY 0
#endif

#define WEBRTC_SUBFRAME_LEN   160    // WebRTC AEC only allows max 160 samples/frame

#define THIS_FILE    "echo_webrtc_aec.c"

#if WEBRTC_AEC_USE_MOBILE == 1
#include <modules/audio_processing/aecm/interface/echo_control_mobile.h>
#else
#include <modules/audio_processing/aec/interface/echo_cancellation.h>
#endif
#include <modules/audio_processing/ns/interface/noise_suppression_x.h>

#include "echo_internal.h"

typedef struct webrtc_ec
{
	void*		AEC_inst;
    NsxHandle*	NS_inst;
    unsigned	samples_per_frame;
    unsigned	echo_tail;
    unsigned	echo_skew;
    unsigned    clock_rate;
    pj_int16_t*	tmp_frame;
    pj_int16_t*	tmp_frame2;
} webrtc_ec;


static void print_webrtc_aec_error(const char* tag, void *AEC_inst) {
#if WEBRTC_AEC_USE_MOBILE == 1
	unsigned status = WebRtcAecm_get_error_code(AEC_inst);
#else
    unsigned status = WebRtcAec_get_error_code(AEC_inst);
#endif
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
	/*
    if (clock_rate != 16000) {
        PJ_LOG(4, (THIS_FILE, "Unsupported sample rate: %d", clock_rate));
        return PJ_EINVAL;
    }
    */

    echo = PJ_POOL_ZALLOC_T(pool, webrtc_ec);
    PJ_ASSERT_RETURN(echo != NULL, PJ_ENOMEM);

    // Alloc memory
#if WEBRTC_AEC_USE_MOBILE == 1
    status = WebRtcAecm_Create(&echo->AEC_inst);
#else
    status = WebRtcAec_Create(&echo->AEC_inst);
#endif
    if(status){
    	return PJ_ENOMEM;
    }
PJ_LOG(4, (THIS_FILE, "Create webRTC AEC with clock rate %d", clock_rate));
    // Init
#if WEBRTC_AEC_USE_MOBILE == 1
    status = WebRtcAecm_Init(echo->AEC_inst,
    		clock_rate);
#else
    status = WebRtcAec_Init(echo->AEC_inst,
    		clock_rate,
    		clock_rate);
#endif

	if(status != 0) {
        if (echo->AEC_inst) {
            print_webrtc_aec_error("Init", echo->AEC_inst);
        }
#if WEBRTC_AEC_USE_MOBILE == 1
    	WebRtcAecm_Free(echo->AEC_inst);
#else
    	WebRtcAec_Free(echo->AEC_inst);
#endif
    	return PJ_EBUG;
    }

#if WEBRTC_AEC_USE_MOBILE == 1
	// TODO
#else
	/*
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
    */
#endif

#if PJMEDIA_WEBRTC_USE_NS == 1
    status = WebRtcNsx_Create(&echo->NS_inst);
    if(status != 0) {
    	return PJ_ENOMEM;
    }

    status = WebRtcNsx_Init(echo->NS_inst, clock_rate);
    if(status != 0) {
        if (echo->NS_inst) {
    	    WebRtcNsx_Free(echo->NS_inst);
            PJ_LOG(4, (THIS_FILE, "Could not initialize noise suppressor"));
        }
    	return PJ_EBUG;
    }

    status = WebRtcNsx_set_policy(echo->NS_inst, PJMEDIA_WEBRTC_NS_POLICY);
    if (status != 0) {
        PJ_LOG(4, (THIS_FILE, "Could not set noise suppressor policy"));
    }
#else
    echo->NS_inst = NULL;
#endif

    echo->samples_per_frame = samples_per_frame;
    echo->echo_tail = tail_ms;
    echo->echo_skew = 0;
    echo->clock_rate = clock_rate;

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
#if WEBRTC_AEC_USE_MOBILE == 1
    	WebRtcAecm_Free(echo->AEC_inst);
#else
    	WebRtcAec_Free(echo->AEC_inst);
#endif
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
#if WEBRTC_AEC_USE_MOBILE == 1
	status = WebRtcAecm_Init(echo->AEC_inst, echo->clock_rate);
#else
    status = WebRtcAec_Init(echo->AEC_inst, echo->clock_rate, echo->clock_rate);
#endif
    if(status != 0) {
        print_webrtc_aec_error("re-Init", echo->AEC_inst);
        return;
    } else {

#if WEBRTC_AEC_USE_MOBILE == 1
		//TODO
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

	tail_factor = echo->samples_per_frame / WEBRTC_SUBFRAME_LEN;
    for(i=0; i < echo->samples_per_frame; i+= WEBRTC_SUBFRAME_LEN) {
    	if(echo->NS_inst){
			/* Noise suppression */
			status = WebRtcNsx_Process(echo->NS_inst,
									  (WebRtc_Word16 *) (&rec_frm[i]),
									  NULL,
									  (WebRtc_Word16 *) (&echo->tmp_frame[i]),
									  NULL);
			if (status != 0) {
				PJ_LOG(4, (THIS_FILE, "Error suppressing noise"));
				return PJ_EBUG;
			}
    	}

		/* Feed farend buffer */
#if WEBRTC_AEC_USE_MOBILE == 1
		status = WebRtcAecm_BufferFarend(echo->AEC_inst, &play_frm[i], WEBRTC_SUBFRAME_LEN);
#else
		status = WebRtcAec_BufferFarend(echo->AEC_inst, &play_frm[i], WEBRTC_SUBFRAME_LEN);
#endif
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
							WEBRTC_SUBFRAME_LEN,
							echo->echo_tail / tail_factor);
#else
		status = WebRtcAec_Process(echo->AEC_inst,
							(echo->NS_inst)?(WebRtc_Word16 *) (&echo->tmp_frame[i]):(WebRtc_Word16 *) (&rec_frm[i]),
							NULL,
							(WebRtc_Word16 *) (&echo->tmp_frame2[i]),
							NULL,
							WEBRTC_SUBFRAME_LEN,
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
