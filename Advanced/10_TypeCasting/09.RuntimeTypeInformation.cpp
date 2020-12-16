///////////////////////////////////////////////////////////////
//
//		Runtime Type Information
//
///////////////////////////////////////////////////////////////

#include <iostream>
#include <typeinfo>
using namespace std;

/*
 *  Run Time Type Information (RTTI) is appended to the v-table
 *  Only the namespace and class name is available and then
 *  usually as a mangled name
 */

namespace RTTI	// namespace info included in RTTI
{
	class Person // class must have a V-Table
	{
	public:
		virtual ~Person() {}
	};

	class Employee : public Person {};
	class Salesman : public Employee {};
}

/////

void determineClass(const RTTI::Person& p);

int main()
{
	RTTI::Person p;
	RTTI::Employee e;
	RTTI::Salesman s;

	determineClass(p);
	determineClass(e);
	determineClass(s);
}

void determineClass(const RTTI::Person& p)
{
	cout << typeid(p).name() << endl;
}
