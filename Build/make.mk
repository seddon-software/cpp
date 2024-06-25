# This makefile is called from elsewhere and various macros (e.g. LFLAGS)
# may be defined already in another makefile, hence the use of recursive assignment
# 	LFLAGS :=  $(LFLAGS)

WARNINGS := -Wall $(WARNINGS)
CC = g++
CFLAGS := -g
CFLAGS := $(CFLAGS) $(WARNINGS) -std=c++11
LFLAGS := $(LFLAGS)   
SOURCES = $(wildcard *.cpp)
EXECUTABLES = $(SOURCES:.cpp=.exe)


all: $(EXECUTABLES)


$(EXECUTABLES): %.exe: %.cpp
	$(CC) $(CFLAGS) $< -o $@ $(LFLAGS)


# note double colon.  This allows other Makefiles to add addition clean rules 
clean::
	- rm -f *.exe
	
	

