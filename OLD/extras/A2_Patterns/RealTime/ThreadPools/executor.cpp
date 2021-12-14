#include "executor.h"
#include "workerThread.h"

executor::executor(int size) : poolSize(size) 
{
	for(int i = 0; i < poolSize; i++)
	{
		thread* ptr = new workerThread(*this);
		threads.push_back(ptr);
	}
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
	jobs.push_back(&job);
}

functor* executor::getJob()
{
	if(jobs.empty()) return 0;
	functor* job = jobs.front();
	jobs.pop_front();
	return job;
}
