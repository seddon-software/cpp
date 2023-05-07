include ../Build/make.mk




all: subsystems

subsystems:
	@echo "\n\n";cd 01.InterfaceModules && $(MAKE) -i
	@echo "\n\n";cd 02.ModulePartitions && $(MAKE) -i
	@echo "\n\n";cd 03.SubModules && $(MAKE) -i
	@echo "\n\n";cd 04.ImplementationModules && $(MAKE) -i

clean::
	@echo "\n\n";cd 01.InterfaceModules && $(MAKE) -i clean
	@echo "\n\n";cd 02.ModulePartitions && $(MAKE) -i clean
	@echo "\n\n";cd 03.SubModules && $(MAKE) -i clean
	@echo "\n\n";cd 04.ImplementationModules && $(MAKE) -i clean


