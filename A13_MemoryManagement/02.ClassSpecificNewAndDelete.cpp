//////////////////////////////////////////////////////////////////////
//
//		Class Specific new and delete
//
//////////////////////////////////////////////////////////////////////

#include <new>
#include <cstdlib>
#include <iostream>
using namespace std;

class Triangle
{
public:
	Triangle() 
	{
		cout << "CTOR called" << endl;
	}
	~Triangle()
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

void* Triangle::operator new (size_t size)
{
	cout << "class specific operator new() called" << endl;
	return malloc(size); 
}

void* Triangle::operator new[] (size_t size)
{
	cout << "class specific operator new[]() called" << endl;
	return malloc(size); 
}

void Triangle::operator delete(void* ptr)
{
	cout << "class specific operator delete() called" << endl;
	free(ptr);
}

void Triangle::operator delete[](void* ptr)
{
	cout << "class specific operator delete[]() called" << endl;
	free(ptr);
}

/////

int main()
{
	Triangle* p;

// object
	cout << "Allocate and deallocate an object" << endl;
	p = new Triangle;
	delete p;
	cout << endl;

// arrays of objects
	cout << "Allocate and deallocate an array of objects" << endl;
	p = new Triangle[5];
	delete[] p;
}
  
