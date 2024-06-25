CC := g++
WARNINGS := -Wall
INCLUDES := $(PYTHON_INC) $(PYBIND11_INC)
CFLAGS := -g -I $(INCLUDES) $(WARNINGS) -std=c++20
LFLAGS := -lm -pthread
SOURCES := $(wildcard *.cpp)
EXECUTABLES := $(SOURCES:.cpp=.exe)


all: $(EXECUTABLES)


$(EXECUTABLES): %.exe: %.cpp
	$(CC) $(CFLAGS) $< -o $@ $(LFLAGS)



clean:
	-rm -f *.o
	-rm -f *.exe
	
