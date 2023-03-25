////////////////////////////////////////////////////////////
//
//		Bind and Function
//
////////////////////////////////////////////////////////////

#include <vector>
#include <iostream>
#include <functional>
using namespace std;

/*
 *  In the previous section we looked at the .* and ->* binding operators.  These operators are an
 *  integral part of the bindings library defined in <functional>.  This library hides these operators
 *  in templates.  The idea behind the bindings library is to defer full specification of the binding 
 *  parameters until runtime (in the spirit of the callback pardigm).  One big advantage of this 
 *  library is that it treats class methods and non class functions in a similar way.  
 * 
 *  We start by declaring classes A and B and 3 global functions Add, Subtract and Multiply for use in
 *  the examples below.  Note that these classes/functions define methods/functions with identical 
 *  parameter lists.  This is important, because binding to different methods/functions only works
 *  for methods/functions with common signatures.
 *
 *  When binding objects to methods/functions we often defer part of the binding until later.  
 *  Consider:
 *      	std::function<int(int,int)> f;
 *
 *  In this expression we define a function pointer "f" that can bind to a method/function with the 
 *  signature int(int, int); this defines a function that takes two ints and returns an int.  This
 *  signature matches the methods in the classes A and B and the 3 global functions defined outside 
 *  main().  When we bind to the global function Add with: 
 *      	f = std::bind(&Add, _1, _2);
 * 
 *  the values of the two int parameters are deferred until f is called:
 *          result = f(50, 60);
 * 
 *  We can bind to methods to objects with similar syntax:
 * 	        A a1(100);
 *          f = std::bind(&A::Add, a1, _1, _2);
 *  where the object bound is added to the bind parameter list after the method name.  This effectively
 *  creates a deferred function call:
 *          a1.Add(_1, _2)
 *
 *  Other similar examples are shown.
 * 
 *  Notes: 1. when specifying the address of methods/function pointers the & is required, even though you
 *            can normally omit the & when specifying a pointer to a function. 
 *         2. _1 and _2 are defined in the "std::placeholders" namespace.
 */

class A
{
private:
	int x;
public:
	A(int x) : x(x) {}
	int Add(int y, int z) { return x + y + z; }	
	int Subtract(int y, int z) { return x - y - z; }
};

class B
{
private:
	int x;
public:
	B(int x) : x(x) {}
	int Add(int y, int z) { return x + y + z; }
	int Subtract(int y, int z) { return x - y - z; }
};

int Add(int a, int b) { return a + b; }
int Subtract(int a, int b) { return a - b; }
int Multiply(int a, int b) { return a * b; }

//////

int main()
{
	using namespace std::placeholders;
    [[ maybe_unused ]]
	int result = 0;
	
	// create pointer to function objects
	std::function<int(int,int)> f;

	// bind to global functions and invoke
	f = std::bind(&Add, _1, _2);
	result = f(50, 60);
	result = f(40, 30);
	f = std::bind(&Subtract, _1, _2);
	result = f(50, 20);
	result = f(40, 30);

	// reduce number of parameters
	std::function<int(int)> g;
	g = std::bind(&Multiply, 10, _1);
	result = g(2);
	result = g(5);

	// bind to a member functions
	A a1(100);
	A a2(200);
	B b1(10);
	B b2(20);

	f = std::bind(&A::Add, a1, _1, _2);
	result = f(2, 3);
	result = f(4, 6);

	// create function object pointers specifying 1st parameter
	std::function<int(A&,int,int)> fa;
	std::function<int(B&,int,int)> fb;
	fa = std::bind(&A::Add, _1, _2, _3);
	fb = std::bind(&B::Subtract, _1, _2, _3);
	result = fa(a1, 4, 7);
	result = fa(a2, 4, 7);
	result = fb(b1, 4, 7);
	result = fb(b2, 4, 7);
}

