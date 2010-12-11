/*
 * jvm_wrapper.h
 *
 *  Created on: 14 mai 2010
 *      Author: r3gis3r
 */
#include <jni.h>

#ifndef JVM_WRAPPER_H_
#define JVM_WRAPPER_H_

extern JavaVM *android_jvm;

#define ATTACH_JVM(jni_env)  \
	JNIEnv *g_env;\
	int env_status = android_jvm->GetEnv((void **)&g_env, JNI_VERSION_1_6); \
	jint attachResult = android_jvm->AttachCurrentThread(&jni_env,NULL);

#define DETACH_JVM(jni_env)   if( env_status == JNI_EDETACHED ){ android_jvm->DetachCurrentThread(); }


#endif /* JVM_WRAPPER_H_ */
