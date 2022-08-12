////////////////////////////////////////////////////////////
//
//		Bind and Function
//
////////////////////////////////////////////////////////////

#include <vector>
#include <string>
#include <iostream>
#include <functional>
using namespace std;

/*
 *  The C# language defines multicast delegates as and object with multiple callbacks.  By
 *  overloading the += operator we can easily simulate this in C++.
 */

class Greeting
{
public:
	Greeting(const string& name) : name(name) {}
	string Hello() { return "Hello " + name; }
	string Wait() { return "Wait " + name; }
	string Goodbye() { return "Goodbye " + name; }
private:
	string name;
};

template <typename T>
struct Delegate
{
	vector<T> list;

	void operator+=(T item)
	{
		list.push_back(item);
	}

	void operator() ()
	{
		for(unsigned i = 0; i < list.size(); i++)
		{
			T item;
			item = list[i];
			cout << item() << endl;
		}
	}
};


//////

int main()
{
	// create pointer to function objects
	Delegate<function<string()>> d;
	Greeting john("John");
	Greeting sue("Sue");

	// load up multicast delegate
	d += bind(&Greeting::Hello, john);
	d += bind(&Greeting::Goodbye, sue);
	d += bind(&Greeting::Wait, john);

	// fire delegate
	d();
}

