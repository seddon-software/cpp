CC := g++
WARNINGS := -Wall -Wno-sign-compare
CFLAGS := -g -O0 $(WARNINGS) -std=c++17 -fno-elide-constructors
SOURCES := $(wildcard *.cpp)
EXECUTABLES := $(SOURCES:.cpp=.exe)


all: $(EXECUTABLES)


$(EXECUTABLES): %.exe: %.cpp
	$(CC) $(CFLAGS) $< -o $@ $(LFLAGS)



clean:
	-rm -f *.o
	-rm -f *.exe
	
	
