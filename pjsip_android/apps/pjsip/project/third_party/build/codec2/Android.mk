##########
# CODEC2 #
##########

LOCAL_PATH := $(call my-dir)/../../codec2/


include $(CLEAR_VARS)
LOCAL_MODULE 	:= codec2

LOCAL_C_INCLUDES += $(LOCAL_PATH)../../pjlib/include/ $(LOCAL_PATH)src/

LOCAL_CFLAGS := $(MY_PJSIP_FLAGS)
PJLIB_SRC_DIR := src

LOCAL_SRC_FILES := $(PJLIB_SRC_DIR)/dump.c \
$(PJLIB_SRC_DIR)/lpc.c \
$(PJLIB_SRC_DIR)/nlp.c \
$(PJLIB_SRC_DIR)/postfilter.c \
$(PJLIB_SRC_DIR)/sine.c \
$(PJLIB_SRC_DIR)/codec2.c \
$(PJLIB_SRC_DIR)/fft.c \
$(PJLIB_SRC_DIR)/kiss_fft.c \
$(PJLIB_SRC_DIR)/interp.c \
$(PJLIB_SRC_DIR)/lsp.c \
$(PJLIB_SRC_DIR)/phase.c \
$(PJLIB_SRC_DIR)/quantise.c \
$(PJLIB_SRC_DIR)/pack.c \
$(PJLIB_SRC_DIR)/codebook.c \
$(PJLIB_SRC_DIR)/codebookd.c \
$(PJLIB_SRC_DIR)/codebookdvq.c




include $(BUILD_STATIC_LIBRARY)