BOOST = boost_1_40_0
BOOST_INC = /cygdrive/c/$(BOOST)
WIN32API = C:/cygwin/lib/w32api

CC := g++
CFLAGS := -g -Wall -I$(BOOST_INC)
LFLAGS := -L$(WIN32API) 
SOURCES := $(wildcard *.cpp)
EXECUTABLES := $(SOURCES:.cpp=.exe)



all: $(EXECUTABLES)

$(EXECUTABLES): %.exe: %.cpp
	$(CC) $(CFLAGS) $< -o $@ $(LFLAGS)

clean:
	rm *.exe
	
	
