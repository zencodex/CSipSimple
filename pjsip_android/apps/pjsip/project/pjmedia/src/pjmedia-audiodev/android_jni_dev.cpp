/* $Id: android_dev.cpp $ */
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
#include <sys/resource.h>
#include <utils/threads.h>

#if PJMEDIA_AUDIO_DEV_HAS_ANDROID


#include <jni.h>
#include <jvm_wrapper.h>





#define THIS_FILE	"android_jni_dev.cpp"
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
	void *user_data;

	JavaVM* jvm;
	pj_bool_t quit_flag;

	//Record
	jobject	record;
	jclass 	record_class;
	pjmedia_aud_rec_cb rec_cb;
	pj_timestamp rec_timestamp;
	pj_bool_t rec_thread_exited;
	//pj_thread_desc rec_thread_desc;
	pj_thread_t *rec_thread;
	jbyte *rec_buf;

	//Track
	jobject	track;
	jclass 	track_class;
	pjmedia_aud_play_cb play_cb;
	pj_timestamp play_timestamp;
	pj_bool_t play_thread_exited;
	//pj_thread_desc play_thread_desc;
	pj_thread_t *play_thread;
	jbyte *play_buf;

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

static int PJ_THREAD_FUNC AndroidRecorderCallback(void* userData){
	struct android_aud_stream *stream = (struct android_aud_stream*) userData;
	JNIEnv *jni_env = 0;
	jmethodID read_method=0;
	int bytesRead;
	ssize_t frameSize;
	pj_status_t status = 0;
	jbyteArray inputBuffer;

	PJ_LOG(3,(THIS_FILE, "<< Enter recorder thread"));

	jint result = stream->jvm->AttachCurrentThread(&jni_env,NULL);
	if (result != 0) {
		return result;
	}
	//Get methods ids
	read_method = jni_env->GetMethodID(stream->record_class,"read", "([BII)I");
	if(read_method==0) {
		goto on_break;
	}

	frameSize = stream->samples_per_frame * stream->bytes_per_sample;


	//Create a buffer for frames read
	inputBuffer = jni_env->NewByteArray(frameSize);
	if (inputBuffer == 0) {
		PJ_LOG(2, (THIS_FILE, "Not able to allocate a buffer for input read process"));
		goto on_break;
	}

	//start recording
	setpriority(PRIO_PROCESS, 0, ANDROID_PRIORITY_URGENT_AUDIO);

	while ( /*!stream->quit_flag &&*/ (bytesRead = jni_env->CallIntMethod(stream->record, read_method,
			inputBuffer,
			0,
			frameSize))>0) {

		if(bytesRead == frameSize){

			jni_env->GetByteArrayRegion(inputBuffer, 0, frameSize, (jbyte*) stream->rec_buf );

			pjmedia_frame frame;

			frame.type = PJMEDIA_FRAME_TYPE_AUDIO;
			frame.size =  frameSize;
			frame.bit_info = 0;
			frame.buf = (void*) stream->rec_buf;
			frame.timestamp.u64 = stream->rec_timestamp.u64;

		//	PJ_LOG(3, (THIS_FILE, "New audio record frame to treat : %d <size : %d>", frame.type, frame.size));

			status = (*stream->rec_cb)(stream->user_data, &frame);
			if (status != PJ_SUCCESS){
				PJ_LOG(1, (THIS_FILE, "Error in record callback"));
				goto on_finish;
			}


			//Update for next step
			stream->rec_timestamp.u64 += stream->samples_per_frame / stream->channel_count;
		}else{
			PJ_LOG(1, (THIS_FILE, "Overrun..."));
		}
	};


	on_finish:
		jni_env->DeleteLocalRef(inputBuffer);

	on_break:
		stream->jvm->DetachCurrentThread();
		PJ_LOG(3,(THIS_FILE, ">> Record thread stopped"));
		stream->rec_thread_exited = 1;
		return 0;
}


static int PJ_THREAD_FUNC AndroidTrackCallback(void* userData){
	struct android_aud_stream *stream = (struct android_aud_stream*) userData;
	JNIEnv *jni_env = 0;
	jmethodID write_method=0;
	//jmethodID get_state_method=0;
	pj_status_t status = 0;
	//jint track_state;
	jbyteArray outputBuffer;
	ssize_t frameSize = stream->samples_per_frame * stream->bytes_per_sample;

	PJ_LOG(3,(THIS_FILE, "<< Enter player thread"));

	jint result = stream->jvm->AttachCurrentThread(&jni_env,NULL);
	if (result != 0) {
		return result;
	}

	//Get method ids
	write_method = jni_env->GetMethodID(stream->track_class,"write", "([BII)I");
	/*
	get_state_method =  jni_env->GetMethodID(stream->track_class,"getState", "()I");
	if(get_state_method==0) {
		goto on_break;
	}*/


	//start playing
	setpriority(PRIO_PROCESS, 0, ANDROID_PRIORITY_URGENT_AUDIO);

	/*
	track_state = jni_env->CallIntMethod(stream->track, get_state_method);
	PJ_LOG(3,(THIS_FILE, "Player state is now %d", track_state));
	if((int)track_state != 1){
		PJ_LOG(1, (THIS_FILE, "Bad player state !!! %d", track_state));
		goto on_break;
	}*/


	outputBuffer = jni_env->NewByteArray(frameSize);

	while ( !stream->quit_flag ) {

		pjmedia_frame frame;
		frame.type = PJMEDIA_FRAME_TYPE_AUDIO;
		frame.size = frameSize;
		frame.buf = (void *) stream->play_buf;
		frame.timestamp.u64 = stream->play_timestamp.u64;
		frame.bit_info = 0;

		//Fill frame from pj
		status = (*stream->play_cb)(stream->user_data, &frame);
		if (status != PJ_SUCCESS){
			goto on_finish;
		}

		if (frame.type != PJMEDIA_FRAME_TYPE_AUDIO){
			pj_bzero(frame.buf, frame.size);
			PJ_LOG(3, (THIS_FILE, "Hey, not an audio frame !!!"));
			continue;
		}

	//	PJ_LOG(3, (THIS_FILE, "New audio track frame to treat : %d <size : %d>", frame.type, frame.size));

		//Write to the java buffer
		jni_env->SetByteArrayRegion(outputBuffer, 0, frame.size, (jbyte*)frame.buf);

		//Write to the device output
		status = jni_env->CallIntMethod(stream->track, write_method,
				outputBuffer,
				0,
				frame.size);
		//PJ_LOG(3, (THIS_FILE, "Written"));
		if(status < 0){
			PJ_LOG(1, (THIS_FILE, "Error while writing %d ", status));
			goto on_finish;
		}else if(frameSize != status){
			PJ_LOG(3, (THIS_FILE, "Not everything written"));
		}

		stream->play_timestamp.u64 += stream->samples_per_frame / stream->channel_count;

	};

	on_finish:
		jni_env->DeleteLocalRef(outputBuffer);


	on_break:
		stream->jvm->DetachCurrentThread();
		PJ_LOG(3,(THIS_FILE, ">> Play thread stopped"));
		stream->play_thread_exited = 1;
		return 0;
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

	stream->rec_buf = (jbyte*)pj_pool_alloc(pool,
			stream->samples_per_frame * stream->bytes_per_sample);
	stream->rec_timestamp.u64 = 0;

	stream->play_buf = (jbyte*)pj_pool_alloc(pool,
			stream->samples_per_frame * stream->bytes_per_sample);
	stream->play_timestamp.u64 = 0;

	int inputBuffSize;
	int sampleFormat;


	//TODO : return codes should be better
	JNIEnv *jni_env = 0;
	jmethodID constructor_method=0;
	jmethodID get_min_buffer_size_method;

	stream->jvm = android_jvm;

	//Attach to jvm
	jint attachResult = stream->jvm->AttachCurrentThread(&jni_env,NULL);
	if (attachResult != 0) {
		PJ_LOG(1, (THIS_FILE, "Not able to attach the jvm"));
		pj_pool_release(pool);
		return PJ_ENOMEM;
	}

	if (param->bits_per_sample == 8) {
		sampleFormat = 3; //ENCODING_PCM_8BIT
	} else if (param->bits_per_sample == 16) {
		sampleFormat = 2; //ENCODING_PCM_16BIT
	} else {
		pj_pool_release(pool);
		return PJMEDIA_EAUD_SAMPFORMAT;
	}


	if (stream->dir & PJMEDIA_DIR_CAPTURE) {
		//Get pointer to the java class
		stream->record_class = (jclass)jni_env->NewGlobalRef(jni_env->FindClass("android/media/AudioRecord"));
		if (stream->record_class == 0) {
			PJ_LOG(2, (THIS_FILE, "Not able to find audio record class"));
			goto on_error;
		}

		PJ_LOG(3, (THIS_FILE, "We have the class"));

		//Get the min buffer function
		get_min_buffer_size_method = jni_env->GetStaticMethodID(stream->record_class, "getMinBufferSize", "(III)I");
		if (get_min_buffer_size_method == 0) {
			PJ_LOG(2, (THIS_FILE, "Not able to find audio record getMinBufferSize method"));
			goto on_error;
		}
		PJ_LOG(3, (THIS_FILE, "We have the buffer method"));
		//Call it
		inputBuffSize = jni_env->CallStaticIntMethod(stream->record_class, get_min_buffer_size_method,
				param->clock_rate, 2, sampleFormat);

		if(inputBuffSize <= 0){
			PJ_LOG(2, (THIS_FILE, "Min buffer size is not a valid value"));
			goto on_error;
		}
		PJ_LOG(3, (THIS_FILE, "Min buffer %d", inputBuffSize));



		//Get pointer to the constructor
		constructor_method = jni_env->GetMethodID(stream->record_class,"<init>", "(IIIII)V");
		if (constructor_method == 0) {
			PJ_LOG(2, (THIS_FILE, "Not able to find audio record class constructor"));
			goto on_error;
		}

		stream->record =  jni_env->NewObject(stream->record_class, constructor_method,
					1, // Mic input source
					param->clock_rate,
					2, // CHANNEL_CONFIGURATION_MONO
					sampleFormat,
					inputBuffSize);


		stream->record = jni_env->NewGlobalRef(stream->record);
		if (stream->record == 0) {
			PJ_LOG(1, (THIS_FILE, "Not able to instantiate record class"));
			goto on_error;
		}

		PJ_LOG(3, (THIS_FILE, "We have the instance done"));

	}


	if (stream->dir & PJMEDIA_DIR_PLAYBACK) {
		//Get pointer to the java class
		stream->track_class = (jclass)jni_env->NewGlobalRef(jni_env->FindClass("android/media/AudioTrack"));
		if (stream->track_class == 0) {
			PJ_LOG(2, (THIS_FILE, "Not able to find audio track class"));
			goto on_error;
		}

		PJ_LOG(3, (THIS_FILE, "We have the track class"));

		//Get the min buffer function
		get_min_buffer_size_method = jni_env->GetStaticMethodID(stream->track_class, "getMinBufferSize", "(III)I");
		if (get_min_buffer_size_method == 0) {
			PJ_LOG(2, (THIS_FILE, "Not able to find audio record getMinBufferSize method"));
			goto on_error;
		}
		PJ_LOG(3, (THIS_FILE, "We have the buffer method"));
		//Call it
		inputBuffSize = jni_env->CallStaticIntMethod(stream->track_class, get_min_buffer_size_method,
				param->clock_rate, 2, sampleFormat);

		if(inputBuffSize < 0){
			PJ_LOG(2, (THIS_FILE, "Min buffer size is not a valid value"));
			goto on_error;
		}
		PJ_LOG(3, (THIS_FILE, "Min buffer %d", inputBuffSize));

		//Get pointer to the constructor
		constructor_method = jni_env->GetMethodID(stream->track_class,"<init>", "(IIIIII)V");
		if (constructor_method == 0) {
			PJ_LOG(2, (THIS_FILE, "Not able to find audio track class constructor"));
			goto on_error;
		}

		stream->track =  jni_env->NewObject(stream->track_class, constructor_method,
					0, // VOICE_CALL
					param->clock_rate,
					2, // CHANNEL_CONFIGURATION_MONO
					sampleFormat,
					inputBuffSize /**2*/,
					1); // MODE_STREAM


		stream->track = jni_env->NewGlobalRef(stream->track);
		if (stream->track == 0) {
			PJ_LOG(1, (THIS_FILE, "Not able to instantiate track class"));
			goto on_error;
		}

		PJ_LOG(3, (THIS_FILE, "We have the instance done"));

	}

	//OK, done
	*p_aud_strm = &stream->base;
	(*p_aud_strm)->op = &android_strm_op;

	return PJ_SUCCESS;

on_error:
	pj_pool_release(pool);
	return PJ_ENOMEM;
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

	//TODO : init media routing here
	JNIEnv *jni_env = 0;

	jint attachResult = stream->jvm->AttachCurrentThread(&jni_env,NULL);
	if (attachResult != 0) {
		PJ_LOG(1, (THIS_FILE, "Not able to attach the jvm"));
		return PJ_ENOMEM;
	}


	pj_status_t status;
	if(stream->record){
		jmethodID record_method = jni_env->GetMethodID(stream->record_class,"startRecording", "()V");

		jni_env->CallVoidMethod(stream->record, record_method);
		PJ_LOG(3, (THIS_FILE, "Recorder is : %x ", stream->record));

		status = pj_thread_create(stream->pool, "android_recorder", &AndroidRecorderCallback, stream, 0, 0,  &stream->rec_thread);
		if (status != PJ_SUCCESS) {
			strm_destroy(&stream->base);
			return status;
		}
	}

	if(stream->track){
		jmethodID play_method = jni_env->GetMethodID(stream->track_class,"play", "()V");
		jni_env->CallVoidMethod(stream->track, play_method);

		status = pj_thread_create(stream->pool, "android_track", &AndroidTrackCallback, stream, 0, 0,  &stream->play_thread);
		if (status != PJ_SUCCESS) {
			strm_destroy(&stream->base);
			return status;
		}
	}



	PJ_LOG(4,(THIS_FILE, "Starting done"));

	return PJ_SUCCESS;
}

/* API: stop stream. */
static pj_status_t strm_stop(pjmedia_aud_stream *s)
{
	struct android_aud_stream *stream = (struct android_aud_stream*)s;
	int i;
	//We assume that all jni calls are safe ... that's acceptable
	if(stream->quit_flag == 0){
		PJ_LOG(3, (THIS_FILE, "Stopping stream"));
	}else{
		PJ_LOG(2, (THIS_FILE, "Already stopped.... nothing to do here"));
		return PJ_SUCCESS;
	}

	JNIEnv *jni_env = 0;
	jmethodID method_id;

	stream->quit_flag = 1;

	jint result = stream->jvm->AttachCurrentThread(&jni_env, NULL);
	if (result != 0) {
		PJ_LOG(1, (THIS_FILE, "Not able to attach the jvm"));
		return PJ_ENOMEM;
	}

	if(stream->record){
		//stop recording
		method_id = jni_env->GetMethodID(stream->record_class, "stop", "()V");
		jni_env->CallVoidMethod(stream->record, method_id);

		if(stream->rec_thread){
			pj_thread_join(stream->rec_thread);
			pj_thread_destroy(stream->rec_thread);
			stream->rec_thread = NULL;
		}
	}


	if(stream->track){
		method_id = jni_env->GetMethodID(stream->track_class,"flush", "()V");
		jni_env->CallVoidMethod(stream->track, method_id);
		method_id = jni_env->GetMethodID(stream->track_class, "stop", "()V");
		jni_env->CallVoidMethod(stream->track, method_id);

		if(stream->play_thread){
			pj_thread_join(stream->play_thread);
			pj_thread_destroy(stream->play_thread);
			stream->play_thread = NULL;
		}
	}


	PJ_LOG(4,(THIS_FILE, "Stopping Done"));

	stream->jvm->DetachCurrentThread();
	return PJ_SUCCESS;

}

/* API: destroy stream. */
static pj_status_t strm_destroy(pjmedia_aud_stream *s)
{

	PJ_LOG(4,(THIS_FILE, "Destroying stream"));

	//Stop the stream
	strm_stop(s);

	struct android_aud_stream *stream = (struct android_aud_stream*)s;
	JNIEnv *jni_env = 0;
	jmethodID release_method=0;


	jint result = stream->jvm->AttachCurrentThread(&jni_env,NULL);
	if (result != 0) {
		return result;
	}

	if(stream->record){
		//release recording - we assume the release method exists
		release_method = jni_env->GetMethodID(stream->record_class,"release", "()V");
		jni_env->CallVoidMethod(stream->record, release_method);

		jni_env->DeleteGlobalRef(stream->record);
		jni_env->DeleteGlobalRef(stream->record_class);
		stream->record = NULL;
		stream->record_class = NULL;
		PJ_LOG(3,(THIS_FILE, "---> Released recorder"));
	}else{
		PJ_LOG(2,(THIS_FILE, "Nothing to release !!! rec"));
	}

	if(stream->track){
		//release recording - we assume the release method exists
		release_method = jni_env->GetMethodID(stream->track_class,"release", "()V");
		jni_env->CallVoidMethod(stream->track, release_method);

		jni_env->DeleteGlobalRef(stream->track);
		jni_env->DeleteGlobalRef(stream->track_class);
		stream->track = NULL;
		stream->track_class = NULL;
		PJ_LOG(3,(THIS_FILE, "---> Released track"));
	}else{
		PJ_LOG(2,(THIS_FILE, "Nothing to release !!! track"));
	}

	pj_pool_release(stream->pool);
	PJ_LOG(3,(THIS_FILE, "Stream is destroyed"));

	stream->jvm->DetachCurrentThread();
	return PJ_SUCCESS;
}

#endif	/* PJMEDIA_AUDIO_DEV_HAS_ANDROID */

