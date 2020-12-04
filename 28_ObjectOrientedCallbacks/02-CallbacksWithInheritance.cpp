///////////////////////////////////////////////////////////////
//
//		Callbacks with Inheritance
//
///////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
using namespace std;


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
	void (A::*fp)();	// pointer to member of A with signature 'void f()'
	A a;
	B b;
	C c;
	fp = &A::f;		// point at polymorphic function
	(a.*fp)();
	(b.*fp)();
	(c.*fp)();
	
	fp = &A::g;		// point at polymorphic function	
	(a.*fp)();
	(b.*fp)();
	(c.*fp)();

	vector<A*> pointers = { &a, &b, &c };
	for(auto& ptr : pointers)
	{
		(ptr->*fp)();
	}
}

