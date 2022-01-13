//////////////////////////////////////////////////////////////////////
//
//      Alternative Forms of new and delete
//
//////////////////////////////////////////////////////////////////////

#include <cstdlib>
#include <cstring>
#include <stdexcept>
#include <string>
#include <iostream>
using namespace std;

/*
 *  If the previous 8 overloads are not enough you can define a number of additional oveloads.  Basically
 *  operator new and operator delete can have as many additional parameters as you like and you can use
 *  these parameters as you see fit.
 * 
 *  In this rather unusual example, we add two extra parameters, x and y, which we use to initialize 
 *  our Point objects:
 *           static void* operator new (size_t size, int x, int y)
 *
 *  Since the initialization is performed in operator new, there is nothing for the CTOR to do.  I'm 
 *  not suggesting doing this is a good idea, but it does show what is possible.  As an added wrinkle, 
 *  we throw an exception if x > y or x == 5.
 * 
 *  If no exception is thrown then operator delete(void*) gets called when the object id deleted.
 * 
 *  If x > y, we throw in operator new().  Now since nothing gets allocated, no operator delete() is 
 *  called as there is nothing to deallocate.
 * 
 *  If x==5, we throw in the CTOR.  In this case memory does gets allocated, so operator delete() is 
 *  called.  However, it might be important to know the values of x and y supplied to operator new() 
 *  when memory was allocated as this could affect how we clean up.  To accomodate this operator 
 *  delete() is called with additional parameters instead of the normal operator delete(void*).
 *  This is the only case where: 
 *          operator delete(void* ptr, int x, int y)
 *  is called.
 * 
 *  Finally, note how additional parameters are passed to operator new():
 *          pa = new (6,8) Point;
 * 
 *  Question: why is it necessary for operator new to return a void* ?
 */

class Point
{
public:
	Point()
	{
    	if(x == 5) throw runtime_error("throw in CTOR");
	}
	
	void display()
	{
		cout << x << ":" << y << endl;
	}
	
    static void* operator new (size_t size, int x, int y)
    {
        cout << "operator new(size_t, int, int) called" << endl;
    	// all initialization done here
	    int* ptr = 0;
    	if(x > y) throw runtime_error("throw in operator new");
        // allocate space for two ints
	    ptr = static_cast<int*>(malloc(size));
    	ptr[0] = x;         // &ptr[0] points at the first int (x)
    	ptr[1] = y;         // &ptr[1] points at the second int (y)
	    return ptr;         // the return is used by the compiler to initialize the this pointer
    }
    static void  operator delete(void* ptr, int x, int y)
	{
		// only called when an exception is thrown in CTR after operator new(size_t, int, int) called
        cout << "operator delete(void*, int, int) called" << endl;
    	if(ptr != 0) free(ptr);
	}

    static void  operator delete(void* ptr)
	{
	    // normal call
        cout << "operator delete(void*) called" << endl;
	    free(ptr);
	}
private:
	int x;
	int y;
};

/////

int main()
{
	Point* pa;
    {
		pa = new (6,8) Point;	// succeeds
		pa->display();
		delete pa;
    }
	try
	{
		pa = new (5,7) Point;	// throws in CTOR
	}
	catch(const runtime_error& e)
	{
	    cout << e.what() << endl;
	}
	try
	{
		pa = new (6,2) Point;	// throws in operator new()
	}
	catch(const runtime_error& e)
	{
	    cout << e.what() << endl;
	}
}
  
