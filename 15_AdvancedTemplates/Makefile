WARNINGS := -Wno-unused-variable
export WARNINGS

all: subsystems

subsystems:
	cd ExpressionTemplates && $(MAKE)
	cd MetaPrograms && $(MAKE)
	cd Miscellaneous && $(MAKE)
	cd SFINAE && $(MAKE)
	cd TemplateTemplateParameters && $(MAKE)
	cd Traits && $(MAKE)
	cd Typelists && $(MAKE)
	
clean:
	@cd ExpressionTemplates && $(MAKE) clean
	@cd MetaPrograms && $(MAKE) clean
	@cd Miscellaneous && $(MAKE) clean
	@cd SFINAE && $(MAKE) clean
	@cd TemplateTemplateParameters && $(MAKE) clean
	@cd Traits && $(MAKE) clean
	@cd Typelists && $(MAKE) clean
	
	
