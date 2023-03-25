////////////////////////////////////////////////////////////
//
//		Smart Pointers
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <stdexcept>
using namespace std;

/*  Smart pointers are used in C++ to control the lifetimes of heap based objects.  In this example
 *  we create our own smart pointer to illustrate how the library smart pointers work.  As you will see
 *  smart pointers overload the -> operator using the handle body pattern:  The smart pointer is the handle 
 *  and the object being managed isknown as the body.
 * 
 *  Note that the size of the smart pointer is minimal (size of a pointer) and hence adds very little
 *  overhead to a program.
 * 
 *  One really important point is that when you want to call methods of the body through the handle
 *  you must use the -> operator, because the body's methods are not present in the handle.  The overload
 *  of the -> operator is unusual in that it is a binary operator, but it is overloaded as a unary operator.  
 *  In fact the overload is performed in two stages.  You overload -> to return a pointer to the body 
 *  and the compiler uses this pointer to make the method call.  This second part of the overload (by 
 *  the compiler) is invisible to the programmer.
 */
class Time
{
private:
	int hours;
	int minutes;
public:
	Time(int h, int m) : hours(h), minutes(m) 
	{
		cout << "CTOR called" << endl;
	}

	~Time() 
	{
		cout << "DTOR called" << endl;
	}
	
	void Print() const
	{ 
		cout << hours << ":" << minutes << endl; 
	}
};

/////

class TimePtr
{
public:
	TimePtr() : ptr(0)
	{}

	TimePtr(int h, int m) : ptr(new Time(h,m))
	{}

	~TimePtr()
	{
		delete ptr;
	}

	const Time* operator->()
	{
		if (ptr == 0) throw range_error("pointer is null");
		return ptr;
	}

	void operator=(Time* const p)
	{
		ptr = p;
	}

private:
	Time* ptr;
};

/////

int main()
{
	TimePtr p1(1, 15);
	TimePtr p2(2, 30);
	TimePtr p3(3, 45);
	TimePtr q;

    // note operator->() returns a pointer to the body; the compiler completes the call
	p1->Print();	 // p1.operator->() -> Print();
	p2->Print();
	p3->Print();

	try
	{
		q->Print();  // this throws because q is not managing a body
	}
	catch(const range_error& e)
	{
		cout << e.what() << endl;
	}
}

