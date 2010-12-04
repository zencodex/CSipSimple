#!/bin/sh

# include common function and variable definitions
. `dirname $0`/prebuilt-common.sh

if [ "x$1" = "x" ]; then
    dump "ERROR: missing NDK_DIR parameter"
    exit 1
fi

NDK_DIR=$1
cd $NDK_DIR
NDK_DIR=`pwd`

ARCH_armeabi=arm
ARCH_x86=x86

if [ "x$NDK_DIR" != "x$ANDROID_NDK_ROOT" ]; then
    mkdir -p $NDK_DIR/build

    for i in `ls -1 $ANDROID_NDK_ROOT/build | grep -v prebuilt`; do
        rm -Rf $NDK_DIR/build/$i
        cp -R $ANDROID_NDK_ROOT/build/$i $NDK_DIR/build
    done

    rm -Rf $NDK_DIR/samples
    mkdir -p $NDK_DIR/samples
    cp -R $ANDROID_NDK_ROOT/samples/missing $NDK_DIR/samples

    cp -f $ANDROID_NDK_ROOT/ndk-build $NDK_DIR
fi

cd $NDK_DIR/samples/missing

#ABI_LIST="armeabi x86"
ABI_LIST=armeabi

PLATFORMS=`ls -1 $ANDROID_NDK_ROOT/build/platforms`
for abi in $ABI_LIST; do
    for p in $PLATFORMS; do
        eval dir=\$ARCH_$abi
        if [ -d $ANDROID_NDK_ROOT/build/platforms/$p/arch-$dir ]; then
            $NDK_DIR/ndk-build -B V=1 TARGET_PLATFORM=$p TARGET_ARCH_ABI=$abi
            dest=$ANDROID_NDK_ROOT/build/platforms/$p/arch-$dir/usr/lib/libmissing.a
            rm -Rf $dest
            cp obj/local/$abi/libmissing.a $dest
        fi
    done
done
rm -Rf obj

cd $NDK_DIR
if [ "x$NDK_DIR" != "x$ANDROID_NDK_ROOT" ]; then
    for i in `ls -1 $NDK_DIR/build | grep -v prebuilt`; do
        rm -Rf $NDK_DIR/build/$i
    done
    rm -Rf $NDK_DIR/samples $NDK_DIR/ndk-build
fi
