#include <iostream>
#include <memory>
#include <stdexcept>
using namespace std;

/*  RAII (resourse acquisition is initialization) is a C++ programming technique using a class's CTOR and 
 *  DTOR which ensures resources such as lock, files, heap memory will be guaranteed to released even in
 *  the presence of exceptions.
 * 
 *  The idea is that a resource is acquired in a CTOR and then released in the corresponding DTOR as shown 
 *  below for the case of a lock.  Obviously, the lock object needs to be stack based to ensure its DTOR
 *  gets called.
 * 
 *  Note that with a lock we must be careful to take a reference to the lock in the MyClass CTOR, 
 *  especially if we are writing multi-threaded code.
 */

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
	{   // stack based objects
        cout << "Stack based objects" << endl;
		MyClass m(lock);
		cout << "exception!" << endl;   // the lock still gets released
		throw exception();
	}
	catch(const exception& e)
	{
		cout << e.what() << " caught" << endl;
	}

    try
    {   // heap based objects need smart pointer to ensure DTOR called
        cout << endl << "Heap based objects" << endl;
        auto ptr = new MyClass(lock);
        unique_ptr<MyClass> m(ptr);
		cout << "exception!" << endl;   // the lock still gets released
		throw exception();
    }
    catch(const exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}



