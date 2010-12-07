########
# G729 #
########

LOCAL_PATH := $(call my-dir)/../../g729/


include $(CLEAR_VARS)
LOCAL_MODULE 	:= g729

LOCAL_C_INCLUDES += $(LOCAL_PATH)../../pjlib/include/ $(LOCAL_PATH)include/

LOCAL_CFLAGS := $(MY_PJSIP_FLAGS)
PJLIB_SRC_DIR := src

LOCAL_SRC_FILES :=  $(PJLIB_SRC_DIR)/acelp_ca.c $(PJLIB_SRC_DIR)/de_acelp.c $(PJLIB_SRC_DIR)/filter.c \
					$(PJLIB_SRC_DIR)/lpcfunc.c $(PJLIB_SRC_DIR)/postfilt.c $(PJLIB_SRC_DIR)/qua_gain.c \
					$(PJLIB_SRC_DIR)/basic_op.c $(PJLIB_SRC_DIR)/dec_gain.c $(PJLIB_SRC_DIR)/g729a_decoder.c \
					$(PJLIB_SRC_DIR)/lspdec.c $(PJLIB_SRC_DIR)/post_pro.c $(PJLIB_SRC_DIR)/qua_lsp.c \
					$(PJLIB_SRC_DIR)/bits.c $(PJLIB_SRC_DIR)/dec_lag3.c $(PJLIB_SRC_DIR)/g729a_encoder.c \
					$(PJLIB_SRC_DIR)/lspgetq.c $(PJLIB_SRC_DIR)/p_parity.c $(PJLIB_SRC_DIR)/tab_ld8a.c \
					$(PJLIB_SRC_DIR)/cod_ld8a.c $(PJLIB_SRC_DIR)/dec_ld8a.c $(PJLIB_SRC_DIR)/gainpred.c \
					$(PJLIB_SRC_DIR)/oper_32b.c $(PJLIB_SRC_DIR)/pred_lt3.c $(PJLIB_SRC_DIR)/taming.c \
					$(PJLIB_SRC_DIR)/cor_func.c $(PJLIB_SRC_DIR)/dspfunc.c $(PJLIB_SRC_DIR)/lpc.c \
					$(PJLIB_SRC_DIR)/pitch_a.c $(PJLIB_SRC_DIR)/pre_proc.c $(PJLIB_SRC_DIR)/util.c \
					$(PJLIB_SRC_DIR)/round.c



include $(BUILD_STATIC_LIBRARY)