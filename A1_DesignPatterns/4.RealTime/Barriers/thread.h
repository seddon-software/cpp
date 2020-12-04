#ifndef THREAD_H
#define THREAD_H

#include "runnable.h"
#include "thread_impl.h"

class thread
{
public:
	thread();
	thread(runnable& target);
	virtual ~thread();
	void start();
	void join();
	virtual int run();
private:
	thread(const thread&);
	thread& operator=(const thread&);
	runnable* pTarget;
	thread_impl* pThread_impl;
};

#endif
