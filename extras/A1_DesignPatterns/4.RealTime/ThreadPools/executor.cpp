#include "executor.h"
#include "workerThread.h"

executor::executor(int size) : poolSize(size) 
{
	pMutex = new Mutex();

	for(int i = 0; i < poolSize; i++)
	{
		thread* ptr = new workerThread(*this);
		threads.push_back(ptr);
	}
}

executor::~executor()
{
	delete pMutex;
}

void executor::start()
{
	for(int i = 0; i < poolSize; i++)
	{
		threads[i]->start();
	}
}

void executor::submitJob(functor& job)
{
	// protect jobs deque
	pMutex->lock();
	jobs.push_back(&job);
	pMutex->unlock();
}

functor* executor::getJob()
{
	functor* job = 0;

	// protect jobs deque
	pMutex->lock();
	if(!jobs.empty()) 
	{
		job = jobs.front();
		jobs.pop_front();
	}
	pMutex->unlock();

	return job;
}
