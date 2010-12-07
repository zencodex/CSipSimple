include ../../../build.mak
include ../../../build/common.mak

export LIBDIR := ../../lib

RULES_MAK := $(PJDIR)/build/rules.mak

export ZSRTP_LIB := ../../lib/libzsrtp-$(TARGET_NAME)$(LIBEXT)

###############################################################################
# Gather all flags.
#
export _CFLAGS 	:= $(CC_INC). $(CC_INC)../../zsrtp/include \
		   $(CC_INC)../../zsrtp/include/crypto \
		   $(CC_INC)../../../pjlib/include \
		   $(CC_INC)../../../pjmedia/include \
		   $(CC_CFLAGS) $(OS_CFLAGS) $(HOST_CFLAGS) $(M_CFLAGS) \
		   $(CFLAGS) 
export _CXXFLAGS:= $(_CFLAGS) $(CC_CXXFLAGS) $(OS_CXXFLAGS) $(M_CXXFLAGS) \
		   $(HOST_CXXFLAGS) $(CXXFLAGS)
export _LDFLAGS := $(CC_LDFLAGS) $(OS_LDFLAGS) $(M_LDFLAGS) $(HOST_LDFLAGS) \
		   $(LDFLAGS) 

ciphersossl = crypto/openssl/AesSrtp.o crypto/openssl/hmac.o

# Gcrypt support currently not tested
#ciphersgcrypt = crypto/gcrypt/gcryptAesSrtp.o crypto/gcrypt/gcrypthmac.o \
#          crypto/gcrypt/InitializeGcrypt.o

cwrapper = ZsrtpCWrapper.o

zsrtpobj = CryptoContext.o 

cryptobj =  $(ciphersossl)

export ZSRTP_SRCDIR = ../../zsrtp
export ZSRTP_OBJS = $(cryptobj) $(cwrapper) $(zsrtpobj)
export ZSRTP_CFLAGS = $(_CFLAGS)
export ZSRTP_CXXFLAGS = $(_CXXFLAGS)


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
	$(MAKE) -f $(RULES_MAK) APP=ZSRTP app=libzsrtp $(ZSRTP_LIB)

clean print_lib:
	$(MAKE) -f $(RULES_MAK) APP=ZSRTP app=libzsrtp $@

realclean:
	$(subst @@,$(subst /,$(HOST_PSEP),.ilbc-$(TARGET_NAME).depend),$(HOST_RMR))
	
	$(MAKE) -f $(RULES_MAK) APP=ZSRTP app=libzsrtp $@

depend:
	$(MAKE) -f $(RULES_MAK) APP=ZSRTP app=libzsrtp $@



