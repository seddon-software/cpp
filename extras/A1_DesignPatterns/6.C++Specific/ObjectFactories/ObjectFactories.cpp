///////////////////////////////////////////////////////////////
//
//		Object Factories
//
///////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;

// could use auto_ptr from the standard library
template<typename T>
class my_auto_ptr
{
private:
	T* ptr;
public:
	my_auto_ptr(T* p) 
	:
		ptr(p) 
	{}

	~my_auto_ptr() 
	{ 
		delete ptr; 
	}
	
	T* operator->() 
	{ 
		return ptr; 
	}
};

/////

class book
{
public:
	static book* create(const string& theTitle) 
	{
		return new book(theTitle);		// calls private CTOR
	}

	~book() 							// gets called by auto_ptr object
	{
		cout << "DTOR called" << endl;
	}

	void display()
	{
		cout << title << endl;
	}

private:
	book(const string& t) : title(t)	// private CTOR
	{
		cout << "Private CTOR called" << endl;
	}

private:
	string title;
};

/////

int main()
{
	my_auto_ptr<book> p = book::create("The Way of Zen");
	p->display();
	return 0;
}	// *p is cleaned up correctly

