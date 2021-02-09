# This makefile is called from elsewhere and various macros (e.g. LFLAGS)
# may be defined already in another makefile, hence the use of recursive assignment
# 	LFLAGS :=  $(LFLAGS)
# To inhibit "return value optimization" in demos, use -fno-elide-constructors  

WARNINGS := -Wall
CC = g++
CFLAGS := -g -O0
CFLAGS := $(CFLAGS) $(WARNINGS) -std=c++20
# CFLAGS := $(CFLAGS) $(WARNINGS) -std=c++17
LFLAGS := $(LFLAGS)   
SOURCES = $(wildcard *.cpp)
EXECUTABLES = $(SOURCES:.cpp=.exe)


all: $(EXECUTABLES)


$(EXECUTABLES): %.exe: %.cpp
	$(CC) $(CFLAGS) $< -o $@ $(LFLAGS)



clean:
	- rm -f *.exe
	
	
