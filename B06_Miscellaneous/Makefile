include ../Build/make.mk


all: subsystems

descend = @echo "\n\n$(1)\n"; cd $(1) && pwd && $(MAKE) -i
clobber = cd $(1) && $(MAKE) -i clean

subsystems:
	$(call descend,RandomNumbers)

clean::
	$(call clobber,RandomNumbers)

