#!/bin/sh
ls src/org/pjsip/pjsua/SWIGTYPE_p_* | grep -v '^SWIGTYPE_p_f_' | sed 's/SWIGTYPE_p_//;s/\.java//; s/src\/org\/pjsip\/pjsua\///' | grep -v -e '^f_' -e '^void$' -e '^unsigned_int$' -e '^int$'
