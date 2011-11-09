LOCAL_PATH := $(call my-dir)
TOP_LOCAL_PATH := $(call my-dir)/../

#Add target arm version
ifeq ($(TARGET_ARCH_ABI),armeabi)
MY_PJSIP_FLAGS := $(BASE_PJSIP_FLAGS) -DPJ_HAS_FLOATING_POINT=0
else
MY_PJSIP_FLAGS := $(BASE_PJSIP_FLAGS) -DPJ_HAS_FLOATING_POINT=1
endif


# Pjsip
include $(TOP_LOCAL_PATH)/pjlib/build/Android.mk
include $(TOP_LOCAL_PATH)/pjlib-util/build/Android.mk
include $(TOP_LOCAL_PATH)/pjnath/build/Android.mk
include $(TOP_LOCAL_PATH)/pjmedia/build/Android.mk
include $(TOP_LOCAL_PATH)/pjsip/build/Android.mk

# Third parties
include $(TOP_LOCAL_PATH)/third_party/build/resample/Android.mk
##Secure third parties

#TLS
ifeq ($(MY_USE_TLS),1)
include $(TOP_LOCAL_PATH)/third_party/openssl/Android.mk
include $(TOP_LOCAL_PATH)/third_party/build/zrtp4pj/Android.mk		
endif

#SRTP
include $(TOP_LOCAL_PATH)/third_party/build/srtp/Android.mk


##Media third parties
ifeq ($(MY_USE_ILBC),1)
	include $(TOP_LOCAL_PATH)/third_party/build/ilbc/Android.mk
endif
ifeq ($(MY_USE_GSM),1)
	include $(TOP_LOCAL_PATH)/third_party/build/gsm/Android.mk
endif
ifeq ($(MY_USE_SPEEX),1)
	include $(TOP_LOCAL_PATH)/third_party/build/speex/Android.mk
endif
ifeq ($(MY_USE_G729),1)
	include $(TOP_LOCAL_PATH)/third_party/build/g729/Android.mk
endif
ifeq ($(MY_USE_SILK),1)
	include $(TOP_LOCAL_PATH)/third_party/build/silk/Android.mk
endif
ifeq ($(MY_USE_CODEC2),1)
	include $(TOP_LOCAL_PATH)/third_party/build/codec2/Android.mk
endif

ifeq ($(MY_USE_G7221),1)
	include $(TOP_LOCAL_PATH)/third_party/build/g7221/Android.mk
endif

ifeq ($(MY_USE_WEBRTC),1)
#Commons
	include $(TOP_LOCAL_PATH)/third_party/webrtc/system_wrappers/source/Android.mk
	include $(TOP_LOCAL_PATH)/third_party/webrtc/modules/audio_processing/utility/Android.mk
	include $(TOP_LOCAL_PATH)/third_party/webrtc/common_audio/signal_processing_library/main/source/Android.mk
	include $(TOP_LOCAL_PATH)/third_party/webrtc/common_audio/vad/main/source/Android.mk
	include $(TOP_LOCAL_PATH)/third_party/webrtc/common_audio/resampler/main/source/Android.mk
	
#AEC
#ifeq ($(TARGET_ARCH_ABI),armeabi)
# AEC fixed 
	include $(TOP_LOCAL_PATH)/third_party/webrtc/modules/audio_processing/aecm/Android.mk
	include $(TOP_LOCAL_PATH)/third_party/webrtc/modules/audio_processing/ns/Android.mk
#else
# AEC floating
#	include $(TOP_LOCAL_PATH)/third_party/webrtc/modules/audio_processing/aec/Android.mk
#endif

#CODECS
	include $(TOP_LOCAL_PATH)/third_party/webrtc/modules/audio_coding/main/source/Android.mk
	include $(TOP_LOCAL_PATH)/third_party/webrtc/modules/audio_coding/neteq/Android.mk
	include $(TOP_LOCAL_PATH)/third_party/webrtc/modules/audio_coding/codecs/CNG/main/source/Android.mk
	include $(TOP_LOCAL_PATH)/third_party/webrtc/modules/audio_coding/codecs/G711/main/source/Android.mk
	include $(TOP_LOCAL_PATH)/third_party/webrtc/modules/audio_coding/codecs/ilbc/Android.mk
	#include $(TOP_LOCAL_PATH)/third_party/webrtc/modules/audio_coding/codecs/PCM16B/main/source/Android.mk
ifeq ($(TARGET_ARCH_ABI),armeabi)
#Fix codecs
	include $(TOP_LOCAL_PATH)/third_party/webrtc/modules/audio_coding/codecs/iSAC/fix/source/Android.mk
else
#Floating codecs
	include $(TOP_LOCAL_PATH)/third_party/webrtc/modules/audio_coding/codecs/iSAC/main/source/Android.mk
endif

# WARN ABOUT DUPLICATE CODEC !
ifeq ($(MY_USE_ILBC),1)
$(warning MY_USE_ILBC and MY_USE_WEBRTC will both produce iLBC codec)
endif

endif


# pjsip JNI
include $(TOP_LOCAL_PATH)/jni/build/Android.mk

