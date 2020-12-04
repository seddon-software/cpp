#include "mutex.h"
#include <process.h>

HANDLE hMutex1;
HANDLE hMutex2;

HANDLE CreateMutex(const char* name)
{
    HANDLE hMutex = CreateMutex(0, false, name);
    if (hMutex == 0) throw "Can't create mutex";
	return hMutex;
}

