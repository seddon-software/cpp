# In this makefile we compile one file at a time.  This is because some files create modules
# which need to be built before they are imported

CC := g++
CFLAGS :=-g -c -fPIE -std=c++20 -fmodules-ts
SYSTEM_HEADER := -x c++-system-header

01.main.exe: OBJECTS = $(patsubst %.cpp,%.o,$(wildcard 01.*.cpp))
02.main.exe: OBJECTS = $(patsubst %.cpp,%.o,$(wildcard 02.*.cpp))
03.main.exe: OBJECTS = $(patsubst %.cpp,%.o,$(wildcard 03.*.cpp))
04.main.exe: OBJECTS = $(patsubst %.cpp,%.o,$(wildcard 04.*.cpp))

all: 01.main.exe 02.main.exe 03.main.exe 04.main.exe

01.main.exe:
	rm -rf gcm.cache
	echo $(OBJECTS)
	$(CC) $(CFLAGS) $(SYSTEM_HEADER) iostream
	$(CC) $(CFLAGS) 01.helloWorld.cpp
	$(CC) $(CFLAGS) 01.main.cpp
	$(CC) $(OBJECTS) -o $@
	$@

02.main.exe:
	rm -rf gcm.cache
	$(CC) $(CFLAGS) $(SYSTEM_HEADER) iostream
	$(CC) $(CFLAGS) $(SYSTEM_HEADER) cstdlib
	$(CC) $(CFLAGS) $(SYSTEM_HEADER) stdlib.h
	$(CC) $(CFLAGS) 02.english.cpp
	$(CC) $(CFLAGS) 02.spanish.cpp
	$(CC) $(CFLAGS) 02.speech.cpp
	$(CC) $(CFLAGS) 02.main.cpp
	$(CC) $(OBJECTS) -o $@
	$@

03.main.exe:
	rm -rf gcm.cache
	$(CC) $(CFLAGS) $(SYSTEM_HEADER) iostream
	$(CC) $(CFLAGS) $(SYSTEM_HEADER) cstdlib
	$(CC) $(CFLAGS) $(SYSTEM_HEADER) stdlib.h
	$(CC) $(CFLAGS) 03.english.cpp
	$(CC) $(CFLAGS) 03.spanish.cpp
	$(CC) $(CFLAGS) 03.speech.cpp
	$(CC) $(CFLAGS) 03.main.cpp
	$(CC) $(OBJECTS) -o $@
	$@

04.main.exe:
	rm -rf gcm.cache
	$(CC) $(CFLAGS) $(SYSTEM_HEADER) iostream
	$(CC) $(CFLAGS) $(SYSTEM_HEADER) cstdlib
	$(CC) $(CFLAGS) $(SYSTEM_HEADER) stdlib.h
	$(CC) $(CFLAGS) 04.english.cpp
	$(CC) $(CFLAGS) 04.spanish.cpp
	$(CC) $(CFLAGS) 04.speech.cpp
	$(CC) $(CFLAGS) 04.main.cpp
	$(CC) $(OBJECTS) -o $@
	$@

14.main.exe:
	rm -rf gcm.cache
	$(CC) $(CFLAGS) $(SYSTEM_HEADER) iostream
	$(CC) $(CFLAGS) $(SYSTEM_HEADER) string
	$(CC) $(CFLAGS) 14.print.cpp
	$(CC) $(CFLAGS) 14.main.cpp
	$(CC) $(OBJECTS) -o $@
	$@

clean:
	rm -rf gcm.cache
	rm *.o
	rm *.exe
