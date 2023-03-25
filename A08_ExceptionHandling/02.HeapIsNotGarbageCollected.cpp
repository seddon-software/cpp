
/* 
 * The biggest problem when using exception handling is that heap based objects
 * don't get cleaned up.  In this example we create 3 stack based Person objects
 * and one heap based object in functions calle from "main".  Finally we throw an 
 * exception to find that all the stack based objects get cleaned up (their DTORs
 * are called), but the heap based object is not cleaned up.
 * 
 * To overcome this problem we need to use smart pointers (see a later example).
 */

#include <iostream>
#include <exception>
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
	throw exception();
}

void f2()
{
	// heap based objects are not cleaned up!
    cout << "Person(\"Steve\") created on the heap; it will not get destroyed" << endl; 
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
	catch(const exception&)
	{
		cout << "Exception caught" << endl;
	}
}
