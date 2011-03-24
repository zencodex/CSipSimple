#

PJSIP_DIR=$(CURDIR)/../apps/pjsip/project
PJSUA_HEADERS=${PJSIP_DIR}/pjsip/include/pjsua-lib/pjsua.h ${PJSIP_DIR}/jni/include/pjsua_jni_addons.h ${PJSIP_DIR}/jni/include/zrtp_android.h #${PJSIP_DIR}/jni/include/opengl_video_dev.h
LINUX_INCLUDE=-I /usr/lib/jvm/java-6-sun/include -I /usr/lib/jvm/java-6-sun/include/linux -I ${PJSIP_DIR}/pjsip/include -I ${PJSIP_DIR}/jni/include
LINUX_LIBDIR=
CFLAGS=-DPJMEDIA_HAS_SRTP=1 -DPJ_HAS_SSL_SOCK=1 -DPJMEDIA_HAS_ZRTP=1
SWIG=swig2.0

all : nativesrc/pjsua_wrap.cpp 

nativesrc/pjsua_wrap.cpp : pjsua.i
	mkdir -p nativesrc
	mkdir -p src/org/pjsip/pjsua
	${SWIG} ${CFLAGS} -Wall -o nativesrc/pjsua_wrap.cpp -outdir src/org/pjsip/pjsua -java -package org.pjsip.pjsua -c++ pjsua.i 
	#Clean source for android target // TODO : condition
	./clean_source_for_android.py nativesrc/pjsua_wrap.cpp > nativesrc/pjsua_wrap.cpp.tmp
	mv nativesrc/pjsua_wrap.cpp.tmp nativesrc/pjsua_wrap.cpp
	#Build pj loader
	./JavaJNI2CJNI_Load.py -i src/org/pjsip/pjsua/pjsuaJNI.java -o nativesrc/pj_loader.c -t ./pj_loader.c.template
	cat nativesrc/pj_loader.c >> nativesrc/pjsua_wrap.cpp
	rm nativesrc/pj_loader.c


pjsua.i : ${PJSUA_HEADERS} pjsua.i_header
	echo > pjsua.i_body
	for f in ${PJSUA_HEADERS}; do ./clean_header_for_swig.py $$f >> pjsua.i_body; done
	cat pjsua.i_header pjsua.i_body > pjsua.i
	rm pjsua.i_body || true
	
clean :
	#-del nativesrc/net_sourceforge_iaxclient_jni_LibJiaxc.h libjiaxc.so jiaxc.o
	rm pjsua.i nativesrc/pjsua_wrap.cpp src/org/pjsip/pjsua/*.java pjsua_wrap.o pjsua_wrap_win.o libpjsua_jni.so || true
