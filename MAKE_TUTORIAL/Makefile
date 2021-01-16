WARNINGS = -Wall
CC = g++
CFLAGS = -g -O0 $(WARNINGS) -std=c++17
LFLAGS := $(LFLAGS)   
SOURCES = $(wildcard *.cpp)
EXECUTABLES = $(SOURCES:.cpp=.exe)


all: $(EXECUTABLES)


example.exe: %.cpp
	$(CC) $(CFLAGS) $< -o $@ $(LFLAGS)



clean::
	- rm -f *.exe
	
	
