#ifndef __ZRTP_ANDROID_H__
#define __ZRTP_ANDROID_H__


#include <pjsua-lib/pjsua.h>
/**
 * ZRTP stuff
 */

pj_status_t on_zrtp_transport_created(pjmedia_transport *tp, pjsua_call_id call_id);

PJ_BEGIN_DECL

#ifndef __PJMEDIA_TRANSPORT_ZRTP_H__
 /**
 * ZRTP option.
 */
enum pjmedia_zrtp_use
{
    /** When this flag is specified, ZRTP will be disabled. */
    PJMEDIA_NO_ZRTP  = 1,

    /** When this flag is specified, PJSUA-LIB creates a ZRTP transport
     * call calls back the applicaion for further process if callback is
     * set.
     */
    PJMEDIA_CREATE_ZRTP  = 2

};

#endif

PJ_DECL(void) jzrtp_SASVerified();

PJ_END_DECL


#endif
