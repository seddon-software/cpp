CC := g++
WARNINGS := -Wall -Wno-sign-compare
CFLAGS := -g -O0 $(WARNINGS) -std=c++20
SOURCES := $(wildcard *.cpp)
EXECUTABLES := $(SOURCES:.cpp=.exe)


all: Association.exe


Association.exe: $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $@ $(LFLAGS)



clean:
	-rm -f *.o
	-rm -f *.exe
	
	
