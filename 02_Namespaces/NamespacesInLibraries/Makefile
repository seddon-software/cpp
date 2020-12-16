include ../../_Build/make.mk

# force: Test
Test:: LibPart1.cpp LibPart2.cpp LibPart3.cpp Test.cpp
	$(CC) $(CFLAGS) $(LFLAGS) LibPart1.cpp LibPart2.cpp LibPart3.cpp Test.cpp -o $@
	mv Test Test.exe
	
%: force
	Test

	

