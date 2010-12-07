#!/bin/bash

usage() {
	echo -n "Usage: $0 [-h] [-d] [-t target abi] [-v version]\n-h : show this help\n-d : turn debugging on\n-t specify target eabis\n" 
}


MAKE_FLAGS=""
VERSION="undefined"
ACTION=""
TARGETS="armeabi armeabi-v7a"

while getopts dhcv:t: arg
do	case "$arg" in
	d)	MAKE_FLAGS="NDK_LOG=true V=1";;
	h)	usage
		exit 0;;
	c)	ACTION="clean";;
	v)	VERSION="$OPTARG";;
	t)	TARGETS="$OPTARG";;
	[?])	usage	
		exit 1;;
	esac
done

$old_IFS = $IFS
IFS=" "

for abi in $TARGETS; do
	#Use the supported platform
	platform="android-8"
	if [[ $abi == "armv4t" ]]; then
		platform="android-3"
	elif [[ $abi == "x86" ]]; then
		platform="android-8"
	elif [[ $abi == "armeabi-v7a" ]]; then
		platform="android-8"
	fi
	#Build the stack
	echo "Make for $abi using $platform"
	make APP=pjsip APP_ABI=$abi APP_PLATFORM=$platform $MAKE_FLAGS $ACTION


	#create bundle and md5 for publish
	OUT_BUILD_PATH="apps/pjsip/project/libs/$abi"
	OUT_NAME=android-${abi}_libpjsipjni-${VERSION}.so.gz
	OUT_TGZ=$OUT_BUILD_PATH/$OUT_NAME

	if [[ $ACTION == "clean" ]]; then
		rm $OUT_TGZ*
	else
		echo "Create bundle $OUT_NAME"
		gzip -c $OUT_BUILD_PATH/libpjsipjni.so > $OUT_TGZ
		md5sum $OUT_TGZ > $OUT_BUILD_PATH/$OUT_NAME.md5sum
	fi
done

IFS=$old_IFS
