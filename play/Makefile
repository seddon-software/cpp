CC := g++
WARNINGS := -Wall
CFLAGS := -g $(WARNINGS) -std=c++20
LFLAGS := -lm -lncursesw -pthread
SOURCES := $(wildcard *.cpp)
EXECUTABLES := $(SOURCES:.cpp=.exe)


all: $(EXECUTABLES)


$(EXECUTABLES): %.exe: %.cpp
	$(CC) $(CFLAGS) $< -o $@ $(LFLAGS)



clean:
	-rm -f *.o
	-rm -f *.exe
	
