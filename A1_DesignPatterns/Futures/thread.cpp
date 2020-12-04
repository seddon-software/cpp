////////////////////////////////////////////////////////////
//
//      Thread class
//
////////////////////////////////////////////////////////////

#include "thread.h"

thread::thread()
    : m_hThread(0), dwThreadId(0)
{
}

thread::~thread()
{
    if (m_hThread != 0)
    {
        CloseHandle(m_hThread);
    }
}

HANDLE thread::getHandle()
{
    return m_hThread;
}

void thread::start()
{
   if(!m_hThread) 
   {
      m_hThread = CreateThread(
                    0,
                    0, 
                    workerThread,
                    (LPVOID) this,
                    0, 
                    &dwThreadId);
   }
}

DWORD thread::result()
{
    DWORD exitCode;
    GetExitCodeThread(m_hThread, &exitCode);
    return exitCode;
}


