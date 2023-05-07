CC := g++
WARNINGS := -Wall
PYBIND11_INC := /opt/anaconda3/lib/python3.9/site-packages/pybind11/include
PYTHON_INC := /opt/anaconda3/include/python3.9
INCLUDES := $(PYTHON_INC) $(PYBIND11_INC)
CFLAGS := -g -I/opt/anaconda3/lib/python3.9/site-packages/pybind11/include/ -I $(PYTHON_INC)
# CFLAGS := -g -I $(INCLUDES) $(WARNINGS) -std=c++20
LFLAGS := -lm -lncursesw -pthread
SOURCES := $(wildcard *.cpp)
EXECUTABLES := $(SOURCES:.cpp=.exe)


all: $(EXECUTABLES)


$(EXECUTABLES): %.exe: %.cpp
	$(CC) $(CFLAGS) $< -o $@ $(LFLAGS)



clean:
	-rm -f *.o
	-rm -f *.exe
	
