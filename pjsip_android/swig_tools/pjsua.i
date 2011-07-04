
/* File : pjsua.i */
%module (directors="1") pjsua
%include "typemaps.i"
%include "enums.swg"
%include "arrays_java.i";
%include "carrays.i";

/* void* shall be handled as byte arrays */
%typemap(jni) void * "void *"
%typemap(jtype) void * "byte[]"
%typemap(jstype) void * "byte[]"
%typemap(javain) void * "$javainput"
%typemap(in) void * %{
	$1 = $input;
%}
%typemap(javadirectorin) void * "$jniinput"
%typemap(out) void * %{ 
	$result = $1; 
%}
%typemap(javaout) void * {
	return $jnicall;
}

// Do not generate the default proxy constructor or destructor
%nodefaultctor pjmedia_port;
%nodefaultdtor pjmedia_port;

// Add in pure Java code proxy constructor
%typemap(javacode) pjmedia_port %{
  /** This constructor creates the proxy which initially does not create nor own any C memory */
  public pjmedia_port() {
    this(0, false);
  }
%}

// Type typemaps for marshalling pjmedia_port **
%typemap(jni) pjmedia_port **pp_port "jobject"
%typemap(jtype) pjmedia_port **pp_port "pjmedia_port"
%typemap(jstype) pjmedia_port **pp_port "pjmedia_port"

// Typemaps for pjmedia_port ** as a parameter output type
%typemap(in) pjmedia_port **pp_port (pjmedia_port *ppMediaPort = 0) %{
  $1 = &ppMediaPort;
%}
%typemap(argout) pjmedia_port **pp_port {
  // Give Java proxy the C pointer (of newly created object)
  jclass clazz = jenv->FindClass("org/pjsip/pjsua/pjmedia_port");
  jfieldID fid = jenv->GetFieldID(clazz, "swigCPtr", "J");
  jlong cPtr = 0;
  *(pjmedia_port **)&cPtr = *$1;
  jenv->SetLongField($input, fid, cPtr);
}
%typemap(javain) pjmedia_port **pp_port "$javainput"

/* Arguments like 'pjsua_acc_id *p_acc_id' should be considered output args */
%apply pjsua_acc_id *OUTPUT { pjsua_acc_id *p_acc_id };
%apply pjsua_call_id *OUTPUT { pjsua_call_id *p_call_id };
%apply pjsua_transport_id *OUTPUT { pjsua_transport_id *p_id };
%apply pjsua_recorder_id *OUTPUT { pjsua_recorder_id *p_id };
%apply unsigned *INOUT { unsigned *count };
%apply int *OUTPUT { int *capture_dev };
%apply int *OUTPUT { int *playback_dev };
%apply pjsua_conf_port_id *OUTPUT { pjsua_conf_port_id *p_id };
//%pp_out(pjmedia_port)
/* We need to be able to pass arrays of pjmedia_tone_desc to pjmedia */
/* The array elements are passed by value (copied) */
JAVA_ARRAYSOFCLASSES(pjmedia_tone_desc)
%apply pjmedia_tone_desc[] {const pjmedia_tone_desc tones[]};
JAVA_ARRAYSOFCLASSES(pj_str_t)
%apply pj_str_t[]{pj_str_t nameserver[4]};

%header %{

#include <pjsua-lib/pjsua.h>
#include "pjsua_jni_addons.h"
#include "zrtp_android.h"

// LOGGING
#define THIS_FILE	"pjsua_wrap.cpp"

class Callback {
public:
	virtual ~Callback() {}
	virtual void on_call_state (pjsua_call_id call_id, pjsip_event *e) {}
	virtual void on_incoming_call (pjsua_acc_id acc_id, pjsua_call_id call_id,
		pjsip_rx_data *rdata) {}
	virtual void on_call_tsx_state (pjsua_call_id call_id, 
		pjsip_transaction *tsx,
		pjsip_event *e) {}
	virtual void on_call_media_state (pjsua_call_id call_id) {}
	virtual void on_stream_created (pjsua_call_id call_id, 
		pjmedia_session *sess,
		unsigned stream_idx, 
		pjmedia_port **p_port) {}
	virtual void on_stream_destroyed (pjsua_call_id call_id,
		pjmedia_session *sess, 
		unsigned stream_idx) {}
	virtual void on_dtmf_digit (pjsua_call_id call_id, int digit) {}
	virtual void on_call_transfer_request (pjsua_call_id call_id,
		const pj_str_t *dst,
		pjsip_status_code *code) {}
	virtual void on_call_transfer_status (pjsua_call_id call_id,
		int st_code,
		const pj_str_t *st_text,
		pj_bool_t final_,
		pj_bool_t *p_cont) {}
	virtual void on_call_replace_request (pjsua_call_id call_id,
		pjsip_rx_data *rdata,
		int *st_code,
		pj_str_t *st_text) {}
	virtual void on_call_replaced (pjsua_call_id old_call_id,
		pjsua_call_id new_call_id) {}
	virtual void on_reg_state (pjsua_acc_id acc_id) {}
	virtual void on_buddy_state (pjsua_buddy_id buddy_id) {}
	virtual void on_pager (pjsua_call_id call_id, const pj_str_t *from,
		const pj_str_t *to, const pj_str_t *contact,
		const pj_str_t *mime_type, const pj_str_t *body) {}
	virtual void on_pager2 (pjsua_call_id call_id, const pj_str_t *from,
		const pj_str_t *to, const pj_str_t *contact,
		const pj_str_t *mime_type, const pj_str_t *body,
		pjsip_rx_data *rdata) {}
	virtual void on_pager_status (pjsua_call_id call_id,
		const pj_str_t *to,
		const pj_str_t *body,
/*XXX		void *user_data,*/
		pjsip_status_code status,
		const pj_str_t *reason) {}
	virtual void on_pager_status2 (pjsua_call_id call_id,
		const pj_str_t *to,
		const pj_str_t *body,
/*XXX		void *user_data,*/
		pjsip_status_code status,
		const pj_str_t *reason,
		pjsip_tx_data *tdata,
		pjsip_rx_data *rdata) {}
	virtual void on_typing (pjsua_call_id call_id, const pj_str_t *from,
		const pj_str_t *to, const pj_str_t *contact,
		pj_bool_t is_typing) {}
	virtual void on_nat_detect (const pj_stun_nat_detect_result *res) {}
	virtual pjsip_redirect_op on_call_redirected (pjsua_call_id call_id, const pj_str_t *target) {}
	virtual void on_mwi_info (pjsua_acc_id acc_id, const pj_str_t *mime_type, const pj_str_t *body) {}
	
	
	virtual pj_status_t on_setup_audio (int clock_rate) {}
	virtual void on_teardown_audio () {}
	virtual int on_set_micro_source () {}
	
	virtual void on_zrtp_show_sas (const pj_str_t *sas, int verified) {}
	virtual void on_zrtp_secure_on (const pj_str_t *cipher) {}
	virtual void on_zrtp_secure_off () {}
	
};

static Callback* registeredCallbackObject = NULL;

extern "C" {
void on_call_state_wrapper(pjsua_call_id call_id, pjsip_event *e) {
	app_on_call_state(call_id, e);
	registeredCallbackObject->on_call_state(call_id, e);
}
    
void on_incoming_call_wrapper (pjsua_acc_id acc_id, pjsua_call_id call_id,
	pjsip_rx_data *rdata) {
	registeredCallbackObject->on_incoming_call(acc_id, call_id, rdata);
}
    
void on_call_tsx_state_wrapper (pjsua_call_id call_id, 
		pjsip_transaction *tsx,
		pjsip_event *e) {
		
	//Workaround for cancelling
	/*
	if (tsx->method.id==PJSIP_CANCEL_METHOD){
		if (tsx->role==PJSIP_ROLE_UAS) {
			pjsua_call_hangup(call_id,0, NULL, NULL);
		}       
	}
	*/
	registeredCallbackObject->on_call_tsx_state(call_id, tsx, e);
}
    
void on_call_media_state_wrapper (pjsua_call_id call_id) {
	ring_stop(call_id);
	registeredCallbackObject->on_call_media_state(call_id);
}
 

void on_stream_created_wrapper (pjsua_call_id call_id, 
		pjmedia_session *sess,
		unsigned stream_idx, 
		pjmedia_port **p_port) {
	registeredCallbackObject->on_stream_created(call_id, sess, stream_idx, p_port);
}

void on_stream_destroyed_wrapper (pjsua_call_id call_id,
	pjmedia_session *sess, 
	unsigned stream_idx) {
	registeredCallbackObject->on_stream_destroyed(call_id, sess, stream_idx);
}

void on_dtmf_digit_wrapper (pjsua_call_id call_id, int digit) {
	registeredCallbackObject->on_dtmf_digit(call_id, digit);
}

void on_call_transfer_request_wrapper (pjsua_call_id call_id,
	const pj_str_t *dst,
	pjsip_status_code *code) {
	registeredCallbackObject->on_call_transfer_request(call_id, dst, code);
}

void on_call_transfer_status_wrapper (pjsua_call_id call_id,
	int st_code,
	const pj_str_t *st_text,
	pj_bool_t final_,
	pj_bool_t *p_cont) {
	registeredCallbackObject->on_call_transfer_status(call_id, st_code, st_text, final_, p_cont);
}

void on_call_replace_request_wrapper (pjsua_call_id call_id,
	pjsip_rx_data *rdata,
	int *st_code,
	pj_str_t *st_text) {
	registeredCallbackObject->on_call_replace_request(call_id, rdata, st_code, st_text);
}

void on_call_replaced_wrapper (pjsua_call_id old_call_id,
	pjsua_call_id new_call_id) {
	registeredCallbackObject->on_call_replaced(old_call_id, new_call_id);
}

void on_reg_state_wrapper (pjsua_acc_id acc_id) {
	registeredCallbackObject->on_reg_state(acc_id);
}

void on_buddy_state_wrapper (pjsua_buddy_id buddy_id) {
	registeredCallbackObject->on_buddy_state(buddy_id);
}

void on_pager_wrapper (pjsua_call_id call_id, const pj_str_t *from,
	const pj_str_t *to, const pj_str_t *contact,
	const pj_str_t *mime_type, const pj_str_t *body) {
	registeredCallbackObject->on_pager(call_id, from, to, contact, mime_type, body);
}

void on_pager2_wrapper (pjsua_call_id call_id, const pj_str_t *from,
	const pj_str_t *to, const pj_str_t *contact,
	const pj_str_t *mime_type, const pj_str_t *body,
	pjsip_rx_data *rdata, pjsua_acc_id acc_id) {
	registeredCallbackObject->on_pager2(call_id, from, to, contact, mime_type, body, rdata);
}

void on_pager_status_wrapper (pjsua_call_id call_id,
	const pj_str_t *to,
	const pj_str_t *body,
	void *user_data,
	pjsip_status_code status,
	const pj_str_t *reason) {
	registeredCallbackObject->on_pager_status(call_id, to, body, /*XXX user_data,*/ status, reason);
}

void on_pager_status2_wrapper (pjsua_call_id call_id,
	const pj_str_t *to,
	const pj_str_t *body,
	void *user_data,
	pjsip_status_code status,
	const pj_str_t *reason,
	pjsip_tx_data *tdata,
	pjsip_rx_data *rdata, pjsua_acc_id acc_id) {
	registeredCallbackObject->on_pager_status2(call_id, to, body, /*XXX user_data,*/ status, reason, tdata, rdata);
}

void on_typing_wrapper (pjsua_call_id call_id, const pj_str_t *from,
	const pj_str_t *to, const pj_str_t *contact,
	pj_bool_t is_typing) {
	registeredCallbackObject->on_typing(call_id, from, to, contact, is_typing);
}

void on_nat_detect_wrapper (const pj_stun_nat_detect_result *res) {
	registeredCallbackObject->on_nat_detect(res);
}


pjsip_redirect_op on_call_redirected_wrapper (pjsua_call_id call_id, const pjsip_uri *target, const pjsip_event *e) {
	char uristr[PJSIP_MAX_URL_SIZE];
	int len;
	pj_str_t uri_pstr;

	len = pjsip_uri_print(PJSIP_URI_IN_FROMTO_HDR, target, uristr, 
			      sizeof(uristr));
	if (len < 1) {
	    pj_ansi_strcpy(uristr, "--URI too long--");
	}
	
	uri_pstr = pj_str(uristr);

	return registeredCallbackObject->on_call_redirected(call_id, &uri_pstr);
}

void on_mwi_info_wrapper (pjsua_acc_id acc_id, pjsua_mwi_info *mwi_info) {
	pj_str_t body;
	pj_str_t mime_type;
	char mime_type_c[80];
	
	// Ignore empty messages
	if (!mwi_info->rdata->msg_info.msg->body) {
		PJ_LOG(4, (THIS_FILE, "MWI info has no body"));
		return;
	}
	
	// Get the mime type
	if (mwi_info->rdata->msg_info.ctype) {
    	const pjsip_ctype_hdr *ctype = mwi_info->rdata->msg_info.ctype;
    	pj_ansi_snprintf(mime_type_c, sizeof(mime_type_c),
    		  "%.*s/%.*s",
              (int)ctype->media.type.slen,
              ctype->media.type.ptr,
              (int)ctype->media.subtype.slen,
              ctype->media.subtype.ptr);
    }
    
	
	body.ptr = (char *) mwi_info->rdata->msg_info.msg->body->data;
	body.slen = mwi_info->rdata->msg_info.msg->body->len;
	
	// Ignore empty messages
	if (body.slen == 0){
		return;
	}
	
	mime_type = pj_str(mime_type_c);
	
	registeredCallbackObject->on_mwi_info(acc_id, &mime_type, &body);
}


pj_status_t on_setup_audio_wrapper (int clock_rate) {
	return registeredCallbackObject->on_setup_audio(clock_rate);
}

void on_teardown_audio_wrapper () {
	registeredCallbackObject->on_teardown_audio();
}

int on_set_micro_source_wrapper () {
	registeredCallbackObject->on_set_micro_source();
}

void on_zrtp_show_sas_wrapper(void* data, char* sas, int verified){
	pj_str_t sas_string = pj_str(sas);
	registeredCallbackObject->on_zrtp_show_sas(&sas_string, verified);
}

void on_zrtp_secure_on_wrapper(void* data, char* cipher){
	pj_str_t cipher_string = pj_str(cipher);
	registeredCallbackObject->on_zrtp_secure_on(&cipher_string);
}

void on_zrtp_secure_off_wrapper(void* data) {
	registeredCallbackObject->on_zrtp_secure_off();
}

}

static struct pjsua_callback wrapper_callback_struct = {
	&on_call_state_wrapper,
	&on_incoming_call_wrapper,
	&on_call_tsx_state_wrapper,
	&on_call_media_state_wrapper,
	&on_stream_created_wrapper,
	&on_stream_destroyed_wrapper,
	&on_dtmf_digit_wrapper,
	&on_call_transfer_request_wrapper,
	&on_call_transfer_status_wrapper,
	&on_call_replace_request_wrapper,
	&on_call_replaced_wrapper,
	&on_reg_state_wrapper,
	NULL, //on_reg2_state
	NULL, // incoming subscribe &on_incoming_subscribe_wrapper,
	NULL, // srv_subscribe state &on_srv_subscribe_state_wrapper,
	&on_buddy_state_wrapper,
	NULL, // on_buddy_evsub_state
	&on_pager_wrapper,
	&on_pager2_wrapper,
	&on_pager_status_wrapper,
	&on_pager_status2_wrapper,
	&on_typing_wrapper,
	NULL, //Typing 2
	&on_nat_detect_wrapper,
	&on_call_redirected_wrapper,
	&on_mwi_info_wrapper,
	NULL, //on_transport_state
	NULL, //on_ice_transport_error
	NULL //on_zrtp_transport_created
};

void setCallbackObject(Callback* callback) {
	registeredCallbackObject = callback;
}

%}

%inline %{
pj_str_t pj_str_copy(const char *str) {
	size_t length = strlen(str) + 1;
	char* copy = (char*)calloc(length, sizeof(char));
	copy = strncpy(copy, str, length);
	return pj_str(copy);
}

%}
/* turn on director wrapping Callback */
%feature("director") Callback;

class Callback {
public:
	virtual ~Callback();
	virtual void on_call_state (pjsua_call_id call_id, pjsip_event *e);
	virtual void on_incoming_call (pjsua_acc_id acc_id, pjsua_call_id call_id,
		pjsip_rx_data *rdata);
	virtual void on_call_tsx_state (pjsua_call_id call_id, 
		pjsip_transaction *tsx,
		pjsip_event *e);
	virtual void on_call_media_state (pjsua_call_id call_id);
	virtual void on_stream_created (pjsua_call_id call_id, 
		pjmedia_session *sess,
		unsigned stream_idx, 
		pjmedia_port **p_port);
	virtual void on_stream_destroyed (pjsua_call_id call_id,
		pjmedia_session *sess, 
		unsigned stream_idx);
	virtual void on_dtmf_digit (pjsua_call_id call_id, int digit);
	virtual void on_call_transfer_request (pjsua_call_id call_id,
		const pj_str_t *dst,
		pjsip_status_code *code);
	virtual void on_call_transfer_status (pjsua_call_id call_id,
		int st_code,
		const pj_str_t *st_text,
		pj_bool_t final_,
		pj_bool_t *p_cont);
	virtual void on_call_replace_request (pjsua_call_id call_id,
		pjsip_rx_data *rdata,
		int *st_code,
		pj_str_t *st_text);
	virtual void on_call_replaced (pjsua_call_id old_call_id,
		pjsua_call_id new_call_id);
	virtual void on_reg_state (pjsua_acc_id acc_id);
	virtual void on_buddy_state (pjsua_buddy_id buddy_id);
	virtual void on_pager (pjsua_call_id call_id, const pj_str_t *from,
		const pj_str_t *to, const pj_str_t *contact,
		const pj_str_t *mime_type, const pj_str_t *body);
	virtual void on_pager2 (pjsua_call_id call_id, const pj_str_t *from,
		const pj_str_t *to, const pj_str_t *contact,
		const pj_str_t *mime_type, const pj_str_t *body,
		pjsip_rx_data *rdata);
	virtual void on_pager_status (pjsua_call_id call_id,
		const pj_str_t *to,
		const pj_str_t *body,
/*XXX		void *user_data,*/
		pjsip_status_code status,
		const pj_str_t *reason);
	virtual void on_pager_status2 (pjsua_call_id call_id,
		const pj_str_t *to,
		const pj_str_t *body,
/*XXX		void *user_data,*/
		pjsip_status_code status,
		const pj_str_t *reason,
		pjsip_tx_data *tdata,
		pjsip_rx_data *rdata);
	virtual void on_typing (pjsua_call_id call_id, const pj_str_t *from,
		const pj_str_t *to, const pj_str_t *contact,
		pj_bool_t is_typing);
	virtual void on_nat_detect (const pj_stun_nat_detect_result *res);
	virtual pjsip_redirect_op on_call_redirected (pjsua_call_id call_id, const pj_str_t *target);
	virtual void on_mwi_info (pjsua_acc_id acc_id, const pj_str_t *mime_type, const pj_str_t *body);
	
	virtual pj_status_t on_setup_audio(int clock_rate);
	virtual void on_teardown_audio();
	virtual int on_set_micro_source();
	
	virtual void on_zrtp_show_sas (const pj_str_t *sas, int verified);
	virtual void on_zrtp_secure_on (const pj_str_t *cipher);
	virtual void on_zrtp_secure_off ();
};

%constant struct pjsua_callback* WRAPPER_CALLBACK_STRUCT = &wrapper_callback_struct;

void setCallbackObject(Callback* callback);

#define PJ_DECL(type) extern type

// The public API does not use lists, therefore we define it to nothing
// From pjlib/include/pj/list.h
#define PJ_DECL_LIST_MEMBER(type)

// Swig requires that structures which are mapped to
// classes are specified in this file, therefore I had
// to copy them from the original header files.

// The following typedefs have been found using:
// find -iname '*.h' | xargs grep 'typedef.*TYPENAME'
// The beginning typedef keyword and the repeated structure
// / enum name have been removed

// From pjlib/include/pj/types.h:63
typedef int               pj_status_t;
// From pjlib/include/pj/types.h:66
typedef int               pj_bool_t;
// From pjlib/include/pj/types.h:48
typedef unsigned short    pj_uint16_t;
// From pjlib/include/pj/types.h:42
typedef unsigned int      pj_uint32_t;
// From pjlib/include/pj/types.h:54
typedef unsigned char     pj_uint8_t;

// From pjlib/include/pj/types.h:86
/** Status is OK. */
#define PJ_SUCCESS  0
/** True value. */
#define PJ_TRUE     1
/** False value. */
#define PJ_FALSE    0

// From pjlib/include/pj/types.h:57
typedef size_t pj_size_t;

// From pjlib/include/pj/types.h:111
struct pj_str_t
{
    /** Buffer pointer, which is by convention NOT null terminated. */
    char       *ptr;

    /** The length of the string. */
    pj_ssize_t  slen;
};


// From pjmedia/include/pjmedia/codec.h:245

//struct pjmedia_codec_param
//{
//    /**
//     * The "info" part of codec param describes the capability of the codec,
//     * and the value should NOT be changed by application.
//     */
//    struct {
//       unsigned    clock_rate;          /**< Sampling rate in Hz            */
//       unsigned    channel_cnt;         /**< Channel count.                 */
//       pj_uint32_t avg_bps;             /**< Average bandwidth in bits/sec  */
//       pj_uint32_t max_bps;             /**< Maximum bandwidth in bits/sec  */
//       pj_uint16_t frm_ptime;           /**< Decoder frame ptime in msec.   */
//       pj_uint16_t enc_ptime;           /**< Encoder ptime, or zero if it's
//                                             equal to decoder ptime.        */
//       pj_uint8_t  pcm_bits_per_sample; /**< Bits/sample in the PCM side    */
//       pj_uint8_t  pt;                  /**< Payload type.                  */
//    } info;

    /**
     * The "setting" part of codec param describes various settings to be
     * applied to the codec. When the codec param is retrieved from the codec
     * or codec factory, the values of these will be filled by the capability
     * of the codec. Any features that are supported by the codec (e.g. vad
     * or plc) will be turned on, so that application can query which
     * capabilities are supported by the codec. Application may change the
     * settings here before instantiating the codec/stream.
     */
//    struct {
//        pj_uint8_t  frm_per_pkt;    /**< Number of frames per packet.   */
//        unsigned    vad:1;          /**< Voice Activity Detector.       */
//        unsigned    cng:1;          /**< Comfort Noise Generator.       */
//        unsigned    penh:1;         /**< Perceptual Enhancement         */
//        unsigned    plc:1;          /**< Packet loss concealment        */
//        unsigned    reserved:1;     /**< Reserved, must be zero.        */
//        pj_uint8_t  enc_fmtp_mode;  /**< Mode param in fmtp (def:0)     */
//        pj_uint8_t  dec_fmtp_mode;  /**< Mode param in fmtp (def:0)     */
//    } setting;
//};

// From pjmedia/include/pjmedia/port.h:253
struct pjmedia_port
{
    pjmedia_port_info    info;              /**< Port information.  */

    /** Port data can be used by the port creator to attach arbitrary
     *  value to be associated with the port.
     */
    struct port_data {
        void            *pdata;             /**< Pointer data.      */
        long             ldata;             /**< Long data.         */
    };

    /**
     * Sink interface.
     * This should only be called by #pjmedia_port_put_frame().
     */
    pj_status_t (*put_frame)(struct pjmedia_port *this_port,
                             const pjmedia_frame *frame);

    /**
     * Source interface.
     * This should only be called by #pjmedia_port_get_frame().
     */
    pj_status_t (*get_frame)(struct pjmedia_port *this_port,
                             pjmedia_frame *frame);

    /**
     * Called to destroy this port.
     */
    pj_status_t (*on_destroy)(struct pjmedia_port *this_port);

};

// From pjmedia/include/pjmedia/types.h:97
enum pjmedia_dir
{
    /** None */
    PJMEDIA_DIR_NONE = 0,

    /** Encoding (outgoing to network) stream */
    PJMEDIA_DIR_ENCODING = 1,

    /** Decoding (incoming from network) stream. */
    PJMEDIA_DIR_DECODING = 2,

    /** Incoming and outgoing stream. */
    PJMEDIA_DIR_ENCODING_DECODING = 3

};

// From pjmedia/include/pjmedia/port.h:205
struct pjmedia_port_info
{
    pj_str_t        name;               /**< Port name.                     */
    pj_uint32_t     signature;          /**< Port signature.                */
    pjmedia_type    type;               /**< Media type.                    */
    pj_bool_t       has_info;           /**< Has info?                      */
    pj_bool_t       need_info;          /**< Need info on connect?          */
    unsigned        pt;                 /**< Payload type (can be dynamic). */
    pj_str_t        encoding_name;      /**< Encoding name.                 */
    unsigned        clock_rate;         /**< Sampling rate.                 */
    unsigned        channel_count;      /**< Number of channels.            */
    unsigned        bits_per_sample;    /**< Bits/sample                    */
    unsigned        samples_per_frame;  /**< No of samples per frame.       */
    unsigned        bytes_per_frame;    /**< No of samples per frame.       */
};


// From pjsip/include/pjsip/sip_auth.h:108
struct pjsip_cred_info
{
    pj_str_t    realm;          /**< Realm. Use "*" to make a credential that
                                     can be used to authenticate against any
                                     challenges.                            */
    pj_str_t    scheme;         /**< Scheme (e.g. "digest").                */
    pj_str_t    username;       /**< User name.                             */
    int         data_type;      /**< Type of data (0 for plaintext passwd). */
    pj_str_t    data;           /**< The data, which can be a plaintext
                                     password or a hashed digest.           */

    /** Extended data */
    union {
        /** Digest AKA credential information. Note that when AKA credential
         *  is being used, the \a data field of this #pjsip_cred_info is
         *  not used, but it still must be initialized to an empty string.
         * Please see \ref PJSIP_AUTH_AKA_API for more information.
         */
        struct {
            pj_str_t      k;    /**< Permanent subscriber key.          */
            pj_str_t      op;   /**< Operator variant key.              */
            pj_str_t      amf;  /**< Authentication Management Field    */
            pjsip_cred_cb cb;   /**< Callback to create AKA digest.     */
        } aka;

    } ext;
};

// From pjsip/include/pjsip/sip_auth.h:50
enum pjsip_cred_data_type
{
    PJSIP_CRED_DATA_PLAIN_PASSWD=0, /**< Plain text password.           */
    PJSIP_CRED_DATA_DIGEST      =1, /**< Hashed digest.                 */

    PJSIP_CRED_DATA_EXT_AKA     =16 /**< Extended AKA info is available */

};


// From pjmedia/include/pjmedia/tonegen.h:105
enum
{
    /**
     * Play the tones in loop, restarting playing the first tone after
     * the last tone has been played.
     */
    PJMEDIA_TONEGEN_LOOP    = 1,

    /**
     * Disable mutex protection to the tone generator.
     */
    PJMEDIA_TONEGEN_NO_LOCK = 2
};

// From pjsip/include/pjsip/sip_event.h:79
struct pjsip_event
{
    /** This is necessary so that we can put events as a list. */
    PJ_DECL_LIST_MEMBER(struct pjsip_event);

    /** The event type, can be any value of \b pjsip_event_id_e.
     */
    pjsip_event_id_e type;

    /**
     * The event body as union, which fields depends on the event type.
     * By convention, the first member of each struct in the union must be
     * the pointer which is relevant to the event.
     */
    union
    {
        /** Timer event. */
        struct
        {
            pj_timer_entry *entry;      /**< The timer entry.           */
        } timer;

        /** Transaction state has changed event. */
        struct
        {
            union
            {
                pjsip_rx_data   *rdata; /**< The incoming message.      */
                pjsip_tx_data   *tdata; /**< The outgoing message.      */
                pj_timer_entry  *timer; /**< The timer.                 */
                pj_status_t      status;/**< Transport error status.    */
                void            *data;  /**< Generic data.              */
            } src;
            pjsip_transaction   *tsx;   /**< The transaction.           */
            int                  prev_state; /**< Previous state.       */
            pjsip_event_id_e     type;  /**< Type of event source:
                                         *      - PJSIP_EVENT_TX_MSG
                                         *      - PJSIP_EVENT_RX_MSG,
                                         *      - PJSIP_EVENT_TRANSPORT_ERROR
                                         *      - PJSIP_EVENT_TIMER
                                         *      - PJSIP_EVENT_USER
                                         */
        } tsx_state;

        /** Message transmission event. */
        struct
        {
            pjsip_tx_data       *tdata; /**< The transmit data buffer.  */

        } tx_msg;

        /** Transmission error event. */
        struct
        {
            pjsip_tx_data       *tdata; /**< The transmit data.         */
            pjsip_transaction   *tsx;   /**< The transaction.           */
        } tx_error;

        /** Message arrival event. */
        struct
        {
            pjsip_rx_data       *rdata; /**< The receive data buffer.   */
        } rx_msg;

        /** User event. */
        struct
        {
            void                *user1; /**< User data 1.               */
            void                *user2; /**< User data 2.               */
            void                *user3; /**< User data 3.               */
            void                *user4; /**< User data 4.               */
        } user;

    } body;
};

// From pjmedia/include/pjmedia/sound.h:69
struct pjmedia_snd_dev_info
{
    char        name[64];               /**< Device name.                   */
    unsigned    input_count;            /**< Max number of input channels.  */
    unsigned    output_count;           /**< Max number of output channels. */
    unsigned    default_samples_per_sec;/**< Default sampling rate.         */
};

// From pjmedia/include/pjmedia/tonegen.h:60
struct pjmedia_tone_desc
{
    short   freq1;          /**< First frequency.                           */
    short   freq2;          /**< Optional second frequency.                 */
    short   on_msec;        /**< Playback ON duration, in miliseconds.      */
    short   off_msec;       /**< Playback OFF duration, ini miliseconds.    */
    short   volume;         /**< Volume (1-16383), or 0 for default.        */
};

// From pjlib/include/pj/pool.h:312
struct pj_pool_t
{
    PJ_DECL_LIST_MEMBER(struct pj_pool_t);  /**< Standard list elements.    */

    /** Pool name */
    char            obj_name[PJ_MAX_OBJ_NAME];

    /** Pool factory. */
    pj_pool_factory *factory;

    /** Data put by factory */
    void            *factory_data;

    /** Current capacity allocated by the pool. */
    pj_size_t       capacity;

    /** Size of memory block to be allocated when the pool runs out of memory */
    pj_size_t       increment_size;

    /** List of memory blocks allcoated by the pool. */
    pj_pool_block   block_list;

    /** The callback to be called when the pool is unable to allocate memory. */
    pj_pool_callback *callback;

};

// From pjsip/include/pjsip/sip_event.h:41
enum pjsip_event_id_e
{
    /** Unidentified event. */
    PJSIP_EVENT_UNKNOWN,

    /** Timer event, normally only used internally in transaction. */
    PJSIP_EVENT_TIMER,

    /** Message transmission event. */
    PJSIP_EVENT_TX_MSG,

    /** Message received event. */
    PJSIP_EVENT_RX_MSG,

    /** Transport error event. */
    PJSIP_EVENT_TRANSPORT_ERROR,

    /** Transaction state changed event. */
    PJSIP_EVENT_TSX_STATE,

    /** Indicates that the event was triggered by user action. */
    PJSIP_EVENT_USER

};

// From pjsip/include/pjsip/sip_types.h:61
enum pjsip_transport_type_e
{
    /** Unspecified. */
    PJSIP_TRANSPORT_UNSPECIFIED,

    /** UDP. */
    PJSIP_TRANSPORT_UDP,

    /** TCP. */
    PJSIP_TRANSPORT_TCP,

    /** TLS. */
    PJSIP_TRANSPORT_TLS,

    /** SCTP. */
    PJSIP_TRANSPORT_SCTP,

    /** Loopback (stream, reliable) */
    PJSIP_TRANSPORT_LOOP,

    /** Loopback (datagram, unreliable) */
    PJSIP_TRANSPORT_LOOP_DGRAM,

    /** Start of user defined transport */
    PJSIP_TRANSPORT_START_OTHER,

    /** Start of IPv6 transports */
    PJSIP_TRANSPORT_IPV6    = 128,

    /** UDP over IPv6 */
    PJSIP_TRANSPORT_UDP6 = PJSIP_TRANSPORT_UDP + PJSIP_TRANSPORT_IPV6,

    /** TCP over IPv6 */
    PJSIP_TRANSPORT_TCP6 = PJSIP_TRANSPORT_TCP + PJSIP_TRANSPORT_IPV6

};

// From pjsip/include/pjsip-ua/sip_inv.h:87
enum pjsip_inv_state
{
    PJSIP_INV_STATE_NULL,           /**< Before INVITE is sent or received  */
    PJSIP_INV_STATE_CALLING,        /**< After INVITE is sent               */
    PJSIP_INV_STATE_INCOMING,       /**< After INVITE is received.          */
    PJSIP_INV_STATE_EARLY,          /**< After response with To tag.        */
    PJSIP_INV_STATE_CONNECTING,     /**< After 2xx is sent/received.        */
    PJSIP_INV_STATE_CONFIRMED,      /**< After ACK is sent/received.        */
    PJSIP_INV_STATE_DISCONNECTED,   /**< Session is terminated.             */
};

// From pjsip/include/pjsip/sip_msg.h:410
enum pjsip_status_code
{
    PJSIP_SC_TRYING = 100,
    PJSIP_SC_RINGING = 180,
    PJSIP_SC_CALL_BEING_FORWARDED = 181,
    PJSIP_SC_QUEUED = 182,
    PJSIP_SC_PROGRESS = 183,

    PJSIP_SC_OK = 200,
    PJSIP_SC_ACCEPTED = 202,

    PJSIP_SC_MULTIPLE_CHOICES = 300,
    PJSIP_SC_MOVED_PERMANENTLY = 301,
    PJSIP_SC_MOVED_TEMPORARILY = 302,
    PJSIP_SC_USE_PROXY = 305,
    PJSIP_SC_ALTERNATIVE_SERVICE = 380,

    PJSIP_SC_BAD_REQUEST = 400,
    PJSIP_SC_UNAUTHORIZED = 401,
    PJSIP_SC_PAYMENT_REQUIRED = 402,
    PJSIP_SC_FORBIDDEN = 403,
    PJSIP_SC_NOT_FOUND = 404,
    PJSIP_SC_METHOD_NOT_ALLOWED = 405,
    PJSIP_SC_NOT_ACCEPTABLE = 406,
    PJSIP_SC_PROXY_AUTHENTICATION_REQUIRED = 407,
    PJSIP_SC_REQUEST_TIMEOUT = 408,
    PJSIP_SC_GONE = 410,
    PJSIP_SC_REQUEST_ENTITY_TOO_LARGE = 413,
    PJSIP_SC_REQUEST_URI_TOO_LONG = 414,
    PJSIP_SC_UNSUPPORTED_MEDIA_TYPE = 415,
    PJSIP_SC_UNSUPPORTED_URI_SCHEME = 416,
    PJSIP_SC_BAD_EXTENSION = 420,
    PJSIP_SC_EXTENSION_REQUIRED = 421,
    PJSIP_SC_SESSION_TIMER_TOO_SMALL = 422,
    PJSIP_SC_INTERVAL_TOO_BRIEF = 423,
    PJSIP_SC_TEMPORARILY_UNAVAILABLE = 480,
    PJSIP_SC_CALL_TSX_DOES_NOT_EXIST = 481,
    PJSIP_SC_LOOP_DETECTED = 482,
    PJSIP_SC_TOO_MANY_HOPS = 483,
    PJSIP_SC_ADDRESS_INCOMPLETE = 484,
    PJSIP_AC_AMBIGUOUS = 485,
    PJSIP_SC_BUSY_HERE = 486,
    PJSIP_SC_REQUEST_TERMINATED = 487,
    PJSIP_SC_NOT_ACCEPTABLE_HERE = 488,
    PJSIP_SC_BAD_EVENT = 489,
    PJSIP_SC_REQUEST_UPDATED = 490,
    PJSIP_SC_REQUEST_PENDING = 491,
    PJSIP_SC_UNDECIPHERABLE = 493,

    PJSIP_SC_INTERNAL_SERVER_ERROR = 500,
    PJSIP_SC_NOT_IMPLEMENTED = 501,
    PJSIP_SC_BAD_GATEWAY = 502,
    PJSIP_SC_SERVICE_UNAVAILABLE = 503,
    PJSIP_SC_SERVER_TIMEOUT = 504,
    PJSIP_SC_VERSION_NOT_SUPPORTED = 505,
    PJSIP_SC_MESSAGE_TOO_LARGE = 513,
    PJSIP_SC_PRECONDITION_FAILURE = 580,

    PJSIP_SC_BUSY_EVERYWHERE = 600,
    PJSIP_SC_DECLINE = 603,
    PJSIP_SC_DOES_NOT_EXIST_ANYWHERE = 604,
    PJSIP_SC_NOT_ACCEPTABLE_ANYWHERE = 606,

    PJSIP_SC_TSX_TIMEOUT = PJSIP_SC_REQUEST_TIMEOUT,
    /*PJSIP_SC_TSX_RESOLVE_ERROR = 702,*/
    PJSIP_SC_TSX_TRANSPORT_ERROR = PJSIP_SC_SERVICE_UNAVAILABLE

};

/** The following functions are not exposed in pjsua.h, but we need them */
// From pjsip/include/pjsua-lib/pjsua.h:1342
PJ_DECL(pj_pool_t*) pjsua_pool_create(const char *name, pj_size_t init_size, pj_size_t increment);
// From pjlib/include/pj/pool.h:390
PJ_DECL(void) pj_pool_release( pj_pool_t *pool );
// From pjmedia/include/pjmedia/tonegen.h:168
PJ_DECL(pj_status_t) pjmedia_tonegen_create2(pj_pool_t *pool,
	const pj_str_t *name,
	unsigned clock_rate,
	unsigned channel_count,
	unsigned samples_per_frame,
	unsigned bits_per_sample,
	unsigned options,
	pjmedia_port **pp_port);
// From pjmedia/include/pjmedia/tonegen.h:225
PJ_DECL(pj_status_t) pjmedia_tonegen_play(pjmedia_port *tonegen,
	unsigned count,
	const pjmedia_tone_desc tones[],
	unsigned options);
// From pjmedia/include/pjmedia/tonegen.h:206
PJ_DECL(pj_status_t) pjmedia_tonegen_rewind(pjmedia_port *tonegen);

// From pjmedia/include/pjmedia/transport_srtp.h:109
enum pjmedia_srtp_use
{
    /**
     * When this flag is specified, SRTP will be disabled, and the transport
     * will reject RTP/SAVP offer.
     */
    PJMEDIA_SRTP_DISABLED,

    /**
     * When this flag is specified, SRTP will be advertised as optional and
     * incoming SRTP offer will be accepted.
     */
    PJMEDIA_SRTP_OPTIONAL,

    /**
     * When this flag is specified, the transport will require that RTP/SAVP
     * media shall be used.
     */
    PJMEDIA_SRTP_MANDATORY

};

// From pjsip/include/pjsip/transport_tls.h

/** SSL protocol method constants. */
enum pjsip_ssl_method
{
    PJSIP_SSL_UNSPECIFIED_METHOD= 0,	/**< Default protocol method.	*/
    PJSIP_TLSV1_METHOD		= 31,	/**< Use SSLv1 method.		*/
    PJSIP_SSLV2_METHOD		= 20,	/**< Use SSLv2 method.		*/
    PJSIP_SSLV3_METHOD		= 30,	/**< Use SSLv3 method.		*/
    PJSIP_SSLV23_METHOD		= 23	/**< Use SSLv23 method.		*/
} ;




/**
 * TLS transport settings.
 */
struct pjsip_tls_setting
{
    /**
     * Certificate of Authority (CA) list file.
     */
    pj_str_t	ca_list_file;

    /**
     * Public endpoint certificate file, which will be used as client-
     * side  certificate for outgoing TLS connection, and server-side
     * certificate for incoming TLS connection.
     */
    pj_str_t	cert_file;

    /**
     * Optional private key of the endpoint certificate to be used.
     */
    pj_str_t	privkey_file;

    /**
     * Password to open private key.
     */
    pj_str_t	password;

    /**
     * TLS protocol method from #pjsip_ssl_method, which can be:
     *	- PJSIP_SSL_UNSPECIFIED_METHOD(0): default (which will use 
     *                                     PJSIP_SSL_DEFAULT_METHOD)
     *	- PJSIP_TLSV1_METHOD(1):	   TLSv1
     *	- PJSIP_SSLV2_METHOD(2):	   SSLv2
     *	- PJSIP_SSLV3_METHOD(3):	   SSL3
     *	- PJSIP_SSLV23_METHOD(23):	   SSL23
     *
     * Default is PJSIP_SSL_UNSPECIFIED_METHOD (0), which in turn will
     * use PJSIP_SSL_DEFAULT_METHOD, which default value is 
     * PJSIP_TLSV1_METHOD.
     */
    int		method;

    /**
     * TLS cipher list string in OpenSSL format. If empty, then default
     * cipher list of the backend will be used.
     */
    pj_str_t	ciphers;

    /**
     * Optionally specify the server name instance to be contacted when
     * making outgoing TLS connection. This setting is useful when the
     * server is hosting multiple domains for the same TLS listening
     * socket.
     *
     * Default: empty.
     */
    pj_str_t	server_name;

    /**
     * Specifies TLS transport behavior on the server TLS certificate 
     * verification result:
     * - If \a verify_server is disabled (set to PJ_FALSE), TLS transport 
     *   will just notify the application via #pjsip_tp_state_callback with
     *   state PJSIP_TP_STATE_CONNECTED regardless TLS verification result.
     * - If \a verify_server is enabled (set to PJ_TRUE), TLS transport 
     *   will be shutdown and application will be notified with state
     *   PJSIP_TP_STATE_DISCONNECTED whenever there is any TLS verification
     *   error, otherwise PJSIP_TP_STATE_CONNECTED will be notified.
     *
     * In any cases, application can inspect #pjsip_tls_state_info in the
     * callback to see the verification detail.
     *
     * Default value is PJ_FALSE.
     */
    pj_bool_t	verify_server;

    /**
     * Specifies TLS transport behavior on the client TLS certificate 
     * verification result:
     * - If \a verify_client is disabled (set to PJ_FALSE), TLS transport 
     *   will just notify the application via #pjsip_tp_state_callback with
     *   state PJSIP_TP_STATE_CONNECTED regardless TLS verification result.
     * - If \a verify_client is enabled (set to PJ_TRUE), TLS transport 
     *   will be shutdown and application will be notified with state
     *   PJSIP_TP_STATE_DISCONNECTED whenever there is any TLS verification
     *   error, otherwise PJSIP_TP_STATE_CONNECTED will be notified.
     *
     * In any cases, application can inspect #pjsip_tls_state_info in the
     * callback to see the verification detail.
     *
     * Default value is PJ_FALSE.
     */
    pj_bool_t	verify_client;

    /**
     * When acting as server (incoming TLS connections), reject inocming
     * connection if client doesn't supply a TLS certificate.
     *
     * This setting corresponds to SSL_VERIFY_FAIL_IF_NO_PEER_CERT flag.
     * Default value is PJ_FALSE.
     */
    pj_bool_t	require_client_cert;

    /**
     * TLS negotiation timeout to be applied for both outgoing and
     * incoming connection. If both sec and msec member is set to zero,
     * the SSL negotiation doesn't have a timeout.
     */
    pj_time_val	timeout;

    /**
     * QoS traffic type to be set on this transport. When application wants
     * to apply QoS tagging to the transport, it's preferable to set this
     * field rather than \a qos_param fields since this is more portable.
     *
     * Default value is PJ_QOS_TYPE_BEST_EFFORT.
     */
    pj_qos_type qos_type;

    /**
     * Set the low level QoS parameters to the transport. This is a lower
     * level operation than setting the \a qos_type field and may not be
     * supported on all platforms.
     *
     * By default all settings in this structure are disabled.
     */
    pj_qos_params qos_params;

    /**
     * Specify if the transport should ignore any errors when setting the QoS
     * traffic type/parameters.
     *
     * Default: PJ_TRUE
     */
    pj_bool_t qos_ignore_error;

} ;

//pjlib/include/pj/types.h
typedef long		pj_ssize_t;

/* QOS */
/**
 * High level traffic classification.
 */
enum pj_qos_type
{
    PJ_QOS_TYPE_BEST_EFFORT,	/**< Best effort traffic (default value).
				     Any QoS function calls with specifying
				     this value are effectively no-op	*/
    PJ_QOS_TYPE_BACKGROUND,	/**< Background traffic.		*/
    PJ_QOS_TYPE_VIDEO,		/**< Video traffic.			*/
    PJ_QOS_TYPE_VOICE,		/**< Voice traffic.			*/
    PJ_QOS_TYPE_CONTROL		/**< Control traffic.			*/
};

/**
 * QoS parameters to be set or retrieved to/from the socket.
 */
struct pj_qos_params
{
    pj_uint8_t      flags;    /**< Determines which values to 
				   set, bitmask of pj_qos_flag	    */
    pj_uint8_t      dscp_val; /**< The 6 bits DSCP value to set	    */
    pj_uint8_t      so_prio;  /**< SO_PRIORITY value		    */
    pj_qos_wmm_prio wmm_prio; /**< WMM priority value		    */
};

/**
 * Representation of time value in this library.
 * This type can be used to represent either an interval or a specific time
 * or date. 
 */
struct pj_time_val
{
    /** The seconds part of the time. */
    long    sec;

    /** The miliseconds fraction of the time. */
    long    msec;

};



//pjnat/include/nat_detect.h
/**
 * This structure contains the result of NAT classification function.
 */
struct pj_stun_nat_detect_result
{
    /**
     * Status of the detection process. If this value is not PJ_SUCCESS,
     * the detection has failed and \a nat_type field will contain
     * PJ_STUN_NAT_TYPE_UNKNOWN.
     */
    pj_status_t		 status;

    /**
     * The text describing the status, if the status is not PJ_SUCCESS.
     */
    const char		*status_text;

    /**
     * This contains the NAT type as detected by the detection procedure.
     * This value is only valid when the \a status is PJ_SUCCESS.
     */
    pj_stun_nat_type	 nat_type;

    /**
     * Text describing that NAT type.
     */
    const char		*nat_type_name;

} ;


// pjsip/include/pjsip/sip_util.h:80
/**
 * These enumerations specify the action to be performed to a redirect
 * response.
 */
typedef enum pjsip_redirect_op
{
    /**
     * Reject the redirection to the current target. The UAC will
     * select the next target from the target set if exists.
     */
    PJSIP_REDIRECT_REJECT,

    /**
     * Accept the redirection to the current target. The INVITE request
     * will be resent to the current target.
     */
    PJSIP_REDIRECT_ACCEPT,

    /**
     * Defer the redirection decision, for example to request permission
     * from the end user.
     */
    PJSIP_REDIRECT_PENDING,

    /**
     * Stop the whole redirection process altogether. This will cause
     * the invite session to be disconnected.
     */
    PJSIP_REDIRECT_STOP

} pjsip_redirect_op;

// pjsip/include/psip-ua/sip_timer.h

/**
 * This structure describes Session Timers settings in an invite session.
 */
struct pjsip_timer_setting
{
    /** 
     * Specify minimum session expiration period, in seconds. Must not be
     * lower than 90. Default is 90.
     */
    unsigned			 min_se;

    /**
     * Specify session expiration period, in seconds. Must not be lower than
     * #min_se. Default is 1800.
     */
    unsigned			 sess_expires;	

};
%rename(logging_config_default) pjsua_logging_config_default;
%javamethodmodifiers pjsua_logging_config_default(pjsua_logging_config *cfg) "public synchronized";
%rename(logging_config_dup) pjsua_logging_config_dup;
%javamethodmodifiers pjsua_logging_config_dup(pj_pool_t *pool,
				       pjsua_logging_config *dst,
				       const pjsua_logging_config *src) "public synchronized";
%rename(config_default) pjsua_config_default;
%javamethodmodifiers pjsua_config_default(pjsua_config *cfg) "public synchronized";
%rename(config_dup) pjsua_config_dup;
%javamethodmodifiers pjsua_config_dup(pj_pool_t *pool,
			       pjsua_config *dst,
			       const pjsua_config *src) "public synchronized";
%rename(msg_data_init) pjsua_msg_data_init;
%javamethodmodifiers pjsua_msg_data_init(pjsua_msg_data *msg_data) "public synchronized";
%rename(create) pjsua_create;
%javamethodmodifiers pjsua_create(void) "public synchronized";
%rename(start) pjsua_start;
%javamethodmodifiers pjsua_start(void) "public synchronized";
%rename(handle_events) pjsua_handle_events;
%javamethodmodifiers pjsua_handle_events(unsigned msec_timeout) "public synchronized";
%rename(pool_create) pjsua_pool_create;
%javamethodmodifiers pjsua_pool_create(const char *name, pj_size_t init_size,
				      pj_size_t increment) "public synchronized";
%rename(reconfigure_logging) pjsua_reconfigure_logging;
%javamethodmodifiers pjsua_reconfigure_logging(const pjsua_logging_config *c) "public synchronized";
%rename(get_pjsip_endpt) pjsua_get_pjsip_endpt;
%javamethodmodifiers pjsua_get_pjsip_endpt(void) "public synchronized";
%rename(get_pjmedia_endpt) pjsua_get_pjmedia_endpt;
%javamethodmodifiers pjsua_get_pjmedia_endpt(void) "public synchronized";
%rename(get_pool_factory) pjsua_get_pool_factory;
%javamethodmodifiers pjsua_get_pool_factory(void) "public synchronized";
%rename(detect_nat_type) pjsua_detect_nat_type;
%javamethodmodifiers pjsua_detect_nat_type(void) "public synchronized";
%rename(get_nat_type) pjsua_get_nat_type;
%javamethodmodifiers pjsua_get_nat_type(pj_stun_nat_type *type) "public synchronized";
%rename(resolve_stun_servers) pjsua_resolve_stun_servers;
%javamethodmodifiers pjsua_resolve_stun_servers(unsigned count,
						pj_str_t srv[],
						pj_bool_t wait,
						void *token,
						pj_stun_resolve_cb cb) "public synchronized";
%rename(cancel_stun_resolution) pjsua_cancel_stun_resolution;
%javamethodmodifiers pjsua_cancel_stun_resolution(void *token,
						  pj_bool_t notify_cb) "public synchronized";
%rename(verify_sip_url) pjsua_verify_sip_url;
%javamethodmodifiers pjsua_verify_sip_url(const char *url) "public synchronized";
%rename(verify_url) pjsua_verify_url;
%javamethodmodifiers pjsua_verify_url(const char *url) "public synchronized";
%rename(schedule_timer) pjsua_schedule_timer;
%javamethodmodifiers pjsua_schedule_timer(pj_timer_entry *entry,
					  const pj_time_val *delay) "public synchronized";
%rename(cancel_timer) pjsua_cancel_timer;
%javamethodmodifiers pjsua_cancel_timer(pj_timer_entry *entry) "public synchronized";
%rename(perror) pjsua_perror;
%javamethodmodifiers pjsua_perror(const char *sender, const char *title, 
			   pj_status_t status) "public synchronized";
%rename(dump) pjsua_dump;
%javamethodmodifiers pjsua_dump(pj_bool_t detail) "public synchronized";
%rename(transport_config_default) pjsua_transport_config_default;
%javamethodmodifiers pjsua_transport_config_default(pjsua_transport_config *cfg) "public synchronized";
%rename(transport_config_dup) pjsua_transport_config_dup;
%javamethodmodifiers pjsua_transport_config_dup(pj_pool_t *pool,
					 pjsua_transport_config *dst,
					 const pjsua_transport_config *src) "public synchronized";
%rename(transport_create) pjsua_transport_create;
%javamethodmodifiers pjsua_transport_create(pjsip_transport_type_e type,
					    const pjsua_transport_config *cfg,
					    pjsua_transport_id *p_id) "public synchronized";
%rename(transport_register) pjsua_transport_register;
%javamethodmodifiers pjsua_transport_register(pjsip_transport *tp,
					      pjsua_transport_id *p_id) "public synchronized";
%rename(enum_transports) pjsua_enum_transports;
%javamethodmodifiers pjsua_enum_transports( pjsua_transport_id id[],
					    unsigned *count ) "public synchronized";
%rename(transport_get_info) pjsua_transport_get_info;
%javamethodmodifiers pjsua_transport_get_info(pjsua_transport_id id,
					      pjsua_transport_info *info) "public synchronized";
%rename(transport_set_enable) pjsua_transport_set_enable;
%javamethodmodifiers pjsua_transport_set_enable(pjsua_transport_id id,
						pj_bool_t enabled) "public synchronized";
%rename(transport_close) pjsua_transport_close;
%javamethodmodifiers pjsua_transport_close( pjsua_transport_id id,
					    pj_bool_t force ) "public synchronized";
%rename(acc_config_default) pjsua_acc_config_default;
%javamethodmodifiers pjsua_acc_config_default(pjsua_acc_config *cfg) "public synchronized";
%rename(acc_config_dup) pjsua_acc_config_dup;
%javamethodmodifiers pjsua_acc_config_dup(pj_pool_t *pool,
				   pjsua_acc_config *dst,
				   const pjsua_acc_config *src) "public synchronized";
%rename(acc_get_count) pjsua_acc_get_count;
%javamethodmodifiers pjsua_acc_get_count(void) "public synchronized";
%rename(acc_is_valid) pjsua_acc_is_valid;
%javamethodmodifiers pjsua_acc_is_valid(pjsua_acc_id acc_id) "public synchronized";
%rename(acc_set_default) pjsua_acc_set_default;
%javamethodmodifiers pjsua_acc_set_default(pjsua_acc_id acc_id) "public synchronized";
%rename(acc_get_default) pjsua_acc_get_default;
%javamethodmodifiers pjsua_acc_get_default(void) "public synchronized";
%rename(acc_add) pjsua_acc_add;
%javamethodmodifiers pjsua_acc_add(const pjsua_acc_config *acc_cfg,
				   pj_bool_t is_default,
				   pjsua_acc_id *p_acc_id) "public synchronized";
%rename(acc_add_local) pjsua_acc_add_local;
%javamethodmodifiers pjsua_acc_add_local(pjsua_transport_id tid,
					 pj_bool_t is_default,
					 pjsua_acc_id *p_acc_id) "public synchronized";
%rename(acc_set_user_data) pjsua_acc_set_user_data;
%javamethodmodifiers pjsua_acc_set_user_data(pjsua_acc_id acc_id,
					     void *user_data) "public synchronized";
%rename(acc_get_user_data) pjsua_acc_get_user_data;
%javamethodmodifiers pjsua_acc_get_user_data(pjsua_acc_id acc_id) "public synchronized";
%rename(acc_del) pjsua_acc_del;
%javamethodmodifiers pjsua_acc_del(pjsua_acc_id acc_id) "public synchronized";
%rename(acc_modify) pjsua_acc_modify;
%javamethodmodifiers pjsua_acc_modify(pjsua_acc_id acc_id,
				      const pjsua_acc_config *acc_cfg) "public synchronized";
%rename(acc_set_online_status) pjsua_acc_set_online_status;
%javamethodmodifiers pjsua_acc_set_online_status(pjsua_acc_id acc_id,
						 pj_bool_t is_online) "public synchronized";
%rename(acc_set_online_status2) pjsua_acc_set_online_status2;
%javamethodmodifiers pjsua_acc_set_online_status2(pjsua_acc_id acc_id,
						  pj_bool_t is_online,
						  const pjrpid_element *pr) "public synchronized";
%rename(acc_set_registration) pjsua_acc_set_registration;
%javamethodmodifiers pjsua_acc_set_registration(pjsua_acc_id acc_id, 
						pj_bool_t renew) "public synchronized";
%rename(acc_get_info) pjsua_acc_get_info;
%javamethodmodifiers pjsua_acc_get_info(pjsua_acc_id acc_id,
					pjsua_acc_info *info) "public synchronized";
%rename(enum_accs) pjsua_enum_accs;
%javamethodmodifiers pjsua_enum_accs(pjsua_acc_id ids[],
				     unsigned *count ) "public synchronized";
%rename(acc_enum_info) pjsua_acc_enum_info;
%javamethodmodifiers pjsua_acc_enum_info( pjsua_acc_info info[],
					  unsigned *count ) "public synchronized";
%rename(acc_find_for_outgoing) pjsua_acc_find_for_outgoing;
%javamethodmodifiers pjsua_acc_find_for_outgoing(const pj_str_t *url) "public synchronized";
%rename(acc_find_for_incoming) pjsua_acc_find_for_incoming;
%javamethodmodifiers pjsua_acc_find_for_incoming(pjsip_rx_data *rdata) "public synchronized";
%rename(acc_create_request) pjsua_acc_create_request;
%javamethodmodifiers pjsua_acc_create_request(pjsua_acc_id acc_id,
					      const pjsip_method *method,
					      const pj_str_t *target,
					      pjsip_tx_data **p_tdata) "public synchronized";
%rename(acc_create_uac_contact) pjsua_acc_create_uac_contact;
%javamethodmodifiers pjsua_acc_create_uac_contact( pj_pool_t *pool,
						   pj_str_t *contact,
						   pjsua_acc_id acc_id,
						   const pj_str_t *uri) "public synchronized";
%rename(acc_create_uas_contact) pjsua_acc_create_uas_contact;
%javamethodmodifiers pjsua_acc_create_uas_contact( pj_pool_t *pool,
						   pj_str_t *contact,
						   pjsua_acc_id acc_id,
						   pjsip_rx_data *rdata ) "public synchronized";
%rename(acc_set_transport) pjsua_acc_set_transport;
%javamethodmodifiers pjsua_acc_set_transport(pjsua_acc_id acc_id,
					     pjsua_transport_id tp_id) "public synchronized";
%rename(call_get_max_count) pjsua_call_get_max_count;
%javamethodmodifiers pjsua_call_get_max_count(void) "public synchronized";
%rename(call_get_count) pjsua_call_get_count;
%javamethodmodifiers pjsua_call_get_count(void) "public synchronized";
%rename(enum_calls) pjsua_enum_calls;
%javamethodmodifiers pjsua_enum_calls(pjsua_call_id ids[],
				      unsigned *count) "public synchronized";
%rename(call_make_call) pjsua_call_make_call;
%javamethodmodifiers pjsua_call_make_call(pjsua_acc_id acc_id,
					  const pj_str_t *dst_uri,
					  unsigned options,
					  void *user_data,
					  const pjsua_msg_data *msg_data,
					  pjsua_call_id *p_call_id) "public synchronized";
%rename(call_is_active) pjsua_call_is_active;
%javamethodmodifiers pjsua_call_is_active(pjsua_call_id call_id) "public synchronized";
%rename(call_has_media) pjsua_call_has_media;
%javamethodmodifiers pjsua_call_has_media(pjsua_call_id call_id) "public synchronized";
%rename(call_get_media_session) pjsua_call_get_media_session;
%javamethodmodifiers pjsua_call_get_media_session(pjsua_call_id call_id) "public synchronized";
%rename(call_get_media_transport) pjsua_call_get_media_transport;
%javamethodmodifiers pjsua_call_get_media_transport(pjsua_call_id cid) "public synchronized";
%rename(call_get_conf_port) pjsua_call_get_conf_port;
%javamethodmodifiers pjsua_call_get_conf_port(pjsua_call_id call_id) "public synchronized";
%rename(call_get_info) pjsua_call_get_info;
%javamethodmodifiers pjsua_call_get_info(pjsua_call_id call_id,
					 pjsua_call_info *info) "public synchronized";
%rename(call_remote_has_cap) pjsua_call_remote_has_cap;
%javamethodmodifiers pjsua_call_remote_has_cap(
						    pjsua_call_id call_id,
						    int htype,
						    const pj_str_t *hname,
						    const pj_str_t *token) "public synchronized";
%rename(call_set_user_data) pjsua_call_set_user_data;
%javamethodmodifiers pjsua_call_set_user_data(pjsua_call_id call_id,
					      void *user_data) "public synchronized";
%rename(call_get_user_data) pjsua_call_get_user_data;
%javamethodmodifiers pjsua_call_get_user_data(pjsua_call_id call_id) "public synchronized";
%rename(call_get_rem_nat_type) pjsua_call_get_rem_nat_type;
%javamethodmodifiers pjsua_call_get_rem_nat_type(pjsua_call_id call_id,
						 pj_stun_nat_type *p_type) "public synchronized";
%rename(call_answer) pjsua_call_answer;
%javamethodmodifiers pjsua_call_answer(pjsua_call_id call_id, 
				       unsigned code,
				       const pj_str_t *reason,
				       const pjsua_msg_data *msg_data) "public synchronized";
%rename(call_hangup) pjsua_call_hangup;
%javamethodmodifiers pjsua_call_hangup(pjsua_call_id call_id,
				       unsigned code,
				       const pj_str_t *reason,
				       const pjsua_msg_data *msg_data) "public synchronized";
%rename(call_process_redirect) pjsua_call_process_redirect;
%javamethodmodifiers pjsua_call_process_redirect(pjsua_call_id call_id,
						 pjsip_redirect_op cmd) "public synchronized";
%rename(call_set_hold) pjsua_call_set_hold;
%javamethodmodifiers pjsua_call_set_hold(pjsua_call_id call_id,
					 const pjsua_msg_data *msg_data) "public synchronized";
%rename(call_reinvite) pjsua_call_reinvite;
%javamethodmodifiers pjsua_call_reinvite(pjsua_call_id call_id,
					 unsigned options,
					 const pjsua_msg_data *msg_data) "public synchronized";
%rename(call_update) pjsua_call_update;
%javamethodmodifiers pjsua_call_update(pjsua_call_id call_id,
				       unsigned options,
				       const pjsua_msg_data *msg_data) "public synchronized";
%rename(call_xfer) pjsua_call_xfer;
%javamethodmodifiers pjsua_call_xfer(pjsua_call_id call_id, 
				     const pj_str_t *dest,
				     const pjsua_msg_data *msg_data) "public synchronized";
%rename(call_xfer_replaces) pjsua_call_xfer_replaces;
%javamethodmodifiers pjsua_call_xfer_replaces(pjsua_call_id call_id, 
					      pjsua_call_id dest_call_id,
					      unsigned options,
					      const pjsua_msg_data *msg_data) "public synchronized";
%rename(call_dial_dtmf) pjsua_call_dial_dtmf;
%javamethodmodifiers pjsua_call_dial_dtmf(pjsua_call_id call_id, 
					  const pj_str_t *digits) "public synchronized";
%rename(call_send_im) pjsua_call_send_im;
%javamethodmodifiers pjsua_call_send_im( pjsua_call_id call_id, 
					 const pj_str_t *mime_type,
					 const pj_str_t *content,
					 const pjsua_msg_data *msg_data,
					 void *user_data) "public synchronized";
%rename(call_send_typing_ind) pjsua_call_send_typing_ind;
%javamethodmodifiers pjsua_call_send_typing_ind(pjsua_call_id call_id, 
						pj_bool_t is_typing,
						const pjsua_msg_data*msg_data) "public synchronized";
%rename(call_send_request) pjsua_call_send_request;
%javamethodmodifiers pjsua_call_send_request(pjsua_call_id call_id,
					     const pj_str_t *method,
					     const pjsua_msg_data *msg_data) "public synchronized";
%rename(call_hangup_all) pjsua_call_hangup_all;
%javamethodmodifiers pjsua_call_hangup_all(void) "public synchronized";
%rename(call_dump) pjsua_call_dump;
%javamethodmodifiers pjsua_call_dump(pjsua_call_id call_id, 
				     pj_bool_t with_media, 
				     char *buffer, 
				     unsigned maxlen,
				     const char *indent) "public synchronized";
%rename(buddy_config_default) pjsua_buddy_config_default;
%javamethodmodifiers pjsua_buddy_config_default(pjsua_buddy_config *cfg) "public synchronized";
%rename(get_buddy_count) pjsua_get_buddy_count;
%javamethodmodifiers pjsua_get_buddy_count(void) "public synchronized";
%rename(buddy_is_valid) pjsua_buddy_is_valid;
%javamethodmodifiers pjsua_buddy_is_valid(pjsua_buddy_id buddy_id) "public synchronized";
%rename(enum_buddies) pjsua_enum_buddies;
%javamethodmodifiers pjsua_enum_buddies(pjsua_buddy_id ids[],
					unsigned *count) "public synchronized";
%rename(buddy_find) pjsua_buddy_find;
%javamethodmodifiers pjsua_buddy_find(const pj_str_t *uri) "public synchronized";
%rename(buddy_get_info) pjsua_buddy_get_info;
%javamethodmodifiers pjsua_buddy_get_info(pjsua_buddy_id buddy_id,
					  pjsua_buddy_info *info) "public synchronized";
%rename(buddy_set_user_data) pjsua_buddy_set_user_data;
%javamethodmodifiers pjsua_buddy_set_user_data(pjsua_buddy_id buddy_id,
					       void *user_data) "public synchronized";
%rename(buddy_get_user_data) pjsua_buddy_get_user_data;
%javamethodmodifiers pjsua_buddy_get_user_data(pjsua_buddy_id buddy_id) "public synchronized";
%rename(buddy_add) pjsua_buddy_add;
%javamethodmodifiers pjsua_buddy_add(const pjsua_buddy_config *buddy_cfg,
				     pjsua_buddy_id *p_buddy_id) "public synchronized";
%rename(buddy_del) pjsua_buddy_del;
%javamethodmodifiers pjsua_buddy_del(pjsua_buddy_id buddy_id) "public synchronized";
%rename(buddy_subscribe_pres) pjsua_buddy_subscribe_pres;
%javamethodmodifiers pjsua_buddy_subscribe_pres(pjsua_buddy_id buddy_id,
						pj_bool_t subscribe) "public synchronized";
%rename(buddy_update_pres) pjsua_buddy_update_pres;
%javamethodmodifiers pjsua_buddy_update_pres(pjsua_buddy_id buddy_id) "public synchronized";
%rename(pres_notify) pjsua_pres_notify;
%javamethodmodifiers pjsua_pres_notify(pjsua_acc_id acc_id,
				       pjsua_srv_pres *srv_pres,
				       pjsip_evsub_state state,
				       const pj_str_t *state_str,
				       const pj_str_t *reason,
				       pj_bool_t with_body,
				       const pjsua_msg_data *msg_data) "public synchronized";
%rename(pres_dump) pjsua_pres_dump;
%javamethodmodifiers pjsua_pres_dump(pj_bool_t verbose) "public synchronized";
%rename(im_send) pjsua_im_send;
%javamethodmodifiers pjsua_im_send(pjsua_acc_id acc_id, 
				   const pj_str_t *to,
				   const pj_str_t *mime_type,
				   const pj_str_t *content,
				   const pjsua_msg_data *msg_data,
				   void *user_data) "public synchronized";
%rename(im_typing) pjsua_im_typing;
%javamethodmodifiers pjsua_im_typing(pjsua_acc_id acc_id, 
				     const pj_str_t *to, 
				     pj_bool_t is_typing,
				     const pjsua_msg_data *msg_data) "public synchronized";
%rename(media_config_default) pjsua_media_config_default;
%javamethodmodifiers pjsua_media_config_default(pjsua_media_config *cfg) "public synchronized";
%rename(conf_get_max_ports) pjsua_conf_get_max_ports;
%javamethodmodifiers pjsua_conf_get_max_ports(void) "public synchronized";
%rename(conf_get_active_ports) pjsua_conf_get_active_ports;
%javamethodmodifiers pjsua_conf_get_active_ports(void) "public synchronized";
%rename(enum_conf_ports) pjsua_enum_conf_ports;
%javamethodmodifiers pjsua_enum_conf_ports(pjsua_conf_port_id id[],
					   unsigned *count) "public synchronized";
%rename(conf_get_port_info) pjsua_conf_get_port_info;
%javamethodmodifiers pjsua_conf_get_port_info( pjsua_conf_port_id port_id,
					       pjsua_conf_port_info *info) "public synchronized";
%rename(conf_add_port) pjsua_conf_add_port;
%javamethodmodifiers pjsua_conf_add_port(pj_pool_t *pool,
					 pjmedia_port *port,
					 pjsua_conf_port_id *p_id) "public synchronized";
%rename(conf_remove_port) pjsua_conf_remove_port;
%javamethodmodifiers pjsua_conf_remove_port(pjsua_conf_port_id port_id) "public synchronized";
%rename(conf_connect) pjsua_conf_connect;
%javamethodmodifiers pjsua_conf_connect(pjsua_conf_port_id source,
					pjsua_conf_port_id sink) "public synchronized";
%rename(conf_disconnect) pjsua_conf_disconnect;
%javamethodmodifiers pjsua_conf_disconnect(pjsua_conf_port_id source,
					   pjsua_conf_port_id sink) "public synchronized";
%rename(conf_adjust_tx_level) pjsua_conf_adjust_tx_level;
%javamethodmodifiers pjsua_conf_adjust_tx_level(pjsua_conf_port_id slot,
						float level) "public synchronized";
%rename(conf_adjust_rx_level) pjsua_conf_adjust_rx_level;
%javamethodmodifiers pjsua_conf_adjust_rx_level(pjsua_conf_port_id slot,
						float level) "public synchronized";
%rename(conf_get_signal_level) pjsua_conf_get_signal_level;
%javamethodmodifiers pjsua_conf_get_signal_level(pjsua_conf_port_id slot,
						 unsigned *tx_level,
						 unsigned *rx_level) "public synchronized";
%rename(player_create) pjsua_player_create;
%javamethodmodifiers pjsua_player_create(const pj_str_t *filename,
					 unsigned options,
					 pjsua_player_id *p_id) "public synchronized";
%rename(playlist_create) pjsua_playlist_create;
%javamethodmodifiers pjsua_playlist_create(const pj_str_t file_names[],
					   unsigned file_count,
					   const pj_str_t *label,
					   unsigned options,
					   pjsua_player_id *p_id) "public synchronized";
%rename(player_get_conf_port) pjsua_player_get_conf_port;
%javamethodmodifiers pjsua_player_get_conf_port(pjsua_player_id id) "public synchronized";
%rename(player_get_port) pjsua_player_get_port;
%javamethodmodifiers pjsua_player_get_port(pjsua_player_id id,
					   pjmedia_port **p_port) "public synchronized";
%rename(player_set_pos) pjsua_player_set_pos;
%javamethodmodifiers pjsua_player_set_pos(pjsua_player_id id,
					  pj_uint32_t samples) "public synchronized";
%rename(player_destroy) pjsua_player_destroy;
%javamethodmodifiers pjsua_player_destroy(pjsua_player_id id) "public synchronized";
%rename(recorder_create) pjsua_recorder_create;
%javamethodmodifiers pjsua_recorder_create(const pj_str_t *filename,
					   unsigned enc_type,
					   void *enc_param,
					   pj_ssize_t max_size,
					   unsigned options,
					   pjsua_recorder_id *p_id) "public synchronized";
%rename(recorder_get_conf_port) pjsua_recorder_get_conf_port;
%javamethodmodifiers pjsua_recorder_get_conf_port(pjsua_recorder_id id) "public synchronized";
%rename(recorder_get_port) pjsua_recorder_get_port;
%javamethodmodifiers pjsua_recorder_get_port(pjsua_recorder_id id,
					     pjmedia_port **p_port) "public synchronized";
%rename(recorder_destroy) pjsua_recorder_destroy;
%javamethodmodifiers pjsua_recorder_destroy(pjsua_recorder_id id) "public synchronized";
%rename(enum_aud_devs) pjsua_enum_aud_devs;
%javamethodmodifiers pjsua_enum_aud_devs(pjmedia_aud_dev_info info[],
					 unsigned *count) "public synchronized";
%rename(enum_snd_devs) pjsua_enum_snd_devs;
%javamethodmodifiers pjsua_enum_snd_devs(pjmedia_snd_dev_info info[],
					 unsigned *count) "public synchronized";
%rename(get_snd_dev) pjsua_get_snd_dev;
%javamethodmodifiers pjsua_get_snd_dev(int *capture_dev,
				       int *playback_dev) "public synchronized";
%rename(set_snd_dev) pjsua_set_snd_dev;
%javamethodmodifiers pjsua_set_snd_dev(int capture_dev,
				       int playback_dev) "public synchronized";
%rename(set_null_snd_dev) pjsua_set_null_snd_dev;
%javamethodmodifiers pjsua_set_null_snd_dev(void) "public synchronized";
%rename(set_no_snd_dev) pjsua_set_no_snd_dev;
%javamethodmodifiers pjsua_set_no_snd_dev(void) "public synchronized";
%rename(set_ec) pjsua_set_ec;
%javamethodmodifiers pjsua_set_ec(unsigned tail_ms, unsigned options) "public synchronized";
%rename(get_ec_tail) pjsua_get_ec_tail;
%javamethodmodifiers pjsua_get_ec_tail(unsigned *p_tail_ms) "public synchronized";
%rename(snd_is_active) pjsua_snd_is_active;
%javamethodmodifiers pjsua_snd_is_active(void) "public synchronized";
%rename(snd_set_setting) pjsua_snd_set_setting;
%javamethodmodifiers pjsua_snd_set_setting(pjmedia_aud_dev_cap cap,
					   const void *pval,
					   pj_bool_t keep) "public synchronized";
%rename(snd_get_setting) pjsua_snd_get_setting;
%javamethodmodifiers pjsua_snd_get_setting(pjmedia_aud_dev_cap cap,
					   void *pval) "public synchronized";
%rename(enum_codecs) pjsua_enum_codecs;
%javamethodmodifiers pjsua_enum_codecs( pjsua_codec_info id[],
				        unsigned *count ) "public synchronized";
%rename(codec_set_priority) pjsua_codec_set_priority;
%javamethodmodifiers pjsua_codec_set_priority( const pj_str_t *codec_id,
					       pj_uint8_t priority ) "public synchronized";
%rename(codec_get_param) pjsua_codec_get_param;
%javamethodmodifiers pjsua_codec_get_param( const pj_str_t *codec_id,
					    pjmedia_codec_param *param ) "public synchronized";
%rename(codec_set_param) pjsua_codec_set_param;
%javamethodmodifiers pjsua_codec_set_param( const pj_str_t *codec_id,
					    const pjmedia_codec_param *param) "public synchronized";
%rename(media_transports_create) pjsua_media_transports_create;
%javamethodmodifiers pjsua_media_transports_create(const pjsua_transport_config *cfg) "public synchronized";

#define PJSUA_INVALID_ID	    (-1)
typedef int pjsua_call_id;
typedef int pjsua_acc_id;
typedef int pjsua_buddy_id;
typedef int pjsua_player_id;
typedef int pjsua_recorder_id;
typedef int pjsua_conf_port_id;
typedef struct pjsua_srv_pres pjsua_srv_pres;
typedef struct pjsua_msg_data pjsua_msg_data;
#ifndef PJSUA_ACC_MAX_PROXIES
#   define PJSUA_ACC_MAX_PROXIES    8
#endif
#if defined(PJMEDIA_HAS_SRTP) && (PJMEDIA_HAS_SRTP != 0)
#ifndef PJSUA_DEFAULT_USE_SRTP
    #define PJSUA_DEFAULT_USE_SRTP  PJMEDIA_SRTP_DISABLED
#endif
#ifndef PJSUA_DEFAULT_SRTP_SECURE_SIGNALING
    #define PJSUA_DEFAULT_SRTP_SECURE_SIGNALING 1
#endif
#endif
//#if defined(PJMEDIA_HAS_ZRTP) && (PJMEDIA_HAS_ZRTP != 0)
#ifndef PJSUA_DEFAULT_USE_ZRTP
    #define PJSUA_DEFAULT_USE_ZRTP  PJMEDIA_CREATE_ZRTP
#endif
//#endif
#ifndef PJSUA_ADD_ICE_TAGS
#   define PJSUA_ADD_ICE_TAGS		1
#endif
#ifndef PJSUA_ACQUIRE_CALL_TIMEOUT
#   define PJSUA_ACQUIRE_CALL_TIMEOUT 2000
#endif
typedef struct pjsua_logging_config
{
    pj_bool_t	msg_logging;
    unsigned	level;
    unsigned	console_level;
    unsigned	decor;
    pj_str_t	log_filename;
    unsigned	log_file_flags;
    void       (*cb)(int level, const char *data, int len);
} pjsua_logging_config;
PJ_DECL(void) pjsua_logging_config_default(pjsua_logging_config *cfg);
PJ_DECL(void) pjsua_logging_config_dup(pj_pool_t *pool,
				       pjsua_logging_config *dst,
				       const pjsua_logging_config *src);
typedef struct pjsua_mwi_info
{
    pjsip_evsub	    *evsub;	
    pjsip_rx_data   *rdata;	
} pjsua_mwi_info;
typedef struct pjsua_reg_info
{
    struct pjsip_regc_cbparam	*cbparam;   
} pjsua_reg_info;
typedef struct pjsua_callback
{
    void (*on_call_state)(pjsua_call_id call_id, pjsip_event *e);
    void (*on_incoming_call)(pjsua_acc_id acc_id, pjsua_call_id call_id,
			     pjsip_rx_data *rdata);
    void (*on_call_tsx_state)(pjsua_call_id call_id, 
			      pjsip_transaction *tsx,
			      pjsip_event *e);
    void (*on_call_media_state)(pjsua_call_id call_id);
    void (*on_stream_created)(pjsua_call_id call_id, 
			      pjmedia_session *sess,
                              unsigned stream_idx, 
			      pjmedia_port **p_port);
    void (*on_stream_destroyed)(pjsua_call_id call_id,
                                pjmedia_session *sess, 
				unsigned stream_idx);
    void (*on_dtmf_digit)(pjsua_call_id call_id, int digit);
    void (*on_call_transfer_request)(pjsua_call_id call_id,
				     const pj_str_t *dst,
				     pjsip_status_code *code);
    void (*on_call_transfer_status)(pjsua_call_id call_id,
				    int st_code,
				    const pj_str_t *st_text,
				    pj_bool_t final,
				    pj_bool_t *p_cont);
    void (*on_call_replace_request)(pjsua_call_id call_id,
				    pjsip_rx_data *rdata,
				    int *st_code,
				    pj_str_t *st_text);
    void (*on_call_replaced)(pjsua_call_id old_call_id,
			     pjsua_call_id new_call_id);
    void (*on_reg_state)(pjsua_acc_id acc_id);
    void (*on_reg_state2)(pjsua_acc_id acc_id, pjsua_reg_info *info);
    void (*on_incoming_subscribe)(pjsua_acc_id acc_id,
				  pjsua_srv_pres *srv_pres,
				  pjsua_buddy_id buddy_id,
				  const pj_str_t *from,
				  pjsip_rx_data *rdata,
				  pjsip_status_code *code,
				  pj_str_t *reason,
				  pjsua_msg_data *msg_data);
    void (*on_srv_subscribe_state)(pjsua_acc_id acc_id,
				   pjsua_srv_pres *srv_pres,
				   const pj_str_t *remote_uri,
				   pjsip_evsub_state state,
				   pjsip_event *event);
    void (*on_buddy_state)(pjsua_buddy_id buddy_id);
    void (*on_buddy_evsub_state)(pjsua_buddy_id buddy_id,
				 pjsip_evsub *sub,
				 pjsip_event *event);
    void (*on_pager)(pjsua_call_id call_id, const pj_str_t *from,
		     const pj_str_t *to, const pj_str_t *contact,
		     const pj_str_t *mime_type, const pj_str_t *body);
    void (*on_pager2)(pjsua_call_id call_id, const pj_str_t *from,
		      const pj_str_t *to, const pj_str_t *contact,
		      const pj_str_t *mime_type, const pj_str_t *body,
		      pjsip_rx_data *rdata, pjsua_acc_id acc_id);
    void (*on_pager_status)(pjsua_call_id call_id,
			    const pj_str_t *to,
			    const pj_str_t *body,
			    void *user_data,
			    pjsip_status_code status,
			    const pj_str_t *reason);
    void (*on_pager_status2)(pjsua_call_id call_id,
			     const pj_str_t *to,
			     const pj_str_t *body,
			     void *user_data,
			     pjsip_status_code status,
			     const pj_str_t *reason,
			     pjsip_tx_data *tdata,
			     pjsip_rx_data *rdata,
			     pjsua_acc_id acc_id);
    void (*on_typing)(pjsua_call_id call_id, const pj_str_t *from,
		      const pj_str_t *to, const pj_str_t *contact,
		      pj_bool_t is_typing);
    void (*on_typing2)(pjsua_call_id call_id, const pj_str_t *from,
		       const pj_str_t *to, const pj_str_t *contact,
		       pj_bool_t is_typing, pjsip_rx_data *rdata,
		       pjsua_acc_id acc_id);
    void (*on_nat_detect)(const pj_stun_nat_detect_result *res);
    pjsip_redirect_op (*on_call_redirected)(pjsua_call_id call_id, 
					    const pjsip_uri *target,
					    const pjsip_event *e);
    void (*on_mwi_info)(pjsua_acc_id acc_id, pjsua_mwi_info *mwi_info);
    pjsip_tp_state_callback on_transport_state;
    void (*on_ice_transport_error)(int index, pj_ice_strans_op op,
				   pj_status_t status, void *param);
//#if defined(PJMEDIA_HAS_ZRTP) && (PJMEDIA_HAS_ZRTP != 0)
    pj_status_t (*on_zrtp_transport_created)(pjmedia_transport *tp, pjsua_call_id call_id);
//#endif
} pjsua_callback;
typedef enum pjsua_sip_timer_use
{
    PJSUA_SIP_TIMER_INACTIVE,
    PJSUA_SIP_TIMER_OPTIONAL,
    PJSUA_SIP_TIMER_REQUIRED,
    PJSUA_SIP_TIMER_ALWAYS
} pjsua_sip_timer_use;
typedef enum pjsua_100rel_use
{
    PJSUA_100REL_NOT_USED,
    PJSUA_100REL_MANDATORY,
    PJSUA_100REL_OPTIONAL
} pjsua_100rel_use;
typedef struct pjsua_config
{
    unsigned	    max_calls;
    unsigned	    thread_cnt;
    unsigned	    nameserver_count;
    pj_str_t	    nameserver[4];
    pj_bool_t	    force_lr;
    unsigned	    outbound_proxy_cnt;
    pj_str_t	    outbound_proxy[4];
    pj_str_t	    stun_domain;
    pj_str_t	    stun_host;
    unsigned	    stun_srv_cnt;
    pj_str_t	    stun_srv[8];
    pj_bool_t	    stun_ignore_failure;
    int		    nat_type_in_sdp;
    pjsua_100rel_use require_100rel;
    pjsua_sip_timer_use use_timer;
    pj_bool_t	    enable_unsolicited_mwi;
    pjsip_timer_setting timer_setting;
    unsigned	    cred_count;
    pjsip_cred_info cred_info[PJSUA_ACC_MAX_PROXIES];
    pjsua_callback  cb;
    pj_str_t	    user_agent;
#if defined(PJMEDIA_HAS_SRTP) && (PJMEDIA_HAS_SRTP != 0)
    pjmedia_srtp_use	use_srtp;
    int		     srtp_secure_signaling;
    pj_bool_t	     srtp_optional_dup_offer;
#endif
    pj_bool_t	     hangup_forked_call;
} pjsua_config;
PJ_DECL(void) pjsua_config_default(pjsua_config *cfg);
#define pjsip_cred_dup	pjsip_cred_info_dup
PJ_DECL(void) pjsua_config_dup(pj_pool_t *pool,
			       pjsua_config *dst,
			       const pjsua_config *src);
struct pjsua_msg_data
{
    pjsip_hdr	hdr_list;
    pj_str_t	content_type;
    pj_str_t	msg_body;
    pjsip_media_type  multipart_ctype;
    pjsip_multipart_part multipart_parts;
};
PJ_DECL(void) pjsua_msg_data_init(pjsua_msg_data *msg_data);
PJ_DECL(pj_status_t) pjsua_create(void);
PJ_DECL(pj_status_t) pjsua_start(void);
PJ_DECL(int) pjsua_handle_events(unsigned msec_timeout);
PJ_DECL(pj_pool_t*) pjsua_pool_create(const char *name, pj_size_t init_size,
				      pj_size_t increment);
PJ_DECL(pj_status_t) pjsua_reconfigure_logging(const pjsua_logging_config *c);
PJ_DECL(pjsip_endpoint*) pjsua_get_pjsip_endpt(void);
PJ_DECL(pjmedia_endpt*) pjsua_get_pjmedia_endpt(void);
PJ_DECL(pj_pool_factory*) pjsua_get_pool_factory(void);
typedef struct pj_stun_resolve_result
{
    void	    *token;
    pj_status_t	     status;
    pj_str_t	     name;
    pj_sockaddr	     addr;
} pj_stun_resolve_result;
typedef void (*pj_stun_resolve_cb)(const pj_stun_resolve_result *result);
PJ_DECL(pj_status_t) pjsua_detect_nat_type(void);
PJ_DECL(pj_status_t) pjsua_get_nat_type(pj_stun_nat_type *type);
PJ_DECL(pj_status_t) pjsua_resolve_stun_servers(unsigned count,
						pj_str_t srv[],
						pj_bool_t wait,
						void *token,
						pj_stun_resolve_cb cb);
PJ_DECL(pj_status_t) pjsua_cancel_stun_resolution(void *token,
						  pj_bool_t notify_cb);
PJ_DECL(pj_status_t) pjsua_verify_sip_url(const char *url);
PJ_DECL(pj_status_t) pjsua_verify_url(const char *url);
PJ_DECL(pj_status_t) pjsua_schedule_timer(pj_timer_entry *entry,
					  const pj_time_val *delay);
PJ_DECL(void) pjsua_cancel_timer(pj_timer_entry *entry);
PJ_DECL(void) pjsua_perror(const char *sender, const char *title, 
			   pj_status_t status);
PJ_DECL(void) pjsua_dump(pj_bool_t detail);
typedef int pjsua_transport_id;
typedef struct pjsua_transport_config
{
    unsigned		port;
    pj_str_t		public_addr;
    pj_str_t		bound_addr;
    pjsip_tls_setting	tls_setting;
    pj_qos_type		qos_type;
    pj_qos_params	qos_params;
} pjsua_transport_config;
PJ_DECL(void) pjsua_transport_config_default(pjsua_transport_config *cfg);
PJ_DECL(void) pjsua_transport_config_dup(pj_pool_t *pool,
					 pjsua_transport_config *dst,
					 const pjsua_transport_config *src);
typedef struct pjsua_transport_info
{
    pjsua_transport_id	    id;
    pjsip_transport_type_e  type;
    pj_str_t		    type_name;
    pj_str_t		    info;
    unsigned		    flag;
    unsigned		    addr_len;
    pj_sockaddr		    local_addr;
    pjsip_host_port	    local_name;
    unsigned		    usage_count;
} pjsua_transport_info;
PJ_DECL(pj_status_t) pjsua_transport_create(pjsip_transport_type_e type,
					    const pjsua_transport_config *cfg,
					    pjsua_transport_id *p_id);
PJ_DECL(pj_status_t) pjsua_transport_register(pjsip_transport *tp,
					      pjsua_transport_id *p_id);
PJ_DECL(pj_status_t) pjsua_enum_transports( pjsua_transport_id id[],
					    unsigned *count );
PJ_DECL(pj_status_t) pjsua_transport_get_info(pjsua_transport_id id,
					      pjsua_transport_info *info);
PJ_DECL(pj_status_t) pjsua_transport_set_enable(pjsua_transport_id id,
						pj_bool_t enabled);
PJ_DECL(pj_status_t) pjsua_transport_close( pjsua_transport_id id,
					    pj_bool_t force );
#ifndef PJSUA_MAX_ACC
#   define PJSUA_MAX_ACC	    8
#endif
#ifndef PJSUA_REG_INTERVAL
#   define PJSUA_REG_INTERVAL	    300
#endif
#ifndef PJSUA_UNREG_TIMEOUT
#   define PJSUA_UNREG_TIMEOUT	    4000
#endif
#ifndef PJSUA_PUBLISH_EXPIRATION
#   define PJSUA_PUBLISH_EXPIRATION PJSIP_PUBC_EXPIRATION_NOT_SPECIFIED
#endif
#ifndef PJSUA_DEFAULT_ACC_PRIORITY
#   define PJSUA_DEFAULT_ACC_PRIORITY	0
#endif
#ifndef PJSUA_SECURE_SCHEME
#   define PJSUA_SECURE_SCHEME		"sip"
#endif
#ifndef PJSUA_UNPUBLISH_MAX_WAIT_TIME_MSEC
#   define PJSUA_UNPUBLISH_MAX_WAIT_TIME_MSEC	2000
#endif
#ifndef PJSUA_REG_RETRY_INTERVAL
#   define PJSUA_REG_RETRY_INTERVAL	300
#endif
#ifndef PJSUA_CONTACT_REWRITE_METHOD
#   define PJSUA_CONTACT_REWRITE_METHOD		2
#endif
#define PJSUA_REG_USE_OUTBOUND_PROXY		1
#define PJSUA_REG_USE_ACC_PROXY			2
typedef enum pjsua_call_hold_type
{
    PJSUA_CALL_HOLD_TYPE_RFC3264,
    PJSUA_CALL_HOLD_TYPE_RFC2543
} pjsua_call_hold_type;
#ifndef PJSUA_CALL_HOLD_TYPE_DEFAULT
#   define PJSUA_CALL_HOLD_TYPE_DEFAULT		PJSUA_CALL_HOLD_TYPE_RFC3264
#endif
typedef struct pjsua_acc_config
{
    void	   *user_data;
    int		    priority;
    pj_str_t	    id;
    pj_str_t	    reg_uri;
    pjsip_hdr	    reg_hdr_list;
    pjsip_hdr	    sub_hdr_list;
    pj_bool_t	    mwi_enabled;
    pj_bool_t	    publish_enabled;
    pjsip_publishc_opt	publish_opt;
    unsigned	    unpublish_max_wait_time_msec;
    pjsip_auth_clt_pref auth_pref;
    pj_str_t	    pidf_tuple_id;
    pj_str_t	    force_contact;
    pj_str_t	    contact_params;
    pj_str_t	    contact_uri_params;
    pjsua_100rel_use require_100rel;
    pjsua_sip_timer_use use_timer;
    pjsip_timer_setting timer_setting;
    unsigned	    proxy_cnt;
    pj_str_t	    proxy[PJSUA_ACC_MAX_PROXIES];
    unsigned	    reg_timeout;
    unsigned	    reg_delay_before_refresh;
    unsigned	    unreg_timeout;
    unsigned	    cred_count;
    pjsip_cred_info cred_info[PJSUA_ACC_MAX_PROXIES];
    pjsua_transport_id  transport_id;
    pj_bool_t allow_contact_rewrite;
    int		     contact_rewrite_method;
    unsigned	     use_rfc5626;
    pj_str_t	     rfc5626_instance_id;
    pj_str_t	     rfc5626_reg_id;
    unsigned	     ka_interval;
    pj_str_t	     ka_data;
#if defined(PJMEDIA_HAS_SRTP) && (PJMEDIA_HAS_SRTP != 0)
    pjmedia_srtp_use	use_srtp;
    int		     srtp_secure_signaling;
    pj_bool_t	     srtp_optional_dup_offer;
#endif
//#if defined(PJMEDIA_HAS_ZRTP) && (PJMEDIA_HAS_ZRTP != 0)
    pjmedia_zrtp_use     use_zrtp;
//#endif
    unsigned	     reg_retry_interval;
    pj_bool_t	     drop_calls_on_reg_fail;
    unsigned	     reg_use_proxy;
#if defined(PJMEDIA_STREAM_ENABLE_KA) && (PJMEDIA_STREAM_ENABLE_KA != 0)
    pj_bool_t	     use_stream_ka;
#endif
    pjsua_call_hold_type call_hold_type;
} pjsua_acc_config;
PJ_DECL(void) pjsua_acc_config_default(pjsua_acc_config *cfg);
PJ_DECL(void) pjsua_acc_config_dup(pj_pool_t *pool,
				   pjsua_acc_config *dst,
				   const pjsua_acc_config *src);
typedef struct pjsua_acc_info
{
    pjsua_acc_id	id;
    pj_bool_t		is_default;
    pj_str_t		acc_uri;
    pj_bool_t		has_registration;
    int			expires;
    pjsip_status_code	status;
    pj_status_t	        reg_last_err;
    pj_str_t		status_text;
    pj_bool_t		online_status;
    pj_str_t		online_status_text;
    pjrpid_element	rpid;
    char		buf_[PJ_ERR_MSG_SIZE];
} pjsua_acc_info;
PJ_DECL(unsigned) pjsua_acc_get_count(void);
PJ_DECL(pj_bool_t) pjsua_acc_is_valid(pjsua_acc_id acc_id);
PJ_DECL(pj_status_t) pjsua_acc_set_default(pjsua_acc_id acc_id);
PJ_DECL(pjsua_acc_id) pjsua_acc_get_default(void);
PJ_DECL(pj_status_t) pjsua_acc_add(const pjsua_acc_config *acc_cfg,
				   pj_bool_t is_default,
				   pjsua_acc_id *p_acc_id);
PJ_DECL(pj_status_t) pjsua_acc_add_local(pjsua_transport_id tid,
					 pj_bool_t is_default,
					 pjsua_acc_id *p_acc_id);
PJ_DECL(pj_status_t) pjsua_acc_set_user_data(pjsua_acc_id acc_id,
					     void *user_data);
PJ_DECL(void*) pjsua_acc_get_user_data(pjsua_acc_id acc_id);
PJ_DECL(pj_status_t) pjsua_acc_del(pjsua_acc_id acc_id);
PJ_DECL(pj_status_t) pjsua_acc_modify(pjsua_acc_id acc_id,
				      const pjsua_acc_config *acc_cfg);
PJ_DECL(pj_status_t) pjsua_acc_set_online_status(pjsua_acc_id acc_id,
						 pj_bool_t is_online);
PJ_DECL(pj_status_t) pjsua_acc_set_online_status2(pjsua_acc_id acc_id,
						  pj_bool_t is_online,
						  const pjrpid_element *pr);
PJ_DECL(pj_status_t) pjsua_acc_set_registration(pjsua_acc_id acc_id, 
						pj_bool_t renew);
PJ_DECL(pj_status_t) pjsua_acc_get_info(pjsua_acc_id acc_id,
					pjsua_acc_info *info);
PJ_DECL(pj_status_t) pjsua_enum_accs(pjsua_acc_id ids[],
				     unsigned *count );
PJ_DECL(pj_status_t) pjsua_acc_enum_info( pjsua_acc_info info[],
					  unsigned *count );
PJ_DECL(pjsua_acc_id) pjsua_acc_find_for_outgoing(const pj_str_t *url);
PJ_DECL(pjsua_acc_id) pjsua_acc_find_for_incoming(pjsip_rx_data *rdata);
PJ_DECL(pj_status_t) pjsua_acc_create_request(pjsua_acc_id acc_id,
					      const pjsip_method *method,
					      const pj_str_t *target,
					      pjsip_tx_data **p_tdata);
PJ_DECL(pj_status_t) pjsua_acc_create_uac_contact( pj_pool_t *pool,
						   pj_str_t *contact,
						   pjsua_acc_id acc_id,
						   const pj_str_t *uri);
PJ_DECL(pj_status_t) pjsua_acc_create_uas_contact( pj_pool_t *pool,
						   pj_str_t *contact,
						   pjsua_acc_id acc_id,
						   pjsip_rx_data *rdata );
PJ_DECL(pj_status_t) pjsua_acc_set_transport(pjsua_acc_id acc_id,
					     pjsua_transport_id tp_id);
#ifndef PJSUA_MAX_CALLS
#   define PJSUA_MAX_CALLS	    32
#endif
typedef enum pjsua_call_media_status
{
    PJSUA_CALL_MEDIA_NONE,
    PJSUA_CALL_MEDIA_ACTIVE,
    PJSUA_CALL_MEDIA_LOCAL_HOLD,
    PJSUA_CALL_MEDIA_REMOTE_HOLD,
    PJSUA_CALL_MEDIA_ERROR
} pjsua_call_media_status;
typedef struct pjsua_call_info
{
    pjsua_call_id	id;
    pjsip_role_e	role;
    pjsua_acc_id	acc_id;
    pj_str_t		local_info;
    pj_str_t		local_contact;
    pj_str_t		remote_info;
    pj_str_t		remote_contact;
    pj_str_t		call_id;
    pjsip_inv_state	state;
    pj_str_t		state_text;
    pjsip_status_code	last_status;
    pj_str_t		last_status_text;
    pjsua_call_media_status media_status;
    pjmedia_dir		media_dir;
    pjsua_conf_port_id	conf_slot;
    pj_time_val		connect_duration;
    pj_time_val		total_duration;
    struct {
	char	local_info[128];
	char	local_contact[128];
	char	remote_info[128];
	char	remote_contact[128];
	char	call_id[128];
	char	last_status_text[128];
    } buf_;
} pjsua_call_info;
typedef enum pjsua_call_flag
{
    PJSUA_CALL_UNHOLD = 1,
    PJSUA_CALL_UPDATE_CONTACT = 2
} pjsua_call_flag;
PJ_DECL(unsigned) pjsua_call_get_max_count(void);
PJ_DECL(unsigned) pjsua_call_get_count(void);
PJ_DECL(pj_status_t) pjsua_enum_calls(pjsua_call_id ids[],
				      unsigned *count);
PJ_DECL(pj_status_t) pjsua_call_make_call(pjsua_acc_id acc_id,
					  const pj_str_t *dst_uri,
					  unsigned options,
					  void *user_data,
					  const pjsua_msg_data *msg_data,
					  pjsua_call_id *p_call_id);
PJ_DECL(pj_bool_t) pjsua_call_is_active(pjsua_call_id call_id);
PJ_DECL(pj_bool_t) pjsua_call_has_media(pjsua_call_id call_id);
PJ_DECL(pjmedia_session*) pjsua_call_get_media_session(pjsua_call_id call_id);
PJ_DECL(pjmedia_transport*) pjsua_call_get_media_transport(pjsua_call_id cid);
PJ_DECL(pjsua_conf_port_id) pjsua_call_get_conf_port(pjsua_call_id call_id);
PJ_DECL(pj_status_t) pjsua_call_get_info(pjsua_call_id call_id,
					 pjsua_call_info *info);
PJ_DECL(pjsip_dialog_cap_status) pjsua_call_remote_has_cap(
						    pjsua_call_id call_id,
						    int htype,
						    const pj_str_t *hname,
						    const pj_str_t *token);
PJ_DECL(pj_status_t) pjsua_call_set_user_data(pjsua_call_id call_id,
					      void *user_data);
PJ_DECL(void*) pjsua_call_get_user_data(pjsua_call_id call_id);
PJ_DECL(pj_status_t) pjsua_call_get_rem_nat_type(pjsua_call_id call_id,
						 pj_stun_nat_type *p_type);
PJ_DECL(pj_status_t) pjsua_call_answer(pjsua_call_id call_id, 
				       unsigned code,
				       const pj_str_t *reason,
				       const pjsua_msg_data *msg_data);
PJ_DECL(pj_status_t) pjsua_call_hangup(pjsua_call_id call_id,
				       unsigned code,
				       const pj_str_t *reason,
				       const pjsua_msg_data *msg_data);
PJ_DECL(pj_status_t) pjsua_call_process_redirect(pjsua_call_id call_id,
						 pjsip_redirect_op cmd);
PJ_DECL(pj_status_t) pjsua_call_set_hold(pjsua_call_id call_id,
					 const pjsua_msg_data *msg_data);
PJ_DECL(pj_status_t) pjsua_call_reinvite(pjsua_call_id call_id,
					 unsigned options,
					 const pjsua_msg_data *msg_data);
PJ_DECL(pj_status_t) pjsua_call_update(pjsua_call_id call_id,
				       unsigned options,
				       const pjsua_msg_data *msg_data);
PJ_DECL(pj_status_t) pjsua_call_xfer(pjsua_call_id call_id, 
				     const pj_str_t *dest,
				     const pjsua_msg_data *msg_data);
#define PJSUA_XFER_NO_REQUIRE_REPLACES	1
PJ_DECL(pj_status_t) pjsua_call_xfer_replaces(pjsua_call_id call_id, 
					      pjsua_call_id dest_call_id,
					      unsigned options,
					      const pjsua_msg_data *msg_data);
PJ_DECL(pj_status_t) pjsua_call_dial_dtmf(pjsua_call_id call_id, 
					  const pj_str_t *digits);
PJ_DECL(pj_status_t) pjsua_call_send_im( pjsua_call_id call_id, 
					 const pj_str_t *mime_type,
					 const pj_str_t *content,
					 const pjsua_msg_data *msg_data,
					 void *user_data);
PJ_DECL(pj_status_t) pjsua_call_send_typing_ind(pjsua_call_id call_id, 
						pj_bool_t is_typing,
						const pjsua_msg_data*msg_data);
PJ_DECL(pj_status_t) pjsua_call_send_request(pjsua_call_id call_id,
					     const pj_str_t *method,
					     const pjsua_msg_data *msg_data);
PJ_DECL(void) pjsua_call_hangup_all(void);
PJ_DECL(pj_status_t) pjsua_call_dump(pjsua_call_id call_id, 
				     pj_bool_t with_media, 
				     char *buffer, 
				     unsigned maxlen,
				     const char *indent);
#ifndef PJSUA_MAX_BUDDIES
#   define PJSUA_MAX_BUDDIES	    256
#endif
#ifndef PJSUA_PRES_TIMER
#   define PJSUA_PRES_TIMER	    300
#endif
typedef struct pjsua_buddy_config
{
    pj_str_t	uri;
    pj_bool_t	subscribe;
    void       *user_data;
} pjsua_buddy_config;
typedef enum pjsua_buddy_status
{
    PJSUA_BUDDY_STATUS_UNKNOWN,
    PJSUA_BUDDY_STATUS_ONLINE,
    PJSUA_BUDDY_STATUS_OFFLINE,
} pjsua_buddy_status;
typedef struct pjsua_buddy_info
{
    pjsua_buddy_id	id;
    pj_str_t		uri;
    pj_str_t		contact;
    pjsua_buddy_status	status;
    pj_str_t		status_text;
    pj_bool_t		monitor_pres;
    pjsip_evsub_state	sub_state;
    const char	       *sub_state_name;
    unsigned		sub_term_code;
    pj_str_t		sub_term_reason;
    pjrpid_element	rpid;
    pjsip_pres_status	pres_status;
    char		buf_[512];
} pjsua_buddy_info;
PJ_DECL(void) pjsua_buddy_config_default(pjsua_buddy_config *cfg);
PJ_DECL(unsigned) pjsua_get_buddy_count(void);
PJ_DECL(pj_bool_t) pjsua_buddy_is_valid(pjsua_buddy_id buddy_id);
PJ_DECL(pj_status_t) pjsua_enum_buddies(pjsua_buddy_id ids[],
					unsigned *count);
PJ_DECL(pjsua_buddy_id) pjsua_buddy_find(const pj_str_t *uri);
PJ_DECL(pj_status_t) pjsua_buddy_get_info(pjsua_buddy_id buddy_id,
					  pjsua_buddy_info *info);
PJ_DECL(pj_status_t) pjsua_buddy_set_user_data(pjsua_buddy_id buddy_id,
					       void *user_data);
PJ_DECL(void*) pjsua_buddy_get_user_data(pjsua_buddy_id buddy_id);
PJ_DECL(pj_status_t) pjsua_buddy_add(const pjsua_buddy_config *buddy_cfg,
				     pjsua_buddy_id *p_buddy_id);
PJ_DECL(pj_status_t) pjsua_buddy_del(pjsua_buddy_id buddy_id);
PJ_DECL(pj_status_t) pjsua_buddy_subscribe_pres(pjsua_buddy_id buddy_id,
						pj_bool_t subscribe);
PJ_DECL(pj_status_t) pjsua_buddy_update_pres(pjsua_buddy_id buddy_id);
PJ_DECL(pj_status_t) pjsua_pres_notify(pjsua_acc_id acc_id,
				       pjsua_srv_pres *srv_pres,
				       pjsip_evsub_state state,
				       const pj_str_t *state_str,
				       const pj_str_t *reason,
				       pj_bool_t with_body,
				       const pjsua_msg_data *msg_data);
PJ_DECL(void) pjsua_pres_dump(pj_bool_t verbose);
extern const pjsip_method pjsip_message_method;
PJ_DECL(pj_status_t) pjsua_im_send(pjsua_acc_id acc_id, 
				   const pj_str_t *to,
				   const pj_str_t *mime_type,
				   const pj_str_t *content,
				   const pjsua_msg_data *msg_data,
				   void *user_data);
PJ_DECL(pj_status_t) pjsua_im_typing(pjsua_acc_id acc_id, 
				     const pj_str_t *to, 
				     pj_bool_t is_typing,
				     const pjsua_msg_data *msg_data);
#ifndef PJSUA_MAX_CONF_PORTS
#   define PJSUA_MAX_CONF_PORTS		254
#endif
#ifndef PJSUA_DEFAULT_CLOCK_RATE
#   define PJSUA_DEFAULT_CLOCK_RATE	16000
#endif
#ifndef PJSUA_DEFAULT_AUDIO_FRAME_PTIME
#   define PJSUA_DEFAULT_AUDIO_FRAME_PTIME  20
#endif
#ifndef PJSUA_DEFAULT_CODEC_QUALITY
#   define PJSUA_DEFAULT_CODEC_QUALITY	8
#endif
#ifndef PJSUA_DEFAULT_ILBC_MODE
#   define PJSUA_DEFAULT_ILBC_MODE	30
#endif
#ifndef PJSUA_DEFAULT_EC_TAIL_LEN
#   define PJSUA_DEFAULT_EC_TAIL_LEN	200
#endif
#ifndef PJSUA_MAX_PLAYERS
#   define PJSUA_MAX_PLAYERS		32
#endif
#ifndef PJSUA_MAX_RECORDERS
#   define PJSUA_MAX_RECORDERS		32
#endif
struct pjsua_media_config
{
    unsigned		clock_rate;
    unsigned		snd_clock_rate;
    unsigned		channel_count;
    unsigned		audio_frame_ptime;
    unsigned		max_media_ports;
    pj_bool_t		has_ioqueue;
    unsigned		thread_cnt;
    unsigned		quality;
    unsigned		ptime;
    pj_bool_t		no_vad;
    unsigned		ilbc_mode;
    unsigned		tx_drop_pct;
    unsigned		rx_drop_pct;
    unsigned		ec_options;
    unsigned		ec_tail_len;
    unsigned		snd_rec_latency;
    unsigned		snd_play_latency;
    int			jb_init;
    int			jb_min_pre;
    int			jb_max_pre;
    int			jb_max;
    pj_bool_t		enable_ice;
    int			ice_max_host_cands;
    pj_ice_sess_options	ice_opt;
    pj_bool_t		ice_no_rtcp;
    pj_bool_t		enable_turn;
    pj_str_t		turn_server;
    pj_turn_tp_type	turn_conn_type;
    pj_stun_auth_cred	turn_auth_cred;
    int			snd_auto_close_time;
};
PJ_DECL(void) pjsua_media_config_default(pjsua_media_config *cfg);
typedef struct pjsua_codec_info
{
    pj_str_t		codec_id;
    pj_uint8_t		priority;
    char		buf_[32];
} pjsua_codec_info;
typedef struct pjsua_conf_port_info
{
    pjsua_conf_port_id	slot_id;
    pj_str_t		name;
    unsigned		clock_rate;
    unsigned		channel_count;
    unsigned		samples_per_frame;
    unsigned		bits_per_sample;
    unsigned		listener_cnt;
    pjsua_conf_port_id	listeners[PJSUA_MAX_CONF_PORTS];
} pjsua_conf_port_info;
typedef struct pjsua_media_transport
{
    pjmedia_sock_info	 skinfo;
    pjmedia_transport	*transport;
} pjsua_media_transport;
PJ_DECL(unsigned) pjsua_conf_get_max_ports(void);
PJ_DECL(unsigned) pjsua_conf_get_active_ports(void);
PJ_DECL(pj_status_t) pjsua_enum_conf_ports(pjsua_conf_port_id id[],
					   unsigned *count);
PJ_DECL(pj_status_t) pjsua_conf_get_port_info( pjsua_conf_port_id port_id,
					       pjsua_conf_port_info *info);
PJ_DECL(pj_status_t) pjsua_conf_add_port(pj_pool_t *pool,
					 pjmedia_port *port,
					 pjsua_conf_port_id *p_id);
PJ_DECL(pj_status_t) pjsua_conf_remove_port(pjsua_conf_port_id port_id);
PJ_DECL(pj_status_t) pjsua_conf_connect(pjsua_conf_port_id source,
					pjsua_conf_port_id sink);
PJ_DECL(pj_status_t) pjsua_conf_disconnect(pjsua_conf_port_id source,
					   pjsua_conf_port_id sink);
PJ_DECL(pj_status_t) pjsua_conf_adjust_tx_level(pjsua_conf_port_id slot,
						float level);
PJ_DECL(pj_status_t) pjsua_conf_adjust_rx_level(pjsua_conf_port_id slot,
						float level);
PJ_DECL(pj_status_t) pjsua_conf_get_signal_level(pjsua_conf_port_id slot,
						 unsigned *tx_level,
						 unsigned *rx_level);
PJ_DECL(pj_status_t) pjsua_player_create(const pj_str_t *filename,
					 unsigned options,
					 pjsua_player_id *p_id);
PJ_DECL(pj_status_t) pjsua_playlist_create(const pj_str_t file_names[],
					   unsigned file_count,
					   const pj_str_t *label,
					   unsigned options,
					   pjsua_player_id *p_id);
PJ_DECL(pjsua_conf_port_id) pjsua_player_get_conf_port(pjsua_player_id id);
PJ_DECL(pj_status_t) pjsua_player_get_port(pjsua_player_id id,
					   pjmedia_port **p_port);
PJ_DECL(pj_status_t) pjsua_player_set_pos(pjsua_player_id id,
					  pj_uint32_t samples);
PJ_DECL(pj_status_t) pjsua_player_destroy(pjsua_player_id id);
PJ_DECL(pj_status_t) pjsua_recorder_create(const pj_str_t *filename,
					   unsigned enc_type,
					   void *enc_param,
					   pj_ssize_t max_size,
					   unsigned options,
					   pjsua_recorder_id *p_id);
PJ_DECL(pjsua_conf_port_id) pjsua_recorder_get_conf_port(pjsua_recorder_id id);
PJ_DECL(pj_status_t) pjsua_recorder_get_port(pjsua_recorder_id id,
					     pjmedia_port **p_port);
PJ_DECL(pj_status_t) pjsua_recorder_destroy(pjsua_recorder_id id);
PJ_DECL(pj_status_t) pjsua_enum_aud_devs(pjmedia_aud_dev_info info[],
					 unsigned *count);
PJ_DECL(pj_status_t) pjsua_enum_snd_devs(pjmedia_snd_dev_info info[],
					 unsigned *count);
PJ_DECL(pj_status_t) pjsua_get_snd_dev(int *capture_dev,
				       int *playback_dev);
PJ_DECL(pj_status_t) pjsua_set_snd_dev(int capture_dev,
				       int playback_dev);
PJ_DECL(pj_status_t) pjsua_set_null_snd_dev(void);
PJ_DECL(pjmedia_port*) pjsua_set_no_snd_dev(void);
PJ_DECL(pj_status_t) pjsua_set_ec(unsigned tail_ms, unsigned options);
PJ_DECL(pj_status_t) pjsua_get_ec_tail(unsigned *p_tail_ms);
PJ_DECL(pj_bool_t) pjsua_snd_is_active(void);
PJ_DECL(pj_status_t) pjsua_snd_set_setting(pjmedia_aud_dev_cap cap,
					   const void *pval,
					   pj_bool_t keep);
PJ_DECL(pj_status_t) pjsua_snd_get_setting(pjmedia_aud_dev_cap cap,
					   void *pval);
PJ_DECL(pj_status_t) pjsua_enum_codecs( pjsua_codec_info id[],
				        unsigned *count );
PJ_DECL(pj_status_t) pjsua_codec_set_priority( const pj_str_t *codec_id,
					       pj_uint8_t priority );
PJ_DECL(pj_status_t) pjsua_codec_get_param( const pj_str_t *codec_id,
					    pjmedia_codec_param *param );
PJ_DECL(pj_status_t) pjsua_codec_set_param( const pj_str_t *codec_id,
					    const pjmedia_codec_param *param);
PJ_DECL(pj_status_t) 
pjsua_media_transports_create(const pjsua_transport_config *cfg);

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

#ifndef __PJMEDIA_TRANSPORT_ZRTP_H__
enum pjmedia_zrtp_use
{
    PJMEDIA_NO_ZRTP  = 1,
    PJMEDIA_CREATE_ZRTP  = 2
};
#endif
PJ_DECL(void) jzrtp_SASVerified();
