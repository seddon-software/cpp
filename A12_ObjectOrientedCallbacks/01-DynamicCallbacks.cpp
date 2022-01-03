///////////////////////////////////////////////////////////////
//
//		Dynamic Callbacks
//
///////////////////////////////////////////////////////////////

/*
 * Event driven programming, such as handling a button press in a GUI system or receiving an interrupt from another 
 * thread, is characterised by the use of callbacks.  In C this is implemented using global function 
 * pointers.  Unfortunately, global function pointers do not work well in an object oriented environment 
 * and it is fair to say that the C callback function model is too primitive for C++.  Member functions 
 * can't be used directly and global functions often require a context to simulate member functions; the
 * context data is passed in separately, sometimes lacking type information (i.e. void*), leading to an 
 * error prone and unsafe system.
 * 
 * We are all familiar with the 
 *     . and -> 
 * operators.  These operators bind an object to a method; the dot operator binds the object at compile 
 * time and the arrow operator binds the object at runtime.  In both cases the function is bound at 
 * compile time.
 *   
 * Two lesser known C++ operators
 *		.* and ->
 * are used to bind a method at runtime.  To summarise:
 * 		.	bind object at compile time, bind method at compile time
 * 		->	bind object at run time,     bind method at compile time
 * 		.*  bind object at compile time, bind method at run time 
 * 		->* bind object at run time,     bind method at run time
 *  
 *  These operators are C++'s way of implementing object oriented callbacks.
 *
 *  In this abstract example (more practical ones to follow), we will perform callbacks on an object and 
 *  method, with both selected at run time using the ->* operator.  We select the method and the object 
 *  sometime before the actual callback using Callback::load().  The callback is made with Callback::fire().
 * 
 *  Note that the syntax of a pointer to a member function requires use of the & operator; omitting the 
 *  & will cause a compilation error.
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

// callback class that holds two pointers: one to an object and one to a method
class Callback
{
public:
//	typedef void (A::*METHOD_PTR)(int);
    using METHOD_PTR = void (A::*)(int);
public:
	void Load(METHOD_PTR pFunction, A& object)
	{
		pf = pFunction;
		po = &object;
	}

	void Fire(int n)
	{
		(po->*pf)(n);
	}
private:
	A*	       po;
	METHOD_PTR pf;
};

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

    // load different object and method
	c.Load(&A::Multiply, a2);
	c.Fire(2);
	c.Fire(3);

    // load different method
	c.Load(&A::Add, a2);
	c.Fire(18);
	c.Fire(57);
}
