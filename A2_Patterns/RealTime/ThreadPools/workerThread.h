#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H

#include "thread.h"
#include "executor.h"

class workerThread : public thread
{
public:
	workerThread(executor& e);
	int run();
private:
	executor& ex;
};

#endif
