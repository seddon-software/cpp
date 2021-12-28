////////////////////////////////////////////////////////////
//
//		Heap is not garbage collected
//
////////////////////////////////////////////////////////////

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
