LIB1 := boost_filesystem-mgw47-mt-d-1_49
LIB2 := boost_system-mgw47-mt-1_49
BOOST = C:\boost_1_49_0
BOOST_INC = $(BOOST)
BOOST_LIB = $(BOOST)\stage\lib

CC := g++
CFLAGS := -g -fpermissive -Wall  -std=c++11 -I$(BOOST_INC)
LFLAGS := -L$(BOOST_LIB)  -l$(LIB1)  -l$(LIB2)

SOURCES := $(wildcard *.cpp)
EXECUTABLES := $(SOURCES:.cpp=.exe)



all: $(EXECUTABLES)

$(EXECUTABLES): %.exe: %.cpp
	$(CC) $(CFLAGS) $< -o $@ $(LFLAGS)

clean:
	rm -f *.exe
