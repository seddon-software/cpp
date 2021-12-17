//////////////////////////////////////////////////////////////////////
//
//      Alternative Forms of new and delete
//
//////////////////////////////////////////////////////////////////////

#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

class A
{
public:
	A()
	{
    	if(x > y) throw string("x > y");
	}
	
	void Display()
	{
		cout << x << ":" << y << endl;
	}
	
    static void* operator new (size_t size, int x, int y)
    {
    	// all initialization done here
	    int* ptr = 0;
    	if(x > y) throw string("x > y");
	    ptr = static_cast<int*>(malloc(size));
    	ptr[0] = x;
    	ptr[1] = y;
	    return ptr; 
    }
    static void  operator delete(void* ptr, int x, int y)
	{
		// only called when an exception is thrown in placement new
    	if(ptr != 0) free(ptr);
	}

    static void  operator delete(void* ptr)
	{
	    // normal call
	    free(ptr);
	}
private:
	int x;
	int y;
};

/////

int main()
{
	A* pa;
	try
	{
		pa = new (5,7) A;	// succeeds
		pa->Display();
		delete pa;

		pa = new (6,2) A;	// throws exception
		pa->Display();
	    delete pa;
	}
	catch(const string& message)
	{
	    cout << message << endl;
	}

	return 0;
}
  
