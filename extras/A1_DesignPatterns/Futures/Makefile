BOOST = boost_1_46_1
BOOST_INC = C:/$(BOOST)
WIN_INC = C:/MinGW/include
WIN32API = C:/cygwin/lib/w32api

CC := g++
CFLAGS := -g -Wall -I$(WIN_INC) -I$(BOOST_INC)
LFLAGS := -L$(WIN32API) 
SOURCES := $(wildcard *.cpp)



all: Futures

Futures : $(SOURCES) 
	$(CC) $(SOURCES) -o $@

clean:
	rm *.exe
	
	
