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

#if defined(PJ_HAS_FLOATING_POINT) && PJ_HAS_FLOATING_POINT != 0
#define WEBRTC_AEC_USE_MOBILE 0
#else
#define WEBRTC_AEC_USE_MOBILE 1
#endif



#if WEBRTC_AEC_USE_MOBILE == 1
#include <modules/audio_processing/aecm/interface/echo_control_mobile.h>
#else
#include <modules/audio_processing/aec/interface/echo_cancellation.h>
#endif

#include "echo_internal.h"

typedef struct webrtc_ec
{
	void *AEC_inst;

    unsigned		  samples_per_frame;
    unsigned		  echo_tail;
    unsigned		  echo_skew;
    pj_int16_t		 *tmp_frame;
} webrtc_ec;



PJ_DEF(void) print_webrtc_error(const char* tag, void *AEC_inst){
#if WEBRTC_AEC_USE_MOBILE == 1
	unsigned webrtc_status = WebRtcAecm_get_error_code(AEC_inst);
#else
	unsigned webrtc_status = WebRtcAec_get_error_code(AEC_inst);
#endif
	PJ_LOG(1, (tag, "WebRTC ERROR %d ", webrtc_status));
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
    int webrtc_status;

    *p_echo = NULL;

    echo = PJ_POOL_ZALLOC_T(pool, webrtc_ec);
    PJ_ASSERT_RETURN(echo != NULL, PJ_ENOMEM);


    // Alloc memory
#if WEBRTC_AEC_USE_MOBILE == 1
    webrtc_status = WebRtcAecm_Create(&echo->AEC_inst);
#else
    webrtc_status = WebRtcAec_Create(&echo->AEC_inst);
#endif
    if(webrtc_status){
    	return PJ_ENOMEM;
    }

    // Init
#if WEBRTC_AEC_USE_MOBILE == 1
    webrtc_status = WebRtcAecm_Init(echo->AEC_inst,
    		clock_rate);
#else
    webrtc_status = WebRtcAec_Init(echo->AEC_inst,
    		clock_rate,
    		clock_rate);
#endif

    if(webrtc_status){
#if WEBRTC_AEC_USE_MOBILE == 1
    	WebRtcAecm_Free(echo->AEC_inst);
#else
    	WebRtcAec_Free(echo->AEC_inst);
#endif
    	return PJ_ENOMEM;
    }

    echo->samples_per_frame = samples_per_frame;
    echo->echo_tail = tail_ms;
    echo->echo_skew = 0;


    /* Create temporary frame for echo cancellation */
    echo->tmp_frame = (pj_int16_t*) pj_pool_zalloc(pool, 2*samples_per_frame);
    PJ_ASSERT_RETURN(echo->tmp_frame != NULL, PJ_ENOMEM);

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

    PJ_ASSERT_RETURN(echo && echo->AEC_inst, PJ_EINVAL);

    if (echo->AEC_inst) {
#if WEBRTC_AEC_USE_MOBILE == 1
    	WebRtcAecm_Free(echo->AEC_inst);
#else
    	WebRtcAec_Free(echo->AEC_inst);
#endif
    	echo->AEC_inst = NULL;
    }

    return PJ_SUCCESS;
}


/*
 * Reset AEC
 */
PJ_DEF(void) webrtc_aec_reset(void *state )
{
#warning NOT YET IMPLEMENTED
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
    int webrtc_status;
    unsigned i, sub_frame_len, tail_factor;

    /* Sanity checks */
    PJ_ASSERT_RETURN(echo && rec_frm && play_frm && options==0 &&
		     reserved==NULL, PJ_EINVAL);

    // WebRTC AEC only allow max 160 samples/frame
	sub_frame_len = 160;
	tail_factor = echo->samples_per_frame / sub_frame_len;
    for(i=0; i < echo->samples_per_frame; i+=sub_frame_len){

		/* Preprocess farend */
#if WEBRTC_AEC_USE_MOBILE == 1
		webrtc_status = WebRtcAecm_BufferFarend(echo->AEC_inst, &play_frm[i], sub_frame_len);
#else
		webrtc_status = WebRtcAec_BufferFarend(echo->AEC_inst, &play_frm[i], sub_frame_len);
#endif
		if(webrtc_status){
			print_webrtc_error("buffer farend", echo->AEC_inst);
			return;
		}


		/* Process echo cancellation */
#if WEBRTC_AEC_USE_MOBILE == 1
		webrtc_status = WebRtcAec_Process(echo->AEC_inst,
							(WebRtc_Word16 *) (&rec_frm[i]),
							NULL,
							(WebRtc_Word16 *) (&echo->tmp_frame[i]),
							NULL,
							sub_frame_len,
							echo->echo_tail / tail_factor,
							echo->echo_skew);
#else
		webrtc_status = WebRtcAecm_Process(echo->AEC_inst,
							(WebRtc_Word16 *) (&rec_frm[i]),
							NULL,
							(WebRtc_Word16 *) (&echo->tmp_frame[i]),
							NULL,
							sub_frame_len,
							echo->echo_tail / tail_factor);
#endif
		if(webrtc_status){
			print_webrtc_error("Process echo", echo->AEC_inst);
			return;
		}
    }


    /* Copy temporary buffer back to original rec_frm */
    pjmedia_copy_samples(rec_frm, echo->tmp_frame, echo->samples_per_frame);

    return PJ_SUCCESS;

}


#endif
