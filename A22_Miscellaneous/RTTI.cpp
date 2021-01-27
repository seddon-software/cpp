///////////////////////////////////////////////////////////////
//
//		Runtime Type Information
//
///////////////////////////////////////////////////////////////

#include <iostream>
#include <typeinfo>
using namespace std;

namespace RTTI
{
	class Person
	{
	public:
		virtual ~Person() {}
	};

	class Employee : public Person {};
	class Salesman : public Employee {};
}

/////

using namespace RTTI;

void DetermineClass(Person& p);

int main()
{
	Person	 p;
	Employee e;
	Salesman s;

	DetermineClass(p);
	DetermineClass(e);
	DetermineClass(s);

	return 0;
}

void DetermineClass(Person& p)
{
	cout << typeid(p).name() << endl;
}
