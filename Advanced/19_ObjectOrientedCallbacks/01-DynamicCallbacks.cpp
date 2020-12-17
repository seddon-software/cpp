///////////////////////////////////////////////////////////////
//
//		Dynamic Callbacks
//
///////////////////////////////////////////////////////////////

/*
Event driven programming, such as handling a button press in a GUI system or receiving an interrupt from another thread,
is characterised by the use of callbacks.  In C this is implemented using global function pointers.  Unfortunately, global
function pointers do not work well in an object oriented environment and it is fair to say that the C callback function model
is too primitive. Member functions can't be used directly and global functions often require a context to simulate member
functions.  The context data is passed in separately, sometimes lacking type information (i.e. void*), leading to an error
prone and unsafe system.  Multiple roots of control, association of data with function, grouping of related functions,
generic interfaces with alternative implementations, etc. are mapped more easily into an object model than into a procedural
one.

We are all familiar with the
	.
	->
operators.  These operators bind an object to a method; the dot operator binds the object at compile time and the arrow
operator binds at runtime.  In both cases the method is bound at compile time.  Two lesser known operators
	.*
	->
are used to bind a method at runtime.  Using all 4 operators allows either the object or the method to be bound at compile
time or run time.  As we will see, these operators are C++'s way of implementing object oriented callbacks.

In this example, we intend to make Object Oriented callbacks to different methods for various objects.  We select the
method and the object sometime before the actual callback.  The Callback class defines Load and Fire methods.  The Load method
records the object and the method, but doesn't actually make the call.  The call is not made until the Fire method is invoked.

To Load the callback select a pointer to a method and an object.  The callback is executed by the Fire method.  Notice that
since each callback method takes a single int parameter; this parameter is passed to Fire and the callback is implemented
using
	(po->*pf)(n);

Note that the syntax of a pointer to a member function requires use of the & operator; omitting the & will cause a
compilation error.
*/

#include <iostream>
using namespace std;

// sample class with several methods, all of the same signature
class A
{
public:
	virtual void Add	 (int n) { cout << "Add: "		<< x + n << endl; }
	virtual void Subtract(int n) { cout << "Subtract: " << x - n << endl; }
	virtual void Multiply(int n) { cout << "Multiply: " << x * n << endl; }
public:
	A(int x0) : x(x0) {}
private:
	int x;
};

// callback class that holds a two pointers: one to an object and one to a method
class Callback
{
public:
	typedef void (A::*POINTER_TO_MEMBER)(int);
public:
	void Load(POINTER_TO_MEMBER pFunction, A& object);
	void Fire(int);
private:
	A*	              po;
	POINTER_TO_MEMBER pf;
};

void Callback::Load(POINTER_TO_MEMBER pFunction, A& object)
{
	pf = pFunction;
	po = &object;
}


void Callback::Fire(int n)
{
	(po->*pf)(n);
}

/////

int main()
{
	A a1(100);
	A a2(200);
	Callback c;

	// load callback object with method and object
	c.Load(&A::Subtract, a1);
	c.Fire(25);
	c.Fire(40);

	c.Load(&A::Multiply, a2);
	c.Fire(2);
	c.Fire(3);

	c.Load(&A::Add, a2);
	c.Fire(18);
	c.Fire(57);
}
