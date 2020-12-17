LFLAGS = -lpthread
export LFLAGS
include ../../_Build/make.mk

all:: subsystems

subsystems:
	cd RandomNumbers && $(MAKE)

clean::
	cd RandomNumbers && $(MAKE) clean
	


