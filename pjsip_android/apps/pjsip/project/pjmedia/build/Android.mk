###########
# PJMEDIA #
###########

LOCAL_PATH := $(call my-dir)/../
include $(CLEAR_VARS)

LOCAL_MODULE    := pjmedia

LOCAL_C_INCLUDES := $(LOCAL_PATH)../pjlib/include/ $(LOCAL_PATH)../pjlib-util/include/ \
	$(LOCAL_PATH)../pjnath/include/ $(LOCAL_PATH)include/ $(LOCAL_PATH)../ \
	$(LOCAL_PATH)../jni/ \
	$(LOCAL_PATH)../third_party/srtp/include $(LOCAL_PATH)../third_party/srtp/include \
	$(LOCAL_PATH)../third_party/srtp/crypto/include $(LOCAL_PATH)../third_party/build/srtp/ \
	$(LOCAL_PATH)../third_party/build/speex/  $(LOCAL_PATH)../third_party/speex/include \
	$(LOCAL_PATH)../third_party/g729/include

LOCAL_CFLAGS := $(MY_PJSIP_FLAGS)
PJLIB_SRC_DIR := src/pjmedia
PJMEDIADEV_SRC_DIR := src/pjmedia-audiodev
PJMEDIACODEC_SRC_DIR := src/pjmedia-codec

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
    $(PJMEDIADEV_SRC_DIR)/android_jni_dev.cpp 

ifeq ($(MY_USE_G729),1)
	LOCAL_SRC_FILES += $(PJMEDIACODEC_SRC_DIR)/g729.c
endif
ifeq ($(MY_USE_G722),1)
	LOCAL_SRC_FILES += $(PJMEDIACODEC_SRC_DIR)/g722.c $(PJMEDIACODEC_SRC_DIR)/g722/g722_enc.c $(PJMEDIACODEC_SRC_DIR)/g722/g722_dec.c
endif
ifeq ($(MY_USE_SPEEX),1)
	LOCAL_SRC_FILES += $(PJMEDIACODEC_SRC_DIR)/speex_codec.c 
endif
ifeq ($(MY_USE_ILBC),1)
	LOCAL_SRC_FILES += $(PJMEDIACODEC_SRC_DIR)/ilbc.c 
endif
ifeq ($(MY_USE_GSM),1)
	LOCAL_SRC_FILES += $(PJMEDIACODEC_SRC_DIR)/gsm.c 
endif


include $(BUILD_STATIC_LIBRARY)

