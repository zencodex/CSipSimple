/*
 * android_dev.h
 *
 *  Created on: 11 déc. 2010
 *      Author: r3gis3r
 */

#ifndef ANDROID_DEV_H_
#define ANDROID_DEV_H_


#include <pjmedia-audiodev/audiodev_imp.h>
#include <pj/assert.h>
#include <pj/log.h>
#include <pj/os.h>
#include <pj/string.h>
#include <sys/resource.h>
#include <utils/threads.h>
#include <jni.h>
#include <jvm_wrapper.h>

/*
 * C compatible declaration of Android factory.
 */
PJ_BEGIN_DECL
PJ_DECL(pjmedia_aud_dev_factory*) pjmedia_android_factory(pj_pool_factory *pf);
PJ_END_DECL


#endif /* ANDROID_DEV_H_ */
