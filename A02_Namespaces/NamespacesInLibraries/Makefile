include ../../Build/make.mk




all: main


$(EXECUTABLES): %.exe: %.cpp ;

main: $(OBJECTS)
	$(CC) $(CFLAGS) $(SOURCES) -o $@
#	mv Test all
	

