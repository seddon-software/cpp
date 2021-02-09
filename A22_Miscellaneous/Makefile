LFLAGS = -lpthread
export LFLAGS
include ../Build/make.mk

all: subsystems

subsystems:
	cd RandomNumbers && $(MAKE)

clean:
	cd RandomNumbers && $(MAKE) clean
	


