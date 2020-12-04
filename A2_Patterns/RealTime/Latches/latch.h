#ifndef LATCH_H
#define LATCH_H

#include <windows.h>

class CountDownLatch
{
public:
	CountDownLatch(int n);
	void acquire();
	void release();
private:
	HANDLE hSemaphore;
	int maxCount;
};

#endif

