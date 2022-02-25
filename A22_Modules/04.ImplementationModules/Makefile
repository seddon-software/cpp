# In this makefile we compile one file at a time.  This is because some files create modules
# which need to be built before they are imported elsewhere.  
#
# Note that the std library modules, once built, are stored in the "gcm.cache" cache.

CC := g++
CFLAGS :=-g -c -fPIE -std=c++20 -fmodules-ts
SYSTEM_HEADER := -x c++-system-header

OBJECTS = $(patsubst %.cpp,%.o,$(wildcard *.cpp))

all: clean main.exe

main.exe:
	$(CC) $(CFLAGS) $(SYSTEM_HEADER) iostream
	$(CC) $(CFLAGS) $(SYSTEM_HEADER) cstdlib
	$(CC) $(CFLAGS) english.cpp
	$(CC) $(CFLAGS) spanish.cpp
	$(CC) $(CFLAGS) speech.cpp
	$(CC) $(CFLAGS) speech_impl.cpp
	$(CC) $(CFLAGS) main.cpp
	$(CC) $(OBJECTS) -o $@

clean:
	rm -rf gcm.cache
	rm *.o
	rm *.exe
