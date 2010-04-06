
LOCAL_PATH := $(call my-dir)

#########
# PJLIB #
#########
include $(CLEAR_VARS)
LOCAL_MODULE    := pjlib

LOCAL_C_INCLUDES += $(LOCAL_PATH)/../pjlib/include/
LOCAL_CFLAGS := -DPJ_ANDROID=1
PJLIB_SRC_DIR := ../pjlib/src/pj

LOCAL_SRC_FILES := $(PJLIB_SRC_DIR)/addr_resolv_sock.c \
$(PJLIB_SRC_DIR)/file_access_unistd.c \
$(PJLIB_SRC_DIR)/file_io_ansi.c \
$(PJLIB_SRC_DIR)/guid_simple.c \
$(PJLIB_SRC_DIR)/log.c \
$(PJLIB_SRC_DIR)/log_writer_stdout.c \
$(PJLIB_SRC_DIR)/os_core_android.c \
$(PJLIB_SRC_DIR)/os_error_unix.c \
$(PJLIB_SRC_DIR)/os_time_common.c \
$(PJLIB_SRC_DIR)/os_time_unix.c \
$(PJLIB_SRC_DIR)/os_timestamp_common.c \
$(PJLIB_SRC_DIR)/os_timestamp_posix.c \
$(PJLIB_SRC_DIR)/pool_policy_malloc.c \
$(PJLIB_SRC_DIR)/sock_common.c \
$(PJLIB_SRC_DIR)/sock_qos_common.c \
$(PJLIB_SRC_DIR)/sock_qos_bsd.c \
$(PJLIB_SRC_DIR)/ssl_sock_common.c \
$(PJLIB_SRC_DIR)/ssl_sock_ossl.c \
$(PJLIB_SRC_DIR)/sock_bsd.c \
$(PJLIB_SRC_DIR)/sock_select.c \
$(PJLIB_SRC_DIR)/activesock.c \
$(PJLIB_SRC_DIR)/array.c \
$(PJLIB_SRC_DIR)/config.c \
$(PJLIB_SRC_DIR)/ctype.c \
$(PJLIB_SRC_DIR)/errno.c \
$(PJLIB_SRC_DIR)/except.c \
$(PJLIB_SRC_DIR)/fifobuf.c \
$(PJLIB_SRC_DIR)/guid.c \
$(PJLIB_SRC_DIR)/hash.c \
$(PJLIB_SRC_DIR)/ip_helper_generic.c \
$(PJLIB_SRC_DIR)/list.c \
$(PJLIB_SRC_DIR)/lock.c \
$(PJLIB_SRC_DIR)/pool.c \
$(PJLIB_SRC_DIR)/pool_buf.c \
$(PJLIB_SRC_DIR)/pool_caching.c \
$(PJLIB_SRC_DIR)/pool_dbg.c \
$(PJLIB_SRC_DIR)/rbtree.c \
$(PJLIB_SRC_DIR)/string.c \
$(PJLIB_SRC_DIR)/rand.c \
$(PJLIB_SRC_DIR)/timer.c \
$(PJLIB_SRC_DIR)/types.c \
$(PJLIB_SRC_DIR)/ioqueue_select.c

include $(BUILD_STATIC_LIBRARY)


##############
# PJLIB-UTIL #
##############
include $(CLEAR_VARS)
LOCAL_MODULE    := pjlib-util

LOCAL_C_INCLUDES += $(LOCAL_PATH)/../pjlib/include/ $(LOCAL_PATH)/../pjlib-util/include/
LOCAL_CFLAGS := -DPJ_ANDROID=1
PJLIB_SRC_DIR := ../pjlib-util/src/pjlib-util

LOCAL_SRC_FILES := $(PJLIB_SRC_DIR)/base64.c \
$(PJLIB_SRC_DIR)/crc32.c \
$(PJLIB_SRC_DIR)/errno.c \
$(PJLIB_SRC_DIR)/dns.c \
$(PJLIB_SRC_DIR)/dns_dump.c \
$(PJLIB_SRC_DIR)/dns_server.c \
$(PJLIB_SRC_DIR)/getopt.c \
$(PJLIB_SRC_DIR)/hmac_md5.c \
$(PJLIB_SRC_DIR)/hmac_sha1.c \
$(PJLIB_SRC_DIR)/md5.c \
$(PJLIB_SRC_DIR)/pcap.c \
$(PJLIB_SRC_DIR)/resolver.c \
$(PJLIB_SRC_DIR)/scanner.c \
$(PJLIB_SRC_DIR)/sha1.c \
$(PJLIB_SRC_DIR)/srv_resolver.c \
$(PJLIB_SRC_DIR)/string.c \
$(PJLIB_SRC_DIR)/stun_simple.c \
$(PJLIB_SRC_DIR)/stun_simple_client.c \
$(PJLIB_SRC_DIR)/xml.c

#LOCAL_STATIC_LIBRARIES := pjlib

include $(BUILD_STATIC_LIBRARY)


##########
# PJNATH #
##########
include $(CLEAR_VARS)
LOCAL_MODULE    := pjnath

LOCAL_C_INCLUDES += $(LOCAL_PATH)/../pjlib/include/ $(LOCAL_PATH)/../pjlib-util/include/ $(LOCAL_PATH)/../pjnath/include/
LOCAL_CFLAGS := -DPJ_ANDROID=1
PJLIB_SRC_DIR := ../pjnath/src/pjnath

LOCAL_SRC_FILES := $(PJLIB_SRC_DIR)/errno.c \
$(PJLIB_SRC_DIR)/ice_session.c \
$(PJLIB_SRC_DIR)/ice_strans.c \
$(PJLIB_SRC_DIR)/nat_detect.c \
$(PJLIB_SRC_DIR)/stun_auth.c \
$(PJLIB_SRC_DIR)/stun_msg.c \
$(PJLIB_SRC_DIR)/stun_msg_dump.c \
$(PJLIB_SRC_DIR)/stun_session.c \
$(PJLIB_SRC_DIR)/stun_sock.c \
$(PJLIB_SRC_DIR)/stun_transaction.c \
$(PJLIB_SRC_DIR)/turn_session.c \
$(PJLIB_SRC_DIR)/turn_sock.c 

#LOCAL_STATIC_LIBRARIES := pjlib pjlib-util

include $(BUILD_STATIC_LIBRARY)



###########
# PJMEDIA #
###########
include $(CLEAR_VARS)
LOCAL_MODULE    := pjmedia

LOCAL_C_INCLUDES += $(LOCAL_PATH)/../pjlib/include/ $(LOCAL_PATH)/../pjlib-util/include/ \
$(LOCAL_PATH)/../pjnath/include/ $(LOCAL_PATH)/../pjmedia/include/ $(LOCAL_PATH)/../ \
$(LOCAL_PATH)/../third_party/srtp/include $(LOCAL_PATH)/../third_party/srtp/include \
$(LOCAL_PATH)/../third_party/srtp/crypto/include $(LOCAL_PATH)/../third_party/build/srtp/ \
 $(LOCAL_PATH)/../third_party/build/speex/  $(LOCAL_PATH)/../third_party/speex/include

LOCAL_CFLAGS := -DPJ_ANDROID=1
PJLIB_SRC_DIR := ../pjmedia/src/pjmedia
PJMEDIADEV_SRC_DIR := ../pjmedia/src/pjmedia-audiodev
PJMEDIACODEC_SRC_DIR := ../pjmedia/src/pjmedia-codec

LOCAL_SRC_FILES := $(PJLIB_SRC_DIR)/alaw_ulaw.c $(PJLIB_SRC_DIR)/alaw_ulaw_table.c \
	$(PJLIB_SRC_DIR)/bidirectional.c \
	$(PJLIB_SRC_DIR)/clock_thread.c $(PJLIB_SRC_DIR)/codec.c \
	$(PJLIB_SRC_DIR)/conference.c $(PJLIB_SRC_DIR)/conf_switch.c $(PJLIB_SRC_DIR)/delaybuf.c $(PJLIB_SRC_DIR)/echo_common.c \
	$(PJLIB_SRC_DIR)/echo_port.c $(PJLIB_SRC_DIR)/echo_suppress.c $(PJLIB_SRC_DIR)/endpoint.c $(PJLIB_SRC_DIR)/errno.c \
	$(PJLIB_SRC_DIR)/g711.c $(PJLIB_SRC_DIR)/jbuf.c $(PJLIB_SRC_DIR)/master_port.c \
	$(PJLIB_SRC_DIR)/mem_capture.c $(PJLIB_SRC_DIR)/mem_player.c \
	$(PJLIB_SRC_DIR)/null_port.c $(PJLIB_SRC_DIR)/plc_common.c $(PJLIB_SRC_DIR)/port.c $(PJLIB_SRC_DIR)/splitcomb.c \
	$(PJLIB_SRC_DIR)/resample_resample.c $(PJLIB_SRC_DIR)/resample_libsamplerate.c \
	$(PJLIB_SRC_DIR)/resample_port.c $(PJLIB_SRC_DIR)/rtcp.c $(PJLIB_SRC_DIR)/rtcp_xr.c $(PJLIB_SRC_DIR)/rtp.c \
	$(PJLIB_SRC_DIR)/sdp.c $(PJLIB_SRC_DIR)/sdp_cmp.c $(PJLIB_SRC_DIR)/sdp_neg.c \
	$(PJLIB_SRC_DIR)/session.c $(PJLIB_SRC_DIR)/silencedet.c \
	$(PJLIB_SRC_DIR)/sound_port.c $(PJLIB_SRC_DIR)/stereo_port.c \
	$(PJLIB_SRC_DIR)/stream.c $(PJLIB_SRC_DIR)/tonegen.c $(PJLIB_SRC_DIR)/transport_adapter_sample.c \
	$(PJLIB_SRC_DIR)/transport_ice.c $(PJLIB_SRC_DIR)/transport_loop.c \
	$(PJLIB_SRC_DIR)/transport_srtp.c $(PJLIB_SRC_DIR)/transport_udp.c \
	$(PJLIB_SRC_DIR)/wav_player.c $(PJLIB_SRC_DIR)/wav_playlist.c $(PJLIB_SRC_DIR)/wav_writer.c $(PJLIB_SRC_DIR)/wave.c \
	$(PJLIB_SRC_DIR)/wsola.c \
	$(PJMEDIADEV_SRC_DIR)/audiodev.c $(PJMEDIADEV_SRC_DIR)/audiotest.c $(PJMEDIADEV_SRC_DIR)/errno.c \
    $(PJMEDIADEV_SRC_DIR)/android_dev.cpp \
    $(PJMEDIACODEC_SRC_DIR)/speex_codec.c \
	$(PJMEDIACODEC_SRC_DIR)/g722.c $(PJMEDIACODEC_SRC_DIR)/g722/g722_enc.c $(PJMEDIACODEC_SRC_DIR)/g722/g722_dec.c \
	$(PJMEDIACODEC_SRC_DIR)/gsm.c
#	$(PJMEDIACODEC_SRC_DIR)/ipp_codecs.c $(PJMEDIACODEC_SRC_DIR)/l16.c $(PJMEDIACODEC_SRC_DIR)/ilbc.c 


include $(BUILD_STATIC_LIBRARY)



#########
# PJSIP #
#########
include $(CLEAR_VARS)
LOCAL_MODULE    := pjsip

LOCAL_C_INCLUDES += $(LOCAL_PATH)/../pjsip/include $(LOCAL_PATH)/../pjlib/include/ \
			$(LOCAL_PATH)/../pjlib-util/include/ \
			$(LOCAL_PATH)/../pjnath/include $(LOCAL_PATH)/../pjmedia/include

LOCAL_CFLAGS := -DPJ_ANDROID=1
PJSIP_SRC_DIR := ../pjsip/src/pjsip
PJSIPUA_SRC_DIR := ../pjsip/src/pjsip-ua
PJSIPSIMPLE_SRC_DIR := ../pjsip/src/pjsip-simple
PJSUA_SRC_DIR := ../pjsip/src/pjsua-lib

LOCAL_SRC_FILES := $(PJSIP_SRC_DIR)/sip_config.c \
		$(PJSIP_SRC_DIR)/sip_errno.c $(PJSIP_SRC_DIR)/sip_msg.c $(PJSIP_SRC_DIR)/sip_parser.c \
		$(PJSIP_SRC_DIR)/sip_tel_uri.c $(PJSIP_SRC_DIR)/sip_uri.c \
		$(PJSIP_SRC_DIR)/sip_endpoint.c $(PJSIP_SRC_DIR)/sip_util.c $(PJSIP_SRC_DIR)/sip_util_proxy.c \
		$(PJSIP_SRC_DIR)/sip_resolve.c $(PJSIP_SRC_DIR)/sip_transport.c $(PJSIP_SRC_DIR)/sip_transport_loop.c \
		$(PJSIP_SRC_DIR)/sip_transport_udp.c $(PJSIP_SRC_DIR)/sip_transport_tcp.c \
		$(PJSIP_SRC_DIR)/sip_transport_tls_ossl.c $(PJSIP_SRC_DIR)/sip_auth_aka.c $(PJSIP_SRC_DIR)/sip_auth_client.c \
		$(PJSIP_SRC_DIR)/sip_auth_msg.c $(PJSIP_SRC_DIR)/sip_auth_parser.c \
		$(PJSIP_SRC_DIR)/sip_auth_server.c \
		$(PJSIP_SRC_DIR)/sip_transaction.c $(PJSIP_SRC_DIR)/sip_util_statefull.c \
		$(PJSIP_SRC_DIR)/sip_dialog.c $(PJSIP_SRC_DIR)/sip_ua_layer.c \
		$(PJSIPUA_SRC_DIR)/sip_inv.c $(PJSIPUA_SRC_DIR)/sip_reg.c \
		$(PJSIPUA_SRC_DIR)/sip_replaces.c $(PJSIPUA_SRC_DIR)/sip_xfer.c \
		$(PJSIPUA_SRC_DIR)/sip_100rel.c $(PJSIPUA_SRC_DIR)/sip_timer.c \
		$(PJSIPSIMPLE_SRC_DIR)/errno.c $(PJSIPSIMPLE_SRC_DIR)/evsub.c \
		$(PJSIPSIMPLE_SRC_DIR)/evsub_msg.c $(PJSIPSIMPLE_SRC_DIR)/iscomposing.c \
		$(PJSIPSIMPLE_SRC_DIR)/mwi.c \
		$(PJSIPSIMPLE_SRC_DIR)/pidf.c $(PJSIPSIMPLE_SRC_DIR)/presence.c \
		$(PJSIPSIMPLE_SRC_DIR)/presence_body.c $(PJSIPSIMPLE_SRC_DIR)/publishc.c \
		$(PJSIPSIMPLE_SRC_DIR)/rpid.c $(PJSIPSIMPLE_SRC_DIR)/xpidf.c \
		$(PJSUA_SRC_DIR)/pjsua_acc.c $(PJSUA_SRC_DIR)/pjsua_call.c $(PJSUA_SRC_DIR)/pjsua_core.c \
		$(PJSUA_SRC_DIR)/pjsua_im.c $(PJSUA_SRC_DIR)/pjsua_media.c $(PJSUA_SRC_DIR)/pjsua_pres.c



include $(BUILD_STATIC_LIBRARY)

############
# RESAMPLE #
############
include $(CLEAR_VARS)
LOCAL_MODULE    := resample

LOCAL_C_INCLUDES += $(LOCAL_PATH)/../pjlib/include/ $(LOCAL_PATH)/../third_party/resample/include \
		   $(LOCAL_PATH)/../third_party/build/resample/

LOCAL_CFLAGS := -DPJ_ANDROID=1
PJLIB_SRC_DIR := ../third_party/resample/src

LOCAL_SRC_FILES := $(PJLIB_SRC_DIR)/resamplesubs.c


include $(BUILD_STATIC_LIBRARY)

#########
# SPEEX #
#########
include $(CLEAR_VARS)
LOCAL_MODULE    := speex
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../third_party/build/speex $(LOCAL_PATH)/../third_party/speex/include \
		   $(LOCAL_PATH)/../third_party/speex/libspeex $(LOCAL_PATH)/../pjlib/include/
LOCAL_CFLAGS := -DPJ_ANDROID=1 -DHAVE_CONFIG_H=1
PJLIB_SRC_DIR := ../third_party/speex/libspeex

LOCAL_SRC_FILES := $(PJLIB_SRC_DIR)/bits.c $(PJLIB_SRC_DIR)/cb_search.c $(PJLIB_SRC_DIR)/exc_10_16_table.c  \
			$(PJLIB_SRC_DIR)/exc_10_32_table.c $(PJLIB_SRC_DIR)/exc_20_32_table.c \
			$(PJLIB_SRC_DIR)/exc_5_256_table.c $(PJLIB_SRC_DIR)/exc_5_64_table.c \
			$(PJLIB_SRC_DIR)/exc_8_128_table.c $(PJLIB_SRC_DIR)/fftwrap.c $(PJLIB_SRC_DIR)/filterbank.c \
			$(PJLIB_SRC_DIR)/filters.c $(PJLIB_SRC_DIR)/gain_table.c $(PJLIB_SRC_DIR)/gain_table_lbr.c \
			$(PJLIB_SRC_DIR)/hexc_10_32_table.c $(PJLIB_SRC_DIR)/hexc_table.c \
			$(PJLIB_SRC_DIR)/high_lsp_tables.c \
			$(PJLIB_SRC_DIR)/kiss_fft.c $(PJLIB_SRC_DIR)/kiss_fftr.c $(PJLIB_SRC_DIR)/lpc.c \
			$(PJLIB_SRC_DIR)/lsp.c $(PJLIB_SRC_DIR)/lsp_tables_nb.c $(PJLIB_SRC_DIR)/ltp.c \
			$(PJLIB_SRC_DIR)/mdf.c $(PJLIB_SRC_DIR)/modes.c $(PJLIB_SRC_DIR)/modes_wb.c \
			$(PJLIB_SRC_DIR)/nb_celp.c $(PJLIB_SRC_DIR)/preprocess.c \
			$(PJLIB_SRC_DIR)/quant_lsp.c $(PJLIB_SRC_DIR)/resample.c $(PJLIB_SRC_DIR)/sb_celp.c $(PJLIB_SRC_DIR)/smallft.c \
			$(PJLIB_SRC_DIR)/speex.c $(PJLIB_SRC_DIR)/speex_callbacks.c $(PJLIB_SRC_DIR)/speex_header.c \
			$(PJLIB_SRC_DIR)/stereo.c $(PJLIB_SRC_DIR)/vbr.c $(PJLIB_SRC_DIR)/vq.c $(PJLIB_SRC_DIR)/window.c

include $(BUILD_STATIC_LIBRARY)




#########
# ILBC  #
#########
include $(CLEAR_VARS)
LOCAL_MODULE    := ilbc

LOCAL_C_INCLUDES += $(LOCAL_PATH)/../pjlib/include/ $(LOCAL_PATH)/../third_party/ilbc/

LOCAL_CFLAGS := -DPJ_ANDROID=1
PJLIB_SRC_DIR := ../third_party/ilbc

LOCAL_SRC_FILES := $(PJLIB_SRC_DIR)/FrameClassify.c $(PJLIB_SRC_DIR)/LPCdecode.c $(PJLIB_SRC_DIR)/LPCencode.c \
		   $(PJLIB_SRC_DIR)/StateConstructW.c $(PJLIB_SRC_DIR)/StateSearchW.c $(PJLIB_SRC_DIR)/anaFilter.c \
		   $(PJLIB_SRC_DIR)/constants.c $(PJLIB_SRC_DIR)/createCB.c $(PJLIB_SRC_DIR)/doCPLC.c \
		   $(PJLIB_SRC_DIR)/enhancer.c $(PJLIB_SRC_DIR)/filter.c $(PJLIB_SRC_DIR)/gainquant.c \
		   $(PJLIB_SRC_DIR)/getCBvec.c $(PJLIB_SRC_DIR)/helpfun.c $(PJLIB_SRC_DIR)/hpInput.c \
		   $(PJLIB_SRC_DIR)/hpOutput.c $(PJLIB_SRC_DIR)/iCBConstruct.c $(PJLIB_SRC_DIR)/iCBSearch.c \
		   $(PJLIB_SRC_DIR)/iLBC_decode.c $(PJLIB_SRC_DIR)/iLBC_encode.c $(PJLIB_SRC_DIR)/lsf.c \
		   $(PJLIB_SRC_DIR)/packing.c $(PJLIB_SRC_DIR)/syntFilter.c
		   
		   
#include $(BUILD_STATIC_LIBRARY)

#######
# GSM #
#######
include $(CLEAR_VARS)
LOCAL_MODULE    := gsm

LOCAL_C_INCLUDES += $(LOCAL_PATH)/../pjlib/include/ $(LOCAL_PATH)/../third_party/gsm/inc \
			$(LOCAL_PATH)/../third_party/build/gsm/

LOCAL_CFLAGS := -DPJ_ANDROID=1
PJLIB_SRC_DIR := ../third_party/gsm/src

LOCAL_SRC_FILES := $(PJLIB_SRC_DIR)/add.c $(PJLIB_SRC_DIR)/code.c $(PJLIB_SRC_DIR)/decode.c \
                	$(PJLIB_SRC_DIR)/gsm_create.c $(PJLIB_SRC_DIR)/gsm_decode.c $(PJLIB_SRC_DIR)/gsm_destroy.c \
                	$(PJLIB_SRC_DIR)/gsm_encode.c $(PJLIB_SRC_DIR)/gsm_explode.c $(PJLIB_SRC_DIR)/gsm_implode.c \
                	$(PJLIB_SRC_DIR)/gsm_option.c $(PJLIB_SRC_DIR)/long_term.c \
                	$(PJLIB_SRC_DIR)/lpc.c $(PJLIB_SRC_DIR)/preprocess.c $(PJLIB_SRC_DIR)/rpe.c $(PJLIB_SRC_DIR)/short_term.c \
                	$(PJLIB_SRC_DIR)/table.c

include $(BUILD_STATIC_LIBRARY)


########
# SRTP #
########
include $(CLEAR_VARS)
LOCAL_MODULE    := srtp

LOCAL_C_INCLUDES += $(LOCAL_PATH)/../pjlib/include \
			$(LOCAL_PATH)/../third_party/srtp/crypto/include/ \
			$(LOCAL_PATH)/../third_party/srtp/include/ \
			$(LOCAL_PATH)/../third_party/build/srtp/

			

LOCAL_CFLAGS := -DPJ_ANDROID=1
PJLIB_SRC_DIR := ../third_party/srtp

LOCAL_SRC_FILES := $(PJLIB_SRC_DIR)/crypto/cipher/cipher.c $(PJLIB_SRC_DIR)/crypto/cipher/null_cipher.c      \
		$(PJLIB_SRC_DIR)/crypto/cipher/aes.c $(PJLIB_SRC_DIR)/crypto/cipher/aes_icm.c             \
		$(PJLIB_SRC_DIR)/crypto/cipher/aes_cbc.c \
		$(PJLIB_SRC_DIR)/crypto/hash/null_auth.c $(PJLIB_SRC_DIR)/crypto/hash/sha1.c \
         	$(PJLIB_SRC_DIR)/crypto/hash/hmac.c $(PJLIB_SRC_DIR)/crypto/hash/auth.c \
		$(PJLIB_SRC_DIR)/crypto/replay/rdb.c $(PJLIB_SRC_DIR)/crypto/replay/rdbx.c               \
		$(PJLIB_SRC_DIR)/crypto/replay/ut_sim.c \
		$(PJLIB_SRC_DIR)/crypto/math/datatypes.c $(PJLIB_SRC_DIR)/crypto/math/stat.c \
		$(PJLIB_SRC_DIR)/crypto/rng/rand_source.c $(PJLIB_SRC_DIR)/crypto/rng/prng.c \
		$(PJLIB_SRC_DIR)/crypto/rng/ctr_prng.c \
		$(PJLIB_SRC_DIR)/pjlib/srtp_err.c \
		$(PJLIB_SRC_DIR)/crypto/kernel/crypto_kernel.c  $(PJLIB_SRC_DIR)/crypto/kernel/alloc.c   \
		$(PJLIB_SRC_DIR)/crypto/kernel/key.c \
		$(PJLIB_SRC_DIR)/srtp/srtp.c 


include $(BUILD_STATIC_LIBRARY)


############
# PJSIPJNI #
############
include $(CLEAR_VARS)
LOCAL_MODULE := pjsipjni

LOCAL_C_INCLUDES += $(LOCAL_PATH)/../pjsip/include $(LOCAL_PATH)/../pjlib-util/include/ \
			$(LOCAL_PATH)/../pjlib/include/ $(LOCAL_PATH)/../pjmedia/include \
			$(LOCAL_PATH)/../pjnath/include $(LOCAL_PATH)/
LOCAL_CFLAGS := -DPJ_ANDROID=1

LOCAL_SRC_FILES := pjsua_wrap.cpp

LOCAL_LDLIBS := -llog -lmedia -lcutils -lutils
LOCAL_STATIC_LIBRARIES := pjsip pjmedia pjnath pjlib-util pjlib resample srtp speex gsm

include $(BUILD_SHARED_LIBRARY)

