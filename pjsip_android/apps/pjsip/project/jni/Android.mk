
LOCAL_PATH := $(call my-dir)


############
# PJSIPJNI #
############
include $(CLEAR_VARS)
LOCAL_MODULE := pjsipjni

LOCAL_C_INCLUDES += $(LOCAL_PATH)/../pjsip/include $(LOCAL_PATH)/../pjlib-util/include/ \
			$(LOCAL_PATH)/../pjlib/include/ $(LOCAL_PATH)/../pjmedia/include \
			$(LOCAL_PATH)/../pjnath/include $(LOCAL_PATH)/
LOCAL_CFLAGS := $(MY_PJSIP_FLAGS)

LOCAL_SRC_FILES := pjsua_wrap.cpp
#LOCAL_ARM_MODE := arm

LOCAL_LDLIBS := -llog #-lmedia -lcutils -lutils
LOCAL_STATIC_LIBRARIES := pjsip pjmedia pjnath pjlib-util pjlib resample srtp speex ilbc gsm g729

include $(BUILD_SHARED_LIBRARY)

