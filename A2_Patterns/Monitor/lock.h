#include <windows.h>
#include <string>
#include <exception>
using namespace std;

class Lock
{
public:
	Lock()
	{
		hMutex = CreateMutex(
			        0,     // security
				    false, // initial owner
					0);    // name
					
		if (hMutex == 0) throw exception();
	}

	~Lock()
	{
		CloseHandle(hMutex);
	}
private:
    void doLock()
    {
		WaitForSingleObject(hMutex, INFINITE);
    }

    void doUnlock()
    {
        ReleaseMutex(hMutex);
    }

private:
	Lock(const Lock&); // prevent copying
    HANDLE hMutex;

public:
	// nested class
	class PrivateLock
	{
	public:
		PrivateLock(Lock& l) : lock(l), flag(false)
		{
			lock.doLock();
		}
		~PrivateLock()
		{
			lock.doUnlock();
		}

		operator bool()
		{
			flag = !flag;
			return flag;
		}
	private:
		Lock& lock;
		bool flag;
	};

};

#define synchronized(M) for(Lock::PrivateLock M##object = M; M##object; )

