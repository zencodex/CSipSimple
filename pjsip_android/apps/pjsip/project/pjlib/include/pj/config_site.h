
//We distribute only for android so by default activate it
#ifndef PJ_ANDROID
#   define PJ_ANDROID   1
#endif

#define PJMEDIA_SDP_NEG_PREFER_REMOTE_CODEC_ORDER 0
#define PJ_HAS_IPV6 1

#define PJ_STUN_KEEP_ALIVE_SEC 90
#define PJ_ICE_SESS_KEEP_ALIVE_MIN 90

/* Fix google voice problem with RTP DTMF events */
#define PJMEDIA_RTP_PT_TELEPHONE_EVENTS          101
#define PJMEDIA_RTP_PT_TELEPHONE_EVENTS_STR      "101"

#if defined(PJ_ANDROID) && PJ_ANDROID!=0
//    #define PJ_LOG_USE_STACK_BUFFER             1
	//#define PJSUA_DEFAULT_AUDIO_FRAME_PTIME 30

	/* Optimizations */
//	#define PJMEDIA_HAS_ALAW_ULAW_TABLE 1
	#define PJ_ENABLE_EXTRA_CHECK   0

	//Conference switch board
	#define PJMEDIA_CONF_USE_SWITCH_BOARD 0

    #define PJ_OS_HAS_CHECK_STACK		0


	#define PJSIP_HAS_DIGEST_MJMD5_AUTH	1

	#define PJ_QOS_IMPLEMENTATION    PJ_QOS_BSD


	#define PJSIP_CHECK_VIA_SENT_BY 0

	/*
     * PJMEDIA settings
     */

    /* Disable non-Android audio devices */
    #define PJMEDIA_AUDIO_DEV_HAS_PORTAUDIO     0
    #define PJMEDIA_AUDIO_DEV_HAS_WMME          0
    #define PJMEDIA_AUDIO_DEV_HAS_ANDROID       1

    /* Select codecs to disable */
    #define PJMEDIA_HAS_L16_CODEC               0

    /* Fine tune Speex's default settings for best performance/quality */
    #define PJMEDIA_CODEC_SPEEX_DEFAULT_QUALITY 5

    /* If no floating point, no speex AEC and use the echo suppressor. */
    #define PJMEDIA_HAS_SPEEX_AEC		PJ_HAS_FLOATING_POINT
	/* If no floating point, no iLBC codec. */
	#define PJMEDIA_HAS_ILBC_CODEC PJ_HAS_FLOATING_POINT

    /* Previously, resampling is disabled due to performance reason and
     * this condition prevented some 'light' wideband codecs (e.g: G722.1)
     * to work along with narrowband codecs. Lately, some tests showed
     * that 16kHz <-> 8kHz resampling using libresample small filter was 
     * affordable on ARM9 222 MHz, so here we decided to enable resampling.
     * Note that it is important to make sure that libresample is created
     * using small filter. For example PJSUA_DEFAULT_CODEC_QUALITY must
     * be set to 3 or 4 so pjsua-lib will apply small filter resampling.
     */
    //#define PJMEDIA_RESAMPLE_IMP              PJMEDIA_RESAMPLE_NONE
    #define PJMEDIA_RESAMPLE_IMP                PJMEDIA_RESAMPLE_LIBRESAMPLE

    /* Use the lighter WSOLA implementation */
    #define PJMEDIA_WSOLA_IMP                   PJMEDIA_WSOLA_IMP_WSOLA_LITE

    /* We probably need more buffers especially if MDA audio backend 
     * is used, so increase the limit 
     */
  //  #define PJMEDIA_SOUND_BUFFER_COUNT          32

//	#define PJMEDIA_SND_DEFAULT_REC_LATENCY 150
//	#define PJMEDIA_SND_DEFAULT_PLAY_LATENCY 200

    /*
     * PJSUA settings.
     */

    /* Default codec quality, previously was set to 5, however it is now
     * set to 4 to make sure pjsua instantiates resampler with small filter.
     */
    #define PJSUA_DEFAULT_CODEC_QUALITY         4
	//We need hi availablitly so retry each minute if network fails -
	//all the more so as we unregister if network not available for us
	#define PJSUA_REG_RETRY_INTERVAL	60
	//#define PJSUA_DEFAULT_ILBC_MODE 			20


    /* Set maximum number of dialog/transaction/calls to minimum */
    #define PJSIP_MAX_TSX_COUNT 		31
    #define PJSIP_MAX_DIALOG_COUNT 		31
    #define PJSUA_MAX_CALLS			4

    /* Other pjsua settings */
    #define PJSUA_MAX_ACC			10
    #define PJSUA_MAX_PLAYERS			4
    #define PJSUA_MAX_RECORDERS			4
    #define PJSUA_MAX_CONF_PORTS		(PJSUA_MAX_CALLS+2*PJSUA_MAX_PLAYERS)
    #define PJSUA_MAX_BUDDIES			32




#endif
