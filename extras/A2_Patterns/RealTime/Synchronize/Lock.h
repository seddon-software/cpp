#include <windows.h>
#include <exception>

class Lock
{
public:
    Lock(HANDLE h) : hMutex(h), flag(true)
    {
		// lock mutex
		WaitForSingleObject(hMutex, INFINITE);
    }

    ~Lock()
    {
		// unlock mutex
        ReleaseMutex(hMutex);
    }

    operator bool () const
    {
        return flag;
    }

	void setUnlock()
    {
        flag = false;        
    }

	static HANDLE Create()
	{
		HANDLE h = ::CreateMutex(
			        0,     // security
				    false, // initial owner
					0);    // name
					
		if (h == 0) throw std::exception();
		return h;
	}
	static void Destroy(HANDLE h)
	{
		CloseHandle(h);
	}
private:
    HANDLE hMutex;
    bool flag;
};

#define synchronized(M) for(Lock M##object = M; M##object; M##object.setUnlock())

