#ifndef EXECUTOR_H
#define EXECUTOR_H

#include "thread.h"
#include "functor.h"
#include <deque>
using namespace std;


class executor
{
public:
	executor(int size = 3);
	void start();
	void submitJob(functor& job);
	functor* getJob();
private:
	deque<functor*> jobs;
	deque<thread*> threads;
	int poolSize;
};

#endif
