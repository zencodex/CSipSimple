#ifndef __PJSUA_JNI_ADDONS_H__
#define __PJSUA_JNI_ADDONS_H__

#include <pj/config_site.h>
#include <pjsua-lib/pjsua.h>
#include <pjsua-lib/pjsua_internal.h>
#include <pjmedia_audiodev.h>
#include <android/log.h>

#ifdef __cplusplus
extern "C" {
#endif
void ringback_start();
void ring_stop(pjsua_call_id call_id);
void init_ringback_tone();
void destroy_ringback_tone();
void app_on_call_state(pjsua_call_id call_id, pjsip_event *e);
static void pj_android_log_msg(int level, const char *data, int len);
static pj_bool_t on_rx_request_tcp_hack(pjsip_rx_data *rdata);
#ifdef __cplusplus
}
#endif

PJ_BEGIN_DECL

PJ_DECL(int) codecs_get_nbr();
PJ_DECL(pj_str_t) codecs_get_id(int codec_id) ;
PJ_DECL(pj_status_t) test_audio_dev(unsigned int clock_rate, unsigned int ptime);
PJ_DECL(pj_status_t) send_dtmf_info(int current_call, pj_str_t digits);
PJ_DECL(pj_str_t) call_dump(pjsua_call_id call_id, pj_bool_t with_media, const char *indent);
PJ_DECL(pj_bool_t) can_use_tls();
PJ_DECL(pj_bool_t) can_use_srtp();
PJ_DECL(pj_bool_t) is_call_secure(pjsua_call_id call_id);
PJ_DECL(pj_status_t) media_transports_create_ipv6(pjsua_transport_config rtp_cfg);
PJ_DECL(pj_str_t) get_error_message(int status);
PJ_DECL(pj_status_t) csipsimple_init(pjsua_config *ua_cfg,
				pjsua_logging_config *log_cfg,
				pjsua_media_config *media_cfg);
PJ_DECL(pj_status_t) csipsimple_destroy(void);
PJ_DECL(pj_status_t) send_keep_alive(int acc_id);
PJ_DECL(pj_status_t) set_turn_cfg(pjsua_media_config *media_cfg, pj_str_t username, pj_str_t data);
PJ_DECL(void) set_use_compact_form(pj_bool_t use_compact_form);
PJ_DECL(void) set_no_update(pj_bool_t use_no_update);
PJ_END_DECL

#endif
