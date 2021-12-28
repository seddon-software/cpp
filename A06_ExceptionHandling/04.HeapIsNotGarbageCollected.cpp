////////////////////////////////////////////////////////////
//
//		Heap is not garbage collected
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
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
	Person* pSteve = new Person("Steve");
	f3();
	delete pSteve;
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
}
