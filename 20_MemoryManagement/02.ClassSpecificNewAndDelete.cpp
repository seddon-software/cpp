//////////////////////////////////////////////////////////////////////
//
//		Class Specific new and delete
//
//////////////////////////////////////////////////////////////////////

#include <new>
#include <cstdlib>
#include <iostream>
using namespace std;

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
	[[ maybe_unused ]] int x;
	[[ maybe_unused ]] int y;
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
  
