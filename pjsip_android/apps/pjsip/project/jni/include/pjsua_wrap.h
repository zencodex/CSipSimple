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

#ifndef SWIG_pjsua_WRAP_H_
#define SWIG_pjsua_WRAP_H_

class SwigDirector_Callback : public Callback, public Swig::Director {

public:
    void swig_connect_director(JNIEnv *jenv, jobject jself, jclass jcls, bool swig_mem_own, bool weak_global);
    SwigDirector_Callback(JNIEnv *jenv);
    virtual ~SwigDirector_Callback();
    virtual void on_call_state(pjsua_call_id call_id, pjsip_event *e);
    virtual void on_incoming_call(pjsua_acc_id acc_id, pjsua_call_id call_id, pjsip_rx_data *rdata);
    virtual void on_call_tsx_state(pjsua_call_id call_id, pjsip_transaction *tsx, pjsip_event *e);
    virtual void on_call_media_state(pjsua_call_id call_id);
    virtual void on_stream_created(pjsua_call_id call_id, pjmedia_session *sess, unsigned int stream_idx, pjmedia_port **p_port);
    virtual void on_stream_destroyed(pjsua_call_id call_id, pjmedia_session *sess, unsigned int stream_idx);
    virtual void on_dtmf_digit(pjsua_call_id call_id, int digit);
    virtual void on_call_transfer_request(pjsua_call_id call_id, pj_str_t const *dst, pjsip_status_code *code);
    virtual void on_call_transfer_status(pjsua_call_id call_id, int st_code, pj_str_t const *st_text, pj_bool_t final_, pj_bool_t *p_cont);
    virtual void on_call_replace_request(pjsua_call_id call_id, pjsip_rx_data *rdata, int *st_code, pj_str_t *st_text);
    virtual void on_call_replaced(pjsua_call_id old_call_id, pjsua_call_id new_call_id);
    virtual void on_reg_state(pjsua_acc_id acc_id);
    virtual void on_buddy_state(pjsua_buddy_id buddy_id);
    virtual void on_pager(pjsua_call_id call_id, pj_str_t const *from, pj_str_t const *to, pj_str_t const *contact, pj_str_t const *mime_type, pj_str_t const *body);
    virtual void on_pager2(pjsua_call_id call_id, pj_str_t const *from, pj_str_t const *to, pj_str_t const *contact, pj_str_t const *mime_type, pj_str_t const *body, pjsip_rx_data *rdata);
    virtual void on_pager_status(pjsua_call_id call_id, pj_str_t const *to, pj_str_t const *body, pjsip_status_code status, pj_str_t const *reason);
    virtual void on_pager_status2(pjsua_call_id call_id, pj_str_t const *to, pj_str_t const *body, pjsip_status_code status, pj_str_t const *reason, pjsip_tx_data *tdata, pjsip_rx_data *rdata);
    virtual void on_typing(pjsua_call_id call_id, pj_str_t const *from, pj_str_t const *to, pj_str_t const *contact, pj_bool_t is_typing);
    virtual void on_nat_detect(pj_stun_nat_detect_result const *res);
    virtual void on_mwi_info(pjsua_acc_id acc_id, pj_str_t const *mime_type, pj_str_t const *body);
    virtual void on_setup_audio();
    virtual void on_teardown_audio();
    virtual void on_zrtp_show_sas(pj_str_t const *sas, int verified);
    virtual void on_zrtp_secure_on(pj_str_t const *cipher);
    virtual void on_zrtp_secure_off();
public:
    bool swig_overrides(int n) {
      return (n < 25 ? swig_override[n] : false);
    }
protected:
    bool swig_override[25];
};


#endif
