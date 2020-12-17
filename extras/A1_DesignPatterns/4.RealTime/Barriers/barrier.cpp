#include "barrier.h"

Barrier::Barrier(int n)
{
	InitializeCriticalSection(&cs);

	size = n;
	currentIndex = 0;

	const int initialCount = 0;
	const int maxCount = 1;

	hSemaphore = new HANDLE[size];

	for(int i = 0; i < size; i++)
	{
		hSemaphore[i] = CreateSemaphore(0, initialCount, maxCount, 0);
	}
}

void Barrier::await()
{
	int index;
	// release your semaphore 
    EnterCriticalSection(&cs);
	index = currentIndex;
	ReleaseSemaphore(hSemaphore[index], 1, 0);
	currentIndex++;
    LeaveCriticalSection(&cs);

	// wait for all semaphores to be released
	WaitForMultipleObjects(size, hSemaphore, true, INFINITE);
	for(int i = 0; i < size; i++)
	{
		ReleaseSemaphore(hSemaphore[i], 1, 0);
	}
}

