#!/bin/sh

usage() {
	echo -n "Usage: $0 [-h] [-d]\n-h : show this help\n-d : turn debugging on\n" 
} 

MAKE_FLAGS=""
VERSION="undefined"
ACTION=""

while getopts dhcv: arg
do	case "$arg" in
	d)	MAKE_FLAGS="NDK_LOG=true V=1";;
	h)	usage
		exit 0;;
	c)	ACTION="clean";;
	v)  VERSION="$OPTARG";;
	[?])	usage	
		exit 1;;
	esac
done

for target_path in build/platforms/*; do
	TARGET_PLATEFORM=`basename $target_path`
	OUT_BUILD_PATH="apps/pjsip/project/libs/armeabi/$TARGET_PLATEFORM"
	rm $OUT_BUILD_PATH/*
	
	#Build the stack
	echo "Make for $TARGET_PLATEFORM"
	make APP=pjsip APP_PLATFORM=$TARGET_PLATEFORM $MAKE_FLAGS $ACTION
	
	#create bundle and md5 for publish
	OUT_NAME=${TARGET_PLATEFORM}_libpjsipjni-${VERSION}.so.gz
	OUT_TGZ=$OUT_BUILD_PATH/$OUT_NAME
	echo "Create bundle $OUT_NAME"
	gzip -c $OUT_BUILD_PATH/libpjsipjni.so > $OUT_TGZ
	md5sum $OUT_TGZ > $OUT_BUILD_PATH/$OUT_NAME.md5sum
done

