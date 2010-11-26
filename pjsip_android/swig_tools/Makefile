#

PJSIP_DIR=$(CURDIR)/../apps/pjsip/project
PJSUA_HEADER=${PJSIP_DIR}/pjsip/include/pjsua-lib/pjsua.h 
ADDONS_HEADER=${PJSIP_DIR}/jni/pjsua_jni_addons.h
LINUX_INCLUDE=-I /usr/lib/jvm/java-6-sun/include -I /usr/lib/jvm/java-6-sun/include/linux -I ${PJSIP_DIR}/pjsip/include -I ${PJSIP_DIR}/jni/
LINUX_LIBDIR=
CFLAGS=-DPJMEDIA_HAS_SRTP=1 -DPJ_HAS_SSL_SOCK=1

all : nativesrc/pjsua_wrap.cpp 

nativesrc/pjsua_wrap.cpp : pjsua.i
	mkdir -p nativesrc
	mkdir -p src/org/pjsip/pjsua
	swig ${CFLAGS} -Wall -o nativesrc/pjsua_wrap.cpp -outdir src/org/pjsip/pjsua -java -package org.pjsip.pjsua -c++ pjsua.i 
	#Disable rtti
	sed -i 's/dynamic_cast<SwigDirector_Callback \*>/(SwigDirector_Callback*)/' nativesrc/pjsua_wrap.cpp
	#Build pj loader
	./JavaJNI2CJNI_Load.py -i src/org/pjsip/pjsua/pjsuaJNI.java -o nativesrc/pj_loader.c -t ./pj_loader.c.template
	cat nativesrc/pj_loader.c >> nativesrc/pjsua_wrap.cpp
	rm nativesrc/pj_loader.c


pjsua.i : ${PJSUA_HEADER} pjsua.i_header
	echo > pjsua.i_body
	cat ${PJSUA_HEADER} | ./strip_comments.pl | ./strip_unnecessary_stuff.pl | ./strip_unwanted_stuff.pl | ./strip_double_typedef_name.pl | ./delete_blank_lines.sh | ./add_swig_rename.pl >> pjsua.i_body
	cat ${ADDONS_HEADER} | ./strip_comments.pl | ./strip_unnecessary_stuff.pl | ./strip_unwanted_stuff.pl | ./strip_double_typedef_name.pl | ./delete_blank_lines.sh | ./add_swig_rename.pl >> pjsua.i_body
	cat pjsua.i_header pjsua.i_body > pjsua.i
	rm pjsua.i_body || true
	
clean :
	#-del nativesrc/net_sourceforge_iaxclient_jni_LibJiaxc.h libjiaxc.so jiaxc.o
	rm pjsua.i nativesrc/pjsua_wrap.cpp src/org/pjsip/pjsua/*.java pjsua_wrap.o pjsua_wrap_win.o libpjsua_jni.so || true
