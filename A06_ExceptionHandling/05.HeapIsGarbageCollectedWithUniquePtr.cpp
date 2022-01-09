////////////////////////////////////////////////////////////
//
//		Heap is garbage collected
//
////////////////////////////////////////////////////////////

/*  As discussed in the previous example, heap based objects don't get cleaned up
 *  if an exception is thrown.  However if we use a smart pointer to track every 
 *  heap based object we can remedy the situation.  This is because the smart pointer 
 *  is stack based and so it will be cleaned up by the compiler.  Its DTOR will call
 *  the heap based object's DTOR that it is tracking.
 * 
 *  Note that although the smart pointer is stack based it creates minimal overhead
 *  to the program.  Modern practice is to track every heap based object with a smart 
 *  pointer, because that means every object gets its DTOR called (e.g. no more memory leaks). 
 */

#include <iostream>
#include <string>
#include <memory>
using namespace std;


class Person
{
public:
	Person(const string& n) : name(n) 
	{
		cout << "CTOR for " << name << endl;
	}

	~Person()
	{
		cout << "DTOR for " << name << endl;
	}
private:
	string name;
};


/////

void f3()
{
	Person hilda("Hilda");
	throw "some kind of problem";
}

void f2()
{
	// heap based objects are not cleaned up!
	// unless wrapped in a unique_ptr
	unique_ptr<Person> pSteve = unique_ptr<Person>(new Person("Steve"));
	f3();
}

void f1()
{
	Person mary("Mary");
	f2();
}

int main()
{
	try
	{
		// stack based objects are cleaned up
		Person john("John");
		f1();
	}
	catch(...)
	{
		cout << "Exception caught" << endl;
	}
	return 0;
}
