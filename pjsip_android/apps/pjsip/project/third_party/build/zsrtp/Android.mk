########
# ZRTP #
########

LOCAL_PATH := $(call my-dir)/../../zsrtp/


include $(CLEAR_VARS)
LOCAL_MODULE 	:= zsrtp

LOCAL_C_INCLUDES += $(LOCAL_PATH) $(LOCAL_PATH)/include \
	$(LOCAL_PATH)/../../pjmedia/include/ $(LOCAL_PATH)/../../pjlib/include/ \
	$(LOCAL_PATH)/../openssl/include

LOCAL_CFLAGS := $(MY_PJSIP_FLAGS)
PJLIB_SRC_DIR := ./

#Do not include zrtp queue
#$(PJLIB_SRC_DIR)/ZrtpQueue.cpp 

LOCAL_SRC_FILES := $(PJLIB_SRC_DIR)/CryptoContext.cpp \
$(PJLIB_SRC_DIR)/ZsrtpCWrapper.cpp \
$(PJLIB_SRC_DIR)/crypto/openssl/AesSrtp.cpp \
$(PJLIB_SRC_DIR)/crypto/openssl/hmac.cpp \




include $(BUILD_STATIC_LIBRARY)
