#ifndef THREAD_IMPL_H
#define THREAD_IMPL_H

#include <windows.h>

class thread;

class thread_impl
{
public:
	thread_impl(thread* pOwner);
	~thread_impl();
	void start();
	void join();
	int run();
	static DWORD WINAPI workerThread(LPVOID lpParam);
private:
	HANDLE hThread;
	DWORD threadId;
	thread* pOwner;
};

#endif
