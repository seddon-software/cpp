#include "mutex.h"


Mutex::Mutex() 
{
	pMutexImpl = new MutexImpl();
}
Mutex::~Mutex()
{
	delete pMutexImpl;
}
void Mutex::lock()
{
	pMutexImpl->lock();
}
void Mutex::unlock()
{
	pMutexImpl->unlock();
}



