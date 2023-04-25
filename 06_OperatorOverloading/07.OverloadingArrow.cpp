/*
 *  The overload of -> is a little unusual.  Its usually used to implement a smart pointer.  A smart
 *  pointer is an object that behaves like a C pointer.
 * 
 *  Although -> is a binary operator in C, it is overloaded as a unary operator in C++.  This means the 
 *  overload has no parameters:
 * 	            Time* operator->()
 *              {
 *                  // code ...
 *              }
 *  Now a smart pointer is used to track another object.  In this example we create a smart pointer on
 *  the stack that tracks a Time object created on the heap.  We do this to ensure heap based objects 
 *  are cleaned up properly, even if an exception is thrown.  Note that the smart pointer has a raw C 
 *  pointer as its one and only attribute.
 * 
 *  Recall that the compiler manages the stack and automatically cleans up stack based objects (i.e.
 *  calls their DTOR).  The idea is that when the smart pointer destructor is called by the compiler it
 *  in turn calls the Time destructor. In fact this works even if an exception is thrown before you have 
 *  time to call delete on the Time object.
 * 
 *  One last caveat.  When we want to call a method of the Time class we can call it via the Smart pointer 
 *  using the -> operator.  If you examine the code below you will see that the operator->() method returns 
 *  the raw C pointer to the Time object.  The compiler then injects code to call the Time class method.  
 *  Thus
 *              s->hello();
 * 
 *  returns an anonymous Time* pointer (imagine it is called ptr).  This pointer is then used by the compiler
 *  to inject the code:
 *              ptr->hello()
 * 
 *  unfortunately you can't see the injected code directly; only see its effect.  In modern C++ we use
 *  the unique_ptr from the standard library rather than rolling our own version, but it is essentially
 *  the same as the class shown here.
 */

#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>
using namespace std;


class Time
{
public:
	Time(int h, int m):hrs(h), min(m) {}
	~Time()
	{
		cout << "Time DTOR called on:" << display() << endl;
	}
	void hello()
	{
		cout << "Hello called" << endl;
	}
	string display()
	{
		stringstream s;
		s << hrs << ":" << min << endl;
		return s.str();
	}
private:
	int hrs;
	int min;
};

class SmartPtr
{
public:
	SmartPtr(Time* p) : ptr(p) {}
	~SmartPtr()
	{
		cout << "SmartPtr DTOR called for: " << ptr->display(); 
		delete ptr;
	}
	Time* operator->()  // overloaded -> as a unary operator
	{
		return ptr;
	}
private:
    Time* ptr;
};

void useSmartPtr(SmartPtr& s)
{
	s->hello();
    // ptr = s.operator->()
    // (*ptr).hello()

	// if we throw then the DTOR for s is called
	// this in turn calls the DTOR for the Time object ...
	// 	... and the heap gets cleaned up correctly
	throw runtime_error("was the heap cleaned up when we throw?");
}

int main()
{
	try
	{
		Time* p = new Time(2,15);
		Time* q = new Time(4,45);
		SmartPtr s1(p);
		SmartPtr s2(q);
		useSmartPtr(s1);
	} catch(const exception& e) {
		cout << e.what() << endl;
	}
}
