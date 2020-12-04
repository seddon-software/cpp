WIN32API = C:/cygwin/lib/w32api
WIN32INC = C:/cygwin/usr/include/w32api
CC := g++
CFLAGS := -g -Wall -I$(WIN32INC)
LFLAGS := -L$(WIN32API) 
SOURCES := $(wildcard *.cpp)


all: futures.exe

futures.exe: $(SOURCES)
	$(CC) $(CFLAGS) $(LFLAGS) $(SOURCES) -o $@


clean:
	rm *.exe
	
	
