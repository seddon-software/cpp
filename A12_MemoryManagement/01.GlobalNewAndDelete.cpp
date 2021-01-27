//////////////////////////////////////////////////////////////////////
//
//		Global new and delete
//
//////////////////////////////////////////////////////////////////////


#include <cstddef>
#include <cstdlib>
#include <iostream>
using namespace std;


class A 
{
public:
	A()  { cout << "A's CTOR" << endl; }
	~A() { cout << "A's DTOR" << endl; }
};

class B 
{
public:
	B()  { cout << "B's CTOR" << endl; }
	~B() { cout << "B's DTOR" << endl; }
};

/////
// overload new and delete globally


void* operator new (std::size_t size)
{
	cout << "global operator new()" << endl;
	return malloc(size); 
}

void* operator new[] (std::size_t size)
{
	cout << "global operator new[]()" << endl;
	return malloc(size);
}


void operator delete(void* ptr) noexcept
{
	cout << "global operator delete()" << endl;
	free(ptr);
}


void operator delete[](void* ptr) noexcept
{
	cout << "global operator delete[]()" << endl;
	free(ptr);
}


/////

int main()
{
	A* pa;
	B* pb;

// object
	cout << "Objects" << endl;
	pa = new A;
	pb = new B;
	delete pa;
	delete pb;

	cout << endl;

// arrays of objects
	cout << "Arrays of objects" << endl;
	pa = new A[5];
	pb = new B[5];
	delete [] pa;
	delete [] pb;
}

