########
# ZRTP #
########

LOCAL_PATH := $(call my-dir)/../../zrtp/src


include $(CLEAR_VARS)
LOCAL_MODULE 	:= zrtp

LOCAL_C_INCLUDES += $(LOCAL_PATH)/../ $(LOCAL_PATH)/libzrtp $(LOCAL_PATH)/../../openssl/include

LOCAL_CFLAGS := $(MY_PJSIP_FLAGS)
PJLIB_SRC_DIR := ./

#Do not include zrtp queue
#$(PJLIB_SRC_DIR)/ZrtpQueue.cpp 

LOCAL_SRC_FILES := $(PJLIB_SRC_DIR)/ZIDFile.cpp \
$(PJLIB_SRC_DIR)/ZIDRecord.cpp \
$(PJLIB_SRC_DIR)/ZrtpCrc32.cpp \
$(PJLIB_SRC_DIR)/Base32.cpp \
$(PJLIB_SRC_DIR)/ZRtp.cpp \
$(PJLIB_SRC_DIR)/ZrtpCallbackWrapper.cpp \
$(PJLIB_SRC_DIR)/ZrtpCWrapper.cpp \
$(PJLIB_SRC_DIR)/ZrtpConfigure.cpp \
$(PJLIB_SRC_DIR)/ZrtpPacketClearAck.cpp \
$(PJLIB_SRC_DIR)/ZrtpPacketCommit.cpp \
$(PJLIB_SRC_DIR)/ZrtpPacketConf2Ack.cpp \
$(PJLIB_SRC_DIR)/ZrtpPacketConfirm.cpp \
$(PJLIB_SRC_DIR)/ZrtpPacketDHPart.cpp \
$(PJLIB_SRC_DIR)/ZrtpPacketErrorAck.cpp \
$(PJLIB_SRC_DIR)/ZrtpPacketError.cpp \
$(PJLIB_SRC_DIR)/ZrtpPacketGoClear.cpp \
$(PJLIB_SRC_DIR)/ZrtpPacketHelloAck.cpp \
$(PJLIB_SRC_DIR)/ZrtpPacketHello.cpp \
$(PJLIB_SRC_DIR)/ZrtpPacketPingAck.cpp \
$(PJLIB_SRC_DIR)/ZrtpPacketPing.cpp \
$(PJLIB_SRC_DIR)/ZrtpStateClass.cpp \
$(PJLIB_SRC_DIR)/ZrtpTextData.cpp \
$(PJLIB_SRC_DIR)/libzrtpcpp/crypto/openssl/hmac256.cpp \
$(PJLIB_SRC_DIR)/libzrtpcpp/crypto/openssl/hmac384.cpp \
$(PJLIB_SRC_DIR)/libzrtpcpp/crypto/openssl/sha256.cpp \
$(PJLIB_SRC_DIR)/libzrtpcpp/crypto/openssl/sha384.cpp \
$(PJLIB_SRC_DIR)/libzrtpcpp/crypto/openssl/AesCFB.cpp \
$(PJLIB_SRC_DIR)/libzrtpcpp/crypto/openssl/ZrtpDH.cpp \
$(PJLIB_SRC_DIR)/libzrtpcpp/crypto/openssl/InitializeOpenSSL.cpp





include $(BUILD_STATIC_LIBRARY)
