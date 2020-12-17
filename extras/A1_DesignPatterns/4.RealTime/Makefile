all: subsystems

subsystems:
	@cd Barriers && $(MAKE)
	@cd Deadlock && $(MAKE)
	@cd StateMachine && $(MAKE)
	@cd ThreadPools && $(MAKE)
	@cd ThreadsRunnable && $(MAKE)
	@cd TreadsInheritance && $(MAKE)
	

clean:
	@cd Barriers && $(MAKE) clean
	@cd Deadlock && $(MAKE) clean
	@cd StateMachine && $(MAKE) clean
	@cd ThreadPools && $(MAKE) clean
	@cd ThreadsRunnable && $(MAKE) clean
	@cd TreadsInheritance && $(MAKE) clean


