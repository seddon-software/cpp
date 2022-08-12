# This makefile is called from elsewhere and various macros (e.g. LFLAGS)
# may be defined already in another makefile, hence the use of recursive assignment
# 	LFLAGS :=  $(LFLAGS)

WARNINGS := -Wall $(WARNINGS)
CC = g++
CFLAGS := -g
CFLAGS := $(CFLAGS) $(WARNINGS) -std=c++20
#CFLAGS := $(CFLAGS) $(WARNINGS) -std=c++17
LFLAGS := $(LFLAGS)   
SOURCES = $(wildcard *.cpp)
EXECUTABLES = $(SOURCES:.cpp=.exe)


all: $(EXECUTABLES)


$(EXECUTABLES): %.exe: %.cpp
	@mkdir -p build
	$(CC) $(CFLAGS) $< -o build/$@ $(LFLAGS)



clean:
	- rm -rf build
	
	
