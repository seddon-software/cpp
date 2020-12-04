BOOST = C:\boost_1_49_0
BOOST_INC = $(BOOST)
BOOST_LIB = $(BOOST)\stage\lib
WIN32API = C:/cygwin/lib/w32api

CC := g++
CFLAGS := -g -Wall -std=c++11 -I$(BOOST_INC)
LFLAGS := 
ifneq ($(WIN32),)
	LFLAGS += -L$(WIN32API)
endif
ifneq ($(LIB1),)
	LFLAGS +=  -L$(BOOST_LIB) -l$(LIB1)
endif
ifneq ($(LIB2),)
	LFLAGS += -l$(LIB2)
endif
SOURCES := $(wildcard *.cpp)
EXECUTABLES := $(SOURCES:.cpp=.exe)



all: $(EXECUTABLES)

$(EXECUTABLES): %.exe: %.cpp
	$(CC) $(CFLAGS) $< -o $@ $(LFLAGS)

clean:
	rm -f *.exe
