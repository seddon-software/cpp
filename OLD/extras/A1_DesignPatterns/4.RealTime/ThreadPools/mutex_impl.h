#include <windows.h>
#include <exception>

class MutexImpl
{
public:
	MutexImpl();
	~MutexImpl();
	void lock();
	void unlock();
private:
	HANDLE hMutex;
};
