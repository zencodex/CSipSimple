########
# SILK #
########

LOCAL_PATH := $(call my-dir)/../../silk/


include $(CLEAR_VARS)
LOCAL_MODULE 	:= silk

LOCAL_C_INCLUDES += $(LOCAL_PATH)../../pjlib/include/ $(LOCAL_PATH)interface/

LOCAL_CFLAGS := $(MY_PJSIP_FLAGS)
PJLIB_SRC_DIR := src

LOCAL_SRC_FILES := $(PJLIB_SRC_DIR)/SKP_Silk_A2NLSF.c \
$(PJLIB_SRC_DIR)/SKP_Silk_allpass_int.c \
$(PJLIB_SRC_DIR)/SKP_Silk_ana_filt_bank_1.c \
$(PJLIB_SRC_DIR)/SKP_Silk_apply_sine_window.c \
$(PJLIB_SRC_DIR)/SKP_Silk_array_maxabs.c \
$(PJLIB_SRC_DIR)/SKP_Silk_autocorr.c \
$(PJLIB_SRC_DIR)/SKP_Silk_biquad_alt.c \
$(PJLIB_SRC_DIR)/SKP_Silk_biquad.c \
$(PJLIB_SRC_DIR)/SKP_Silk_burg_modified.c \
$(PJLIB_SRC_DIR)/SKP_Silk_bwexpander_32.c \
$(PJLIB_SRC_DIR)/SKP_Silk_bwexpander.c \
$(PJLIB_SRC_DIR)/SKP_Silk_CNG.c \
$(PJLIB_SRC_DIR)/SKP_Silk_code_signs.c \
$(PJLIB_SRC_DIR)/SKP_Silk_control_codec_FIX.c \
$(PJLIB_SRC_DIR)/SKP_Silk_corrMatrix_FIX.c \
$(PJLIB_SRC_DIR)/SKP_Silk_create_init_destroy.c \
$(PJLIB_SRC_DIR)/SKP_Silk_dec_API.c \
$(PJLIB_SRC_DIR)/SKP_Silk_decode_core.c \
$(PJLIB_SRC_DIR)/SKP_Silk_decode_frame.c \
$(PJLIB_SRC_DIR)/SKP_Silk_decode_parameters.c \
$(PJLIB_SRC_DIR)/SKP_Silk_decode_pitch.c \
$(PJLIB_SRC_DIR)/SKP_Silk_decode_pulses.c \
$(PJLIB_SRC_DIR)/SKP_Silk_decoder_set_fs.c \
$(PJLIB_SRC_DIR)/SKP_Silk_detect_SWB_input.c \
$(PJLIB_SRC_DIR)/SKP_Silk_enc_API.c \
$(PJLIB_SRC_DIR)/SKP_Silk_encode_frame_FIX.c \
$(PJLIB_SRC_DIR)/SKP_Silk_encode_parameters.c \
$(PJLIB_SRC_DIR)/SKP_Silk_encode_pulses.c \
$(PJLIB_SRC_DIR)/SKP_Silk_find_LPC_FIX.c \
$(PJLIB_SRC_DIR)/SKP_Silk_find_LTP_FIX.c \
$(PJLIB_SRC_DIR)/SKP_Silk_find_pitch_lags_FIX.c \
$(PJLIB_SRC_DIR)/SKP_Silk_find_pred_coefs_FIX.c \
$(PJLIB_SRC_DIR)/SKP_Silk_gain_quant.c \
$(PJLIB_SRC_DIR)/SKP_Silk_HP_variable_cutoff_FIX.c \
$(PJLIB_SRC_DIR)/SKP_Silk_init_encoder_FIX.c \
$(PJLIB_SRC_DIR)/SKP_Silk_inner_prod_aligned.c \
$(PJLIB_SRC_DIR)/SKP_Silk_interpolate.c \
$(PJLIB_SRC_DIR)/SKP_Silk_k2a.c \
$(PJLIB_SRC_DIR)/SKP_Silk_k2a_Q16.c \
$(PJLIB_SRC_DIR)/SKP_Silk_LBRR_reset.c \
$(PJLIB_SRC_DIR)/SKP_Silk_lin2log.c \
$(PJLIB_SRC_DIR)/SKP_Silk_log2lin.c \
$(PJLIB_SRC_DIR)/SKP_Silk_lowpass_int.c \
$(PJLIB_SRC_DIR)/SKP_Silk_lowpass_short.c \
$(PJLIB_SRC_DIR)/SKP_Silk_LPC_inv_pred_gain.c \
$(PJLIB_SRC_DIR)/SKP_Silk_LPC_stabilize.c \
$(PJLIB_SRC_DIR)/SKP_Silk_LPC_synthesis_filter.c \
$(PJLIB_SRC_DIR)/SKP_Silk_LPC_synthesis_order16.c \
$(PJLIB_SRC_DIR)/SKP_Silk_LP_variable_cutoff.c \
$(PJLIB_SRC_DIR)/SKP_Silk_LSF_cos_table.c \
$(PJLIB_SRC_DIR)/SKP_Silk_LTP_analysis_filter_FIX.c \
$(PJLIB_SRC_DIR)/SKP_Silk_LTP_scale_ctrl_FIX.c \
$(PJLIB_SRC_DIR)/SKP_Silk_MA.c \
$(PJLIB_SRC_DIR)/SKP_Silk_NLSF2A.c \
$(PJLIB_SRC_DIR)/SKP_Silk_NLSF2A_stable.c \
$(PJLIB_SRC_DIR)/SKP_Silk_NLSF_MSVQ_decode.c \
$(PJLIB_SRC_DIR)/SKP_Silk_NLSF_MSVQ_encode_FIX.c \
$(PJLIB_SRC_DIR)/SKP_Silk_NLSF_stabilize.c \
$(PJLIB_SRC_DIR)/SKP_Silk_NLSF_VQ_rate_distortion_FIX.c \
$(PJLIB_SRC_DIR)/SKP_Silk_NLSF_VQ_sum_error_FIX.c \
$(PJLIB_SRC_DIR)/SKP_Silk_NLSF_VQ_weights_laroia.c \
$(PJLIB_SRC_DIR)/SKP_Silk_noise_shape_analysis_FIX.c \
$(PJLIB_SRC_DIR)/SKP_Silk_NSQ.c \
$(PJLIB_SRC_DIR)/SKP_Silk_NSQ_del_dec.c \
$(PJLIB_SRC_DIR)/SKP_Silk_pitch_analysis_core.c \
$(PJLIB_SRC_DIR)/SKP_Silk_pitch_est_tables.c \
$(PJLIB_SRC_DIR)/SKP_Silk_PLC.c \
$(PJLIB_SRC_DIR)/SKP_Silk_prefilter_FIX.c \
$(PJLIB_SRC_DIR)/SKP_Silk_process_gains_FIX.c \
$(PJLIB_SRC_DIR)/SKP_Silk_process_NLSFs_FIX.c \
$(PJLIB_SRC_DIR)/SKP_Silk_quant_LTP_gains_FIX.c \
$(PJLIB_SRC_DIR)/SKP_Silk_range_coder.c \
$(PJLIB_SRC_DIR)/SKP_Silk_regularize_correlations_FIX.c \
$(PJLIB_SRC_DIR)/SKP_Silk_resampler.c \
$(PJLIB_SRC_DIR)/SKP_Silk_resampler_down2_3.c \
$(PJLIB_SRC_DIR)/SKP_Silk_resampler_down2.c \
$(PJLIB_SRC_DIR)/SKP_Silk_resampler_down3.c \
$(PJLIB_SRC_DIR)/SKP_Silk_resampler_private_AR2.c \
$(PJLIB_SRC_DIR)/SKP_Silk_resampler_private_ARMA4.c \
$(PJLIB_SRC_DIR)/SKP_Silk_resampler_private_copy.c \
$(PJLIB_SRC_DIR)/SKP_Silk_resampler_private_down4.c \
$(PJLIB_SRC_DIR)/SKP_Silk_resampler_private_down_FIR.c \
$(PJLIB_SRC_DIR)/SKP_Silk_resampler_private_IIR_FIR.c \
$(PJLIB_SRC_DIR)/SKP_Silk_resampler_private_up2_HQ.c \
$(PJLIB_SRC_DIR)/SKP_Silk_resampler_private_up4.c \
$(PJLIB_SRC_DIR)/SKP_Silk_resampler_rom.c \
$(PJLIB_SRC_DIR)/SKP_Silk_resampler_up2.c \
$(PJLIB_SRC_DIR)/SKP_Silk_residual_energy16_FIX.c \
$(PJLIB_SRC_DIR)/SKP_Silk_residual_energy_FIX.c \
$(PJLIB_SRC_DIR)/SKP_Silk_scale_copy_vector16.c \
$(PJLIB_SRC_DIR)/SKP_Silk_scale_vector.c \
$(PJLIB_SRC_DIR)/SKP_Silk_schur64.c \
$(PJLIB_SRC_DIR)/SKP_Silk_schur.c \
$(PJLIB_SRC_DIR)/SKP_Silk_shell_coder.c \
$(PJLIB_SRC_DIR)/SKP_Silk_sigm_Q15.c \
$(PJLIB_SRC_DIR)/SKP_Silk_solve_LS_FIX.c \
$(PJLIB_SRC_DIR)/SKP_Silk_sort.c \
$(PJLIB_SRC_DIR)/SKP_Silk_sum_sqr_shift.c \
$(PJLIB_SRC_DIR)/SKP_Silk_tables_gain.c \
$(PJLIB_SRC_DIR)/SKP_Silk_tables_LTP.c \
$(PJLIB_SRC_DIR)/SKP_Silk_tables_NLSF_CB0_10.c \
$(PJLIB_SRC_DIR)/SKP_Silk_tables_NLSF_CB0_16.c \
$(PJLIB_SRC_DIR)/SKP_Silk_tables_NLSF_CB1_10.c \
$(PJLIB_SRC_DIR)/SKP_Silk_tables_NLSF_CB1_16.c \
$(PJLIB_SRC_DIR)/SKP_Silk_tables_other.c \
$(PJLIB_SRC_DIR)/SKP_Silk_tables_pitch_lag.c \
$(PJLIB_SRC_DIR)/SKP_Silk_tables_pulses_per_block.c \
$(PJLIB_SRC_DIR)/SKP_Silk_tables_sign.c \
$(PJLIB_SRC_DIR)/SKP_Silk_tables_type_offset.c \
$(PJLIB_SRC_DIR)/SKP_Silk_VAD.c \
$(PJLIB_SRC_DIR)/SKP_Silk_VQ_nearest_neighbor_FIX.c \





include $(BUILD_STATIC_LIBRARY)