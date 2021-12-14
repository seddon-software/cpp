////////////////////////////////////////////////////////////
//
//		Double Checked Locking Pattern
//
////////////////////////////////////////////////////////////

// https://stackoverflow.com/questions/5050763/double-checked-locking-pattern

#include <iostream>
using namespace std;
/*
CRITICAL_SECTION cs;

class Lock
{
public:
	Lock() 
	{	
	    EnterCriticalSection(&cs);
	}
	~Lock()
	{
	    LeaveCriticalSection(&cs);
	}
};

/////

class Singleton
{
private:
	static Singleton* pInstance;
protected:
	Singleton(const Singleton&) {}
	Singleton() {};
	~Singleton() {};
public:
    void f() 
    {
    	// print address of singleton
    	cout << this << endl;
    }
    
	static Singleton *instance();
};

Singleton* Singleton::instance()
{
	if(!pInstance)	// first check
	{
		Lock locker;	// CTOR locks
		if(!pInstance)	// second check
		{
			pInstance = new Singleton;
		}
	} // DTOR unlocks
	return pInstance;
}

Singleton* Singleton::pInstance = 0;

/////
*/
int main()
{
/*
	InitializeCriticalSection(&cs);
	
	// double check pattern unsafe in multithreaded programs
	// defeated by relaxed memory model
	
	Singleton* p = Singleton::instance();
	p->f();
	
	Singleton* q = Singleton::instance();
	q->f();
*/
}
