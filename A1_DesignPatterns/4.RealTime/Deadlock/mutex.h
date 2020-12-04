#ifndef MUTEX_H
#define MUTEX_H

#include <windows.h>


extern HANDLE hMutex1;
extern HANDLE hMutex2;

HANDLE CreateMutex(const char* name);

#endif
