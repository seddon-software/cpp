/*
 *  Allocating objects on the heap is achieved by using the "new" operator.  If you wish to customise
 *  allocation you can overload this operator.  It turns out you can overload "new" globally or on a
 *  class by class basis.
 * 
 *  In this example we investigate overloading global "new" and "delete" with what the standard library
 *  uses if we don't overload these operators, so that we can undestand the default behaviour of these 
 *  operators.  In later examples, we will provide our own customized overloads to provide non standard
 *  behaviour, such as caching objects for efficient use of the heap.
 * 
 *  One final point, there are two versions of operator "new" and two of "delete".  One version is for
 *  individual objects (or built in types), the other is for arrays.  The two versions are slightly 
 *  different:
 *          new      : allocate an object
 *          new[]    : allocate an array of objects
 *          delete   : deallocate an object
 *          delete[] : deallocate an array of objects
 * 
 *  As we'll see these operators call operator functions, which in turn call the C allocation routines, 
 *  malloc and free.  The default scheme is as follows:
 *          new      -->  operator new() --> malloc()
 *                   └->  CTOR
 * 
 *          delete   --> DTOR
 *                   └-> operator delete() --> free()
 * 
 *  The other two operators are similar, with allocator functions called once, but CTORs and DTORs 
 *  are called for each of the N objects in the array.
 *          new[]    -->  operator new() --> malloc()
 *                   └->  CTOR * N 
 * 
 *          delete[] --> DTOR * N
 *                   └-> operator delete() --> free()
 */


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

