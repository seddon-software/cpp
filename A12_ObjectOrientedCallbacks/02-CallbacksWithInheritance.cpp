///////////////////////////////////////////////////////////////
//
//		Callbacks with Inheritance
//
///////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
using namespace std;

/*  
 * C++s callback mechanism works alongside polymorphism with the compiler generating code to use
 *  V-Tables. Note that specifying the base class pointer to method (&A::f) is sufficient and 
 *  necessary to trigger the virtual calls.
 */

class A
{
public:
	virtual void f() {}
	virtual void g() {}
};


class B : public A
{
public:
	virtual void f() {}
	virtual void g() {}
};

class C : public B
{
public:
	virtual void f() {}
	virtual void g() {}
};

/////

int main()
{
	void (A::*fp)();	// declaring a pointer to member of A (or B or C) with signature 'void f()'
	A a;
	B b;
	C c;
	fp = &A::f;		// point fp at polymorphic function f()
	(a.*fp)();		// v-tables are used to dispatch these calls
	(b.*fp)();
	(c.*fp)();
	
	fp = &A::g;		// point fp at polymorphic function g()	
	(a.*fp)();      // v-tables are used to dispatch these calls
	(b.*fp)();
	(c.*fp)();

	// now store pointers in a vector
	vector<A*> pointers = { &a, &b, &c };
	for(auto& ptr : pointers)
	{
		(ptr->*fp)(); // v-tables are used to dispatch these calls
	}
}

