WARNINGS = -Wall
CC = g++
CFLAGS = -g -O0 $(WARNINGS) -std=c++17
LFLAGS := $(LFLAGS)   
SOURCES = $(wildcard *.cpp)


all: example.exe

example.exe: $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $@ $(LFLAGS)

clean::
	- rm -f *.exe
	
	
