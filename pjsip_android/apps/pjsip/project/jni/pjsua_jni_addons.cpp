#include <pjsua_jni_addons.h>

#define THIS_FILE		"pjsua_jni_addons.c"

PJ_DECL(int) codecs_get_nbr() {
	pjsua_codec_info c[32];
	unsigned i, count = PJ_ARRAY_SIZE(c);
	pj_status_t status = pjsua_enum_codecs(c, &count);
	if (status == PJ_SUCCESS) {
		return count;
	}
	return 0;
}

PJ_DECL(pj_str_t) codecs_get_id(int codec_id) {
	pjsua_codec_info c[32];
	unsigned i, count = PJ_ARRAY_SIZE(c);

	pjsua_enum_codecs(c, &count);
	if (codec_id < count) {
		return c[codec_id].codec_id;
	}
	return pj_str((char *)"INVALID/8000/1");
}

PJ_DECL(pj_str_t) call_dump(pjsua_call_id call_id, pj_bool_t with_media, const char *indent){
	char some_buf[1024 * 3];
    pjsua_call_dump(call_id, with_media, some_buf,
		    sizeof(some_buf), indent);
    return pj_str(some_buf);
}

PJ_DECL(pj_bool_t) can_use_tls(){
	return PJ_HAS_SSL_SOCK;
}

PJ_DECL(pj_bool_t) can_use_srtp(){
	return PJMEDIA_HAS_SRTP;
}


PJ_DECL(pj_status_t) test_audio_dev(unsigned int clock_rate, unsigned int ptime) {

	pjmedia_aud_param param;
	pjmedia_aud_test_results result;
	pj_status_t status;

	pjmedia_dir dir = PJMEDIA_DIR_ENCODING_DECODING;

	if (dir & PJMEDIA_DIR_CAPTURE) {
		status = pjmedia_aud_dev_default_param(0, &param);
	} else {
		status = pjmedia_aud_dev_default_param(0, &param);
	}

	if (status != PJ_SUCCESS) {
		PJ_LOG(1, (THIS_FILE, "pjmedia_aud_dev_default_param() %d", status));
		return status;
	}

	param.dir = dir;
	param.rec_id = 0;
	param.play_id = 0;
	param.clock_rate = clock_rate;
	param.channel_count = 1;
	param.samples_per_frame = clock_rate * 1 * ptime / 1000;

	/* Latency settings */
	param.flags |= (PJMEDIA_AUD_DEV_CAP_INPUT_LATENCY
			| PJMEDIA_AUD_DEV_CAP_OUTPUT_LATENCY);
	param.input_latency_ms = PJMEDIA_SND_DEFAULT_REC_LATENCY;
	param.output_latency_ms = PJMEDIA_SND_DEFAULT_PLAY_LATENCY;

	PJ_LOG(3,(THIS_FILE, "Performing test.."));

	status = pjmedia_aud_test(&param, &result);
	if (status != PJ_SUCCESS) {
		PJ_LOG(1, (THIS_FILE, "Test has completed with error %d", status));
		return status;
	}

	PJ_LOG(3,(THIS_FILE, "Done. Result:"));

	if (dir & PJMEDIA_DIR_CAPTURE) {
		if (result.rec.frame_cnt == 0) {
			PJ_LOG(1,(THIS_FILE, "Error: no frames captured!"));
		} else {
			PJ_LOG(3,(THIS_FILE, "  %-20s: interval (min/max/avg/dev)=%u/%u/%u/%u, burst=%u",
							"Recording result",
							result.rec.min_interval,
							result.rec.max_interval,
							result.rec.avg_interval,
							result.rec.dev_interval,
							result.rec.max_burst));
		}
	}

	if (dir & PJMEDIA_DIR_PLAYBACK) {
		if (result.play.frame_cnt == 0) {
			PJ_LOG(1,(THIS_FILE, "Error: no playback!"));
		} else {
			PJ_LOG(3,(THIS_FILE, "  %-20s: interval (min/max/avg/dev)=%u/%u/%u/%u, burst=%u",
							"Playback result",
							result.play.min_interval,
							result.play.max_interval,
							result.play.avg_interval,
							result.play.dev_interval,
							result.play.max_burst));
		}
	}

	if (dir == PJMEDIA_DIR_CAPTURE_PLAYBACK) {
		if (result.rec_drift_per_sec == 0) {
			PJ_LOG(3,(THIS_FILE, " No clock drift detected"));
		} else {
			const char *which = result.rec_drift_per_sec >= 0 ? "faster"
					: "slower";
			unsigned drift =
					result.rec_drift_per_sec >= 0 ? result.rec_drift_per_sec
							: -result.rec_drift_per_sec;

			PJ_LOG(3,(THIS_FILE, " Clock drifts detected. Capture device "
							"is running %d samples per second %s "
							"than the playback device",
							drift, which));
		}
	}

	return status;
}

PJ_DECL(pj_status_t) send_dtmf_info(int current_call, pj_str_t digits){
	/* Send DTMF with INFO */
	if (current_call == -1) {
		PJ_LOG(3,(THIS_FILE, "No current call"));
		return PJ_EINVAL;
	} else {
		const pj_str_t SIP_INFO = pj_str((char *)"INFO");
		int call = current_call;
		int i;
		pj_status_t status = PJ_EINVAL;
		pjsua_msg_data msg_data;
		PJ_LOG(4,(THIS_FILE, "SEND DTMF : %.s", digits.slen, digits.ptr));

		for (i=0; i<digits.slen; ++i) {
			char body[80];

			pjsua_msg_data_init(&msg_data);
			msg_data.content_type = pj_str((char *)"application/dtmf-relay");

			pj_ansi_snprintf(body, sizeof(body),
					 "Signal=%c\r\n"
					 "Duration=160",
					 digits.ptr[i]);
			msg_data.msg_body = pj_str(body);
			PJ_LOG(4,(THIS_FILE, "Send %.s", msg_data.msg_body.slen, msg_data.msg_body.ptr));

			status = pjsua_call_send_request(current_call, &SIP_INFO,
							 &msg_data);
			if (status != PJ_SUCCESS) {
				PJ_LOG(2,(THIS_FILE, "Failed %d", status));
			break;
			}
		}
		return status;
	}
}

PJ_DECL(pj_status_t) media_transports_create_ipv6(pjsua_transport_config rtp_cfg) {
    pjsua_media_transport tp[PJSUA_MAX_CALLS];
    pj_status_t status;
    int port = rtp_cfg.port;
    unsigned i;

    //TODO : here should be get from config
    for (i=0; i<PJSUA_MAX_CALLS; ++i) {
	enum { MAX_RETRY = 10 };
	pj_sock_t sock[2];
	pjmedia_sock_info si;
	unsigned j;

	/* Get rid of uninitialized var compiler warning with MSVC */
	status = PJ_SUCCESS;

	for (j=0; j<MAX_RETRY; ++j) {
	    unsigned k;

	    for (k=0; k<2; ++k) {
		pj_sockaddr bound_addr;

		status = pj_sock_socket(pj_AF_INET6(), pj_SOCK_DGRAM(), 0, &sock[k]);
		if (status != PJ_SUCCESS)
		    break;

		status = pj_sockaddr_init(pj_AF_INET6(), &bound_addr,
					  &rtp_cfg.bound_addr,
					  (unsigned short)(port+k));
		if (status != PJ_SUCCESS)
		    break;

		status = pj_sock_bind(sock[k], &bound_addr,
				      pj_sockaddr_get_len(&bound_addr));
		if (status != PJ_SUCCESS)
		    break;
	    }
	    if (status != PJ_SUCCESS) {
		if (k==1)
		    pj_sock_close(sock[0]);

		if (port != 0)
		    port += 10;
		else
		    break;

		continue;
	    }

	    pj_bzero(&si, sizeof(si));
	    si.rtp_sock = sock[0];
	    si.rtcp_sock = sock[1];

	    pj_sockaddr_init(pj_AF_INET6(), &si.rtp_addr_name,
			     &rtp_cfg.public_addr,
			     (unsigned short)(port));
	    pj_sockaddr_init(pj_AF_INET6(), &si.rtcp_addr_name,
			     &rtp_cfg.public_addr,
			     (unsigned short)(port+1));

	    status = pjmedia_transport_udp_attach(pjsua_get_pjmedia_endpt(),
						  NULL,
						  &si,
						  0,
						  &tp[i].transport);
	    if (port != 0)
		port += 10;
	    else
		break;

	    if (status == PJ_SUCCESS)
		break;
	}

	if (status != PJ_SUCCESS) {
	    pjsua_perror(THIS_FILE, "Error creating IPv6 UDP media transport",
			 status);
	    for (j=0; j<i; ++j) {
		pjmedia_transport_close(tp[j].transport);
	    }
	    return status;
	}
    }

    return pjsua_media_transports_attach(tp, i, PJ_TRUE);
}




//Wrap start & stop
PJ_DECL(pj_status_t) csipsimple_init(pjsua_config *ua_cfg,
				pjsua_logging_config *log_cfg,
				pjsua_media_config *media_cfg){
	pj_status_t result;
	log_cfg->cb = &pj_android_log_msg;
	result = (pj_status_t) pjsua_init(ua_cfg, log_cfg, media_cfg);
	if(result == PJ_SUCCESS){
		init_ringback_tone();
	}
	return result;
}

PJ_DECL(pj_status_t) csipsimple_destroy(void){
	destroy_ringback_tone();
	return (pj_status_t) pjsua_destroy();
}


// Android app glue

#define LOGV(...) __android_log_print(ANDROID_LOG_VERBOSE, "libpjsip", __VA_ARGS__)
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG  , "libpjsip", __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO   , "libpjsip", __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN   , "libpjsip", __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR  , "libpjsip", __VA_ARGS__)


static void pj_android_log_msg(int level, const char *data, int len) {
	if (level <= 1) {
		LOGE("%s", data);
	} else if (level == 2) {
		LOGW("%s", data);
	} else if (level == 3) {
		LOGI("%s", data);
	} else if (level == 4) {
		LOGD("%s", data);
	} else if (level >= 5) {
		LOGV("%s", data);
	}
}


//---------------------
// RINGBACK MANAGEMENT-
// --------------------
/* Ringtones		    US	       UK  */
#define RINGBACK_FREQ1	    440	    /* 400 */
#define RINGBACK_FREQ2	    480	    /* 450 */
#define RINGBACK_ON	    2000    /* 400 */
#define RINGBACK_OFF	    4000    /* 200 */
#define RINGBACK_CNT	    1	    /* 2   */
#define RINGBACK_INTERVAL   4000    /* 2000 */

static struct app_config {
	pj_pool_t		   *pool;
    int			    ringback_slot;
    int			    ringback_cnt;
    pjmedia_port	   *ringback_port;
    pj_bool_t ringback_on;
} app_config;

void ringback_start(){
	if (app_config.ringback_on) {
		//Already ringing back
		return;
	}
	app_config.ringback_on = PJ_TRUE;
    if (++app_config.ringback_cnt==1 && app_config.ringback_slot!=PJSUA_INVALID_ID){
    	pjsua_conf_connect(app_config.ringback_slot, 0);
    }
}

void ring_stop(pjsua_call_id call_id) {
    if (app_config.ringback_on) {
    	app_config.ringback_on = PJ_FALSE;

		pj_assert(app_config.ringback_cnt>0);
		if (--app_config.ringback_cnt == 0 &&
			app_config.ringback_slot!=PJSUA_INVALID_ID)  {
			pjsua_conf_disconnect(app_config.ringback_slot, 0);
			pjmedia_tonegen_rewind(app_config.ringback_port);
		}
    }
}

void init_ringback_tone(){
	pj_status_t status;
	pj_str_t name;
	pjmedia_tone_desc tone[RINGBACK_CNT];
	unsigned i;

	app_config.pool = pjsua_pool_create("pjsua-app", 1000, 1000);
	app_config.ringback_slot=PJSUA_INVALID_ID;
	app_config.ringback_on = PJ_FALSE;
	app_config.ringback_cnt = 0;

	//Ringback
	name = pj_str((char *)"ringback");
	status = pjmedia_tonegen_create2(app_config.pool, &name,
					 16000,
					 1,
					 320,
					 16, PJMEDIA_TONEGEN_LOOP,
					 &app_config.ringback_port);
	if (status != PJ_SUCCESS){
		goto on_error;
	}

	pj_bzero(&tone, sizeof(tone));
	for (i=0; i<RINGBACK_CNT; ++i) {
		tone[i].freq1 = RINGBACK_FREQ1;
		tone[i].freq2 = RINGBACK_FREQ2;
		tone[i].on_msec = RINGBACK_ON;
		tone[i].off_msec = RINGBACK_OFF;
	}
	tone[RINGBACK_CNT-1].off_msec = RINGBACK_INTERVAL;
	pjmedia_tonegen_play(app_config.ringback_port, RINGBACK_CNT, tone, PJMEDIA_TONEGEN_LOOP);
	status = pjsua_conf_add_port(app_config.pool, app_config.ringback_port,
					 &app_config.ringback_slot);
	if (status != PJ_SUCCESS){
		goto on_error;
	}
	return;

	on_error :{
		pj_pool_release(app_config.pool);
	}
}

void destroy_ringback_tone(){
	/* Close ringback port */
	if (app_config.ringback_port &&
	app_config.ringback_slot != PJSUA_INVALID_ID){
		pjsua_conf_remove_port(app_config.ringback_slot);
		app_config.ringback_slot = PJSUA_INVALID_ID;
		pjmedia_port_destroy(app_config.ringback_port);
		app_config.ringback_port = NULL;
	}
}

void app_on_call_state(pjsua_call_id call_id, pjsip_event *e) {
	pjsua_call_info call_info;
	pjsua_call_get_info(call_id, &call_info);

	if (call_info.state == PJSIP_INV_STATE_DISCONNECTED) {
		/* Stop all ringback for this call */
		ring_stop(call_id);
		PJ_LOG(3,(THIS_FILE, "Call %d is DISCONNECTED [reason=%d (%s)]",
						call_id,
						call_info.last_status,
						call_info.last_status_text.ptr));
	} else {
		if (call_info.state == PJSIP_INV_STATE_EARLY) {
			int code;
			pj_str_t reason;
			pjsip_msg *msg;

			/* This can only occur because of TX or RX message */
			pj_assert(e->type == PJSIP_EVENT_TSX_STATE);

			if (e->body.tsx_state.type == PJSIP_EVENT_RX_MSG) {
				msg = e->body.tsx_state.src.rdata->msg_info.msg;
			} else {
				msg = e->body.tsx_state.src.tdata->msg;
			}

			code = msg->line.status.code;
			reason = msg->line.status.reason;

			/* Start ringback for 180 for UAC unless there's SDP in 180 */
			if (call_info.role == PJSIP_ROLE_UAC && code == 180 && msg->body
					== NULL && call_info.media_status == PJSUA_CALL_MEDIA_NONE) {
				ringback_start();
			}

			PJ_LOG(3,(THIS_FILE, "Call %d state changed to %s (%d %.*s)",
							call_id, call_info.state_text.ptr,
							code, (int)reason.slen, reason.ptr));
		} else {
			PJ_LOG(3,(THIS_FILE, "Call %d state changed to %s",
							call_id,
							call_info.state_text.ptr));
		}
	}
}


