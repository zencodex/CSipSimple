#!/bin/sh

if [ "x$ANDROID_NDK_ROOT" = "x" ]; then
    cd `dirname $0`/../..
    ANDROID_NDK_ROOT=`pwd`
fi

CPPHEADERS="cstddef cassert cctype cerrno cfloat climits cmath csetjmp csignal"
CPPHEADERS="$CPPHEADERS cstdint cstdio cstdlib cstring ctime cwchar"
CPPHEADERS="$CPPHEADERS cwctype_is_not_supported new stl_pair.h typeinfo utility"
for i in $CPPHEADERS libstdc++.a libstdc++.so
do
    find $ANDROID_NDK_ROOT/build/platforms -name $i -exec rm -f '{}' \;
done
