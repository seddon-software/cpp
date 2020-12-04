////////////////////////////////////////////////////////////
//
//		Bind and Function
//
////////////////////////////////////////////////////////////

#include <vector>
#include <string>
#include <iostream>
#include <boost/bind.hpp>
#include <boost/function.hpp>
using namespace std;


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
	boost::function<string()> f;
	Delegate<boost::function<string()> > d;
	Greeting john("John");
	Greeting sue("Sue");

	// load up multicast delegate
	d += boost::bind(&Greeting::Hello, john);
	d += boost::bind(&Greeting::Goodbye, sue);
	d += boost::bind(&Greeting::Wait, john);

	// fire delegate
	d();
	
	return 0;
}

