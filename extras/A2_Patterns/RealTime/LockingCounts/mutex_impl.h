#include <windows.h>
#include <exception>

class MutexImpl
{
public:
	MutexImpl() 
	{
		hMutex = ::CreateMutex(
			0,     // security
			false, // initial owner
			0);    // name
		if (hMutex == 0) throw std::exception("Can't create mutex");
	}
	~MutexImpl() 
	{
		if (hMutex) CloseHandle(hMutex);
	}
	void lock()
	{
		WaitForSingleObject(hMutex, INFINITE);
	}
	void unlock()
	{
		ReleaseMutex(hMutex);
	}
private:
	HANDLE hMutex;
};
