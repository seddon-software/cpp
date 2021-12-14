#ifndef THREAD_H
#define THREAD_H

#include "runnable.h"
#include "thread_impl.h"

namespace dp
{
// This class uses handle body to separate windows specific code from
// the thread abstraction.  This class contains the abstraction and
// thread_impl contains the windows specific implementations.

	class thread
	{
	public:
		thread();
		thread(dp::runnable& target);
		virtual ~thread();
		void start();
		void join();
		virtual int run();
	private:
		thread(const thread&);
		thread& operator=(const thread&);
		dp::runnable* pTarget;
		thread_impl* pThread_impl;
	};
}

#endif
