#ifndef BARRIER_H
#define BARRIER_H

#include <windows.h>

class Barrier
{
public:
	Barrier(int n);
	void await();
private:
	CRITICAL_SECTION cs;
	HANDLE* hSemaphore;
	int size;
	int currentIndex;
};

#endif

