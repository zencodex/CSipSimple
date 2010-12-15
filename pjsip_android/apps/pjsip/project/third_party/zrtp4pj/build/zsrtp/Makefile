# Adapt this path to your pjproject path

export PJDIR := ~/devhome/pjproject-1.8.5

include $(PJDIR)/build.mak
include $(PJDIR)/build/common.mak

export LIBDIR := ../../lib

RULES_MAK := $(PJDIR)/build/rules.mak

export ZSRTP_LIB := ../../lib/libzsrtp-$(TARGET_NAME)$(LIBEXT)

###############################################################################
# Gather all flags.
#
export _CFLAGS 	:= $(CC_INC). $(CC_INC)../../zsrtp/include \
		   $(CC_INC)../../zsrtp/include/crypto \
		   $(CC_INC)$(PJDIR)/pjlib/include \
		   $(CC_INC)$(PJDIR)/pjlib-util/include \
		   $(CC_INC)$(PJDIR)/pjmedia/include \
		   $(CC_CFLAGS) $(OS_CFLAGS) $(HOST_CFLAGS) $(M_CFLAGS) \
		   $(CFLAGS) 
export _CXXFLAGS:= $(_CFLAGS) $(CC_CXXFLAGS) $(OS_CXXFLAGS) $(M_CXXFLAGS) \
		   $(HOST_CXXFLAGS) $(CXXFLAGS)
export _LDFLAGS := $(CC_LDFLAGS) $(OS_LDFLAGS) $(M_LDFLAGS) $(HOST_LDFLAGS) \
		   $(LDFLAGS) 

ciphersossl = crypto/openssl/AesSrtp.o crypto/openssl/hmac.o \
    crypto/openssl/ZrtpDH.o \
    crypto/openssl/hmac256.o \
    crypto/openssl/sha256.o \
    crypto/openssl/hmac384.o \
    crypto/openssl/sha384.o \
    crypto/openssl/AesCFB.o 


# Gcrypt support currently not tested
#ciphersgcrypt = crypto/gcrypt/gcryptAesSrtp.o crypto/gcrypt/gcrypthmac.o \
#          crypto/gcrypt/InitializeGcrypt.o

zrtpobj = zrtp/ZrtpCallbackWrapper.o \
    zrtp/ZIDFile.o \
    zrtp/ZIDRecord.o \
    zrtp/ZRtp.o \
    zrtp/ZrtpCrc32.o \
    zrtp/ZrtpPacketCommit.o \
    zrtp/ZrtpPacketConf2Ack.o \
    zrtp/ZrtpPacketConfirm.o \
    zrtp/ZrtpPacketDHPart.o \
    zrtp/ZrtpPacketGoClear.o \
    zrtp/ZrtpPacketClearAck.o \
    zrtp/ZrtpPacketHelloAck.o \
    zrtp/ZrtpPacketHello.o \
    zrtp/ZrtpPacketError.o \
    zrtp/ZrtpPacketErrorAck.o \
    zrtp/ZrtpPacketPingAck.o \
    zrtp/ZrtpPacketPing.o \
    zrtp/ZrtpStateClass.o \
    zrtp/ZrtpTextData.o \
    zrtp/ZrtpConfigure.o \
    zrtp/ZrtpCWrapper.o \
    zrtp/Base32.o

srtpobj = srtp/ZsrtpCWrapper.o srtp/CryptoContext.o

transportobj = transport_zrtp.o

cryptobj =  $(ciphersossl)

export ZSRTP_SRCDIR = ../../zsrtp
export ZSRTP_OBJS = $(zrtpobj) $(cryptobj) $(srtpobj) $(srtpobj) $(transportobj)
export ZSRTP_CFLAGS = $(_CFLAGS)
export ZSRTP_CXXFLAGS = $(_CXXFLAGS)

#path := `pwd`

export CC_OUT CC AR RANLIB HOST_MV HOST_RM HOST_RMDIR HOST_MKDIR OBJEXT LD LDOUT
###############################################################################
# Main entry
#
# $(TARGET) is defined in os-$(OS_NAME).mak file in current directory.
#
TARGETS := libzsrtp

all: $(TARGETS)

doc:
	cd .. && doxygen docs/doxygen.cfg

dep: depend
distclean: realclean

.PHONY: dep depend libsrtp clean realclean distclean

libzsrtp:
	rm -f build.mak
	$(MAKE) -f $(RULES_MAK) APP=ZSRTP app=libzsrtp $(ZSRTP_LIB)
	echo 'export PJ_CFLAGS := $(PJ_CFLAGS)' -I`pwd`/../../zsrtp/include >> build.mak
	echo 'export PJ_LDFLAGS := $(PJ_LDFLAGS)' -L`pwd`/../../lib/ >> build.mak
	echo  export PJ_LDLIBS := -lzsrtp-$(TARGET_NAME) $(PJ_LDLIBS) >> build.mak

clean print_lib:
	$(MAKE) -f $(RULES_MAK) APP=ZSRTP app=libzsrtp $@

realclean:
	$(subst @@,$(subst /,$(HOST_PSEP),.ilbc-$(TARGET_NAME).depend),$(HOST_RMR))
	
	$(MAKE) -f $(RULES_MAK) APP=ZSRTP app=libzsrtp $@

depend:
	$(MAKE) -f $(RULES_MAK) APP=ZSRTP app=libzsrtp $@



