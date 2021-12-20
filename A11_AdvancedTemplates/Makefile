WARNINGS := -Wno-unused-variable
export WARNINGS

all: subsystems

subsystems:
	cd 1_MetaPrograms && $(MAKE)
	cd 2_Specialization && $(MAKE)
	cd 3_Traits && $(MAKE)
	cd 4_VariadicTemplates && $(MAKE)
	cd 5_Miscellaneous && $(MAKE)
	
clean:
	@cd 1_MetaPrograms && $(MAKE) clean
	@cd 2_Specialization && $(MAKE) clean
	@cd 3_Traits && $(MAKE) clean
	@cd 4_VariadicTemplates && $(MAKE) clean
	@cd 5_Miscellaneous && $(MAKE) clean
