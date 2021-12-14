#include "latch.h"


CountDownLatch::CountDownLatch(int n)
{
	maxCount = n;
	hSemaphore = CreateSemaphore(0, 0, maxCount, 0);
}

void CountDownLatch::release()
{
	ReleaseSemaphore(hSemaphore, maxCount, 0);
}

void CountDownLatch::acquire()
{
	WaitForSingleObject(hSemaphore, INFINITE);
}

