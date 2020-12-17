WIN32API = C:/cygwin/lib/w32api
WIN32INC = C:/cygwin/usr/include/w32api
WIN32API = C:/MinGW/lib
WIN32INC = C:/MinGW/include
CC := g++
CFLAGS := -g -Wall -I$(WIN32INC)
LFLAGS := -L$(WIN32API) 
SOURCES := $(wildcard *.cpp)


all: threadPools.exe

threadPools.exe: $(SOURCES)
	$(CC) $(CFLAGS) $(LFLAGS) $(SOURCES) -o $@


clean:
	dir
	del *.exe
	
	
