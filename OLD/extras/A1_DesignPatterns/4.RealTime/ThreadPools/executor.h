#ifndef EXECUTOR_H
#define EXECUTOR_H

#include <deque>
using namespace std;

#include "thread.h"
#include "functor.h"
#include "mutex.h"


class executor
{
public:
	executor(int size = 3);
	~executor();
	void start();
	void submitJob(functor& job);
	functor* getJob();
private:
	Mutex* pMutex;
	deque<functor*> jobs;
	deque<thread*> threads;
	int poolSize;
};

#endif
