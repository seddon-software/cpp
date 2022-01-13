//////////////////////////////////////////////////////////////////////
//
//		Class Specific new and delete
//
//////////////////////////////////////////////////////////////////////

#include <new>
#include <cstdlib>
#include <iostream>
using namespace std;

/*
 *  Overloading global new and delete is a bit drastic, because it effects not just your code, 
 *  but library code as well.  It's much more common to overload these operators on a class by
 *  class basis.  Consider the code below, the scheme is similar to global new and delete, with
 *  additional forms for arrays of objects.
 */

class Point
{
public:
	Point() 
	{
		cout << "CTOR called" << endl;
	}
	~Point()
	{
		cout << "DTOR called" << endl;
	}
	// overload new and delete for the class
	static void* operator new(size_t);
	static void* operator new[](size_t);
	static void  operator delete(void*);
	static void  operator delete[](void*);
private:
	int x;
	int y;
};

/////

void* Point::operator new (size_t size)
{
	cout << "class specific operator new() called" << endl;
	return malloc(size); 
}

void* Point::operator new[] (size_t size)
{
	cout << "class specific operator new[]() called" << endl;
	return malloc(size); 
}

void Point::operator delete(void* ptr)
{
	cout << "class specific operator delete() called" << endl;
	free(ptr);
}

void Point::operator delete[](void* ptr)
{
	cout << "class specific operator delete[]() called" << endl;
	free(ptr);
}

/////

int main()
{
	Point* p;

// object
	cout << "Allocate and deallocate an object" << endl;
	p = new Point;
	delete p;
	cout << endl;

// arrays of objects
	cout << "Allocate and deallocate an array of objects" << endl;
	p = new Point[5];
	delete[] p;
}
  
