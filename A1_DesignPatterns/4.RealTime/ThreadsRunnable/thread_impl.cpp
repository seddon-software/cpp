#include "thread_impl.h"
#include "thread.h"

namespace dp
{
	thread_impl::thread_impl(thread* pOwner)
		: hThread(0), threadId(0), pOwner(pOwner) {}

	thread_impl::~thread_impl()
	{
		if (hThread) CloseHandle(hThread);
	}

	void thread_impl::start()
	{
		if(!hThread)
		{
			hThread = CreateThread(
					0,
					0,
					workerThread,
					(LPVOID) this,
					0,
					&threadId);
		}
	}

	void thread_impl::join()
	{
		WaitForSingleObject(hThread, INFINITE);
	}
	
	int thread_impl::run()
	{
		return pOwner->run();
	}

	DWORD WINAPI thread_impl::workerThread(LPVOID lpParam)
	{
		thread_impl* _this = (reinterpret_cast<thread_impl*>(lpParam));  // recast this
		DWORD dwReturn = _this->run();		   // call polymorphic run
		return dwReturn;
	}
}
