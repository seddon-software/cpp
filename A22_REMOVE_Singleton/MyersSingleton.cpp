////////////////////////////////////////////////////////////
//
//		Singleton
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <cstdlib>
using namespace std;


class Singleton
{
protected:
	Singleton(const Singleton&) {}
	Singleton() 
	{
		cout << "CTOR called" << endl;
	}
	~Singleton() 
	{
		cout << "DTOR called" << endl;
	}
public:
    void f() 
    {
    	// print address of singleton
    	cout << this << endl;
    }
    
	static Singleton* instance();
};

Singleton* Singleton::instance()
{
	// static objects are initialized when control first 
	//  passes through this function
	// not to be confused with static variables which are
	//  initialized at program load time
	
	static Singleton instance;
	return &instance;
	
	// compiler ensures DTOR is registered as an atexit function
}


/////

void tidyup()
{
	// singleton should be DTORed by now
}

int main()
{
	atexit(tidyup);
	Singleton* p = Singleton::instance();
	p->f();
	
	Singleton* q = Singleton::instance();
	q->f();
}
