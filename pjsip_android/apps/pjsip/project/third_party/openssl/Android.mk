LOCAL_PATH := $(call my-dir)

subdirs := $(addprefix $(LOCAL_PATH)/,$(addsuffix /Android.mk, \
		crypto \
		ssl \
	))

include $(subdirs)

# static library
# =====================================================

include $(CLEAR_VARS)
LOCAL_SRC_FILES:=
LOCAL_C_INCLUDES:=
ifeq ($(MY_USE_ZRTP),0)
LOCAL_WHOLE_STATIC_LIBRARIES += crypto ssl
else
#If we have zrtp only, cryto only is needed
LOCAL_WHOLE_STATIC_LIBRARIES += crypto
endif

LOCAL_MODULE:= openssl
include $(BUILD_STATIC_LIBRARY)
