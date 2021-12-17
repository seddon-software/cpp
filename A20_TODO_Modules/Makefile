#includeders ../../Build/make.mk

CC := g++
CFLAGS := $(CFLAGS) -std=c++20 -fmodules-ts
#! /bin/sh
#g++ -c -std=c++20 -fmodules-ts 01.helloWorld.cpp
#g++ -c -std=c++20 -fmodules-ts 01.main.cpp
#g++ 01.helloWorld.o 01.main.o -o main.exe
#all: main.exe

SOURCES_01 := 01.helloWorld.cpp 01.main.cpp 
SOURCES_02 := 02.mylib.o 02.main.o 
#$(EXECUTABLES): %.exe: %.cpp ;

main1.exe: 
	$(CC) $(CFLAGS) $(SOURCES_01) -o $@
main2.exe:
	g++ -c -std=c++20 -fmodules-ts -x c++-system-header iostream
	g++ -c -std=c++20 -fmodules-ts -x c++-system-header vector
	g++ -c -std=c++20 -fmodules-ts 02.headers.cpp
	g++ -c -std=c++20 -fmodules-ts 02.mylib.cpp
	g++ -c -std=c++20 -fmodules-ts 02.main.cpp
	$(CC) $(CFLAGS) $(SOURCES_02) -o $@

preprocess:
	$(CC) -E $(CFLAGS) $(SOURCES_01)

clean:
	rm *.exe
