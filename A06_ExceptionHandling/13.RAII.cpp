#include <iostream>
#include <stdexcept>
using namespace std;

class Lock
{
public:
    void acquireLock(const string& message)
	{
    	cout << message << endl;
	}
    void unlock(const string& message)
    {
    	cout << message << endl;
    }
};

class MyClass
{
public:
	MyClass(Lock& lock) : theLock(lock)
	{
		theLock.acquireLock("lock acquired in MyClass CTOR");
	}
	~MyClass()
	{
		theLock.unlock("lock released in MyClass DTOR");
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
		cout << "exception!" << endl;
		throw exception();
	}
	catch(const exception& e)
	{
		cout << e.what() << " caught" << endl;
	}
}



