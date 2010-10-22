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
#define SWIGJAVA
#define SWIG_DIRECTORS


#ifdef __cplusplus
/* SwigValueWrapper is described in swig.swg */
template<typename T> class SwigValueWrapper {
  struct SwigMovePointer {
    T *ptr;
    SwigMovePointer(T *p) : ptr(p) { }
    ~SwigMovePointer() { delete ptr; }
    SwigMovePointer& operator=(SwigMovePointer& rhs) { T* oldptr = ptr; ptr = 0; delete oldptr; ptr = rhs.ptr; rhs.ptr = 0; return *this; }
  } pointer;
  SwigValueWrapper& operator=(const SwigValueWrapper<T>& rhs);
  SwigValueWrapper(const SwigValueWrapper<T>& rhs);
public:
  SwigValueWrapper() : pointer(0) { }
  SwigValueWrapper& operator=(const T& t) { SwigMovePointer tmp(new T(t)); pointer = tmp; return *this; }
  operator T&() const { return *pointer.ptr; }
  T *operator&() { return pointer.ptr; }
};

template <typename T> T SwigValueInit() {
  return T();
}
#endif

/* -----------------------------------------------------------------------------
 *  This section contains generic SWIG labels for method/variable
 *  declarations/attributes, and other compiler dependent labels.
 * ----------------------------------------------------------------------------- */

/* template workaround for compilers that cannot correctly implement the C++ standard */
#ifndef SWIGTEMPLATEDISAMBIGUATOR
# if defined(__SUNPRO_CC) && (__SUNPRO_CC <= 0x560)
#  define SWIGTEMPLATEDISAMBIGUATOR template
# elif defined(__HP_aCC)
/* Needed even with `aCC -AA' when `aCC -V' reports HP ANSI C++ B3910B A.03.55 */
/* If we find a maximum version that requires this, the test would be __HP_aCC <= 35500 for A.03.55 */
#  define SWIGTEMPLATEDISAMBIGUATOR template
# else
#  define SWIGTEMPLATEDISAMBIGUATOR
# endif
#endif

/* inline attribute */
#ifndef SWIGINLINE
# if defined(__cplusplus) || (defined(__GNUC__) && !defined(__STRICT_ANSI__))
#   define SWIGINLINE inline
# else
#   define SWIGINLINE
# endif
#endif

/* attribute recognised by some compilers to avoid 'unused' warnings */
#ifndef SWIGUNUSED
# if defined(__GNUC__)
#   if !(defined(__cplusplus)) || (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4))
#     define SWIGUNUSED __attribute__ ((__unused__)) 
#   else
#     define SWIGUNUSED
#   endif
# elif defined(__ICC)
#   define SWIGUNUSED __attribute__ ((__unused__)) 
# else
#   define SWIGUNUSED 
# endif
#endif

#ifndef SWIG_MSC_UNSUPPRESS_4505
# if defined(_MSC_VER)
#   pragma warning(disable : 4505) /* unreferenced local function has been removed */
# endif 
#endif

#ifndef SWIGUNUSEDPARM
# ifdef __cplusplus
#   define SWIGUNUSEDPARM(p)
# else
#   define SWIGUNUSEDPARM(p) p SWIGUNUSED 
# endif
#endif

/* internal SWIG method */
#ifndef SWIGINTERN
# define SWIGINTERN static SWIGUNUSED
#endif

/* internal inline SWIG method */
#ifndef SWIGINTERNINLINE
# define SWIGINTERNINLINE SWIGINTERN SWIGINLINE
#endif

/* exporting methods */
#if (__GNUC__ >= 4) || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4)
#  ifndef GCC_HASCLASSVISIBILITY
#    define GCC_HASCLASSVISIBILITY
#  endif
#endif

#ifndef SWIGEXPORT
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   if defined(STATIC_LINKED)
#     define SWIGEXPORT
#   else
#     define SWIGEXPORT __declspec(dllexport)
#   endif
# else
#   if defined(__GNUC__) && defined(GCC_HASCLASSVISIBILITY)
#     define SWIGEXPORT __attribute__ ((visibility("default")))
#   else
#     define SWIGEXPORT
#   endif
# endif
#endif

/* calling conventions for Windows */
#ifndef SWIGSTDCALL
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   define SWIGSTDCALL __stdcall
# else
#   define SWIGSTDCALL
# endif 
#endif

/* Deal with Microsoft's attempt at deprecating C standard runtime functions */
#if !defined(SWIG_NO_CRT_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_CRT_SECURE_NO_DEPRECATE)
# define _CRT_SECURE_NO_DEPRECATE
#endif

/* Deal with Microsoft's attempt at deprecating methods in the standard C++ library */
#if !defined(SWIG_NO_SCL_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_SCL_SECURE_NO_DEPRECATE)
# define _SCL_SECURE_NO_DEPRECATE
#endif



/* Fix for jlong on some versions of gcc on Windows */
#if defined(__GNUC__) && !defined(__INTEL_COMPILER)
  typedef long long __int64;
#endif

/* Fix for jlong on 64-bit x86 Solaris */
#if defined(__x86_64)
# ifdef _LP64
#   undef _LP64
# endif
#endif

#include <jni.h>
#include <stdlib.h>
#include <string.h>


/* Support for throwing Java exceptions */
typedef enum {
  SWIG_JavaOutOfMemoryError = 1, 
  SWIG_JavaIOException, 
  SWIG_JavaRuntimeException, 
  SWIG_JavaIndexOutOfBoundsException,
  SWIG_JavaArithmeticException,
  SWIG_JavaIllegalArgumentException,
  SWIG_JavaNullPointerException,
  SWIG_JavaDirectorPureVirtual,
  SWIG_JavaUnknownError
} SWIG_JavaExceptionCodes;

typedef struct {
  SWIG_JavaExceptionCodes code;
  const char *java_exception;
} SWIG_JavaExceptions_t;


static void SWIGUNUSED SWIG_JavaThrowException(JNIEnv *jenv, SWIG_JavaExceptionCodes code, const char *msg) {
  jclass excep;
  static const SWIG_JavaExceptions_t java_exceptions[] = {
    { SWIG_JavaOutOfMemoryError, "java/lang/OutOfMemoryError" },
    { SWIG_JavaIOException, "java/io/IOException" },
    { SWIG_JavaRuntimeException, "java/lang/RuntimeException" },
    { SWIG_JavaIndexOutOfBoundsException, "java/lang/IndexOutOfBoundsException" },
    { SWIG_JavaArithmeticException, "java/lang/ArithmeticException" },
    { SWIG_JavaIllegalArgumentException, "java/lang/IllegalArgumentException" },
    { SWIG_JavaNullPointerException, "java/lang/NullPointerException" },
    { SWIG_JavaDirectorPureVirtual, "java/lang/RuntimeException" },
    { SWIG_JavaUnknownError,  "java/lang/UnknownError" },
    { (SWIG_JavaExceptionCodes)0,  "java/lang/UnknownError" }
  };
  const SWIG_JavaExceptions_t *except_ptr = java_exceptions;

  while (except_ptr->code != code && except_ptr->code)
    except_ptr++;

  jenv->ExceptionClear();
  excep = jenv->FindClass(except_ptr->java_exception);
  if (excep)
    jenv->ThrowNew(excep, msg);
}


/* Contract support */

#define SWIG_contract_assert(nullreturn, expr, msg) if (!(expr)) {SWIG_JavaThrowException(jenv, SWIG_JavaIllegalArgumentException, msg); return nullreturn; } else

/* -----------------------------------------------------------------------------
 * director.swg
 *
 * This file contains support for director classes that proxy
 * method calls from C++ to Java extensions.
 * ----------------------------------------------------------------------------- */

#ifdef __cplusplus

#if defined(DEBUG_DIRECTOR_OWNED)
#include <iostream>
#endif

namespace Swig {
  /* Java object wrapper */
  class JObjectWrapper {
  public:
    JObjectWrapper() : jthis_(NULL), weak_global_(true) {
    }

    ~JObjectWrapper() {
      jthis_ = NULL;
      weak_global_ = true;
    }

    bool set(JNIEnv *jenv, jobject jobj, bool mem_own, bool weak_global) {
      if (!jthis_) {
        weak_global_ = weak_global;
        if (jobj)
          jthis_ = ((weak_global_ || !mem_own) ? jenv->NewWeakGlobalRef(jobj) : jenv->NewGlobalRef(jobj));
#if defined(DEBUG_DIRECTOR_OWNED)
        std::cout << "JObjectWrapper::set(" << jobj << ", " << (weak_global ? "weak_global" : "global_ref") << ") -> " << jthis_ << std::endl;
#endif
        return true;
      } else {
#if defined(DEBUG_DIRECTOR_OWNED)
        std::cout << "JObjectWrapper::set(" << jobj << ", " << (weak_global ? "weak_global" : "global_ref") << ") -> already set" << std::endl;
#endif
        return false;
      }
    }

    jobject get(JNIEnv *jenv) const {
#if defined(DEBUG_DIRECTOR_OWNED)
      std::cout << "JObjectWrapper::get(";
      if (jthis_)
        std::cout << jthis_;
      else
        std::cout << "null";
      std::cout << ") -> return new local ref" << std::endl;
#endif
      return (jthis_ ? jenv->NewLocalRef(jthis_) : jthis_);
    }

    void release(JNIEnv *jenv) {
#if defined(DEBUG_DIRECTOR_OWNED)
      std::cout << "JObjectWrapper::release(" << jthis_ << "): " << (weak_global_ ? "weak global ref" : "global ref") << std::endl;
#endif
      if (jthis_) {
        if (weak_global_) {
          if (jenv->IsSameObject(jthis_, NULL) == JNI_FALSE)
            jenv->DeleteWeakGlobalRef((jweak)jthis_);
        } else
          jenv->DeleteGlobalRef(jthis_);
      }

      jthis_ = NULL;
      weak_global_ = true;
    }

    jobject peek() {
      return jthis_;
    }

    /* Java proxy releases ownership of C++ object, C++ object is now
       responsible for destruction (creates NewGlobalRef to pin Java
       proxy) */
    void java_change_ownership(JNIEnv *jenv, jobject jself, bool take_or_release) {
      if (take_or_release) {  /* Java takes ownership of C++ object's lifetime. */
        if (!weak_global_) {
          jenv->DeleteGlobalRef(jthis_);
          jthis_ = jenv->NewWeakGlobalRef(jself);
          weak_global_ = true;
        }
      } else { /* Java releases ownership of C++ object's lifetime */
        if (weak_global_) {
          jenv->DeleteWeakGlobalRef((jweak)jthis_);
          jthis_ = jenv->NewGlobalRef(jself);
          weak_global_ = false;
        }
      }
    }

  private:
    /* pointer to Java object */
    jobject jthis_;
    /* Local or global reference flag */
    bool weak_global_;
  };

  /* director base class */
  class Director {
    /* pointer to Java virtual machine */
    JavaVM *swig_jvm_;

  protected:
#if defined (_MSC_VER) && (_MSC_VER<1300)
    class JNIEnvWrapper;
    friend class JNIEnvWrapper;
#endif
    /* Utility class for managing the JNI environment */
    class JNIEnvWrapper {
      const Director *director_;
      JNIEnv *jenv_;
      int env_status;
      JNIEnv *g_env;
    public:
      JNIEnvWrapper(const Director *director) : director_(director), jenv_(0) {
    	env_status = director_->swig_jvm_->GetEnv( (void **) &g_env, JNI_VERSION_1_6);
#if defined(SWIG_JAVA_ATTACH_CURRENT_THREAD_AS_DAEMON)
        // Attach a daemon thread to the JVM. Useful when the JVM should not wait for
        // the thread to exit upon shutdown. Only for jdk-1.4 and later.
        director_->swig_jvm_->AttachCurrentThreadAsDaemon( &jenv_, NULL);
#else
        director_->swig_jvm_->AttachCurrentThread( &jenv_, NULL);
#endif
      }
      ~JNIEnvWrapper() {
#if !defined(SWIG_JAVA_NO_DETACH_CURRENT_THREAD)
        // Some JVMs, eg jdk-1.4.2 and lower on Solaris have a bug and crash with the DetachCurrentThread call.
        // However, without this call, the JVM hangs on exit when the thread was not created by the JVM and creates a memory leak.

    	 if( env_status == JNI_EDETACHED ){
			  director_->swig_jvm_->DetachCurrentThread();
    	 }

#endif
      }
      JNIEnv *getJNIEnv() const {
        return jenv_;
      }
    };

    /* Java object wrapper */
    JObjectWrapper swig_self_;

    /* Disconnect director from Java object */
    void swig_disconnect_director_self(const char *disconn_method) {
      JNIEnvWrapper jnienv(this) ;
      JNIEnv *jenv = jnienv.getJNIEnv() ;
      jobject jobj = swig_self_.peek();
#if defined(DEBUG_DIRECTOR_OWNED)
      std::cout << "Swig::Director::disconnect_director_self(" << jobj << ")" << std::endl;
#endif
      if (jobj && jenv->IsSameObject(jobj, NULL) == JNI_FALSE) {
        jmethodID disconn_meth = jenv->GetMethodID(jenv->GetObjectClass(jobj), disconn_method, "()V");
        if (disconn_meth) {
#if defined(DEBUG_DIRECTOR_OWNED)
          std::cout << "Swig::Director::disconnect_director_self upcall to " << disconn_method << std::endl;
#endif
          jenv->CallVoidMethod(jobj, disconn_meth);
        }
      }
    }

  public:
    Director(JNIEnv *jenv) : swig_jvm_((JavaVM *) NULL), swig_self_() {
      /* Acquire the Java VM pointer */
      jenv->GetJavaVM(&swig_jvm_);
    }

    virtual ~Director() {
      JNIEnvWrapper jnienv(this) ;
      JNIEnv *jenv = jnienv.getJNIEnv() ;
      swig_self_.release(jenv);
    }

    bool swig_set_self(JNIEnv *jenv, jobject jself, bool mem_own, bool weak_global) {
      return swig_self_.set(jenv, jself, mem_own, weak_global);
    }

    jobject swig_get_self(JNIEnv *jenv) const {
      return swig_self_.get(jenv);
    }

    // Change C++ object's ownership, relative to Java
    void swig_java_change_ownership(JNIEnv *jenv, jobject jself, bool take_or_release) {
      swig_self_.java_change_ownership(jenv, jself, take_or_release);
    }
  };
}

#endif /* __cplusplus */


namespace Swig {
  namespace {
    jclass jclass_pjsuaJNI = NULL;
    jmethodID director_methids[19];
  }
}

#if defined(SWIG_NOINCLUDE) || defined(SWIG_NOARRAYS)


int SWIG_JavaArrayInBool (JNIEnv *jenv, jboolean **jarr, bool **carr, jbooleanArray input);
void SWIG_JavaArrayArgoutBool (JNIEnv *jenv, jboolean *jarr, bool *carr, jbooleanArray input);
jbooleanArray SWIG_JavaArrayOutBool (JNIEnv *jenv, bool *result, jsize sz);


int SWIG_JavaArrayInSchar (JNIEnv *jenv, jbyte **jarr, signed char **carr, jbyteArray input);
void SWIG_JavaArrayArgoutSchar (JNIEnv *jenv, jbyte *jarr, signed char *carr, jbyteArray input);
jbyteArray SWIG_JavaArrayOutSchar (JNIEnv *jenv, signed char *result, jsize sz);


int SWIG_JavaArrayInUchar (JNIEnv *jenv, jshort **jarr, unsigned char **carr, jshortArray input);
void SWIG_JavaArrayArgoutUchar (JNIEnv *jenv, jshort *jarr, unsigned char *carr, jshortArray input);
jshortArray SWIG_JavaArrayOutUchar (JNIEnv *jenv, unsigned char *result, jsize sz);


int SWIG_JavaArrayInShort (JNIEnv *jenv, jshort **jarr, short **carr, jshortArray input);
void SWIG_JavaArrayArgoutShort (JNIEnv *jenv, jshort *jarr, short *carr, jshortArray input);
jshortArray SWIG_JavaArrayOutShort (JNIEnv *jenv, short *result, jsize sz);


int SWIG_JavaArrayInUshort (JNIEnv *jenv, jint **jarr, unsigned short **carr, jintArray input);
void SWIG_JavaArrayArgoutUshort (JNIEnv *jenv, jint *jarr, unsigned short *carr, jintArray input);
jintArray SWIG_JavaArrayOutUshort (JNIEnv *jenv, unsigned short *result, jsize sz);


int SWIG_JavaArrayInInt (JNIEnv *jenv, jint **jarr, int **carr, jintArray input);
void SWIG_JavaArrayArgoutInt (JNIEnv *jenv, jint *jarr, int *carr, jintArray input);
jintArray SWIG_JavaArrayOutInt (JNIEnv *jenv, int *result, jsize sz);


int SWIG_JavaArrayInUint (JNIEnv *jenv, jlong **jarr, unsigned int **carr, jlongArray input);
void SWIG_JavaArrayArgoutUint (JNIEnv *jenv, jlong *jarr, unsigned int *carr, jlongArray input);
jlongArray SWIG_JavaArrayOutUint (JNIEnv *jenv, unsigned int *result, jsize sz);


int SWIG_JavaArrayInLong (JNIEnv *jenv, jint **jarr, long **carr, jintArray input);
void SWIG_JavaArrayArgoutLong (JNIEnv *jenv, jint *jarr, long *carr, jintArray input);
jintArray SWIG_JavaArrayOutLong (JNIEnv *jenv, long *result, jsize sz);


int SWIG_JavaArrayInUlong (JNIEnv *jenv, jlong **jarr, unsigned long **carr, jlongArray input);
void SWIG_JavaArrayArgoutUlong (JNIEnv *jenv, jlong *jarr, unsigned long *carr, jlongArray input);
jlongArray SWIG_JavaArrayOutUlong (JNIEnv *jenv, unsigned long *result, jsize sz);


int SWIG_JavaArrayInLonglong (JNIEnv *jenv, jlong **jarr, jlong **carr, jlongArray input);
void SWIG_JavaArrayArgoutLonglong (JNIEnv *jenv, jlong *jarr, jlong *carr, jlongArray input);
jlongArray SWIG_JavaArrayOutLonglong (JNIEnv *jenv, jlong *result, jsize sz);


int SWIG_JavaArrayInFloat (JNIEnv *jenv, jfloat **jarr, float **carr, jfloatArray input);
void SWIG_JavaArrayArgoutFloat (JNIEnv *jenv, jfloat *jarr, float *carr, jfloatArray input);
jfloatArray SWIG_JavaArrayOutFloat (JNIEnv *jenv, float *result, jsize sz);


int SWIG_JavaArrayInDouble (JNIEnv *jenv, jdouble **jarr, double **carr, jdoubleArray input);
void SWIG_JavaArrayArgoutDouble (JNIEnv *jenv, jdouble *jarr, double *carr, jdoubleArray input);
jdoubleArray SWIG_JavaArrayOutDouble (JNIEnv *jenv, double *result, jsize sz);


#else


/* bool[] support */
int SWIG_JavaArrayInBool (JNIEnv *jenv, jboolean **jarr, bool **carr, jbooleanArray input) {
  int i;
  jsize sz;
  if (!input) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null array");
    return 0;
  }
  sz = jenv->GetArrayLength(input);
  *jarr = jenv->GetBooleanArrayElements(input, 0);
  if (!*jarr)
    return 0; 
  *carr = new bool[sz]; 
  if (!*carr) {
    SWIG_JavaThrowException(jenv, SWIG_JavaOutOfMemoryError, "array memory allocation failed");
    return 0;
  }
  for (i=0; i<sz; i++)
    (*carr)[i] = ((*jarr)[i] != 0);
  return 1;
}

void SWIG_JavaArrayArgoutBool (JNIEnv *jenv, jboolean *jarr, bool *carr, jbooleanArray input) {
  int i;
  jsize sz = jenv->GetArrayLength(input);
  for (i=0; i<sz; i++)
    jarr[i] = (jboolean)carr[i];
  jenv->ReleaseBooleanArrayElements(input, jarr, 0);
}

jbooleanArray SWIG_JavaArrayOutBool (JNIEnv *jenv, bool *result, jsize sz) {
  jboolean *arr;
  int i;
  jbooleanArray jresult = jenv->NewBooleanArray(sz);
  if (!jresult)
    return NULL;
  arr = jenv->GetBooleanArrayElements(jresult, 0);
  if (!arr)
    return NULL;
  for (i=0; i<sz; i++)
    arr[i] = (jboolean)result[i];
  jenv->ReleaseBooleanArrayElements(jresult, arr, 0);
  return jresult;
}


/* signed char[] support */
int SWIG_JavaArrayInSchar (JNIEnv *jenv, jbyte **jarr, signed char **carr, jbyteArray input) {
  int i;
  jsize sz;
  if (!input) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null array");
    return 0;
  }
  sz = jenv->GetArrayLength(input);
  *jarr = jenv->GetByteArrayElements(input, 0);
  if (!*jarr)
    return 0; 
  *carr = new signed char[sz]; 
  if (!*carr) {
    SWIG_JavaThrowException(jenv, SWIG_JavaOutOfMemoryError, "array memory allocation failed");
    return 0;
  }
  for (i=0; i<sz; i++)
    (*carr)[i] = (signed char)(*jarr)[i];
  return 1;
}

void SWIG_JavaArrayArgoutSchar (JNIEnv *jenv, jbyte *jarr, signed char *carr, jbyteArray input) {
  int i;
  jsize sz = jenv->GetArrayLength(input);
  for (i=0; i<sz; i++)
    jarr[i] = (jbyte)carr[i];
  jenv->ReleaseByteArrayElements(input, jarr, 0);
}

jbyteArray SWIG_JavaArrayOutSchar (JNIEnv *jenv, signed char *result, jsize sz) {
  jbyte *arr;
  int i;
  jbyteArray jresult = jenv->NewByteArray(sz);
  if (!jresult)
    return NULL;
  arr = jenv->GetByteArrayElements(jresult, 0);
  if (!arr)
    return NULL;
  for (i=0; i<sz; i++)
    arr[i] = (jbyte)result[i];
  jenv->ReleaseByteArrayElements(jresult, arr, 0);
  return jresult;
}


/* unsigned char[] support */
int SWIG_JavaArrayInUchar (JNIEnv *jenv, jshort **jarr, unsigned char **carr, jshortArray input) {
  int i;
  jsize sz;
  if (!input) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null array");
    return 0;
  }
  sz = jenv->GetArrayLength(input);
  *jarr = jenv->GetShortArrayElements(input, 0);
  if (!*jarr)
    return 0; 
  *carr = new unsigned char[sz]; 
  if (!*carr) {
    SWIG_JavaThrowException(jenv, SWIG_JavaOutOfMemoryError, "array memory allocation failed");
    return 0;
  }
  for (i=0; i<sz; i++)
    (*carr)[i] = (unsigned char)(*jarr)[i];
  return 1;
}

void SWIG_JavaArrayArgoutUchar (JNIEnv *jenv, jshort *jarr, unsigned char *carr, jshortArray input) {
  int i;
  jsize sz = jenv->GetArrayLength(input);
  for (i=0; i<sz; i++)
    jarr[i] = (jshort)carr[i];
  jenv->ReleaseShortArrayElements(input, jarr, 0);
}

jshortArray SWIG_JavaArrayOutUchar (JNIEnv *jenv, unsigned char *result, jsize sz) {
  jshort *arr;
  int i;
  jshortArray jresult = jenv->NewShortArray(sz);
  if (!jresult)
    return NULL;
  arr = jenv->GetShortArrayElements(jresult, 0);
  if (!arr)
    return NULL;
  for (i=0; i<sz; i++)
    arr[i] = (jshort)result[i];
  jenv->ReleaseShortArrayElements(jresult, arr, 0);
  return jresult;
}


/* short[] support */
int SWIG_JavaArrayInShort (JNIEnv *jenv, jshort **jarr, short **carr, jshortArray input) {
  int i;
  jsize sz;
  if (!input) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null array");
    return 0;
  }
  sz = jenv->GetArrayLength(input);
  *jarr = jenv->GetShortArrayElements(input, 0);
  if (!*jarr)
    return 0; 
  *carr = new short[sz]; 
  if (!*carr) {
    SWIG_JavaThrowException(jenv, SWIG_JavaOutOfMemoryError, "array memory allocation failed");
    return 0;
  }
  for (i=0; i<sz; i++)
    (*carr)[i] = (short)(*jarr)[i];
  return 1;
}

void SWIG_JavaArrayArgoutShort (JNIEnv *jenv, jshort *jarr, short *carr, jshortArray input) {
  int i;
  jsize sz = jenv->GetArrayLength(input);
  for (i=0; i<sz; i++)
    jarr[i] = (jshort)carr[i];
  jenv->ReleaseShortArrayElements(input, jarr, 0);
}

jshortArray SWIG_JavaArrayOutShort (JNIEnv *jenv, short *result, jsize sz) {
  jshort *arr;
  int i;
  jshortArray jresult = jenv->NewShortArray(sz);
  if (!jresult)
    return NULL;
  arr = jenv->GetShortArrayElements(jresult, 0);
  if (!arr)
    return NULL;
  for (i=0; i<sz; i++)
    arr[i] = (jshort)result[i];
  jenv->ReleaseShortArrayElements(jresult, arr, 0);
  return jresult;
}


/* unsigned short[] support */
int SWIG_JavaArrayInUshort (JNIEnv *jenv, jint **jarr, unsigned short **carr, jintArray input) {
  int i;
  jsize sz;
  if (!input) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null array");
    return 0;
  }
  sz = jenv->GetArrayLength(input);
  *jarr = jenv->GetIntArrayElements(input, 0);
  if (!*jarr)
    return 0; 
  *carr = new unsigned short[sz]; 
  if (!*carr) {
    SWIG_JavaThrowException(jenv, SWIG_JavaOutOfMemoryError, "array memory allocation failed");
    return 0;
  }
  for (i=0; i<sz; i++)
    (*carr)[i] = (unsigned short)(*jarr)[i];
  return 1;
}

void SWIG_JavaArrayArgoutUshort (JNIEnv *jenv, jint *jarr, unsigned short *carr, jintArray input) {
  int i;
  jsize sz = jenv->GetArrayLength(input);
  for (i=0; i<sz; i++)
    jarr[i] = (jint)carr[i];
  jenv->ReleaseIntArrayElements(input, jarr, 0);
}

jintArray SWIG_JavaArrayOutUshort (JNIEnv *jenv, unsigned short *result, jsize sz) {
  jint *arr;
  int i;
  jintArray jresult = jenv->NewIntArray(sz);
  if (!jresult)
    return NULL;
  arr = jenv->GetIntArrayElements(jresult, 0);
  if (!arr)
    return NULL;
  for (i=0; i<sz; i++)
    arr[i] = (jint)result[i];
  jenv->ReleaseIntArrayElements(jresult, arr, 0);
  return jresult;
}


/* int[] support */
int SWIG_JavaArrayInInt (JNIEnv *jenv, jint **jarr, int **carr, jintArray input) {
  int i;
  jsize sz;
  if (!input) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null array");
    return 0;
  }
  sz = jenv->GetArrayLength(input);
  *jarr = jenv->GetIntArrayElements(input, 0);
  if (!*jarr)
    return 0; 
  *carr = new int[sz]; 
  if (!*carr) {
    SWIG_JavaThrowException(jenv, SWIG_JavaOutOfMemoryError, "array memory allocation failed");
    return 0;
  }
  for (i=0; i<sz; i++)
    (*carr)[i] = (int)(*jarr)[i];
  return 1;
}

void SWIG_JavaArrayArgoutInt (JNIEnv *jenv, jint *jarr, int *carr, jintArray input) {
  int i;
  jsize sz = jenv->GetArrayLength(input);
  for (i=0; i<sz; i++)
    jarr[i] = (jint)carr[i];
  jenv->ReleaseIntArrayElements(input, jarr, 0);
}

jintArray SWIG_JavaArrayOutInt (JNIEnv *jenv, int *result, jsize sz) {
  jint *arr;
  int i;
  jintArray jresult = jenv->NewIntArray(sz);
  if (!jresult)
    return NULL;
  arr = jenv->GetIntArrayElements(jresult, 0);
  if (!arr)
    return NULL;
  for (i=0; i<sz; i++)
    arr[i] = (jint)result[i];
  jenv->ReleaseIntArrayElements(jresult, arr, 0);
  return jresult;
}


/* unsigned int[] support */
int SWIG_JavaArrayInUint (JNIEnv *jenv, jlong **jarr, unsigned int **carr, jlongArray input) {
  int i;
  jsize sz;
  if (!input) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null array");
    return 0;
  }
  sz = jenv->GetArrayLength(input);
  *jarr = jenv->GetLongArrayElements(input, 0);
  if (!*jarr)
    return 0; 
  *carr = new unsigned int[sz]; 
  if (!*carr) {
    SWIG_JavaThrowException(jenv, SWIG_JavaOutOfMemoryError, "array memory allocation failed");
    return 0;
  }
  for (i=0; i<sz; i++)
    (*carr)[i] = (unsigned int)(*jarr)[i];
  return 1;
}

void SWIG_JavaArrayArgoutUint (JNIEnv *jenv, jlong *jarr, unsigned int *carr, jlongArray input) {
  int i;
  jsize sz = jenv->GetArrayLength(input);
  for (i=0; i<sz; i++)
    jarr[i] = (jlong)carr[i];
  jenv->ReleaseLongArrayElements(input, jarr, 0);
}

jlongArray SWIG_JavaArrayOutUint (JNIEnv *jenv, unsigned int *result, jsize sz) {
  jlong *arr;
  int i;
  jlongArray jresult = jenv->NewLongArray(sz);
  if (!jresult)
    return NULL;
  arr = jenv->GetLongArrayElements(jresult, 0);
  if (!arr)
    return NULL;
  for (i=0; i<sz; i++)
    arr[i] = (jlong)result[i];
  jenv->ReleaseLongArrayElements(jresult, arr, 0);
  return jresult;
}


/* long[] support */
int SWIG_JavaArrayInLong (JNIEnv *jenv, jint **jarr, long **carr, jintArray input) {
  int i;
  jsize sz;
  if (!input) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null array");
    return 0;
  }
  sz = jenv->GetArrayLength(input);
  *jarr = jenv->GetIntArrayElements(input, 0);
  if (!*jarr)
    return 0; 
  *carr = new long[sz]; 
  if (!*carr) {
    SWIG_JavaThrowException(jenv, SWIG_JavaOutOfMemoryError, "array memory allocation failed");
    return 0;
  }
  for (i=0; i<sz; i++)
    (*carr)[i] = (long)(*jarr)[i];
  return 1;
}

void SWIG_JavaArrayArgoutLong (JNIEnv *jenv, jint *jarr, long *carr, jintArray input) {
  int i;
  jsize sz = jenv->GetArrayLength(input);
  for (i=0; i<sz; i++)
    jarr[i] = (jint)carr[i];
  jenv->ReleaseIntArrayElements(input, jarr, 0);
}

jintArray SWIG_JavaArrayOutLong (JNIEnv *jenv, long *result, jsize sz) {
  jint *arr;
  int i;
  jintArray jresult = jenv->NewIntArray(sz);
  if (!jresult)
    return NULL;
  arr = jenv->GetIntArrayElements(jresult, 0);
  if (!arr)
    return NULL;
  for (i=0; i<sz; i++)
    arr[i] = (jint)result[i];
  jenv->ReleaseIntArrayElements(jresult, arr, 0);
  return jresult;
}


/* unsigned long[] support */
int SWIG_JavaArrayInUlong (JNIEnv *jenv, jlong **jarr, unsigned long **carr, jlongArray input) {
  int i;
  jsize sz;
  if (!input) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null array");
    return 0;
  }
  sz = jenv->GetArrayLength(input);
  *jarr = jenv->GetLongArrayElements(input, 0);
  if (!*jarr)
    return 0; 
  *carr = new unsigned long[sz]; 
  if (!*carr) {
    SWIG_JavaThrowException(jenv, SWIG_JavaOutOfMemoryError, "array memory allocation failed");
    return 0;
  }
  for (i=0; i<sz; i++)
    (*carr)[i] = (unsigned long)(*jarr)[i];
  return 1;
}

void SWIG_JavaArrayArgoutUlong (JNIEnv *jenv, jlong *jarr, unsigned long *carr, jlongArray input) {
  int i;
  jsize sz = jenv->GetArrayLength(input);
  for (i=0; i<sz; i++)
    jarr[i] = (jlong)carr[i];
  jenv->ReleaseLongArrayElements(input, jarr, 0);
}

jlongArray SWIG_JavaArrayOutUlong (JNIEnv *jenv, unsigned long *result, jsize sz) {
  jlong *arr;
  int i;
  jlongArray jresult = jenv->NewLongArray(sz);
  if (!jresult)
    return NULL;
  arr = jenv->GetLongArrayElements(jresult, 0);
  if (!arr)
    return NULL;
  for (i=0; i<sz; i++)
    arr[i] = (jlong)result[i];
  jenv->ReleaseLongArrayElements(jresult, arr, 0);
  return jresult;
}


/* jlong[] support */
int SWIG_JavaArrayInLonglong (JNIEnv *jenv, jlong **jarr, jlong **carr, jlongArray input) {
  int i;
  jsize sz;
  if (!input) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null array");
    return 0;
  }
  sz = jenv->GetArrayLength(input);
  *jarr = jenv->GetLongArrayElements(input, 0);
  if (!*jarr)
    return 0; 
  *carr = new jlong[sz]; 
  if (!*carr) {
    SWIG_JavaThrowException(jenv, SWIG_JavaOutOfMemoryError, "array memory allocation failed");
    return 0;
  }
  for (i=0; i<sz; i++)
    (*carr)[i] = (jlong)(*jarr)[i];
  return 1;
}

void SWIG_JavaArrayArgoutLonglong (JNIEnv *jenv, jlong *jarr, jlong *carr, jlongArray input) {
  int i;
  jsize sz = jenv->GetArrayLength(input);
  for (i=0; i<sz; i++)
    jarr[i] = (jlong)carr[i];
  jenv->ReleaseLongArrayElements(input, jarr, 0);
}

jlongArray SWIG_JavaArrayOutLonglong (JNIEnv *jenv, jlong *result, jsize sz) {
  jlong *arr;
  int i;
  jlongArray jresult = jenv->NewLongArray(sz);
  if (!jresult)
    return NULL;
  arr = jenv->GetLongArrayElements(jresult, 0);
  if (!arr)
    return NULL;
  for (i=0; i<sz; i++)
    arr[i] = (jlong)result[i];
  jenv->ReleaseLongArrayElements(jresult, arr, 0);
  return jresult;
}


/* float[] support */
int SWIG_JavaArrayInFloat (JNIEnv *jenv, jfloat **jarr, float **carr, jfloatArray input) {
  int i;
  jsize sz;
  if (!input) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null array");
    return 0;
  }
  sz = jenv->GetArrayLength(input);
  *jarr = jenv->GetFloatArrayElements(input, 0);
  if (!*jarr)
    return 0; 
  *carr = new float[sz]; 
  if (!*carr) {
    SWIG_JavaThrowException(jenv, SWIG_JavaOutOfMemoryError, "array memory allocation failed");
    return 0;
  }
  for (i=0; i<sz; i++)
    (*carr)[i] = (float)(*jarr)[i];
  return 1;
}

void SWIG_JavaArrayArgoutFloat (JNIEnv *jenv, jfloat *jarr, float *carr, jfloatArray input) {
  int i;
  jsize sz = jenv->GetArrayLength(input);
  for (i=0; i<sz; i++)
    jarr[i] = (jfloat)carr[i];
  jenv->ReleaseFloatArrayElements(input, jarr, 0);
}

jfloatArray SWIG_JavaArrayOutFloat (JNIEnv *jenv, float *result, jsize sz) {
  jfloat *arr;
  int i;
  jfloatArray jresult = jenv->NewFloatArray(sz);
  if (!jresult)
    return NULL;
  arr = jenv->GetFloatArrayElements(jresult, 0);
  if (!arr)
    return NULL;
  for (i=0; i<sz; i++)
    arr[i] = (jfloat)result[i];
  jenv->ReleaseFloatArrayElements(jresult, arr, 0);
  return jresult;
}


/* double[] support */
int SWIG_JavaArrayInDouble (JNIEnv *jenv, jdouble **jarr, double **carr, jdoubleArray input) {
  int i;
  jsize sz;
  if (!input) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null array");
    return 0;
  }
  sz = jenv->GetArrayLength(input);
  *jarr = jenv->GetDoubleArrayElements(input, 0);
  if (!*jarr)
    return 0; 
  *carr = new double[sz]; 
  if (!*carr) {
    SWIG_JavaThrowException(jenv, SWIG_JavaOutOfMemoryError, "array memory allocation failed");
    return 0;
  }
  for (i=0; i<sz; i++)
    (*carr)[i] = (double)(*jarr)[i];
  return 1;
}

void SWIG_JavaArrayArgoutDouble (JNIEnv *jenv, jdouble *jarr, double *carr, jdoubleArray input) {
  int i;
  jsize sz = jenv->GetArrayLength(input);
  for (i=0; i<sz; i++)
    jarr[i] = (jdouble)carr[i];
  jenv->ReleaseDoubleArrayElements(input, jarr, 0);
}

jdoubleArray SWIG_JavaArrayOutDouble (JNIEnv *jenv, double *result, jsize sz) {
  jdouble *arr;
  int i;
  jdoubleArray jresult = jenv->NewDoubleArray(sz);
  if (!jresult)
    return NULL;
  arr = jenv->GetDoubleArrayElements(jresult, 0);
  if (!arr)
    return NULL;
  for (i=0; i<sz; i++)
    arr[i] = (jdouble)result[i];
  jenv->ReleaseDoubleArrayElements(jresult, arr, 0);
  return jresult;
}


#endif



#include <pjsua-lib/pjsua.h>
#include <pjsua_jni_addons.h>

// LOGGING
#define THIS_FILE	"pjsua_wrap.cpp"

class Callback {
public:
	virtual ~Callback() {}
	virtual void on_call_state (pjsua_call_id call_id, pjsip_event *e) {}
	virtual void on_incoming_call (pjsua_acc_id acc_id, pjsua_call_id call_id,
		pjsip_rx_data *rdata) {}
	virtual void on_call_tsx_state (pjsua_call_id call_id, 
		pjsip_transaction *tsx,
		pjsip_event *e) {}
	virtual void on_call_media_state (pjsua_call_id call_id) {}
	virtual void on_stream_created (pjsua_call_id call_id, 
		pjmedia_session *sess,
		unsigned stream_idx, 
		pjmedia_port **p_port) {}
	virtual void on_stream_destroyed (pjsua_call_id call_id,
		pjmedia_session *sess, 
		unsigned stream_idx) {}
	virtual void on_dtmf_digit (pjsua_call_id call_id, int digit) {}
	virtual void on_call_transfer_request (pjsua_call_id call_id,
		const pj_str_t *dst,
		pjsip_status_code *code) {}
	virtual void on_call_transfer_status (pjsua_call_id call_id,
		int st_code,
		const pj_str_t *st_text,
		pj_bool_t final_,
		pj_bool_t *p_cont) {}
	virtual void on_call_replace_request (pjsua_call_id call_id,
		pjsip_rx_data *rdata,
		int *st_code,
		pj_str_t *st_text) {}
	virtual void on_call_replaced (pjsua_call_id old_call_id,
		pjsua_call_id new_call_id) {}
	virtual void on_reg_state (pjsua_acc_id acc_id) {}
	virtual void on_buddy_state (pjsua_buddy_id buddy_id) {}
	virtual void on_pager (pjsua_call_id call_id, const pj_str_t *from,
		const pj_str_t *to, const pj_str_t *contact,
		const pj_str_t *mime_type, const pj_str_t *body) {}
	virtual void on_pager2 (pjsua_call_id call_id, const pj_str_t *from,
		const pj_str_t *to, const pj_str_t *contact,
		const pj_str_t *mime_type, const pj_str_t *body,
		pjsip_rx_data *rdata) {}
	virtual void on_pager_status (pjsua_call_id call_id,
		const pj_str_t *to,
		const pj_str_t *body,
/*XXX		void *user_data,*/
		pjsip_status_code status,
		const pj_str_t *reason) {}
	virtual void on_pager_status2 (pjsua_call_id call_id,
		const pj_str_t *to,
		const pj_str_t *body,
/*XXX		void *user_data,*/
		pjsip_status_code status,
		const pj_str_t *reason,
		pjsip_tx_data *tdata,
		pjsip_rx_data *rdata) {}
	virtual void on_typing (pjsua_call_id call_id, const pj_str_t *from,
		const pj_str_t *to, const pj_str_t *contact,
		pj_bool_t is_typing) {}
	virtual void on_nat_detect (const pj_stun_nat_detect_result *res) {}
};

static Callback* registeredCallbackObject = NULL;

extern "C" {
void on_call_state_wrapper(pjsua_call_id call_id, pjsip_event *e) {
	app_on_call_state(call_id, e);
	registeredCallbackObject->on_call_state(call_id, e);
}
    
void on_incoming_call_wrapper (pjsua_acc_id acc_id, pjsua_call_id call_id,
	pjsip_rx_data *rdata) {
	registeredCallbackObject->on_incoming_call(acc_id, call_id, rdata);
}
    
void on_call_tsx_state_wrapper (pjsua_call_id call_id, 
		pjsip_transaction *tsx,
		pjsip_event *e) {
	registeredCallbackObject->on_call_tsx_state(call_id, tsx, e);
}
    
void on_call_media_state_wrapper (pjsua_call_id call_id) {
	ring_stop(call_id);
	registeredCallbackObject->on_call_media_state(call_id);
}
 

void on_stream_created_wrapper (pjsua_call_id call_id, 
		pjmedia_session *sess,
		unsigned stream_idx, 
		pjmedia_port **p_port) {
	registeredCallbackObject->on_stream_created(call_id, sess, stream_idx, p_port);
}

void on_stream_destroyed_wrapper (pjsua_call_id call_id,
	pjmedia_session *sess, 
	unsigned stream_idx) {
	registeredCallbackObject->on_stream_destroyed(call_id, sess, stream_idx);
}

void on_dtmf_digit_wrapper (pjsua_call_id call_id, int digit) {
	registeredCallbackObject->on_dtmf_digit(call_id, digit);
}

void on_call_transfer_request_wrapper (pjsua_call_id call_id,
	const pj_str_t *dst,
	pjsip_status_code *code) {
	registeredCallbackObject->on_call_transfer_request(call_id, dst, code);
}

void on_call_transfer_status_wrapper (pjsua_call_id call_id,
	int st_code,
	const pj_str_t *st_text,
	pj_bool_t final_,
	pj_bool_t *p_cont) {
	registeredCallbackObject->on_call_transfer_status(call_id, st_code, st_text, final_, p_cont);
}

void on_call_replace_request_wrapper (pjsua_call_id call_id,
	pjsip_rx_data *rdata,
	int *st_code,
	pj_str_t *st_text) {
	registeredCallbackObject->on_call_replace_request(call_id, rdata, st_code, st_text);
}

void on_call_replaced_wrapper (pjsua_call_id old_call_id,
	pjsua_call_id new_call_id) {
	registeredCallbackObject->on_call_replaced(old_call_id, new_call_id);
}

void on_reg_state_wrapper (pjsua_acc_id acc_id) {
	registeredCallbackObject->on_reg_state(acc_id);
}

void on_buddy_state_wrapper (pjsua_buddy_id buddy_id) {
	registeredCallbackObject->on_buddy_state(buddy_id);
}

void on_pager_wrapper (pjsua_call_id call_id, const pj_str_t *from,
	const pj_str_t *to, const pj_str_t *contact,
	const pj_str_t *mime_type, const pj_str_t *body) {
	registeredCallbackObject->on_pager(call_id, from, to, contact, mime_type, body);
}

void on_pager2_wrapper (pjsua_call_id call_id, const pj_str_t *from,
	const pj_str_t *to, const pj_str_t *contact,
	const pj_str_t *mime_type, const pj_str_t *body,
	pjsip_rx_data *rdata, pjsua_acc_id acc_id) {
	registeredCallbackObject->on_pager2(call_id, from, to, contact, mime_type, body, rdata);
}

void on_pager_status_wrapper (pjsua_call_id call_id,
	const pj_str_t *to,
	const pj_str_t *body,
	void *user_data,
	pjsip_status_code status,
	const pj_str_t *reason) {
	registeredCallbackObject->on_pager_status(call_id, to, body, /*XXX user_data,*/ status, reason);
}

void on_pager_status2_wrapper (pjsua_call_id call_id,
	const pj_str_t *to,
	const pj_str_t *body,
	void *user_data,
	pjsip_status_code status,
	const pj_str_t *reason,
	pjsip_tx_data *tdata,
	pjsip_rx_data *rdata, pjsua_acc_id acc_id) {
	registeredCallbackObject->on_pager_status2(call_id, to, body, /*XXX user_data,*/ status, reason, tdata, rdata);
}

void on_typing_wrapper (pjsua_call_id call_id, const pj_str_t *from,
	const pj_str_t *to, const pj_str_t *contact,
	pj_bool_t is_typing) {
	registeredCallbackObject->on_typing(call_id, from, to, contact, is_typing);
}

void on_nat_detect_wrapper (const pj_stun_nat_detect_result *res) {
	registeredCallbackObject->on_nat_detect(res);
}
}

static struct pjsua_callback wrapper_callback_struct = {
	&on_call_state_wrapper,
	&on_incoming_call_wrapper,
	&on_call_tsx_state_wrapper,
	&on_call_media_state_wrapper,
	&on_stream_created_wrapper,
	&on_stream_destroyed_wrapper,
	&on_dtmf_digit_wrapper,
	&on_call_transfer_request_wrapper,
	&on_call_transfer_status_wrapper,
	&on_call_replace_request_wrapper,
	&on_call_replaced_wrapper,
	&on_reg_state_wrapper,
	NULL, //on_reg2_state
	NULL, // incoming subscribe &on_incoming_subscribe_wrapper,
	NULL, // srv_subscribe state &on_srv_subscribe_state_wrapper,
	&on_buddy_state_wrapper,
	NULL, // on_buddy_evsub_state
	&on_pager_wrapper,
	&on_pager2_wrapper,
	&on_pager_status_wrapper,
	&on_pager_status2_wrapper,
	&on_typing_wrapper,
	NULL, //Typing 2
	&on_nat_detect_wrapper,
	NULL, //on_call_redirected
	NULL
};

void setCallbackObject(Callback* callback) {
	registeredCallbackObject = callback;
}



pj_str_t pj_str_copy(const char *str) {
	size_t length = strlen(str) + 1;
	char* copy = (char*)calloc(length, sizeof(char));
	copy = strncpy(copy, str, length);
	return pj_str(copy);
}




/* ---------------------------------------------------
 * C++ director class methods
 * --------------------------------------------------- */

#include "pjsua_wrap.h"

SwigDirector_Callback::SwigDirector_Callback(JNIEnv *jenv) : Callback(), Swig::Director(jenv) {
}

SwigDirector_Callback::~SwigDirector_Callback() {
  swig_disconnect_director_self("swigDirectorDisconnect");
}


void SwigDirector_Callback::on_call_state(pjsua_call_id call_id, pjsip_event *e) {
  JNIEnvWrapper swigjnienv(this) ;
  JNIEnv * jenv = swigjnienv.getJNIEnv() ;
  jobject swigjobj = (jobject) NULL ;
  jint jcall_id  ;
  jlong je = 0 ;
  
  if (!swig_override[0]) {
    Callback::on_call_state(call_id,e);
    return;
  }
  swigjobj = swig_get_self(jenv);
  if (swigjobj && jenv->IsSameObject(swigjobj, NULL) == JNI_FALSE) {
    jcall_id = (jint) call_id;
    *((pjsip_event **)&je) = (pjsip_event *) e; 
    jenv->CallStaticVoidMethod(Swig::jclass_pjsuaJNI, Swig::director_methids[0], swigjobj, jcall_id, je);
    if (jenv->ExceptionOccurred()) return ;
  } else {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null upcall object");
  }
  if (swigjobj) jenv->DeleteLocalRef(swigjobj);
}

void SwigDirector_Callback::on_incoming_call(pjsua_acc_id acc_id, pjsua_call_id call_id, pjsip_rx_data *rdata) {
  JNIEnvWrapper swigjnienv(this) ;
  JNIEnv * jenv = swigjnienv.getJNIEnv() ;
  jobject swigjobj = (jobject) NULL ;
  jint jacc_id  ;
  jint jcall_id  ;
  jlong jrdata = 0 ;
  
  if (!swig_override[1]) {
    Callback::on_incoming_call(acc_id,call_id,rdata);
    return;
  }
  swigjobj = swig_get_self(jenv);
  if (swigjobj && jenv->IsSameObject(swigjobj, NULL) == JNI_FALSE) {
    jacc_id = (jint) acc_id;
    jcall_id = (jint) call_id;
    *((pjsip_rx_data **)&jrdata) = (pjsip_rx_data *) rdata; 
    jenv->CallStaticVoidMethod(Swig::jclass_pjsuaJNI, Swig::director_methids[1], swigjobj, jacc_id, jcall_id, jrdata);
    if (jenv->ExceptionOccurred()) return ;
  } else {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null upcall object");
  }
  if (swigjobj) jenv->DeleteLocalRef(swigjobj);
}

void SwigDirector_Callback::on_call_tsx_state(pjsua_call_id call_id, pjsip_transaction *tsx, pjsip_event *e) {
  JNIEnvWrapper swigjnienv(this) ;
  JNIEnv * jenv = swigjnienv.getJNIEnv() ;
  jobject swigjobj = (jobject) NULL ;
  jint jcall_id  ;
  jlong jtsx = 0 ;
  jlong je = 0 ;
  
  if (!swig_override[2]) {
    Callback::on_call_tsx_state(call_id,tsx,e);
    return;
  }
  swigjobj = swig_get_self(jenv);
  if (swigjobj && jenv->IsSameObject(swigjobj, NULL) == JNI_FALSE) {
    jcall_id = (jint) call_id;
    *((pjsip_transaction **)&jtsx) = (pjsip_transaction *) tsx; 
    *((pjsip_event **)&je) = (pjsip_event *) e; 
    jenv->CallStaticVoidMethod(Swig::jclass_pjsuaJNI, Swig::director_methids[2], swigjobj, jcall_id, jtsx, je);
    if (jenv->ExceptionOccurred()) return ;
  } else {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null upcall object");
  }
  if (swigjobj) jenv->DeleteLocalRef(swigjobj);
}

void SwigDirector_Callback::on_call_media_state(pjsua_call_id call_id) {
  JNIEnvWrapper swigjnienv(this) ;
  JNIEnv * jenv = swigjnienv.getJNIEnv() ;
  jobject swigjobj = (jobject) NULL ;
  jint jcall_id  ;
  
  if (!swig_override[3]) {
    Callback::on_call_media_state(call_id);
    return;
  }
  swigjobj = swig_get_self(jenv);
  if (swigjobj && jenv->IsSameObject(swigjobj, NULL) == JNI_FALSE) {
    jcall_id = (jint) call_id;
    jenv->CallStaticVoidMethod(Swig::jclass_pjsuaJNI, Swig::director_methids[3], swigjobj, jcall_id);
    if (jenv->ExceptionOccurred()) return ;
  } else {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null upcall object");
  }
  if (swigjobj) jenv->DeleteLocalRef(swigjobj);
}

void SwigDirector_Callback::on_stream_created(pjsua_call_id call_id, pjmedia_session *sess, unsigned int stream_idx, pjmedia_port **p_port) {
  JNIEnvWrapper swigjnienv(this) ;
  JNIEnv * jenv = swigjnienv.getJNIEnv() ;
  jobject swigjobj = (jobject) NULL ;
  jint jcall_id  ;
  jlong jsess = 0 ;
  jlong jstream_idx  ;
  jlong jp_port = 0 ;
  
  if (!swig_override[4]) {
    Callback::on_stream_created(call_id,sess,stream_idx,p_port);
    return;
  }
  swigjobj = swig_get_self(jenv);
  if (swigjobj && jenv->IsSameObject(swigjobj, NULL) == JNI_FALSE) {
    jcall_id = (jint) call_id;
    *((pjmedia_session **)&jsess) = (pjmedia_session *) sess; 
    jstream_idx = (jlong) stream_idx;
    *((pjmedia_port ***)&jp_port) = (pjmedia_port **) p_port; 
    jenv->CallStaticVoidMethod(Swig::jclass_pjsuaJNI, Swig::director_methids[4], swigjobj, jcall_id, jsess, jstream_idx, jp_port);
    if (jenv->ExceptionOccurred()) return ;
  } else {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null upcall object");
  }
  if (swigjobj) jenv->DeleteLocalRef(swigjobj);
}

void SwigDirector_Callback::on_stream_destroyed(pjsua_call_id call_id, pjmedia_session *sess, unsigned int stream_idx) {
  JNIEnvWrapper swigjnienv(this) ;
  JNIEnv * jenv = swigjnienv.getJNIEnv() ;
  jobject swigjobj = (jobject) NULL ;
  jint jcall_id  ;
  jlong jsess = 0 ;
  jlong jstream_idx  ;
  
  if (!swig_override[5]) {
    Callback::on_stream_destroyed(call_id,sess,stream_idx);
    return;
  }
  swigjobj = swig_get_self(jenv);
  if (swigjobj && jenv->IsSameObject(swigjobj, NULL) == JNI_FALSE) {
    jcall_id = (jint) call_id;
    *((pjmedia_session **)&jsess) = (pjmedia_session *) sess; 
    jstream_idx = (jlong) stream_idx;
    jenv->CallStaticVoidMethod(Swig::jclass_pjsuaJNI, Swig::director_methids[5], swigjobj, jcall_id, jsess, jstream_idx);
    if (jenv->ExceptionOccurred()) return ;
  } else {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null upcall object");
  }
  if (swigjobj) jenv->DeleteLocalRef(swigjobj);
}

void SwigDirector_Callback::on_dtmf_digit(pjsua_call_id call_id, int digit) {
  JNIEnvWrapper swigjnienv(this) ;
  JNIEnv * jenv = swigjnienv.getJNIEnv() ;
  jobject swigjobj = (jobject) NULL ;
  jint jcall_id  ;
  jint jdigit  ;
  
  if (!swig_override[6]) {
    Callback::on_dtmf_digit(call_id,digit);
    return;
  }
  swigjobj = swig_get_self(jenv);
  if (swigjobj && jenv->IsSameObject(swigjobj, NULL) == JNI_FALSE) {
    jcall_id = (jint) call_id;
    jdigit = (jint) digit;
    jenv->CallStaticVoidMethod(Swig::jclass_pjsuaJNI, Swig::director_methids[6], swigjobj, jcall_id, jdigit);
    if (jenv->ExceptionOccurred()) return ;
  } else {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null upcall object");
  }
  if (swigjobj) jenv->DeleteLocalRef(swigjobj);
}

void SwigDirector_Callback::on_call_transfer_request(pjsua_call_id call_id, pj_str_t const *dst, pjsip_status_code *code) {
  JNIEnvWrapper swigjnienv(this) ;
  JNIEnv * jenv = swigjnienv.getJNIEnv() ;
  jobject swigjobj = (jobject) NULL ;
  jint jcall_id  ;
  jlong jdst = 0 ;
  jlong jcode = 0 ;
  
  if (!swig_override[7]) {
    Callback::on_call_transfer_request(call_id,dst,code);
    return;
  }
  swigjobj = swig_get_self(jenv);
  if (swigjobj && jenv->IsSameObject(swigjobj, NULL) == JNI_FALSE) {
    jcall_id = (jint) call_id;
    *((pj_str_t **)&jdst) = (pj_str_t *) dst; 
    *((pjsip_status_code **)&jcode) = (pjsip_status_code *) code; 
    jenv->CallStaticVoidMethod(Swig::jclass_pjsuaJNI, Swig::director_methids[7], swigjobj, jcall_id, jdst, jcode);
    if (jenv->ExceptionOccurred()) return ;
  } else {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null upcall object");
  }
  if (swigjobj) jenv->DeleteLocalRef(swigjobj);
}

void SwigDirector_Callback::on_call_transfer_status(pjsua_call_id call_id, int st_code, pj_str_t const *st_text, pj_bool_t final_, pj_bool_t *p_cont) {
  JNIEnvWrapper swigjnienv(this) ;
  JNIEnv * jenv = swigjnienv.getJNIEnv() ;
  jobject swigjobj = (jobject) NULL ;
  jint jcall_id  ;
  jint jst_code  ;
  jlong jst_text = 0 ;
  jint jfinal_  ;
  jlong jp_cont = 0 ;
  
  if (!swig_override[8]) {
    Callback::on_call_transfer_status(call_id,st_code,st_text,final_,p_cont);
    return;
  }
  swigjobj = swig_get_self(jenv);
  if (swigjobj && jenv->IsSameObject(swigjobj, NULL) == JNI_FALSE) {
    jcall_id = (jint) call_id;
    jst_code = (jint) st_code;
    *((pj_str_t **)&jst_text) = (pj_str_t *) st_text; 
    jfinal_ = (jint) final_;
    *((pj_bool_t **)&jp_cont) = (pj_bool_t *) p_cont; 
    jenv->CallStaticVoidMethod(Swig::jclass_pjsuaJNI, Swig::director_methids[8], swigjobj, jcall_id, jst_code, jst_text, jfinal_, jp_cont);
    if (jenv->ExceptionOccurred()) return ;
  } else {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null upcall object");
  }
  if (swigjobj) jenv->DeleteLocalRef(swigjobj);
}

void SwigDirector_Callback::on_call_replace_request(pjsua_call_id call_id, pjsip_rx_data *rdata, int *st_code, pj_str_t *st_text) {
  JNIEnvWrapper swigjnienv(this) ;
  JNIEnv * jenv = swigjnienv.getJNIEnv() ;
  jobject swigjobj = (jobject) NULL ;
  jint jcall_id  ;
  jlong jrdata = 0 ;
  jlong jst_code = 0 ;
  jlong jst_text = 0 ;
  
  if (!swig_override[9]) {
    Callback::on_call_replace_request(call_id,rdata,st_code,st_text);
    return;
  }
  swigjobj = swig_get_self(jenv);
  if (swigjobj && jenv->IsSameObject(swigjobj, NULL) == JNI_FALSE) {
    jcall_id = (jint) call_id;
    *((pjsip_rx_data **)&jrdata) = (pjsip_rx_data *) rdata; 
    *((int **)&jst_code) = (int *) st_code; 
    *((pj_str_t **)&jst_text) = (pj_str_t *) st_text; 
    jenv->CallStaticVoidMethod(Swig::jclass_pjsuaJNI, Swig::director_methids[9], swigjobj, jcall_id, jrdata, jst_code, jst_text);
    if (jenv->ExceptionOccurred()) return ;
  } else {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null upcall object");
  }
  if (swigjobj) jenv->DeleteLocalRef(swigjobj);
}

void SwigDirector_Callback::on_call_replaced(pjsua_call_id old_call_id, pjsua_call_id new_call_id) {
  JNIEnvWrapper swigjnienv(this) ;
  JNIEnv * jenv = swigjnienv.getJNIEnv() ;
  jobject swigjobj = (jobject) NULL ;
  jint jold_call_id  ;
  jint jnew_call_id  ;
  
  if (!swig_override[10]) {
    Callback::on_call_replaced(old_call_id,new_call_id);
    return;
  }
  swigjobj = swig_get_self(jenv);
  if (swigjobj && jenv->IsSameObject(swigjobj, NULL) == JNI_FALSE) {
    jold_call_id = (jint) old_call_id;
    jnew_call_id = (jint) new_call_id;
    jenv->CallStaticVoidMethod(Swig::jclass_pjsuaJNI, Swig::director_methids[10], swigjobj, jold_call_id, jnew_call_id);
    if (jenv->ExceptionOccurred()) return ;
  } else {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null upcall object");
  }
  if (swigjobj) jenv->DeleteLocalRef(swigjobj);
}

void SwigDirector_Callback::on_reg_state(pjsua_acc_id acc_id) {
  JNIEnvWrapper swigjnienv(this) ;
  JNIEnv * jenv = swigjnienv.getJNIEnv() ;
  jobject swigjobj = (jobject) NULL ;
  jint jacc_id  ;
  
  if (!swig_override[11]) {
    Callback::on_reg_state(acc_id);
    return;
  }
  swigjobj = swig_get_self(jenv);
  if (swigjobj && jenv->IsSameObject(swigjobj, NULL) == JNI_FALSE) {
    jacc_id = (jint) acc_id;
    jenv->CallStaticVoidMethod(Swig::jclass_pjsuaJNI, Swig::director_methids[11], swigjobj, jacc_id);
    if (jenv->ExceptionOccurred()) return ;
  } else {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null upcall object");
  }
  if (swigjobj) jenv->DeleteLocalRef(swigjobj);
}

void SwigDirector_Callback::on_buddy_state(pjsua_buddy_id buddy_id) {
  JNIEnvWrapper swigjnienv(this) ;
  JNIEnv * jenv = swigjnienv.getJNIEnv() ;
  jobject swigjobj = (jobject) NULL ;
  jint jbuddy_id  ;
  
  if (!swig_override[12]) {
    Callback::on_buddy_state(buddy_id);
    return;
  }
  swigjobj = swig_get_self(jenv);
  if (swigjobj && jenv->IsSameObject(swigjobj, NULL) == JNI_FALSE) {
    jbuddy_id = (jint) buddy_id;
    jenv->CallStaticVoidMethod(Swig::jclass_pjsuaJNI, Swig::director_methids[12], swigjobj, jbuddy_id);
    if (jenv->ExceptionOccurred()) return ;
  } else {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null upcall object");
  }
  if (swigjobj) jenv->DeleteLocalRef(swigjobj);
}

void SwigDirector_Callback::on_pager(pjsua_call_id call_id, pj_str_t const *from, pj_str_t const *to, pj_str_t const *contact, pj_str_t const *mime_type, pj_str_t const *body) {
  JNIEnvWrapper swigjnienv(this) ;
  JNIEnv * jenv = swigjnienv.getJNIEnv() ;
  jobject swigjobj = (jobject) NULL ;
  jint jcall_id  ;
  jlong jfrom = 0 ;
  jlong jto = 0 ;
  jlong jcontact = 0 ;
  jlong jmime_type = 0 ;
  jlong jbody = 0 ;
  
  if (!swig_override[13]) {
    Callback::on_pager(call_id,from,to,contact,mime_type,body);
    return;
  }
  swigjobj = swig_get_self(jenv);
  if (swigjobj && jenv->IsSameObject(swigjobj, NULL) == JNI_FALSE) {
    jcall_id = (jint) call_id;
    *((pj_str_t **)&jfrom) = (pj_str_t *) from; 
    *((pj_str_t **)&jto) = (pj_str_t *) to; 
    *((pj_str_t **)&jcontact) = (pj_str_t *) contact; 
    *((pj_str_t **)&jmime_type) = (pj_str_t *) mime_type; 
    *((pj_str_t **)&jbody) = (pj_str_t *) body; 
    jenv->CallStaticVoidMethod(Swig::jclass_pjsuaJNI, Swig::director_methids[13], swigjobj, jcall_id, jfrom, jto, jcontact, jmime_type, jbody);
    if (jenv->ExceptionOccurred()) return ;
  } else {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null upcall object");
  }
  if (swigjobj) jenv->DeleteLocalRef(swigjobj);
}

void SwigDirector_Callback::on_pager2(pjsua_call_id call_id, pj_str_t const *from, pj_str_t const *to, pj_str_t const *contact, pj_str_t const *mime_type, pj_str_t const *body, pjsip_rx_data *rdata) {
  JNIEnvWrapper swigjnienv(this) ;
  JNIEnv * jenv = swigjnienv.getJNIEnv() ;
  jobject swigjobj = (jobject) NULL ;
  jint jcall_id  ;
  jlong jfrom = 0 ;
  jlong jto = 0 ;
  jlong jcontact = 0 ;
  jlong jmime_type = 0 ;
  jlong jbody = 0 ;
  jlong jrdata = 0 ;
  
  if (!swig_override[14]) {
    Callback::on_pager2(call_id,from,to,contact,mime_type,body,rdata);
    return;
  }
  swigjobj = swig_get_self(jenv);
  if (swigjobj && jenv->IsSameObject(swigjobj, NULL) == JNI_FALSE) {
    jcall_id = (jint) call_id;
    *((pj_str_t **)&jfrom) = (pj_str_t *) from; 
    *((pj_str_t **)&jto) = (pj_str_t *) to; 
    *((pj_str_t **)&jcontact) = (pj_str_t *) contact; 
    *((pj_str_t **)&jmime_type) = (pj_str_t *) mime_type; 
    *((pj_str_t **)&jbody) = (pj_str_t *) body; 
    *((pjsip_rx_data **)&jrdata) = (pjsip_rx_data *) rdata; 
    jenv->CallStaticVoidMethod(Swig::jclass_pjsuaJNI, Swig::director_methids[14], swigjobj, jcall_id, jfrom, jto, jcontact, jmime_type, jbody, jrdata);
    if (jenv->ExceptionOccurred()) return ;
  } else {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null upcall object");
  }
  if (swigjobj) jenv->DeleteLocalRef(swigjobj);
}

void SwigDirector_Callback::on_pager_status(pjsua_call_id call_id, pj_str_t const *to, pj_str_t const *body, pjsip_status_code status, pj_str_t const *reason) {
  JNIEnvWrapper swigjnienv(this) ;
  JNIEnv * jenv = swigjnienv.getJNIEnv() ;
  jobject swigjobj = (jobject) NULL ;
  jint jcall_id  ;
  jlong jto = 0 ;
  jlong jbody = 0 ;
  jint jstatus  ;
  jlong jreason = 0 ;
  
  if (!swig_override[15]) {
    Callback::on_pager_status(call_id,to,body,status,reason);
    return;
  }
  swigjobj = swig_get_self(jenv);
  if (swigjobj && jenv->IsSameObject(swigjobj, NULL) == JNI_FALSE) {
    jcall_id = (jint) call_id;
    *((pj_str_t **)&jto) = (pj_str_t *) to; 
    *((pj_str_t **)&jbody) = (pj_str_t *) body; 
    jstatus = (jint) status;
    *((pj_str_t **)&jreason) = (pj_str_t *) reason; 
    jenv->CallStaticVoidMethod(Swig::jclass_pjsuaJNI, Swig::director_methids[15], swigjobj, jcall_id, jto, jbody, jstatus, jreason);
    if (jenv->ExceptionOccurred()) return ;
  } else {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null upcall object");
  }
  if (swigjobj) jenv->DeleteLocalRef(swigjobj);
}

void SwigDirector_Callback::on_pager_status2(pjsua_call_id call_id, pj_str_t const *to, pj_str_t const *body, pjsip_status_code status, pj_str_t const *reason, pjsip_tx_data *tdata, pjsip_rx_data *rdata) {
  JNIEnvWrapper swigjnienv(this) ;
  JNIEnv * jenv = swigjnienv.getJNIEnv() ;
  jobject swigjobj = (jobject) NULL ;
  jint jcall_id  ;
  jlong jto = 0 ;
  jlong jbody = 0 ;
  jint jstatus  ;
  jlong jreason = 0 ;
  jlong jtdata = 0 ;
  jlong jrdata = 0 ;
  
  if (!swig_override[16]) {
    Callback::on_pager_status2(call_id,to,body,status,reason,tdata,rdata);
    return;
  }
  swigjobj = swig_get_self(jenv);
  if (swigjobj && jenv->IsSameObject(swigjobj, NULL) == JNI_FALSE) {
    jcall_id = (jint) call_id;
    *((pj_str_t **)&jto) = (pj_str_t *) to; 
    *((pj_str_t **)&jbody) = (pj_str_t *) body; 
    jstatus = (jint) status;
    *((pj_str_t **)&jreason) = (pj_str_t *) reason; 
    *((pjsip_tx_data **)&jtdata) = (pjsip_tx_data *) tdata; 
    *((pjsip_rx_data **)&jrdata) = (pjsip_rx_data *) rdata; 
    jenv->CallStaticVoidMethod(Swig::jclass_pjsuaJNI, Swig::director_methids[16], swigjobj, jcall_id, jto, jbody, jstatus, jreason, jtdata, jrdata);
    if (jenv->ExceptionOccurred()) return ;
  } else {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null upcall object");
  }
  if (swigjobj) jenv->DeleteLocalRef(swigjobj);
}

void SwigDirector_Callback::on_typing(pjsua_call_id call_id, pj_str_t const *from, pj_str_t const *to, pj_str_t const *contact, pj_bool_t is_typing) {
  JNIEnvWrapper swigjnienv(this) ;
  JNIEnv * jenv = swigjnienv.getJNIEnv() ;
  jobject swigjobj = (jobject) NULL ;
  jint jcall_id  ;
  jlong jfrom = 0 ;
  jlong jto = 0 ;
  jlong jcontact = 0 ;
  jint jis_typing  ;
  
  if (!swig_override[17]) {
    Callback::on_typing(call_id,from,to,contact,is_typing);
    return;
  }
  swigjobj = swig_get_self(jenv);
  if (swigjobj && jenv->IsSameObject(swigjobj, NULL) == JNI_FALSE) {
    jcall_id = (jint) call_id;
    *((pj_str_t **)&jfrom) = (pj_str_t *) from; 
    *((pj_str_t **)&jto) = (pj_str_t *) to; 
    *((pj_str_t **)&jcontact) = (pj_str_t *) contact; 
    jis_typing = (jint) is_typing;
    jenv->CallStaticVoidMethod(Swig::jclass_pjsuaJNI, Swig::director_methids[17], swigjobj, jcall_id, jfrom, jto, jcontact, jis_typing);
    if (jenv->ExceptionOccurred()) return ;
  } else {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null upcall object");
  }
  if (swigjobj) jenv->DeleteLocalRef(swigjobj);
}

void SwigDirector_Callback::on_nat_detect(pj_stun_nat_detect_result const *res) {
  JNIEnvWrapper swigjnienv(this) ;
  JNIEnv * jenv = swigjnienv.getJNIEnv() ;
  jobject swigjobj = (jobject) NULL ;
  jlong jres = 0 ;
  
  if (!swig_override[18]) {
    Callback::on_nat_detect(res);
    return;
  }
  swigjobj = swig_get_self(jenv);
  if (swigjobj && jenv->IsSameObject(swigjobj, NULL) == JNI_FALSE) {
    *((pj_stun_nat_detect_result **)&jres) = (pj_stun_nat_detect_result *) res; 
    jenv->CallStaticVoidMethod(Swig::jclass_pjsuaJNI, Swig::director_methids[18], swigjobj, jres);
    if (jenv->ExceptionOccurred()) return ;
  } else {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null upcall object");
  }
  if (swigjobj) jenv->DeleteLocalRef(swigjobj);
}

void SwigDirector_Callback::swig_connect_director(JNIEnv *jenv, jobject jself, jclass jcls, bool swig_mem_own, bool weak_global) {
  static struct {
    const char *mname;
    const char *mdesc;
    jmethodID base_methid;
  } methods[] = {
    {
      "on_call_state", "(ILorg/pjsip/pjsua/pjsip_event;)V", NULL 
    },
    {
      "on_incoming_call", "(IILorg/pjsip/pjsua/SWIGTYPE_p_pjsip_rx_data;)V", NULL 
    },
    {
      "on_call_tsx_state", "(ILorg/pjsip/pjsua/SWIGTYPE_p_pjsip_transaction;Lorg/pjsip/pjsua/pjsip_event;)V", NULL 
    },
    {
      "on_call_media_state", "(I)V", NULL 
    },
    {
      "on_stream_created", "(ILorg/pjsip/pjsua/SWIGTYPE_p_pjmedia_session;JLorg/pjsip/pjsua/SWIGTYPE_p_p_pjmedia_port;)V", NULL 
    },
    {
      "on_stream_destroyed", "(ILorg/pjsip/pjsua/SWIGTYPE_p_pjmedia_session;J)V", NULL 
    },
    {
      "on_dtmf_digit", "(II)V", NULL 
    },
    {
      "on_call_transfer_request", "(ILorg/pjsip/pjsua/pj_str_t;Lorg/pjsip/pjsua/SWIGTYPE_p_pjsip_status_code;)V", NULL 
    },
    {
      "on_call_transfer_status", "(IILorg/pjsip/pjsua/pj_str_t;ILorg/pjsip/pjsua/SWIGTYPE_p_int;)V", NULL 
    },
    {
      "on_call_replace_request", "(ILorg/pjsip/pjsua/SWIGTYPE_p_pjsip_rx_data;Lorg/pjsip/pjsua/SWIGTYPE_p_int;Lorg/pjsip/pjsua/pj_str_t;)V", NULL 
    },
    {
      "on_call_replaced", "(II)V", NULL 
    },
    {
      "on_reg_state", "(I)V", NULL 
    },
    {
      "on_buddy_state", "(I)V", NULL 
    },
    {
      "on_pager", "(ILorg/pjsip/pjsua/pj_str_t;Lorg/pjsip/pjsua/pj_str_t;Lorg/pjsip/pjsua/pj_str_t;Lorg/pjsip/pjsua/pj_str_t;Lorg/pjsip/pjsua/pj_str_t;)V", NULL 
    },
    {
      "on_pager2", "(ILorg/pjsip/pjsua/pj_str_t;Lorg/pjsip/pjsua/pj_str_t;Lorg/pjsip/pjsua/pj_str_t;Lorg/pjsip/pjsua/pj_str_t;Lorg/pjsip/pjsua/pj_str_t;Lorg/pjsip/pjsua/SWIGTYPE_p_pjsip_rx_data;)V", NULL 
    },
    {
      "on_pager_status", "(ILorg/pjsip/pjsua/pj_str_t;Lorg/pjsip/pjsua/pj_str_t;Lorg/pjsip/pjsua/pjsip_status_code;Lorg/pjsip/pjsua/pj_str_t;)V", NULL 
    },
    {
      "on_pager_status2", "(ILorg/pjsip/pjsua/pj_str_t;Lorg/pjsip/pjsua/pj_str_t;Lorg/pjsip/pjsua/pjsip_status_code;Lorg/pjsip/pjsua/pj_str_t;Lorg/pjsip/pjsua/SWIGTYPE_p_pjsip_tx_data;Lorg/pjsip/pjsua/SWIGTYPE_p_pjsip_rx_data;)V", NULL 
    },
    {
      "on_typing", "(ILorg/pjsip/pjsua/pj_str_t;Lorg/pjsip/pjsua/pj_str_t;Lorg/pjsip/pjsua/pj_str_t;I)V", NULL 
    },
    {
      "on_nat_detect", "(Lorg/pjsip/pjsua/SWIGTYPE_p_pj_stun_nat_detect_result;)V", NULL 
    }
  };
  
  static jclass baseclass = 0 ;
  
  if (swig_set_self(jenv, jself, swig_mem_own, weak_global)) {
    if (!baseclass) {
      baseclass = jenv->FindClass("org/pjsip/pjsua/Callback");
      if (!baseclass) return;
      baseclass = (jclass) jenv->NewGlobalRef(baseclass);
    }
    bool derived = (jenv->IsSameObject(baseclass, jcls) ? false : true);
    for (int i = 0; i < 19; ++i) {
      if (!methods[i].base_methid) {
        methods[i].base_methid = jenv->GetMethodID(baseclass, methods[i].mname, methods[i].mdesc);
        if (!methods[i].base_methid) return;
      }
      swig_override[i] = false;
      if (derived) {
        jmethodID methid = jenv->GetMethodID(jcls, methods[i].mname, methods[i].mdesc);
        swig_override[i] = (methid != methods[i].base_methid);
        jenv->ExceptionClear();
      }
    }
  }
}



#ifdef __cplusplus
extern "C" {
#endif

SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pj_1str_1copy(JNIEnv *jenv, jclass jcls, jstring jarg1) {
  jlong jresult = 0 ;
  char *arg1 = (char *) 0 ;
  pj_str_t result;
  
  (void)jenv;
  (void)jcls;
  arg1 = 0;
  if (jarg1) {
    arg1 = (char *)jenv->GetStringUTFChars(jarg1, 0);
    if (!arg1) return 0;
  }
  result = pj_str_copy((char const *)arg1);
  *(pj_str_t **)&jresult = new pj_str_t((const pj_str_t &)result); 
  if (arg1) jenv->ReleaseStringUTFChars(jarg1, (const char *)arg1);
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_delete_1Callback(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  Callback *arg1 = (Callback *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(Callback **)&jarg1; 
  delete arg1;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1call_1state(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2, jlong jarg3, jobject jarg3_) {
  Callback *arg1 = (Callback *) 0 ;
  pjsua_call_id arg2 ;
  pjsip_event *arg3 = (pjsip_event *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg3_;
  arg1 = *(Callback **)&jarg1; 
  arg2 = (pjsua_call_id)jarg2; 
  arg3 = *(pjsip_event **)&jarg3; 
  (arg1)->on_call_state(arg2,arg3);
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1call_1stateSwigExplicitCallback(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2, jlong jarg3, jobject jarg3_) {
  Callback *arg1 = (Callback *) 0 ;
  pjsua_call_id arg2 ;
  pjsip_event *arg3 = (pjsip_event *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg3_;
  arg1 = *(Callback **)&jarg1; 
  arg2 = (pjsua_call_id)jarg2; 
  arg3 = *(pjsip_event **)&jarg3; 
  (arg1)->Callback::on_call_state(arg2,arg3);
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1incoming_1call(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2, jint jarg3, jlong jarg4) {
  Callback *arg1 = (Callback *) 0 ;
  pjsua_acc_id arg2 ;
  pjsua_call_id arg3 ;
  pjsip_rx_data *arg4 = (pjsip_rx_data *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(Callback **)&jarg1; 
  arg2 = (pjsua_acc_id)jarg2; 
  arg3 = (pjsua_call_id)jarg3; 
  arg4 = *(pjsip_rx_data **)&jarg4; 
  (arg1)->on_incoming_call(arg2,arg3,arg4);
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1incoming_1callSwigExplicitCallback(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2, jint jarg3, jlong jarg4) {
  Callback *arg1 = (Callback *) 0 ;
  pjsua_acc_id arg2 ;
  pjsua_call_id arg3 ;
  pjsip_rx_data *arg4 = (pjsip_rx_data *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(Callback **)&jarg1; 
  arg2 = (pjsua_acc_id)jarg2; 
  arg3 = (pjsua_call_id)jarg3; 
  arg4 = *(pjsip_rx_data **)&jarg4; 
  (arg1)->Callback::on_incoming_call(arg2,arg3,arg4);
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1call_1tsx_1state(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2, jlong jarg3, jlong jarg4, jobject jarg4_) {
  Callback *arg1 = (Callback *) 0 ;
  pjsua_call_id arg2 ;
  pjsip_transaction *arg3 = (pjsip_transaction *) 0 ;
  pjsip_event *arg4 = (pjsip_event *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg4_;
  arg1 = *(Callback **)&jarg1; 
  arg2 = (pjsua_call_id)jarg2; 
  arg3 = *(pjsip_transaction **)&jarg3; 
  arg4 = *(pjsip_event **)&jarg4; 
  (arg1)->on_call_tsx_state(arg2,arg3,arg4);
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1call_1tsx_1stateSwigExplicitCallback(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2, jlong jarg3, jlong jarg4, jobject jarg4_) {
  Callback *arg1 = (Callback *) 0 ;
  pjsua_call_id arg2 ;
  pjsip_transaction *arg3 = (pjsip_transaction *) 0 ;
  pjsip_event *arg4 = (pjsip_event *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg4_;
  arg1 = *(Callback **)&jarg1; 
  arg2 = (pjsua_call_id)jarg2; 
  arg3 = *(pjsip_transaction **)&jarg3; 
  arg4 = *(pjsip_event **)&jarg4; 
  (arg1)->Callback::on_call_tsx_state(arg2,arg3,arg4);
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1call_1media_1state(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  Callback *arg1 = (Callback *) 0 ;
  pjsua_call_id arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(Callback **)&jarg1; 
  arg2 = (pjsua_call_id)jarg2; 
  (arg1)->on_call_media_state(arg2);
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1call_1media_1stateSwigExplicitCallback(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  Callback *arg1 = (Callback *) 0 ;
  pjsua_call_id arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(Callback **)&jarg1; 
  arg2 = (pjsua_call_id)jarg2; 
  (arg1)->Callback::on_call_media_state(arg2);
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1stream_1created(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2, jlong jarg3, jlong jarg4, jlong jarg5) {
  Callback *arg1 = (Callback *) 0 ;
  pjsua_call_id arg2 ;
  pjmedia_session *arg3 = (pjmedia_session *) 0 ;
  unsigned int arg4 ;
  pjmedia_port **arg5 = (pjmedia_port **) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(Callback **)&jarg1; 
  arg2 = (pjsua_call_id)jarg2; 
  arg3 = *(pjmedia_session **)&jarg3; 
  arg4 = (unsigned int)jarg4; 
  arg5 = *(pjmedia_port ***)&jarg5; 
  (arg1)->on_stream_created(arg2,arg3,arg4,arg5);
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1stream_1createdSwigExplicitCallback(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2, jlong jarg3, jlong jarg4, jlong jarg5) {
  Callback *arg1 = (Callback *) 0 ;
  pjsua_call_id arg2 ;
  pjmedia_session *arg3 = (pjmedia_session *) 0 ;
  unsigned int arg4 ;
  pjmedia_port **arg5 = (pjmedia_port **) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(Callback **)&jarg1; 
  arg2 = (pjsua_call_id)jarg2; 
  arg3 = *(pjmedia_session **)&jarg3; 
  arg4 = (unsigned int)jarg4; 
  arg5 = *(pjmedia_port ***)&jarg5; 
  (arg1)->Callback::on_stream_created(arg2,arg3,arg4,arg5);
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1stream_1destroyed(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2, jlong jarg3, jlong jarg4) {
  Callback *arg1 = (Callback *) 0 ;
  pjsua_call_id arg2 ;
  pjmedia_session *arg3 = (pjmedia_session *) 0 ;
  unsigned int arg4 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(Callback **)&jarg1; 
  arg2 = (pjsua_call_id)jarg2; 
  arg3 = *(pjmedia_session **)&jarg3; 
  arg4 = (unsigned int)jarg4; 
  (arg1)->on_stream_destroyed(arg2,arg3,arg4);
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1stream_1destroyedSwigExplicitCallback(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2, jlong jarg3, jlong jarg4) {
  Callback *arg1 = (Callback *) 0 ;
  pjsua_call_id arg2 ;
  pjmedia_session *arg3 = (pjmedia_session *) 0 ;
  unsigned int arg4 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(Callback **)&jarg1; 
  arg2 = (pjsua_call_id)jarg2; 
  arg3 = *(pjmedia_session **)&jarg3; 
  arg4 = (unsigned int)jarg4; 
  (arg1)->Callback::on_stream_destroyed(arg2,arg3,arg4);
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1dtmf_1digit(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2, jint jarg3) {
  Callback *arg1 = (Callback *) 0 ;
  pjsua_call_id arg2 ;
  int arg3 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(Callback **)&jarg1; 
  arg2 = (pjsua_call_id)jarg2; 
  arg3 = (int)jarg3; 
  (arg1)->on_dtmf_digit(arg2,arg3);
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1dtmf_1digitSwigExplicitCallback(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2, jint jarg3) {
  Callback *arg1 = (Callback *) 0 ;
  pjsua_call_id arg2 ;
  int arg3 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(Callback **)&jarg1; 
  arg2 = (pjsua_call_id)jarg2; 
  arg3 = (int)jarg3; 
  (arg1)->Callback::on_dtmf_digit(arg2,arg3);
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1call_1transfer_1request(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2, jlong jarg3, jobject jarg3_, jlong jarg4) {
  Callback *arg1 = (Callback *) 0 ;
  pjsua_call_id arg2 ;
  pj_str_t *arg3 = (pj_str_t *) 0 ;
  pjsip_status_code *arg4 = (pjsip_status_code *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg3_;
  arg1 = *(Callback **)&jarg1; 
  arg2 = (pjsua_call_id)jarg2; 
  arg3 = *(pj_str_t **)&jarg3; 
  arg4 = *(pjsip_status_code **)&jarg4; 
  (arg1)->on_call_transfer_request(arg2,(pj_str_t const *)arg3,arg4);
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1call_1transfer_1requestSwigExplicitCallback(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2, jlong jarg3, jobject jarg3_, jlong jarg4) {
  Callback *arg1 = (Callback *) 0 ;
  pjsua_call_id arg2 ;
  pj_str_t *arg3 = (pj_str_t *) 0 ;
  pjsip_status_code *arg4 = (pjsip_status_code *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg3_;
  arg1 = *(Callback **)&jarg1; 
  arg2 = (pjsua_call_id)jarg2; 
  arg3 = *(pj_str_t **)&jarg3; 
  arg4 = *(pjsip_status_code **)&jarg4; 
  (arg1)->Callback::on_call_transfer_request(arg2,(pj_str_t const *)arg3,arg4);
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1call_1transfer_1status(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2, jint jarg3, jlong jarg4, jobject jarg4_, jint jarg5, jlong jarg6) {
  Callback *arg1 = (Callback *) 0 ;
  pjsua_call_id arg2 ;
  int arg3 ;
  pj_str_t *arg4 = (pj_str_t *) 0 ;
  pj_bool_t arg5 ;
  pj_bool_t *arg6 = (pj_bool_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg4_;
  arg1 = *(Callback **)&jarg1; 
  arg2 = (pjsua_call_id)jarg2; 
  arg3 = (int)jarg3; 
  arg4 = *(pj_str_t **)&jarg4; 
  arg5 = (pj_bool_t)jarg5; 
  arg6 = *(pj_bool_t **)&jarg6; 
  (arg1)->on_call_transfer_status(arg2,arg3,(pj_str_t const *)arg4,arg5,arg6);
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1call_1transfer_1statusSwigExplicitCallback(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2, jint jarg3, jlong jarg4, jobject jarg4_, jint jarg5, jlong jarg6) {
  Callback *arg1 = (Callback *) 0 ;
  pjsua_call_id arg2 ;
  int arg3 ;
  pj_str_t *arg4 = (pj_str_t *) 0 ;
  pj_bool_t arg5 ;
  pj_bool_t *arg6 = (pj_bool_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg4_;
  arg1 = *(Callback **)&jarg1; 
  arg2 = (pjsua_call_id)jarg2; 
  arg3 = (int)jarg3; 
  arg4 = *(pj_str_t **)&jarg4; 
  arg5 = (pj_bool_t)jarg5; 
  arg6 = *(pj_bool_t **)&jarg6; 
  (arg1)->Callback::on_call_transfer_status(arg2,arg3,(pj_str_t const *)arg4,arg5,arg6);
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1call_1replace_1request(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2, jlong jarg3, jlong jarg4, jlong jarg5, jobject jarg5_) {
  Callback *arg1 = (Callback *) 0 ;
  pjsua_call_id arg2 ;
  pjsip_rx_data *arg3 = (pjsip_rx_data *) 0 ;
  int *arg4 = (int *) 0 ;
  pj_str_t *arg5 = (pj_str_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg5_;
  arg1 = *(Callback **)&jarg1; 
  arg2 = (pjsua_call_id)jarg2; 
  arg3 = *(pjsip_rx_data **)&jarg3; 
  arg4 = *(int **)&jarg4; 
  arg5 = *(pj_str_t **)&jarg5; 
  (arg1)->on_call_replace_request(arg2,arg3,arg4,arg5);
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1call_1replace_1requestSwigExplicitCallback(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2, jlong jarg3, jlong jarg4, jlong jarg5, jobject jarg5_) {
  Callback *arg1 = (Callback *) 0 ;
  pjsua_call_id arg2 ;
  pjsip_rx_data *arg3 = (pjsip_rx_data *) 0 ;
  int *arg4 = (int *) 0 ;
  pj_str_t *arg5 = (pj_str_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg5_;
  arg1 = *(Callback **)&jarg1; 
  arg2 = (pjsua_call_id)jarg2; 
  arg3 = *(pjsip_rx_data **)&jarg3; 
  arg4 = *(int **)&jarg4; 
  arg5 = *(pj_str_t **)&jarg5; 
  (arg1)->Callback::on_call_replace_request(arg2,arg3,arg4,arg5);
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1call_1replaced(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2, jint jarg3) {
  Callback *arg1 = (Callback *) 0 ;
  pjsua_call_id arg2 ;
  pjsua_call_id arg3 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(Callback **)&jarg1; 
  arg2 = (pjsua_call_id)jarg2; 
  arg3 = (pjsua_call_id)jarg3; 
  (arg1)->on_call_replaced(arg2,arg3);
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1call_1replacedSwigExplicitCallback(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2, jint jarg3) {
  Callback *arg1 = (Callback *) 0 ;
  pjsua_call_id arg2 ;
  pjsua_call_id arg3 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(Callback **)&jarg1; 
  arg2 = (pjsua_call_id)jarg2; 
  arg3 = (pjsua_call_id)jarg3; 
  (arg1)->Callback::on_call_replaced(arg2,arg3);
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1reg_1state(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  Callback *arg1 = (Callback *) 0 ;
  pjsua_acc_id arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(Callback **)&jarg1; 
  arg2 = (pjsua_acc_id)jarg2; 
  (arg1)->on_reg_state(arg2);
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1reg_1stateSwigExplicitCallback(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  Callback *arg1 = (Callback *) 0 ;
  pjsua_acc_id arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(Callback **)&jarg1; 
  arg2 = (pjsua_acc_id)jarg2; 
  (arg1)->Callback::on_reg_state(arg2);
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1buddy_1state(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  Callback *arg1 = (Callback *) 0 ;
  pjsua_buddy_id arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(Callback **)&jarg1; 
  arg2 = (pjsua_buddy_id)jarg2; 
  (arg1)->on_buddy_state(arg2);
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1buddy_1stateSwigExplicitCallback(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  Callback *arg1 = (Callback *) 0 ;
  pjsua_buddy_id arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(Callback **)&jarg1; 
  arg2 = (pjsua_buddy_id)jarg2; 
  (arg1)->Callback::on_buddy_state(arg2);
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1pager(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2, jlong jarg3, jobject jarg3_, jlong jarg4, jobject jarg4_, jlong jarg5, jobject jarg5_, jlong jarg6, jobject jarg6_, jlong jarg7, jobject jarg7_) {
  Callback *arg1 = (Callback *) 0 ;
  pjsua_call_id arg2 ;
  pj_str_t *arg3 = (pj_str_t *) 0 ;
  pj_str_t *arg4 = (pj_str_t *) 0 ;
  pj_str_t *arg5 = (pj_str_t *) 0 ;
  pj_str_t *arg6 = (pj_str_t *) 0 ;
  pj_str_t *arg7 = (pj_str_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg3_;
  (void)jarg4_;
  (void)jarg5_;
  (void)jarg6_;
  (void)jarg7_;
  arg1 = *(Callback **)&jarg1; 
  arg2 = (pjsua_call_id)jarg2; 
  arg3 = *(pj_str_t **)&jarg3; 
  arg4 = *(pj_str_t **)&jarg4; 
  arg5 = *(pj_str_t **)&jarg5; 
  arg6 = *(pj_str_t **)&jarg6; 
  arg7 = *(pj_str_t **)&jarg7; 
  (arg1)->on_pager(arg2,(pj_str_t const *)arg3,(pj_str_t const *)arg4,(pj_str_t const *)arg5,(pj_str_t const *)arg6,(pj_str_t const *)arg7);
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1pagerSwigExplicitCallback(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2, jlong jarg3, jobject jarg3_, jlong jarg4, jobject jarg4_, jlong jarg5, jobject jarg5_, jlong jarg6, jobject jarg6_, jlong jarg7, jobject jarg7_) {
  Callback *arg1 = (Callback *) 0 ;
  pjsua_call_id arg2 ;
  pj_str_t *arg3 = (pj_str_t *) 0 ;
  pj_str_t *arg4 = (pj_str_t *) 0 ;
  pj_str_t *arg5 = (pj_str_t *) 0 ;
  pj_str_t *arg6 = (pj_str_t *) 0 ;
  pj_str_t *arg7 = (pj_str_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg3_;
  (void)jarg4_;
  (void)jarg5_;
  (void)jarg6_;
  (void)jarg7_;
  arg1 = *(Callback **)&jarg1; 
  arg2 = (pjsua_call_id)jarg2; 
  arg3 = *(pj_str_t **)&jarg3; 
  arg4 = *(pj_str_t **)&jarg4; 
  arg5 = *(pj_str_t **)&jarg5; 
  arg6 = *(pj_str_t **)&jarg6; 
  arg7 = *(pj_str_t **)&jarg7; 
  (arg1)->Callback::on_pager(arg2,(pj_str_t const *)arg3,(pj_str_t const *)arg4,(pj_str_t const *)arg5,(pj_str_t const *)arg6,(pj_str_t const *)arg7);
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1pager2(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2, jlong jarg3, jobject jarg3_, jlong jarg4, jobject jarg4_, jlong jarg5, jobject jarg5_, jlong jarg6, jobject jarg6_, jlong jarg7, jobject jarg7_, jlong jarg8) {
  Callback *arg1 = (Callback *) 0 ;
  pjsua_call_id arg2 ;
  pj_str_t *arg3 = (pj_str_t *) 0 ;
  pj_str_t *arg4 = (pj_str_t *) 0 ;
  pj_str_t *arg5 = (pj_str_t *) 0 ;
  pj_str_t *arg6 = (pj_str_t *) 0 ;
  pj_str_t *arg7 = (pj_str_t *) 0 ;
  pjsip_rx_data *arg8 = (pjsip_rx_data *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg3_;
  (void)jarg4_;
  (void)jarg5_;
  (void)jarg6_;
  (void)jarg7_;
  arg1 = *(Callback **)&jarg1; 
  arg2 = (pjsua_call_id)jarg2; 
  arg3 = *(pj_str_t **)&jarg3; 
  arg4 = *(pj_str_t **)&jarg4; 
  arg5 = *(pj_str_t **)&jarg5; 
  arg6 = *(pj_str_t **)&jarg6; 
  arg7 = *(pj_str_t **)&jarg7; 
  arg8 = *(pjsip_rx_data **)&jarg8; 
  (arg1)->on_pager2(arg2,(pj_str_t const *)arg3,(pj_str_t const *)arg4,(pj_str_t const *)arg5,(pj_str_t const *)arg6,(pj_str_t const *)arg7,arg8);
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1pager2SwigExplicitCallback(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2, jlong jarg3, jobject jarg3_, jlong jarg4, jobject jarg4_, jlong jarg5, jobject jarg5_, jlong jarg6, jobject jarg6_, jlong jarg7, jobject jarg7_, jlong jarg8) {
  Callback *arg1 = (Callback *) 0 ;
  pjsua_call_id arg2 ;
  pj_str_t *arg3 = (pj_str_t *) 0 ;
  pj_str_t *arg4 = (pj_str_t *) 0 ;
  pj_str_t *arg5 = (pj_str_t *) 0 ;
  pj_str_t *arg6 = (pj_str_t *) 0 ;
  pj_str_t *arg7 = (pj_str_t *) 0 ;
  pjsip_rx_data *arg8 = (pjsip_rx_data *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg3_;
  (void)jarg4_;
  (void)jarg5_;
  (void)jarg6_;
  (void)jarg7_;
  arg1 = *(Callback **)&jarg1; 
  arg2 = (pjsua_call_id)jarg2; 
  arg3 = *(pj_str_t **)&jarg3; 
  arg4 = *(pj_str_t **)&jarg4; 
  arg5 = *(pj_str_t **)&jarg5; 
  arg6 = *(pj_str_t **)&jarg6; 
  arg7 = *(pj_str_t **)&jarg7; 
  arg8 = *(pjsip_rx_data **)&jarg8; 
  (arg1)->Callback::on_pager2(arg2,(pj_str_t const *)arg3,(pj_str_t const *)arg4,(pj_str_t const *)arg5,(pj_str_t const *)arg6,(pj_str_t const *)arg7,arg8);
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1pager_1status(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2, jlong jarg3, jobject jarg3_, jlong jarg4, jobject jarg4_, jint jarg5, jlong jarg6, jobject jarg6_) {
  Callback *arg1 = (Callback *) 0 ;
  pjsua_call_id arg2 ;
  pj_str_t *arg3 = (pj_str_t *) 0 ;
  pj_str_t *arg4 = (pj_str_t *) 0 ;
  pjsip_status_code arg5 ;
  pj_str_t *arg6 = (pj_str_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg3_;
  (void)jarg4_;
  (void)jarg6_;
  arg1 = *(Callback **)&jarg1; 
  arg2 = (pjsua_call_id)jarg2; 
  arg3 = *(pj_str_t **)&jarg3; 
  arg4 = *(pj_str_t **)&jarg4; 
  arg5 = (pjsip_status_code)jarg5; 
  arg6 = *(pj_str_t **)&jarg6; 
  (arg1)->on_pager_status(arg2,(pj_str_t const *)arg3,(pj_str_t const *)arg4,arg5,(pj_str_t const *)arg6);
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1pager_1statusSwigExplicitCallback(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2, jlong jarg3, jobject jarg3_, jlong jarg4, jobject jarg4_, jint jarg5, jlong jarg6, jobject jarg6_) {
  Callback *arg1 = (Callback *) 0 ;
  pjsua_call_id arg2 ;
  pj_str_t *arg3 = (pj_str_t *) 0 ;
  pj_str_t *arg4 = (pj_str_t *) 0 ;
  pjsip_status_code arg5 ;
  pj_str_t *arg6 = (pj_str_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg3_;
  (void)jarg4_;
  (void)jarg6_;
  arg1 = *(Callback **)&jarg1; 
  arg2 = (pjsua_call_id)jarg2; 
  arg3 = *(pj_str_t **)&jarg3; 
  arg4 = *(pj_str_t **)&jarg4; 
  arg5 = (pjsip_status_code)jarg5; 
  arg6 = *(pj_str_t **)&jarg6; 
  (arg1)->Callback::on_pager_status(arg2,(pj_str_t const *)arg3,(pj_str_t const *)arg4,arg5,(pj_str_t const *)arg6);
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1pager_1status2(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2, jlong jarg3, jobject jarg3_, jlong jarg4, jobject jarg4_, jint jarg5, jlong jarg6, jobject jarg6_, jlong jarg7, jlong jarg8) {
  Callback *arg1 = (Callback *) 0 ;
  pjsua_call_id arg2 ;
  pj_str_t *arg3 = (pj_str_t *) 0 ;
  pj_str_t *arg4 = (pj_str_t *) 0 ;
  pjsip_status_code arg5 ;
  pj_str_t *arg6 = (pj_str_t *) 0 ;
  pjsip_tx_data *arg7 = (pjsip_tx_data *) 0 ;
  pjsip_rx_data *arg8 = (pjsip_rx_data *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg3_;
  (void)jarg4_;
  (void)jarg6_;
  arg1 = *(Callback **)&jarg1; 
  arg2 = (pjsua_call_id)jarg2; 
  arg3 = *(pj_str_t **)&jarg3; 
  arg4 = *(pj_str_t **)&jarg4; 
  arg5 = (pjsip_status_code)jarg5; 
  arg6 = *(pj_str_t **)&jarg6; 
  arg7 = *(pjsip_tx_data **)&jarg7; 
  arg8 = *(pjsip_rx_data **)&jarg8; 
  (arg1)->on_pager_status2(arg2,(pj_str_t const *)arg3,(pj_str_t const *)arg4,arg5,(pj_str_t const *)arg6,arg7,arg8);
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1pager_1status2SwigExplicitCallback(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2, jlong jarg3, jobject jarg3_, jlong jarg4, jobject jarg4_, jint jarg5, jlong jarg6, jobject jarg6_, jlong jarg7, jlong jarg8) {
  Callback *arg1 = (Callback *) 0 ;
  pjsua_call_id arg2 ;
  pj_str_t *arg3 = (pj_str_t *) 0 ;
  pj_str_t *arg4 = (pj_str_t *) 0 ;
  pjsip_status_code arg5 ;
  pj_str_t *arg6 = (pj_str_t *) 0 ;
  pjsip_tx_data *arg7 = (pjsip_tx_data *) 0 ;
  pjsip_rx_data *arg8 = (pjsip_rx_data *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg3_;
  (void)jarg4_;
  (void)jarg6_;
  arg1 = *(Callback **)&jarg1; 
  arg2 = (pjsua_call_id)jarg2; 
  arg3 = *(pj_str_t **)&jarg3; 
  arg4 = *(pj_str_t **)&jarg4; 
  arg5 = (pjsip_status_code)jarg5; 
  arg6 = *(pj_str_t **)&jarg6; 
  arg7 = *(pjsip_tx_data **)&jarg7; 
  arg8 = *(pjsip_rx_data **)&jarg8; 
  (arg1)->Callback::on_pager_status2(arg2,(pj_str_t const *)arg3,(pj_str_t const *)arg4,arg5,(pj_str_t const *)arg6,arg7,arg8);
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1typing(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2, jlong jarg3, jobject jarg3_, jlong jarg4, jobject jarg4_, jlong jarg5, jobject jarg5_, jint jarg6) {
  Callback *arg1 = (Callback *) 0 ;
  pjsua_call_id arg2 ;
  pj_str_t *arg3 = (pj_str_t *) 0 ;
  pj_str_t *arg4 = (pj_str_t *) 0 ;
  pj_str_t *arg5 = (pj_str_t *) 0 ;
  pj_bool_t arg6 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg3_;
  (void)jarg4_;
  (void)jarg5_;
  arg1 = *(Callback **)&jarg1; 
  arg2 = (pjsua_call_id)jarg2; 
  arg3 = *(pj_str_t **)&jarg3; 
  arg4 = *(pj_str_t **)&jarg4; 
  arg5 = *(pj_str_t **)&jarg5; 
  arg6 = (pj_bool_t)jarg6; 
  (arg1)->on_typing(arg2,(pj_str_t const *)arg3,(pj_str_t const *)arg4,(pj_str_t const *)arg5,arg6);
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1typingSwigExplicitCallback(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2, jlong jarg3, jobject jarg3_, jlong jarg4, jobject jarg4_, jlong jarg5, jobject jarg5_, jint jarg6) {
  Callback *arg1 = (Callback *) 0 ;
  pjsua_call_id arg2 ;
  pj_str_t *arg3 = (pj_str_t *) 0 ;
  pj_str_t *arg4 = (pj_str_t *) 0 ;
  pj_str_t *arg5 = (pj_str_t *) 0 ;
  pj_bool_t arg6 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg3_;
  (void)jarg4_;
  (void)jarg5_;
  arg1 = *(Callback **)&jarg1; 
  arg2 = (pjsua_call_id)jarg2; 
  arg3 = *(pj_str_t **)&jarg3; 
  arg4 = *(pj_str_t **)&jarg4; 
  arg5 = *(pj_str_t **)&jarg5; 
  arg6 = (pj_bool_t)jarg6; 
  (arg1)->Callback::on_typing(arg2,(pj_str_t const *)arg3,(pj_str_t const *)arg4,(pj_str_t const *)arg5,arg6);
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1nat_1detect(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  Callback *arg1 = (Callback *) 0 ;
  pj_stun_nat_detect_result *arg2 = (pj_stun_nat_detect_result *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(Callback **)&jarg1; 
  arg2 = *(pj_stun_nat_detect_result **)&jarg2; 
  (arg1)->on_nat_detect((pj_stun_nat_detect_result const *)arg2);
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1nat_1detectSwigExplicitCallback(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  Callback *arg1 = (Callback *) 0 ;
  pj_stun_nat_detect_result *arg2 = (pj_stun_nat_detect_result *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(Callback **)&jarg1; 
  arg2 = *(pj_stun_nat_detect_result **)&jarg2; 
  (arg1)->Callback::on_nat_detect((pj_stun_nat_detect_result const *)arg2);
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_new_1Callback(JNIEnv *jenv, jclass jcls) {
  jlong jresult = 0 ;
  Callback *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  result = (Callback *)new SwigDirector_Callback(jenv);
  *(Callback **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_Callback_1director_1connect(JNIEnv *jenv, jclass jcls, jobject jself, jlong objarg, jboolean jswig_mem_own, jboolean jweak_global) {
  Callback *obj = *((Callback **)&objarg);
  (void)jcls;
  SwigDirector_Callback *director = (SwigDirector_Callback*)(obj);
  if (director) {
    director->swig_connect_director(jenv, jself, jenv->GetObjectClass(jself), (jswig_mem_own == JNI_TRUE), (jweak_global == JNI_TRUE));
  }
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_Callback_1change_1ownership(JNIEnv *jenv, jclass jcls, jobject jself, jlong objarg, jboolean jtake_or_release) {
  Callback *obj = *((Callback **)&objarg);
  SwigDirector_Callback *director = (SwigDirector_Callback*)(obj);
  (void)jcls;
  if (director) {
    director->swig_java_change_ownership(jenv, jself, jtake_or_release ? true : false);
  }
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_WRAPPER_1CALLBACK_1STRUCT_1get(JNIEnv *jenv, jclass jcls) {
  jlong jresult = 0 ;
  struct pjsua_callback *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  result = (struct pjsua_callback *)(&wrapper_callback_struct);
  *(struct pjsua_callback **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_setCallbackObject(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  Callback *arg1 = (Callback *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(Callback **)&jarg1; 
  setCallbackObject(arg1);
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJ_1SUCCESS_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  result = (int)(0);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJ_1TRUE_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  result = (int)(1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJ_1FALSE_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  result = (int)(0);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pj_1str_1t_1ptr_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jstring jarg2) {
  pj_str_t *arg1 = (pj_str_t *) 0 ;
  char *arg2 = (char *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pj_str_t **)&jarg1; 
  arg2 = 0;
  if (jarg2) {
    arg2 = (char *)jenv->GetStringUTFChars(jarg2, 0);
    if (!arg2) return ;
  }
  {
    if (arg1->ptr) delete [] arg1->ptr;
    if (arg2) {
      arg1->ptr = (char *) (new char[strlen((const char *)arg2)+1]);
      strcpy((char *)arg1->ptr, (const char *)arg2);
    } else {
      arg1->ptr = 0;
    }
  }
  if (arg2) jenv->ReleaseStringUTFChars(jarg2, (const char *)arg2);
}


SWIGEXPORT jstring JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pj_1str_1t_1ptr_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jstring jresult = 0 ;
  pj_str_t *arg1 = (pj_str_t *) 0 ;
  char *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pj_str_t **)&jarg1; 
  result = (char *) ((arg1)->ptr);
  if (result) jresult = jenv->NewStringUTF((const char *)result);
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pj_1str_1t_1slen_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pj_str_t *arg1 = (pj_str_t *) 0 ;
  pj_ssize_t arg2 ;
  pj_ssize_t *argp2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pj_str_t **)&jarg1; 
  argp2 = *(pj_ssize_t **)&jarg2; 
  if (!argp2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null pj_ssize_t");
    return ;
  }
  arg2 = *argp2; 
  if (arg1) (arg1)->slen = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pj_1str_1t_1slen_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pj_str_t *arg1 = (pj_str_t *) 0 ;
  pj_ssize_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pj_str_t **)&jarg1; 
  result =  ((arg1)->slen);
  *(pj_ssize_t **)&jresult = new pj_ssize_t((const pj_ssize_t &)result); 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_new_1pj_1str_1t(JNIEnv *jenv, jclass jcls) {
  jlong jresult = 0 ;
  pj_str_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  result = (pj_str_t *)new pj_str_t();
  *(pj_str_t **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_delete_1pj_1str_1t(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  pj_str_t *arg1 = (pj_str_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(pj_str_t **)&jarg1; 
  delete arg1;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1info_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_) {
  pjmedia_port *arg1 = (pjmedia_port *) 0 ;
  pjmedia_port_info *arg2 = (pjmedia_port_info *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(pjmedia_port **)&jarg1; 
  arg2 = *(pjmedia_port_info **)&jarg2; 
  if (arg1) (arg1)->info = *arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1info_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjmedia_port *arg1 = (pjmedia_port *) 0 ;
  pjmedia_port_info *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjmedia_port **)&jarg1; 
  result = (pjmedia_port_info *)& ((arg1)->info);
  *(pjmedia_port_info **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1put_1frame_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjmedia_port *arg1 = (pjmedia_port *) 0 ;
  pj_status_t (*arg2)(pjmedia_port *,pjmedia_frame const *) = (pj_status_t (*)(pjmedia_port *,pjmedia_frame const *)) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjmedia_port **)&jarg1; 
  arg2 = *(pj_status_t (**)(pjmedia_port *,pjmedia_frame const *))&jarg2; 
  if (arg1) (arg1)->put_frame = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1put_1frame_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjmedia_port *arg1 = (pjmedia_port *) 0 ;
  pj_status_t (*result)(pjmedia_port *,pjmedia_frame const *) = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjmedia_port **)&jarg1; 
  result = (pj_status_t (*)(pjmedia_port *,pjmedia_frame const *)) ((arg1)->put_frame);
  *(pj_status_t (**)(pjmedia_port *,pjmedia_frame const *))&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1get_1frame_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjmedia_port *arg1 = (pjmedia_port *) 0 ;
  pj_status_t (*arg2)(pjmedia_port *,pjmedia_frame *) = (pj_status_t (*)(pjmedia_port *,pjmedia_frame *)) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjmedia_port **)&jarg1; 
  arg2 = *(pj_status_t (**)(pjmedia_port *,pjmedia_frame *))&jarg2; 
  if (arg1) (arg1)->get_frame = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1get_1frame_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjmedia_port *arg1 = (pjmedia_port *) 0 ;
  pj_status_t (*result)(pjmedia_port *,pjmedia_frame *) = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjmedia_port **)&jarg1; 
  result = (pj_status_t (*)(pjmedia_port *,pjmedia_frame *)) ((arg1)->get_frame);
  *(pj_status_t (**)(pjmedia_port *,pjmedia_frame *))&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1on_1destroy_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjmedia_port *arg1 = (pjmedia_port *) 0 ;
  pj_status_t (*arg2)(pjmedia_port *) = (pj_status_t (*)(pjmedia_port *)) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjmedia_port **)&jarg1; 
  arg2 = *(pj_status_t (**)(pjmedia_port *))&jarg2; 
  if (arg1) (arg1)->on_destroy = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1on_1destroy_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjmedia_port *arg1 = (pjmedia_port *) 0 ;
  pj_status_t (*result)(pjmedia_port *) = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjmedia_port **)&jarg1; 
  result = (pj_status_t (*)(pjmedia_port *)) ((arg1)->on_destroy);
  *(pj_status_t (**)(pjmedia_port *))&jresult = result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJMEDIA_1DIR_1NONE_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjmedia_dir result;
  
  (void)jenv;
  (void)jcls;
  result = (pjmedia_dir)PJMEDIA_DIR_NONE;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJMEDIA_1DIR_1ENCODING_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjmedia_dir result;
  
  (void)jenv;
  (void)jcls;
  result = (pjmedia_dir)PJMEDIA_DIR_ENCODING;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJMEDIA_1DIR_1DECODING_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjmedia_dir result;
  
  (void)jenv;
  (void)jcls;
  result = (pjmedia_dir)PJMEDIA_DIR_DECODING;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJMEDIA_1DIR_1ENCODING_1DECODING_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjmedia_dir result;
  
  (void)jenv;
  (void)jcls;
  result = (pjmedia_dir)PJMEDIA_DIR_ENCODING_DECODING;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1info_1name_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_) {
  pjmedia_port_info *arg1 = (pjmedia_port_info *) 0 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(pjmedia_port_info **)&jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  if (arg1) (arg1)->name = *arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1info_1name_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjmedia_port_info *arg1 = (pjmedia_port_info *) 0 ;
  pj_str_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjmedia_port_info **)&jarg1; 
  result = (pj_str_t *)& ((arg1)->name);
  *(pj_str_t **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1info_1signature_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjmedia_port_info *arg1 = (pjmedia_port_info *) 0 ;
  pj_uint32_t arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjmedia_port_info **)&jarg1; 
  arg2 = (pj_uint32_t)jarg2; 
  if (arg1) (arg1)->signature = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1info_1signature_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjmedia_port_info *arg1 = (pjmedia_port_info *) 0 ;
  pj_uint32_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjmedia_port_info **)&jarg1; 
  result = (pj_uint32_t) ((arg1)->signature);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1info_1type_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjmedia_port_info *arg1 = (pjmedia_port_info *) 0 ;
  pjmedia_type arg2 ;
  pjmedia_type *argp2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjmedia_port_info **)&jarg1; 
  argp2 = *(pjmedia_type **)&jarg2; 
  if (!argp2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null pjmedia_type");
    return ;
  }
  arg2 = *argp2; 
  if (arg1) (arg1)->type = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1info_1type_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjmedia_port_info *arg1 = (pjmedia_port_info *) 0 ;
  pjmedia_type result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjmedia_port_info **)&jarg1; 
  result =  ((arg1)->type);
  *(pjmedia_type **)&jresult = new pjmedia_type((const pjmedia_type &)result); 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1info_1has_1info_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjmedia_port_info *arg1 = (pjmedia_port_info *) 0 ;
  pj_bool_t arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjmedia_port_info **)&jarg1; 
  arg2 = (pj_bool_t)jarg2; 
  if (arg1) (arg1)->has_info = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1info_1has_1info_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjmedia_port_info *arg1 = (pjmedia_port_info *) 0 ;
  pj_bool_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjmedia_port_info **)&jarg1; 
  result = (pj_bool_t) ((arg1)->has_info);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1info_1need_1info_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjmedia_port_info *arg1 = (pjmedia_port_info *) 0 ;
  pj_bool_t arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjmedia_port_info **)&jarg1; 
  arg2 = (pj_bool_t)jarg2; 
  if (arg1) (arg1)->need_info = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1info_1need_1info_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjmedia_port_info *arg1 = (pjmedia_port_info *) 0 ;
  pj_bool_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjmedia_port_info **)&jarg1; 
  result = (pj_bool_t) ((arg1)->need_info);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1info_1pt_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjmedia_port_info *arg1 = (pjmedia_port_info *) 0 ;
  unsigned int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjmedia_port_info **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  if (arg1) (arg1)->pt = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1info_1pt_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjmedia_port_info *arg1 = (pjmedia_port_info *) 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjmedia_port_info **)&jarg1; 
  result = (unsigned int) ((arg1)->pt);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1info_1encoding_1name_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_) {
  pjmedia_port_info *arg1 = (pjmedia_port_info *) 0 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(pjmedia_port_info **)&jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  if (arg1) (arg1)->encoding_name = *arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1info_1encoding_1name_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjmedia_port_info *arg1 = (pjmedia_port_info *) 0 ;
  pj_str_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjmedia_port_info **)&jarg1; 
  result = (pj_str_t *)& ((arg1)->encoding_name);
  *(pj_str_t **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1info_1clock_1rate_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjmedia_port_info *arg1 = (pjmedia_port_info *) 0 ;
  unsigned int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjmedia_port_info **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  if (arg1) (arg1)->clock_rate = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1info_1clock_1rate_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjmedia_port_info *arg1 = (pjmedia_port_info *) 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjmedia_port_info **)&jarg1; 
  result = (unsigned int) ((arg1)->clock_rate);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1info_1channel_1count_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjmedia_port_info *arg1 = (pjmedia_port_info *) 0 ;
  unsigned int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjmedia_port_info **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  if (arg1) (arg1)->channel_count = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1info_1channel_1count_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjmedia_port_info *arg1 = (pjmedia_port_info *) 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjmedia_port_info **)&jarg1; 
  result = (unsigned int) ((arg1)->channel_count);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1info_1bits_1per_1sample_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjmedia_port_info *arg1 = (pjmedia_port_info *) 0 ;
  unsigned int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjmedia_port_info **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  if (arg1) (arg1)->bits_per_sample = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1info_1bits_1per_1sample_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjmedia_port_info *arg1 = (pjmedia_port_info *) 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjmedia_port_info **)&jarg1; 
  result = (unsigned int) ((arg1)->bits_per_sample);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1info_1samples_1per_1frame_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjmedia_port_info *arg1 = (pjmedia_port_info *) 0 ;
  unsigned int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjmedia_port_info **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  if (arg1) (arg1)->samples_per_frame = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1info_1samples_1per_1frame_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjmedia_port_info *arg1 = (pjmedia_port_info *) 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjmedia_port_info **)&jarg1; 
  result = (unsigned int) ((arg1)->samples_per_frame);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1info_1bytes_1per_1frame_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjmedia_port_info *arg1 = (pjmedia_port_info *) 0 ;
  unsigned int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjmedia_port_info **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  if (arg1) (arg1)->bytes_per_frame = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1info_1bytes_1per_1frame_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjmedia_port_info *arg1 = (pjmedia_port_info *) 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjmedia_port_info **)&jarg1; 
  result = (unsigned int) ((arg1)->bytes_per_frame);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_new_1pjmedia_1port_1info(JNIEnv *jenv, jclass jcls) {
  jlong jresult = 0 ;
  pjmedia_port_info *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  result = (pjmedia_port_info *)new pjmedia_port_info();
  *(pjmedia_port_info **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_delete_1pjmedia_1port_1info(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  pjmedia_port_info *arg1 = (pjmedia_port_info *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(pjmedia_port_info **)&jarg1; 
  delete arg1;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1cred_1info_1realm_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_) {
  pjsip_cred_info *arg1 = (pjsip_cred_info *) 0 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(pjsip_cred_info **)&jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  if (arg1) (arg1)->realm = *arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1cred_1info_1realm_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsip_cred_info *arg1 = (pjsip_cred_info *) 0 ;
  pj_str_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsip_cred_info **)&jarg1; 
  result = (pj_str_t *)& ((arg1)->realm);
  *(pj_str_t **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1cred_1info_1scheme_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_) {
  pjsip_cred_info *arg1 = (pjsip_cred_info *) 0 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(pjsip_cred_info **)&jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  if (arg1) (arg1)->scheme = *arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1cred_1info_1scheme_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsip_cred_info *arg1 = (pjsip_cred_info *) 0 ;
  pj_str_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsip_cred_info **)&jarg1; 
  result = (pj_str_t *)& ((arg1)->scheme);
  *(pj_str_t **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1cred_1info_1username_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_) {
  pjsip_cred_info *arg1 = (pjsip_cred_info *) 0 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(pjsip_cred_info **)&jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  if (arg1) (arg1)->username = *arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1cred_1info_1username_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsip_cred_info *arg1 = (pjsip_cred_info *) 0 ;
  pj_str_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsip_cred_info **)&jarg1; 
  result = (pj_str_t *)& ((arg1)->username);
  *(pj_str_t **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1cred_1info_1data_1type_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsip_cred_info *arg1 = (pjsip_cred_info *) 0 ;
  int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsip_cred_info **)&jarg1; 
  arg2 = (int)jarg2; 
  if (arg1) (arg1)->data_type = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1cred_1info_1data_1type_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsip_cred_info *arg1 = (pjsip_cred_info *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsip_cred_info **)&jarg1; 
  result = (int) ((arg1)->data_type);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1cred_1info_1data_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_) {
  pjsip_cred_info *arg1 = (pjsip_cred_info *) 0 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(pjsip_cred_info **)&jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  if (arg1) (arg1)->data = *arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1cred_1info_1data_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsip_cred_info *arg1 = (pjsip_cred_info *) 0 ;
  pj_str_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsip_cred_info **)&jarg1; 
  result = (pj_str_t *)& ((arg1)->data);
  *(pj_str_t **)&jresult = result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_new_1pjsip_1cred_1info(JNIEnv *jenv, jclass jcls) {
  jlong jresult = 0 ;
  pjsip_cred_info *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_cred_info *)new pjsip_cred_info();
  *(pjsip_cred_info **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_delete_1pjsip_1cred_1info(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  pjsip_cred_info *arg1 = (pjsip_cred_info *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(pjsip_cred_info **)&jarg1; 
  delete arg1;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1CRED_1DATA_1PLAIN_1PASSWD_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_cred_data_type result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_cred_data_type)PJSIP_CRED_DATA_PLAIN_PASSWD;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1CRED_1DATA_1DIGEST_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_cred_data_type result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_cred_data_type)PJSIP_CRED_DATA_DIGEST;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1CRED_1DATA_1EXT_1AKA_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_cred_data_type result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_cred_data_type)PJSIP_CRED_DATA_EXT_AKA;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJMEDIA_1TONEGEN_1LOOP_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  result = (int)PJMEDIA_TONEGEN_LOOP;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJMEDIA_1TONEGEN_1NO_1LOCK_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  result = (int)PJMEDIA_TONEGEN_NO_LOCK;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1event_1type_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsip_event *arg1 = (pjsip_event *) 0 ;
  pjsip_event_id_e arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsip_event **)&jarg1; 
  arg2 = (pjsip_event_id_e)jarg2; 
  if (arg1) (arg1)->type = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1event_1type_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsip_event *arg1 = (pjsip_event *) 0 ;
  pjsip_event_id_e result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsip_event **)&jarg1; 
  result = (pjsip_event_id_e) ((arg1)->type);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_new_1pjsip_1event(JNIEnv *jenv, jclass jcls) {
  jlong jresult = 0 ;
  pjsip_event *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_event *)new pjsip_event();
  *(pjsip_event **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_delete_1pjsip_1event(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  pjsip_event *arg1 = (pjsip_event *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(pjsip_event **)&jarg1; 
  delete arg1;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1snd_1dev_1info_1name_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jstring jarg2) {
  pjmedia_snd_dev_info *arg1 = (pjmedia_snd_dev_info *) 0 ;
  char *arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjmedia_snd_dev_info **)&jarg1; 
  arg2 = 0;
  if (jarg2) {
    arg2 = (char *)jenv->GetStringUTFChars(jarg2, 0);
    if (!arg2) return ;
  }
  {
    if(arg2) {
      strncpy((char*)arg1->name, (const char *)arg2, 64-1);
      arg1->name[64-1] = 0;
    } else {
      arg1->name[0] = 0;
    }
  }
  
  if (arg2) jenv->ReleaseStringUTFChars(jarg2, (const char *)arg2);
}


SWIGEXPORT jstring JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1snd_1dev_1info_1name_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jstring jresult = 0 ;
  pjmedia_snd_dev_info *arg1 = (pjmedia_snd_dev_info *) 0 ;
  char *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjmedia_snd_dev_info **)&jarg1; 
  result = (char *)(char *) ((arg1)->name);
  if (result) jresult = jenv->NewStringUTF((const char *)result);
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1snd_1dev_1info_1input_1count_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjmedia_snd_dev_info *arg1 = (pjmedia_snd_dev_info *) 0 ;
  unsigned int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjmedia_snd_dev_info **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  if (arg1) (arg1)->input_count = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1snd_1dev_1info_1input_1count_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjmedia_snd_dev_info *arg1 = (pjmedia_snd_dev_info *) 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjmedia_snd_dev_info **)&jarg1; 
  result = (unsigned int) ((arg1)->input_count);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1snd_1dev_1info_1output_1count_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjmedia_snd_dev_info *arg1 = (pjmedia_snd_dev_info *) 0 ;
  unsigned int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjmedia_snd_dev_info **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  if (arg1) (arg1)->output_count = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1snd_1dev_1info_1output_1count_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjmedia_snd_dev_info *arg1 = (pjmedia_snd_dev_info *) 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjmedia_snd_dev_info **)&jarg1; 
  result = (unsigned int) ((arg1)->output_count);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1snd_1dev_1info_1default_1samples_1per_1sec_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjmedia_snd_dev_info *arg1 = (pjmedia_snd_dev_info *) 0 ;
  unsigned int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjmedia_snd_dev_info **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  if (arg1) (arg1)->default_samples_per_sec = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1snd_1dev_1info_1default_1samples_1per_1sec_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjmedia_snd_dev_info *arg1 = (pjmedia_snd_dev_info *) 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjmedia_snd_dev_info **)&jarg1; 
  result = (unsigned int) ((arg1)->default_samples_per_sec);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_new_1pjmedia_1snd_1dev_1info(JNIEnv *jenv, jclass jcls) {
  jlong jresult = 0 ;
  pjmedia_snd_dev_info *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  result = (pjmedia_snd_dev_info *)new pjmedia_snd_dev_info();
  *(pjmedia_snd_dev_info **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_delete_1pjmedia_1snd_1dev_1info(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  pjmedia_snd_dev_info *arg1 = (pjmedia_snd_dev_info *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(pjmedia_snd_dev_info **)&jarg1; 
  delete arg1;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1tone_1desc_1freq1_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jshort jarg2) {
  pjmedia_tone_desc *arg1 = (pjmedia_tone_desc *) 0 ;
  short arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjmedia_tone_desc **)&jarg1; 
  arg2 = (short)jarg2; 
  if (arg1) (arg1)->freq1 = arg2;
}


SWIGEXPORT jshort JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1tone_1desc_1freq1_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jshort jresult = 0 ;
  pjmedia_tone_desc *arg1 = (pjmedia_tone_desc *) 0 ;
  short result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjmedia_tone_desc **)&jarg1; 
  result = (short) ((arg1)->freq1);
  jresult = (jshort)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1tone_1desc_1freq2_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jshort jarg2) {
  pjmedia_tone_desc *arg1 = (pjmedia_tone_desc *) 0 ;
  short arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjmedia_tone_desc **)&jarg1; 
  arg2 = (short)jarg2; 
  if (arg1) (arg1)->freq2 = arg2;
}


SWIGEXPORT jshort JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1tone_1desc_1freq2_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jshort jresult = 0 ;
  pjmedia_tone_desc *arg1 = (pjmedia_tone_desc *) 0 ;
  short result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjmedia_tone_desc **)&jarg1; 
  result = (short) ((arg1)->freq2);
  jresult = (jshort)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1tone_1desc_1on_1msec_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jshort jarg2) {
  pjmedia_tone_desc *arg1 = (pjmedia_tone_desc *) 0 ;
  short arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjmedia_tone_desc **)&jarg1; 
  arg2 = (short)jarg2; 
  if (arg1) (arg1)->on_msec = arg2;
}


SWIGEXPORT jshort JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1tone_1desc_1on_1msec_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jshort jresult = 0 ;
  pjmedia_tone_desc *arg1 = (pjmedia_tone_desc *) 0 ;
  short result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjmedia_tone_desc **)&jarg1; 
  result = (short) ((arg1)->on_msec);
  jresult = (jshort)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1tone_1desc_1off_1msec_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jshort jarg2) {
  pjmedia_tone_desc *arg1 = (pjmedia_tone_desc *) 0 ;
  short arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjmedia_tone_desc **)&jarg1; 
  arg2 = (short)jarg2; 
  if (arg1) (arg1)->off_msec = arg2;
}


SWIGEXPORT jshort JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1tone_1desc_1off_1msec_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jshort jresult = 0 ;
  pjmedia_tone_desc *arg1 = (pjmedia_tone_desc *) 0 ;
  short result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjmedia_tone_desc **)&jarg1; 
  result = (short) ((arg1)->off_msec);
  jresult = (jshort)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1tone_1desc_1volume_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jshort jarg2) {
  pjmedia_tone_desc *arg1 = (pjmedia_tone_desc *) 0 ;
  short arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjmedia_tone_desc **)&jarg1; 
  arg2 = (short)jarg2; 
  if (arg1) (arg1)->volume = arg2;
}


SWIGEXPORT jshort JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1tone_1desc_1volume_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jshort jresult = 0 ;
  pjmedia_tone_desc *arg1 = (pjmedia_tone_desc *) 0 ;
  short result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjmedia_tone_desc **)&jarg1; 
  result = (short) ((arg1)->volume);
  jresult = (jshort)result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_new_1pjmedia_1tone_1desc(JNIEnv *jenv, jclass jcls) {
  jlong jresult = 0 ;
  pjmedia_tone_desc *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  result = (pjmedia_tone_desc *)new pjmedia_tone_desc();
  *(pjmedia_tone_desc **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_delete_1pjmedia_1tone_1desc(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  pjmedia_tone_desc *arg1 = (pjmedia_tone_desc *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(pjmedia_tone_desc **)&jarg1; 
  delete arg1;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pj_1pool_1t_1obj_1name_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jstring jarg2) {
  pj_pool_t *arg1 = (pj_pool_t *) 0 ;
  char *arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pj_pool_t **)&jarg1; 
  arg2 = 0;
  if (jarg2) {
    arg2 = (char *)jenv->GetStringUTFChars(jarg2, 0);
    if (!arg2) return ;
  }
  {
    if(arg2) {
      strncpy((char*)arg1->obj_name, (const char *)arg2, PJ_MAX_OBJ_NAME-1);
      arg1->obj_name[PJ_MAX_OBJ_NAME-1] = 0;
    } else {
      arg1->obj_name[0] = 0;
    }
  }
  
  if (arg2) jenv->ReleaseStringUTFChars(jarg2, (const char *)arg2);
}


SWIGEXPORT jstring JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pj_1pool_1t_1obj_1name_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jstring jresult = 0 ;
  pj_pool_t *arg1 = (pj_pool_t *) 0 ;
  char *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pj_pool_t **)&jarg1; 
  result = (char *)(char *) ((arg1)->obj_name);
  if (result) jresult = jenv->NewStringUTF((const char *)result);
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pj_1pool_1t_1factory_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pj_pool_t *arg1 = (pj_pool_t *) 0 ;
  pj_pool_factory *arg2 = (pj_pool_factory *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pj_pool_t **)&jarg1; 
  arg2 = *(pj_pool_factory **)&jarg2; 
  if (arg1) (arg1)->factory = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pj_1pool_1t_1factory_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pj_pool_t *arg1 = (pj_pool_t *) 0 ;
  pj_pool_factory *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pj_pool_t **)&jarg1; 
  result = (pj_pool_factory *) ((arg1)->factory);
  *(pj_pool_factory **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pj_1pool_1t_1factory_1data_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, void * jarg2) {
  pj_pool_t *arg1 = (pj_pool_t *) 0 ;
  void *arg2 = (void *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pj_pool_t **)&jarg1; 
  
  arg2 = jarg2;
  
  if (arg1) (arg1)->factory_data = arg2;
}


SWIGEXPORT void * JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pj_1pool_1t_1factory_1data_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  void * jresult = 0 ;
  pj_pool_t *arg1 = (pj_pool_t *) 0 ;
  void *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pj_pool_t **)&jarg1; 
  result = (void *) ((arg1)->factory_data);
  
  jresult = result; 
  
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pj_1pool_1t_1capacity_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pj_pool_t *arg1 = (pj_pool_t *) 0 ;
  pj_size_t arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pj_pool_t **)&jarg1; 
  arg2 = (pj_size_t)jarg2; 
  if (arg1) (arg1)->capacity = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pj_1pool_1t_1capacity_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pj_pool_t *arg1 = (pj_pool_t *) 0 ;
  pj_size_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pj_pool_t **)&jarg1; 
  result =  ((arg1)->capacity);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pj_1pool_1t_1increment_1size_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pj_pool_t *arg1 = (pj_pool_t *) 0 ;
  pj_size_t arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pj_pool_t **)&jarg1; 
  arg2 = (pj_size_t)jarg2; 
  if (arg1) (arg1)->increment_size = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pj_1pool_1t_1increment_1size_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pj_pool_t *arg1 = (pj_pool_t *) 0 ;
  pj_size_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pj_pool_t **)&jarg1; 
  result =  ((arg1)->increment_size);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pj_1pool_1t_1block_1list_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pj_pool_t *arg1 = (pj_pool_t *) 0 ;
  pj_pool_block arg2 ;
  pj_pool_block *argp2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pj_pool_t **)&jarg1; 
  argp2 = *(pj_pool_block **)&jarg2; 
  if (!argp2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null pj_pool_block");
    return ;
  }
  arg2 = *argp2; 
  if (arg1) (arg1)->block_list = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pj_1pool_1t_1block_1list_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pj_pool_t *arg1 = (pj_pool_t *) 0 ;
  pj_pool_block result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pj_pool_t **)&jarg1; 
  result =  ((arg1)->block_list);
  *(pj_pool_block **)&jresult = new pj_pool_block((const pj_pool_block &)result); 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pj_1pool_1t_1callback_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pj_pool_t *arg1 = (pj_pool_t *) 0 ;
  pj_pool_callback *arg2 = (pj_pool_callback *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pj_pool_t **)&jarg1; 
  arg2 = *(pj_pool_callback **)&jarg2; 
  if (arg1) (arg1)->callback = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pj_1pool_1t_1callback_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pj_pool_t *arg1 = (pj_pool_t *) 0 ;
  pj_pool_callback *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pj_pool_t **)&jarg1; 
  result = (pj_pool_callback *) ((arg1)->callback);
  *(pj_pool_callback **)&jresult = result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_new_1pj_1pool_1t(JNIEnv *jenv, jclass jcls) {
  jlong jresult = 0 ;
  pj_pool_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  result = (pj_pool_t *)new pj_pool_t();
  *(pj_pool_t **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_delete_1pj_1pool_1t(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  pj_pool_t *arg1 = (pj_pool_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(pj_pool_t **)&jarg1; 
  delete arg1;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1TRANSPORT_1IPV6_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_transport_type_e result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_transport_type_e)PJSIP_TRANSPORT_IPV6;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1TRANSPORT_1UDP6_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_transport_type_e result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_transport_type_e)PJSIP_TRANSPORT_UDP6;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1TRANSPORT_1TCP6_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_transport_type_e result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_transport_type_e)PJSIP_TRANSPORT_TCP6;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1TRYING_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_TRYING;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1RINGING_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_RINGING;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1CALL_1BEING_1FORWARDED_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_CALL_BEING_FORWARDED;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1QUEUED_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_QUEUED;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1PROGRESS_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_PROGRESS;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1OK_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_OK;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1ACCEPTED_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_ACCEPTED;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1MULTIPLE_1CHOICES_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_MULTIPLE_CHOICES;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1MOVED_1PERMANENTLY_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_MOVED_PERMANENTLY;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1MOVED_1TEMPORARILY_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_MOVED_TEMPORARILY;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1USE_1PROXY_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_USE_PROXY;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1ALTERNATIVE_1SERVICE_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_ALTERNATIVE_SERVICE;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1BAD_1REQUEST_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_BAD_REQUEST;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1UNAUTHORIZED_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_UNAUTHORIZED;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1PAYMENT_1REQUIRED_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_PAYMENT_REQUIRED;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1FORBIDDEN_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_FORBIDDEN;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1NOT_1FOUND_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_NOT_FOUND;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1METHOD_1NOT_1ALLOWED_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_METHOD_NOT_ALLOWED;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1NOT_1ACCEPTABLE_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_NOT_ACCEPTABLE;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1PROXY_1AUTHENTICATION_1REQUIRED_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_PROXY_AUTHENTICATION_REQUIRED;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1REQUEST_1TIMEOUT_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_REQUEST_TIMEOUT;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1GONE_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_GONE;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1REQUEST_1ENTITY_1TOO_1LARGE_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_REQUEST_ENTITY_TOO_LARGE;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1REQUEST_1URI_1TOO_1LONG_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_REQUEST_URI_TOO_LONG;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1UNSUPPORTED_1MEDIA_1TYPE_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_UNSUPPORTED_MEDIA_TYPE;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1UNSUPPORTED_1URI_1SCHEME_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_UNSUPPORTED_URI_SCHEME;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1BAD_1EXTENSION_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_BAD_EXTENSION;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1EXTENSION_1REQUIRED_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_EXTENSION_REQUIRED;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1SESSION_1TIMER_1TOO_1SMALL_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_SESSION_TIMER_TOO_SMALL;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1INTERVAL_1TOO_1BRIEF_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_INTERVAL_TOO_BRIEF;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1TEMPORARILY_1UNAVAILABLE_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_TEMPORARILY_UNAVAILABLE;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1CALL_1TSX_1DOES_1NOT_1EXIST_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_CALL_TSX_DOES_NOT_EXIST;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1LOOP_1DETECTED_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_LOOP_DETECTED;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1TOO_1MANY_1HOPS_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_TOO_MANY_HOPS;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1ADDRESS_1INCOMPLETE_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_ADDRESS_INCOMPLETE;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1AC_1AMBIGUOUS_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_AC_AMBIGUOUS;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1BUSY_1HERE_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_BUSY_HERE;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1REQUEST_1TERMINATED_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_REQUEST_TERMINATED;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1NOT_1ACCEPTABLE_1HERE_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_NOT_ACCEPTABLE_HERE;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1BAD_1EVENT_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_BAD_EVENT;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1REQUEST_1UPDATED_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_REQUEST_UPDATED;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1REQUEST_1PENDING_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_REQUEST_PENDING;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1UNDECIPHERABLE_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_UNDECIPHERABLE;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1INTERNAL_1SERVER_1ERROR_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_INTERNAL_SERVER_ERROR;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1NOT_1IMPLEMENTED_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_NOT_IMPLEMENTED;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1BAD_1GATEWAY_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_BAD_GATEWAY;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1SERVICE_1UNAVAILABLE_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_SERVICE_UNAVAILABLE;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1SERVER_1TIMEOUT_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_SERVER_TIMEOUT;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1VERSION_1NOT_1SUPPORTED_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_VERSION_NOT_SUPPORTED;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1MESSAGE_1TOO_1LARGE_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_MESSAGE_TOO_LARGE;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1PRECONDITION_1FAILURE_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_PRECONDITION_FAILURE;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1BUSY_1EVERYWHERE_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_BUSY_EVERYWHERE;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1DECLINE_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_DECLINE;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1DOES_1NOT_1EXIST_1ANYWHERE_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_DOES_NOT_EXIST_ANYWHERE;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1NOT_1ACCEPTABLE_1ANYWHERE_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_NOT_ACCEPTABLE_ANYWHERE;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1TSX_1TIMEOUT_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_TSX_TIMEOUT;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1TSX_1TRANSPORT_1ERROR_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_status_code)PJSIP_SC_TSX_TRANSPORT_ERROR;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1pool_1create(JNIEnv *jenv, jclass jcls, jstring jarg1, jlong jarg2, jlong jarg3) {
  jlong jresult = 0 ;
  char *arg1 = (char *) 0 ;
  pj_size_t arg2 ;
  pj_size_t arg3 ;
  pj_pool_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = 0;
  if (jarg1) {
    arg1 = (char *)jenv->GetStringUTFChars(jarg1, 0);
    if (!arg1) return 0;
  }
  arg2 = (pj_size_t)jarg2; 
  arg3 = (pj_size_t)jarg3; 
  result = (pj_pool_t *)pjsua_pool_create((char const *)arg1,arg2,arg3);
  *(pj_pool_t **)&jresult = result; 
  if (arg1) jenv->ReleaseStringUTFChars(jarg1, (const char *)arg1);
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pj_1pool_1release(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  pj_pool_t *arg1 = (pj_pool_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pj_pool_t **)&jarg1; 
  pj_pool_release(arg1);
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1tonegen_1create2(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_, jlong jarg3, jlong jarg4, jlong jarg5, jlong jarg6, jlong jarg7, jobject jarg8) {
  jint jresult = 0 ;
  pj_pool_t *arg1 = (pj_pool_t *) 0 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  unsigned int arg3 ;
  unsigned int arg4 ;
  unsigned int arg5 ;
  unsigned int arg6 ;
  unsigned int arg7 ;
  pjmedia_port **arg8 = (pjmedia_port **) 0 ;
  pjmedia_port *ppMediaPort8 = 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(pj_pool_t **)&jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  arg3 = (unsigned int)jarg3; 
  arg4 = (unsigned int)jarg4; 
  arg5 = (unsigned int)jarg5; 
  arg6 = (unsigned int)jarg6; 
  arg7 = (unsigned int)jarg7; 
  
  arg8 = &ppMediaPort8;
  
  result = (pj_status_t)pjmedia_tonegen_create2(arg1,(pj_str_t const *)arg2,arg3,arg4,arg5,arg6,arg7,arg8);
  jresult = (jint)result; 
  {
    // Give Java proxy the C pointer (of newly created object)
    jclass clazz = jenv->FindClass("org/pjsip/pjsua/pjmedia_port");
    jfieldID fid = jenv->GetFieldID(clazz, "swigCPtr", "J");
    jlong cPtr = 0;
    *(pjmedia_port **)&cPtr = *arg8;
    jenv->SetLongField(jarg8, fid, cPtr);
  }
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1tonegen_1play(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jlongArray jarg3, jlong jarg4) {
  jint jresult = 0 ;
  pjmedia_port *arg1 = (pjmedia_port *) 0 ;
  unsigned int arg2 ;
  pjmedia_tone_desc *arg3 ;
  unsigned int arg4 ;
  jlong *jarr3 ;
  jsize sz3 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjmedia_port **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  {
    int i;
    if (!jarg3) {
      SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null array");
      return 0;
    }
    sz3 = jenv->GetArrayLength(jarg3);
    jarr3 = jenv->GetLongArrayElements(jarg3, 0);
    if (!jarr3) {
      return 0;
    }
    
    arg3 = new pjmedia_tone_desc[sz3];
    
    
    
    if (!arg3) {
      SWIG_JavaThrowException(jenv, SWIG_JavaOutOfMemoryError, "array memory allocation failed");
      return 0;
    }
    for (i=0; i<sz3; i++) {
      arg3[i] = **(pjmedia_tone_desc **)&jarr3[i];
    }
  }
  arg4 = (unsigned int)jarg4; 
  result = (pj_status_t)pjmedia_tonegen_play(arg1,arg2,(pjmedia_tone_desc const (*))arg3,arg4);
  jresult = (jint)result; 
  {
    int i;
    for (i=0; i<sz3; i++) {
      **(pjmedia_tone_desc **)&jarr3[i] = arg3[i];
    }
    jenv->ReleaseLongArrayElements(jarg3, jarr3, 0);
  }
  delete [] arg3; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1tonegen_1rewind(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjmedia_port *arg1 = (pjmedia_port *) 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjmedia_port **)&jarg1; 
  result = (pj_status_t)pjmedia_tonegen_rewind(arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SSL_1UNSPECIFIED_1METHOD_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_ssl_method result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_ssl_method)PJSIP_SSL_UNSPECIFIED_METHOD;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1TLSV1_1METHOD_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_ssl_method result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_ssl_method)PJSIP_TLSV1_METHOD;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SSLV2_1METHOD_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_ssl_method result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_ssl_method)PJSIP_SSLV2_METHOD;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SSLV3_1METHOD_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_ssl_method result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_ssl_method)PJSIP_SSLV3_METHOD;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SSLV23_1METHOD_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsip_ssl_method result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_ssl_method)PJSIP_SSLV23_METHOD;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1ca_1list_1file_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_) {
  pjsip_tls_setting *arg1 = (pjsip_tls_setting *) 0 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(pjsip_tls_setting **)&jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  if (arg1) (arg1)->ca_list_file = *arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1ca_1list_1file_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsip_tls_setting *arg1 = (pjsip_tls_setting *) 0 ;
  pj_str_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsip_tls_setting **)&jarg1; 
  result = (pj_str_t *)& ((arg1)->ca_list_file);
  *(pj_str_t **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1cert_1file_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_) {
  pjsip_tls_setting *arg1 = (pjsip_tls_setting *) 0 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(pjsip_tls_setting **)&jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  if (arg1) (arg1)->cert_file = *arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1cert_1file_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsip_tls_setting *arg1 = (pjsip_tls_setting *) 0 ;
  pj_str_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsip_tls_setting **)&jarg1; 
  result = (pj_str_t *)& ((arg1)->cert_file);
  *(pj_str_t **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1privkey_1file_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_) {
  pjsip_tls_setting *arg1 = (pjsip_tls_setting *) 0 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(pjsip_tls_setting **)&jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  if (arg1) (arg1)->privkey_file = *arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1privkey_1file_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsip_tls_setting *arg1 = (pjsip_tls_setting *) 0 ;
  pj_str_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsip_tls_setting **)&jarg1; 
  result = (pj_str_t *)& ((arg1)->privkey_file);
  *(pj_str_t **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1password_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_) {
  pjsip_tls_setting *arg1 = (pjsip_tls_setting *) 0 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(pjsip_tls_setting **)&jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  if (arg1) (arg1)->password = *arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1password_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsip_tls_setting *arg1 = (pjsip_tls_setting *) 0 ;
  pj_str_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsip_tls_setting **)&jarg1; 
  result = (pj_str_t *)& ((arg1)->password);
  *(pj_str_t **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1method_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsip_tls_setting *arg1 = (pjsip_tls_setting *) 0 ;
  int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsip_tls_setting **)&jarg1; 
  arg2 = (int)jarg2; 
  if (arg1) (arg1)->method = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1method_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsip_tls_setting *arg1 = (pjsip_tls_setting *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsip_tls_setting **)&jarg1; 
  result = (int) ((arg1)->method);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1ciphers_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_) {
  pjsip_tls_setting *arg1 = (pjsip_tls_setting *) 0 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(pjsip_tls_setting **)&jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  if (arg1) (arg1)->ciphers = *arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1ciphers_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsip_tls_setting *arg1 = (pjsip_tls_setting *) 0 ;
  pj_str_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsip_tls_setting **)&jarg1; 
  result = (pj_str_t *)& ((arg1)->ciphers);
  *(pj_str_t **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1server_1name_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_) {
  pjsip_tls_setting *arg1 = (pjsip_tls_setting *) 0 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(pjsip_tls_setting **)&jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  if (arg1) (arg1)->server_name = *arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1server_1name_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsip_tls_setting *arg1 = (pjsip_tls_setting *) 0 ;
  pj_str_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsip_tls_setting **)&jarg1; 
  result = (pj_str_t *)& ((arg1)->server_name);
  *(pj_str_t **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1verify_1server_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsip_tls_setting *arg1 = (pjsip_tls_setting *) 0 ;
  pj_bool_t arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsip_tls_setting **)&jarg1; 
  arg2 = (pj_bool_t)jarg2; 
  if (arg1) (arg1)->verify_server = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1verify_1server_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsip_tls_setting *arg1 = (pjsip_tls_setting *) 0 ;
  pj_bool_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsip_tls_setting **)&jarg1; 
  result = (pj_bool_t) ((arg1)->verify_server);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1verify_1client_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsip_tls_setting *arg1 = (pjsip_tls_setting *) 0 ;
  pj_bool_t arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsip_tls_setting **)&jarg1; 
  arg2 = (pj_bool_t)jarg2; 
  if (arg1) (arg1)->verify_client = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1verify_1client_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsip_tls_setting *arg1 = (pjsip_tls_setting *) 0 ;
  pj_bool_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsip_tls_setting **)&jarg1; 
  result = (pj_bool_t) ((arg1)->verify_client);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1require_1client_1cert_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsip_tls_setting *arg1 = (pjsip_tls_setting *) 0 ;
  pj_bool_t arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsip_tls_setting **)&jarg1; 
  arg2 = (pj_bool_t)jarg2; 
  if (arg1) (arg1)->require_client_cert = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1require_1client_1cert_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsip_tls_setting *arg1 = (pjsip_tls_setting *) 0 ;
  pj_bool_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsip_tls_setting **)&jarg1; 
  result = (pj_bool_t) ((arg1)->require_client_cert);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1timeout_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsip_tls_setting *arg1 = (pjsip_tls_setting *) 0 ;
  pj_time_val arg2 ;
  pj_time_val *argp2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsip_tls_setting **)&jarg1; 
  argp2 = *(pj_time_val **)&jarg2; 
  if (!argp2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null pj_time_val");
    return ;
  }
  arg2 = *argp2; 
  if (arg1) (arg1)->timeout = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1timeout_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsip_tls_setting *arg1 = (pjsip_tls_setting *) 0 ;
  pj_time_val result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsip_tls_setting **)&jarg1; 
  result =  ((arg1)->timeout);
  *(pj_time_val **)&jresult = new pj_time_val((const pj_time_val &)result); 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1qos_1type_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsip_tls_setting *arg1 = (pjsip_tls_setting *) 0 ;
  pj_qos_type arg2 ;
  pj_qos_type *argp2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsip_tls_setting **)&jarg1; 
  argp2 = *(pj_qos_type **)&jarg2; 
  if (!argp2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null pj_qos_type");
    return ;
  }
  arg2 = *argp2; 
  if (arg1) (arg1)->qos_type = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1qos_1type_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsip_tls_setting *arg1 = (pjsip_tls_setting *) 0 ;
  pj_qos_type result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsip_tls_setting **)&jarg1; 
  result =  ((arg1)->qos_type);
  *(pj_qos_type **)&jresult = new pj_qos_type((const pj_qos_type &)result); 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1qos_1params_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsip_tls_setting *arg1 = (pjsip_tls_setting *) 0 ;
  pj_qos_params arg2 ;
  pj_qos_params *argp2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsip_tls_setting **)&jarg1; 
  argp2 = *(pj_qos_params **)&jarg2; 
  if (!argp2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null pj_qos_params");
    return ;
  }
  arg2 = *argp2; 
  if (arg1) (arg1)->qos_params = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1qos_1params_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsip_tls_setting *arg1 = (pjsip_tls_setting *) 0 ;
  pj_qos_params result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsip_tls_setting **)&jarg1; 
  result =  ((arg1)->qos_params);
  *(pj_qos_params **)&jresult = new pj_qos_params((const pj_qos_params &)result); 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1qos_1ignore_1error_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsip_tls_setting *arg1 = (pjsip_tls_setting *) 0 ;
  pj_bool_t arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsip_tls_setting **)&jarg1; 
  arg2 = (pj_bool_t)jarg2; 
  if (arg1) (arg1)->qos_ignore_error = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1qos_1ignore_1error_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsip_tls_setting *arg1 = (pjsip_tls_setting *) 0 ;
  pj_bool_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsip_tls_setting **)&jarg1; 
  result = (pj_bool_t) ((arg1)->qos_ignore_error);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_new_1pjsip_1tls_1setting(JNIEnv *jenv, jclass jcls) {
  jlong jresult = 0 ;
  pjsip_tls_setting *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_tls_setting *)new pjsip_tls_setting();
  *(pjsip_tls_setting **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_delete_1pjsip_1tls_1setting(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  pjsip_tls_setting *arg1 = (pjsip_tls_setting *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(pjsip_tls_setting **)&jarg1; 
  delete arg1;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSUA_1INVALID_1ID_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  result = (int)((-1));
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSUA_1ACC_1MAX_1PROXIES_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  result = (int)(8);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSUA_1DEFAULT_1SRTP_1SECURE_1SIGNALING_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  result = (int)(1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSUA_1ADD_1ICE_1TAGS_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  result = (int)(1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSUA_1ACQUIRE_1CALL_1TIMEOUT_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  result = (int)(2000);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1logging_1config_1msg_1logging_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_logging_config *arg1 = (pjsua_logging_config *) 0 ;
  pj_bool_t arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_logging_config **)&jarg1; 
  arg2 = (pj_bool_t)jarg2; 
  if (arg1) (arg1)->msg_logging = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1logging_1config_1msg_1logging_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_logging_config *arg1 = (pjsua_logging_config *) 0 ;
  pj_bool_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_logging_config **)&jarg1; 
  result = (pj_bool_t) ((arg1)->msg_logging);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1logging_1config_1level_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_logging_config *arg1 = (pjsua_logging_config *) 0 ;
  unsigned int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_logging_config **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  if (arg1) (arg1)->level = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1logging_1config_1level_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_logging_config *arg1 = (pjsua_logging_config *) 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_logging_config **)&jarg1; 
  result = (unsigned int) ((arg1)->level);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1logging_1config_1console_1level_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_logging_config *arg1 = (pjsua_logging_config *) 0 ;
  unsigned int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_logging_config **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  if (arg1) (arg1)->console_level = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1logging_1config_1console_1level_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_logging_config *arg1 = (pjsua_logging_config *) 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_logging_config **)&jarg1; 
  result = (unsigned int) ((arg1)->console_level);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1logging_1config_1decor_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_logging_config *arg1 = (pjsua_logging_config *) 0 ;
  unsigned int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_logging_config **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  if (arg1) (arg1)->decor = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1logging_1config_1decor_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_logging_config *arg1 = (pjsua_logging_config *) 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_logging_config **)&jarg1; 
  result = (unsigned int) ((arg1)->decor);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1logging_1config_1log_1filename_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_) {
  pjsua_logging_config *arg1 = (pjsua_logging_config *) 0 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(pjsua_logging_config **)&jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  if (arg1) (arg1)->log_filename = *arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1logging_1config_1log_1filename_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_logging_config *arg1 = (pjsua_logging_config *) 0 ;
  pj_str_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_logging_config **)&jarg1; 
  result = (pj_str_t *)& ((arg1)->log_filename);
  *(pj_str_t **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1logging_1config_1log_1file_1flags_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_logging_config *arg1 = (pjsua_logging_config *) 0 ;
  unsigned int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_logging_config **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  if (arg1) (arg1)->log_file_flags = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1logging_1config_1log_1file_1flags_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_logging_config *arg1 = (pjsua_logging_config *) 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_logging_config **)&jarg1; 
  result = (unsigned int) ((arg1)->log_file_flags);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1logging_1config_1cb_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_logging_config *arg1 = (pjsua_logging_config *) 0 ;
  void (*arg2)(int,char const *,int) = (void (*)(int,char const *,int)) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_logging_config **)&jarg1; 
  arg2 = *(void (**)(int,char const *,int))&jarg2; 
  if (arg1) (arg1)->cb = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1logging_1config_1cb_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_logging_config *arg1 = (pjsua_logging_config *) 0 ;
  void (*result)(int,char const *,int) = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_logging_config **)&jarg1; 
  result = (void (*)(int,char const *,int)) ((arg1)->cb);
  *(void (**)(int,char const *,int))&jresult = result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_new_1pjsua_1logging_1config(JNIEnv *jenv, jclass jcls) {
  jlong jresult = 0 ;
  pjsua_logging_config *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  result = (pjsua_logging_config *)new pjsua_logging_config();
  *(pjsua_logging_config **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_delete_1pjsua_1logging_1config(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  pjsua_logging_config *arg1 = (pjsua_logging_config *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(pjsua_logging_config **)&jarg1; 
  delete arg1;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_logging_1config_1default(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  pjsua_logging_config *arg1 = (pjsua_logging_config *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_logging_config **)&jarg1; 
  pjsua_logging_config_default(arg1);
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_logging_1config_1dup(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_, jlong jarg3, jobject jarg3_) {
  pj_pool_t *arg1 = (pj_pool_t *) 0 ;
  pjsua_logging_config *arg2 = (pjsua_logging_config *) 0 ;
  pjsua_logging_config *arg3 = (pjsua_logging_config *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  (void)jarg3_;
  arg1 = *(pj_pool_t **)&jarg1; 
  arg2 = *(pjsua_logging_config **)&jarg2; 
  arg3 = *(pjsua_logging_config **)&jarg3; 
  pjsua_logging_config_dup(arg1,arg2,(pjsua_logging_config const *)arg3);
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1mwi_1info_1evsub_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_mwi_info *arg1 = (pjsua_mwi_info *) 0 ;
  pjsip_evsub *arg2 = (pjsip_evsub *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_mwi_info **)&jarg1; 
  arg2 = *(pjsip_evsub **)&jarg2; 
  if (arg1) (arg1)->evsub = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1mwi_1info_1evsub_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_mwi_info *arg1 = (pjsua_mwi_info *) 0 ;
  pjsip_evsub *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_mwi_info **)&jarg1; 
  result = (pjsip_evsub *) ((arg1)->evsub);
  *(pjsip_evsub **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1mwi_1info_1rdata_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_mwi_info *arg1 = (pjsua_mwi_info *) 0 ;
  pjsip_rx_data *arg2 = (pjsip_rx_data *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_mwi_info **)&jarg1; 
  arg2 = *(pjsip_rx_data **)&jarg2; 
  if (arg1) (arg1)->rdata = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1mwi_1info_1rdata_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_mwi_info *arg1 = (pjsua_mwi_info *) 0 ;
  pjsip_rx_data *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_mwi_info **)&jarg1; 
  result = (pjsip_rx_data *) ((arg1)->rdata);
  *(pjsip_rx_data **)&jresult = result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_new_1pjsua_1mwi_1info(JNIEnv *jenv, jclass jcls) {
  jlong jresult = 0 ;
  pjsua_mwi_info *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  result = (pjsua_mwi_info *)new pjsua_mwi_info();
  *(pjsua_mwi_info **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_delete_1pjsua_1mwi_1info(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  pjsua_mwi_info *arg1 = (pjsua_mwi_info *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(pjsua_mwi_info **)&jarg1; 
  delete arg1;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1reg_1info_1cbparam_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_reg_info *arg1 = (pjsua_reg_info *) 0 ;
  pjsip_regc_cbparam *arg2 = (pjsip_regc_cbparam *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_reg_info **)&jarg1; 
  arg2 = *(pjsip_regc_cbparam **)&jarg2; 
  if (arg1) (arg1)->cbparam = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1reg_1info_1cbparam_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_reg_info *arg1 = (pjsua_reg_info *) 0 ;
  pjsip_regc_cbparam *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_reg_info **)&jarg1; 
  result = (pjsip_regc_cbparam *) ((arg1)->cbparam);
  *(pjsip_regc_cbparam **)&jresult = result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_new_1pjsua_1reg_1info(JNIEnv *jenv, jclass jcls) {
  jlong jresult = 0 ;
  pjsua_reg_info *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  result = (pjsua_reg_info *)new pjsua_reg_info();
  *(pjsua_reg_info **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_delete_1pjsua_1reg_1info(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  pjsua_reg_info *arg1 = (pjsua_reg_info *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(pjsua_reg_info **)&jarg1; 
  delete arg1;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1call_1state_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  void (*arg2)(pjsua_call_id,pjsip_event *) = (void (*)(pjsua_call_id,pjsip_event *)) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  arg2 = *(void (**)(pjsua_call_id,pjsip_event *))&jarg2; 
  if (arg1) (arg1)->on_call_state = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1call_1state_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  void (*result)(pjsua_call_id,pjsip_event *) = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  result = (void (*)(pjsua_call_id,pjsip_event *)) ((arg1)->on_call_state);
  *(void (**)(pjsua_call_id,pjsip_event *))&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1incoming_1call_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  void (*arg2)(pjsua_acc_id,pjsua_call_id,pjsip_rx_data *) = (void (*)(pjsua_acc_id,pjsua_call_id,pjsip_rx_data *)) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  arg2 = *(void (**)(pjsua_acc_id,pjsua_call_id,pjsip_rx_data *))&jarg2; 
  if (arg1) (arg1)->on_incoming_call = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1incoming_1call_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  void (*result)(pjsua_acc_id,pjsua_call_id,pjsip_rx_data *) = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  result = (void (*)(pjsua_acc_id,pjsua_call_id,pjsip_rx_data *)) ((arg1)->on_incoming_call);
  *(void (**)(pjsua_acc_id,pjsua_call_id,pjsip_rx_data *))&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1call_1tsx_1state_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  void (*arg2)(pjsua_call_id,pjsip_transaction *,pjsip_event *) = (void (*)(pjsua_call_id,pjsip_transaction *,pjsip_event *)) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  arg2 = *(void (**)(pjsua_call_id,pjsip_transaction *,pjsip_event *))&jarg2; 
  if (arg1) (arg1)->on_call_tsx_state = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1call_1tsx_1state_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  void (*result)(pjsua_call_id,pjsip_transaction *,pjsip_event *) = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  result = (void (*)(pjsua_call_id,pjsip_transaction *,pjsip_event *)) ((arg1)->on_call_tsx_state);
  *(void (**)(pjsua_call_id,pjsip_transaction *,pjsip_event *))&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1call_1media_1state_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  void (*arg2)(pjsua_call_id) = (void (*)(pjsua_call_id)) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  arg2 = *(void (**)(pjsua_call_id))&jarg2; 
  if (arg1) (arg1)->on_call_media_state = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1call_1media_1state_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  void (*result)(pjsua_call_id) = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  result = (void (*)(pjsua_call_id)) ((arg1)->on_call_media_state);
  *(void (**)(pjsua_call_id))&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1stream_1created_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  void (*arg2)(pjsua_call_id,pjmedia_session *,unsigned int,pjmedia_port **) = (void (*)(pjsua_call_id,pjmedia_session *,unsigned int,pjmedia_port **)) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  arg2 = *(void (**)(pjsua_call_id,pjmedia_session *,unsigned int,pjmedia_port **))&jarg2; 
  if (arg1) (arg1)->on_stream_created = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1stream_1created_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  void (*result)(pjsua_call_id,pjmedia_session *,unsigned int,pjmedia_port **) = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  result = (void (*)(pjsua_call_id,pjmedia_session *,unsigned int,pjmedia_port **)) ((arg1)->on_stream_created);
  *(void (**)(pjsua_call_id,pjmedia_session *,unsigned int,pjmedia_port **))&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1stream_1destroyed_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  void (*arg2)(pjsua_call_id,pjmedia_session *,unsigned int) = (void (*)(pjsua_call_id,pjmedia_session *,unsigned int)) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  arg2 = *(void (**)(pjsua_call_id,pjmedia_session *,unsigned int))&jarg2; 
  if (arg1) (arg1)->on_stream_destroyed = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1stream_1destroyed_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  void (*result)(pjsua_call_id,pjmedia_session *,unsigned int) = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  result = (void (*)(pjsua_call_id,pjmedia_session *,unsigned int)) ((arg1)->on_stream_destroyed);
  *(void (**)(pjsua_call_id,pjmedia_session *,unsigned int))&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1dtmf_1digit_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  void (*arg2)(pjsua_call_id,int) = (void (*)(pjsua_call_id,int)) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  arg2 = *(void (**)(pjsua_call_id,int))&jarg2; 
  if (arg1) (arg1)->on_dtmf_digit = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1dtmf_1digit_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  void (*result)(pjsua_call_id,int) = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  result = (void (*)(pjsua_call_id,int)) ((arg1)->on_dtmf_digit);
  *(void (**)(pjsua_call_id,int))&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1call_1transfer_1request_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  void (*arg2)(pjsua_call_id,pj_str_t const *,pjsip_status_code *) = (void (*)(pjsua_call_id,pj_str_t const *,pjsip_status_code *)) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  arg2 = *(void (**)(pjsua_call_id,pj_str_t const *,pjsip_status_code *))&jarg2; 
  if (arg1) (arg1)->on_call_transfer_request = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1call_1transfer_1request_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  void (*result)(pjsua_call_id,pj_str_t const *,pjsip_status_code *) = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  result = (void (*)(pjsua_call_id,pj_str_t const *,pjsip_status_code *)) ((arg1)->on_call_transfer_request);
  *(void (**)(pjsua_call_id,pj_str_t const *,pjsip_status_code *))&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1call_1transfer_1status_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  void (*arg2)(pjsua_call_id,int,pj_str_t const *,pj_bool_t,pj_bool_t *) = (void (*)(pjsua_call_id,int,pj_str_t const *,pj_bool_t,pj_bool_t *)) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  arg2 = *(void (**)(pjsua_call_id,int,pj_str_t const *,pj_bool_t,pj_bool_t *))&jarg2; 
  if (arg1) (arg1)->on_call_transfer_status = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1call_1transfer_1status_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  void (*result)(pjsua_call_id,int,pj_str_t const *,pj_bool_t,pj_bool_t *) = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  result = (void (*)(pjsua_call_id,int,pj_str_t const *,pj_bool_t,pj_bool_t *)) ((arg1)->on_call_transfer_status);
  *(void (**)(pjsua_call_id,int,pj_str_t const *,pj_bool_t,pj_bool_t *))&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1call_1replace_1request_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  void (*arg2)(pjsua_call_id,pjsip_rx_data *,int *,pj_str_t *) = (void (*)(pjsua_call_id,pjsip_rx_data *,int *,pj_str_t *)) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  arg2 = *(void (**)(pjsua_call_id,pjsip_rx_data *,int *,pj_str_t *))&jarg2; 
  if (arg1) (arg1)->on_call_replace_request = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1call_1replace_1request_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  void (*result)(pjsua_call_id,pjsip_rx_data *,int *,pj_str_t *) = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  result = (void (*)(pjsua_call_id,pjsip_rx_data *,int *,pj_str_t *)) ((arg1)->on_call_replace_request);
  *(void (**)(pjsua_call_id,pjsip_rx_data *,int *,pj_str_t *))&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1call_1replaced_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  void (*arg2)(pjsua_call_id,pjsua_call_id) = (void (*)(pjsua_call_id,pjsua_call_id)) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  arg2 = *(void (**)(pjsua_call_id,pjsua_call_id))&jarg2; 
  if (arg1) (arg1)->on_call_replaced = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1call_1replaced_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  void (*result)(pjsua_call_id,pjsua_call_id) = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  result = (void (*)(pjsua_call_id,pjsua_call_id)) ((arg1)->on_call_replaced);
  *(void (**)(pjsua_call_id,pjsua_call_id))&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1reg_1state_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  void (*arg2)(pjsua_acc_id) = (void (*)(pjsua_acc_id)) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  arg2 = *(void (**)(pjsua_acc_id))&jarg2; 
  if (arg1) (arg1)->on_reg_state = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1reg_1state_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  void (*result)(pjsua_acc_id) = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  result = (void (*)(pjsua_acc_id)) ((arg1)->on_reg_state);
  *(void (**)(pjsua_acc_id))&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1reg_1state2_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  void (*arg2)(pjsua_acc_id,pjsua_reg_info *) = (void (*)(pjsua_acc_id,pjsua_reg_info *)) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  arg2 = *(void (**)(pjsua_acc_id,pjsua_reg_info *))&jarg2; 
  if (arg1) (arg1)->on_reg_state2 = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1reg_1state2_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  void (*result)(pjsua_acc_id,pjsua_reg_info *) = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  result = (void (*)(pjsua_acc_id,pjsua_reg_info *)) ((arg1)->on_reg_state2);
  *(void (**)(pjsua_acc_id,pjsua_reg_info *))&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1incoming_1subscribe_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  void (*arg2)(pjsua_acc_id,pjsua_srv_pres *,pjsua_buddy_id,pj_str_t const *,pjsip_rx_data *,pjsip_status_code *,pj_str_t *,pjsua_msg_data *) = (void (*)(pjsua_acc_id,pjsua_srv_pres *,pjsua_buddy_id,pj_str_t const *,pjsip_rx_data *,pjsip_status_code *,pj_str_t *,pjsua_msg_data *)) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  arg2 = *(void (**)(pjsua_acc_id,pjsua_srv_pres *,pjsua_buddy_id,pj_str_t const *,pjsip_rx_data *,pjsip_status_code *,pj_str_t *,pjsua_msg_data *))&jarg2; 
  if (arg1) (arg1)->on_incoming_subscribe = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1incoming_1subscribe_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  void (*result)(pjsua_acc_id,pjsua_srv_pres *,pjsua_buddy_id,pj_str_t const *,pjsip_rx_data *,pjsip_status_code *,pj_str_t *,pjsua_msg_data *) = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  result = (void (*)(pjsua_acc_id,pjsua_srv_pres *,pjsua_buddy_id,pj_str_t const *,pjsip_rx_data *,pjsip_status_code *,pj_str_t *,pjsua_msg_data *)) ((arg1)->on_incoming_subscribe);
  *(void (**)(pjsua_acc_id,pjsua_srv_pres *,pjsua_buddy_id,pj_str_t const *,pjsip_rx_data *,pjsip_status_code *,pj_str_t *,pjsua_msg_data *))&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1srv_1subscribe_1state_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  void (*arg2)(pjsua_acc_id,pjsua_srv_pres *,pj_str_t const *,pjsip_evsub_state,pjsip_event *) = (void (*)(pjsua_acc_id,pjsua_srv_pres *,pj_str_t const *,pjsip_evsub_state,pjsip_event *)) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  arg2 = *(void (**)(pjsua_acc_id,pjsua_srv_pres *,pj_str_t const *,pjsip_evsub_state,pjsip_event *))&jarg2; 
  if (arg1) (arg1)->on_srv_subscribe_state = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1srv_1subscribe_1state_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  void (*result)(pjsua_acc_id,pjsua_srv_pres *,pj_str_t const *,pjsip_evsub_state,pjsip_event *) = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  result = (void (*)(pjsua_acc_id,pjsua_srv_pres *,pj_str_t const *,pjsip_evsub_state,pjsip_event *)) ((arg1)->on_srv_subscribe_state);
  *(void (**)(pjsua_acc_id,pjsua_srv_pres *,pj_str_t const *,pjsip_evsub_state,pjsip_event *))&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1buddy_1state_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  void (*arg2)(pjsua_buddy_id) = (void (*)(pjsua_buddy_id)) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  arg2 = *(void (**)(pjsua_buddy_id))&jarg2; 
  if (arg1) (arg1)->on_buddy_state = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1buddy_1state_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  void (*result)(pjsua_buddy_id) = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  result = (void (*)(pjsua_buddy_id)) ((arg1)->on_buddy_state);
  *(void (**)(pjsua_buddy_id))&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1buddy_1evsub_1state_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  void (*arg2)(pjsua_buddy_id,pjsip_evsub *,pjsip_event *) = (void (*)(pjsua_buddy_id,pjsip_evsub *,pjsip_event *)) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  arg2 = *(void (**)(pjsua_buddy_id,pjsip_evsub *,pjsip_event *))&jarg2; 
  if (arg1) (arg1)->on_buddy_evsub_state = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1buddy_1evsub_1state_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  void (*result)(pjsua_buddy_id,pjsip_evsub *,pjsip_event *) = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  result = (void (*)(pjsua_buddy_id,pjsip_evsub *,pjsip_event *)) ((arg1)->on_buddy_evsub_state);
  *(void (**)(pjsua_buddy_id,pjsip_evsub *,pjsip_event *))&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1pager_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  void (*arg2)(pjsua_call_id,pj_str_t const *,pj_str_t const *,pj_str_t const *,pj_str_t const *,pj_str_t const *) = (void (*)(pjsua_call_id,pj_str_t const *,pj_str_t const *,pj_str_t const *,pj_str_t const *,pj_str_t const *)) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  arg2 = *(void (**)(pjsua_call_id,pj_str_t const *,pj_str_t const *,pj_str_t const *,pj_str_t const *,pj_str_t const *))&jarg2; 
  if (arg1) (arg1)->on_pager = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1pager_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  void (*result)(pjsua_call_id,pj_str_t const *,pj_str_t const *,pj_str_t const *,pj_str_t const *,pj_str_t const *) = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  result = (void (*)(pjsua_call_id,pj_str_t const *,pj_str_t const *,pj_str_t const *,pj_str_t const *,pj_str_t const *)) ((arg1)->on_pager);
  *(void (**)(pjsua_call_id,pj_str_t const *,pj_str_t const *,pj_str_t const *,pj_str_t const *,pj_str_t const *))&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1pager2_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  void (*arg2)(pjsua_call_id,pj_str_t const *,pj_str_t const *,pj_str_t const *,pj_str_t const *,pj_str_t const *,pjsip_rx_data *,pjsua_acc_id) = (void (*)(pjsua_call_id,pj_str_t const *,pj_str_t const *,pj_str_t const *,pj_str_t const *,pj_str_t const *,pjsip_rx_data *,pjsua_acc_id)) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  arg2 = *(void (**)(pjsua_call_id,pj_str_t const *,pj_str_t const *,pj_str_t const *,pj_str_t const *,pj_str_t const *,pjsip_rx_data *,pjsua_acc_id))&jarg2; 
  if (arg1) (arg1)->on_pager2 = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1pager2_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  void (*result)(pjsua_call_id,pj_str_t const *,pj_str_t const *,pj_str_t const *,pj_str_t const *,pj_str_t const *,pjsip_rx_data *,pjsua_acc_id) = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  result = (void (*)(pjsua_call_id,pj_str_t const *,pj_str_t const *,pj_str_t const *,pj_str_t const *,pj_str_t const *,pjsip_rx_data *,pjsua_acc_id)) ((arg1)->on_pager2);
  *(void (**)(pjsua_call_id,pj_str_t const *,pj_str_t const *,pj_str_t const *,pj_str_t const *,pj_str_t const *,pjsip_rx_data *,pjsua_acc_id))&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1pager_1status_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  void (*arg2)(pjsua_call_id,pj_str_t const *,pj_str_t const *,void *,pjsip_status_code,pj_str_t const *) = (void (*)(pjsua_call_id,pj_str_t const *,pj_str_t const *,void *,pjsip_status_code,pj_str_t const *)) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  arg2 = *(void (**)(pjsua_call_id,pj_str_t const *,pj_str_t const *,void *,pjsip_status_code,pj_str_t const *))&jarg2; 
  if (arg1) (arg1)->on_pager_status = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1pager_1status_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  void (*result)(pjsua_call_id,pj_str_t const *,pj_str_t const *,void *,pjsip_status_code,pj_str_t const *) = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  result = (void (*)(pjsua_call_id,pj_str_t const *,pj_str_t const *,void *,pjsip_status_code,pj_str_t const *)) ((arg1)->on_pager_status);
  *(void (**)(pjsua_call_id,pj_str_t const *,pj_str_t const *,void *,pjsip_status_code,pj_str_t const *))&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1pager_1status2_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  void (*arg2)(pjsua_call_id,pj_str_t const *,pj_str_t const *,void *,pjsip_status_code,pj_str_t const *,pjsip_tx_data *,pjsip_rx_data *,pjsua_acc_id) = (void (*)(pjsua_call_id,pj_str_t const *,pj_str_t const *,void *,pjsip_status_code,pj_str_t const *,pjsip_tx_data *,pjsip_rx_data *,pjsua_acc_id)) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  arg2 = *(void (**)(pjsua_call_id,pj_str_t const *,pj_str_t const *,void *,pjsip_status_code,pj_str_t const *,pjsip_tx_data *,pjsip_rx_data *,pjsua_acc_id))&jarg2; 
  if (arg1) (arg1)->on_pager_status2 = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1pager_1status2_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  void (*result)(pjsua_call_id,pj_str_t const *,pj_str_t const *,void *,pjsip_status_code,pj_str_t const *,pjsip_tx_data *,pjsip_rx_data *,pjsua_acc_id) = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  result = (void (*)(pjsua_call_id,pj_str_t const *,pj_str_t const *,void *,pjsip_status_code,pj_str_t const *,pjsip_tx_data *,pjsip_rx_data *,pjsua_acc_id)) ((arg1)->on_pager_status2);
  *(void (**)(pjsua_call_id,pj_str_t const *,pj_str_t const *,void *,pjsip_status_code,pj_str_t const *,pjsip_tx_data *,pjsip_rx_data *,pjsua_acc_id))&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1typing_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  void (*arg2)(pjsua_call_id,pj_str_t const *,pj_str_t const *,pj_str_t const *,pj_bool_t) = (void (*)(pjsua_call_id,pj_str_t const *,pj_str_t const *,pj_str_t const *,pj_bool_t)) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  arg2 = *(void (**)(pjsua_call_id,pj_str_t const *,pj_str_t const *,pj_str_t const *,pj_bool_t))&jarg2; 
  if (arg1) (arg1)->on_typing = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1typing_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  void (*result)(pjsua_call_id,pj_str_t const *,pj_str_t const *,pj_str_t const *,pj_bool_t) = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  result = (void (*)(pjsua_call_id,pj_str_t const *,pj_str_t const *,pj_str_t const *,pj_bool_t)) ((arg1)->on_typing);
  *(void (**)(pjsua_call_id,pj_str_t const *,pj_str_t const *,pj_str_t const *,pj_bool_t))&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1typing2_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  void (*arg2)(pjsua_call_id,pj_str_t const *,pj_str_t const *,pj_str_t const *,pj_bool_t,pjsip_rx_data *,pjsua_acc_id) = (void (*)(pjsua_call_id,pj_str_t const *,pj_str_t const *,pj_str_t const *,pj_bool_t,pjsip_rx_data *,pjsua_acc_id)) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  arg2 = *(void (**)(pjsua_call_id,pj_str_t const *,pj_str_t const *,pj_str_t const *,pj_bool_t,pjsip_rx_data *,pjsua_acc_id))&jarg2; 
  if (arg1) (arg1)->on_typing2 = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1typing2_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  void (*result)(pjsua_call_id,pj_str_t const *,pj_str_t const *,pj_str_t const *,pj_bool_t,pjsip_rx_data *,pjsua_acc_id) = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  result = (void (*)(pjsua_call_id,pj_str_t const *,pj_str_t const *,pj_str_t const *,pj_bool_t,pjsip_rx_data *,pjsua_acc_id)) ((arg1)->on_typing2);
  *(void (**)(pjsua_call_id,pj_str_t const *,pj_str_t const *,pj_str_t const *,pj_bool_t,pjsip_rx_data *,pjsua_acc_id))&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1nat_1detect_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  void (*arg2)(pj_stun_nat_detect_result const *) = (void (*)(pj_stun_nat_detect_result const *)) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  arg2 = *(void (**)(pj_stun_nat_detect_result const *))&jarg2; 
  if (arg1) (arg1)->on_nat_detect = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1nat_1detect_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  void (*result)(pj_stun_nat_detect_result const *) = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  result = (void (*)(pj_stun_nat_detect_result const *)) ((arg1)->on_nat_detect);
  *(void (**)(pj_stun_nat_detect_result const *))&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1call_1redirected_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  pjsip_redirect_op (*arg2)(pjsua_call_id,pjsip_uri const *,pjsip_event const *) = (pjsip_redirect_op (*)(pjsua_call_id,pjsip_uri const *,pjsip_event const *)) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  arg2 = *(pjsip_redirect_op (**)(pjsua_call_id,pjsip_uri const *,pjsip_event const *))&jarg2; 
  if (arg1) (arg1)->on_call_redirected = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1call_1redirected_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  pjsip_redirect_op (*result)(pjsua_call_id,pjsip_uri const *,pjsip_event const *) = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  result = (pjsip_redirect_op (*)(pjsua_call_id,pjsip_uri const *,pjsip_event const *)) ((arg1)->on_call_redirected);
  *(pjsip_redirect_op (**)(pjsua_call_id,pjsip_uri const *,pjsip_event const *))&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1mwi_1info_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  void (*arg2)(pjsua_acc_id,pjsua_mwi_info *) = (void (*)(pjsua_acc_id,pjsua_mwi_info *)) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  arg2 = *(void (**)(pjsua_acc_id,pjsua_mwi_info *))&jarg2; 
  if (arg1) (arg1)->on_mwi_info = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1mwi_1info_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  void (*result)(pjsua_acc_id,pjsua_mwi_info *) = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  result = (void (*)(pjsua_acc_id,pjsua_mwi_info *)) ((arg1)->on_mwi_info);
  *(void (**)(pjsua_acc_id,pjsua_mwi_info *))&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1transport_1state_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  pjsip_tp_state_callback arg2 ;
  pjsip_tp_state_callback *argp2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  argp2 = *(pjsip_tp_state_callback **)&jarg2; 
  if (!argp2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null pjsip_tp_state_callback");
    return ;
  }
  arg2 = *argp2; 
  if (arg1) (arg1)->on_transport_state = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1transport_1state_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  pjsip_tp_state_callback result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  result =  ((arg1)->on_transport_state);
  *(pjsip_tp_state_callback **)&jresult = new pjsip_tp_state_callback((const pjsip_tp_state_callback &)result); 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1ice_1transport_1error_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  void (*arg2)(int,pj_ice_strans_op,pj_status_t,void *) = (void (*)(int,pj_ice_strans_op,pj_status_t,void *)) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  arg2 = *(void (**)(int,pj_ice_strans_op,pj_status_t,void *))&jarg2; 
  if (arg1) (arg1)->on_ice_transport_error = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1ice_1transport_1error_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  void (*result)(int,pj_ice_strans_op,pj_status_t,void *) = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_callback **)&jarg1; 
  result = (void (*)(int,pj_ice_strans_op,pj_status_t,void *)) ((arg1)->on_ice_transport_error);
  *(void (**)(int,pj_ice_strans_op,pj_status_t,void *))&jresult = result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_new_1pjsua_1callback(JNIEnv *jenv, jclass jcls) {
  jlong jresult = 0 ;
  pjsua_callback *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  result = (pjsua_callback *)new pjsua_callback();
  *(pjsua_callback **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_delete_1pjsua_1callback(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  pjsua_callback *arg1 = (pjsua_callback *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(pjsua_callback **)&jarg1; 
  delete arg1;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1max_1calls_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_config *arg1 = (pjsua_config *) 0 ;
  unsigned int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_config **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  if (arg1) (arg1)->max_calls = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1max_1calls_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_config *arg1 = (pjsua_config *) 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_config **)&jarg1; 
  result = (unsigned int) ((arg1)->max_calls);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1thread_1cnt_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_config *arg1 = (pjsua_config *) 0 ;
  unsigned int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_config **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  if (arg1) (arg1)->thread_cnt = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1thread_1cnt_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_config *arg1 = (pjsua_config *) 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_config **)&jarg1; 
  result = (unsigned int) ((arg1)->thread_cnt);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1nameserver_1count_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_config *arg1 = (pjsua_config *) 0 ;
  unsigned int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_config **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  if (arg1) (arg1)->nameserver_count = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1nameserver_1count_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_config *arg1 = (pjsua_config *) 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_config **)&jarg1; 
  result = (unsigned int) ((arg1)->nameserver_count);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1nameserver_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlongArray jarg2) {
  pjsua_config *arg1 = (pjsua_config *) 0 ;
  pj_str_t *arg2 ;
  jlong *jarr2 ;
  jsize sz2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_config **)&jarg1; 
  {
    int i;
    if (!jarg2) {
      SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null array");
      return ;
    }
    sz2 = jenv->GetArrayLength(jarg2);
    jarr2 = jenv->GetLongArrayElements(jarg2, 0);
    if (!jarr2) {
      return ;
    }
    
    arg2 = new pj_str_t[sz2];
    
    
    
    if (!arg2) {
      SWIG_JavaThrowException(jenv, SWIG_JavaOutOfMemoryError, "array memory allocation failed");
      return ;
    }
    for (i=0; i<sz2; i++) {
      arg2[i] = **(pj_str_t **)&jarr2[i];
    }
  }
  {
    size_t ii;
    pj_str_t *b = (pj_str_t *) arg1->nameserver;
    for (ii = 0; ii < (size_t)4; ii++) b[ii] = *((pj_str_t *) arg2 + ii);
  }
  {
    int i;
    for (i=0; i<sz2; i++) {
      **(pj_str_t **)&jarr2[i] = arg2[i];
    }
    jenv->ReleaseLongArrayElements(jarg2, jarr2, 0);
  }
  delete [] arg2; 
}


SWIGEXPORT jlongArray JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1nameserver_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlongArray jresult = 0 ;
  pjsua_config *arg1 = (pjsua_config *) 0 ;
  pj_str_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_config **)&jarg1; 
  result = (pj_str_t *)(pj_str_t *) ((arg1)->nameserver);
  {
    jlong *arr;
    int i;
    jresult = jenv->NewLongArray(4);
    if (!jresult) {
      return 0;
    }
    arr = jenv->GetLongArrayElements(jresult, 0);
    if (!arr) {
      return 0;
    }
    for (i=0; i<4; i++) {
      arr[i] = 0;
      *(pj_str_t **)&arr[i] = &result[i];
    }
    jenv->ReleaseLongArrayElements(jresult, arr, 0);
  }
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1force_1lr_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_config *arg1 = (pjsua_config *) 0 ;
  pj_bool_t arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_config **)&jarg1; 
  arg2 = (pj_bool_t)jarg2; 
  if (arg1) (arg1)->force_lr = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1force_1lr_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_config *arg1 = (pjsua_config *) 0 ;
  pj_bool_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_config **)&jarg1; 
  result = (pj_bool_t) ((arg1)->force_lr);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1outbound_1proxy_1cnt_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_config *arg1 = (pjsua_config *) 0 ;
  unsigned int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_config **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  if (arg1) (arg1)->outbound_proxy_cnt = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1outbound_1proxy_1cnt_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_config *arg1 = (pjsua_config *) 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_config **)&jarg1; 
  result = (unsigned int) ((arg1)->outbound_proxy_cnt);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1outbound_1proxy_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlongArray jarg2) {
  pjsua_config *arg1 = (pjsua_config *) 0 ;
  pj_str_t *arg2 ;
  jlong *jarr2 ;
  jsize sz2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_config **)&jarg1; 
  {
    int i;
    if (!jarg2) {
      SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null array");
      return ;
    }
    sz2 = jenv->GetArrayLength(jarg2);
    if (sz2 != 4) {
      SWIG_JavaThrowException(jenv, SWIG_JavaIndexOutOfBoundsException, "incorrect array size");
      return ;
    }
    jarr2 = jenv->GetLongArrayElements(jarg2, 0);
    if (!jarr2) {
      return ;
    }
    
    arg2 = new pj_str_t[sz2];
    
    
    
    if (!arg2) {
      SWIG_JavaThrowException(jenv, SWIG_JavaOutOfMemoryError, "array memory allocation failed");
      return ;
    }
    for (i=0; i<sz2; i++) {
      arg2[i] = **(pj_str_t **)&jarr2[i];
    }
  }
  {
    size_t ii;
    pj_str_t *b = (pj_str_t *) arg1->outbound_proxy;
    for (ii = 0; ii < (size_t)4; ii++) b[ii] = *((pj_str_t *) arg2 + ii);
  }
  {
    int i;
    for (i=0; i<sz2; i++) {
      **(pj_str_t **)&jarr2[i] = arg2[i];
    }
    jenv->ReleaseLongArrayElements(jarg2, jarr2, 0);
  }
  delete [] arg2; 
}


SWIGEXPORT jlongArray JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1outbound_1proxy_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlongArray jresult = 0 ;
  pjsua_config *arg1 = (pjsua_config *) 0 ;
  pj_str_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_config **)&jarg1; 
  result = (pj_str_t *)(pj_str_t *) ((arg1)->outbound_proxy);
  {
    jlong *arr;
    int i;
    jresult = jenv->NewLongArray(4);
    if (!jresult) {
      return 0;
    }
    arr = jenv->GetLongArrayElements(jresult, 0);
    if (!arr) {
      return 0;
    }
    for (i=0; i<4; i++) {
      arr[i] = 0;
      *(pj_str_t **)&arr[i] = &result[i];
    }
    jenv->ReleaseLongArrayElements(jresult, arr, 0);
  }
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1stun_1domain_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_) {
  pjsua_config *arg1 = (pjsua_config *) 0 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(pjsua_config **)&jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  if (arg1) (arg1)->stun_domain = *arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1stun_1domain_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_config *arg1 = (pjsua_config *) 0 ;
  pj_str_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_config **)&jarg1; 
  result = (pj_str_t *)& ((arg1)->stun_domain);
  *(pj_str_t **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1stun_1host_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_) {
  pjsua_config *arg1 = (pjsua_config *) 0 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(pjsua_config **)&jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  if (arg1) (arg1)->stun_host = *arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1stun_1host_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_config *arg1 = (pjsua_config *) 0 ;
  pj_str_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_config **)&jarg1; 
  result = (pj_str_t *)& ((arg1)->stun_host);
  *(pj_str_t **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1stun_1srv_1cnt_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_config *arg1 = (pjsua_config *) 0 ;
  unsigned int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_config **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  if (arg1) (arg1)->stun_srv_cnt = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1stun_1srv_1cnt_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_config *arg1 = (pjsua_config *) 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_config **)&jarg1; 
  result = (unsigned int) ((arg1)->stun_srv_cnt);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1stun_1srv_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlongArray jarg2) {
  pjsua_config *arg1 = (pjsua_config *) 0 ;
  pj_str_t *arg2 ;
  jlong *jarr2 ;
  jsize sz2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_config **)&jarg1; 
  {
    int i;
    if (!jarg2) {
      SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null array");
      return ;
    }
    sz2 = jenv->GetArrayLength(jarg2);
    if (sz2 != 8) {
      SWIG_JavaThrowException(jenv, SWIG_JavaIndexOutOfBoundsException, "incorrect array size");
      return ;
    }
    jarr2 = jenv->GetLongArrayElements(jarg2, 0);
    if (!jarr2) {
      return ;
    }
    
    arg2 = new pj_str_t[sz2];
    
    
    
    if (!arg2) {
      SWIG_JavaThrowException(jenv, SWIG_JavaOutOfMemoryError, "array memory allocation failed");
      return ;
    }
    for (i=0; i<sz2; i++) {
      arg2[i] = **(pj_str_t **)&jarr2[i];
    }
  }
  {
    size_t ii;
    pj_str_t *b = (pj_str_t *) arg1->stun_srv;
    for (ii = 0; ii < (size_t)8; ii++) b[ii] = *((pj_str_t *) arg2 + ii);
  }
  {
    int i;
    for (i=0; i<sz2; i++) {
      **(pj_str_t **)&jarr2[i] = arg2[i];
    }
    jenv->ReleaseLongArrayElements(jarg2, jarr2, 0);
  }
  delete [] arg2; 
}


SWIGEXPORT jlongArray JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1stun_1srv_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlongArray jresult = 0 ;
  pjsua_config *arg1 = (pjsua_config *) 0 ;
  pj_str_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_config **)&jarg1; 
  result = (pj_str_t *)(pj_str_t *) ((arg1)->stun_srv);
  {
    jlong *arr;
    int i;
    jresult = jenv->NewLongArray(8);
    if (!jresult) {
      return 0;
    }
    arr = jenv->GetLongArrayElements(jresult, 0);
    if (!arr) {
      return 0;
    }
    for (i=0; i<8; i++) {
      arr[i] = 0;
      *(pj_str_t **)&arr[i] = &result[i];
    }
    jenv->ReleaseLongArrayElements(jresult, arr, 0);
  }
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1stun_1ignore_1failure_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_config *arg1 = (pjsua_config *) 0 ;
  pj_bool_t arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_config **)&jarg1; 
  arg2 = (pj_bool_t)jarg2; 
  if (arg1) (arg1)->stun_ignore_failure = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1stun_1ignore_1failure_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_config *arg1 = (pjsua_config *) 0 ;
  pj_bool_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_config **)&jarg1; 
  result = (pj_bool_t) ((arg1)->stun_ignore_failure);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1nat_1type_1in_1sdp_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_config *arg1 = (pjsua_config *) 0 ;
  int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_config **)&jarg1; 
  arg2 = (int)jarg2; 
  if (arg1) (arg1)->nat_type_in_sdp = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1nat_1type_1in_1sdp_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_config *arg1 = (pjsua_config *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_config **)&jarg1; 
  result = (int) ((arg1)->nat_type_in_sdp);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1require_1100rel_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_config *arg1 = (pjsua_config *) 0 ;
  pj_bool_t arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_config **)&jarg1; 
  arg2 = (pj_bool_t)jarg2; 
  if (arg1) (arg1)->require_100rel = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1require_1100rel_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_config *arg1 = (pjsua_config *) 0 ;
  pj_bool_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_config **)&jarg1; 
  result = (pj_bool_t) ((arg1)->require_100rel);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1use_1timer_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_config *arg1 = (pjsua_config *) 0 ;
  pjsua_sip_timer_use arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_config **)&jarg1; 
  arg2 = (pjsua_sip_timer_use)jarg2; 
  if (arg1) (arg1)->use_timer = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1use_1timer_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_config *arg1 = (pjsua_config *) 0 ;
  pjsua_sip_timer_use result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_config **)&jarg1; 
  result = (pjsua_sip_timer_use) ((arg1)->use_timer);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1enable_1unsolicited_1mwi_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_config *arg1 = (pjsua_config *) 0 ;
  pj_bool_t arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_config **)&jarg1; 
  arg2 = (pj_bool_t)jarg2; 
  if (arg1) (arg1)->enable_unsolicited_mwi = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1enable_1unsolicited_1mwi_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_config *arg1 = (pjsua_config *) 0 ;
  pj_bool_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_config **)&jarg1; 
  result = (pj_bool_t) ((arg1)->enable_unsolicited_mwi);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1timer_1setting_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_config *arg1 = (pjsua_config *) 0 ;
  pjsip_timer_setting arg2 ;
  pjsip_timer_setting *argp2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_config **)&jarg1; 
  argp2 = *(pjsip_timer_setting **)&jarg2; 
  if (!argp2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null pjsip_timer_setting");
    return ;
  }
  arg2 = *argp2; 
  if (arg1) (arg1)->timer_setting = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1timer_1setting_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_config *arg1 = (pjsua_config *) 0 ;
  pjsip_timer_setting result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_config **)&jarg1; 
  result =  ((arg1)->timer_setting);
  *(pjsip_timer_setting **)&jresult = new pjsip_timer_setting((const pjsip_timer_setting &)result); 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1cred_1count_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_config *arg1 = (pjsua_config *) 0 ;
  unsigned int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_config **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  if (arg1) (arg1)->cred_count = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1cred_1count_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_config *arg1 = (pjsua_config *) 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_config **)&jarg1; 
  result = (unsigned int) ((arg1)->cred_count);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1cred_1info_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_) {
  pjsua_config *arg1 = (pjsua_config *) 0 ;
  pjsip_cred_info *arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(pjsua_config **)&jarg1; 
  arg2 = *(pjsip_cred_info **)&jarg2; 
  {
    size_t ii;
    pjsip_cred_info *b = (pjsip_cred_info *) arg1->cred_info;
    for (ii = 0; ii < (size_t)8; ii++) b[ii] = *((pjsip_cred_info *) arg2 + ii);
  }
  
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1cred_1info_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_config *arg1 = (pjsua_config *) 0 ;
  pjsip_cred_info *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_config **)&jarg1; 
  result = (pjsip_cred_info *)(pjsip_cred_info *) ((arg1)->cred_info);
  *(pjsip_cred_info **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1cb_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_) {
  pjsua_config *arg1 = (pjsua_config *) 0 ;
  pjsua_callback *arg2 = (pjsua_callback *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(pjsua_config **)&jarg1; 
  arg2 = *(pjsua_callback **)&jarg2; 
  if (arg1) (arg1)->cb = *arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1cb_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_config *arg1 = (pjsua_config *) 0 ;
  pjsua_callback *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_config **)&jarg1; 
  result = (pjsua_callback *)& ((arg1)->cb);
  *(pjsua_callback **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1user_1agent_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_) {
  pjsua_config *arg1 = (pjsua_config *) 0 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(pjsua_config **)&jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  if (arg1) (arg1)->user_agent = *arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1user_1agent_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_config *arg1 = (pjsua_config *) 0 ;
  pj_str_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_config **)&jarg1; 
  result = (pj_str_t *)& ((arg1)->user_agent);
  *(pj_str_t **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1use_1srtp_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_config *arg1 = (pjsua_config *) 0 ;
  pjmedia_srtp_use arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_config **)&jarg1; 
  arg2 = (pjmedia_srtp_use)jarg2; 
  if (arg1) (arg1)->use_srtp = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1use_1srtp_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_config *arg1 = (pjsua_config *) 0 ;
  pjmedia_srtp_use result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_config **)&jarg1; 
  result = (pjmedia_srtp_use) ((arg1)->use_srtp);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1srtp_1secure_1signaling_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_config *arg1 = (pjsua_config *) 0 ;
  int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_config **)&jarg1; 
  arg2 = (int)jarg2; 
  if (arg1) (arg1)->srtp_secure_signaling = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1srtp_1secure_1signaling_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_config *arg1 = (pjsua_config *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_config **)&jarg1; 
  result = (int) ((arg1)->srtp_secure_signaling);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1srtp_1optional_1dup_1offer_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_config *arg1 = (pjsua_config *) 0 ;
  pj_bool_t arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_config **)&jarg1; 
  arg2 = (pj_bool_t)jarg2; 
  if (arg1) (arg1)->srtp_optional_dup_offer = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1srtp_1optional_1dup_1offer_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_config *arg1 = (pjsua_config *) 0 ;
  pj_bool_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_config **)&jarg1; 
  result = (pj_bool_t) ((arg1)->srtp_optional_dup_offer);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1hangup_1forked_1call_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_config *arg1 = (pjsua_config *) 0 ;
  pj_bool_t arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_config **)&jarg1; 
  arg2 = (pj_bool_t)jarg2; 
  if (arg1) (arg1)->hangup_forked_call = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1hangup_1forked_1call_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_config *arg1 = (pjsua_config *) 0 ;
  pj_bool_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_config **)&jarg1; 
  result = (pj_bool_t) ((arg1)->hangup_forked_call);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_new_1pjsua_1config(JNIEnv *jenv, jclass jcls) {
  jlong jresult = 0 ;
  pjsua_config *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  result = (pjsua_config *)new pjsua_config();
  *(pjsua_config **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_delete_1pjsua_1config(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  pjsua_config *arg1 = (pjsua_config *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(pjsua_config **)&jarg1; 
  delete arg1;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_config_1default(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  pjsua_config *arg1 = (pjsua_config *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_config **)&jarg1; 
  pjsua_config_default(arg1);
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_config_1dup(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_, jlong jarg3, jobject jarg3_) {
  pj_pool_t *arg1 = (pj_pool_t *) 0 ;
  pjsua_config *arg2 = (pjsua_config *) 0 ;
  pjsua_config *arg3 = (pjsua_config *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  (void)jarg3_;
  arg1 = *(pj_pool_t **)&jarg1; 
  arg2 = *(pjsua_config **)&jarg2; 
  arg3 = *(pjsua_config **)&jarg3; 
  pjsua_config_dup(arg1,arg2,(pjsua_config const *)arg3);
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1msg_1data_1hdr_1list_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2) {
  pjsua_msg_data *arg1 = (pjsua_msg_data *) 0 ;
  pjsip_hdr arg2 ;
  pjsip_hdr *argp2 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(pjsua_msg_data **)&jarg1; 
  argp2 = *(pjsip_hdr **)&jarg2; 
  if (!argp2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null pjsip_hdr");
    return ;
  }
  arg2 = *argp2; 
  if (arg1) (arg1)->hdr_list = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1msg_1data_1hdr_1list_1get(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  jlong jresult = 0 ;
  pjsua_msg_data *arg1 = (pjsua_msg_data *) 0 ;
  pjsip_hdr result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(pjsua_msg_data **)&jarg1; 
  result =  ((arg1)->hdr_list);
  *(pjsip_hdr **)&jresult = new pjsip_hdr((const pjsip_hdr &)result); 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1msg_1data_1content_1type_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2, jobject jarg2_) {
  pjsua_msg_data *arg1 = (pjsua_msg_data *) 0 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg2_;
  arg1 = *(pjsua_msg_data **)&jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  if (arg1) (arg1)->content_type = *arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1msg_1data_1content_1type_1get(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  jlong jresult = 0 ;
  pjsua_msg_data *arg1 = (pjsua_msg_data *) 0 ;
  pj_str_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(pjsua_msg_data **)&jarg1; 
  result = (pj_str_t *)& ((arg1)->content_type);
  *(pj_str_t **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1msg_1data_1msg_1body_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2, jobject jarg2_) {
  pjsua_msg_data *arg1 = (pjsua_msg_data *) 0 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg2_;
  arg1 = *(pjsua_msg_data **)&jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  if (arg1) (arg1)->msg_body = *arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1msg_1data_1msg_1body_1get(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  jlong jresult = 0 ;
  pjsua_msg_data *arg1 = (pjsua_msg_data *) 0 ;
  pj_str_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(pjsua_msg_data **)&jarg1; 
  result = (pj_str_t *)& ((arg1)->msg_body);
  *(pj_str_t **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1msg_1data_1multipart_1ctype_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2) {
  pjsua_msg_data *arg1 = (pjsua_msg_data *) 0 ;
  pjsip_media_type arg2 ;
  pjsip_media_type *argp2 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(pjsua_msg_data **)&jarg1; 
  argp2 = *(pjsip_media_type **)&jarg2; 
  if (!argp2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null pjsip_media_type");
    return ;
  }
  arg2 = *argp2; 
  if (arg1) (arg1)->multipart_ctype = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1msg_1data_1multipart_1ctype_1get(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  jlong jresult = 0 ;
  pjsua_msg_data *arg1 = (pjsua_msg_data *) 0 ;
  pjsip_media_type result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(pjsua_msg_data **)&jarg1; 
  result =  ((arg1)->multipart_ctype);
  *(pjsip_media_type **)&jresult = new pjsip_media_type((const pjsip_media_type &)result); 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1msg_1data_1multipart_1parts_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2) {
  pjsua_msg_data *arg1 = (pjsua_msg_data *) 0 ;
  pjsip_multipart_part arg2 ;
  pjsip_multipart_part *argp2 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(pjsua_msg_data **)&jarg1; 
  argp2 = *(pjsip_multipart_part **)&jarg2; 
  if (!argp2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null pjsip_multipart_part");
    return ;
  }
  arg2 = *argp2; 
  if (arg1) (arg1)->multipart_parts = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1msg_1data_1multipart_1parts_1get(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  jlong jresult = 0 ;
  pjsua_msg_data *arg1 = (pjsua_msg_data *) 0 ;
  pjsip_multipart_part result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(pjsua_msg_data **)&jarg1; 
  result =  ((arg1)->multipart_parts);
  *(pjsip_multipart_part **)&jresult = new pjsip_multipart_part((const pjsip_multipart_part &)result); 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_new_1pjsua_1msg_1data(JNIEnv *jenv, jclass jcls) {
  jlong jresult = 0 ;
  pjsua_msg_data *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  result = (pjsua_msg_data *)new pjsua_msg_data();
  *(pjsua_msg_data **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_delete_1pjsua_1msg_1data(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  pjsua_msg_data *arg1 = (pjsua_msg_data *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(pjsua_msg_data **)&jarg1; 
  delete arg1;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_msg_1data_1init(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  pjsua_msg_data *arg1 = (pjsua_msg_data *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(pjsua_msg_data **)&jarg1; 
  pjsua_msg_data_init(arg1);
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_create(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  result = (pj_status_t)pjsua_create();
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_start(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  result = (pj_status_t)pjsua_start();
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_handle_1events(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  jint jresult = 0 ;
  unsigned int arg1 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (unsigned int)jarg1; 
  result = (int)pjsua_handle_events(arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pool_1create(JNIEnv *jenv, jclass jcls, jstring jarg1, jlong jarg2, jlong jarg3) {
  jlong jresult = 0 ;
  char *arg1 = (char *) 0 ;
  pj_size_t arg2 ;
  pj_size_t arg3 ;
  pj_pool_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = 0;
  if (jarg1) {
    arg1 = (char *)jenv->GetStringUTFChars(jarg1, 0);
    if (!arg1) return 0;
  }
  arg2 = (pj_size_t)jarg2; 
  arg3 = (pj_size_t)jarg3; 
  result = (pj_pool_t *)pjsua_pool_create((char const *)arg1,arg2,arg3);
  *(pj_pool_t **)&jresult = result; 
  if (arg1) jenv->ReleaseStringUTFChars(jarg1, (const char *)arg1);
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_reconfigure_1logging(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_logging_config *arg1 = (pjsua_logging_config *) 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_logging_config **)&jarg1; 
  result = (pj_status_t)pjsua_reconfigure_logging((pjsua_logging_config const *)arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_get_1pjsip_1endpt(JNIEnv *jenv, jclass jcls) {
  jlong jresult = 0 ;
  pjsip_endpoint *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_endpoint *)pjsua_get_pjsip_endpt();
  *(pjsip_endpoint **)&jresult = result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_get_1pjmedia_1endpt(JNIEnv *jenv, jclass jcls) {
  jlong jresult = 0 ;
  pjmedia_endpt *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  result = (pjmedia_endpt *)pjsua_get_pjmedia_endpt();
  *(pjmedia_endpt **)&jresult = result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_get_1pool_1factory(JNIEnv *jenv, jclass jcls) {
  jlong jresult = 0 ;
  pj_pool_factory *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  result = (pj_pool_factory *)pjsua_get_pool_factory();
  *(pj_pool_factory **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pj_1stun_1resolve_1result_1token_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, void * jarg2) {
  pj_stun_resolve_result *arg1 = (pj_stun_resolve_result *) 0 ;
  void *arg2 = (void *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pj_stun_resolve_result **)&jarg1; 
  
  arg2 = jarg2;
  
  if (arg1) (arg1)->token = arg2;
}


SWIGEXPORT void * JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pj_1stun_1resolve_1result_1token_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  void * jresult = 0 ;
  pj_stun_resolve_result *arg1 = (pj_stun_resolve_result *) 0 ;
  void *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pj_stun_resolve_result **)&jarg1; 
  result = (void *) ((arg1)->token);
  
  jresult = result; 
  
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pj_1stun_1resolve_1result_1status_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pj_stun_resolve_result *arg1 = (pj_stun_resolve_result *) 0 ;
  pj_status_t arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pj_stun_resolve_result **)&jarg1; 
  arg2 = (pj_status_t)jarg2; 
  if (arg1) (arg1)->status = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pj_1stun_1resolve_1result_1status_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pj_stun_resolve_result *arg1 = (pj_stun_resolve_result *) 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pj_stun_resolve_result **)&jarg1; 
  result = (pj_status_t) ((arg1)->status);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pj_1stun_1resolve_1result_1name_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_) {
  pj_stun_resolve_result *arg1 = (pj_stun_resolve_result *) 0 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(pj_stun_resolve_result **)&jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  if (arg1) (arg1)->name = *arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pj_1stun_1resolve_1result_1name_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pj_stun_resolve_result *arg1 = (pj_stun_resolve_result *) 0 ;
  pj_str_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pj_stun_resolve_result **)&jarg1; 
  result = (pj_str_t *)& ((arg1)->name);
  *(pj_str_t **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pj_1stun_1resolve_1result_1addr_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pj_stun_resolve_result *arg1 = (pj_stun_resolve_result *) 0 ;
  pj_sockaddr arg2 ;
  pj_sockaddr *argp2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pj_stun_resolve_result **)&jarg1; 
  argp2 = *(pj_sockaddr **)&jarg2; 
  if (!argp2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null pj_sockaddr");
    return ;
  }
  arg2 = *argp2; 
  if (arg1) (arg1)->addr = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pj_1stun_1resolve_1result_1addr_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pj_stun_resolve_result *arg1 = (pj_stun_resolve_result *) 0 ;
  pj_sockaddr result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pj_stun_resolve_result **)&jarg1; 
  result =  ((arg1)->addr);
  *(pj_sockaddr **)&jresult = new pj_sockaddr((const pj_sockaddr &)result); 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_new_1pj_1stun_1resolve_1result(JNIEnv *jenv, jclass jcls) {
  jlong jresult = 0 ;
  pj_stun_resolve_result *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  result = (pj_stun_resolve_result *)new pj_stun_resolve_result();
  *(pj_stun_resolve_result **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_delete_1pj_1stun_1resolve_1result(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  pj_stun_resolve_result *arg1 = (pj_stun_resolve_result *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(pj_stun_resolve_result **)&jarg1; 
  delete arg1;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_detect_1nat_1type(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  result = (pj_status_t)pjsua_detect_nat_type();
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_get_1nat_1type(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  jint jresult = 0 ;
  pj_stun_nat_type *arg1 = (pj_stun_nat_type *) 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(pj_stun_nat_type **)&jarg1; 
  result = (pj_status_t)pjsua_get_nat_type(arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_resolve_1stun_1servers(JNIEnv *jenv, jclass jcls, jlong jarg1, jlongArray jarg2, jint jarg3, void * jarg4, jlong jarg5) {
  jint jresult = 0 ;
  unsigned int arg1 ;
  pj_str_t *arg2 ;
  pj_bool_t arg3 ;
  void *arg4 = (void *) 0 ;
  pj_stun_resolve_cb arg5 = (pj_stun_resolve_cb) 0 ;
  jlong *jarr2 ;
  jsize sz2 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (unsigned int)jarg1; 
  {
    int i;
    if (!jarg2) {
      SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null array");
      return 0;
    }
    sz2 = jenv->GetArrayLength(jarg2);
    jarr2 = jenv->GetLongArrayElements(jarg2, 0);
    if (!jarr2) {
      return 0;
    }
    
    arg2 = new pj_str_t[sz2];
    
    
    
    if (!arg2) {
      SWIG_JavaThrowException(jenv, SWIG_JavaOutOfMemoryError, "array memory allocation failed");
      return 0;
    }
    for (i=0; i<sz2; i++) {
      arg2[i] = **(pj_str_t **)&jarr2[i];
    }
  }
  arg3 = (pj_bool_t)jarg3; 
  
  arg4 = jarg4;
  
  arg5 = *(pj_stun_resolve_cb *)&jarg5; 
  result = (pj_status_t)pjsua_resolve_stun_servers(arg1,arg2,arg3,arg4,arg5);
  jresult = (jint)result; 
  {
    int i;
    for (i=0; i<sz2; i++) {
      **(pj_str_t **)&jarr2[i] = arg2[i];
    }
    jenv->ReleaseLongArrayElements(jarg2, jarr2, 0);
  }
  delete [] arg2; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_cancel_1stun_1resolution(JNIEnv *jenv, jclass jcls, void * jarg1, jint jarg2) {
  jint jresult = 0 ;
  void *arg1 = (void *) 0 ;
  pj_bool_t arg2 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  
  arg1 = jarg1;
  
  arg2 = (pj_bool_t)jarg2; 
  result = (pj_status_t)pjsua_cancel_stun_resolution(arg1,arg2);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_verify_1sip_1url(JNIEnv *jenv, jclass jcls, jstring jarg1) {
  jint jresult = 0 ;
  char *arg1 = (char *) 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  arg1 = 0;
  if (jarg1) {
    arg1 = (char *)jenv->GetStringUTFChars(jarg1, 0);
    if (!arg1) return 0;
  }
  result = (pj_status_t)pjsua_verify_sip_url((char const *)arg1);
  jresult = (jint)result; 
  if (arg1) jenv->ReleaseStringUTFChars(jarg1, (const char *)arg1);
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_verify_1url(JNIEnv *jenv, jclass jcls, jstring jarg1) {
  jint jresult = 0 ;
  char *arg1 = (char *) 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  arg1 = 0;
  if (jarg1) {
    arg1 = (char *)jenv->GetStringUTFChars(jarg1, 0);
    if (!arg1) return 0;
  }
  result = (pj_status_t)pjsua_verify_url((char const *)arg1);
  jresult = (jint)result; 
  if (arg1) jenv->ReleaseStringUTFChars(jarg1, (const char *)arg1);
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_schedule_1timer(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2) {
  jint jresult = 0 ;
  pj_timer_entry *arg1 = (pj_timer_entry *) 0 ;
  pj_time_val *arg2 = (pj_time_val *) 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(pj_timer_entry **)&jarg1; 
  arg2 = *(pj_time_val **)&jarg2; 
  result = (pj_status_t)pjsua_schedule_timer(arg1,(pj_time_val const *)arg2);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_cancel_1timer(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  pj_timer_entry *arg1 = (pj_timer_entry *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(pj_timer_entry **)&jarg1; 
  pjsua_cancel_timer(arg1);
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_perror(JNIEnv *jenv, jclass jcls, jstring jarg1, jstring jarg2, jint jarg3) {
  char *arg1 = (char *) 0 ;
  char *arg2 = (char *) 0 ;
  pj_status_t arg3 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = 0;
  if (jarg1) {
    arg1 = (char *)jenv->GetStringUTFChars(jarg1, 0);
    if (!arg1) return ;
  }
  arg2 = 0;
  if (jarg2) {
    arg2 = (char *)jenv->GetStringUTFChars(jarg2, 0);
    if (!arg2) return ;
  }
  arg3 = (pj_status_t)jarg3; 
  pjsua_perror((char const *)arg1,(char const *)arg2,arg3);
  if (arg1) jenv->ReleaseStringUTFChars(jarg1, (const char *)arg1);
  if (arg2) jenv->ReleaseStringUTFChars(jarg2, (const char *)arg2);
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_dump(JNIEnv *jenv, jclass jcls, jint jarg1) {
  pj_bool_t arg1 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = (pj_bool_t)jarg1; 
  pjsua_dump(arg1);
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1config_1port_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_transport_config *arg1 = (pjsua_transport_config *) 0 ;
  unsigned int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_transport_config **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  if (arg1) (arg1)->port = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1config_1port_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_transport_config *arg1 = (pjsua_transport_config *) 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_transport_config **)&jarg1; 
  result = (unsigned int) ((arg1)->port);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1config_1public_1addr_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_) {
  pjsua_transport_config *arg1 = (pjsua_transport_config *) 0 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(pjsua_transport_config **)&jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  if (arg1) (arg1)->public_addr = *arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1config_1public_1addr_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_transport_config *arg1 = (pjsua_transport_config *) 0 ;
  pj_str_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_transport_config **)&jarg1; 
  result = (pj_str_t *)& ((arg1)->public_addr);
  *(pj_str_t **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1config_1bound_1addr_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_) {
  pjsua_transport_config *arg1 = (pjsua_transport_config *) 0 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(pjsua_transport_config **)&jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  if (arg1) (arg1)->bound_addr = *arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1config_1bound_1addr_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_transport_config *arg1 = (pjsua_transport_config *) 0 ;
  pj_str_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_transport_config **)&jarg1; 
  result = (pj_str_t *)& ((arg1)->bound_addr);
  *(pj_str_t **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1config_1tls_1setting_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_) {
  pjsua_transport_config *arg1 = (pjsua_transport_config *) 0 ;
  pjsip_tls_setting *arg2 = (pjsip_tls_setting *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(pjsua_transport_config **)&jarg1; 
  arg2 = *(pjsip_tls_setting **)&jarg2; 
  if (arg1) (arg1)->tls_setting = *arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1config_1tls_1setting_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_transport_config *arg1 = (pjsua_transport_config *) 0 ;
  pjsip_tls_setting *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_transport_config **)&jarg1; 
  result = (pjsip_tls_setting *)& ((arg1)->tls_setting);
  *(pjsip_tls_setting **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1config_1qos_1type_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_transport_config *arg1 = (pjsua_transport_config *) 0 ;
  pj_qos_type arg2 ;
  pj_qos_type *argp2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_transport_config **)&jarg1; 
  argp2 = *(pj_qos_type **)&jarg2; 
  if (!argp2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null pj_qos_type");
    return ;
  }
  arg2 = *argp2; 
  if (arg1) (arg1)->qos_type = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1config_1qos_1type_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_transport_config *arg1 = (pjsua_transport_config *) 0 ;
  pj_qos_type result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_transport_config **)&jarg1; 
  result =  ((arg1)->qos_type);
  *(pj_qos_type **)&jresult = new pj_qos_type((const pj_qos_type &)result); 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1config_1qos_1params_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_transport_config *arg1 = (pjsua_transport_config *) 0 ;
  pj_qos_params arg2 ;
  pj_qos_params *argp2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_transport_config **)&jarg1; 
  argp2 = *(pj_qos_params **)&jarg2; 
  if (!argp2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null pj_qos_params");
    return ;
  }
  arg2 = *argp2; 
  if (arg1) (arg1)->qos_params = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1config_1qos_1params_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_transport_config *arg1 = (pjsua_transport_config *) 0 ;
  pj_qos_params result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_transport_config **)&jarg1; 
  result =  ((arg1)->qos_params);
  *(pj_qos_params **)&jresult = new pj_qos_params((const pj_qos_params &)result); 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_new_1pjsua_1transport_1config(JNIEnv *jenv, jclass jcls) {
  jlong jresult = 0 ;
  pjsua_transport_config *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  result = (pjsua_transport_config *)new pjsua_transport_config();
  *(pjsua_transport_config **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_delete_1pjsua_1transport_1config(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  pjsua_transport_config *arg1 = (pjsua_transport_config *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(pjsua_transport_config **)&jarg1; 
  delete arg1;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_transport_1config_1default(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  pjsua_transport_config *arg1 = (pjsua_transport_config *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_transport_config **)&jarg1; 
  pjsua_transport_config_default(arg1);
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_transport_1config_1dup(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_, jlong jarg3, jobject jarg3_) {
  pj_pool_t *arg1 = (pj_pool_t *) 0 ;
  pjsua_transport_config *arg2 = (pjsua_transport_config *) 0 ;
  pjsua_transport_config *arg3 = (pjsua_transport_config *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  (void)jarg3_;
  arg1 = *(pj_pool_t **)&jarg1; 
  arg2 = *(pjsua_transport_config **)&jarg2; 
  arg3 = *(pjsua_transport_config **)&jarg3; 
  pjsua_transport_config_dup(arg1,arg2,(pjsua_transport_config const *)arg3);
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1info_1id_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_transport_info *arg1 = (pjsua_transport_info *) 0 ;
  pjsua_transport_id arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_transport_info **)&jarg1; 
  arg2 = (pjsua_transport_id)jarg2; 
  if (arg1) (arg1)->id = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1info_1id_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_transport_info *arg1 = (pjsua_transport_info *) 0 ;
  pjsua_transport_id result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_transport_info **)&jarg1; 
  result = (pjsua_transport_id) ((arg1)->id);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1info_1type_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_transport_info *arg1 = (pjsua_transport_info *) 0 ;
  pjsip_transport_type_e arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_transport_info **)&jarg1; 
  arg2 = (pjsip_transport_type_e)jarg2; 
  if (arg1) (arg1)->type = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1info_1type_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_transport_info *arg1 = (pjsua_transport_info *) 0 ;
  pjsip_transport_type_e result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_transport_info **)&jarg1; 
  result = (pjsip_transport_type_e) ((arg1)->type);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1info_1type_1name_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_) {
  pjsua_transport_info *arg1 = (pjsua_transport_info *) 0 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(pjsua_transport_info **)&jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  if (arg1) (arg1)->type_name = *arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1info_1type_1name_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_transport_info *arg1 = (pjsua_transport_info *) 0 ;
  pj_str_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_transport_info **)&jarg1; 
  result = (pj_str_t *)& ((arg1)->type_name);
  *(pj_str_t **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1info_1info_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_) {
  pjsua_transport_info *arg1 = (pjsua_transport_info *) 0 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(pjsua_transport_info **)&jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  if (arg1) (arg1)->info = *arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1info_1info_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_transport_info *arg1 = (pjsua_transport_info *) 0 ;
  pj_str_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_transport_info **)&jarg1; 
  result = (pj_str_t *)& ((arg1)->info);
  *(pj_str_t **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1info_1flag_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_transport_info *arg1 = (pjsua_transport_info *) 0 ;
  unsigned int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_transport_info **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  if (arg1) (arg1)->flag = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1info_1flag_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_transport_info *arg1 = (pjsua_transport_info *) 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_transport_info **)&jarg1; 
  result = (unsigned int) ((arg1)->flag);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1info_1addr_1len_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_transport_info *arg1 = (pjsua_transport_info *) 0 ;
  unsigned int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_transport_info **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  if (arg1) (arg1)->addr_len = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1info_1addr_1len_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_transport_info *arg1 = (pjsua_transport_info *) 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_transport_info **)&jarg1; 
  result = (unsigned int) ((arg1)->addr_len);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1info_1local_1addr_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_transport_info *arg1 = (pjsua_transport_info *) 0 ;
  pj_sockaddr arg2 ;
  pj_sockaddr *argp2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_transport_info **)&jarg1; 
  argp2 = *(pj_sockaddr **)&jarg2; 
  if (!argp2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null pj_sockaddr");
    return ;
  }
  arg2 = *argp2; 
  if (arg1) (arg1)->local_addr = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1info_1local_1addr_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_transport_info *arg1 = (pjsua_transport_info *) 0 ;
  pj_sockaddr result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_transport_info **)&jarg1; 
  result =  ((arg1)->local_addr);
  *(pj_sockaddr **)&jresult = new pj_sockaddr((const pj_sockaddr &)result); 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1info_1local_1name_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_transport_info *arg1 = (pjsua_transport_info *) 0 ;
  pjsip_host_port arg2 ;
  pjsip_host_port *argp2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_transport_info **)&jarg1; 
  argp2 = *(pjsip_host_port **)&jarg2; 
  if (!argp2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null pjsip_host_port");
    return ;
  }
  arg2 = *argp2; 
  if (arg1) (arg1)->local_name = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1info_1local_1name_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_transport_info *arg1 = (pjsua_transport_info *) 0 ;
  pjsip_host_port result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_transport_info **)&jarg1; 
  result =  ((arg1)->local_name);
  *(pjsip_host_port **)&jresult = new pjsip_host_port((const pjsip_host_port &)result); 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1info_1usage_1count_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_transport_info *arg1 = (pjsua_transport_info *) 0 ;
  unsigned int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_transport_info **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  if (arg1) (arg1)->usage_count = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1info_1usage_1count_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_transport_info *arg1 = (pjsua_transport_info *) 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_transport_info **)&jarg1; 
  result = (unsigned int) ((arg1)->usage_count);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_new_1pjsua_1transport_1info(JNIEnv *jenv, jclass jcls) {
  jlong jresult = 0 ;
  pjsua_transport_info *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  result = (pjsua_transport_info *)new pjsua_transport_info();
  *(pjsua_transport_info **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_delete_1pjsua_1transport_1info(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  pjsua_transport_info *arg1 = (pjsua_transport_info *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(pjsua_transport_info **)&jarg1; 
  delete arg1;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_transport_1create(JNIEnv *jenv, jclass jcls, jint jarg1, jlong jarg2, jobject jarg2_, jintArray jarg3) {
  jint jresult = 0 ;
  pjsip_transport_type_e arg1 ;
  pjsua_transport_config *arg2 = (pjsua_transport_config *) 0 ;
  pjsua_transport_id *arg3 = (pjsua_transport_id *) 0 ;
  pjsua_transport_id temp3 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg2_;
  arg1 = (pjsip_transport_type_e)jarg1; 
  arg2 = *(pjsua_transport_config **)&jarg2; 
  {
    if (!jarg3) {
      SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "array null");
      return 0;
    }
    if (jenv->GetArrayLength(jarg3) == 0) {
      SWIG_JavaThrowException(jenv, SWIG_JavaIndexOutOfBoundsException, "Array must contain at least 1 element");
      return 0;
    }
    arg3 = &temp3; 
  }
  result = (pj_status_t)pjsua_transport_create(arg1,(pjsua_transport_config const *)arg2,arg3);
  jresult = (jint)result; 
  {
    jint jvalue = (jint)temp3;
    jenv->SetIntArrayRegion(jarg3, 0, 1, &jvalue);
  }
  
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_transport_1register(JNIEnv *jenv, jclass jcls, jlong jarg1, jintArray jarg2) {
  jint jresult = 0 ;
  pjsip_transport *arg1 = (pjsip_transport *) 0 ;
  pjsua_transport_id *arg2 = (pjsua_transport_id *) 0 ;
  pjsua_transport_id temp2 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(pjsip_transport **)&jarg1; 
  {
    if (!jarg2) {
      SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "array null");
      return 0;
    }
    if (jenv->GetArrayLength(jarg2) == 0) {
      SWIG_JavaThrowException(jenv, SWIG_JavaIndexOutOfBoundsException, "Array must contain at least 1 element");
      return 0;
    }
    arg2 = &temp2; 
  }
  result = (pj_status_t)pjsua_transport_register(arg1,arg2);
  jresult = (jint)result; 
  {
    jint jvalue = (jint)temp2;
    jenv->SetIntArrayRegion(jarg2, 0, 1, &jvalue);
  }
  
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_enum_1transports(JNIEnv *jenv, jclass jcls, jintArray jarg1, jlongArray jarg2) {
  jint jresult = 0 ;
  pjsua_transport_id *arg1 ;
  unsigned int *arg2 = (unsigned int *) 0 ;
  jint *jarr1 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  if (!SWIG_JavaArrayInInt(jenv, &jarr1, &arg1, jarg1)) return 0; 
  {
    if (!jarg2) {
      SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "array null");
      return 0;
    }
    if (jenv->GetArrayLength(jarg2) == 0) {
      SWIG_JavaThrowException(jenv, SWIG_JavaIndexOutOfBoundsException, "Array must contain at least 1 element");
      return 0;
    }
    arg2 = (unsigned int *) jenv->GetLongArrayElements(jarg2, 0); 
  }
  result = (pj_status_t)pjsua_enum_transports(arg1,arg2);
  jresult = (jint)result; 
  SWIG_JavaArrayArgoutInt(jenv, jarr1, arg1, jarg1); 
  {
    jenv->ReleaseLongArrayElements(jarg2, (jlong *)arg2, 0); 
  }
  delete [] arg1; 
  
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_transport_1get_1info(JNIEnv *jenv, jclass jcls, jint jarg1, jlong jarg2, jobject jarg2_) {
  jint jresult = 0 ;
  pjsua_transport_id arg1 ;
  pjsua_transport_info *arg2 = (pjsua_transport_info *) 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg2_;
  arg1 = (pjsua_transport_id)jarg1; 
  arg2 = *(pjsua_transport_info **)&jarg2; 
  result = (pj_status_t)pjsua_transport_get_info(arg1,arg2);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_transport_1set_1enable(JNIEnv *jenv, jclass jcls, jint jarg1, jint jarg2) {
  jint jresult = 0 ;
  pjsua_transport_id arg1 ;
  pj_bool_t arg2 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (pjsua_transport_id)jarg1; 
  arg2 = (pj_bool_t)jarg2; 
  result = (pj_status_t)pjsua_transport_set_enable(arg1,arg2);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_transport_1close(JNIEnv *jenv, jclass jcls, jint jarg1, jint jarg2) {
  jint jresult = 0 ;
  pjsua_transport_id arg1 ;
  pj_bool_t arg2 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (pjsua_transport_id)jarg1; 
  arg2 = (pj_bool_t)jarg2; 
  result = (pj_status_t)pjsua_transport_close(arg1,arg2);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSUA_1MAX_1ACC_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  result = (int)(8);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSUA_1REG_1INTERVAL_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  result = (int)(300);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSUA_1UNREG_1TIMEOUT_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  result = (int)(4000);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSUA_1DEFAULT_1ACC_1PRIORITY_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  result = (int)(0);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jstring JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSUA_1SECURE_1SCHEME_1get(JNIEnv *jenv, jclass jcls) {
  jstring jresult = 0 ;
  char *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  result = (char *)("sip");
  if (result) jresult = jenv->NewStringUTF((const char *)result);
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSUA_1UNPUBLISH_1MAX_1WAIT_1TIME_1MSEC_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  result = (int)(2000);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSUA_1REG_1RETRY_1INTERVAL_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  result = (int)(300);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSUA_1CONTACT_1REWRITE_1METHOD_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  result = (int)(2);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSUA_1REG_1USE_1OUTBOUND_1PROXY_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  result = (int)(1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSUA_1REG_1USE_1ACC_1PROXY_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  result = (int)(2);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1user_1data_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, void * jarg2) {
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  void *arg2 = (void *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  
  arg2 = jarg2;
  
  if (arg1) (arg1)->user_data = arg2;
}


SWIGEXPORT void * JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1user_1data_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  void * jresult = 0 ;
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  void *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  result = (void *) ((arg1)->user_data);
  
  jresult = result; 
  
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1priority_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  arg2 = (int)jarg2; 
  if (arg1) (arg1)->priority = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1priority_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  result = (int) ((arg1)->priority);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1id_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_) {
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  if (arg1) (arg1)->id = *arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1id_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  pj_str_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  result = (pj_str_t *)& ((arg1)->id);
  *(pj_str_t **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1reg_1uri_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_) {
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  if (arg1) (arg1)->reg_uri = *arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1reg_1uri_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  pj_str_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  result = (pj_str_t *)& ((arg1)->reg_uri);
  *(pj_str_t **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1reg_1hdr_1list_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  pjsip_hdr arg2 ;
  pjsip_hdr *argp2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  argp2 = *(pjsip_hdr **)&jarg2; 
  if (!argp2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null pjsip_hdr");
    return ;
  }
  arg2 = *argp2; 
  if (arg1) (arg1)->reg_hdr_list = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1reg_1hdr_1list_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  pjsip_hdr result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  result =  ((arg1)->reg_hdr_list);
  *(pjsip_hdr **)&jresult = new pjsip_hdr((const pjsip_hdr &)result); 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1mwi_1enabled_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  pj_bool_t arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  arg2 = (pj_bool_t)jarg2; 
  if (arg1) (arg1)->mwi_enabled = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1mwi_1enabled_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  pj_bool_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  result = (pj_bool_t) ((arg1)->mwi_enabled);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1publish_1enabled_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  pj_bool_t arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  arg2 = (pj_bool_t)jarg2; 
  if (arg1) (arg1)->publish_enabled = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1publish_1enabled_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  pj_bool_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  result = (pj_bool_t) ((arg1)->publish_enabled);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1publish_1opt_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  pjsip_publishc_opt arg2 ;
  pjsip_publishc_opt *argp2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  argp2 = *(pjsip_publishc_opt **)&jarg2; 
  if (!argp2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null pjsip_publishc_opt");
    return ;
  }
  arg2 = *argp2; 
  if (arg1) (arg1)->publish_opt = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1publish_1opt_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  pjsip_publishc_opt result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  result =  ((arg1)->publish_opt);
  *(pjsip_publishc_opt **)&jresult = new pjsip_publishc_opt((const pjsip_publishc_opt &)result); 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1unpublish_1max_1wait_1time_1msec_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  unsigned int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  if (arg1) (arg1)->unpublish_max_wait_time_msec = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1unpublish_1max_1wait_1time_1msec_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  result = (unsigned int) ((arg1)->unpublish_max_wait_time_msec);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1auth_1pref_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  pjsip_auth_clt_pref arg2 ;
  pjsip_auth_clt_pref *argp2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  argp2 = *(pjsip_auth_clt_pref **)&jarg2; 
  if (!argp2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null pjsip_auth_clt_pref");
    return ;
  }
  arg2 = *argp2; 
  if (arg1) (arg1)->auth_pref = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1auth_1pref_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  pjsip_auth_clt_pref result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  result =  ((arg1)->auth_pref);
  *(pjsip_auth_clt_pref **)&jresult = new pjsip_auth_clt_pref((const pjsip_auth_clt_pref &)result); 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1pidf_1tuple_1id_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_) {
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  if (arg1) (arg1)->pidf_tuple_id = *arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1pidf_1tuple_1id_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  pj_str_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  result = (pj_str_t *)& ((arg1)->pidf_tuple_id);
  *(pj_str_t **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1force_1contact_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_) {
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  if (arg1) (arg1)->force_contact = *arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1force_1contact_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  pj_str_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  result = (pj_str_t *)& ((arg1)->force_contact);
  *(pj_str_t **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1contact_1params_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_) {
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  if (arg1) (arg1)->contact_params = *arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1contact_1params_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  pj_str_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  result = (pj_str_t *)& ((arg1)->contact_params);
  *(pj_str_t **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1contact_1uri_1params_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_) {
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  if (arg1) (arg1)->contact_uri_params = *arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1contact_1uri_1params_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  pj_str_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  result = (pj_str_t *)& ((arg1)->contact_uri_params);
  *(pj_str_t **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1require_1100rel_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  pj_bool_t arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  arg2 = (pj_bool_t)jarg2; 
  if (arg1) (arg1)->require_100rel = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1require_1100rel_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  pj_bool_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  result = (pj_bool_t) ((arg1)->require_100rel);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1use_1timer_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  pjsua_sip_timer_use arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  arg2 = (pjsua_sip_timer_use)jarg2; 
  if (arg1) (arg1)->use_timer = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1use_1timer_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  pjsua_sip_timer_use result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  result = (pjsua_sip_timer_use) ((arg1)->use_timer);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1timer_1setting_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  pjsip_timer_setting arg2 ;
  pjsip_timer_setting *argp2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  argp2 = *(pjsip_timer_setting **)&jarg2; 
  if (!argp2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null pjsip_timer_setting");
    return ;
  }
  arg2 = *argp2; 
  if (arg1) (arg1)->timer_setting = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1timer_1setting_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  pjsip_timer_setting result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  result =  ((arg1)->timer_setting);
  *(pjsip_timer_setting **)&jresult = new pjsip_timer_setting((const pjsip_timer_setting &)result); 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1proxy_1cnt_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  unsigned int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  if (arg1) (arg1)->proxy_cnt = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1proxy_1cnt_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  result = (unsigned int) ((arg1)->proxy_cnt);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1proxy_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlongArray jarg2) {
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  pj_str_t *arg2 ;
  jlong *jarr2 ;
  jsize sz2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  {
    int i;
    if (!jarg2) {
      SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null array");
      return ;
    }
    sz2 = jenv->GetArrayLength(jarg2);
    if (sz2 != 8) {
      SWIG_JavaThrowException(jenv, SWIG_JavaIndexOutOfBoundsException, "incorrect array size");
      return ;
    }
    jarr2 = jenv->GetLongArrayElements(jarg2, 0);
    if (!jarr2) {
      return ;
    }
    
    arg2 = new pj_str_t[sz2];
    
    
    
    if (!arg2) {
      SWIG_JavaThrowException(jenv, SWIG_JavaOutOfMemoryError, "array memory allocation failed");
      return ;
    }
    for (i=0; i<sz2; i++) {
      arg2[i] = **(pj_str_t **)&jarr2[i];
    }
  }
  {
    size_t ii;
    pj_str_t *b = (pj_str_t *) arg1->proxy;
    for (ii = 0; ii < (size_t)8; ii++) b[ii] = *((pj_str_t *) arg2 + ii);
  }
  {
    int i;
    for (i=0; i<sz2; i++) {
      **(pj_str_t **)&jarr2[i] = arg2[i];
    }
    jenv->ReleaseLongArrayElements(jarg2, jarr2, 0);
  }
  delete [] arg2; 
}


SWIGEXPORT jlongArray JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1proxy_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlongArray jresult = 0 ;
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  pj_str_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  result = (pj_str_t *)(pj_str_t *) ((arg1)->proxy);
  {
    jlong *arr;
    int i;
    jresult = jenv->NewLongArray(8);
    if (!jresult) {
      return 0;
    }
    arr = jenv->GetLongArrayElements(jresult, 0);
    if (!arr) {
      return 0;
    }
    for (i=0; i<8; i++) {
      arr[i] = 0;
      *(pj_str_t **)&arr[i] = &result[i];
    }
    jenv->ReleaseLongArrayElements(jresult, arr, 0);
  }
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1reg_1timeout_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  unsigned int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  if (arg1) (arg1)->reg_timeout = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1reg_1timeout_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  result = (unsigned int) ((arg1)->reg_timeout);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1unreg_1timeout_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  unsigned int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  if (arg1) (arg1)->unreg_timeout = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1unreg_1timeout_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  result = (unsigned int) ((arg1)->unreg_timeout);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1cred_1count_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  unsigned int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  if (arg1) (arg1)->cred_count = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1cred_1count_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  result = (unsigned int) ((arg1)->cred_count);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1cred_1info_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_) {
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  pjsip_cred_info *arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  arg2 = *(pjsip_cred_info **)&jarg2; 
  {
    size_t ii;
    pjsip_cred_info *b = (pjsip_cred_info *) arg1->cred_info;
    for (ii = 0; ii < (size_t)8; ii++) b[ii] = *((pjsip_cred_info *) arg2 + ii);
  }
  
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1cred_1info_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  pjsip_cred_info *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  result = (pjsip_cred_info *)(pjsip_cred_info *) ((arg1)->cred_info);
  *(pjsip_cred_info **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1transport_1id_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  pjsua_transport_id arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  arg2 = (pjsua_transport_id)jarg2; 
  if (arg1) (arg1)->transport_id = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1transport_1id_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  pjsua_transport_id result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  result = (pjsua_transport_id) ((arg1)->transport_id);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1allow_1contact_1rewrite_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  pj_bool_t arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  arg2 = (pj_bool_t)jarg2; 
  if (arg1) (arg1)->allow_contact_rewrite = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1allow_1contact_1rewrite_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  pj_bool_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  result = (pj_bool_t) ((arg1)->allow_contact_rewrite);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1contact_1rewrite_1method_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  arg2 = (int)jarg2; 
  if (arg1) (arg1)->contact_rewrite_method = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1contact_1rewrite_1method_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  result = (int) ((arg1)->contact_rewrite_method);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1ka_1interval_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  unsigned int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  if (arg1) (arg1)->ka_interval = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1ka_1interval_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  result = (unsigned int) ((arg1)->ka_interval);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1ka_1data_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_) {
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  if (arg1) (arg1)->ka_data = *arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1ka_1data_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  pj_str_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  result = (pj_str_t *)& ((arg1)->ka_data);
  *(pj_str_t **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1use_1srtp_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  pjmedia_srtp_use arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  arg2 = (pjmedia_srtp_use)jarg2; 
  if (arg1) (arg1)->use_srtp = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1use_1srtp_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  pjmedia_srtp_use result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  result = (pjmedia_srtp_use) ((arg1)->use_srtp);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1srtp_1secure_1signaling_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  arg2 = (int)jarg2; 
  if (arg1) (arg1)->srtp_secure_signaling = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1srtp_1secure_1signaling_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  result = (int) ((arg1)->srtp_secure_signaling);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1srtp_1optional_1dup_1offer_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  pj_bool_t arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  arg2 = (pj_bool_t)jarg2; 
  if (arg1) (arg1)->srtp_optional_dup_offer = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1srtp_1optional_1dup_1offer_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  pj_bool_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  result = (pj_bool_t) ((arg1)->srtp_optional_dup_offer);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1reg_1retry_1interval_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  unsigned int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  if (arg1) (arg1)->reg_retry_interval = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1reg_1retry_1interval_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  result = (unsigned int) ((arg1)->reg_retry_interval);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1drop_1calls_1on_1reg_1fail_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  pj_bool_t arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  arg2 = (pj_bool_t)jarg2; 
  if (arg1) (arg1)->drop_calls_on_reg_fail = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1drop_1calls_1on_1reg_1fail_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  pj_bool_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  result = (pj_bool_t) ((arg1)->drop_calls_on_reg_fail);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1reg_1use_1proxy_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  unsigned int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  if (arg1) (arg1)->reg_use_proxy = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1reg_1use_1proxy_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  result = (unsigned int) ((arg1)->reg_use_proxy);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1call_1hold_1type_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  pjsua_call_hold_type arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  arg2 = (pjsua_call_hold_type)jarg2; 
  if (arg1) (arg1)->call_hold_type = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1call_1hold_1type_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  pjsua_call_hold_type result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  result = (pjsua_call_hold_type) ((arg1)->call_hold_type);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_new_1pjsua_1acc_1config(JNIEnv *jenv, jclass jcls) {
  jlong jresult = 0 ;
  pjsua_acc_config *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  result = (pjsua_acc_config *)new pjsua_acc_config();
  *(pjsua_acc_config **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_delete_1pjsua_1acc_1config(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  delete arg1;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_acc_1config_1default(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  pjsua_acc_config_default(arg1);
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_acc_1config_1dup(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_, jlong jarg3, jobject jarg3_) {
  pj_pool_t *arg1 = (pj_pool_t *) 0 ;
  pjsua_acc_config *arg2 = (pjsua_acc_config *) 0 ;
  pjsua_acc_config *arg3 = (pjsua_acc_config *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  (void)jarg3_;
  arg1 = *(pj_pool_t **)&jarg1; 
  arg2 = *(pjsua_acc_config **)&jarg2; 
  arg3 = *(pjsua_acc_config **)&jarg3; 
  pjsua_acc_config_dup(arg1,arg2,(pjsua_acc_config const *)arg3);
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1info_1id_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_acc_info *arg1 = (pjsua_acc_info *) 0 ;
  pjsua_acc_id arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_info **)&jarg1; 
  arg2 = (pjsua_acc_id)jarg2; 
  if (arg1) (arg1)->id = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1info_1id_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_acc_info *arg1 = (pjsua_acc_info *) 0 ;
  pjsua_acc_id result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_info **)&jarg1; 
  result = (pjsua_acc_id) ((arg1)->id);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1info_1is_1default_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_acc_info *arg1 = (pjsua_acc_info *) 0 ;
  pj_bool_t arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_info **)&jarg1; 
  arg2 = (pj_bool_t)jarg2; 
  if (arg1) (arg1)->is_default = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1info_1is_1default_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_acc_info *arg1 = (pjsua_acc_info *) 0 ;
  pj_bool_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_info **)&jarg1; 
  result = (pj_bool_t) ((arg1)->is_default);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1info_1acc_1uri_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_) {
  pjsua_acc_info *arg1 = (pjsua_acc_info *) 0 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(pjsua_acc_info **)&jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  if (arg1) (arg1)->acc_uri = *arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1info_1acc_1uri_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_acc_info *arg1 = (pjsua_acc_info *) 0 ;
  pj_str_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_info **)&jarg1; 
  result = (pj_str_t *)& ((arg1)->acc_uri);
  *(pj_str_t **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1info_1has_1registration_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_acc_info *arg1 = (pjsua_acc_info *) 0 ;
  pj_bool_t arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_info **)&jarg1; 
  arg2 = (pj_bool_t)jarg2; 
  if (arg1) (arg1)->has_registration = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1info_1has_1registration_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_acc_info *arg1 = (pjsua_acc_info *) 0 ;
  pj_bool_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_info **)&jarg1; 
  result = (pj_bool_t) ((arg1)->has_registration);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1info_1expires_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_acc_info *arg1 = (pjsua_acc_info *) 0 ;
  int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_info **)&jarg1; 
  arg2 = (int)jarg2; 
  if (arg1) (arg1)->expires = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1info_1expires_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_acc_info *arg1 = (pjsua_acc_info *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_info **)&jarg1; 
  result = (int) ((arg1)->expires);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1info_1status_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_acc_info *arg1 = (pjsua_acc_info *) 0 ;
  pjsip_status_code arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_info **)&jarg1; 
  arg2 = (pjsip_status_code)jarg2; 
  if (arg1) (arg1)->status = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1info_1status_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_acc_info *arg1 = (pjsua_acc_info *) 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_info **)&jarg1; 
  result = (pjsip_status_code) ((arg1)->status);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1info_1reg_1last_1err_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_acc_info *arg1 = (pjsua_acc_info *) 0 ;
  pj_status_t arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_info **)&jarg1; 
  arg2 = (pj_status_t)jarg2; 
  if (arg1) (arg1)->reg_last_err = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1info_1reg_1last_1err_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_acc_info *arg1 = (pjsua_acc_info *) 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_info **)&jarg1; 
  result = (pj_status_t) ((arg1)->reg_last_err);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1info_1status_1text_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_) {
  pjsua_acc_info *arg1 = (pjsua_acc_info *) 0 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(pjsua_acc_info **)&jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  if (arg1) (arg1)->status_text = *arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1info_1status_1text_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_acc_info *arg1 = (pjsua_acc_info *) 0 ;
  pj_str_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_info **)&jarg1; 
  result = (pj_str_t *)& ((arg1)->status_text);
  *(pj_str_t **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1info_1online_1status_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_acc_info *arg1 = (pjsua_acc_info *) 0 ;
  pj_bool_t arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_info **)&jarg1; 
  arg2 = (pj_bool_t)jarg2; 
  if (arg1) (arg1)->online_status = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1info_1online_1status_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_acc_info *arg1 = (pjsua_acc_info *) 0 ;
  pj_bool_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_info **)&jarg1; 
  result = (pj_bool_t) ((arg1)->online_status);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1info_1online_1status_1text_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_) {
  pjsua_acc_info *arg1 = (pjsua_acc_info *) 0 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(pjsua_acc_info **)&jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  if (arg1) (arg1)->online_status_text = *arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1info_1online_1status_1text_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_acc_info *arg1 = (pjsua_acc_info *) 0 ;
  pj_str_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_info **)&jarg1; 
  result = (pj_str_t *)& ((arg1)->online_status_text);
  *(pj_str_t **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1info_1rpid_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_acc_info *arg1 = (pjsua_acc_info *) 0 ;
  pjrpid_element arg2 ;
  pjrpid_element *argp2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_info **)&jarg1; 
  argp2 = *(pjrpid_element **)&jarg2; 
  if (!argp2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null pjrpid_element");
    return ;
  }
  arg2 = *argp2; 
  if (arg1) (arg1)->rpid = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1info_1rpid_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_acc_info *arg1 = (pjsua_acc_info *) 0 ;
  pjrpid_element result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_info **)&jarg1; 
  result =  ((arg1)->rpid);
  *(pjrpid_element **)&jresult = new pjrpid_element((const pjrpid_element &)result); 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1info_1buf_1_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jstring jarg2) {
  pjsua_acc_info *arg1 = (pjsua_acc_info *) 0 ;
  char *arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_info **)&jarg1; 
  arg2 = 0;
  if (jarg2) {
    arg2 = (char *)jenv->GetStringUTFChars(jarg2, 0);
    if (!arg2) return ;
  }
  {
    if(arg2) {
      strncpy((char*)arg1->buf_, (const char *)arg2, PJ_ERR_MSG_SIZE-1);
      arg1->buf_[PJ_ERR_MSG_SIZE-1] = 0;
    } else {
      arg1->buf_[0] = 0;
    }
  }
  
  if (arg2) jenv->ReleaseStringUTFChars(jarg2, (const char *)arg2);
}


SWIGEXPORT jstring JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1info_1buf_1_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jstring jresult = 0 ;
  pjsua_acc_info *arg1 = (pjsua_acc_info *) 0 ;
  char *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_info **)&jarg1; 
  result = (char *)(char *) ((arg1)->buf_);
  if (result) jresult = jenv->NewStringUTF((const char *)result);
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_new_1pjsua_1acc_1info(JNIEnv *jenv, jclass jcls) {
  jlong jresult = 0 ;
  pjsua_acc_info *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  result = (pjsua_acc_info *)new pjsua_acc_info();
  *(pjsua_acc_info **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_delete_1pjsua_1acc_1info(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  pjsua_acc_info *arg1 = (pjsua_acc_info *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(pjsua_acc_info **)&jarg1; 
  delete arg1;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_acc_1get_1count(JNIEnv *jenv, jclass jcls) {
  jlong jresult = 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  result = (unsigned int)pjsua_acc_get_count();
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_acc_1is_1valid(JNIEnv *jenv, jclass jcls, jint jarg1) {
  jint jresult = 0 ;
  pjsua_acc_id arg1 ;
  pj_bool_t result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (pjsua_acc_id)jarg1; 
  result = (pj_bool_t)pjsua_acc_is_valid(arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_acc_1set_1default(JNIEnv *jenv, jclass jcls, jint jarg1) {
  jint jresult = 0 ;
  pjsua_acc_id arg1 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (pjsua_acc_id)jarg1; 
  result = (pj_status_t)pjsua_acc_set_default(arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_acc_1get_1default(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pjsua_acc_id result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsua_acc_id)pjsua_acc_get_default();
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_acc_1add(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2, jintArray jarg3) {
  jint jresult = 0 ;
  pjsua_acc_config *arg1 = (pjsua_acc_config *) 0 ;
  pj_bool_t arg2 ;
  pjsua_acc_id *arg3 = (pjsua_acc_id *) 0 ;
  pjsua_acc_id temp3 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_config **)&jarg1; 
  arg2 = (pj_bool_t)jarg2; 
  {
    if (!jarg3) {
      SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "array null");
      return 0;
    }
    if (jenv->GetArrayLength(jarg3) == 0) {
      SWIG_JavaThrowException(jenv, SWIG_JavaIndexOutOfBoundsException, "Array must contain at least 1 element");
      return 0;
    }
    arg3 = &temp3; 
  }
  result = (pj_status_t)pjsua_acc_add((pjsua_acc_config const *)arg1,arg2,arg3);
  jresult = (jint)result; 
  {
    jint jvalue = (jint)temp3;
    jenv->SetIntArrayRegion(jarg3, 0, 1, &jvalue);
  }
  
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_acc_1add_1local(JNIEnv *jenv, jclass jcls, jint jarg1, jint jarg2, jintArray jarg3) {
  jint jresult = 0 ;
  pjsua_transport_id arg1 ;
  pj_bool_t arg2 ;
  pjsua_acc_id *arg3 = (pjsua_acc_id *) 0 ;
  pjsua_acc_id temp3 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (pjsua_transport_id)jarg1; 
  arg2 = (pj_bool_t)jarg2; 
  {
    if (!jarg3) {
      SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "array null");
      return 0;
    }
    if (jenv->GetArrayLength(jarg3) == 0) {
      SWIG_JavaThrowException(jenv, SWIG_JavaIndexOutOfBoundsException, "Array must contain at least 1 element");
      return 0;
    }
    arg3 = &temp3; 
  }
  result = (pj_status_t)pjsua_acc_add_local(arg1,arg2,arg3);
  jresult = (jint)result; 
  {
    jint jvalue = (jint)temp3;
    jenv->SetIntArrayRegion(jarg3, 0, 1, &jvalue);
  }
  
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_acc_1set_1user_1data(JNIEnv *jenv, jclass jcls, jint jarg1, void * jarg2) {
  jint jresult = 0 ;
  pjsua_acc_id arg1 ;
  void *arg2 = (void *) 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (pjsua_acc_id)jarg1; 
  
  arg2 = jarg2;
  
  result = (pj_status_t)pjsua_acc_set_user_data(arg1,arg2);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void * JNICALL Java_org_pjsip_pjsua_pjsuaJNI_acc_1get_1user_1data(JNIEnv *jenv, jclass jcls, jint jarg1) {
  void * jresult = 0 ;
  pjsua_acc_id arg1 ;
  void *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = (pjsua_acc_id)jarg1; 
  result = (void *)pjsua_acc_get_user_data(arg1);
  
  jresult = result; 
  
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_acc_1del(JNIEnv *jenv, jclass jcls, jint jarg1) {
  jint jresult = 0 ;
  pjsua_acc_id arg1 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (pjsua_acc_id)jarg1; 
  result = (pj_status_t)pjsua_acc_del(arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_acc_1modify(JNIEnv *jenv, jclass jcls, jint jarg1, jlong jarg2, jobject jarg2_) {
  jint jresult = 0 ;
  pjsua_acc_id arg1 ;
  pjsua_acc_config *arg2 = (pjsua_acc_config *) 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg2_;
  arg1 = (pjsua_acc_id)jarg1; 
  arg2 = *(pjsua_acc_config **)&jarg2; 
  result = (pj_status_t)pjsua_acc_modify(arg1,(pjsua_acc_config const *)arg2);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_acc_1set_1online_1status(JNIEnv *jenv, jclass jcls, jint jarg1, jint jarg2) {
  jint jresult = 0 ;
  pjsua_acc_id arg1 ;
  pj_bool_t arg2 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (pjsua_acc_id)jarg1; 
  arg2 = (pj_bool_t)jarg2; 
  result = (pj_status_t)pjsua_acc_set_online_status(arg1,arg2);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_acc_1set_1online_1status2(JNIEnv *jenv, jclass jcls, jint jarg1, jint jarg2, jlong jarg3) {
  jint jresult = 0 ;
  pjsua_acc_id arg1 ;
  pj_bool_t arg2 ;
  pjrpid_element *arg3 = (pjrpid_element *) 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (pjsua_acc_id)jarg1; 
  arg2 = (pj_bool_t)jarg2; 
  arg3 = *(pjrpid_element **)&jarg3; 
  result = (pj_status_t)pjsua_acc_set_online_status2(arg1,arg2,(pjrpid_element const *)arg3);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_acc_1set_1registration(JNIEnv *jenv, jclass jcls, jint jarg1, jint jarg2) {
  jint jresult = 0 ;
  pjsua_acc_id arg1 ;
  pj_bool_t arg2 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (pjsua_acc_id)jarg1; 
  arg2 = (pj_bool_t)jarg2; 
  result = (pj_status_t)pjsua_acc_set_registration(arg1,arg2);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_acc_1get_1info(JNIEnv *jenv, jclass jcls, jint jarg1, jlong jarg2, jobject jarg2_) {
  jint jresult = 0 ;
  pjsua_acc_id arg1 ;
  pjsua_acc_info *arg2 = (pjsua_acc_info *) 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg2_;
  arg1 = (pjsua_acc_id)jarg1; 
  arg2 = *(pjsua_acc_info **)&jarg2; 
  result = (pj_status_t)pjsua_acc_get_info(arg1,arg2);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_enum_1accs(JNIEnv *jenv, jclass jcls, jintArray jarg1, jlongArray jarg2) {
  jint jresult = 0 ;
  pjsua_acc_id *arg1 ;
  unsigned int *arg2 = (unsigned int *) 0 ;
  jint *jarr1 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  if (!SWIG_JavaArrayInInt(jenv, &jarr1, &arg1, jarg1)) return 0; 
  {
    if (!jarg2) {
      SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "array null");
      return 0;
    }
    if (jenv->GetArrayLength(jarg2) == 0) {
      SWIG_JavaThrowException(jenv, SWIG_JavaIndexOutOfBoundsException, "Array must contain at least 1 element");
      return 0;
    }
    arg2 = (unsigned int *) jenv->GetLongArrayElements(jarg2, 0); 
  }
  result = (pj_status_t)pjsua_enum_accs(arg1,arg2);
  jresult = (jint)result; 
  SWIG_JavaArrayArgoutInt(jenv, jarr1, arg1, jarg1); 
  {
    jenv->ReleaseLongArrayElements(jarg2, (jlong *)arg2, 0); 
  }
  delete [] arg1; 
  
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_acc_1enum_1info(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlongArray jarg2) {
  jint jresult = 0 ;
  pjsua_acc_info *arg1 ;
  unsigned int *arg2 = (unsigned int *) 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_acc_info **)&jarg1; 
  {
    if (!jarg2) {
      SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "array null");
      return 0;
    }
    if (jenv->GetArrayLength(jarg2) == 0) {
      SWIG_JavaThrowException(jenv, SWIG_JavaIndexOutOfBoundsException, "Array must contain at least 1 element");
      return 0;
    }
    arg2 = (unsigned int *) jenv->GetLongArrayElements(jarg2, 0); 
  }
  result = (pj_status_t)pjsua_acc_enum_info(arg1,arg2);
  jresult = (jint)result; 
  {
    jenv->ReleaseLongArrayElements(jarg2, (jlong *)arg2, 0); 
  }
  
  
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_acc_1find_1for_1outgoing(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pj_str_t *arg1 = (pj_str_t *) 0 ;
  pjsua_acc_id result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pj_str_t **)&jarg1; 
  result = (pjsua_acc_id)pjsua_acc_find_for_outgoing((pj_str_t const *)arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_acc_1find_1for_1incoming(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  jint jresult = 0 ;
  pjsip_rx_data *arg1 = (pjsip_rx_data *) 0 ;
  pjsua_acc_id result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(pjsip_rx_data **)&jarg1; 
  result = (pjsua_acc_id)pjsua_acc_find_for_incoming(arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_acc_1create_1request(JNIEnv *jenv, jclass jcls, jint jarg1, jlong jarg2, jlong jarg3, jobject jarg3_, jlong jarg4) {
  jint jresult = 0 ;
  pjsua_acc_id arg1 ;
  pjsip_method *arg2 = (pjsip_method *) 0 ;
  pj_str_t *arg3 = (pj_str_t *) 0 ;
  pjsip_tx_data **arg4 = (pjsip_tx_data **) 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg3_;
  arg1 = (pjsua_acc_id)jarg1; 
  arg2 = *(pjsip_method **)&jarg2; 
  arg3 = *(pj_str_t **)&jarg3; 
  arg4 = *(pjsip_tx_data ***)&jarg4; 
  result = (pj_status_t)pjsua_acc_create_request(arg1,(pjsip_method const *)arg2,(pj_str_t const *)arg3,arg4);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_acc_1create_1uac_1contact(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_, jint jarg3, jlong jarg4, jobject jarg4_) {
  jint jresult = 0 ;
  pj_pool_t *arg1 = (pj_pool_t *) 0 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  pjsua_acc_id arg3 ;
  pj_str_t *arg4 = (pj_str_t *) 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  (void)jarg4_;
  arg1 = *(pj_pool_t **)&jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  arg3 = (pjsua_acc_id)jarg3; 
  arg4 = *(pj_str_t **)&jarg4; 
  result = (pj_status_t)pjsua_acc_create_uac_contact(arg1,arg2,arg3,(pj_str_t const *)arg4);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_acc_1create_1uas_1contact(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_, jint jarg3, jlong jarg4) {
  jint jresult = 0 ;
  pj_pool_t *arg1 = (pj_pool_t *) 0 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  pjsua_acc_id arg3 ;
  pjsip_rx_data *arg4 = (pjsip_rx_data *) 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(pj_pool_t **)&jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  arg3 = (pjsua_acc_id)jarg3; 
  arg4 = *(pjsip_rx_data **)&jarg4; 
  result = (pj_status_t)pjsua_acc_create_uas_contact(arg1,arg2,arg3,arg4);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_acc_1set_1transport(JNIEnv *jenv, jclass jcls, jint jarg1, jint jarg2) {
  jint jresult = 0 ;
  pjsua_acc_id arg1 ;
  pjsua_transport_id arg2 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (pjsua_acc_id)jarg1; 
  arg2 = (pjsua_transport_id)jarg2; 
  result = (pj_status_t)pjsua_acc_set_transport(arg1,arg2);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSUA_1MAX_1CALLS_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  result = (int)(32);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1id_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_call_info *arg1 = (pjsua_call_info *) 0 ;
  pjsua_call_id arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_call_info **)&jarg1; 
  arg2 = (pjsua_call_id)jarg2; 
  if (arg1) (arg1)->id = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1id_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_call_info *arg1 = (pjsua_call_info *) 0 ;
  pjsua_call_id result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_call_info **)&jarg1; 
  result = (pjsua_call_id) ((arg1)->id);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1role_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_call_info *arg1 = (pjsua_call_info *) 0 ;
  pjsip_role_e arg2 ;
  pjsip_role_e *argp2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_call_info **)&jarg1; 
  argp2 = *(pjsip_role_e **)&jarg2; 
  if (!argp2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null pjsip_role_e");
    return ;
  }
  arg2 = *argp2; 
  if (arg1) (arg1)->role = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1role_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_call_info *arg1 = (pjsua_call_info *) 0 ;
  pjsip_role_e result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_call_info **)&jarg1; 
  result =  ((arg1)->role);
  *(pjsip_role_e **)&jresult = new pjsip_role_e((const pjsip_role_e &)result); 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1acc_1id_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_call_info *arg1 = (pjsua_call_info *) 0 ;
  pjsua_acc_id arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_call_info **)&jarg1; 
  arg2 = (pjsua_acc_id)jarg2; 
  if (arg1) (arg1)->acc_id = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1acc_1id_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_call_info *arg1 = (pjsua_call_info *) 0 ;
  pjsua_acc_id result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_call_info **)&jarg1; 
  result = (pjsua_acc_id) ((arg1)->acc_id);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1local_1info_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_) {
  pjsua_call_info *arg1 = (pjsua_call_info *) 0 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(pjsua_call_info **)&jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  if (arg1) (arg1)->local_info = *arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1local_1info_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_call_info *arg1 = (pjsua_call_info *) 0 ;
  pj_str_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_call_info **)&jarg1; 
  result = (pj_str_t *)& ((arg1)->local_info);
  *(pj_str_t **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1local_1contact_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_) {
  pjsua_call_info *arg1 = (pjsua_call_info *) 0 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(pjsua_call_info **)&jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  if (arg1) (arg1)->local_contact = *arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1local_1contact_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_call_info *arg1 = (pjsua_call_info *) 0 ;
  pj_str_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_call_info **)&jarg1; 
  result = (pj_str_t *)& ((arg1)->local_contact);
  *(pj_str_t **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1remote_1info_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_) {
  pjsua_call_info *arg1 = (pjsua_call_info *) 0 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(pjsua_call_info **)&jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  if (arg1) (arg1)->remote_info = *arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1remote_1info_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_call_info *arg1 = (pjsua_call_info *) 0 ;
  pj_str_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_call_info **)&jarg1; 
  result = (pj_str_t *)& ((arg1)->remote_info);
  *(pj_str_t **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1remote_1contact_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_) {
  pjsua_call_info *arg1 = (pjsua_call_info *) 0 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(pjsua_call_info **)&jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  if (arg1) (arg1)->remote_contact = *arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1remote_1contact_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_call_info *arg1 = (pjsua_call_info *) 0 ;
  pj_str_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_call_info **)&jarg1; 
  result = (pj_str_t *)& ((arg1)->remote_contact);
  *(pj_str_t **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1call_1id_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_) {
  pjsua_call_info *arg1 = (pjsua_call_info *) 0 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(pjsua_call_info **)&jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  if (arg1) (arg1)->call_id = *arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1call_1id_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_call_info *arg1 = (pjsua_call_info *) 0 ;
  pj_str_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_call_info **)&jarg1; 
  result = (pj_str_t *)& ((arg1)->call_id);
  *(pj_str_t **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1state_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_call_info *arg1 = (pjsua_call_info *) 0 ;
  pjsip_inv_state arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_call_info **)&jarg1; 
  arg2 = (pjsip_inv_state)jarg2; 
  if (arg1) (arg1)->state = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1state_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_call_info *arg1 = (pjsua_call_info *) 0 ;
  pjsip_inv_state result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_call_info **)&jarg1; 
  result = (pjsip_inv_state) ((arg1)->state);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1state_1text_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_) {
  pjsua_call_info *arg1 = (pjsua_call_info *) 0 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(pjsua_call_info **)&jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  if (arg1) (arg1)->state_text = *arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1state_1text_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_call_info *arg1 = (pjsua_call_info *) 0 ;
  pj_str_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_call_info **)&jarg1; 
  result = (pj_str_t *)& ((arg1)->state_text);
  *(pj_str_t **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1last_1status_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_call_info *arg1 = (pjsua_call_info *) 0 ;
  pjsip_status_code arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_call_info **)&jarg1; 
  arg2 = (pjsip_status_code)jarg2; 
  if (arg1) (arg1)->last_status = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1last_1status_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_call_info *arg1 = (pjsua_call_info *) 0 ;
  pjsip_status_code result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_call_info **)&jarg1; 
  result = (pjsip_status_code) ((arg1)->last_status);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1last_1status_1text_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_) {
  pjsua_call_info *arg1 = (pjsua_call_info *) 0 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(pjsua_call_info **)&jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  if (arg1) (arg1)->last_status_text = *arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1last_1status_1text_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_call_info *arg1 = (pjsua_call_info *) 0 ;
  pj_str_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_call_info **)&jarg1; 
  result = (pj_str_t *)& ((arg1)->last_status_text);
  *(pj_str_t **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1media_1status_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_call_info *arg1 = (pjsua_call_info *) 0 ;
  pjsua_call_media_status arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_call_info **)&jarg1; 
  arg2 = (pjsua_call_media_status)jarg2; 
  if (arg1) (arg1)->media_status = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1media_1status_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_call_info *arg1 = (pjsua_call_info *) 0 ;
  pjsua_call_media_status result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_call_info **)&jarg1; 
  result = (pjsua_call_media_status) ((arg1)->media_status);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1media_1dir_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_call_info *arg1 = (pjsua_call_info *) 0 ;
  pjmedia_dir arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_call_info **)&jarg1; 
  arg2 = (pjmedia_dir)jarg2; 
  if (arg1) (arg1)->media_dir = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1media_1dir_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_call_info *arg1 = (pjsua_call_info *) 0 ;
  pjmedia_dir result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_call_info **)&jarg1; 
  result = (pjmedia_dir) ((arg1)->media_dir);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1conf_1slot_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_call_info *arg1 = (pjsua_call_info *) 0 ;
  pjsua_conf_port_id arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_call_info **)&jarg1; 
  arg2 = (pjsua_conf_port_id)jarg2; 
  if (arg1) (arg1)->conf_slot = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1conf_1slot_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_call_info *arg1 = (pjsua_call_info *) 0 ;
  pjsua_conf_port_id result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_call_info **)&jarg1; 
  result = (pjsua_conf_port_id) ((arg1)->conf_slot);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1connect_1duration_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_call_info *arg1 = (pjsua_call_info *) 0 ;
  pj_time_val arg2 ;
  pj_time_val *argp2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_call_info **)&jarg1; 
  argp2 = *(pj_time_val **)&jarg2; 
  if (!argp2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null pj_time_val");
    return ;
  }
  arg2 = *argp2; 
  if (arg1) (arg1)->connect_duration = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1connect_1duration_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_call_info *arg1 = (pjsua_call_info *) 0 ;
  pj_time_val result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_call_info **)&jarg1; 
  result =  ((arg1)->connect_duration);
  *(pj_time_val **)&jresult = new pj_time_val((const pj_time_val &)result); 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1total_1duration_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_call_info *arg1 = (pjsua_call_info *) 0 ;
  pj_time_val arg2 ;
  pj_time_val *argp2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_call_info **)&jarg1; 
  argp2 = *(pj_time_val **)&jarg2; 
  if (!argp2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null pj_time_val");
    return ;
  }
  arg2 = *argp2; 
  if (arg1) (arg1)->total_duration = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1total_1duration_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_call_info *arg1 = (pjsua_call_info *) 0 ;
  pj_time_val result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_call_info **)&jarg1; 
  result =  ((arg1)->total_duration);
  *(pj_time_val **)&jresult = new pj_time_val((const pj_time_val &)result); 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_new_1pjsua_1call_1info(JNIEnv *jenv, jclass jcls) {
  jlong jresult = 0 ;
  pjsua_call_info *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  result = (pjsua_call_info *)new pjsua_call_info();
  *(pjsua_call_info **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_delete_1pjsua_1call_1info(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  pjsua_call_info *arg1 = (pjsua_call_info *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(pjsua_call_info **)&jarg1; 
  delete arg1;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_call_1get_1max_1count(JNIEnv *jenv, jclass jcls) {
  jlong jresult = 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  result = (unsigned int)pjsua_call_get_max_count();
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_call_1get_1count(JNIEnv *jenv, jclass jcls) {
  jlong jresult = 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  result = (unsigned int)pjsua_call_get_count();
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_enum_1calls(JNIEnv *jenv, jclass jcls, jintArray jarg1, jlongArray jarg2) {
  jint jresult = 0 ;
  pjsua_call_id *arg1 ;
  unsigned int *arg2 = (unsigned int *) 0 ;
  jint *jarr1 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  if (!SWIG_JavaArrayInInt(jenv, &jarr1, &arg1, jarg1)) return 0; 
  {
    if (!jarg2) {
      SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "array null");
      return 0;
    }
    if (jenv->GetArrayLength(jarg2) == 0) {
      SWIG_JavaThrowException(jenv, SWIG_JavaIndexOutOfBoundsException, "Array must contain at least 1 element");
      return 0;
    }
    arg2 = (unsigned int *) jenv->GetLongArrayElements(jarg2, 0); 
  }
  result = (pj_status_t)pjsua_enum_calls(arg1,arg2);
  jresult = (jint)result; 
  SWIG_JavaArrayArgoutInt(jenv, jarr1, arg1, jarg1); 
  {
    jenv->ReleaseLongArrayElements(jarg2, (jlong *)arg2, 0); 
  }
  delete [] arg1; 
  
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_call_1make_1call(JNIEnv *jenv, jclass jcls, jint jarg1, jlong jarg2, jobject jarg2_, jlong jarg3, void * jarg4, jlong jarg5, jintArray jarg6) {
  jint jresult = 0 ;
  pjsua_acc_id arg1 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  unsigned int arg3 ;
  void *arg4 = (void *) 0 ;
  pjsua_msg_data *arg5 = (pjsua_msg_data *) 0 ;
  pjsua_call_id *arg6 = (pjsua_call_id *) 0 ;
  pjsua_call_id temp6 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg2_;
  arg1 = (pjsua_acc_id)jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  arg3 = (unsigned int)jarg3; 
  
  arg4 = jarg4;
  
  arg5 = *(pjsua_msg_data **)&jarg5; 
  {
    if (!jarg6) {
      SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "array null");
      return 0;
    }
    if (jenv->GetArrayLength(jarg6) == 0) {
      SWIG_JavaThrowException(jenv, SWIG_JavaIndexOutOfBoundsException, "Array must contain at least 1 element");
      return 0;
    }
    arg6 = &temp6; 
  }
  result = (pj_status_t)pjsua_call_make_call(arg1,(pj_str_t const *)arg2,arg3,arg4,(pjsua_msg_data const *)arg5,arg6);
  jresult = (jint)result; 
  {
    jint jvalue = (jint)temp6;
    jenv->SetIntArrayRegion(jarg6, 0, 1, &jvalue);
  }
  
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_call_1is_1active(JNIEnv *jenv, jclass jcls, jint jarg1) {
  jint jresult = 0 ;
  pjsua_call_id arg1 ;
  pj_bool_t result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (pjsua_call_id)jarg1; 
  result = (pj_bool_t)pjsua_call_is_active(arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_call_1has_1media(JNIEnv *jenv, jclass jcls, jint jarg1) {
  jint jresult = 0 ;
  pjsua_call_id arg1 ;
  pj_bool_t result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (pjsua_call_id)jarg1; 
  result = (pj_bool_t)pjsua_call_has_media(arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_call_1get_1media_1session(JNIEnv *jenv, jclass jcls, jint jarg1) {
  jlong jresult = 0 ;
  pjsua_call_id arg1 ;
  pjmedia_session *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = (pjsua_call_id)jarg1; 
  result = (pjmedia_session *)pjsua_call_get_media_session(arg1);
  *(pjmedia_session **)&jresult = result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_call_1get_1media_1transport(JNIEnv *jenv, jclass jcls, jint jarg1) {
  jlong jresult = 0 ;
  pjsua_call_id arg1 ;
  pjmedia_transport *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = (pjsua_call_id)jarg1; 
  result = (pjmedia_transport *)pjsua_call_get_media_transport(arg1);
  *(pjmedia_transport **)&jresult = result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_call_1get_1conf_1port(JNIEnv *jenv, jclass jcls, jint jarg1) {
  jint jresult = 0 ;
  pjsua_call_id arg1 ;
  pjsua_conf_port_id result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (pjsua_call_id)jarg1; 
  result = (pjsua_conf_port_id)pjsua_call_get_conf_port(arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_call_1get_1info(JNIEnv *jenv, jclass jcls, jint jarg1, jlong jarg2, jobject jarg2_) {
  jint jresult = 0 ;
  pjsua_call_id arg1 ;
  pjsua_call_info *arg2 = (pjsua_call_info *) 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg2_;
  arg1 = (pjsua_call_id)jarg1; 
  arg2 = *(pjsua_call_info **)&jarg2; 
  result = (pj_status_t)pjsua_call_get_info(arg1,arg2);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_call_1remote_1has_1cap(JNIEnv *jenv, jclass jcls, jint jarg1, jint jarg2, jlong jarg3, jobject jarg3_, jlong jarg4, jobject jarg4_) {
  jlong jresult = 0 ;
  pjsua_call_id arg1 ;
  int arg2 ;
  pj_str_t *arg3 = (pj_str_t *) 0 ;
  pj_str_t *arg4 = (pj_str_t *) 0 ;
  pjsip_dialog_cap_status result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg3_;
  (void)jarg4_;
  arg1 = (pjsua_call_id)jarg1; 
  arg2 = (int)jarg2; 
  arg3 = *(pj_str_t **)&jarg3; 
  arg4 = *(pj_str_t **)&jarg4; 
  result = pjsua_call_remote_has_cap(arg1,arg2,(pj_str_t const *)arg3,(pj_str_t const *)arg4);
  *(pjsip_dialog_cap_status **)&jresult = new pjsip_dialog_cap_status((const pjsip_dialog_cap_status &)result); 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_call_1set_1user_1data(JNIEnv *jenv, jclass jcls, jint jarg1, void * jarg2) {
  jint jresult = 0 ;
  pjsua_call_id arg1 ;
  void *arg2 = (void *) 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (pjsua_call_id)jarg1; 
  
  arg2 = jarg2;
  
  result = (pj_status_t)pjsua_call_set_user_data(arg1,arg2);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void * JNICALL Java_org_pjsip_pjsua_pjsuaJNI_call_1get_1user_1data(JNIEnv *jenv, jclass jcls, jint jarg1) {
  void * jresult = 0 ;
  pjsua_call_id arg1 ;
  void *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = (pjsua_call_id)jarg1; 
  result = (void *)pjsua_call_get_user_data(arg1);
  
  jresult = result; 
  
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_call_1get_1rem_1nat_1type(JNIEnv *jenv, jclass jcls, jint jarg1, jlong jarg2) {
  jint jresult = 0 ;
  pjsua_call_id arg1 ;
  pj_stun_nat_type *arg2 = (pj_stun_nat_type *) 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (pjsua_call_id)jarg1; 
  arg2 = *(pj_stun_nat_type **)&jarg2; 
  result = (pj_status_t)pjsua_call_get_rem_nat_type(arg1,arg2);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_call_1answer(JNIEnv *jenv, jclass jcls, jint jarg1, jlong jarg2, jlong jarg3, jobject jarg3_, jlong jarg4) {
  jint jresult = 0 ;
  pjsua_call_id arg1 ;
  unsigned int arg2 ;
  pj_str_t *arg3 = (pj_str_t *) 0 ;
  pjsua_msg_data *arg4 = (pjsua_msg_data *) 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg3_;
  arg1 = (pjsua_call_id)jarg1; 
  arg2 = (unsigned int)jarg2; 
  arg3 = *(pj_str_t **)&jarg3; 
  arg4 = *(pjsua_msg_data **)&jarg4; 
  result = (pj_status_t)pjsua_call_answer(arg1,arg2,(pj_str_t const *)arg3,(pjsua_msg_data const *)arg4);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_call_1hangup(JNIEnv *jenv, jclass jcls, jint jarg1, jlong jarg2, jlong jarg3, jobject jarg3_, jlong jarg4) {
  jint jresult = 0 ;
  pjsua_call_id arg1 ;
  unsigned int arg2 ;
  pj_str_t *arg3 = (pj_str_t *) 0 ;
  pjsua_msg_data *arg4 = (pjsua_msg_data *) 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg3_;
  arg1 = (pjsua_call_id)jarg1; 
  arg2 = (unsigned int)jarg2; 
  arg3 = *(pj_str_t **)&jarg3; 
  arg4 = *(pjsua_msg_data **)&jarg4; 
  result = (pj_status_t)pjsua_call_hangup(arg1,arg2,(pj_str_t const *)arg3,(pjsua_msg_data const *)arg4);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_call_1process_1redirect(JNIEnv *jenv, jclass jcls, jint jarg1, jlong jarg2) {
  jint jresult = 0 ;
  pjsua_call_id arg1 ;
  pjsip_redirect_op arg2 ;
  pjsip_redirect_op *argp2 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (pjsua_call_id)jarg1; 
  argp2 = *(pjsip_redirect_op **)&jarg2; 
  if (!argp2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null pjsip_redirect_op");
    return 0;
  }
  arg2 = *argp2; 
  result = (pj_status_t)pjsua_call_process_redirect(arg1,arg2);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_call_1set_1hold(JNIEnv *jenv, jclass jcls, jint jarg1, jlong jarg2) {
  jint jresult = 0 ;
  pjsua_call_id arg1 ;
  pjsua_msg_data *arg2 = (pjsua_msg_data *) 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (pjsua_call_id)jarg1; 
  arg2 = *(pjsua_msg_data **)&jarg2; 
  result = (pj_status_t)pjsua_call_set_hold(arg1,(pjsua_msg_data const *)arg2);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_call_1reinvite(JNIEnv *jenv, jclass jcls, jint jarg1, jint jarg2, jlong jarg3) {
  jint jresult = 0 ;
  pjsua_call_id arg1 ;
  pj_bool_t arg2 ;
  pjsua_msg_data *arg3 = (pjsua_msg_data *) 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (pjsua_call_id)jarg1; 
  arg2 = (pj_bool_t)jarg2; 
  arg3 = *(pjsua_msg_data **)&jarg3; 
  result = (pj_status_t)pjsua_call_reinvite(arg1,arg2,(pjsua_msg_data const *)arg3);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_call_1update(JNIEnv *jenv, jclass jcls, jint jarg1, jlong jarg2, jlong jarg3) {
  jint jresult = 0 ;
  pjsua_call_id arg1 ;
  unsigned int arg2 ;
  pjsua_msg_data *arg3 = (pjsua_msg_data *) 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (pjsua_call_id)jarg1; 
  arg2 = (unsigned int)jarg2; 
  arg3 = *(pjsua_msg_data **)&jarg3; 
  result = (pj_status_t)pjsua_call_update(arg1,arg2,(pjsua_msg_data const *)arg3);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_call_1xfer(JNIEnv *jenv, jclass jcls, jint jarg1, jlong jarg2, jobject jarg2_, jlong jarg3) {
  jint jresult = 0 ;
  pjsua_call_id arg1 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  pjsua_msg_data *arg3 = (pjsua_msg_data *) 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg2_;
  arg1 = (pjsua_call_id)jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  arg3 = *(pjsua_msg_data **)&jarg3; 
  result = (pj_status_t)pjsua_call_xfer(arg1,(pj_str_t const *)arg2,(pjsua_msg_data const *)arg3);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSUA_1XFER_1NO_1REQUIRE_1REPLACES_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  result = (int)(1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_call_1xfer_1replaces(JNIEnv *jenv, jclass jcls, jint jarg1, jint jarg2, jlong jarg3, jlong jarg4) {
  jint jresult = 0 ;
  pjsua_call_id arg1 ;
  pjsua_call_id arg2 ;
  unsigned int arg3 ;
  pjsua_msg_data *arg4 = (pjsua_msg_data *) 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (pjsua_call_id)jarg1; 
  arg2 = (pjsua_call_id)jarg2; 
  arg3 = (unsigned int)jarg3; 
  arg4 = *(pjsua_msg_data **)&jarg4; 
  result = (pj_status_t)pjsua_call_xfer_replaces(arg1,arg2,arg3,(pjsua_msg_data const *)arg4);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_call_1dial_1dtmf(JNIEnv *jenv, jclass jcls, jint jarg1, jlong jarg2, jobject jarg2_) {
  jint jresult = 0 ;
  pjsua_call_id arg1 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg2_;
  arg1 = (pjsua_call_id)jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  result = (pj_status_t)pjsua_call_dial_dtmf(arg1,(pj_str_t const *)arg2);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_call_1send_1im(JNIEnv *jenv, jclass jcls, jint jarg1, jlong jarg2, jobject jarg2_, jlong jarg3, jobject jarg3_, jlong jarg4, void * jarg5) {
  jint jresult = 0 ;
  pjsua_call_id arg1 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  pj_str_t *arg3 = (pj_str_t *) 0 ;
  pjsua_msg_data *arg4 = (pjsua_msg_data *) 0 ;
  void *arg5 = (void *) 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg2_;
  (void)jarg3_;
  arg1 = (pjsua_call_id)jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  arg3 = *(pj_str_t **)&jarg3; 
  arg4 = *(pjsua_msg_data **)&jarg4; 
  
  arg5 = jarg5;
  
  result = (pj_status_t)pjsua_call_send_im(arg1,(pj_str_t const *)arg2,(pj_str_t const *)arg3,(pjsua_msg_data const *)arg4,arg5);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_call_1send_1typing_1ind(JNIEnv *jenv, jclass jcls, jint jarg1, jint jarg2, jlong jarg3) {
  jint jresult = 0 ;
  pjsua_call_id arg1 ;
  pj_bool_t arg2 ;
  pjsua_msg_data *arg3 = (pjsua_msg_data *) 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (pjsua_call_id)jarg1; 
  arg2 = (pj_bool_t)jarg2; 
  arg3 = *(pjsua_msg_data **)&jarg3; 
  result = (pj_status_t)pjsua_call_send_typing_ind(arg1,arg2,(pjsua_msg_data const *)arg3);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_call_1send_1request(JNIEnv *jenv, jclass jcls, jint jarg1, jlong jarg2, jobject jarg2_, jlong jarg3) {
  jint jresult = 0 ;
  pjsua_call_id arg1 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  pjsua_msg_data *arg3 = (pjsua_msg_data *) 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg2_;
  arg1 = (pjsua_call_id)jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  arg3 = *(pjsua_msg_data **)&jarg3; 
  result = (pj_status_t)pjsua_call_send_request(arg1,(pj_str_t const *)arg2,(pjsua_msg_data const *)arg3);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_call_1hangup_1all(JNIEnv *jenv, jclass jcls) {
  (void)jenv;
  (void)jcls;
  pjsua_call_hangup_all();
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_call_1dump_1_1SWIG_10(JNIEnv *jenv, jclass jcls, jint jarg1, jint jarg2, jstring jarg3, jlong jarg4, jstring jarg5) {
  jint jresult = 0 ;
  pjsua_call_id arg1 ;
  pj_bool_t arg2 ;
  char *arg3 = (char *) 0 ;
  unsigned int arg4 ;
  char *arg5 = (char *) 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (pjsua_call_id)jarg1; 
  arg2 = (pj_bool_t)jarg2; 
  arg3 = 0;
  if (jarg3) {
    arg3 = (char *)jenv->GetStringUTFChars(jarg3, 0);
    if (!arg3) return 0;
  }
  arg4 = (unsigned int)jarg4; 
  arg5 = 0;
  if (jarg5) {
    arg5 = (char *)jenv->GetStringUTFChars(jarg5, 0);
    if (!arg5) return 0;
  }
  result = (pj_status_t)pjsua_call_dump(arg1,arg2,arg3,arg4,(char const *)arg5);
  jresult = (jint)result; 
  if (arg3) jenv->ReleaseStringUTFChars(jarg3, (const char *)arg3);
  if (arg5) jenv->ReleaseStringUTFChars(jarg5, (const char *)arg5);
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSUA_1MAX_1BUDDIES_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  result = (int)(256);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSUA_1PRES_1TIMER_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  result = (int)(300);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1config_1uri_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_) {
  pjsua_buddy_config *arg1 = (pjsua_buddy_config *) 0 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(pjsua_buddy_config **)&jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  if (arg1) (arg1)->uri = *arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1config_1uri_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_buddy_config *arg1 = (pjsua_buddy_config *) 0 ;
  pj_str_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_buddy_config **)&jarg1; 
  result = (pj_str_t *)& ((arg1)->uri);
  *(pj_str_t **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1config_1subscribe_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_buddy_config *arg1 = (pjsua_buddy_config *) 0 ;
  pj_bool_t arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_buddy_config **)&jarg1; 
  arg2 = (pj_bool_t)jarg2; 
  if (arg1) (arg1)->subscribe = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1config_1subscribe_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_buddy_config *arg1 = (pjsua_buddy_config *) 0 ;
  pj_bool_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_buddy_config **)&jarg1; 
  result = (pj_bool_t) ((arg1)->subscribe);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1config_1user_1data_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, void * jarg2) {
  pjsua_buddy_config *arg1 = (pjsua_buddy_config *) 0 ;
  void *arg2 = (void *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_buddy_config **)&jarg1; 
  
  arg2 = jarg2;
  
  if (arg1) (arg1)->user_data = arg2;
}


SWIGEXPORT void * JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1config_1user_1data_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  void * jresult = 0 ;
  pjsua_buddy_config *arg1 = (pjsua_buddy_config *) 0 ;
  void *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_buddy_config **)&jarg1; 
  result = (void *) ((arg1)->user_data);
  
  jresult = result; 
  
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_new_1pjsua_1buddy_1config(JNIEnv *jenv, jclass jcls) {
  jlong jresult = 0 ;
  pjsua_buddy_config *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  result = (pjsua_buddy_config *)new pjsua_buddy_config();
  *(pjsua_buddy_config **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_delete_1pjsua_1buddy_1config(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  pjsua_buddy_config *arg1 = (pjsua_buddy_config *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(pjsua_buddy_config **)&jarg1; 
  delete arg1;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1info_1id_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_buddy_info *arg1 = (pjsua_buddy_info *) 0 ;
  pjsua_buddy_id arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_buddy_info **)&jarg1; 
  arg2 = (pjsua_buddy_id)jarg2; 
  if (arg1) (arg1)->id = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1info_1id_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_buddy_info *arg1 = (pjsua_buddy_info *) 0 ;
  pjsua_buddy_id result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_buddy_info **)&jarg1; 
  result = (pjsua_buddy_id) ((arg1)->id);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1info_1uri_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_) {
  pjsua_buddy_info *arg1 = (pjsua_buddy_info *) 0 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(pjsua_buddy_info **)&jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  if (arg1) (arg1)->uri = *arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1info_1uri_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_buddy_info *arg1 = (pjsua_buddy_info *) 0 ;
  pj_str_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_buddy_info **)&jarg1; 
  result = (pj_str_t *)& ((arg1)->uri);
  *(pj_str_t **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1info_1contact_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_) {
  pjsua_buddy_info *arg1 = (pjsua_buddy_info *) 0 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(pjsua_buddy_info **)&jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  if (arg1) (arg1)->contact = *arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1info_1contact_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_buddy_info *arg1 = (pjsua_buddy_info *) 0 ;
  pj_str_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_buddy_info **)&jarg1; 
  result = (pj_str_t *)& ((arg1)->contact);
  *(pj_str_t **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1info_1status_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_buddy_info *arg1 = (pjsua_buddy_info *) 0 ;
  pjsua_buddy_status arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_buddy_info **)&jarg1; 
  arg2 = (pjsua_buddy_status)jarg2; 
  if (arg1) (arg1)->status = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1info_1status_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_buddy_info *arg1 = (pjsua_buddy_info *) 0 ;
  pjsua_buddy_status result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_buddy_info **)&jarg1; 
  result = (pjsua_buddy_status) ((arg1)->status);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1info_1status_1text_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_) {
  pjsua_buddy_info *arg1 = (pjsua_buddy_info *) 0 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(pjsua_buddy_info **)&jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  if (arg1) (arg1)->status_text = *arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1info_1status_1text_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_buddy_info *arg1 = (pjsua_buddy_info *) 0 ;
  pj_str_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_buddy_info **)&jarg1; 
  result = (pj_str_t *)& ((arg1)->status_text);
  *(pj_str_t **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1info_1monitor_1pres_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_buddy_info *arg1 = (pjsua_buddy_info *) 0 ;
  pj_bool_t arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_buddy_info **)&jarg1; 
  arg2 = (pj_bool_t)jarg2; 
  if (arg1) (arg1)->monitor_pres = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1info_1monitor_1pres_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_buddy_info *arg1 = (pjsua_buddy_info *) 0 ;
  pj_bool_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_buddy_info **)&jarg1; 
  result = (pj_bool_t) ((arg1)->monitor_pres);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1info_1sub_1state_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_buddy_info *arg1 = (pjsua_buddy_info *) 0 ;
  pjsip_evsub_state arg2 ;
  pjsip_evsub_state *argp2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_buddy_info **)&jarg1; 
  argp2 = *(pjsip_evsub_state **)&jarg2; 
  if (!argp2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null pjsip_evsub_state");
    return ;
  }
  arg2 = *argp2; 
  if (arg1) (arg1)->sub_state = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1info_1sub_1state_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_buddy_info *arg1 = (pjsua_buddy_info *) 0 ;
  pjsip_evsub_state result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_buddy_info **)&jarg1; 
  result =  ((arg1)->sub_state);
  *(pjsip_evsub_state **)&jresult = new pjsip_evsub_state((const pjsip_evsub_state &)result); 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1info_1sub_1state_1name_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jstring jarg2) {
  pjsua_buddy_info *arg1 = (pjsua_buddy_info *) 0 ;
  char *arg2 = (char *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_buddy_info **)&jarg1; 
  arg2 = 0;
  if (jarg2) {
    arg2 = (char *)jenv->GetStringUTFChars(jarg2, 0);
    if (!arg2) return ;
  }
  {
    if (arg2) {
      arg1->sub_state_name = (char const *) (new char[strlen((const char *)arg2)+1]);
      strcpy((char *)arg1->sub_state_name, (const char *)arg2);
    } else {
      arg1->sub_state_name = 0;
    }
  }
  if (arg2) jenv->ReleaseStringUTFChars(jarg2, (const char *)arg2);
}


SWIGEXPORT jstring JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1info_1sub_1state_1name_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jstring jresult = 0 ;
  pjsua_buddy_info *arg1 = (pjsua_buddy_info *) 0 ;
  char *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_buddy_info **)&jarg1; 
  result = (char *) ((arg1)->sub_state_name);
  if (result) jresult = jenv->NewStringUTF((const char *)result);
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1info_1sub_1term_1code_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_buddy_info *arg1 = (pjsua_buddy_info *) 0 ;
  unsigned int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_buddy_info **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  if (arg1) (arg1)->sub_term_code = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1info_1sub_1term_1code_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_buddy_info *arg1 = (pjsua_buddy_info *) 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_buddy_info **)&jarg1; 
  result = (unsigned int) ((arg1)->sub_term_code);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1info_1sub_1term_1reason_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_) {
  pjsua_buddy_info *arg1 = (pjsua_buddy_info *) 0 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(pjsua_buddy_info **)&jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  if (arg1) (arg1)->sub_term_reason = *arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1info_1sub_1term_1reason_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_buddy_info *arg1 = (pjsua_buddy_info *) 0 ;
  pj_str_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_buddy_info **)&jarg1; 
  result = (pj_str_t *)& ((arg1)->sub_term_reason);
  *(pj_str_t **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1info_1rpid_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_buddy_info *arg1 = (pjsua_buddy_info *) 0 ;
  pjrpid_element arg2 ;
  pjrpid_element *argp2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_buddy_info **)&jarg1; 
  argp2 = *(pjrpid_element **)&jarg2; 
  if (!argp2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null pjrpid_element");
    return ;
  }
  arg2 = *argp2; 
  if (arg1) (arg1)->rpid = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1info_1rpid_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_buddy_info *arg1 = (pjsua_buddy_info *) 0 ;
  pjrpid_element result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_buddy_info **)&jarg1; 
  result =  ((arg1)->rpid);
  *(pjrpid_element **)&jresult = new pjrpid_element((const pjrpid_element &)result); 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1info_1pres_1status_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_buddy_info *arg1 = (pjsua_buddy_info *) 0 ;
  pjsip_pres_status arg2 ;
  pjsip_pres_status *argp2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_buddy_info **)&jarg1; 
  argp2 = *(pjsip_pres_status **)&jarg2; 
  if (!argp2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null pjsip_pres_status");
    return ;
  }
  arg2 = *argp2; 
  if (arg1) (arg1)->pres_status = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1info_1pres_1status_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_buddy_info *arg1 = (pjsua_buddy_info *) 0 ;
  pjsip_pres_status result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_buddy_info **)&jarg1; 
  result =  ((arg1)->pres_status);
  *(pjsip_pres_status **)&jresult = new pjsip_pres_status((const pjsip_pres_status &)result); 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1info_1buf_1_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jstring jarg2) {
  pjsua_buddy_info *arg1 = (pjsua_buddy_info *) 0 ;
  char *arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_buddy_info **)&jarg1; 
  arg2 = 0;
  if (jarg2) {
    arg2 = (char *)jenv->GetStringUTFChars(jarg2, 0);
    if (!arg2) return ;
  }
  {
    if(arg2) {
      strncpy((char*)arg1->buf_, (const char *)arg2, 512-1);
      arg1->buf_[512-1] = 0;
    } else {
      arg1->buf_[0] = 0;
    }
  }
  
  if (arg2) jenv->ReleaseStringUTFChars(jarg2, (const char *)arg2);
}


SWIGEXPORT jstring JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1info_1buf_1_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jstring jresult = 0 ;
  pjsua_buddy_info *arg1 = (pjsua_buddy_info *) 0 ;
  char *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_buddy_info **)&jarg1; 
  result = (char *)(char *) ((arg1)->buf_);
  if (result) jresult = jenv->NewStringUTF((const char *)result);
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_new_1pjsua_1buddy_1info(JNIEnv *jenv, jclass jcls) {
  jlong jresult = 0 ;
  pjsua_buddy_info *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  result = (pjsua_buddy_info *)new pjsua_buddy_info();
  *(pjsua_buddy_info **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_delete_1pjsua_1buddy_1info(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  pjsua_buddy_info *arg1 = (pjsua_buddy_info *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(pjsua_buddy_info **)&jarg1; 
  delete arg1;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_buddy_1config_1default(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  pjsua_buddy_config *arg1 = (pjsua_buddy_config *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_buddy_config **)&jarg1; 
  pjsua_buddy_config_default(arg1);
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_get_1buddy_1count(JNIEnv *jenv, jclass jcls) {
  jlong jresult = 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  result = (unsigned int)pjsua_get_buddy_count();
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_buddy_1is_1valid(JNIEnv *jenv, jclass jcls, jint jarg1) {
  jint jresult = 0 ;
  pjsua_buddy_id arg1 ;
  pj_bool_t result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (pjsua_buddy_id)jarg1; 
  result = (pj_bool_t)pjsua_buddy_is_valid(arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_enum_1buddies(JNIEnv *jenv, jclass jcls, jintArray jarg1, jlongArray jarg2) {
  jint jresult = 0 ;
  pjsua_buddy_id *arg1 ;
  unsigned int *arg2 = (unsigned int *) 0 ;
  jint *jarr1 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  if (!SWIG_JavaArrayInInt(jenv, &jarr1, &arg1, jarg1)) return 0; 
  {
    if (!jarg2) {
      SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "array null");
      return 0;
    }
    if (jenv->GetArrayLength(jarg2) == 0) {
      SWIG_JavaThrowException(jenv, SWIG_JavaIndexOutOfBoundsException, "Array must contain at least 1 element");
      return 0;
    }
    arg2 = (unsigned int *) jenv->GetLongArrayElements(jarg2, 0); 
  }
  result = (pj_status_t)pjsua_enum_buddies(arg1,arg2);
  jresult = (jint)result; 
  SWIG_JavaArrayArgoutInt(jenv, jarr1, arg1, jarg1); 
  {
    jenv->ReleaseLongArrayElements(jarg2, (jlong *)arg2, 0); 
  }
  delete [] arg1; 
  
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_buddy_1find(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pj_str_t *arg1 = (pj_str_t *) 0 ;
  pjsua_buddy_id result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pj_str_t **)&jarg1; 
  result = (pjsua_buddy_id)pjsua_buddy_find((pj_str_t const *)arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_buddy_1get_1info(JNIEnv *jenv, jclass jcls, jint jarg1, jlong jarg2, jobject jarg2_) {
  jint jresult = 0 ;
  pjsua_buddy_id arg1 ;
  pjsua_buddy_info *arg2 = (pjsua_buddy_info *) 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg2_;
  arg1 = (pjsua_buddy_id)jarg1; 
  arg2 = *(pjsua_buddy_info **)&jarg2; 
  result = (pj_status_t)pjsua_buddy_get_info(arg1,arg2);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_buddy_1set_1user_1data(JNIEnv *jenv, jclass jcls, jint jarg1, void * jarg2) {
  jint jresult = 0 ;
  pjsua_buddy_id arg1 ;
  void *arg2 = (void *) 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (pjsua_buddy_id)jarg1; 
  
  arg2 = jarg2;
  
  result = (pj_status_t)pjsua_buddy_set_user_data(arg1,arg2);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void * JNICALL Java_org_pjsip_pjsua_pjsuaJNI_buddy_1get_1user_1data(JNIEnv *jenv, jclass jcls, jint jarg1) {
  void * jresult = 0 ;
  pjsua_buddy_id arg1 ;
  void *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = (pjsua_buddy_id)jarg1; 
  result = (void *)pjsua_buddy_get_user_data(arg1);
  
  jresult = result; 
  
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_buddy_1add(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  jint jresult = 0 ;
  pjsua_buddy_config *arg1 = (pjsua_buddy_config *) 0 ;
  pjsua_buddy_id *arg2 = (pjsua_buddy_id *) 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_buddy_config **)&jarg1; 
  arg2 = *(pjsua_buddy_id **)&jarg2; 
  result = (pj_status_t)pjsua_buddy_add((pjsua_buddy_config const *)arg1,arg2);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_buddy_1del(JNIEnv *jenv, jclass jcls, jint jarg1) {
  jint jresult = 0 ;
  pjsua_buddy_id arg1 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (pjsua_buddy_id)jarg1; 
  result = (pj_status_t)pjsua_buddy_del(arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_buddy_1subscribe_1pres(JNIEnv *jenv, jclass jcls, jint jarg1, jint jarg2) {
  jint jresult = 0 ;
  pjsua_buddy_id arg1 ;
  pj_bool_t arg2 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (pjsua_buddy_id)jarg1; 
  arg2 = (pj_bool_t)jarg2; 
  result = (pj_status_t)pjsua_buddy_subscribe_pres(arg1,arg2);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_buddy_1update_1pres(JNIEnv *jenv, jclass jcls, jint jarg1) {
  jint jresult = 0 ;
  pjsua_buddy_id arg1 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (pjsua_buddy_id)jarg1; 
  result = (pj_status_t)pjsua_buddy_update_pres(arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pres_1notify(JNIEnv *jenv, jclass jcls, jint jarg1, jlong jarg2, jlong jarg3, jlong jarg4, jobject jarg4_, jlong jarg5, jobject jarg5_, jint jarg6, jlong jarg7) {
  jint jresult = 0 ;
  pjsua_acc_id arg1 ;
  pjsua_srv_pres *arg2 = (pjsua_srv_pres *) 0 ;
  pjsip_evsub_state arg3 ;
  pj_str_t *arg4 = (pj_str_t *) 0 ;
  pj_str_t *arg5 = (pj_str_t *) 0 ;
  pj_bool_t arg6 ;
  pjsua_msg_data *arg7 = (pjsua_msg_data *) 0 ;
  pjsip_evsub_state *argp3 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg4_;
  (void)jarg5_;
  arg1 = (pjsua_acc_id)jarg1; 
  arg2 = *(pjsua_srv_pres **)&jarg2; 
  argp3 = *(pjsip_evsub_state **)&jarg3; 
  if (!argp3) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null pjsip_evsub_state");
    return 0;
  }
  arg3 = *argp3; 
  arg4 = *(pj_str_t **)&jarg4; 
  arg5 = *(pj_str_t **)&jarg5; 
  arg6 = (pj_bool_t)jarg6; 
  arg7 = *(pjsua_msg_data **)&jarg7; 
  result = (pj_status_t)pjsua_pres_notify(arg1,arg2,arg3,(pj_str_t const *)arg4,(pj_str_t const *)arg5,arg6,(pjsua_msg_data const *)arg7);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pres_1dump(JNIEnv *jenv, jclass jcls, jint jarg1) {
  pj_bool_t arg1 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = (pj_bool_t)jarg1; 
  pjsua_pres_dump(arg1);
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1message_1method_1get(JNIEnv *jenv, jclass jcls) {
  jlong jresult = 0 ;
  pjsip_method result;
  
  (void)jenv;
  (void)jcls;
  result = (pjsip_method)pjsip_message_method;
  *(pjsip_method **)&jresult = new pjsip_method((const pjsip_method &)result); 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_im_1send(JNIEnv *jenv, jclass jcls, jint jarg1, jlong jarg2, jobject jarg2_, jlong jarg3, jobject jarg3_, jlong jarg4, jobject jarg4_, jlong jarg5, void * jarg6) {
  jint jresult = 0 ;
  pjsua_acc_id arg1 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  pj_str_t *arg3 = (pj_str_t *) 0 ;
  pj_str_t *arg4 = (pj_str_t *) 0 ;
  pjsua_msg_data *arg5 = (pjsua_msg_data *) 0 ;
  void *arg6 = (void *) 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg2_;
  (void)jarg3_;
  (void)jarg4_;
  arg1 = (pjsua_acc_id)jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  arg3 = *(pj_str_t **)&jarg3; 
  arg4 = *(pj_str_t **)&jarg4; 
  arg5 = *(pjsua_msg_data **)&jarg5; 
  
  arg6 = jarg6;
  
  result = (pj_status_t)pjsua_im_send(arg1,(pj_str_t const *)arg2,(pj_str_t const *)arg3,(pj_str_t const *)arg4,(pjsua_msg_data const *)arg5,arg6);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_im_1typing(JNIEnv *jenv, jclass jcls, jint jarg1, jlong jarg2, jobject jarg2_, jint jarg3, jlong jarg4) {
  jint jresult = 0 ;
  pjsua_acc_id arg1 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  pj_bool_t arg3 ;
  pjsua_msg_data *arg4 = (pjsua_msg_data *) 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg2_;
  arg1 = (pjsua_acc_id)jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  arg3 = (pj_bool_t)jarg3; 
  arg4 = *(pjsua_msg_data **)&jarg4; 
  result = (pj_status_t)pjsua_im_typing(arg1,(pj_str_t const *)arg2,arg3,(pjsua_msg_data const *)arg4);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSUA_1MAX_1CONF_1PORTS_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  result = (int)(254);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSUA_1DEFAULT_1CLOCK_1RATE_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  result = (int)(16000);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSUA_1DEFAULT_1AUDIO_1FRAME_1PTIME_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  result = (int)(20);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSUA_1DEFAULT_1CODEC_1QUALITY_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  result = (int)(8);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSUA_1DEFAULT_1ILBC_1MODE_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  result = (int)(30);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSUA_1DEFAULT_1EC_1TAIL_1LEN_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  result = (int)(200);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSUA_1MAX_1PLAYERS_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  result = (int)(32);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_PJSUA_1MAX_1RECORDERS_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  result = (int)(32);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1clock_1rate_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  unsigned int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  if (arg1) (arg1)->clock_rate = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1clock_1rate_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  result = (unsigned int) ((arg1)->clock_rate);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1snd_1clock_1rate_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  unsigned int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  if (arg1) (arg1)->snd_clock_rate = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1snd_1clock_1rate_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  result = (unsigned int) ((arg1)->snd_clock_rate);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1channel_1count_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  unsigned int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  if (arg1) (arg1)->channel_count = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1channel_1count_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  result = (unsigned int) ((arg1)->channel_count);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1audio_1frame_1ptime_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  unsigned int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  if (arg1) (arg1)->audio_frame_ptime = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1audio_1frame_1ptime_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  result = (unsigned int) ((arg1)->audio_frame_ptime);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1max_1media_1ports_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  unsigned int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  if (arg1) (arg1)->max_media_ports = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1max_1media_1ports_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  result = (unsigned int) ((arg1)->max_media_ports);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1has_1ioqueue_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  pj_bool_t arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  arg2 = (pj_bool_t)jarg2; 
  if (arg1) (arg1)->has_ioqueue = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1has_1ioqueue_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  pj_bool_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  result = (pj_bool_t) ((arg1)->has_ioqueue);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1thread_1cnt_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  unsigned int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  if (arg1) (arg1)->thread_cnt = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1thread_1cnt_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  result = (unsigned int) ((arg1)->thread_cnt);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1quality_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  unsigned int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  if (arg1) (arg1)->quality = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1quality_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  result = (unsigned int) ((arg1)->quality);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1ptime_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  unsigned int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  if (arg1) (arg1)->ptime = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1ptime_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  result = (unsigned int) ((arg1)->ptime);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1no_1vad_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  pj_bool_t arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  arg2 = (pj_bool_t)jarg2; 
  if (arg1) (arg1)->no_vad = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1no_1vad_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  pj_bool_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  result = (pj_bool_t) ((arg1)->no_vad);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1ilbc_1mode_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  unsigned int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  if (arg1) (arg1)->ilbc_mode = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1ilbc_1mode_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  result = (unsigned int) ((arg1)->ilbc_mode);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1tx_1drop_1pct_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  unsigned int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  if (arg1) (arg1)->tx_drop_pct = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1tx_1drop_1pct_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  result = (unsigned int) ((arg1)->tx_drop_pct);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1rx_1drop_1pct_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  unsigned int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  if (arg1) (arg1)->rx_drop_pct = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1rx_1drop_1pct_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  result = (unsigned int) ((arg1)->rx_drop_pct);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1ec_1options_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  unsigned int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  if (arg1) (arg1)->ec_options = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1ec_1options_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  result = (unsigned int) ((arg1)->ec_options);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1ec_1tail_1len_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  unsigned int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  if (arg1) (arg1)->ec_tail_len = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1ec_1tail_1len_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  result = (unsigned int) ((arg1)->ec_tail_len);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1snd_1rec_1latency_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  unsigned int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  if (arg1) (arg1)->snd_rec_latency = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1snd_1rec_1latency_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  result = (unsigned int) ((arg1)->snd_rec_latency);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1snd_1play_1latency_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  unsigned int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  if (arg1) (arg1)->snd_play_latency = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1snd_1play_1latency_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  result = (unsigned int) ((arg1)->snd_play_latency);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1jb_1init_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  arg2 = (int)jarg2; 
  if (arg1) (arg1)->jb_init = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1jb_1init_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  result = (int) ((arg1)->jb_init);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1jb_1min_1pre_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  arg2 = (int)jarg2; 
  if (arg1) (arg1)->jb_min_pre = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1jb_1min_1pre_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  result = (int) ((arg1)->jb_min_pre);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1jb_1max_1pre_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  arg2 = (int)jarg2; 
  if (arg1) (arg1)->jb_max_pre = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1jb_1max_1pre_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  result = (int) ((arg1)->jb_max_pre);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1jb_1max_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  arg2 = (int)jarg2; 
  if (arg1) (arg1)->jb_max = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1jb_1max_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  result = (int) ((arg1)->jb_max);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1enable_1ice_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  pj_bool_t arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  arg2 = (pj_bool_t)jarg2; 
  if (arg1) (arg1)->enable_ice = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1enable_1ice_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  pj_bool_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  result = (pj_bool_t) ((arg1)->enable_ice);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1ice_1max_1host_1cands_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  arg2 = (int)jarg2; 
  if (arg1) (arg1)->ice_max_host_cands = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1ice_1max_1host_1cands_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  result = (int) ((arg1)->ice_max_host_cands);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1ice_1opt_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  pj_ice_sess_options arg2 ;
  pj_ice_sess_options *argp2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  argp2 = *(pj_ice_sess_options **)&jarg2; 
  if (!argp2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null pj_ice_sess_options");
    return ;
  }
  arg2 = *argp2; 
  if (arg1) (arg1)->ice_opt = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1ice_1opt_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  pj_ice_sess_options result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  result =  ((arg1)->ice_opt);
  *(pj_ice_sess_options **)&jresult = new pj_ice_sess_options((const pj_ice_sess_options &)result); 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1ice_1no_1rtcp_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  pj_bool_t arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  arg2 = (pj_bool_t)jarg2; 
  if (arg1) (arg1)->ice_no_rtcp = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1ice_1no_1rtcp_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  pj_bool_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  result = (pj_bool_t) ((arg1)->ice_no_rtcp);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1enable_1turn_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  pj_bool_t arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  arg2 = (pj_bool_t)jarg2; 
  if (arg1) (arg1)->enable_turn = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1enable_1turn_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  pj_bool_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  result = (pj_bool_t) ((arg1)->enable_turn);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1turn_1server_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_) {
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  if (arg1) (arg1)->turn_server = *arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1turn_1server_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  pj_str_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  result = (pj_str_t *)& ((arg1)->turn_server);
  *(pj_str_t **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1turn_1conn_1type_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  pj_turn_tp_type arg2 ;
  pj_turn_tp_type *argp2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  argp2 = *(pj_turn_tp_type **)&jarg2; 
  if (!argp2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null pj_turn_tp_type");
    return ;
  }
  arg2 = *argp2; 
  if (arg1) (arg1)->turn_conn_type = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1turn_1conn_1type_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  pj_turn_tp_type result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  result =  ((arg1)->turn_conn_type);
  *(pj_turn_tp_type **)&jresult = new pj_turn_tp_type((const pj_turn_tp_type &)result); 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1turn_1auth_1cred_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  pj_stun_auth_cred arg2 ;
  pj_stun_auth_cred *argp2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  argp2 = *(pj_stun_auth_cred **)&jarg2; 
  if (!argp2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null pj_stun_auth_cred");
    return ;
  }
  arg2 = *argp2; 
  if (arg1) (arg1)->turn_auth_cred = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1turn_1auth_1cred_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  pj_stun_auth_cred result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  result =  ((arg1)->turn_auth_cred);
  *(pj_stun_auth_cred **)&jresult = new pj_stun_auth_cred((const pj_stun_auth_cred &)result); 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1snd_1auto_1close_1time_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  arg2 = (int)jarg2; 
  if (arg1) (arg1)->snd_auto_close_time = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1snd_1auto_1close_1time_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  result = (int) ((arg1)->snd_auto_close_time);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_new_1pjsua_1media_1config(JNIEnv *jenv, jclass jcls) {
  jlong jresult = 0 ;
  pjsua_media_config *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  result = (pjsua_media_config *)new pjsua_media_config();
  *(pjsua_media_config **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_delete_1pjsua_1media_1config(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(pjsua_media_config **)&jarg1; 
  delete arg1;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_media_1config_1default(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  pjsua_media_config *arg1 = (pjsua_media_config *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_config **)&jarg1; 
  pjsua_media_config_default(arg1);
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1codec_1info_1codec_1id_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_) {
  pjsua_codec_info *arg1 = (pjsua_codec_info *) 0 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(pjsua_codec_info **)&jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  if (arg1) (arg1)->codec_id = *arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1codec_1info_1codec_1id_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_codec_info *arg1 = (pjsua_codec_info *) 0 ;
  pj_str_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_codec_info **)&jarg1; 
  result = (pj_str_t *)& ((arg1)->codec_id);
  *(pj_str_t **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1codec_1info_1priority_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jshort jarg2) {
  pjsua_codec_info *arg1 = (pjsua_codec_info *) 0 ;
  pj_uint8_t arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_codec_info **)&jarg1; 
  arg2 = (pj_uint8_t)jarg2; 
  if (arg1) (arg1)->priority = arg2;
}


SWIGEXPORT jshort JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1codec_1info_1priority_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jshort jresult = 0 ;
  pjsua_codec_info *arg1 = (pjsua_codec_info *) 0 ;
  pj_uint8_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_codec_info **)&jarg1; 
  result = (pj_uint8_t) ((arg1)->priority);
  jresult = (jshort)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1codec_1info_1buf_1_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jstring jarg2) {
  pjsua_codec_info *arg1 = (pjsua_codec_info *) 0 ;
  char *arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_codec_info **)&jarg1; 
  arg2 = 0;
  if (jarg2) {
    arg2 = (char *)jenv->GetStringUTFChars(jarg2, 0);
    if (!arg2) return ;
  }
  {
    if(arg2) {
      strncpy((char*)arg1->buf_, (const char *)arg2, 32-1);
      arg1->buf_[32-1] = 0;
    } else {
      arg1->buf_[0] = 0;
    }
  }
  
  if (arg2) jenv->ReleaseStringUTFChars(jarg2, (const char *)arg2);
}


SWIGEXPORT jstring JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1codec_1info_1buf_1_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jstring jresult = 0 ;
  pjsua_codec_info *arg1 = (pjsua_codec_info *) 0 ;
  char *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_codec_info **)&jarg1; 
  result = (char *)(char *) ((arg1)->buf_);
  if (result) jresult = jenv->NewStringUTF((const char *)result);
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_new_1pjsua_1codec_1info(JNIEnv *jenv, jclass jcls) {
  jlong jresult = 0 ;
  pjsua_codec_info *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  result = (pjsua_codec_info *)new pjsua_codec_info();
  *(pjsua_codec_info **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_delete_1pjsua_1codec_1info(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  pjsua_codec_info *arg1 = (pjsua_codec_info *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(pjsua_codec_info **)&jarg1; 
  delete arg1;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1conf_1port_1info_1slot_1id_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  pjsua_conf_port_info *arg1 = (pjsua_conf_port_info *) 0 ;
  pjsua_conf_port_id arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_conf_port_info **)&jarg1; 
  arg2 = (pjsua_conf_port_id)jarg2; 
  if (arg1) (arg1)->slot_id = arg2;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1conf_1port_1info_1slot_1id_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_conf_port_info *arg1 = (pjsua_conf_port_info *) 0 ;
  pjsua_conf_port_id result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_conf_port_info **)&jarg1; 
  result = (pjsua_conf_port_id) ((arg1)->slot_id);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1conf_1port_1info_1name_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_) {
  pjsua_conf_port_info *arg1 = (pjsua_conf_port_info *) 0 ;
  pj_str_t *arg2 = (pj_str_t *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(pjsua_conf_port_info **)&jarg1; 
  arg2 = *(pj_str_t **)&jarg2; 
  if (arg1) (arg1)->name = *arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1conf_1port_1info_1name_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_conf_port_info *arg1 = (pjsua_conf_port_info *) 0 ;
  pj_str_t *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_conf_port_info **)&jarg1; 
  result = (pj_str_t *)& ((arg1)->name);
  *(pj_str_t **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1conf_1port_1info_1clock_1rate_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_conf_port_info *arg1 = (pjsua_conf_port_info *) 0 ;
  unsigned int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_conf_port_info **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  if (arg1) (arg1)->clock_rate = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1conf_1port_1info_1clock_1rate_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_conf_port_info *arg1 = (pjsua_conf_port_info *) 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_conf_port_info **)&jarg1; 
  result = (unsigned int) ((arg1)->clock_rate);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1conf_1port_1info_1channel_1count_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_conf_port_info *arg1 = (pjsua_conf_port_info *) 0 ;
  unsigned int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_conf_port_info **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  if (arg1) (arg1)->channel_count = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1conf_1port_1info_1channel_1count_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_conf_port_info *arg1 = (pjsua_conf_port_info *) 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_conf_port_info **)&jarg1; 
  result = (unsigned int) ((arg1)->channel_count);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1conf_1port_1info_1samples_1per_1frame_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_conf_port_info *arg1 = (pjsua_conf_port_info *) 0 ;
  unsigned int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_conf_port_info **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  if (arg1) (arg1)->samples_per_frame = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1conf_1port_1info_1samples_1per_1frame_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_conf_port_info *arg1 = (pjsua_conf_port_info *) 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_conf_port_info **)&jarg1; 
  result = (unsigned int) ((arg1)->samples_per_frame);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1conf_1port_1info_1bits_1per_1sample_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_conf_port_info *arg1 = (pjsua_conf_port_info *) 0 ;
  unsigned int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_conf_port_info **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  if (arg1) (arg1)->bits_per_sample = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1conf_1port_1info_1bits_1per_1sample_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_conf_port_info *arg1 = (pjsua_conf_port_info *) 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_conf_port_info **)&jarg1; 
  result = (unsigned int) ((arg1)->bits_per_sample);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1conf_1port_1info_1listener_1cnt_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_conf_port_info *arg1 = (pjsua_conf_port_info *) 0 ;
  unsigned int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_conf_port_info **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  if (arg1) (arg1)->listener_cnt = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1conf_1port_1info_1listener_1cnt_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_conf_port_info *arg1 = (pjsua_conf_port_info *) 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_conf_port_info **)&jarg1; 
  result = (unsigned int) ((arg1)->listener_cnt);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1conf_1port_1info_1listeners_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jintArray jarg2) {
  pjsua_conf_port_info *arg1 = (pjsua_conf_port_info *) 0 ;
  pjsua_conf_port_id *arg2 ;
  jint *jarr2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_conf_port_info **)&jarg1; 
  if (jarg2 && jenv->GetArrayLength(jarg2) != 254) {
    SWIG_JavaThrowException(jenv, SWIG_JavaIndexOutOfBoundsException, "incorrect array size");
    return ;
  }
  if (!SWIG_JavaArrayInInt(jenv, &jarr2, &arg2, jarg2)) return ; 
  {
    size_t ii;
    pjsua_conf_port_id *b = (pjsua_conf_port_id *) arg1->listeners;
    for (ii = 0; ii < (size_t)254; ii++) b[ii] = *((pjsua_conf_port_id *) arg2 + ii);
  }
  SWIG_JavaArrayArgoutInt(jenv, jarr2, arg2, jarg2); 
  delete [] arg2; 
}


SWIGEXPORT jintArray JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1conf_1port_1info_1listeners_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jintArray jresult = 0 ;
  pjsua_conf_port_info *arg1 = (pjsua_conf_port_info *) 0 ;
  pjsua_conf_port_id *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_conf_port_info **)&jarg1; 
  result = (pjsua_conf_port_id *)(pjsua_conf_port_id *) ((arg1)->listeners);
  jresult = SWIG_JavaArrayOutInt(jenv, result, 254); 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_new_1pjsua_1conf_1port_1info(JNIEnv *jenv, jclass jcls) {
  jlong jresult = 0 ;
  pjsua_conf_port_info *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  result = (pjsua_conf_port_info *)new pjsua_conf_port_info();
  *(pjsua_conf_port_info **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_delete_1pjsua_1conf_1port_1info(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  pjsua_conf_port_info *arg1 = (pjsua_conf_port_info *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(pjsua_conf_port_info **)&jarg1; 
  delete arg1;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1transport_1skinfo_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_media_transport *arg1 = (pjsua_media_transport *) 0 ;
  pjmedia_sock_info arg2 ;
  pjmedia_sock_info *argp2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_transport **)&jarg1; 
  argp2 = *(pjmedia_sock_info **)&jarg2; 
  if (!argp2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null pjmedia_sock_info");
    return ;
  }
  arg2 = *argp2; 
  if (arg1) (arg1)->skinfo = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1transport_1skinfo_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_media_transport *arg1 = (pjsua_media_transport *) 0 ;
  pjmedia_sock_info result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_transport **)&jarg1; 
  result =  ((arg1)->skinfo);
  *(pjmedia_sock_info **)&jresult = new pjmedia_sock_info((const pjmedia_sock_info &)result); 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1transport_1transport_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  pjsua_media_transport *arg1 = (pjsua_media_transport *) 0 ;
  pjmedia_transport *arg2 = (pjmedia_transport *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_transport **)&jarg1; 
  arg2 = *(pjmedia_transport **)&jarg2; 
  if (arg1) (arg1)->transport = arg2;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1transport_1transport_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  pjsua_media_transport *arg1 = (pjsua_media_transport *) 0 ;
  pjmedia_transport *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_media_transport **)&jarg1; 
  result = (pjmedia_transport *) ((arg1)->transport);
  *(pjmedia_transport **)&jresult = result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_new_1pjsua_1media_1transport(JNIEnv *jenv, jclass jcls) {
  jlong jresult = 0 ;
  pjsua_media_transport *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  result = (pjsua_media_transport *)new pjsua_media_transport();
  *(pjsua_media_transport **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_delete_1pjsua_1media_1transport(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  pjsua_media_transport *arg1 = (pjsua_media_transport *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(pjsua_media_transport **)&jarg1; 
  delete arg1;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_conf_1get_1max_1ports(JNIEnv *jenv, jclass jcls) {
  jlong jresult = 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  result = (unsigned int)pjsua_conf_get_max_ports();
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_conf_1get_1active_1ports(JNIEnv *jenv, jclass jcls) {
  jlong jresult = 0 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  result = (unsigned int)pjsua_conf_get_active_ports();
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_enum_1conf_1ports(JNIEnv *jenv, jclass jcls, jintArray jarg1, jlongArray jarg2) {
  jint jresult = 0 ;
  pjsua_conf_port_id *arg1 ;
  unsigned int *arg2 = (unsigned int *) 0 ;
  jint *jarr1 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  if (!SWIG_JavaArrayInInt(jenv, &jarr1, &arg1, jarg1)) return 0; 
  {
    if (!jarg2) {
      SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "array null");
      return 0;
    }
    if (jenv->GetArrayLength(jarg2) == 0) {
      SWIG_JavaThrowException(jenv, SWIG_JavaIndexOutOfBoundsException, "Array must contain at least 1 element");
      return 0;
    }
    arg2 = (unsigned int *) jenv->GetLongArrayElements(jarg2, 0); 
  }
  result = (pj_status_t)pjsua_enum_conf_ports(arg1,arg2);
  jresult = (jint)result; 
  SWIG_JavaArrayArgoutInt(jenv, jarr1, arg1, jarg1); 
  {
    jenv->ReleaseLongArrayElements(jarg2, (jlong *)arg2, 0); 
  }
  delete [] arg1; 
  
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_conf_1get_1port_1info(JNIEnv *jenv, jclass jcls, jint jarg1, jlong jarg2, jobject jarg2_) {
  jint jresult = 0 ;
  pjsua_conf_port_id arg1 ;
  pjsua_conf_port_info *arg2 = (pjsua_conf_port_info *) 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg2_;
  arg1 = (pjsua_conf_port_id)jarg1; 
  arg2 = *(pjsua_conf_port_info **)&jarg2; 
  result = (pj_status_t)pjsua_conf_get_port_info(arg1,arg2);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_conf_1add_1port(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_, jintArray jarg3) {
  jint jresult = 0 ;
  pj_pool_t *arg1 = (pj_pool_t *) 0 ;
  pjmedia_port *arg2 = (pjmedia_port *) 0 ;
  pjsua_conf_port_id *arg3 = (pjsua_conf_port_id *) 0 ;
  pjsua_conf_port_id temp3 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(pj_pool_t **)&jarg1; 
  arg2 = *(pjmedia_port **)&jarg2; 
  {
    if (!jarg3) {
      SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "array null");
      return 0;
    }
    if (jenv->GetArrayLength(jarg3) == 0) {
      SWIG_JavaThrowException(jenv, SWIG_JavaIndexOutOfBoundsException, "Array must contain at least 1 element");
      return 0;
    }
    arg3 = &temp3; 
  }
  result = (pj_status_t)pjsua_conf_add_port(arg1,arg2,arg3);
  jresult = (jint)result; 
  {
    jint jvalue = (jint)temp3;
    jenv->SetIntArrayRegion(jarg3, 0, 1, &jvalue);
  }
  
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_conf_1remove_1port(JNIEnv *jenv, jclass jcls, jint jarg1) {
  jint jresult = 0 ;
  pjsua_conf_port_id arg1 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (pjsua_conf_port_id)jarg1; 
  result = (pj_status_t)pjsua_conf_remove_port(arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_conf_1connect(JNIEnv *jenv, jclass jcls, jint jarg1, jint jarg2) {
  jint jresult = 0 ;
  pjsua_conf_port_id arg1 ;
  pjsua_conf_port_id arg2 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (pjsua_conf_port_id)jarg1; 
  arg2 = (pjsua_conf_port_id)jarg2; 
  result = (pj_status_t)pjsua_conf_connect(arg1,arg2);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_conf_1disconnect(JNIEnv *jenv, jclass jcls, jint jarg1, jint jarg2) {
  jint jresult = 0 ;
  pjsua_conf_port_id arg1 ;
  pjsua_conf_port_id arg2 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (pjsua_conf_port_id)jarg1; 
  arg2 = (pjsua_conf_port_id)jarg2; 
  result = (pj_status_t)pjsua_conf_disconnect(arg1,arg2);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_conf_1adjust_1tx_1level(JNIEnv *jenv, jclass jcls, jint jarg1, jfloat jarg2) {
  jint jresult = 0 ;
  pjsua_conf_port_id arg1 ;
  float arg2 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (pjsua_conf_port_id)jarg1; 
  arg2 = (float)jarg2; 
  result = (pj_status_t)pjsua_conf_adjust_tx_level(arg1,arg2);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_conf_1adjust_1rx_1level(JNIEnv *jenv, jclass jcls, jint jarg1, jfloat jarg2) {
  jint jresult = 0 ;
  pjsua_conf_port_id arg1 ;
  float arg2 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (pjsua_conf_port_id)jarg1; 
  arg2 = (float)jarg2; 
  result = (pj_status_t)pjsua_conf_adjust_rx_level(arg1,arg2);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_conf_1get_1signal_1level(JNIEnv *jenv, jclass jcls, jint jarg1, jlong jarg2, jlong jarg3) {
  jint jresult = 0 ;
  pjsua_conf_port_id arg1 ;
  unsigned int *arg2 = (unsigned int *) 0 ;
  unsigned int *arg3 = (unsigned int *) 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (pjsua_conf_port_id)jarg1; 
  arg2 = *(unsigned int **)&jarg2; 
  arg3 = *(unsigned int **)&jarg3; 
  result = (pj_status_t)pjsua_conf_get_signal_level(arg1,arg2,arg3);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_player_1create(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jlong jarg3) {
  jint jresult = 0 ;
  pj_str_t *arg1 = (pj_str_t *) 0 ;
  unsigned int arg2 ;
  pjsua_player_id *arg3 = (pjsua_player_id *) 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pj_str_t **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  arg3 = *(pjsua_player_id **)&jarg3; 
  result = (pj_status_t)pjsua_player_create((pj_str_t const *)arg1,arg2,arg3);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_playlist_1create(JNIEnv *jenv, jclass jcls, jlongArray jarg1, jlong jarg2, jlong jarg3, jobject jarg3_, jlong jarg4, jlong jarg5) {
  jint jresult = 0 ;
  pj_str_t *arg1 ;
  unsigned int arg2 ;
  pj_str_t *arg3 = (pj_str_t *) 0 ;
  unsigned int arg4 ;
  pjsua_player_id *arg5 = (pjsua_player_id *) 0 ;
  jlong *jarr1 ;
  jsize sz1 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg3_;
  {
    int i;
    if (!jarg1) {
      SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "null array");
      return 0;
    }
    sz1 = jenv->GetArrayLength(jarg1);
    jarr1 = jenv->GetLongArrayElements(jarg1, 0);
    if (!jarr1) {
      return 0;
    }
    
    arg1 = new pj_str_t[sz1];
    
    
    
    if (!arg1) {
      SWIG_JavaThrowException(jenv, SWIG_JavaOutOfMemoryError, "array memory allocation failed");
      return 0;
    }
    for (i=0; i<sz1; i++) {
      arg1[i] = **(pj_str_t **)&jarr1[i];
    }
  }
  arg2 = (unsigned int)jarg2; 
  arg3 = *(pj_str_t **)&jarg3; 
  arg4 = (unsigned int)jarg4; 
  arg5 = *(pjsua_player_id **)&jarg5; 
  result = (pj_status_t)pjsua_playlist_create((pj_str_t const (*))arg1,arg2,(pj_str_t const *)arg3,arg4,arg5);
  jresult = (jint)result; 
  {
    int i;
    for (i=0; i<sz1; i++) {
      **(pj_str_t **)&jarr1[i] = arg1[i];
    }
    jenv->ReleaseLongArrayElements(jarg1, jarr1, 0);
  }
  delete [] arg1; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_player_1get_1conf_1port(JNIEnv *jenv, jclass jcls, jint jarg1) {
  jint jresult = 0 ;
  pjsua_player_id arg1 ;
  pjsua_conf_port_id result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (pjsua_player_id)jarg1; 
  result = (pjsua_conf_port_id)pjsua_player_get_conf_port(arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_player_1get_1port(JNIEnv *jenv, jclass jcls, jint jarg1, jlong jarg2) {
  jint jresult = 0 ;
  pjsua_player_id arg1 ;
  pjmedia_port **arg2 = (pjmedia_port **) 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (pjsua_player_id)jarg1; 
  arg2 = *(pjmedia_port ***)&jarg2; 
  result = (pj_status_t)pjsua_player_get_port(arg1,arg2);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_player_1set_1pos(JNIEnv *jenv, jclass jcls, jint jarg1, jlong jarg2) {
  jint jresult = 0 ;
  pjsua_player_id arg1 ;
  pj_uint32_t arg2 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (pjsua_player_id)jarg1; 
  arg2 = (pj_uint32_t)jarg2; 
  result = (pj_status_t)pjsua_player_set_pos(arg1,arg2);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_player_1destroy(JNIEnv *jenv, jclass jcls, jint jarg1) {
  jint jresult = 0 ;
  pjsua_player_id arg1 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (pjsua_player_id)jarg1; 
  result = (pj_status_t)pjsua_player_destroy(arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_recorder_1create(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, void * jarg3, jlong jarg4, jlong jarg5, jlong jarg6) {
  jint jresult = 0 ;
  pj_str_t *arg1 = (pj_str_t *) 0 ;
  unsigned int arg2 ;
  void *arg3 = (void *) 0 ;
  pj_ssize_t arg4 ;
  unsigned int arg5 ;
  pjsua_recorder_id *arg6 = (pjsua_recorder_id *) 0 ;
  pj_ssize_t *argp4 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pj_str_t **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  
  arg3 = jarg3;
  
  argp4 = *(pj_ssize_t **)&jarg4; 
  if (!argp4) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null pj_ssize_t");
    return 0;
  }
  arg4 = *argp4; 
  arg5 = (unsigned int)jarg5; 
  arg6 = *(pjsua_recorder_id **)&jarg6; 
  result = (pj_status_t)pjsua_recorder_create((pj_str_t const *)arg1,arg2,arg3,arg4,arg5,arg6);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_recorder_1get_1conf_1port(JNIEnv *jenv, jclass jcls, jint jarg1) {
  jint jresult = 0 ;
  pjsua_recorder_id arg1 ;
  pjsua_conf_port_id result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (pjsua_recorder_id)jarg1; 
  result = (pjsua_conf_port_id)pjsua_recorder_get_conf_port(arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_recorder_1get_1port(JNIEnv *jenv, jclass jcls, jint jarg1, jlong jarg2) {
  jint jresult = 0 ;
  pjsua_recorder_id arg1 ;
  pjmedia_port **arg2 = (pjmedia_port **) 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (pjsua_recorder_id)jarg1; 
  arg2 = *(pjmedia_port ***)&jarg2; 
  result = (pj_status_t)pjsua_recorder_get_port(arg1,arg2);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_recorder_1destroy(JNIEnv *jenv, jclass jcls, jint jarg1) {
  jint jresult = 0 ;
  pjsua_recorder_id arg1 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (pjsua_recorder_id)jarg1; 
  result = (pj_status_t)pjsua_recorder_destroy(arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_enum_1aud_1devs(JNIEnv *jenv, jclass jcls, jlong jarg1, jlongArray jarg2) {
  jint jresult = 0 ;
  pjmedia_aud_dev_info *arg1 ;
  unsigned int *arg2 = (unsigned int *) 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(pjmedia_aud_dev_info **)&jarg1; 
  {
    if (!jarg2) {
      SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "array null");
      return 0;
    }
    if (jenv->GetArrayLength(jarg2) == 0) {
      SWIG_JavaThrowException(jenv, SWIG_JavaIndexOutOfBoundsException, "Array must contain at least 1 element");
      return 0;
    }
    arg2 = (unsigned int *) jenv->GetLongArrayElements(jarg2, 0); 
  }
  result = (pj_status_t)pjsua_enum_aud_devs(arg1,arg2);
  jresult = (jint)result; 
  {
    jenv->ReleaseLongArrayElements(jarg2, (jlong *)arg2, 0); 
  }
  
  
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_enum_1snd_1devs(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlongArray jarg2) {
  jint jresult = 0 ;
  pjmedia_snd_dev_info *arg1 ;
  unsigned int *arg2 = (unsigned int *) 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjmedia_snd_dev_info **)&jarg1; 
  {
    if (!jarg2) {
      SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "array null");
      return 0;
    }
    if (jenv->GetArrayLength(jarg2) == 0) {
      SWIG_JavaThrowException(jenv, SWIG_JavaIndexOutOfBoundsException, "Array must contain at least 1 element");
      return 0;
    }
    arg2 = (unsigned int *) jenv->GetLongArrayElements(jarg2, 0); 
  }
  result = (pj_status_t)pjsua_enum_snd_devs(arg1,arg2);
  jresult = (jint)result; 
  {
    jenv->ReleaseLongArrayElements(jarg2, (jlong *)arg2, 0); 
  }
  
  
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_get_1snd_1dev(JNIEnv *jenv, jclass jcls, jintArray jarg1, jintArray jarg2) {
  jint jresult = 0 ;
  int *arg1 = (int *) 0 ;
  int *arg2 = (int *) 0 ;
  int temp1 ;
  int temp2 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  {
    if (!jarg1) {
      SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "array null");
      return 0;
    }
    if (jenv->GetArrayLength(jarg1) == 0) {
      SWIG_JavaThrowException(jenv, SWIG_JavaIndexOutOfBoundsException, "Array must contain at least 1 element");
      return 0;
    }
    arg1 = &temp1; 
  }
  {
    if (!jarg2) {
      SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "array null");
      return 0;
    }
    if (jenv->GetArrayLength(jarg2) == 0) {
      SWIG_JavaThrowException(jenv, SWIG_JavaIndexOutOfBoundsException, "Array must contain at least 1 element");
      return 0;
    }
    arg2 = &temp2; 
  }
  result = (pj_status_t)pjsua_get_snd_dev(arg1,arg2);
  jresult = (jint)result; 
  {
    jint jvalue = (jint)temp1;
    jenv->SetIntArrayRegion(jarg1, 0, 1, &jvalue);
  }
  {
    jint jvalue = (jint)temp2;
    jenv->SetIntArrayRegion(jarg2, 0, 1, &jvalue);
  }
  
  
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_set_1snd_1dev(JNIEnv *jenv, jclass jcls, jint jarg1, jint jarg2) {
  jint jresult = 0 ;
  int arg1 ;
  int arg2 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (int)jarg1; 
  arg2 = (int)jarg2; 
  result = (pj_status_t)pjsua_set_snd_dev(arg1,arg2);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_set_1null_1snd_1dev(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  result = (pj_status_t)pjsua_set_null_snd_dev();
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_set_1no_1snd_1dev(JNIEnv *jenv, jclass jcls) {
  jlong jresult = 0 ;
  pjmedia_port *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  result = (pjmedia_port *)pjsua_set_no_snd_dev();
  *(pjmedia_port **)&jresult = result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_set_1ec(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2) {
  jint jresult = 0 ;
  unsigned int arg1 ;
  unsigned int arg2 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (unsigned int)jarg1; 
  arg2 = (unsigned int)jarg2; 
  result = (pj_status_t)pjsua_set_ec(arg1,arg2);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_get_1ec_1tail(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  jint jresult = 0 ;
  unsigned int *arg1 = (unsigned int *) 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(unsigned int **)&jarg1; 
  result = (pj_status_t)pjsua_get_ec_tail(arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_snd_1is_1active(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pj_bool_t result;
  
  (void)jenv;
  (void)jcls;
  result = (pj_bool_t)pjsua_snd_is_active();
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_snd_1set_1setting(JNIEnv *jenv, jclass jcls, jlong jarg1, void * jarg2, jint jarg3) {
  jint jresult = 0 ;
  pjmedia_aud_dev_cap arg1 ;
  void *arg2 = (void *) 0 ;
  pj_bool_t arg3 ;
  pjmedia_aud_dev_cap *argp1 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  argp1 = *(pjmedia_aud_dev_cap **)&jarg1; 
  if (!argp1) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null pjmedia_aud_dev_cap");
    return 0;
  }
  arg1 = *argp1; 
  
  arg2 = jarg2;
  
  arg3 = (pj_bool_t)jarg3; 
  result = (pj_status_t)pjsua_snd_set_setting(arg1,(void const *)arg2,arg3);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_snd_1get_1setting(JNIEnv *jenv, jclass jcls, jlong jarg1, void * jarg2) {
  jint jresult = 0 ;
  pjmedia_aud_dev_cap arg1 ;
  void *arg2 = (void *) 0 ;
  pjmedia_aud_dev_cap *argp1 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  argp1 = *(pjmedia_aud_dev_cap **)&jarg1; 
  if (!argp1) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null pjmedia_aud_dev_cap");
    return 0;
  }
  arg1 = *argp1; 
  
  arg2 = jarg2;
  
  result = (pj_status_t)pjsua_snd_get_setting(arg1,arg2);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_enum_1codecs(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlongArray jarg2) {
  jint jresult = 0 ;
  pjsua_codec_info *arg1 ;
  unsigned int *arg2 = (unsigned int *) 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_codec_info **)&jarg1; 
  {
    if (!jarg2) {
      SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "array null");
      return 0;
    }
    if (jenv->GetArrayLength(jarg2) == 0) {
      SWIG_JavaThrowException(jenv, SWIG_JavaIndexOutOfBoundsException, "Array must contain at least 1 element");
      return 0;
    }
    arg2 = (unsigned int *) jenv->GetLongArrayElements(jarg2, 0); 
  }
  result = (pj_status_t)pjsua_enum_codecs(arg1,arg2);
  jresult = (jint)result; 
  {
    jenv->ReleaseLongArrayElements(jarg2, (jlong *)arg2, 0); 
  }
  
  
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_codec_1set_1priority(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jshort jarg2) {
  jint jresult = 0 ;
  pj_str_t *arg1 = (pj_str_t *) 0 ;
  pj_uint8_t arg2 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pj_str_t **)&jarg1; 
  arg2 = (pj_uint8_t)jarg2; 
  result = (pj_status_t)pjsua_codec_set_priority((pj_str_t const *)arg1,arg2);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_codec_1get_1param(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  jint jresult = 0 ;
  pj_str_t *arg1 = (pj_str_t *) 0 ;
  pjmedia_codec_param *arg2 = (pjmedia_codec_param *) 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pj_str_t **)&jarg1; 
  arg2 = *(pjmedia_codec_param **)&jarg2; 
  result = (pj_status_t)pjsua_codec_get_param((pj_str_t const *)arg1,arg2);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_codec_1set_1param(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  jint jresult = 0 ;
  pj_str_t *arg1 = (pj_str_t *) 0 ;
  pjmedia_codec_param *arg2 = (pjmedia_codec_param *) 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pj_str_t **)&jarg1; 
  arg2 = *(pjmedia_codec_param **)&jarg2; 
  result = (pj_status_t)pjsua_codec_set_param((pj_str_t const *)arg1,(pjmedia_codec_param const *)arg2);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_media_1transports_1create(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_transport_config *arg1 = (pjsua_transport_config *) 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(pjsua_transport_config **)&jarg1; 
  result = (pj_status_t)pjsua_media_transports_create((pjsua_transport_config const *)arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_codecs_1get_1nbr(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  result = (int)codecs_get_nbr();
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_codecs_1get_1id(JNIEnv *jenv, jclass jcls, jint jarg1) {
  jlong jresult = 0 ;
  int arg1 ;
  pj_str_t result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (int)jarg1; 
  result = codecs_get_id(arg1);
  *(pj_str_t **)&jresult = new pj_str_t((const pj_str_t &)result); 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_test_1audio_1dev(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2) {
  jint jresult = 0 ;
  unsigned int arg1 ;
  unsigned int arg2 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (unsigned int)jarg1; 
  arg2 = (unsigned int)jarg2; 
  result = (pj_status_t)test_audio_dev(arg1,arg2);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_send_1dtmf_1info(JNIEnv *jenv, jclass jcls, jint jarg1, jlong jarg2, jobject jarg2_) {
  jint jresult = 0 ;
  int arg1 ;
  pj_str_t arg2 ;
  pj_str_t *argp2 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg2_;
  arg1 = (int)jarg1; 
  argp2 = *(pj_str_t **)&jarg2; 
  if (!argp2) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null pj_str_t");
    return 0;
  }
  arg2 = *argp2; 
  result = (pj_status_t)send_dtmf_info(arg1,arg2);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_org_pjsip_pjsua_pjsuaJNI_call_1dump_1_1SWIG_11(JNIEnv *jenv, jclass jcls, jint jarg1, jint jarg2, jstring jarg3) {
  jlong jresult = 0 ;
  pjsua_call_id arg1 ;
  pj_bool_t arg2 ;
  char *arg3 = (char *) 0 ;
  pj_str_t result;
  
  (void)jenv;
  (void)jcls;
  arg1 = (pjsua_call_id)jarg1; 
  arg2 = (pj_bool_t)jarg2; 
  arg3 = 0;
  if (jarg3) {
    arg3 = (char *)jenv->GetStringUTFChars(jarg3, 0);
    if (!arg3) return 0;
  }
  result = call_dump(arg1,arg2,(char const *)arg3);
  *(pj_str_t **)&jresult = new pj_str_t((const pj_str_t &)result); 
  if (arg3) jenv->ReleaseStringUTFChars(jarg3, (const char *)arg3);
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_can_1use_1tls(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pj_bool_t result;
  
  (void)jenv;
  (void)jcls;
  result = (pj_bool_t)can_use_tls();
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_can_1use_1srtp(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pj_bool_t result;
  
  (void)jenv;
  (void)jcls;
  result = (pj_bool_t)can_use_srtp();
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_media_1transports_1create_1ipv6(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  pjsua_transport_config arg1 ;
  pjsua_transport_config *argp1 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  argp1 = *(pjsua_transport_config **)&jarg1; 
  if (!argp1) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null pjsua_transport_config");
    return 0;
  }
  arg1 = *argp1; 
  result = (pj_status_t)media_transports_create_ipv6(arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_csipsimple_1init(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_, jlong jarg3, jobject jarg3_) {
  jint jresult = 0 ;
  pjsua_config *arg1 = (pjsua_config *) 0 ;
  pjsua_logging_config *arg2 = (pjsua_logging_config *) 0 ;
  pjsua_media_config *arg3 = (pjsua_media_config *) 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  (void)jarg3_;
  arg1 = *(pjsua_config **)&jarg1; 
  arg2 = *(pjsua_logging_config **)&jarg2; 
  arg3 = *(pjsua_media_config **)&jarg3; 
  result = (pj_status_t)csipsimple_init(arg1,arg2,arg3);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_org_pjsip_pjsua_pjsuaJNI_csipsimple_1destroy(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  pj_status_t result;
  
  (void)jenv;
  (void)jcls;
  result = (pj_status_t)csipsimple_destroy();
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_pjsip_pjsua_pjsuaJNI_swig_1module_1init(JNIEnv *jenv, jclass jcls) {
  int i;
  
  static struct {
    const char *method;
    const char *signature;
  } methods[19] = {
    {
      "SwigDirector_Callback_on_call_state", "(Lorg/pjsip/pjsua/Callback;IJ)V" 
    },
    {
      "SwigDirector_Callback_on_incoming_call", "(Lorg/pjsip/pjsua/Callback;IIJ)V" 
    },
    {
      "SwigDirector_Callback_on_call_tsx_state", "(Lorg/pjsip/pjsua/Callback;IJJ)V" 
    },
    {
      "SwigDirector_Callback_on_call_media_state", "(Lorg/pjsip/pjsua/Callback;I)V" 
    },
    {
      "SwigDirector_Callback_on_stream_created", "(Lorg/pjsip/pjsua/Callback;IJJJ)V" 
    },
    {
      "SwigDirector_Callback_on_stream_destroyed", "(Lorg/pjsip/pjsua/Callback;IJJ)V" 
    },
    {
      "SwigDirector_Callback_on_dtmf_digit", "(Lorg/pjsip/pjsua/Callback;II)V" 
    },
    {
      "SwigDirector_Callback_on_call_transfer_request", "(Lorg/pjsip/pjsua/Callback;IJJ)V" 
    },
    {
      "SwigDirector_Callback_on_call_transfer_status", "(Lorg/pjsip/pjsua/Callback;IIJIJ)V" 
    },
    {
      "SwigDirector_Callback_on_call_replace_request", "(Lorg/pjsip/pjsua/Callback;IJJJ)V" 
    },
    {
      "SwigDirector_Callback_on_call_replaced", "(Lorg/pjsip/pjsua/Callback;II)V" 
    },
    {
      "SwigDirector_Callback_on_reg_state", "(Lorg/pjsip/pjsua/Callback;I)V" 
    },
    {
      "SwigDirector_Callback_on_buddy_state", "(Lorg/pjsip/pjsua/Callback;I)V" 
    },
    {
      "SwigDirector_Callback_on_pager", "(Lorg/pjsip/pjsua/Callback;IJJJJJ)V" 
    },
    {
      "SwigDirector_Callback_on_pager2", "(Lorg/pjsip/pjsua/Callback;IJJJJJJ)V" 
    },
    {
      "SwigDirector_Callback_on_pager_status", "(Lorg/pjsip/pjsua/Callback;IJJIJ)V" 
    },
    {
      "SwigDirector_Callback_on_pager_status2", "(Lorg/pjsip/pjsua/Callback;IJJIJJJ)V" 
    },
    {
      "SwigDirector_Callback_on_typing", "(Lorg/pjsip/pjsua/Callback;IJJJI)V" 
    },
    {
      "SwigDirector_Callback_on_nat_detect", "(Lorg/pjsip/pjsua/Callback;J)V" 
    }
  };
  Swig::jclass_pjsuaJNI = (jclass) jenv->NewGlobalRef(jcls);
  if (!Swig::jclass_pjsuaJNI) return;
  for (i = 0; i < (int) (sizeof(methods)/sizeof(methods[0])); ++i) {
    Swig::director_methids[i] = jenv->GetStaticMethodID(jcls, methods[i].method, methods[i].signature);
    if (!Swig::director_methids[i]) return;
  }
}


#ifdef __cplusplus
}
#endif


JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved) {
	JNIEnv *env;
	jclass k;
	jint r;
	//Assume it is c++
	r = vm->GetEnv ((void **) &env, JNI_VERSION_1_4);
	k = env->FindClass ("org/pjsip/pjsua/pjsuaJNI");

#if USE_JNI_AUDIO==1
	android_jvm = vm;
#endif

	JNINativeMethod methods[] = {

	{"pj_str_copy", "(Ljava/lang/String;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pj_1str_1copy},
{"delete_Callback", "(J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_delete_1Callback},
{"Callback_on_call_state", "(JLorg/pjsip/pjsua/Callback;IJLorg/pjsip/pjsua/pjsip_event;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1call_1state},
{"Callback_on_call_stateSwigExplicitCallback", "(JLorg/pjsip/pjsua/Callback;IJLorg/pjsip/pjsua/pjsip_event;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1call_1stateSwigExplicitCallback},
{"Callback_on_incoming_call", "(JLorg/pjsip/pjsua/Callback;IIJ)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1incoming_1call},
{"Callback_on_incoming_callSwigExplicitCallback", "(JLorg/pjsip/pjsua/Callback;IIJ)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1incoming_1callSwigExplicitCallback},
{"Callback_on_call_tsx_state", "(JLorg/pjsip/pjsua/Callback;IJJLorg/pjsip/pjsua/pjsip_event;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1call_1tsx_1state},
{"Callback_on_call_tsx_stateSwigExplicitCallback", "(JLorg/pjsip/pjsua/Callback;IJJLorg/pjsip/pjsua/pjsip_event;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1call_1tsx_1stateSwigExplicitCallback},
{"Callback_on_call_media_state", "(JLorg/pjsip/pjsua/Callback;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1call_1media_1state},
{"Callback_on_call_media_stateSwigExplicitCallback", "(JLorg/pjsip/pjsua/Callback;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1call_1media_1stateSwigExplicitCallback},
{"Callback_on_stream_created", "(JLorg/pjsip/pjsua/Callback;IJJJ)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1stream_1created},
{"Callback_on_stream_createdSwigExplicitCallback", "(JLorg/pjsip/pjsua/Callback;IJJJ)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1stream_1createdSwigExplicitCallback},
{"Callback_on_stream_destroyed", "(JLorg/pjsip/pjsua/Callback;IJJ)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1stream_1destroyed},
{"Callback_on_stream_destroyedSwigExplicitCallback", "(JLorg/pjsip/pjsua/Callback;IJJ)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1stream_1destroyedSwigExplicitCallback},
{"Callback_on_dtmf_digit", "(JLorg/pjsip/pjsua/Callback;II)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1dtmf_1digit},
{"Callback_on_dtmf_digitSwigExplicitCallback", "(JLorg/pjsip/pjsua/Callback;II)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1dtmf_1digitSwigExplicitCallback},
{"Callback_on_call_transfer_request", "(JLorg/pjsip/pjsua/Callback;IJLorg/pjsip/pjsua/pj_str_t;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1call_1transfer_1request},
{"Callback_on_call_transfer_requestSwigExplicitCallback", "(JLorg/pjsip/pjsua/Callback;IJLorg/pjsip/pjsua/pj_str_t;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1call_1transfer_1requestSwigExplicitCallback},
{"Callback_on_call_transfer_status", "(JLorg/pjsip/pjsua/Callback;IIJLorg/pjsip/pjsua/pj_str_t;IJ)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1call_1transfer_1status},
{"Callback_on_call_transfer_statusSwigExplicitCallback", "(JLorg/pjsip/pjsua/Callback;IIJLorg/pjsip/pjsua/pj_str_t;IJ)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1call_1transfer_1statusSwigExplicitCallback},
{"Callback_on_call_replace_request", "(JLorg/pjsip/pjsua/Callback;IJJJLorg/pjsip/pjsua/pj_str_t;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1call_1replace_1request},
{"Callback_on_call_replace_requestSwigExplicitCallback", "(JLorg/pjsip/pjsua/Callback;IJJJLorg/pjsip/pjsua/pj_str_t;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1call_1replace_1requestSwigExplicitCallback},
{"Callback_on_call_replaced", "(JLorg/pjsip/pjsua/Callback;II)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1call_1replaced},
{"Callback_on_call_replacedSwigExplicitCallback", "(JLorg/pjsip/pjsua/Callback;II)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1call_1replacedSwigExplicitCallback},
{"Callback_on_reg_state", "(JLorg/pjsip/pjsua/Callback;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1reg_1state},
{"Callback_on_reg_stateSwigExplicitCallback", "(JLorg/pjsip/pjsua/Callback;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1reg_1stateSwigExplicitCallback},
{"Callback_on_buddy_state", "(JLorg/pjsip/pjsua/Callback;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1buddy_1state},
{"Callback_on_buddy_stateSwigExplicitCallback", "(JLorg/pjsip/pjsua/Callback;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1buddy_1stateSwigExplicitCallback},
{"Callback_on_pager", "(JLorg/pjsip/pjsua/Callback;IJLorg/pjsip/pjsua/pj_str_t;JLorg/pjsip/pjsua/pj_str_t;JLorg/pjsip/pjsua/pj_str_t;JLorg/pjsip/pjsua/pj_str_t;JLorg/pjsip/pjsua/pj_str_t;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1pager},
{"Callback_on_pagerSwigExplicitCallback", "(JLorg/pjsip/pjsua/Callback;IJLorg/pjsip/pjsua/pj_str_t;JLorg/pjsip/pjsua/pj_str_t;JLorg/pjsip/pjsua/pj_str_t;JLorg/pjsip/pjsua/pj_str_t;JLorg/pjsip/pjsua/pj_str_t;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1pagerSwigExplicitCallback},
{"Callback_on_pager2", "(JLorg/pjsip/pjsua/Callback;IJLorg/pjsip/pjsua/pj_str_t;JLorg/pjsip/pjsua/pj_str_t;JLorg/pjsip/pjsua/pj_str_t;JLorg/pjsip/pjsua/pj_str_t;JLorg/pjsip/pjsua/pj_str_t;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1pager2},
{"Callback_on_pager2SwigExplicitCallback", "(JLorg/pjsip/pjsua/Callback;IJLorg/pjsip/pjsua/pj_str_t;JLorg/pjsip/pjsua/pj_str_t;JLorg/pjsip/pjsua/pj_str_t;JLorg/pjsip/pjsua/pj_str_t;JLorg/pjsip/pjsua/pj_str_t;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1pager2SwigExplicitCallback},
{"Callback_on_pager_status", "(JLorg/pjsip/pjsua/Callback;IJLorg/pjsip/pjsua/pj_str_t;JLorg/pjsip/pjsua/pj_str_t;IJLorg/pjsip/pjsua/pj_str_t;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1pager_1status},
{"Callback_on_pager_statusSwigExplicitCallback", "(JLorg/pjsip/pjsua/Callback;IJLorg/pjsip/pjsua/pj_str_t;JLorg/pjsip/pjsua/pj_str_t;IJLorg/pjsip/pjsua/pj_str_t;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1pager_1statusSwigExplicitCallback},
{"Callback_on_pager_status2", "(JLorg/pjsip/pjsua/Callback;IJLorg/pjsip/pjsua/pj_str_t;JLorg/pjsip/pjsua/pj_str_t;IJLorg/pjsip/pjsua/pj_str_t;JJ)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1pager_1status2},
{"Callback_on_pager_status2SwigExplicitCallback", "(JLorg/pjsip/pjsua/Callback;IJLorg/pjsip/pjsua/pj_str_t;JLorg/pjsip/pjsua/pj_str_t;IJLorg/pjsip/pjsua/pj_str_t;JJ)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1pager_1status2SwigExplicitCallback},
{"Callback_on_typing", "(JLorg/pjsip/pjsua/Callback;IJLorg/pjsip/pjsua/pj_str_t;JLorg/pjsip/pjsua/pj_str_t;JLorg/pjsip/pjsua/pj_str_t;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1typing},
{"Callback_on_typingSwigExplicitCallback", "(JLorg/pjsip/pjsua/Callback;IJLorg/pjsip/pjsua/pj_str_t;JLorg/pjsip/pjsua/pj_str_t;JLorg/pjsip/pjsua/pj_str_t;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1typingSwigExplicitCallback},
{"Callback_on_nat_detect", "(JLorg/pjsip/pjsua/Callback;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1nat_1detect},
{"Callback_on_nat_detectSwigExplicitCallback", "(JLorg/pjsip/pjsua/Callback;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_Callback_1on_1nat_1detectSwigExplicitCallback},
{"new_Callback", "()J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_new_1Callback},
{"Callback_director_connect", "(Lorg/pjsip/pjsua/Callback;JZZ)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_Callback_1director_1connect},
{"Callback_change_ownership", "(Lorg/pjsip/pjsua/Callback;JZ)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_Callback_1change_1ownership},
{"WRAPPER_CALLBACK_STRUCT_get", "()J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_WRAPPER_1CALLBACK_1STRUCT_1get},
{"setCallbackObject", "(JLorg/pjsip/pjsua/Callback;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_setCallbackObject},
{"PJ_SUCCESS_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJ_1SUCCESS_1get},
{"PJ_TRUE_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJ_1TRUE_1get},
{"PJ_FALSE_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJ_1FALSE_1get},
{"pj_str_t_ptr_set", "(JLorg/pjsip/pjsua/pj_str_t;Ljava/lang/String;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pj_1str_1t_1ptr_1set},
{"pj_str_t_ptr_get", "(JLorg/pjsip/pjsua/pj_str_t;)Ljava/lang/String;", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pj_1str_1t_1ptr_1get},
{"pj_str_t_slen_set", "(JLorg/pjsip/pjsua/pj_str_t;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pj_1str_1t_1slen_1set},
{"pj_str_t_slen_get", "(JLorg/pjsip/pjsua/pj_str_t;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pj_1str_1t_1slen_1get},
{"new_pj_str_t", "()J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_new_1pj_1str_1t},
{"delete_pj_str_t", "(J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_delete_1pj_1str_1t},
{"pjmedia_port_info_set", "(JLorg/pjsip/pjsua/pjmedia_port;JLorg/pjsip/pjsua/pjmedia_port_info;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1info_1set},
{"pjmedia_port_info_get", "(JLorg/pjsip/pjsua/pjmedia_port;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1info_1get},
{"pjmedia_port_put_frame_set", "(JLorg/pjsip/pjsua/pjmedia_port;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1put_1frame_1set},
{"pjmedia_port_put_frame_get", "(JLorg/pjsip/pjsua/pjmedia_port;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1put_1frame_1get},
{"pjmedia_port_get_frame_set", "(JLorg/pjsip/pjsua/pjmedia_port;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1get_1frame_1set},
{"pjmedia_port_get_frame_get", "(JLorg/pjsip/pjsua/pjmedia_port;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1get_1frame_1get},
{"pjmedia_port_on_destroy_set", "(JLorg/pjsip/pjsua/pjmedia_port;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1on_1destroy_1set},
{"pjmedia_port_on_destroy_get", "(JLorg/pjsip/pjsua/pjmedia_port;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1on_1destroy_1get},
{"PJMEDIA_DIR_NONE_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJMEDIA_1DIR_1NONE_1get},
{"PJMEDIA_DIR_ENCODING_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJMEDIA_1DIR_1ENCODING_1get},
{"PJMEDIA_DIR_DECODING_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJMEDIA_1DIR_1DECODING_1get},
{"PJMEDIA_DIR_ENCODING_DECODING_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJMEDIA_1DIR_1ENCODING_1DECODING_1get},
{"pjmedia_port_info_name_set", "(JLorg/pjsip/pjsua/pjmedia_port_info;JLorg/pjsip/pjsua/pj_str_t;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1info_1name_1set},
{"pjmedia_port_info_name_get", "(JLorg/pjsip/pjsua/pjmedia_port_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1info_1name_1get},
{"pjmedia_port_info_signature_set", "(JLorg/pjsip/pjsua/pjmedia_port_info;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1info_1signature_1set},
{"pjmedia_port_info_signature_get", "(JLorg/pjsip/pjsua/pjmedia_port_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1info_1signature_1get},
{"pjmedia_port_info_type_set", "(JLorg/pjsip/pjsua/pjmedia_port_info;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1info_1type_1set},
{"pjmedia_port_info_type_get", "(JLorg/pjsip/pjsua/pjmedia_port_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1info_1type_1get},
{"pjmedia_port_info_has_info_set", "(JLorg/pjsip/pjsua/pjmedia_port_info;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1info_1has_1info_1set},
{"pjmedia_port_info_has_info_get", "(JLorg/pjsip/pjsua/pjmedia_port_info;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1info_1has_1info_1get},
{"pjmedia_port_info_need_info_set", "(JLorg/pjsip/pjsua/pjmedia_port_info;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1info_1need_1info_1set},
{"pjmedia_port_info_need_info_get", "(JLorg/pjsip/pjsua/pjmedia_port_info;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1info_1need_1info_1get},
{"pjmedia_port_info_pt_set", "(JLorg/pjsip/pjsua/pjmedia_port_info;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1info_1pt_1set},
{"pjmedia_port_info_pt_get", "(JLorg/pjsip/pjsua/pjmedia_port_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1info_1pt_1get},
{"pjmedia_port_info_encoding_name_set", "(JLorg/pjsip/pjsua/pjmedia_port_info;JLorg/pjsip/pjsua/pj_str_t;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1info_1encoding_1name_1set},
{"pjmedia_port_info_encoding_name_get", "(JLorg/pjsip/pjsua/pjmedia_port_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1info_1encoding_1name_1get},
{"pjmedia_port_info_clock_rate_set", "(JLorg/pjsip/pjsua/pjmedia_port_info;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1info_1clock_1rate_1set},
{"pjmedia_port_info_clock_rate_get", "(JLorg/pjsip/pjsua/pjmedia_port_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1info_1clock_1rate_1get},
{"pjmedia_port_info_channel_count_set", "(JLorg/pjsip/pjsua/pjmedia_port_info;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1info_1channel_1count_1set},
{"pjmedia_port_info_channel_count_get", "(JLorg/pjsip/pjsua/pjmedia_port_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1info_1channel_1count_1get},
{"pjmedia_port_info_bits_per_sample_set", "(JLorg/pjsip/pjsua/pjmedia_port_info;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1info_1bits_1per_1sample_1set},
{"pjmedia_port_info_bits_per_sample_get", "(JLorg/pjsip/pjsua/pjmedia_port_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1info_1bits_1per_1sample_1get},
{"pjmedia_port_info_samples_per_frame_set", "(JLorg/pjsip/pjsua/pjmedia_port_info;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1info_1samples_1per_1frame_1set},
{"pjmedia_port_info_samples_per_frame_get", "(JLorg/pjsip/pjsua/pjmedia_port_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1info_1samples_1per_1frame_1get},
{"pjmedia_port_info_bytes_per_frame_set", "(JLorg/pjsip/pjsua/pjmedia_port_info;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1info_1bytes_1per_1frame_1set},
{"pjmedia_port_info_bytes_per_frame_get", "(JLorg/pjsip/pjsua/pjmedia_port_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1port_1info_1bytes_1per_1frame_1get},
{"new_pjmedia_port_info", "()J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_new_1pjmedia_1port_1info},
{"delete_pjmedia_port_info", "(J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_delete_1pjmedia_1port_1info},
{"pjsip_cred_info_realm_set", "(JLorg/pjsip/pjsua/pjsip_cred_info;JLorg/pjsip/pjsua/pj_str_t;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1cred_1info_1realm_1set},
{"pjsip_cred_info_realm_get", "(JLorg/pjsip/pjsua/pjsip_cred_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1cred_1info_1realm_1get},
{"pjsip_cred_info_scheme_set", "(JLorg/pjsip/pjsua/pjsip_cred_info;JLorg/pjsip/pjsua/pj_str_t;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1cred_1info_1scheme_1set},
{"pjsip_cred_info_scheme_get", "(JLorg/pjsip/pjsua/pjsip_cred_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1cred_1info_1scheme_1get},
{"pjsip_cred_info_username_set", "(JLorg/pjsip/pjsua/pjsip_cred_info;JLorg/pjsip/pjsua/pj_str_t;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1cred_1info_1username_1set},
{"pjsip_cred_info_username_get", "(JLorg/pjsip/pjsua/pjsip_cred_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1cred_1info_1username_1get},
{"pjsip_cred_info_data_type_set", "(JLorg/pjsip/pjsua/pjsip_cred_info;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1cred_1info_1data_1type_1set},
{"pjsip_cred_info_data_type_get", "(JLorg/pjsip/pjsua/pjsip_cred_info;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1cred_1info_1data_1type_1get},
{"pjsip_cred_info_data_set", "(JLorg/pjsip/pjsua/pjsip_cred_info;JLorg/pjsip/pjsua/pj_str_t;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1cred_1info_1data_1set},
{"pjsip_cred_info_data_get", "(JLorg/pjsip/pjsua/pjsip_cred_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1cred_1info_1data_1get},
{"new_pjsip_cred_info", "()J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_new_1pjsip_1cred_1info},
{"delete_pjsip_cred_info", "(J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_delete_1pjsip_1cred_1info},
{"PJSIP_CRED_DATA_PLAIN_PASSWD_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1CRED_1DATA_1PLAIN_1PASSWD_1get},
{"PJSIP_CRED_DATA_DIGEST_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1CRED_1DATA_1DIGEST_1get},
{"PJSIP_CRED_DATA_EXT_AKA_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1CRED_1DATA_1EXT_1AKA_1get},
{"PJMEDIA_TONEGEN_LOOP_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJMEDIA_1TONEGEN_1LOOP_1get},
{"PJMEDIA_TONEGEN_NO_LOCK_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJMEDIA_1TONEGEN_1NO_1LOCK_1get},
{"pjsip_event_type_set", "(JLorg/pjsip/pjsua/pjsip_event;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1event_1type_1set},
{"pjsip_event_type_get", "(JLorg/pjsip/pjsua/pjsip_event;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1event_1type_1get},
{"new_pjsip_event", "()J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_new_1pjsip_1event},
{"delete_pjsip_event", "(J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_delete_1pjsip_1event},
{"pjmedia_snd_dev_info_name_set", "(JLorg/pjsip/pjsua/pjmedia_snd_dev_info;Ljava/lang/String;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1snd_1dev_1info_1name_1set},
{"pjmedia_snd_dev_info_name_get", "(JLorg/pjsip/pjsua/pjmedia_snd_dev_info;)Ljava/lang/String;", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1snd_1dev_1info_1name_1get},
{"pjmedia_snd_dev_info_input_count_set", "(JLorg/pjsip/pjsua/pjmedia_snd_dev_info;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1snd_1dev_1info_1input_1count_1set},
{"pjmedia_snd_dev_info_input_count_get", "(JLorg/pjsip/pjsua/pjmedia_snd_dev_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1snd_1dev_1info_1input_1count_1get},
{"pjmedia_snd_dev_info_output_count_set", "(JLorg/pjsip/pjsua/pjmedia_snd_dev_info;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1snd_1dev_1info_1output_1count_1set},
{"pjmedia_snd_dev_info_output_count_get", "(JLorg/pjsip/pjsua/pjmedia_snd_dev_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1snd_1dev_1info_1output_1count_1get},
{"pjmedia_snd_dev_info_default_samples_per_sec_set", "(JLorg/pjsip/pjsua/pjmedia_snd_dev_info;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1snd_1dev_1info_1default_1samples_1per_1sec_1set},
{"pjmedia_snd_dev_info_default_samples_per_sec_get", "(JLorg/pjsip/pjsua/pjmedia_snd_dev_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1snd_1dev_1info_1default_1samples_1per_1sec_1get},
{"new_pjmedia_snd_dev_info", "()J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_new_1pjmedia_1snd_1dev_1info},
{"delete_pjmedia_snd_dev_info", "(J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_delete_1pjmedia_1snd_1dev_1info},
{"pjmedia_tone_desc_freq1_set", "(JLorg/pjsip/pjsua/pjmedia_tone_desc;S)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1tone_1desc_1freq1_1set},
{"pjmedia_tone_desc_freq1_get", "(JLorg/pjsip/pjsua/pjmedia_tone_desc;)S", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1tone_1desc_1freq1_1get},
{"pjmedia_tone_desc_freq2_set", "(JLorg/pjsip/pjsua/pjmedia_tone_desc;S)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1tone_1desc_1freq2_1set},
{"pjmedia_tone_desc_freq2_get", "(JLorg/pjsip/pjsua/pjmedia_tone_desc;)S", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1tone_1desc_1freq2_1get},
{"pjmedia_tone_desc_on_msec_set", "(JLorg/pjsip/pjsua/pjmedia_tone_desc;S)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1tone_1desc_1on_1msec_1set},
{"pjmedia_tone_desc_on_msec_get", "(JLorg/pjsip/pjsua/pjmedia_tone_desc;)S", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1tone_1desc_1on_1msec_1get},
{"pjmedia_tone_desc_off_msec_set", "(JLorg/pjsip/pjsua/pjmedia_tone_desc;S)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1tone_1desc_1off_1msec_1set},
{"pjmedia_tone_desc_off_msec_get", "(JLorg/pjsip/pjsua/pjmedia_tone_desc;)S", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1tone_1desc_1off_1msec_1get},
{"pjmedia_tone_desc_volume_set", "(JLorg/pjsip/pjsua/pjmedia_tone_desc;S)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1tone_1desc_1volume_1set},
{"pjmedia_tone_desc_volume_get", "(JLorg/pjsip/pjsua/pjmedia_tone_desc;)S", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1tone_1desc_1volume_1get},
{"new_pjmedia_tone_desc", "()J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_new_1pjmedia_1tone_1desc},
{"delete_pjmedia_tone_desc", "(J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_delete_1pjmedia_1tone_1desc},
{"pj_pool_t_obj_name_set", "(JLorg/pjsip/pjsua/pj_pool_t;Ljava/lang/String;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pj_1pool_1t_1obj_1name_1set},
{"pj_pool_t_obj_name_get", "(JLorg/pjsip/pjsua/pj_pool_t;)Ljava/lang/String;", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pj_1pool_1t_1obj_1name_1get},
{"pj_pool_t_factory_set", "(JLorg/pjsip/pjsua/pj_pool_t;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pj_1pool_1t_1factory_1set},
{"pj_pool_t_factory_get", "(JLorg/pjsip/pjsua/pj_pool_t;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pj_1pool_1t_1factory_1get},
{"pj_pool_t_factory_data_set", "(JLorg/pjsip/pjsua/pj_pool_t;[B)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pj_1pool_1t_1factory_1data_1set},
{"pj_pool_t_capacity_set", "(JLorg/pjsip/pjsua/pj_pool_t;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pj_1pool_1t_1capacity_1set},
{"pj_pool_t_capacity_get", "(JLorg/pjsip/pjsua/pj_pool_t;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pj_1pool_1t_1capacity_1get},
{"pj_pool_t_increment_size_set", "(JLorg/pjsip/pjsua/pj_pool_t;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pj_1pool_1t_1increment_1size_1set},
{"pj_pool_t_increment_size_get", "(JLorg/pjsip/pjsua/pj_pool_t;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pj_1pool_1t_1increment_1size_1get},
{"pj_pool_t_block_list_set", "(JLorg/pjsip/pjsua/pj_pool_t;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pj_1pool_1t_1block_1list_1set},
{"pj_pool_t_block_list_get", "(JLorg/pjsip/pjsua/pj_pool_t;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pj_1pool_1t_1block_1list_1get},
{"pj_pool_t_callback_set", "(JLorg/pjsip/pjsua/pj_pool_t;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pj_1pool_1t_1callback_1set},
{"pj_pool_t_callback_get", "(JLorg/pjsip/pjsua/pj_pool_t;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pj_1pool_1t_1callback_1get},
{"new_pj_pool_t", "()J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_new_1pj_1pool_1t},
{"delete_pj_pool_t", "(J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_delete_1pj_1pool_1t},
{"PJSIP_TRANSPORT_IPV6_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1TRANSPORT_1IPV6_1get},
{"PJSIP_TRANSPORT_UDP6_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1TRANSPORT_1UDP6_1get},
{"PJSIP_TRANSPORT_TCP6_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1TRANSPORT_1TCP6_1get},
{"PJSIP_SC_TRYING_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1TRYING_1get},
{"PJSIP_SC_RINGING_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1RINGING_1get},
{"PJSIP_SC_CALL_BEING_FORWARDED_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1CALL_1BEING_1FORWARDED_1get},
{"PJSIP_SC_QUEUED_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1QUEUED_1get},
{"PJSIP_SC_PROGRESS_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1PROGRESS_1get},
{"PJSIP_SC_OK_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1OK_1get},
{"PJSIP_SC_ACCEPTED_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1ACCEPTED_1get},
{"PJSIP_SC_MULTIPLE_CHOICES_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1MULTIPLE_1CHOICES_1get},
{"PJSIP_SC_MOVED_PERMANENTLY_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1MOVED_1PERMANENTLY_1get},
{"PJSIP_SC_MOVED_TEMPORARILY_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1MOVED_1TEMPORARILY_1get},
{"PJSIP_SC_USE_PROXY_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1USE_1PROXY_1get},
{"PJSIP_SC_ALTERNATIVE_SERVICE_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1ALTERNATIVE_1SERVICE_1get},
{"PJSIP_SC_BAD_REQUEST_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1BAD_1REQUEST_1get},
{"PJSIP_SC_UNAUTHORIZED_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1UNAUTHORIZED_1get},
{"PJSIP_SC_PAYMENT_REQUIRED_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1PAYMENT_1REQUIRED_1get},
{"PJSIP_SC_FORBIDDEN_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1FORBIDDEN_1get},
{"PJSIP_SC_NOT_FOUND_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1NOT_1FOUND_1get},
{"PJSIP_SC_METHOD_NOT_ALLOWED_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1METHOD_1NOT_1ALLOWED_1get},
{"PJSIP_SC_NOT_ACCEPTABLE_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1NOT_1ACCEPTABLE_1get},
{"PJSIP_SC_PROXY_AUTHENTICATION_REQUIRED_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1PROXY_1AUTHENTICATION_1REQUIRED_1get},
{"PJSIP_SC_REQUEST_TIMEOUT_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1REQUEST_1TIMEOUT_1get},
{"PJSIP_SC_GONE_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1GONE_1get},
{"PJSIP_SC_REQUEST_ENTITY_TOO_LARGE_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1REQUEST_1ENTITY_1TOO_1LARGE_1get},
{"PJSIP_SC_REQUEST_URI_TOO_LONG_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1REQUEST_1URI_1TOO_1LONG_1get},
{"PJSIP_SC_UNSUPPORTED_MEDIA_TYPE_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1UNSUPPORTED_1MEDIA_1TYPE_1get},
{"PJSIP_SC_UNSUPPORTED_URI_SCHEME_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1UNSUPPORTED_1URI_1SCHEME_1get},
{"PJSIP_SC_BAD_EXTENSION_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1BAD_1EXTENSION_1get},
{"PJSIP_SC_EXTENSION_REQUIRED_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1EXTENSION_1REQUIRED_1get},
{"PJSIP_SC_SESSION_TIMER_TOO_SMALL_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1SESSION_1TIMER_1TOO_1SMALL_1get},
{"PJSIP_SC_INTERVAL_TOO_BRIEF_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1INTERVAL_1TOO_1BRIEF_1get},
{"PJSIP_SC_TEMPORARILY_UNAVAILABLE_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1TEMPORARILY_1UNAVAILABLE_1get},
{"PJSIP_SC_CALL_TSX_DOES_NOT_EXIST_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1CALL_1TSX_1DOES_1NOT_1EXIST_1get},
{"PJSIP_SC_LOOP_DETECTED_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1LOOP_1DETECTED_1get},
{"PJSIP_SC_TOO_MANY_HOPS_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1TOO_1MANY_1HOPS_1get},
{"PJSIP_SC_ADDRESS_INCOMPLETE_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1ADDRESS_1INCOMPLETE_1get},
{"PJSIP_AC_AMBIGUOUS_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1AC_1AMBIGUOUS_1get},
{"PJSIP_SC_BUSY_HERE_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1BUSY_1HERE_1get},
{"PJSIP_SC_REQUEST_TERMINATED_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1REQUEST_1TERMINATED_1get},
{"PJSIP_SC_NOT_ACCEPTABLE_HERE_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1NOT_1ACCEPTABLE_1HERE_1get},
{"PJSIP_SC_BAD_EVENT_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1BAD_1EVENT_1get},
{"PJSIP_SC_REQUEST_UPDATED_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1REQUEST_1UPDATED_1get},
{"PJSIP_SC_REQUEST_PENDING_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1REQUEST_1PENDING_1get},
{"PJSIP_SC_UNDECIPHERABLE_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1UNDECIPHERABLE_1get},
{"PJSIP_SC_INTERNAL_SERVER_ERROR_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1INTERNAL_1SERVER_1ERROR_1get},
{"PJSIP_SC_NOT_IMPLEMENTED_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1NOT_1IMPLEMENTED_1get},
{"PJSIP_SC_BAD_GATEWAY_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1BAD_1GATEWAY_1get},
{"PJSIP_SC_SERVICE_UNAVAILABLE_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1SERVICE_1UNAVAILABLE_1get},
{"PJSIP_SC_SERVER_TIMEOUT_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1SERVER_1TIMEOUT_1get},
{"PJSIP_SC_VERSION_NOT_SUPPORTED_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1VERSION_1NOT_1SUPPORTED_1get},
{"PJSIP_SC_MESSAGE_TOO_LARGE_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1MESSAGE_1TOO_1LARGE_1get},
{"PJSIP_SC_PRECONDITION_FAILURE_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1PRECONDITION_1FAILURE_1get},
{"PJSIP_SC_BUSY_EVERYWHERE_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1BUSY_1EVERYWHERE_1get},
{"PJSIP_SC_DECLINE_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1DECLINE_1get},
{"PJSIP_SC_DOES_NOT_EXIST_ANYWHERE_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1DOES_1NOT_1EXIST_1ANYWHERE_1get},
{"PJSIP_SC_NOT_ACCEPTABLE_ANYWHERE_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1NOT_1ACCEPTABLE_1ANYWHERE_1get},
{"PJSIP_SC_TSX_TIMEOUT_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1TSX_1TIMEOUT_1get},
{"PJSIP_SC_TSX_TRANSPORT_ERROR_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SC_1TSX_1TRANSPORT_1ERROR_1get},
{"pjsua_pool_create", "(Ljava/lang/String;JJ)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1pool_1create},
{"pj_pool_release", "(JLorg/pjsip/pjsua/pj_pool_t;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pj_1pool_1release},
{"pjmedia_tonegen_create2", "(JLorg/pjsip/pjsua/pj_pool_t;JLorg/pjsip/pjsua/pj_str_t;JJJJJLorg/pjsip/pjsua/pjmedia_port;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1tonegen_1create2},
{"pjmedia_tonegen_play", "(JLorg/pjsip/pjsua/pjmedia_port;J[JJ)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1tonegen_1play},
{"pjmedia_tonegen_rewind", "(JLorg/pjsip/pjsua/pjmedia_port;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjmedia_1tonegen_1rewind},
{"PJSIP_SSL_UNSPECIFIED_METHOD_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SSL_1UNSPECIFIED_1METHOD_1get},
{"PJSIP_TLSV1_METHOD_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1TLSV1_1METHOD_1get},
{"PJSIP_SSLV2_METHOD_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SSLV2_1METHOD_1get},
{"PJSIP_SSLV3_METHOD_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SSLV3_1METHOD_1get},
{"PJSIP_SSLV23_METHOD_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSIP_1SSLV23_1METHOD_1get},
{"pjsip_tls_setting_ca_list_file_set", "(JLorg/pjsip/pjsua/pjsip_tls_setting;JLorg/pjsip/pjsua/pj_str_t;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1ca_1list_1file_1set},
{"pjsip_tls_setting_ca_list_file_get", "(JLorg/pjsip/pjsua/pjsip_tls_setting;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1ca_1list_1file_1get},
{"pjsip_tls_setting_cert_file_set", "(JLorg/pjsip/pjsua/pjsip_tls_setting;JLorg/pjsip/pjsua/pj_str_t;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1cert_1file_1set},
{"pjsip_tls_setting_cert_file_get", "(JLorg/pjsip/pjsua/pjsip_tls_setting;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1cert_1file_1get},
{"pjsip_tls_setting_privkey_file_set", "(JLorg/pjsip/pjsua/pjsip_tls_setting;JLorg/pjsip/pjsua/pj_str_t;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1privkey_1file_1set},
{"pjsip_tls_setting_privkey_file_get", "(JLorg/pjsip/pjsua/pjsip_tls_setting;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1privkey_1file_1get},
{"pjsip_tls_setting_password_set", "(JLorg/pjsip/pjsua/pjsip_tls_setting;JLorg/pjsip/pjsua/pj_str_t;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1password_1set},
{"pjsip_tls_setting_password_get", "(JLorg/pjsip/pjsua/pjsip_tls_setting;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1password_1get},
{"pjsip_tls_setting_method_set", "(JLorg/pjsip/pjsua/pjsip_tls_setting;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1method_1set},
{"pjsip_tls_setting_method_get", "(JLorg/pjsip/pjsua/pjsip_tls_setting;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1method_1get},
{"pjsip_tls_setting_ciphers_set", "(JLorg/pjsip/pjsua/pjsip_tls_setting;JLorg/pjsip/pjsua/pj_str_t;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1ciphers_1set},
{"pjsip_tls_setting_ciphers_get", "(JLorg/pjsip/pjsua/pjsip_tls_setting;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1ciphers_1get},
{"pjsip_tls_setting_server_name_set", "(JLorg/pjsip/pjsua/pjsip_tls_setting;JLorg/pjsip/pjsua/pj_str_t;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1server_1name_1set},
{"pjsip_tls_setting_server_name_get", "(JLorg/pjsip/pjsua/pjsip_tls_setting;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1server_1name_1get},
{"pjsip_tls_setting_verify_server_set", "(JLorg/pjsip/pjsua/pjsip_tls_setting;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1verify_1server_1set},
{"pjsip_tls_setting_verify_server_get", "(JLorg/pjsip/pjsua/pjsip_tls_setting;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1verify_1server_1get},
{"pjsip_tls_setting_verify_client_set", "(JLorg/pjsip/pjsua/pjsip_tls_setting;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1verify_1client_1set},
{"pjsip_tls_setting_verify_client_get", "(JLorg/pjsip/pjsua/pjsip_tls_setting;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1verify_1client_1get},
{"pjsip_tls_setting_require_client_cert_set", "(JLorg/pjsip/pjsua/pjsip_tls_setting;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1require_1client_1cert_1set},
{"pjsip_tls_setting_require_client_cert_get", "(JLorg/pjsip/pjsua/pjsip_tls_setting;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1require_1client_1cert_1get},
{"pjsip_tls_setting_timeout_set", "(JLorg/pjsip/pjsua/pjsip_tls_setting;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1timeout_1set},
{"pjsip_tls_setting_timeout_get", "(JLorg/pjsip/pjsua/pjsip_tls_setting;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1timeout_1get},
{"pjsip_tls_setting_qos_type_set", "(JLorg/pjsip/pjsua/pjsip_tls_setting;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1qos_1type_1set},
{"pjsip_tls_setting_qos_type_get", "(JLorg/pjsip/pjsua/pjsip_tls_setting;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1qos_1type_1get},
{"pjsip_tls_setting_qos_params_set", "(JLorg/pjsip/pjsua/pjsip_tls_setting;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1qos_1params_1set},
{"pjsip_tls_setting_qos_params_get", "(JLorg/pjsip/pjsua/pjsip_tls_setting;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1qos_1params_1get},
{"pjsip_tls_setting_qos_ignore_error_set", "(JLorg/pjsip/pjsua/pjsip_tls_setting;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1qos_1ignore_1error_1set},
{"pjsip_tls_setting_qos_ignore_error_get", "(JLorg/pjsip/pjsua/pjsip_tls_setting;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1tls_1setting_1qos_1ignore_1error_1get},
{"new_pjsip_tls_setting", "()J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_new_1pjsip_1tls_1setting},
{"delete_pjsip_tls_setting", "(J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_delete_1pjsip_1tls_1setting},
{"PJSUA_INVALID_ID_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSUA_1INVALID_1ID_1get},
{"PJSUA_ACC_MAX_PROXIES_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSUA_1ACC_1MAX_1PROXIES_1get},
{"PJSUA_DEFAULT_SRTP_SECURE_SIGNALING_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSUA_1DEFAULT_1SRTP_1SECURE_1SIGNALING_1get},
{"PJSUA_ADD_ICE_TAGS_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSUA_1ADD_1ICE_1TAGS_1get},
{"PJSUA_ACQUIRE_CALL_TIMEOUT_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSUA_1ACQUIRE_1CALL_1TIMEOUT_1get},
{"pjsua_logging_config_msg_logging_set", "(JLorg/pjsip/pjsua/pjsua_logging_config;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1logging_1config_1msg_1logging_1set},
{"pjsua_logging_config_msg_logging_get", "(JLorg/pjsip/pjsua/pjsua_logging_config;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1logging_1config_1msg_1logging_1get},
{"pjsua_logging_config_level_set", "(JLorg/pjsip/pjsua/pjsua_logging_config;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1logging_1config_1level_1set},
{"pjsua_logging_config_level_get", "(JLorg/pjsip/pjsua/pjsua_logging_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1logging_1config_1level_1get},
{"pjsua_logging_config_console_level_set", "(JLorg/pjsip/pjsua/pjsua_logging_config;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1logging_1config_1console_1level_1set},
{"pjsua_logging_config_console_level_get", "(JLorg/pjsip/pjsua/pjsua_logging_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1logging_1config_1console_1level_1get},
{"pjsua_logging_config_decor_set", "(JLorg/pjsip/pjsua/pjsua_logging_config;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1logging_1config_1decor_1set},
{"pjsua_logging_config_decor_get", "(JLorg/pjsip/pjsua/pjsua_logging_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1logging_1config_1decor_1get},
{"pjsua_logging_config_log_filename_set", "(JLorg/pjsip/pjsua/pjsua_logging_config;JLorg/pjsip/pjsua/pj_str_t;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1logging_1config_1log_1filename_1set},
{"pjsua_logging_config_log_filename_get", "(JLorg/pjsip/pjsua/pjsua_logging_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1logging_1config_1log_1filename_1get},
{"pjsua_logging_config_log_file_flags_set", "(JLorg/pjsip/pjsua/pjsua_logging_config;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1logging_1config_1log_1file_1flags_1set},
{"pjsua_logging_config_log_file_flags_get", "(JLorg/pjsip/pjsua/pjsua_logging_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1logging_1config_1log_1file_1flags_1get},
{"pjsua_logging_config_cb_set", "(JLorg/pjsip/pjsua/pjsua_logging_config;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1logging_1config_1cb_1set},
{"pjsua_logging_config_cb_get", "(JLorg/pjsip/pjsua/pjsua_logging_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1logging_1config_1cb_1get},
{"new_pjsua_logging_config", "()J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_new_1pjsua_1logging_1config},
{"delete_pjsua_logging_config", "(J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_delete_1pjsua_1logging_1config},
{"logging_config_default", "(JLorg/pjsip/pjsua/pjsua_logging_config;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_logging_1config_1default},
{"logging_config_dup", "(JLorg/pjsip/pjsua/pj_pool_t;JLorg/pjsip/pjsua/pjsua_logging_config;JLorg/pjsip/pjsua/pjsua_logging_config;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_logging_1config_1dup},
{"pjsua_mwi_info_evsub_set", "(JLorg/pjsip/pjsua/pjsua_mwi_info;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1mwi_1info_1evsub_1set},
{"pjsua_mwi_info_evsub_get", "(JLorg/pjsip/pjsua/pjsua_mwi_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1mwi_1info_1evsub_1get},
{"pjsua_mwi_info_rdata_set", "(JLorg/pjsip/pjsua/pjsua_mwi_info;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1mwi_1info_1rdata_1set},
{"pjsua_mwi_info_rdata_get", "(JLorg/pjsip/pjsua/pjsua_mwi_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1mwi_1info_1rdata_1get},
{"new_pjsua_mwi_info", "()J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_new_1pjsua_1mwi_1info},
{"delete_pjsua_mwi_info", "(J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_delete_1pjsua_1mwi_1info},
{"pjsua_reg_info_cbparam_set", "(JLorg/pjsip/pjsua/pjsua_reg_info;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1reg_1info_1cbparam_1set},
{"pjsua_reg_info_cbparam_get", "(JLorg/pjsip/pjsua/pjsua_reg_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1reg_1info_1cbparam_1get},
{"new_pjsua_reg_info", "()J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_new_1pjsua_1reg_1info},
{"delete_pjsua_reg_info", "(J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_delete_1pjsua_1reg_1info},
{"pjsua_callback_on_call_state_set", "(JLorg/pjsip/pjsua/pjsua_callback;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1call_1state_1set},
{"pjsua_callback_on_call_state_get", "(JLorg/pjsip/pjsua/pjsua_callback;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1call_1state_1get},
{"pjsua_callback_on_incoming_call_set", "(JLorg/pjsip/pjsua/pjsua_callback;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1incoming_1call_1set},
{"pjsua_callback_on_incoming_call_get", "(JLorg/pjsip/pjsua/pjsua_callback;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1incoming_1call_1get},
{"pjsua_callback_on_call_tsx_state_set", "(JLorg/pjsip/pjsua/pjsua_callback;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1call_1tsx_1state_1set},
{"pjsua_callback_on_call_tsx_state_get", "(JLorg/pjsip/pjsua/pjsua_callback;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1call_1tsx_1state_1get},
{"pjsua_callback_on_call_media_state_set", "(JLorg/pjsip/pjsua/pjsua_callback;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1call_1media_1state_1set},
{"pjsua_callback_on_call_media_state_get", "(JLorg/pjsip/pjsua/pjsua_callback;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1call_1media_1state_1get},
{"pjsua_callback_on_stream_created_set", "(JLorg/pjsip/pjsua/pjsua_callback;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1stream_1created_1set},
{"pjsua_callback_on_stream_created_get", "(JLorg/pjsip/pjsua/pjsua_callback;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1stream_1created_1get},
{"pjsua_callback_on_stream_destroyed_set", "(JLorg/pjsip/pjsua/pjsua_callback;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1stream_1destroyed_1set},
{"pjsua_callback_on_stream_destroyed_get", "(JLorg/pjsip/pjsua/pjsua_callback;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1stream_1destroyed_1get},
{"pjsua_callback_on_dtmf_digit_set", "(JLorg/pjsip/pjsua/pjsua_callback;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1dtmf_1digit_1set},
{"pjsua_callback_on_dtmf_digit_get", "(JLorg/pjsip/pjsua/pjsua_callback;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1dtmf_1digit_1get},
{"pjsua_callback_on_call_transfer_request_set", "(JLorg/pjsip/pjsua/pjsua_callback;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1call_1transfer_1request_1set},
{"pjsua_callback_on_call_transfer_request_get", "(JLorg/pjsip/pjsua/pjsua_callback;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1call_1transfer_1request_1get},
{"pjsua_callback_on_call_transfer_status_set", "(JLorg/pjsip/pjsua/pjsua_callback;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1call_1transfer_1status_1set},
{"pjsua_callback_on_call_transfer_status_get", "(JLorg/pjsip/pjsua/pjsua_callback;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1call_1transfer_1status_1get},
{"pjsua_callback_on_call_replace_request_set", "(JLorg/pjsip/pjsua/pjsua_callback;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1call_1replace_1request_1set},
{"pjsua_callback_on_call_replace_request_get", "(JLorg/pjsip/pjsua/pjsua_callback;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1call_1replace_1request_1get},
{"pjsua_callback_on_call_replaced_set", "(JLorg/pjsip/pjsua/pjsua_callback;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1call_1replaced_1set},
{"pjsua_callback_on_call_replaced_get", "(JLorg/pjsip/pjsua/pjsua_callback;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1call_1replaced_1get},
{"pjsua_callback_on_reg_state_set", "(JLorg/pjsip/pjsua/pjsua_callback;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1reg_1state_1set},
{"pjsua_callback_on_reg_state_get", "(JLorg/pjsip/pjsua/pjsua_callback;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1reg_1state_1get},
{"pjsua_callback_on_reg_state2_set", "(JLorg/pjsip/pjsua/pjsua_callback;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1reg_1state2_1set},
{"pjsua_callback_on_reg_state2_get", "(JLorg/pjsip/pjsua/pjsua_callback;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1reg_1state2_1get},
{"pjsua_callback_on_incoming_subscribe_set", "(JLorg/pjsip/pjsua/pjsua_callback;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1incoming_1subscribe_1set},
{"pjsua_callback_on_incoming_subscribe_get", "(JLorg/pjsip/pjsua/pjsua_callback;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1incoming_1subscribe_1get},
{"pjsua_callback_on_srv_subscribe_state_set", "(JLorg/pjsip/pjsua/pjsua_callback;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1srv_1subscribe_1state_1set},
{"pjsua_callback_on_srv_subscribe_state_get", "(JLorg/pjsip/pjsua/pjsua_callback;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1srv_1subscribe_1state_1get},
{"pjsua_callback_on_buddy_state_set", "(JLorg/pjsip/pjsua/pjsua_callback;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1buddy_1state_1set},
{"pjsua_callback_on_buddy_state_get", "(JLorg/pjsip/pjsua/pjsua_callback;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1buddy_1state_1get},
{"pjsua_callback_on_buddy_evsub_state_set", "(JLorg/pjsip/pjsua/pjsua_callback;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1buddy_1evsub_1state_1set},
{"pjsua_callback_on_buddy_evsub_state_get", "(JLorg/pjsip/pjsua/pjsua_callback;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1buddy_1evsub_1state_1get},
{"pjsua_callback_on_pager_set", "(JLorg/pjsip/pjsua/pjsua_callback;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1pager_1set},
{"pjsua_callback_on_pager_get", "(JLorg/pjsip/pjsua/pjsua_callback;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1pager_1get},
{"pjsua_callback_on_pager2_set", "(JLorg/pjsip/pjsua/pjsua_callback;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1pager2_1set},
{"pjsua_callback_on_pager2_get", "(JLorg/pjsip/pjsua/pjsua_callback;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1pager2_1get},
{"pjsua_callback_on_pager_status_set", "(JLorg/pjsip/pjsua/pjsua_callback;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1pager_1status_1set},
{"pjsua_callback_on_pager_status_get", "(JLorg/pjsip/pjsua/pjsua_callback;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1pager_1status_1get},
{"pjsua_callback_on_pager_status2_set", "(JLorg/pjsip/pjsua/pjsua_callback;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1pager_1status2_1set},
{"pjsua_callback_on_pager_status2_get", "(JLorg/pjsip/pjsua/pjsua_callback;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1pager_1status2_1get},
{"pjsua_callback_on_typing_set", "(JLorg/pjsip/pjsua/pjsua_callback;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1typing_1set},
{"pjsua_callback_on_typing_get", "(JLorg/pjsip/pjsua/pjsua_callback;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1typing_1get},
{"pjsua_callback_on_typing2_set", "(JLorg/pjsip/pjsua/pjsua_callback;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1typing2_1set},
{"pjsua_callback_on_typing2_get", "(JLorg/pjsip/pjsua/pjsua_callback;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1typing2_1get},
{"pjsua_callback_on_nat_detect_set", "(JLorg/pjsip/pjsua/pjsua_callback;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1nat_1detect_1set},
{"pjsua_callback_on_nat_detect_get", "(JLorg/pjsip/pjsua/pjsua_callback;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1nat_1detect_1get},
{"pjsua_callback_on_call_redirected_set", "(JLorg/pjsip/pjsua/pjsua_callback;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1call_1redirected_1set},
{"pjsua_callback_on_call_redirected_get", "(JLorg/pjsip/pjsua/pjsua_callback;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1call_1redirected_1get},
{"pjsua_callback_on_mwi_info_set", "(JLorg/pjsip/pjsua/pjsua_callback;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1mwi_1info_1set},
{"pjsua_callback_on_mwi_info_get", "(JLorg/pjsip/pjsua/pjsua_callback;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1mwi_1info_1get},
{"pjsua_callback_on_transport_state_set", "(JLorg/pjsip/pjsua/pjsua_callback;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1transport_1state_1set},
{"pjsua_callback_on_transport_state_get", "(JLorg/pjsip/pjsua/pjsua_callback;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1transport_1state_1get},
{"pjsua_callback_on_ice_transport_error_set", "(JLorg/pjsip/pjsua/pjsua_callback;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1ice_1transport_1error_1set},
{"pjsua_callback_on_ice_transport_error_get", "(JLorg/pjsip/pjsua/pjsua_callback;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1callback_1on_1ice_1transport_1error_1get},
{"new_pjsua_callback", "()J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_new_1pjsua_1callback},
{"delete_pjsua_callback", "(J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_delete_1pjsua_1callback},
{"pjsua_config_max_calls_set", "(JLorg/pjsip/pjsua/pjsua_config;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1max_1calls_1set},
{"pjsua_config_max_calls_get", "(JLorg/pjsip/pjsua/pjsua_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1max_1calls_1get},
{"pjsua_config_thread_cnt_set", "(JLorg/pjsip/pjsua/pjsua_config;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1thread_1cnt_1set},
{"pjsua_config_thread_cnt_get", "(JLorg/pjsip/pjsua/pjsua_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1thread_1cnt_1get},
{"pjsua_config_nameserver_count_set", "(JLorg/pjsip/pjsua/pjsua_config;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1nameserver_1count_1set},
{"pjsua_config_nameserver_count_get", "(JLorg/pjsip/pjsua/pjsua_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1nameserver_1count_1get},
{"pjsua_config_nameserver_set", "(JLorg/pjsip/pjsua/pjsua_config;[J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1nameserver_1set},
{"pjsua_config_force_lr_set", "(JLorg/pjsip/pjsua/pjsua_config;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1force_1lr_1set},
{"pjsua_config_force_lr_get", "(JLorg/pjsip/pjsua/pjsua_config;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1force_1lr_1get},
{"pjsua_config_outbound_proxy_cnt_set", "(JLorg/pjsip/pjsua/pjsua_config;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1outbound_1proxy_1cnt_1set},
{"pjsua_config_outbound_proxy_cnt_get", "(JLorg/pjsip/pjsua/pjsua_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1outbound_1proxy_1cnt_1get},
{"pjsua_config_outbound_proxy_set", "(JLorg/pjsip/pjsua/pjsua_config;[J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1outbound_1proxy_1set},
{"pjsua_config_stun_domain_set", "(JLorg/pjsip/pjsua/pjsua_config;JLorg/pjsip/pjsua/pj_str_t;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1stun_1domain_1set},
{"pjsua_config_stun_domain_get", "(JLorg/pjsip/pjsua/pjsua_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1stun_1domain_1get},
{"pjsua_config_stun_host_set", "(JLorg/pjsip/pjsua/pjsua_config;JLorg/pjsip/pjsua/pj_str_t;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1stun_1host_1set},
{"pjsua_config_stun_host_get", "(JLorg/pjsip/pjsua/pjsua_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1stun_1host_1get},
{"pjsua_config_stun_srv_cnt_set", "(JLorg/pjsip/pjsua/pjsua_config;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1stun_1srv_1cnt_1set},
{"pjsua_config_stun_srv_cnt_get", "(JLorg/pjsip/pjsua/pjsua_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1stun_1srv_1cnt_1get},
{"pjsua_config_stun_srv_set", "(JLorg/pjsip/pjsua/pjsua_config;[J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1stun_1srv_1set},
{"pjsua_config_stun_ignore_failure_set", "(JLorg/pjsip/pjsua/pjsua_config;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1stun_1ignore_1failure_1set},
{"pjsua_config_stun_ignore_failure_get", "(JLorg/pjsip/pjsua/pjsua_config;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1stun_1ignore_1failure_1get},
{"pjsua_config_nat_type_in_sdp_set", "(JLorg/pjsip/pjsua/pjsua_config;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1nat_1type_1in_1sdp_1set},
{"pjsua_config_nat_type_in_sdp_get", "(JLorg/pjsip/pjsua/pjsua_config;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1nat_1type_1in_1sdp_1get},
{"pjsua_config_require_100rel_set", "(JLorg/pjsip/pjsua/pjsua_config;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1require_1100rel_1set},
{"pjsua_config_require_100rel_get", "(JLorg/pjsip/pjsua/pjsua_config;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1require_1100rel_1get},
{"pjsua_config_use_timer_set", "(JLorg/pjsip/pjsua/pjsua_config;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1use_1timer_1set},
{"pjsua_config_use_timer_get", "(JLorg/pjsip/pjsua/pjsua_config;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1use_1timer_1get},
{"pjsua_config_enable_unsolicited_mwi_set", "(JLorg/pjsip/pjsua/pjsua_config;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1enable_1unsolicited_1mwi_1set},
{"pjsua_config_enable_unsolicited_mwi_get", "(JLorg/pjsip/pjsua/pjsua_config;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1enable_1unsolicited_1mwi_1get},
{"pjsua_config_timer_setting_set", "(JLorg/pjsip/pjsua/pjsua_config;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1timer_1setting_1set},
{"pjsua_config_timer_setting_get", "(JLorg/pjsip/pjsua/pjsua_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1timer_1setting_1get},
{"pjsua_config_cred_count_set", "(JLorg/pjsip/pjsua/pjsua_config;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1cred_1count_1set},
{"pjsua_config_cred_count_get", "(JLorg/pjsip/pjsua/pjsua_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1cred_1count_1get},
{"pjsua_config_cred_info_set", "(JLorg/pjsip/pjsua/pjsua_config;JLorg/pjsip/pjsua/pjsip_cred_info;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1cred_1info_1set},
{"pjsua_config_cred_info_get", "(JLorg/pjsip/pjsua/pjsua_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1cred_1info_1get},
{"pjsua_config_cb_set", "(JLorg/pjsip/pjsua/pjsua_config;JLorg/pjsip/pjsua/pjsua_callback;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1cb_1set},
{"pjsua_config_cb_get", "(JLorg/pjsip/pjsua/pjsua_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1cb_1get},
{"pjsua_config_user_agent_set", "(JLorg/pjsip/pjsua/pjsua_config;JLorg/pjsip/pjsua/pj_str_t;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1user_1agent_1set},
{"pjsua_config_user_agent_get", "(JLorg/pjsip/pjsua/pjsua_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1user_1agent_1get},
{"pjsua_config_use_srtp_set", "(JLorg/pjsip/pjsua/pjsua_config;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1use_1srtp_1set},
{"pjsua_config_use_srtp_get", "(JLorg/pjsip/pjsua/pjsua_config;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1use_1srtp_1get},
{"pjsua_config_srtp_secure_signaling_set", "(JLorg/pjsip/pjsua/pjsua_config;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1srtp_1secure_1signaling_1set},
{"pjsua_config_srtp_secure_signaling_get", "(JLorg/pjsip/pjsua/pjsua_config;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1srtp_1secure_1signaling_1get},
{"pjsua_config_srtp_optional_dup_offer_set", "(JLorg/pjsip/pjsua/pjsua_config;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1srtp_1optional_1dup_1offer_1set},
{"pjsua_config_srtp_optional_dup_offer_get", "(JLorg/pjsip/pjsua/pjsua_config;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1srtp_1optional_1dup_1offer_1get},
{"pjsua_config_hangup_forked_call_set", "(JLorg/pjsip/pjsua/pjsua_config;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1hangup_1forked_1call_1set},
{"pjsua_config_hangup_forked_call_get", "(JLorg/pjsip/pjsua/pjsua_config;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1config_1hangup_1forked_1call_1get},
{"new_pjsua_config", "()J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_new_1pjsua_1config},
{"delete_pjsua_config", "(J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_delete_1pjsua_1config},
{"config_default", "(JLorg/pjsip/pjsua/pjsua_config;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_config_1default},
{"config_dup", "(JLorg/pjsip/pjsua/pj_pool_t;JLorg/pjsip/pjsua/pjsua_config;JLorg/pjsip/pjsua/pjsua_config;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_config_1dup},
{"pjsua_msg_data_hdr_list_set", "(JJ)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1msg_1data_1hdr_1list_1set},
{"pjsua_msg_data_hdr_list_get", "(J)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1msg_1data_1hdr_1list_1get},
{"pjsua_msg_data_content_type_set", "(JJLorg/pjsip/pjsua/pj_str_t;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1msg_1data_1content_1type_1set},
{"pjsua_msg_data_content_type_get", "(J)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1msg_1data_1content_1type_1get},
{"pjsua_msg_data_msg_body_set", "(JJLorg/pjsip/pjsua/pj_str_t;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1msg_1data_1msg_1body_1set},
{"pjsua_msg_data_msg_body_get", "(J)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1msg_1data_1msg_1body_1get},
{"pjsua_msg_data_multipart_ctype_set", "(JJ)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1msg_1data_1multipart_1ctype_1set},
{"pjsua_msg_data_multipart_ctype_get", "(J)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1msg_1data_1multipart_1ctype_1get},
{"pjsua_msg_data_multipart_parts_set", "(JJ)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1msg_1data_1multipart_1parts_1set},
{"pjsua_msg_data_multipart_parts_get", "(J)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1msg_1data_1multipart_1parts_1get},
{"new_pjsua_msg_data", "()J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_new_1pjsua_1msg_1data},
{"delete_pjsua_msg_data", "(J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_delete_1pjsua_1msg_1data},
{"msg_data_init", "(J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_msg_1data_1init},
{"create", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_create},
{"start", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_start},
{"handle_events", "(J)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_handle_1events},
{"pool_create", "(Ljava/lang/String;JJ)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pool_1create},
{"reconfigure_logging", "(JLorg/pjsip/pjsua/pjsua_logging_config;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_reconfigure_1logging},
{"get_pjsip_endpt", "()J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_get_1pjsip_1endpt},
{"get_pjmedia_endpt", "()J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_get_1pjmedia_1endpt},
{"get_pool_factory", "()J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_get_1pool_1factory},
{"pj_stun_resolve_result_token_set", "(JLorg/pjsip/pjsua/pj_stun_resolve_result;[B)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pj_1stun_1resolve_1result_1token_1set},
{"pj_stun_resolve_result_status_set", "(JLorg/pjsip/pjsua/pj_stun_resolve_result;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pj_1stun_1resolve_1result_1status_1set},
{"pj_stun_resolve_result_status_get", "(JLorg/pjsip/pjsua/pj_stun_resolve_result;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pj_1stun_1resolve_1result_1status_1get},
{"pj_stun_resolve_result_name_set", "(JLorg/pjsip/pjsua/pj_stun_resolve_result;JLorg/pjsip/pjsua/pj_str_t;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pj_1stun_1resolve_1result_1name_1set},
{"pj_stun_resolve_result_name_get", "(JLorg/pjsip/pjsua/pj_stun_resolve_result;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pj_1stun_1resolve_1result_1name_1get},
{"pj_stun_resolve_result_addr_set", "(JLorg/pjsip/pjsua/pj_stun_resolve_result;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pj_1stun_1resolve_1result_1addr_1set},
{"pj_stun_resolve_result_addr_get", "(JLorg/pjsip/pjsua/pj_stun_resolve_result;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pj_1stun_1resolve_1result_1addr_1get},
{"new_pj_stun_resolve_result", "()J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_new_1pj_1stun_1resolve_1result},
{"delete_pj_stun_resolve_result", "(J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_delete_1pj_1stun_1resolve_1result},
{"detect_nat_type", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_detect_1nat_1type},
{"get_nat_type", "(J)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_get_1nat_1type},
{"resolve_stun_servers", "(J[JI[BJ)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_resolve_1stun_1servers},
{"cancel_stun_resolution", "([BI)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_cancel_1stun_1resolution},
{"verify_sip_url", "(Ljava/lang/String;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_verify_1sip_1url},
{"verify_url", "(Ljava/lang/String;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_verify_1url},
{"schedule_timer", "(JJ)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_schedule_1timer},
{"cancel_timer", "(J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_cancel_1timer},
{"perror", "(Ljava/lang/String;Ljava/lang/String;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_perror},
{"dump", "(I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_dump},
{"pjsua_transport_config_port_set", "(JLorg/pjsip/pjsua/pjsua_transport_config;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1config_1port_1set},
{"pjsua_transport_config_port_get", "(JLorg/pjsip/pjsua/pjsua_transport_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1config_1port_1get},
{"pjsua_transport_config_public_addr_set", "(JLorg/pjsip/pjsua/pjsua_transport_config;JLorg/pjsip/pjsua/pj_str_t;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1config_1public_1addr_1set},
{"pjsua_transport_config_public_addr_get", "(JLorg/pjsip/pjsua/pjsua_transport_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1config_1public_1addr_1get},
{"pjsua_transport_config_bound_addr_set", "(JLorg/pjsip/pjsua/pjsua_transport_config;JLorg/pjsip/pjsua/pj_str_t;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1config_1bound_1addr_1set},
{"pjsua_transport_config_bound_addr_get", "(JLorg/pjsip/pjsua/pjsua_transport_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1config_1bound_1addr_1get},
{"pjsua_transport_config_tls_setting_set", "(JLorg/pjsip/pjsua/pjsua_transport_config;JLorg/pjsip/pjsua/pjsip_tls_setting;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1config_1tls_1setting_1set},
{"pjsua_transport_config_tls_setting_get", "(JLorg/pjsip/pjsua/pjsua_transport_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1config_1tls_1setting_1get},
{"pjsua_transport_config_qos_type_set", "(JLorg/pjsip/pjsua/pjsua_transport_config;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1config_1qos_1type_1set},
{"pjsua_transport_config_qos_type_get", "(JLorg/pjsip/pjsua/pjsua_transport_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1config_1qos_1type_1get},
{"pjsua_transport_config_qos_params_set", "(JLorg/pjsip/pjsua/pjsua_transport_config;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1config_1qos_1params_1set},
{"pjsua_transport_config_qos_params_get", "(JLorg/pjsip/pjsua/pjsua_transport_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1config_1qos_1params_1get},
{"new_pjsua_transport_config", "()J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_new_1pjsua_1transport_1config},
{"delete_pjsua_transport_config", "(J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_delete_1pjsua_1transport_1config},
{"transport_config_default", "(JLorg/pjsip/pjsua/pjsua_transport_config;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_transport_1config_1default},
{"transport_config_dup", "(JLorg/pjsip/pjsua/pj_pool_t;JLorg/pjsip/pjsua/pjsua_transport_config;JLorg/pjsip/pjsua/pjsua_transport_config;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_transport_1config_1dup},
{"pjsua_transport_info_id_set", "(JLorg/pjsip/pjsua/pjsua_transport_info;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1info_1id_1set},
{"pjsua_transport_info_id_get", "(JLorg/pjsip/pjsua/pjsua_transport_info;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1info_1id_1get},
{"pjsua_transport_info_type_set", "(JLorg/pjsip/pjsua/pjsua_transport_info;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1info_1type_1set},
{"pjsua_transport_info_type_get", "(JLorg/pjsip/pjsua/pjsua_transport_info;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1info_1type_1get},
{"pjsua_transport_info_type_name_set", "(JLorg/pjsip/pjsua/pjsua_transport_info;JLorg/pjsip/pjsua/pj_str_t;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1info_1type_1name_1set},
{"pjsua_transport_info_type_name_get", "(JLorg/pjsip/pjsua/pjsua_transport_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1info_1type_1name_1get},
{"pjsua_transport_info_info_set", "(JLorg/pjsip/pjsua/pjsua_transport_info;JLorg/pjsip/pjsua/pj_str_t;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1info_1info_1set},
{"pjsua_transport_info_info_get", "(JLorg/pjsip/pjsua/pjsua_transport_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1info_1info_1get},
{"pjsua_transport_info_flag_set", "(JLorg/pjsip/pjsua/pjsua_transport_info;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1info_1flag_1set},
{"pjsua_transport_info_flag_get", "(JLorg/pjsip/pjsua/pjsua_transport_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1info_1flag_1get},
{"pjsua_transport_info_addr_len_set", "(JLorg/pjsip/pjsua/pjsua_transport_info;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1info_1addr_1len_1set},
{"pjsua_transport_info_addr_len_get", "(JLorg/pjsip/pjsua/pjsua_transport_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1info_1addr_1len_1get},
{"pjsua_transport_info_local_addr_set", "(JLorg/pjsip/pjsua/pjsua_transport_info;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1info_1local_1addr_1set},
{"pjsua_transport_info_local_addr_get", "(JLorg/pjsip/pjsua/pjsua_transport_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1info_1local_1addr_1get},
{"pjsua_transport_info_local_name_set", "(JLorg/pjsip/pjsua/pjsua_transport_info;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1info_1local_1name_1set},
{"pjsua_transport_info_local_name_get", "(JLorg/pjsip/pjsua/pjsua_transport_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1info_1local_1name_1get},
{"pjsua_transport_info_usage_count_set", "(JLorg/pjsip/pjsua/pjsua_transport_info;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1info_1usage_1count_1set},
{"pjsua_transport_info_usage_count_get", "(JLorg/pjsip/pjsua/pjsua_transport_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1transport_1info_1usage_1count_1get},
{"new_pjsua_transport_info", "()J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_new_1pjsua_1transport_1info},
{"delete_pjsua_transport_info", "(J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_delete_1pjsua_1transport_1info},
{"transport_create", "(IJLorg/pjsip/pjsua/pjsua_transport_config;[I)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_transport_1create},
{"transport_register", "(J[I)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_transport_1register},
{"enum_transports", "([I[J)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_enum_1transports},
{"transport_get_info", "(IJLorg/pjsip/pjsua/pjsua_transport_info;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_transport_1get_1info},
{"transport_set_enable", "(II)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_transport_1set_1enable},
{"transport_close", "(II)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_transport_1close},
{"PJSUA_MAX_ACC_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSUA_1MAX_1ACC_1get},
{"PJSUA_REG_INTERVAL_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSUA_1REG_1INTERVAL_1get},
{"PJSUA_UNREG_TIMEOUT_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSUA_1UNREG_1TIMEOUT_1get},
{"PJSUA_DEFAULT_ACC_PRIORITY_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSUA_1DEFAULT_1ACC_1PRIORITY_1get},
{"PJSUA_SECURE_SCHEME_get", "()Ljava/lang/String;", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSUA_1SECURE_1SCHEME_1get},
{"PJSUA_UNPUBLISH_MAX_WAIT_TIME_MSEC_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSUA_1UNPUBLISH_1MAX_1WAIT_1TIME_1MSEC_1get},
{"PJSUA_REG_RETRY_INTERVAL_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSUA_1REG_1RETRY_1INTERVAL_1get},
{"PJSUA_CONTACT_REWRITE_METHOD_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSUA_1CONTACT_1REWRITE_1METHOD_1get},
{"PJSUA_REG_USE_OUTBOUND_PROXY_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSUA_1REG_1USE_1OUTBOUND_1PROXY_1get},
{"PJSUA_REG_USE_ACC_PROXY_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSUA_1REG_1USE_1ACC_1PROXY_1get},
{"pjsua_acc_config_user_data_set", "(JLorg/pjsip/pjsua/pjsua_acc_config;[B)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1user_1data_1set},
{"pjsua_acc_config_priority_set", "(JLorg/pjsip/pjsua/pjsua_acc_config;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1priority_1set},
{"pjsua_acc_config_priority_get", "(JLorg/pjsip/pjsua/pjsua_acc_config;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1priority_1get},
{"pjsua_acc_config_id_set", "(JLorg/pjsip/pjsua/pjsua_acc_config;JLorg/pjsip/pjsua/pj_str_t;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1id_1set},
{"pjsua_acc_config_id_get", "(JLorg/pjsip/pjsua/pjsua_acc_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1id_1get},
{"pjsua_acc_config_reg_uri_set", "(JLorg/pjsip/pjsua/pjsua_acc_config;JLorg/pjsip/pjsua/pj_str_t;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1reg_1uri_1set},
{"pjsua_acc_config_reg_uri_get", "(JLorg/pjsip/pjsua/pjsua_acc_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1reg_1uri_1get},
{"pjsua_acc_config_reg_hdr_list_set", "(JLorg/pjsip/pjsua/pjsua_acc_config;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1reg_1hdr_1list_1set},
{"pjsua_acc_config_reg_hdr_list_get", "(JLorg/pjsip/pjsua/pjsua_acc_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1reg_1hdr_1list_1get},
{"pjsua_acc_config_mwi_enabled_set", "(JLorg/pjsip/pjsua/pjsua_acc_config;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1mwi_1enabled_1set},
{"pjsua_acc_config_mwi_enabled_get", "(JLorg/pjsip/pjsua/pjsua_acc_config;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1mwi_1enabled_1get},
{"pjsua_acc_config_publish_enabled_set", "(JLorg/pjsip/pjsua/pjsua_acc_config;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1publish_1enabled_1set},
{"pjsua_acc_config_publish_enabled_get", "(JLorg/pjsip/pjsua/pjsua_acc_config;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1publish_1enabled_1get},
{"pjsua_acc_config_publish_opt_set", "(JLorg/pjsip/pjsua/pjsua_acc_config;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1publish_1opt_1set},
{"pjsua_acc_config_publish_opt_get", "(JLorg/pjsip/pjsua/pjsua_acc_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1publish_1opt_1get},
{"pjsua_acc_config_unpublish_max_wait_time_msec_set", "(JLorg/pjsip/pjsua/pjsua_acc_config;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1unpublish_1max_1wait_1time_1msec_1set},
{"pjsua_acc_config_unpublish_max_wait_time_msec_get", "(JLorg/pjsip/pjsua/pjsua_acc_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1unpublish_1max_1wait_1time_1msec_1get},
{"pjsua_acc_config_auth_pref_set", "(JLorg/pjsip/pjsua/pjsua_acc_config;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1auth_1pref_1set},
{"pjsua_acc_config_auth_pref_get", "(JLorg/pjsip/pjsua/pjsua_acc_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1auth_1pref_1get},
{"pjsua_acc_config_pidf_tuple_id_set", "(JLorg/pjsip/pjsua/pjsua_acc_config;JLorg/pjsip/pjsua/pj_str_t;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1pidf_1tuple_1id_1set},
{"pjsua_acc_config_pidf_tuple_id_get", "(JLorg/pjsip/pjsua/pjsua_acc_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1pidf_1tuple_1id_1get},
{"pjsua_acc_config_force_contact_set", "(JLorg/pjsip/pjsua/pjsua_acc_config;JLorg/pjsip/pjsua/pj_str_t;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1force_1contact_1set},
{"pjsua_acc_config_force_contact_get", "(JLorg/pjsip/pjsua/pjsua_acc_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1force_1contact_1get},
{"pjsua_acc_config_contact_params_set", "(JLorg/pjsip/pjsua/pjsua_acc_config;JLorg/pjsip/pjsua/pj_str_t;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1contact_1params_1set},
{"pjsua_acc_config_contact_params_get", "(JLorg/pjsip/pjsua/pjsua_acc_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1contact_1params_1get},
{"pjsua_acc_config_contact_uri_params_set", "(JLorg/pjsip/pjsua/pjsua_acc_config;JLorg/pjsip/pjsua/pj_str_t;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1contact_1uri_1params_1set},
{"pjsua_acc_config_contact_uri_params_get", "(JLorg/pjsip/pjsua/pjsua_acc_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1contact_1uri_1params_1get},
{"pjsua_acc_config_require_100rel_set", "(JLorg/pjsip/pjsua/pjsua_acc_config;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1require_1100rel_1set},
{"pjsua_acc_config_require_100rel_get", "(JLorg/pjsip/pjsua/pjsua_acc_config;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1require_1100rel_1get},
{"pjsua_acc_config_use_timer_set", "(JLorg/pjsip/pjsua/pjsua_acc_config;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1use_1timer_1set},
{"pjsua_acc_config_use_timer_get", "(JLorg/pjsip/pjsua/pjsua_acc_config;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1use_1timer_1get},
{"pjsua_acc_config_timer_setting_set", "(JLorg/pjsip/pjsua/pjsua_acc_config;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1timer_1setting_1set},
{"pjsua_acc_config_timer_setting_get", "(JLorg/pjsip/pjsua/pjsua_acc_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1timer_1setting_1get},
{"pjsua_acc_config_proxy_cnt_set", "(JLorg/pjsip/pjsua/pjsua_acc_config;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1proxy_1cnt_1set},
{"pjsua_acc_config_proxy_cnt_get", "(JLorg/pjsip/pjsua/pjsua_acc_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1proxy_1cnt_1get},
{"pjsua_acc_config_proxy_set", "(JLorg/pjsip/pjsua/pjsua_acc_config;[J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1proxy_1set},
{"pjsua_acc_config_reg_timeout_set", "(JLorg/pjsip/pjsua/pjsua_acc_config;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1reg_1timeout_1set},
{"pjsua_acc_config_reg_timeout_get", "(JLorg/pjsip/pjsua/pjsua_acc_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1reg_1timeout_1get},
{"pjsua_acc_config_unreg_timeout_set", "(JLorg/pjsip/pjsua/pjsua_acc_config;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1unreg_1timeout_1set},
{"pjsua_acc_config_unreg_timeout_get", "(JLorg/pjsip/pjsua/pjsua_acc_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1unreg_1timeout_1get},
{"pjsua_acc_config_cred_count_set", "(JLorg/pjsip/pjsua/pjsua_acc_config;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1cred_1count_1set},
{"pjsua_acc_config_cred_count_get", "(JLorg/pjsip/pjsua/pjsua_acc_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1cred_1count_1get},
{"pjsua_acc_config_cred_info_set", "(JLorg/pjsip/pjsua/pjsua_acc_config;JLorg/pjsip/pjsua/pjsip_cred_info;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1cred_1info_1set},
{"pjsua_acc_config_cred_info_get", "(JLorg/pjsip/pjsua/pjsua_acc_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1cred_1info_1get},
{"pjsua_acc_config_transport_id_set", "(JLorg/pjsip/pjsua/pjsua_acc_config;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1transport_1id_1set},
{"pjsua_acc_config_transport_id_get", "(JLorg/pjsip/pjsua/pjsua_acc_config;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1transport_1id_1get},
{"pjsua_acc_config_allow_contact_rewrite_set", "(JLorg/pjsip/pjsua/pjsua_acc_config;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1allow_1contact_1rewrite_1set},
{"pjsua_acc_config_allow_contact_rewrite_get", "(JLorg/pjsip/pjsua/pjsua_acc_config;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1allow_1contact_1rewrite_1get},
{"pjsua_acc_config_contact_rewrite_method_set", "(JLorg/pjsip/pjsua/pjsua_acc_config;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1contact_1rewrite_1method_1set},
{"pjsua_acc_config_contact_rewrite_method_get", "(JLorg/pjsip/pjsua/pjsua_acc_config;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1contact_1rewrite_1method_1get},
{"pjsua_acc_config_ka_interval_set", "(JLorg/pjsip/pjsua/pjsua_acc_config;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1ka_1interval_1set},
{"pjsua_acc_config_ka_interval_get", "(JLorg/pjsip/pjsua/pjsua_acc_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1ka_1interval_1get},
{"pjsua_acc_config_ka_data_set", "(JLorg/pjsip/pjsua/pjsua_acc_config;JLorg/pjsip/pjsua/pj_str_t;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1ka_1data_1set},
{"pjsua_acc_config_ka_data_get", "(JLorg/pjsip/pjsua/pjsua_acc_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1ka_1data_1get},
{"pjsua_acc_config_use_srtp_set", "(JLorg/pjsip/pjsua/pjsua_acc_config;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1use_1srtp_1set},
{"pjsua_acc_config_use_srtp_get", "(JLorg/pjsip/pjsua/pjsua_acc_config;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1use_1srtp_1get},
{"pjsua_acc_config_srtp_secure_signaling_set", "(JLorg/pjsip/pjsua/pjsua_acc_config;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1srtp_1secure_1signaling_1set},
{"pjsua_acc_config_srtp_secure_signaling_get", "(JLorg/pjsip/pjsua/pjsua_acc_config;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1srtp_1secure_1signaling_1get},
{"pjsua_acc_config_srtp_optional_dup_offer_set", "(JLorg/pjsip/pjsua/pjsua_acc_config;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1srtp_1optional_1dup_1offer_1set},
{"pjsua_acc_config_srtp_optional_dup_offer_get", "(JLorg/pjsip/pjsua/pjsua_acc_config;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1srtp_1optional_1dup_1offer_1get},
{"pjsua_acc_config_reg_retry_interval_set", "(JLorg/pjsip/pjsua/pjsua_acc_config;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1reg_1retry_1interval_1set},
{"pjsua_acc_config_reg_retry_interval_get", "(JLorg/pjsip/pjsua/pjsua_acc_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1reg_1retry_1interval_1get},
{"pjsua_acc_config_drop_calls_on_reg_fail_set", "(JLorg/pjsip/pjsua/pjsua_acc_config;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1drop_1calls_1on_1reg_1fail_1set},
{"pjsua_acc_config_drop_calls_on_reg_fail_get", "(JLorg/pjsip/pjsua/pjsua_acc_config;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1drop_1calls_1on_1reg_1fail_1get},
{"pjsua_acc_config_reg_use_proxy_set", "(JLorg/pjsip/pjsua/pjsua_acc_config;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1reg_1use_1proxy_1set},
{"pjsua_acc_config_reg_use_proxy_get", "(JLorg/pjsip/pjsua/pjsua_acc_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1reg_1use_1proxy_1get},
{"pjsua_acc_config_call_hold_type_set", "(JLorg/pjsip/pjsua/pjsua_acc_config;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1call_1hold_1type_1set},
{"pjsua_acc_config_call_hold_type_get", "(JLorg/pjsip/pjsua/pjsua_acc_config;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1config_1call_1hold_1type_1get},
{"new_pjsua_acc_config", "()J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_new_1pjsua_1acc_1config},
{"delete_pjsua_acc_config", "(J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_delete_1pjsua_1acc_1config},
{"acc_config_default", "(JLorg/pjsip/pjsua/pjsua_acc_config;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_acc_1config_1default},
{"acc_config_dup", "(JLorg/pjsip/pjsua/pj_pool_t;JLorg/pjsip/pjsua/pjsua_acc_config;JLorg/pjsip/pjsua/pjsua_acc_config;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_acc_1config_1dup},
{"pjsua_acc_info_id_set", "(JLorg/pjsip/pjsua/pjsua_acc_info;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1info_1id_1set},
{"pjsua_acc_info_id_get", "(JLorg/pjsip/pjsua/pjsua_acc_info;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1info_1id_1get},
{"pjsua_acc_info_is_default_set", "(JLorg/pjsip/pjsua/pjsua_acc_info;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1info_1is_1default_1set},
{"pjsua_acc_info_is_default_get", "(JLorg/pjsip/pjsua/pjsua_acc_info;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1info_1is_1default_1get},
{"pjsua_acc_info_acc_uri_set", "(JLorg/pjsip/pjsua/pjsua_acc_info;JLorg/pjsip/pjsua/pj_str_t;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1info_1acc_1uri_1set},
{"pjsua_acc_info_acc_uri_get", "(JLorg/pjsip/pjsua/pjsua_acc_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1info_1acc_1uri_1get},
{"pjsua_acc_info_has_registration_set", "(JLorg/pjsip/pjsua/pjsua_acc_info;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1info_1has_1registration_1set},
{"pjsua_acc_info_has_registration_get", "(JLorg/pjsip/pjsua/pjsua_acc_info;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1info_1has_1registration_1get},
{"pjsua_acc_info_expires_set", "(JLorg/pjsip/pjsua/pjsua_acc_info;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1info_1expires_1set},
{"pjsua_acc_info_expires_get", "(JLorg/pjsip/pjsua/pjsua_acc_info;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1info_1expires_1get},
{"pjsua_acc_info_status_set", "(JLorg/pjsip/pjsua/pjsua_acc_info;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1info_1status_1set},
{"pjsua_acc_info_status_get", "(JLorg/pjsip/pjsua/pjsua_acc_info;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1info_1status_1get},
{"pjsua_acc_info_reg_last_err_set", "(JLorg/pjsip/pjsua/pjsua_acc_info;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1info_1reg_1last_1err_1set},
{"pjsua_acc_info_reg_last_err_get", "(JLorg/pjsip/pjsua/pjsua_acc_info;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1info_1reg_1last_1err_1get},
{"pjsua_acc_info_status_text_set", "(JLorg/pjsip/pjsua/pjsua_acc_info;JLorg/pjsip/pjsua/pj_str_t;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1info_1status_1text_1set},
{"pjsua_acc_info_status_text_get", "(JLorg/pjsip/pjsua/pjsua_acc_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1info_1status_1text_1get},
{"pjsua_acc_info_online_status_set", "(JLorg/pjsip/pjsua/pjsua_acc_info;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1info_1online_1status_1set},
{"pjsua_acc_info_online_status_get", "(JLorg/pjsip/pjsua/pjsua_acc_info;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1info_1online_1status_1get},
{"pjsua_acc_info_online_status_text_set", "(JLorg/pjsip/pjsua/pjsua_acc_info;JLorg/pjsip/pjsua/pj_str_t;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1info_1online_1status_1text_1set},
{"pjsua_acc_info_online_status_text_get", "(JLorg/pjsip/pjsua/pjsua_acc_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1info_1online_1status_1text_1get},
{"pjsua_acc_info_rpid_set", "(JLorg/pjsip/pjsua/pjsua_acc_info;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1info_1rpid_1set},
{"pjsua_acc_info_rpid_get", "(JLorg/pjsip/pjsua/pjsua_acc_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1info_1rpid_1get},
{"pjsua_acc_info_buf__set", "(JLorg/pjsip/pjsua/pjsua_acc_info;Ljava/lang/String;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1info_1buf_1_1set},
{"pjsua_acc_info_buf__get", "(JLorg/pjsip/pjsua/pjsua_acc_info;)Ljava/lang/String;", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1acc_1info_1buf_1_1get},
{"new_pjsua_acc_info", "()J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_new_1pjsua_1acc_1info},
{"delete_pjsua_acc_info", "(J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_delete_1pjsua_1acc_1info},
{"acc_get_count", "()J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_acc_1get_1count},
{"acc_is_valid", "(I)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_acc_1is_1valid},
{"acc_set_default", "(I)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_acc_1set_1default},
{"acc_get_default", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_acc_1get_1default},
{"acc_add", "(JLorg/pjsip/pjsua/pjsua_acc_config;I[I)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_acc_1add},
{"acc_add_local", "(II[I)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_acc_1add_1local},
{"acc_set_user_data", "(I[B)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_acc_1set_1user_1data},
{"acc_del", "(I)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_acc_1del},
{"acc_modify", "(IJLorg/pjsip/pjsua/pjsua_acc_config;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_acc_1modify},
{"acc_set_online_status", "(II)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_acc_1set_1online_1status},
{"acc_set_online_status2", "(IIJ)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_acc_1set_1online_1status2},
{"acc_set_registration", "(II)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_acc_1set_1registration},
{"acc_get_info", "(IJLorg/pjsip/pjsua/pjsua_acc_info;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_acc_1get_1info},
{"enum_accs", "([I[J)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_enum_1accs},
{"acc_enum_info", "(JLorg/pjsip/pjsua/pjsua_acc_info;[J)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_acc_1enum_1info},
{"acc_find_for_outgoing", "(JLorg/pjsip/pjsua/pj_str_t;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_acc_1find_1for_1outgoing},
{"acc_find_for_incoming", "(J)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_acc_1find_1for_1incoming},
{"acc_create_request", "(IJJLorg/pjsip/pjsua/pj_str_t;J)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_acc_1create_1request},
{"acc_create_uac_contact", "(JLorg/pjsip/pjsua/pj_pool_t;JLorg/pjsip/pjsua/pj_str_t;IJLorg/pjsip/pjsua/pj_str_t;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_acc_1create_1uac_1contact},
{"acc_create_uas_contact", "(JLorg/pjsip/pjsua/pj_pool_t;JLorg/pjsip/pjsua/pj_str_t;IJ)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_acc_1create_1uas_1contact},
{"acc_set_transport", "(II)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_acc_1set_1transport},
{"PJSUA_MAX_CALLS_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSUA_1MAX_1CALLS_1get},
{"pjsua_call_info_id_set", "(JLorg/pjsip/pjsua/pjsua_call_info;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1id_1set},
{"pjsua_call_info_id_get", "(JLorg/pjsip/pjsua/pjsua_call_info;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1id_1get},
{"pjsua_call_info_role_set", "(JLorg/pjsip/pjsua/pjsua_call_info;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1role_1set},
{"pjsua_call_info_role_get", "(JLorg/pjsip/pjsua/pjsua_call_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1role_1get},
{"pjsua_call_info_acc_id_set", "(JLorg/pjsip/pjsua/pjsua_call_info;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1acc_1id_1set},
{"pjsua_call_info_acc_id_get", "(JLorg/pjsip/pjsua/pjsua_call_info;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1acc_1id_1get},
{"pjsua_call_info_local_info_set", "(JLorg/pjsip/pjsua/pjsua_call_info;JLorg/pjsip/pjsua/pj_str_t;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1local_1info_1set},
{"pjsua_call_info_local_info_get", "(JLorg/pjsip/pjsua/pjsua_call_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1local_1info_1get},
{"pjsua_call_info_local_contact_set", "(JLorg/pjsip/pjsua/pjsua_call_info;JLorg/pjsip/pjsua/pj_str_t;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1local_1contact_1set},
{"pjsua_call_info_local_contact_get", "(JLorg/pjsip/pjsua/pjsua_call_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1local_1contact_1get},
{"pjsua_call_info_remote_info_set", "(JLorg/pjsip/pjsua/pjsua_call_info;JLorg/pjsip/pjsua/pj_str_t;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1remote_1info_1set},
{"pjsua_call_info_remote_info_get", "(JLorg/pjsip/pjsua/pjsua_call_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1remote_1info_1get},
{"pjsua_call_info_remote_contact_set", "(JLorg/pjsip/pjsua/pjsua_call_info;JLorg/pjsip/pjsua/pj_str_t;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1remote_1contact_1set},
{"pjsua_call_info_remote_contact_get", "(JLorg/pjsip/pjsua/pjsua_call_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1remote_1contact_1get},
{"pjsua_call_info_call_id_set", "(JLorg/pjsip/pjsua/pjsua_call_info;JLorg/pjsip/pjsua/pj_str_t;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1call_1id_1set},
{"pjsua_call_info_call_id_get", "(JLorg/pjsip/pjsua/pjsua_call_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1call_1id_1get},
{"pjsua_call_info_state_set", "(JLorg/pjsip/pjsua/pjsua_call_info;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1state_1set},
{"pjsua_call_info_state_get", "(JLorg/pjsip/pjsua/pjsua_call_info;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1state_1get},
{"pjsua_call_info_state_text_set", "(JLorg/pjsip/pjsua/pjsua_call_info;JLorg/pjsip/pjsua/pj_str_t;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1state_1text_1set},
{"pjsua_call_info_state_text_get", "(JLorg/pjsip/pjsua/pjsua_call_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1state_1text_1get},
{"pjsua_call_info_last_status_set", "(JLorg/pjsip/pjsua/pjsua_call_info;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1last_1status_1set},
{"pjsua_call_info_last_status_get", "(JLorg/pjsip/pjsua/pjsua_call_info;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1last_1status_1get},
{"pjsua_call_info_last_status_text_set", "(JLorg/pjsip/pjsua/pjsua_call_info;JLorg/pjsip/pjsua/pj_str_t;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1last_1status_1text_1set},
{"pjsua_call_info_last_status_text_get", "(JLorg/pjsip/pjsua/pjsua_call_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1last_1status_1text_1get},
{"pjsua_call_info_media_status_set", "(JLorg/pjsip/pjsua/pjsua_call_info;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1media_1status_1set},
{"pjsua_call_info_media_status_get", "(JLorg/pjsip/pjsua/pjsua_call_info;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1media_1status_1get},
{"pjsua_call_info_media_dir_set", "(JLorg/pjsip/pjsua/pjsua_call_info;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1media_1dir_1set},
{"pjsua_call_info_media_dir_get", "(JLorg/pjsip/pjsua/pjsua_call_info;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1media_1dir_1get},
{"pjsua_call_info_conf_slot_set", "(JLorg/pjsip/pjsua/pjsua_call_info;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1conf_1slot_1set},
{"pjsua_call_info_conf_slot_get", "(JLorg/pjsip/pjsua/pjsua_call_info;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1conf_1slot_1get},
{"pjsua_call_info_connect_duration_set", "(JLorg/pjsip/pjsua/pjsua_call_info;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1connect_1duration_1set},
{"pjsua_call_info_connect_duration_get", "(JLorg/pjsip/pjsua/pjsua_call_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1connect_1duration_1get},
{"pjsua_call_info_total_duration_set", "(JLorg/pjsip/pjsua/pjsua_call_info;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1total_1duration_1set},
{"pjsua_call_info_total_duration_get", "(JLorg/pjsip/pjsua/pjsua_call_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1call_1info_1total_1duration_1get},
{"new_pjsua_call_info", "()J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_new_1pjsua_1call_1info},
{"delete_pjsua_call_info", "(J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_delete_1pjsua_1call_1info},
{"call_get_max_count", "()J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_call_1get_1max_1count},
{"call_get_count", "()J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_call_1get_1count},
{"enum_calls", "([I[J)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_enum_1calls},
{"call_make_call", "(IJLorg/pjsip/pjsua/pj_str_t;J[BJ[I)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_call_1make_1call},
{"call_is_active", "(I)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_call_1is_1active},
{"call_has_media", "(I)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_call_1has_1media},
{"call_get_media_session", "(I)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_call_1get_1media_1session},
{"call_get_media_transport", "(I)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_call_1get_1media_1transport},
{"call_get_conf_port", "(I)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_call_1get_1conf_1port},
{"call_get_info", "(IJLorg/pjsip/pjsua/pjsua_call_info;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_call_1get_1info},
{"call_remote_has_cap", "(IIJLorg/pjsip/pjsua/pj_str_t;JLorg/pjsip/pjsua/pj_str_t;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_call_1remote_1has_1cap},
{"call_set_user_data", "(I[B)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_call_1set_1user_1data},
{"call_get_rem_nat_type", "(IJ)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_call_1get_1rem_1nat_1type},
{"call_answer", "(IJJLorg/pjsip/pjsua/pj_str_t;J)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_call_1answer},
{"call_hangup", "(IJJLorg/pjsip/pjsua/pj_str_t;J)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_call_1hangup},
{"call_process_redirect", "(IJ)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_call_1process_1redirect},
{"call_set_hold", "(IJ)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_call_1set_1hold},
{"call_reinvite", "(IIJ)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_call_1reinvite},
{"call_update", "(IJJ)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_call_1update},
{"call_xfer", "(IJLorg/pjsip/pjsua/pj_str_t;J)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_call_1xfer},
{"PJSUA_XFER_NO_REQUIRE_REPLACES_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSUA_1XFER_1NO_1REQUIRE_1REPLACES_1get},
{"call_xfer_replaces", "(IIJJ)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_call_1xfer_1replaces},
{"call_dial_dtmf", "(IJLorg/pjsip/pjsua/pj_str_t;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_call_1dial_1dtmf},
{"call_send_im", "(IJLorg/pjsip/pjsua/pj_str_t;JLorg/pjsip/pjsua/pj_str_t;J[B)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_call_1send_1im},
{"call_send_typing_ind", "(IIJ)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_call_1send_1typing_1ind},
{"call_send_request", "(IJLorg/pjsip/pjsua/pj_str_t;J)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_call_1send_1request},
{"call_hangup_all", "()V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_call_1hangup_1all},
{"call_dump__SWIG_0", "(IILjava/lang/String;JLjava/lang/String;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_call_1dump_1_1SWIG_10},
{"PJSUA_MAX_BUDDIES_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSUA_1MAX_1BUDDIES_1get},
{"PJSUA_PRES_TIMER_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSUA_1PRES_1TIMER_1get},
{"pjsua_buddy_config_uri_set", "(JLorg/pjsip/pjsua/pjsua_buddy_config;JLorg/pjsip/pjsua/pj_str_t;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1config_1uri_1set},
{"pjsua_buddy_config_uri_get", "(JLorg/pjsip/pjsua/pjsua_buddy_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1config_1uri_1get},
{"pjsua_buddy_config_subscribe_set", "(JLorg/pjsip/pjsua/pjsua_buddy_config;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1config_1subscribe_1set},
{"pjsua_buddy_config_subscribe_get", "(JLorg/pjsip/pjsua/pjsua_buddy_config;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1config_1subscribe_1get},
{"pjsua_buddy_config_user_data_set", "(JLorg/pjsip/pjsua/pjsua_buddy_config;[B)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1config_1user_1data_1set},
{"new_pjsua_buddy_config", "()J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_new_1pjsua_1buddy_1config},
{"delete_pjsua_buddy_config", "(J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_delete_1pjsua_1buddy_1config},
{"pjsua_buddy_info_id_set", "(JLorg/pjsip/pjsua/pjsua_buddy_info;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1info_1id_1set},
{"pjsua_buddy_info_id_get", "(JLorg/pjsip/pjsua/pjsua_buddy_info;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1info_1id_1get},
{"pjsua_buddy_info_uri_set", "(JLorg/pjsip/pjsua/pjsua_buddy_info;JLorg/pjsip/pjsua/pj_str_t;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1info_1uri_1set},
{"pjsua_buddy_info_uri_get", "(JLorg/pjsip/pjsua/pjsua_buddy_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1info_1uri_1get},
{"pjsua_buddy_info_contact_set", "(JLorg/pjsip/pjsua/pjsua_buddy_info;JLorg/pjsip/pjsua/pj_str_t;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1info_1contact_1set},
{"pjsua_buddy_info_contact_get", "(JLorg/pjsip/pjsua/pjsua_buddy_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1info_1contact_1get},
{"pjsua_buddy_info_status_set", "(JLorg/pjsip/pjsua/pjsua_buddy_info;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1info_1status_1set},
{"pjsua_buddy_info_status_get", "(JLorg/pjsip/pjsua/pjsua_buddy_info;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1info_1status_1get},
{"pjsua_buddy_info_status_text_set", "(JLorg/pjsip/pjsua/pjsua_buddy_info;JLorg/pjsip/pjsua/pj_str_t;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1info_1status_1text_1set},
{"pjsua_buddy_info_status_text_get", "(JLorg/pjsip/pjsua/pjsua_buddy_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1info_1status_1text_1get},
{"pjsua_buddy_info_monitor_pres_set", "(JLorg/pjsip/pjsua/pjsua_buddy_info;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1info_1monitor_1pres_1set},
{"pjsua_buddy_info_monitor_pres_get", "(JLorg/pjsip/pjsua/pjsua_buddy_info;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1info_1monitor_1pres_1get},
{"pjsua_buddy_info_sub_state_set", "(JLorg/pjsip/pjsua/pjsua_buddy_info;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1info_1sub_1state_1set},
{"pjsua_buddy_info_sub_state_get", "(JLorg/pjsip/pjsua/pjsua_buddy_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1info_1sub_1state_1get},
{"pjsua_buddy_info_sub_state_name_set", "(JLorg/pjsip/pjsua/pjsua_buddy_info;Ljava/lang/String;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1info_1sub_1state_1name_1set},
{"pjsua_buddy_info_sub_state_name_get", "(JLorg/pjsip/pjsua/pjsua_buddy_info;)Ljava/lang/String;", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1info_1sub_1state_1name_1get},
{"pjsua_buddy_info_sub_term_code_set", "(JLorg/pjsip/pjsua/pjsua_buddy_info;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1info_1sub_1term_1code_1set},
{"pjsua_buddy_info_sub_term_code_get", "(JLorg/pjsip/pjsua/pjsua_buddy_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1info_1sub_1term_1code_1get},
{"pjsua_buddy_info_sub_term_reason_set", "(JLorg/pjsip/pjsua/pjsua_buddy_info;JLorg/pjsip/pjsua/pj_str_t;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1info_1sub_1term_1reason_1set},
{"pjsua_buddy_info_sub_term_reason_get", "(JLorg/pjsip/pjsua/pjsua_buddy_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1info_1sub_1term_1reason_1get},
{"pjsua_buddy_info_rpid_set", "(JLorg/pjsip/pjsua/pjsua_buddy_info;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1info_1rpid_1set},
{"pjsua_buddy_info_rpid_get", "(JLorg/pjsip/pjsua/pjsua_buddy_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1info_1rpid_1get},
{"pjsua_buddy_info_pres_status_set", "(JLorg/pjsip/pjsua/pjsua_buddy_info;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1info_1pres_1status_1set},
{"pjsua_buddy_info_pres_status_get", "(JLorg/pjsip/pjsua/pjsua_buddy_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1info_1pres_1status_1get},
{"pjsua_buddy_info_buf__set", "(JLorg/pjsip/pjsua/pjsua_buddy_info;Ljava/lang/String;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1info_1buf_1_1set},
{"pjsua_buddy_info_buf__get", "(JLorg/pjsip/pjsua/pjsua_buddy_info;)Ljava/lang/String;", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1buddy_1info_1buf_1_1get},
{"new_pjsua_buddy_info", "()J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_new_1pjsua_1buddy_1info},
{"delete_pjsua_buddy_info", "(J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_delete_1pjsua_1buddy_1info},
{"buddy_config_default", "(JLorg/pjsip/pjsua/pjsua_buddy_config;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_buddy_1config_1default},
{"get_buddy_count", "()J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_get_1buddy_1count},
{"buddy_is_valid", "(I)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_buddy_1is_1valid},
{"enum_buddies", "([I[J)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_enum_1buddies},
{"buddy_find", "(JLorg/pjsip/pjsua/pj_str_t;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_buddy_1find},
{"buddy_get_info", "(IJLorg/pjsip/pjsua/pjsua_buddy_info;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_buddy_1get_1info},
{"buddy_set_user_data", "(I[B)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_buddy_1set_1user_1data},
{"buddy_add", "(JLorg/pjsip/pjsua/pjsua_buddy_config;J)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_buddy_1add},
{"buddy_del", "(I)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_buddy_1del},
{"buddy_subscribe_pres", "(II)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_buddy_1subscribe_1pres},
{"buddy_update_pres", "(I)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_buddy_1update_1pres},
{"pres_notify", "(IJJJLorg/pjsip/pjsua/pj_str_t;JLorg/pjsip/pjsua/pj_str_t;IJ)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pres_1notify},
{"pres_dump", "(I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pres_1dump},
{"pjsip_message_method_get", "()J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsip_1message_1method_1get},
{"im_send", "(IJLorg/pjsip/pjsua/pj_str_t;JLorg/pjsip/pjsua/pj_str_t;JLorg/pjsip/pjsua/pj_str_t;J[B)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_im_1send},
{"im_typing", "(IJLorg/pjsip/pjsua/pj_str_t;IJ)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_im_1typing},
{"PJSUA_MAX_CONF_PORTS_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSUA_1MAX_1CONF_1PORTS_1get},
{"PJSUA_DEFAULT_CLOCK_RATE_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSUA_1DEFAULT_1CLOCK_1RATE_1get},
{"PJSUA_DEFAULT_AUDIO_FRAME_PTIME_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSUA_1DEFAULT_1AUDIO_1FRAME_1PTIME_1get},
{"PJSUA_DEFAULT_CODEC_QUALITY_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSUA_1DEFAULT_1CODEC_1QUALITY_1get},
{"PJSUA_DEFAULT_ILBC_MODE_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSUA_1DEFAULT_1ILBC_1MODE_1get},
{"PJSUA_DEFAULT_EC_TAIL_LEN_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSUA_1DEFAULT_1EC_1TAIL_1LEN_1get},
{"PJSUA_MAX_PLAYERS_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSUA_1MAX_1PLAYERS_1get},
{"PJSUA_MAX_RECORDERS_get", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_PJSUA_1MAX_1RECORDERS_1get},
{"pjsua_media_config_clock_rate_set", "(JLorg/pjsip/pjsua/pjsua_media_config;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1clock_1rate_1set},
{"pjsua_media_config_clock_rate_get", "(JLorg/pjsip/pjsua/pjsua_media_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1clock_1rate_1get},
{"pjsua_media_config_snd_clock_rate_set", "(JLorg/pjsip/pjsua/pjsua_media_config;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1snd_1clock_1rate_1set},
{"pjsua_media_config_snd_clock_rate_get", "(JLorg/pjsip/pjsua/pjsua_media_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1snd_1clock_1rate_1get},
{"pjsua_media_config_channel_count_set", "(JLorg/pjsip/pjsua/pjsua_media_config;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1channel_1count_1set},
{"pjsua_media_config_channel_count_get", "(JLorg/pjsip/pjsua/pjsua_media_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1channel_1count_1get},
{"pjsua_media_config_audio_frame_ptime_set", "(JLorg/pjsip/pjsua/pjsua_media_config;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1audio_1frame_1ptime_1set},
{"pjsua_media_config_audio_frame_ptime_get", "(JLorg/pjsip/pjsua/pjsua_media_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1audio_1frame_1ptime_1get},
{"pjsua_media_config_max_media_ports_set", "(JLorg/pjsip/pjsua/pjsua_media_config;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1max_1media_1ports_1set},
{"pjsua_media_config_max_media_ports_get", "(JLorg/pjsip/pjsua/pjsua_media_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1max_1media_1ports_1get},
{"pjsua_media_config_has_ioqueue_set", "(JLorg/pjsip/pjsua/pjsua_media_config;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1has_1ioqueue_1set},
{"pjsua_media_config_has_ioqueue_get", "(JLorg/pjsip/pjsua/pjsua_media_config;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1has_1ioqueue_1get},
{"pjsua_media_config_thread_cnt_set", "(JLorg/pjsip/pjsua/pjsua_media_config;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1thread_1cnt_1set},
{"pjsua_media_config_thread_cnt_get", "(JLorg/pjsip/pjsua/pjsua_media_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1thread_1cnt_1get},
{"pjsua_media_config_quality_set", "(JLorg/pjsip/pjsua/pjsua_media_config;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1quality_1set},
{"pjsua_media_config_quality_get", "(JLorg/pjsip/pjsua/pjsua_media_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1quality_1get},
{"pjsua_media_config_ptime_set", "(JLorg/pjsip/pjsua/pjsua_media_config;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1ptime_1set},
{"pjsua_media_config_ptime_get", "(JLorg/pjsip/pjsua/pjsua_media_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1ptime_1get},
{"pjsua_media_config_no_vad_set", "(JLorg/pjsip/pjsua/pjsua_media_config;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1no_1vad_1set},
{"pjsua_media_config_no_vad_get", "(JLorg/pjsip/pjsua/pjsua_media_config;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1no_1vad_1get},
{"pjsua_media_config_ilbc_mode_set", "(JLorg/pjsip/pjsua/pjsua_media_config;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1ilbc_1mode_1set},
{"pjsua_media_config_ilbc_mode_get", "(JLorg/pjsip/pjsua/pjsua_media_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1ilbc_1mode_1get},
{"pjsua_media_config_tx_drop_pct_set", "(JLorg/pjsip/pjsua/pjsua_media_config;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1tx_1drop_1pct_1set},
{"pjsua_media_config_tx_drop_pct_get", "(JLorg/pjsip/pjsua/pjsua_media_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1tx_1drop_1pct_1get},
{"pjsua_media_config_rx_drop_pct_set", "(JLorg/pjsip/pjsua/pjsua_media_config;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1rx_1drop_1pct_1set},
{"pjsua_media_config_rx_drop_pct_get", "(JLorg/pjsip/pjsua/pjsua_media_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1rx_1drop_1pct_1get},
{"pjsua_media_config_ec_options_set", "(JLorg/pjsip/pjsua/pjsua_media_config;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1ec_1options_1set},
{"pjsua_media_config_ec_options_get", "(JLorg/pjsip/pjsua/pjsua_media_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1ec_1options_1get},
{"pjsua_media_config_ec_tail_len_set", "(JLorg/pjsip/pjsua/pjsua_media_config;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1ec_1tail_1len_1set},
{"pjsua_media_config_ec_tail_len_get", "(JLorg/pjsip/pjsua/pjsua_media_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1ec_1tail_1len_1get},
{"pjsua_media_config_snd_rec_latency_set", "(JLorg/pjsip/pjsua/pjsua_media_config;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1snd_1rec_1latency_1set},
{"pjsua_media_config_snd_rec_latency_get", "(JLorg/pjsip/pjsua/pjsua_media_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1snd_1rec_1latency_1get},
{"pjsua_media_config_snd_play_latency_set", "(JLorg/pjsip/pjsua/pjsua_media_config;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1snd_1play_1latency_1set},
{"pjsua_media_config_snd_play_latency_get", "(JLorg/pjsip/pjsua/pjsua_media_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1snd_1play_1latency_1get},
{"pjsua_media_config_jb_init_set", "(JLorg/pjsip/pjsua/pjsua_media_config;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1jb_1init_1set},
{"pjsua_media_config_jb_init_get", "(JLorg/pjsip/pjsua/pjsua_media_config;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1jb_1init_1get},
{"pjsua_media_config_jb_min_pre_set", "(JLorg/pjsip/pjsua/pjsua_media_config;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1jb_1min_1pre_1set},
{"pjsua_media_config_jb_min_pre_get", "(JLorg/pjsip/pjsua/pjsua_media_config;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1jb_1min_1pre_1get},
{"pjsua_media_config_jb_max_pre_set", "(JLorg/pjsip/pjsua/pjsua_media_config;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1jb_1max_1pre_1set},
{"pjsua_media_config_jb_max_pre_get", "(JLorg/pjsip/pjsua/pjsua_media_config;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1jb_1max_1pre_1get},
{"pjsua_media_config_jb_max_set", "(JLorg/pjsip/pjsua/pjsua_media_config;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1jb_1max_1set},
{"pjsua_media_config_jb_max_get", "(JLorg/pjsip/pjsua/pjsua_media_config;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1jb_1max_1get},
{"pjsua_media_config_enable_ice_set", "(JLorg/pjsip/pjsua/pjsua_media_config;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1enable_1ice_1set},
{"pjsua_media_config_enable_ice_get", "(JLorg/pjsip/pjsua/pjsua_media_config;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1enable_1ice_1get},
{"pjsua_media_config_ice_max_host_cands_set", "(JLorg/pjsip/pjsua/pjsua_media_config;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1ice_1max_1host_1cands_1set},
{"pjsua_media_config_ice_max_host_cands_get", "(JLorg/pjsip/pjsua/pjsua_media_config;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1ice_1max_1host_1cands_1get},
{"pjsua_media_config_ice_opt_set", "(JLorg/pjsip/pjsua/pjsua_media_config;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1ice_1opt_1set},
{"pjsua_media_config_ice_opt_get", "(JLorg/pjsip/pjsua/pjsua_media_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1ice_1opt_1get},
{"pjsua_media_config_ice_no_rtcp_set", "(JLorg/pjsip/pjsua/pjsua_media_config;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1ice_1no_1rtcp_1set},
{"pjsua_media_config_ice_no_rtcp_get", "(JLorg/pjsip/pjsua/pjsua_media_config;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1ice_1no_1rtcp_1get},
{"pjsua_media_config_enable_turn_set", "(JLorg/pjsip/pjsua/pjsua_media_config;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1enable_1turn_1set},
{"pjsua_media_config_enable_turn_get", "(JLorg/pjsip/pjsua/pjsua_media_config;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1enable_1turn_1get},
{"pjsua_media_config_turn_server_set", "(JLorg/pjsip/pjsua/pjsua_media_config;JLorg/pjsip/pjsua/pj_str_t;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1turn_1server_1set},
{"pjsua_media_config_turn_server_get", "(JLorg/pjsip/pjsua/pjsua_media_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1turn_1server_1get},
{"pjsua_media_config_turn_conn_type_set", "(JLorg/pjsip/pjsua/pjsua_media_config;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1turn_1conn_1type_1set},
{"pjsua_media_config_turn_conn_type_get", "(JLorg/pjsip/pjsua/pjsua_media_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1turn_1conn_1type_1get},
{"pjsua_media_config_turn_auth_cred_set", "(JLorg/pjsip/pjsua/pjsua_media_config;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1turn_1auth_1cred_1set},
{"pjsua_media_config_turn_auth_cred_get", "(JLorg/pjsip/pjsua/pjsua_media_config;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1turn_1auth_1cred_1get},
{"pjsua_media_config_snd_auto_close_time_set", "(JLorg/pjsip/pjsua/pjsua_media_config;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1snd_1auto_1close_1time_1set},
{"pjsua_media_config_snd_auto_close_time_get", "(JLorg/pjsip/pjsua/pjsua_media_config;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1config_1snd_1auto_1close_1time_1get},
{"new_pjsua_media_config", "()J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_new_1pjsua_1media_1config},
{"delete_pjsua_media_config", "(J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_delete_1pjsua_1media_1config},
{"media_config_default", "(JLorg/pjsip/pjsua/pjsua_media_config;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_media_1config_1default},
{"pjsua_codec_info_codec_id_set", "(JLorg/pjsip/pjsua/pjsua_codec_info;JLorg/pjsip/pjsua/pj_str_t;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1codec_1info_1codec_1id_1set},
{"pjsua_codec_info_codec_id_get", "(JLorg/pjsip/pjsua/pjsua_codec_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1codec_1info_1codec_1id_1get},
{"pjsua_codec_info_priority_set", "(JLorg/pjsip/pjsua/pjsua_codec_info;S)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1codec_1info_1priority_1set},
{"pjsua_codec_info_priority_get", "(JLorg/pjsip/pjsua/pjsua_codec_info;)S", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1codec_1info_1priority_1get},
{"pjsua_codec_info_buf__set", "(JLorg/pjsip/pjsua/pjsua_codec_info;Ljava/lang/String;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1codec_1info_1buf_1_1set},
{"pjsua_codec_info_buf__get", "(JLorg/pjsip/pjsua/pjsua_codec_info;)Ljava/lang/String;", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1codec_1info_1buf_1_1get},
{"new_pjsua_codec_info", "()J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_new_1pjsua_1codec_1info},
{"delete_pjsua_codec_info", "(J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_delete_1pjsua_1codec_1info},
{"pjsua_conf_port_info_slot_id_set", "(JLorg/pjsip/pjsua/pjsua_conf_port_info;I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1conf_1port_1info_1slot_1id_1set},
{"pjsua_conf_port_info_slot_id_get", "(JLorg/pjsip/pjsua/pjsua_conf_port_info;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1conf_1port_1info_1slot_1id_1get},
{"pjsua_conf_port_info_name_set", "(JLorg/pjsip/pjsua/pjsua_conf_port_info;JLorg/pjsip/pjsua/pj_str_t;)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1conf_1port_1info_1name_1set},
{"pjsua_conf_port_info_name_get", "(JLorg/pjsip/pjsua/pjsua_conf_port_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1conf_1port_1info_1name_1get},
{"pjsua_conf_port_info_clock_rate_set", "(JLorg/pjsip/pjsua/pjsua_conf_port_info;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1conf_1port_1info_1clock_1rate_1set},
{"pjsua_conf_port_info_clock_rate_get", "(JLorg/pjsip/pjsua/pjsua_conf_port_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1conf_1port_1info_1clock_1rate_1get},
{"pjsua_conf_port_info_channel_count_set", "(JLorg/pjsip/pjsua/pjsua_conf_port_info;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1conf_1port_1info_1channel_1count_1set},
{"pjsua_conf_port_info_channel_count_get", "(JLorg/pjsip/pjsua/pjsua_conf_port_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1conf_1port_1info_1channel_1count_1get},
{"pjsua_conf_port_info_samples_per_frame_set", "(JLorg/pjsip/pjsua/pjsua_conf_port_info;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1conf_1port_1info_1samples_1per_1frame_1set},
{"pjsua_conf_port_info_samples_per_frame_get", "(JLorg/pjsip/pjsua/pjsua_conf_port_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1conf_1port_1info_1samples_1per_1frame_1get},
{"pjsua_conf_port_info_bits_per_sample_set", "(JLorg/pjsip/pjsua/pjsua_conf_port_info;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1conf_1port_1info_1bits_1per_1sample_1set},
{"pjsua_conf_port_info_bits_per_sample_get", "(JLorg/pjsip/pjsua/pjsua_conf_port_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1conf_1port_1info_1bits_1per_1sample_1get},
{"pjsua_conf_port_info_listener_cnt_set", "(JLorg/pjsip/pjsua/pjsua_conf_port_info;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1conf_1port_1info_1listener_1cnt_1set},
{"pjsua_conf_port_info_listener_cnt_get", "(JLorg/pjsip/pjsua/pjsua_conf_port_info;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1conf_1port_1info_1listener_1cnt_1get},
{"pjsua_conf_port_info_listeners_set", "(JLorg/pjsip/pjsua/pjsua_conf_port_info;[I)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1conf_1port_1info_1listeners_1set},
{"new_pjsua_conf_port_info", "()J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_new_1pjsua_1conf_1port_1info},
{"delete_pjsua_conf_port_info", "(J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_delete_1pjsua_1conf_1port_1info},
{"pjsua_media_transport_skinfo_set", "(JLorg/pjsip/pjsua/pjsua_media_transport;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1transport_1skinfo_1set},
{"pjsua_media_transport_skinfo_get", "(JLorg/pjsip/pjsua/pjsua_media_transport;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1transport_1skinfo_1get},
{"pjsua_media_transport_transport_set", "(JLorg/pjsip/pjsua/pjsua_media_transport;J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1transport_1transport_1set},
{"pjsua_media_transport_transport_get", "(JLorg/pjsip/pjsua/pjsua_media_transport;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_pjsua_1media_1transport_1transport_1get},
{"new_pjsua_media_transport", "()J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_new_1pjsua_1media_1transport},
{"delete_pjsua_media_transport", "(J)V", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_delete_1pjsua_1media_1transport},
{"conf_get_max_ports", "()J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_conf_1get_1max_1ports},
{"conf_get_active_ports", "()J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_conf_1get_1active_1ports},
{"enum_conf_ports", "([I[J)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_enum_1conf_1ports},
{"conf_get_port_info", "(IJLorg/pjsip/pjsua/pjsua_conf_port_info;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_conf_1get_1port_1info},
{"conf_add_port", "(JLorg/pjsip/pjsua/pj_pool_t;JLorg/pjsip/pjsua/pjmedia_port;[I)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_conf_1add_1port},
{"conf_remove_port", "(I)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_conf_1remove_1port},
{"conf_connect", "(II)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_conf_1connect},
{"conf_disconnect", "(II)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_conf_1disconnect},
{"conf_adjust_tx_level", "(IF)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_conf_1adjust_1tx_1level},
{"conf_adjust_rx_level", "(IF)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_conf_1adjust_1rx_1level},
{"conf_get_signal_level", "(IJJ)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_conf_1get_1signal_1level},
{"player_create", "(JLorg/pjsip/pjsua/pj_str_t;JJ)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_player_1create},
{"playlist_create", "([JJJLorg/pjsip/pjsua/pj_str_t;JJ)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_playlist_1create},
{"player_get_conf_port", "(I)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_player_1get_1conf_1port},
{"player_get_port", "(IJ)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_player_1get_1port},
{"player_set_pos", "(IJ)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_player_1set_1pos},
{"player_destroy", "(I)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_player_1destroy},
{"recorder_create", "(JLorg/pjsip/pjsua/pj_str_t;J[BJJJ)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_recorder_1create},
{"recorder_get_conf_port", "(I)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_recorder_1get_1conf_1port},
{"recorder_get_port", "(IJ)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_recorder_1get_1port},
{"recorder_destroy", "(I)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_recorder_1destroy},
{"enum_aud_devs", "(J[J)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_enum_1aud_1devs},
{"enum_snd_devs", "(JLorg/pjsip/pjsua/pjmedia_snd_dev_info;[J)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_enum_1snd_1devs},
{"get_snd_dev", "([I[I)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_get_1snd_1dev},
{"set_snd_dev", "(II)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_set_1snd_1dev},
{"set_null_snd_dev", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_set_1null_1snd_1dev},
{"set_no_snd_dev", "()J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_set_1no_1snd_1dev},
{"set_ec", "(JJ)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_set_1ec},
{"get_ec_tail", "(J)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_get_1ec_1tail},
{"snd_is_active", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_snd_1is_1active},
{"snd_set_setting", "(J[BI)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_snd_1set_1setting},
{"snd_get_setting", "(J[B)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_snd_1get_1setting},
{"enum_codecs", "(JLorg/pjsip/pjsua/pjsua_codec_info;[J)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_enum_1codecs},
{"codec_set_priority", "(JLorg/pjsip/pjsua/pj_str_t;S)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_codec_1set_1priority},
{"codec_get_param", "(JLorg/pjsip/pjsua/pj_str_t;J)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_codec_1get_1param},
{"codec_set_param", "(JLorg/pjsip/pjsua/pj_str_t;J)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_codec_1set_1param},
{"media_transports_create", "(JLorg/pjsip/pjsua/pjsua_transport_config;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_media_1transports_1create},
{"codecs_get_nbr", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_codecs_1get_1nbr},
{"codecs_get_id", "(I)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_codecs_1get_1id},
{"test_audio_dev", "(JJ)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_test_1audio_1dev},
{"send_dtmf_info", "(IJLorg/pjsip/pjsua/pj_str_t;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_send_1dtmf_1info},
{"call_dump__SWIG_1", "(IILjava/lang/String;)J", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_call_1dump_1_1SWIG_11},
{"can_use_tls", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_can_1use_1tls},
{"can_use_srtp", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_can_1use_1srtp},
{"media_transports_create_ipv6", "(JLorg/pjsip/pjsua/pjsua_transport_config;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_media_1transports_1create_1ipv6},
{"csipsimple_init", "(JLorg/pjsip/pjsua/pjsua_config;JLorg/pjsip/pjsua/pjsua_logging_config;JLorg/pjsip/pjsua/pjsua_media_config;)I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_csipsimple_1init},
{"csipsimple_destroy", "()I", (void*)& Java_org_pjsip_pjsua_pjsuaJNI_csipsimple_1destroy}

	};

	r = env->RegisterNatives (k, methods, NELEM(methods));
	return JNI_VERSION_1_4;
}
