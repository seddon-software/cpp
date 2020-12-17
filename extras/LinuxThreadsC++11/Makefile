CC := g++
CFLAGS := -g -Wall -std=c++11
LFLAGS := -lpthread --with-threads=posix
#LFLAGS := --with-threads=posix
SOURCES := $(wildcard *.cpp)
EXECUTABLES := $(SOURCES:.cpp=.exe)



all: $(EXECUTABLES)

	
$(EXECUTABLES): %.exe: %.cpp
	$(CC) $(CFLAGS) $< -o $@ $(LFLAGS)



clean:
	rm *.exe
	
	
