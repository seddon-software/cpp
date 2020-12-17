#include <windows.h>
#include <stdexcept>
#include "mutex_impl.h"

MutexImpl::MutexImpl() 
{
	hMutex = ::CreateMutex(
		0,     // security
		false, // initial owner
		0);    // name
	if (hMutex == 0) throw std::runtime_error("Can't create mutex");
}

MutexImpl::~MutexImpl() 
{
	if (hMutex) CloseHandle(hMutex);
}

void MutexImpl::lock()
{
	WaitForSingleObject(hMutex, INFINITE);
}

void MutexImpl::unlock()
{
	ReleaseMutex(hMutex);
}
