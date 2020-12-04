////////////////////////////////////////////////////////////
//
//		Scoped Pointer
//
////////////////////////////////////////////////////////////


#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <stdexcept>
#include <boost/scoped_ptr.hpp>
using namespace std;


class person
{
public:
	person(const string& n) : name(n)
	{
		cout << "CTOR called for " << name << endl;
	}

	~person()
	{
		cout << "DTOR called for " << name << endl; 
	}
	void f()
	{
		cout << "f() called ..." << endl;
	}
private:
	string name;
};

/////

void f3()
{
	boost::scoped_ptr<person> hilda(new person("Hilda"));
	hilda->f();
	cout << endl << "Throwing Exception ..." << endl << endl;
	throw runtime_error("some sort of problem");
}

void f2()
{
	boost::scoped_ptr<person> peter(new person("Peter"));
	f3();
}

void f1()
{
	boost::scoped_ptr<person> mary(new person("Mary"));
	f2();
}

int main()
{
	try
	{
		boost::scoped_ptr<person> john(new person("John"));
		f1();
	}
	catch(const runtime_error& e)
	{
		cout << endl << "Exception caught - " << e.what() << endl << endl;
		cout << "All scoped_ptr<person> objects destroyed" << endl;
	}	

	return 0;
}
