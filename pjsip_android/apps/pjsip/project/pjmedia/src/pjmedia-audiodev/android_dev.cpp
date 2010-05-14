/* $Id: android_dev.c $ */
/**
 * This file is part of CSipSimple.
 *
 *  CSipSimple is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  CSipSimple is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with CSipSimple.  If not, see <http://www.gnu.org/licenses/>.
 */
/**
 * Since deeply inspired from portaudio dev port:
 * Copyright (C) 2009-2010 r3gis (http://www.r3gis.fr)
 * Copyright (C) 2008-2009 Teluu Inc. (http://www.teluu.com)
 * Copyright (C) 2003-2008 Benny Prijono <benny@prijono.org>
 */

//This file is a port for android devices
// It's deeply inspired from port audio

#include <pjmedia-audiodev/audiodev_imp.h>
#include <pj/assert.h>
#include <pj/log.h>
#include <pj/os.h>
#include <pj/string.h>
//#include <dlfcn.h>

#if PJMEDIA_AUDIO_DEV_HAS_ANDROID

#include <media/AudioRecord.h>
#include <media/AudioSystem.h>
#include <media/AudioTrack.h>

#if ANDROID_APP_PLATFORM==android-3 || ANDROID_APP_PLATFORM==android-4
#define ANDROID_VERSION 3
#else
#define ANDROID_VERSION 5
#endif

#if ANDROID_APP_PLATFORM==android-3
#define RECORDER_HACK 1
#else
#define RECORDER_HACK 0
#endif

#define THIS_FILE	"android_dev.cpp"
#define DRIVER_NAME	"ANDROID"

struct android_aud_factory
{
	pjmedia_aud_dev_factory base;
	pj_pool_factory *pf;
	pj_pool_t *pool;
};


/*
 * C compatible declaration of Android factory.
 */
PJ_BEGIN_DECL
PJ_DECL(pjmedia_aud_dev_factory*) pjmedia_android_factory(pj_pool_factory *pf);
PJ_END_DECL

/* 
 * Sound stream descriptor.
 * This struct may be used for both unidirectional or bidirectional sound
 * streams.
 */
struct android_aud_stream
{
	pjmedia_aud_stream base;

	pj_pool_t *pool;
	pj_str_t name;
	pjmedia_dir dir;
	pjmedia_aud_param param;

	int bytes_per_sample;
	pj_uint32_t samples_per_sec;
	unsigned samples_per_frame;
	int channel_count;

	android::AudioRecord *rec_strm;
	android::AudioTrack *play_strm;

	void *user_data;
	pjmedia_aud_rec_cb rec_cb;
	pjmedia_aud_play_cb play_cb;

	pj_timestamp play_timestamp;
	pj_timestamp rec_timestamp;
	pj_uint32_t underflow;
	pj_uint32_t overflow;

	pj_bool_t quit_flag;

	pj_bool_t rec_thread_exited;
	pj_bool_t rec_thread_initialized;
	pj_thread_desc rec_thread_desc;
	pj_thread_t *rec_thread;

	pj_bool_t play_thread_exited;
	pj_bool_t play_thread_initialized;
	pj_thread_desc play_thread_desc;
	pj_thread_t *play_thread;

	/* Callback does not return framesize as configured
	 * In this case, we need a buffer for the recorded samples.
	 */
	pj_int16_t *rec_buf;
	unsigned rec_buf_count;
	pj_int16_t *play_buf;
	unsigned play_buf_count;


	int saved_audio_mode;
	unsigned saved_audio_routing;

#if RECORDER_HACK==1
	pj_thread_t         *recorder_thread;
#endif


};

/* Factory prototypes */
static pj_status_t android_init(pjmedia_aud_dev_factory *f);
static pj_status_t android_destroy(pjmedia_aud_dev_factory *f);
static unsigned android_get_dev_count(pjmedia_aud_dev_factory *f);
static pj_status_t android_get_dev_info(pjmedia_aud_dev_factory *f,
		unsigned index,
		pjmedia_aud_dev_info *info);
static pj_status_t android_default_param(pjmedia_aud_dev_factory *f,
		unsigned index,
		pjmedia_aud_param *param);
static pj_status_t android_create_stream(pjmedia_aud_dev_factory *f,
		const pjmedia_aud_param *param,
		pjmedia_aud_rec_cb rec_cb,
		pjmedia_aud_play_cb play_cb,
		void *user_data,
		pjmedia_aud_stream **p_aud_strm);

/* Stream prototypes */
static pj_status_t strm_get_param(pjmedia_aud_stream *strm,
		pjmedia_aud_param *param);
static pj_status_t strm_get_cap(pjmedia_aud_stream *strm,
		pjmedia_aud_dev_cap cap,
		void *value);
static pj_status_t strm_set_cap(pjmedia_aud_stream *strm,
		pjmedia_aud_dev_cap cap,
		const void *value);
static pj_status_t strm_start(pjmedia_aud_stream *strm);
static pj_status_t strm_stop(pjmedia_aud_stream *strm);
static pj_status_t strm_destroy(pjmedia_aud_stream *strm);

static pjmedia_aud_dev_factory_op android_op =
{
	&android_init,
	&android_destroy,
	&android_get_dev_count,
	&android_get_dev_info,
	&android_default_param,
	&android_create_stream
};

static pjmedia_aud_stream_op android_strm_op =
{
	&strm_get_param,
	&strm_get_cap,
	&strm_set_cap,
	&strm_start,
	&strm_stop,
	&strm_destroy
};

#if RECORDER_HACK==0
static void AndroidRecorderCallback(int event, void* userData, void* info)
{


	if(!userData || !info){
		return;
	}

	if(event != android::AudioRecord::EVENT_MORE_DATA ){
		PJ_LOG(3, (THIS_FILE, "Record event ignored : %d", event));
		return;
	}

	struct android_aud_stream *stream = (struct android_aud_stream*) userData;
	android::AudioRecord::Buffer* uinfo = (android::AudioRecord::Buffer*) info;
	pj_status_t status = 0;
	unsigned nsamples;
	pj_int16_t *input;

	if (stream->quit_flag){
		goto on_break;
	}

	input = (pj_int16_t *) uinfo->raw;



	/* Known cases of callback's thread:
	 * - The thread may be changed in the middle of a session
	 *   it happens when plugging/unplugging headphone.
	 * - The same thread may be reused in consecutive sessions. The first
	 *   session will leave TLS set, but release the TLS data address,
	 *   so the second session must re-register the callback's thread.
	 */
	if (stream->rec_thread_initialized == 0 || !pj_thread_is_registered())
	{
		status = pj_thread_register("android_rec", stream->rec_thread_desc,
				&stream->rec_thread);
		stream->rec_thread_initialized = 1;
		PJ_LOG(3,(THIS_FILE, "Recorder thread started"));
		//TODO: Ensure android give the thread the highest priority
	}


	// Calculate number of samples we've got
	nsamples = uinfo->frameCount * stream->channel_count + stream->rec_buf_count;

	if (nsamples >= stream->samples_per_frame){
		/* If buffer is not empty, combine the buffer with the just incoming
		 * samples, then call put_frame.
		 */
		if (stream->rec_buf_count) {
			unsigned chunk_count = 0;
			pjmedia_frame frame;

			chunk_count = stream->samples_per_frame - stream->rec_buf_count;
			pjmedia_copy_samples(stream->rec_buf + stream->rec_buf_count,
					(pj_int16_t*)input, chunk_count);

			frame.type = PJMEDIA_FRAME_TYPE_AUDIO;
			frame.buf = (void*) stream->rec_buf;
			frame.size = stream->samples_per_frame * stream->bytes_per_sample;
			frame.timestamp.u64 = stream->rec_timestamp.u64;
			frame.bit_info = 0;

			status = (*stream->rec_cb)(stream->user_data, &frame);

			input = (pj_int16_t*) input + chunk_count;
			nsamples -= stream->samples_per_frame;
			stream->rec_buf_count = 0;
			stream->rec_timestamp.u64 += stream->samples_per_frame /
			stream->channel_count;
		}

		// Give all frames we have
		while (nsamples >= stream->samples_per_frame && status == 0) {
			pjmedia_frame frame;

			frame.type = PJMEDIA_FRAME_TYPE_AUDIO;
			frame.buf = (void*) input;
			frame.size = stream->samples_per_frame * stream->bytes_per_sample;
			frame.timestamp.u64 = stream->rec_timestamp.u64;
			frame.bit_info = 0;

			status = (*stream->rec_cb)(stream->user_data, &frame);

			input = (pj_int16_t*) input + stream->samples_per_frame;
			nsamples -= stream->samples_per_frame;
			stream->rec_timestamp.u64 += stream->samples_per_frame /
			stream->channel_count;
		}

		// Store the remaining samples into the buffer
		if (nsamples && status == 0) {
			stream->rec_buf_count = nsamples;
			pjmedia_copy_samples(stream->rec_buf, (pj_int16_t*)input,
					nsamples);
		}

	} else {
		// Not enough samples, let's just store them in the buffer
		pjmedia_copy_samples(stream->rec_buf + stream->rec_buf_count,
				(pj_int16_t*)input,
				uinfo->frameCount * stream->channel_count);
		stream->rec_buf_count += uinfo->frameCount * stream->channel_count;
	}
	if (status==0)
	return;

	on_break:
	PJ_LOG(3,(THIS_FILE, "Record thread stopped"));
	stream->rec_thread_exited = 1;
	return;
}
#else
static void AndroidRecorderCallback(int event, void* userData, void* info)
{
	if (event == android::AudioRecord::EVENT_MORE_DATA) {
	// set size to 0 to signal we're not using the callback to read more data
		android::AudioRecord::Buffer* pBuff = (android::AudioRecord::Buffer*)info;
		pBuff->size = 0;
	}
	//We have nothing to do with other events
}


static int PJ_THREAD_FUNC AndroidRecorderThread(void *userData){
	struct android_aud_stream *stream = (struct android_aud_stream*) userData;



	pj_status_t status = 0;
	ssize_t bufferSize = stream->samples_per_frame * stream->bytes_per_sample;

	pj_int16_t* input = new pj_int16_t[bufferSize]();


	if (stream->quit_flag){
		goto on_break;
	}

	//We have to loop even if we quit
	//If we quit, we want to eat all buffers from android
	while (/*!stream->quit_flag &&*/ status == PJ_SUCCESS) {

		pjmedia_frame frame;
		frame.type = PJMEDIA_FRAME_TYPE_AUDIO;
		frame.buf = (void*) input;
		frame.size = stream->samples_per_frame * stream->bytes_per_sample;
		frame.timestamp.u64 = stream->rec_timestamp.u64;
		frame.bit_info = 0;

		ssize_t readSize = stream->rec_strm->read(input, frame.size);
		if(readSize <= 0){
			break;
		}

		if(!stream->quit_flag){
			status = (*stream->rec_cb)(stream->user_data, &frame);
		}


	};

	delete input;


	on_break:
		PJ_LOG(3,(THIS_FILE, "Record thread stopped"));
		stream->rec_thread_exited = 1;
		return PJ_SUCCESS;
}

#endif

static void AndroidPlayerCallback( int event, void* userData, void* info)
{



	if(!userData || !info){
		return;
	}

	if(event != android::AudioTrack::EVENT_MORE_DATA ){
		PJ_LOG(3, (THIS_FILE, "Play event ignored : %d", event));
		return;
	}


	struct android_aud_stream *stream = (struct android_aud_stream*) userData;
	pj_status_t status = 0;

	android::AudioTrack::Buffer* uinfo = (android::AudioTrack::Buffer*) info;
	unsigned nsamples_req = uinfo->frameCount * stream->channel_count;

	pj_int16_t *output;

	if (stream->quit_flag)
	goto on_break;

	output = (pj_int16_t*) uinfo->raw;

	/* Known cases of callback's thread:
	 * - The thread may be changed in the middle of a session
	 * - The same thread may be reused in consecutive sessions. The first
	 *   session will leave TLS set, but release the TLS data address,
	 *   so the second session must re-register the callback's thread.
	 */
	if (stream->play_thread_initialized == 0 || !pj_thread_is_registered())
	{
		status = pj_thread_register("android", stream->play_thread_desc,
				&stream->play_thread);
		stream->play_thread_initialized = 1;
		PJ_LOG(3,(THIS_FILE, "Player thread started"));
		//TODO: Ensure android give the thread the highest priority
	}

	// Check if any buffered samples
	if (stream->play_buf_count) {
		// samples buffered >= requested by sound device
		if (stream->play_buf_count >= nsamples_req) {
			pjmedia_copy_samples((pj_int16_t*)output, stream->play_buf,
					nsamples_req);
			stream->play_buf_count -= nsamples_req;
			pjmedia_move_samples(stream->play_buf,
					stream->play_buf + nsamples_req,
					stream->play_buf_count);
			nsamples_req = 0;

			return;
		}

		// samples buffered < requested by sound device
		pjmedia_copy_samples((pj_int16_t*)output, stream->play_buf,
				stream->play_buf_count);
		nsamples_req -= stream->play_buf_count;
		output = (pj_int16_t*)output + stream->play_buf_count;
		stream->play_buf_count = 0;
	}

	// Fill output buffer as requested
	while (nsamples_req && status == 0) {
		if (nsamples_req >= stream->samples_per_frame) {
			pjmedia_frame frame;

			frame.type = PJMEDIA_FRAME_TYPE_AUDIO;
			frame.buf = output;
			frame.size = stream->samples_per_frame * stream->bytes_per_sample;
			frame.timestamp.u64 = stream->play_timestamp.u64;
			frame.bit_info = 0;

			status = (*stream->play_cb)(stream->user_data, &frame);
			if (status != PJ_SUCCESS)
			goto on_break;

			if (frame.type != PJMEDIA_FRAME_TYPE_AUDIO)
			pj_bzero(frame.buf, frame.size);

			nsamples_req -= stream->samples_per_frame;
			output = (pj_int16_t*)output + stream->samples_per_frame;
		} else {
			pjmedia_frame frame;

			frame.type = PJMEDIA_FRAME_TYPE_AUDIO;
			frame.buf = stream->play_buf;
			frame.size = stream->samples_per_frame * stream->bytes_per_sample;
			frame.timestamp.u64 = stream->play_timestamp.u64;
			frame.bit_info = 0;

			status = (*stream->play_cb)(stream->user_data, &frame);
			if (status != PJ_SUCCESS)
			goto on_break;

			if (frame.type != PJMEDIA_FRAME_TYPE_AUDIO)
			pj_bzero(frame.buf, frame.size);

			pjmedia_copy_samples((pj_int16_t*)output, stream->play_buf,
					nsamples_req);
			stream->play_buf_count = stream->samples_per_frame - nsamples_req;
			pjmedia_move_samples(stream->play_buf,
					stream->play_buf+nsamples_req,
					stream->play_buf_count);
			nsamples_req = 0;
		}

		stream->play_timestamp.u64 += stream->samples_per_frame /
		stream->channel_count;
	}

	if (status==0)
	return;

	on_break:
	PJ_LOG(3,(THIS_FILE, "Play thread stopped"));
	stream->play_thread_exited = 1;
	return;
}

/*
 * Init Android audio driver.
 */
pjmedia_aud_dev_factory* pjmedia_android_factory(pj_pool_factory *pf)
{
	struct android_aud_factory *f;
	pj_pool_t *pool;

	pool = pj_pool_create(pf, "android", 64, 64, NULL);
	f = PJ_POOL_ZALLOC_T(pool, struct android_aud_factory);
	f->pf = pf;
	f->pool = pool;
	f->base.op = &android_op;

	return &f->base;
}

/* API: Init factory */
static pj_status_t android_init(pjmedia_aud_dev_factory *f)
{
	int err;

	PJ_UNUSED_ARG(f);

	PJ_LOG(4,(THIS_FILE, "Android sound library initialized"));
	PJ_LOG(4,(THIS_FILE, "Sound device count=%d", android_get_dev_count(f)));

	return PJ_SUCCESS;
}

/* API: Destroy factory */
static pj_status_t android_destroy(pjmedia_aud_dev_factory *f)
{
	struct android_aud_factory *pa = (struct android_aud_factory*)f;
	pj_pool_t *pool;
	int err;

	PJ_LOG(4,(THIS_FILE, "Android sound library shutting down.."));

	pool = pa->pool;
	pa->pool = NULL;
	pj_pool_release(pool);

	return PJ_SUCCESS;
}

/* API: Get device count. */
static unsigned android_get_dev_count(pjmedia_aud_dev_factory *f)
{
	PJ_LOG(4,(THIS_FILE, "Get dev count"));
	int count = 1;
	PJ_UNUSED_ARG(f);
	return count < 0 ? 0 : count;
}

/* API: Get device info. */
static pj_status_t android_get_dev_info(pjmedia_aud_dev_factory *f,
		unsigned index,
		pjmedia_aud_dev_info *info)
{

	PJ_UNUSED_ARG(f);
	PJ_LOG(4,(THIS_FILE, "Get dev info"));

	pj_bzero(info, sizeof(*info));

	pj_ansi_strcpy(info->name, "Android Audio");
	info->default_samples_per_sec = 8000;
	info->caps = PJMEDIA_AUD_DEV_CAP_INPUT_VOLUME_SETTING |
				 PJMEDIA_AUD_DEV_CAP_OUTPUT_VOLUME_SETTING;
	info->input_count = 1;
	info->output_count = 1;

	return PJ_SUCCESS;
}

/* API: fill in with default parameter. */
static pj_status_t android_default_param(pjmedia_aud_dev_factory *f,
		unsigned index,
		pjmedia_aud_param *param)
{

	PJ_LOG(4,(THIS_FILE, "Default params"));
	pjmedia_aud_dev_info adi;
	pj_status_t status;

	PJ_UNUSED_ARG(f);

	status = android_get_dev_info(f, index, &adi);
	if (status != PJ_SUCCESS)
	return status;

	pj_bzero(param, sizeof(*param));
	if (adi.input_count && adi.output_count) {
		param->dir = PJMEDIA_DIR_CAPTURE_PLAYBACK;
		param->rec_id = index;
		param->play_id = index;
	} else if (adi.input_count) {
		param->dir = PJMEDIA_DIR_CAPTURE;
		param->rec_id = index;
		param->play_id = PJMEDIA_AUD_INVALID_DEV;
	} else if (adi.output_count) {
		param->dir = PJMEDIA_DIR_PLAYBACK;
		param->play_id = index;
		param->rec_id = PJMEDIA_AUD_INVALID_DEV;
	} else {
		return PJMEDIA_EAUD_INVDEV;
	}

	param->clock_rate = adi.default_samples_per_sec;
	param->channel_count = 1;
	param->samples_per_frame = adi.default_samples_per_sec * 20 / 1000;
	param->bits_per_sample = 16;
	param->flags = adi.caps;
	param->input_latency_ms = PJMEDIA_SND_DEFAULT_REC_LATENCY;
	param->output_latency_ms = PJMEDIA_SND_DEFAULT_PLAY_LATENCY;

	return PJ_SUCCESS;
}

/* API: create stream */
static pj_status_t android_create_stream(pjmedia_aud_dev_factory *f,
		const pjmedia_aud_param *param,
		pjmedia_aud_rec_cb rec_cb,
		pjmedia_aud_play_cb play_cb,
		void *user_data,
		pjmedia_aud_stream **p_aud_strm)
{

	PJ_LOG(4,(THIS_FILE, "Creating stream"));
	struct android_aud_factory *pa = (struct android_aud_factory*)f;
	pj_pool_t *pool;
	struct android_aud_stream *stream;
	int sampleFormat;

	PJ_ASSERT_RETURN(play_cb && rec_cb && p_aud_strm, PJ_EINVAL);


	// Only supports for mono channel for now
	PJ_ASSERT_RETURN(param->channel_count == 1, PJ_EINVAL);


	pool = pj_pool_create(pa->pf, "sndstream", 1024, 1024, NULL);
	if (!pool) {
		return PJ_ENOMEM;
	}

	stream = PJ_POOL_ZALLOC_T(pool, struct android_aud_stream);
	stream->pool = pool;
	pj_strdup2_with_null(pool, &stream->name, "Android stream");
	stream->dir = PJMEDIA_DIR_CAPTURE_PLAYBACK;
	stream->param = *param;
	stream->user_data = user_data;
	stream->samples_per_sec = param->clock_rate;
	stream->samples_per_frame = param->samples_per_frame;
	stream->bytes_per_sample = param->bits_per_sample / 8;
	stream->channel_count = param->channel_count;
	stream->rec_cb = rec_cb;
	stream->play_cb = play_cb;

	stream->rec_buf = (pj_int16_t*)pj_pool_alloc(pool,
			stream->samples_per_frame * stream->bytes_per_sample);
	stream->rec_buf_count = 0;

	stream->play_buf = (pj_int16_t*)pj_pool_alloc(pool,
			stream->samples_per_frame * stream->bytes_per_sample);
	stream->play_buf_count = 0;


	if (param->bits_per_sample == 8) {
		sampleFormat = android::AudioSystem::PCM_8_BIT;
	} else if (param->bits_per_sample == 16) {
		sampleFormat = android::AudioSystem::PCM_16_BIT;
	} else {
		return PJMEDIA_EAUD_SAMPFORMAT;
	}

	//Compute buffer size
	size_t inputBuffSize = 0;
	android::AudioSystem::getInputBufferSize(param->clock_rate,
			sampleFormat,
			param->channel_count, &inputBuffSize);
	// We use 2* size of input buffer for ping pong use of record buffer.
	inputBuffSize = 2 * inputBuffSize;


	int channel_count = param->channel_count;
#if ANDROID_VERSION==5
		channel_count = android::AudioSystem::CHANNEL_IN_MONO;
#endif


	if (stream->dir & PJMEDIA_DIR_CAPTURE) {
		stream->rec_strm = new android::AudioRecord();
		if(!stream->rec_strm) {
			PJ_LOG(2, (THIS_FILE, "fail to create audio record"));
			pj_pool_release(pool);
			return PJ_ENOMEM;
		}


		int inputSource;
#if ANDROID_VERSION==3
		inputSource = android::AudioRecord::MIC_INPUT;
#elif ANDROID_VERSION==5
		//inputSource = android::AUDIO_SOURCE_MIC;
		inputSource = 0;
		//PJ_LOG(3, (THIS_FILE, "Channel count is : %d", android::AudioSystem::isInputChannel(channel_count)));
		//inputBuffSize = inputBuffSize / 2;
#endif

		int create_result = stream->rec_strm->set(inputSource,
				param->clock_rate,
				sampleFormat,
				channel_count,
				inputBuffSize,
				0, //flags
				&AndroidRecorderCallback,
				(void *) stream,
				0,
				false);

		if(create_result != android::NO_ERROR){
			PJ_LOG(2, (THIS_FILE, "fail to check audio record : error code %d", create_result));
		}


		if(stream->rec_strm->initCheck() != android::NO_ERROR) {
			PJ_LOG(2, (THIS_FILE, "fail to check audio record : buffer size is : %d, error code : %d", inputBuffSize, stream->rec_strm->initCheck() ));
			pj_pool_release(pool);
			//TODO : more expressive error
			return PJ_ENOMEM;
		}
	}

	if (stream->dir & PJMEDIA_DIR_PLAYBACK ) {
		stream->play_strm = new android::AudioTrack();
		if(!stream->play_strm) {
			pj_pool_release(pool);
			return PJ_ENOMEM;
		}

		stream->play_strm->set(android::AudioSystem::VOICE_CALL,
//		stream->play_strm->set(android::AudioSystem::MUSIC,
				param->clock_rate, //this is sample rate in Hz (16000 Hz for example)
				sampleFormat,
				channel_count, //For now this is mono (we expect 1)
				inputBuffSize,
				0, //flags
				&AndroidPlayerCallback,
				(void *) stream,
				0,
				0,
				false);

		if(!stream->play_strm) {
			pj_pool_release(pool);
			return PJ_ENOMEM;
		}
	}

	//OK, done
	*p_aud_strm = &stream->base;
	(*p_aud_strm)->op = &android_strm_op;

	return PJ_SUCCESS;
}

/* API: Get stream parameters */
static pj_status_t strm_get_param(pjmedia_aud_stream *s,
		pjmedia_aud_param *pi)
{

	PJ_LOG(4,(THIS_FILE, "Get stream params"));
	struct android_aud_stream *strm = (struct android_aud_stream*)s;
	PJ_ASSERT_RETURN(strm && pi, PJ_EINVAL);
	pj_memcpy(pi, &strm->param, sizeof(*pi));

	return PJ_SUCCESS;
}

/* API: get capability */
static pj_status_t strm_get_cap(pjmedia_aud_stream *s,
		pjmedia_aud_dev_cap cap,
		void *pval)
{
	PJ_LOG(4,(THIS_FILE, "Get stream caps"));
	struct android_aud_stream *strm = (struct android_aud_stream*)s;

	pj_status_t status = PJ_ENOTSUP;

	PJ_ASSERT_RETURN(s && pval, PJ_EINVAL);

	switch (cap) {
		case PJMEDIA_AUD_DEV_CAP_INPUT_VOLUME_SETTING:
			status = PJ_SUCCESS;
			break;
		case PJMEDIA_AUD_DEV_CAP_OUTPUT_VOLUME_SETTING:
			status = PJ_SUCCESS;
			break;
		default:
		break;
	}

	return status;
}

/* API: set capability */
static pj_status_t strm_set_cap(pjmedia_aud_stream *strm,
		pjmedia_aud_dev_cap cap,
		const void *value)
{
	PJ_UNUSED_ARG(strm);
	PJ_UNUSED_ARG(cap);
	PJ_UNUSED_ARG(value);
	PJ_LOG(4,(THIS_FILE, "Set stream cap"));
	/* Nothing is supported in fact */
	return PJMEDIA_EAUD_INVCAP;
}

/* API: start stream. */
static pj_status_t strm_start(pjmedia_aud_stream *s)
{
	struct android_aud_stream *stream = (struct android_aud_stream*)s;

	PJ_LOG(4,(THIS_FILE, "Starting %s stream..", stream->name.ptr));
	stream->quit_flag = 0;

	if (stream->play_strm) {
		stream->play_strm->start();
		stream->play_thread_exited = 0;
	}

	if (stream->rec_strm) {
		stream->rec_strm->start();
		stream->rec_thread_exited = 0;
	}
#if RECORDER_HACK==1
	pj_status_t status = pj_thread_create(stream->pool, "android_recorder", &AndroidRecorderThread, stream, 0, 0,  &stream->recorder_thread);
	if (status != PJ_SUCCESS) {
		strm_destroy(&stream->base);
		return status;
	}
#endif

	PJ_LOG(4,(THIS_FILE, "Starting done"));

	return PJ_SUCCESS;
}

/* API: stop stream. */
static pj_status_t strm_stop(pjmedia_aud_stream *s)
{
	struct android_aud_stream *stream = (struct android_aud_stream*)s;
	int i;

	PJ_LOG(3,(THIS_FILE, "Will Stop stream, wait for all audio callback clean"));
	stream->quit_flag = 1;
	for (i=0; !stream->rec_thread_exited && i<100; ++i){
		pj_thread_sleep(20);
	}
	for (i=0; !stream->play_thread_exited && i<100; ++i){
		pj_thread_sleep(20);
	}

	//After all sleep for 0.1 seconds since android device can be slow
	pj_thread_sleep(1);

	PJ_LOG(3,(THIS_FILE, "Stopping stream.."));

	if (stream->rec_strm) {
		stream->rec_strm->stop();
	}

	if (stream->play_strm) {
		stream->play_strm->stop();
	}

	stream->play_thread_initialized = 0;
	stream->rec_thread_initialized = 0;

	PJ_LOG(4,(THIS_FILE, "Stopping Done"));

	return PJ_SUCCESS;
}

/* API: destroy stream. */
static pj_status_t strm_destroy(pjmedia_aud_stream *s)
{
	struct android_aud_stream *stream = (struct android_aud_stream*)s;
	int i = 0;

	stream->quit_flag = 1;
	for (i=0; !stream->rec_thread_exited && i<100; ++i) {
		pj_thread_sleep(1);
	}
	for (i=0; !stream->play_thread_exited && i<100; ++i) {
		pj_thread_sleep(1);
	}


	PJ_LOG(3,(THIS_FILE, "Closing %.*s",
					(int)stream->name.slen,
					stream->name.ptr));

	if (stream->play_strm) {
		stream->play_strm->stop();
		delete stream->play_strm;
		stream->play_strm = NULL;

	}

	if (stream->rec_strm) {
		stream->rec_strm->stop();
#if RECORDER_HACK==1
	    if (stream->recorder_thread){
			pj_thread_join(stream->recorder_thread);
			pj_thread_destroy(stream->recorder_thread);
			stream->recorder_thread = NULL;
	    }
#endif

		//FIXME this crash under 1.5 cupcake
		delete stream->rec_strm;
		stream->rec_strm = NULL;
	}

	pj_pool_release(stream->pool);
	PJ_LOG(3,(THIS_FILE, "Stream is destroyed"));

	return PJ_SUCCESS;
}

#endif	/* PJMEDIA_AUDIO_DEV_HAS_ANDROID */

