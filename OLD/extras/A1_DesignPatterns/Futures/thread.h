#ifndef THREAD_H
#define THREAD_H

#include <windows.h>

class thread
{
public:
	thread();
	virtual ~thread();
	void start();
    HANDLE getHandle();
    DWORD result();
protected:
	virtual int run() = 0;
private:
	thread(const thread&);
	thread& operator=(const thread&); 
	HANDLE m_hThread;
	DWORD dwThreadId;
	static DWORD WINAPI workerThread(LPVOID lpParam);
};

#endif
