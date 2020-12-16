#include <iostream>
#include <stdexcept>
using namespace std;

class Lock
{
public:
    void acquireLock()
	{
    	cout << "lock acquired" << endl;
	}
    void unlock()
    {
    	cout << "lock released" << endl;
    }
};

class MyClass
{
public:
	MyClass(Lock& lock) : theLock(lock)
	{
		theLock.acquireLock();
	}
	~MyClass()
	{
		theLock.unlock();
	}
private:
	Lock& theLock;
};

int main()
{
    Lock lock;
	try
	{
		MyClass m(lock);
		throw exception();
	}
	catch(const exception& e)
	{
		cout << e.what() << endl;
	}
}



