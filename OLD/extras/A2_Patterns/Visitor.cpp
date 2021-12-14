////////////////////////////////////////////////////////////
//
//		Visitor Pattern
//
////////////////////////////////////////////////////////////

/*
 *	In this example classes A, B and C define methods g1,g2,g3
 *  Suppose these classes can't be modified, but we want to add
 *  extra methods.  To accomodate this, each class provides a
 *  Visitor hook
 *
 *  We then define 4 Visitors than can visit each class A, B, C
 *  Each visitor effectively adds an extra method to these classes
 *  making 3 + 4 methods per class
 */

#include <iostream>
#include <string>
using namespace std;

void Print(string s)
{
	cout << s << endl;
}


// our class hierarchy - can't be modified
class A;
class B;
class C;

// Visitors effectively add methods to our hierarchy ...
// Vistors have methods for each class in our hierarchy 
class Visitor
{
public:
	virtual void f(A) = 0;
	virtual void f(B) = 0;
	virtual void f(C) = 0;
};

class IAccept
{
public:
	virtual void accept(Visitor& v) = 0;
};

class A : public IAccept
{
public:
	// acts as a hook
	virtual void accept(Visitor& v) 
	{
	    v.f(*this);
	}
	virtual void g1() { Print("A::g1"); }
	virtual void g2() { Print("A::g2"); }
	virtual void g3() { Print("A::g3"); }
};

class B : public IAccept
{
public:
	// acts as a hook
	virtual void accept(Visitor& v) 
	{
	    v.f(*this);
	}
	virtual void g1() { Print("B::g1"); }
	virtual void g2() { Print("B::g2"); }
	virtual void g3() { Print("B::g3"); }
};

class C : public IAccept
{
public:
	// acts as a hook
	virtual void accept(Visitor& v) 
	{
	    v.f(*this);
	}
	virtual void g1() { Print("C::g1"); }
	virtual void g2() { Print("C::g2"); }
	virtual void g3() { Print("C::g3"); }
};

// each visitor effectively adds a new method to our hierarchy
class Visitor1 : public Visitor
{
public:
	void f(A) { Print("A::f1"); }
	void f(B) { Print("B::f1"); }
	void f(C) { Print("C::f1"); }
};

class Visitor2 : public Visitor
{
public:
	void f(A) { Print("A::f2"); }
	void f(B) { Print("B::f2"); }
	void f(C) { Print("C::f2"); }
};

class Visitor3 : public Visitor
{
public:
	void f(A) { Print("A::f3"); }
	void f(B) { Print("B::f3"); }
	void f(C) { Print("C::f3"); }
};

class Visitor4 : public Visitor
{
public:
	void f(A) { Print("A::f4"); }
	void f(B) { Print("B::f4"); }
	void f(C) { Print("C::f4"); }
};

/////

int main()
{
	// create normal objects and visitors
    A a;
    B b;
    C c;
    Visitor1& v1 = *new Visitor1();
    Visitor2& v2 = *new Visitor2();
    Visitor3& v3 = *new Visitor3();
    Visitor4& v4 = *new Visitor4();

	// a has 3 standard methods and 4 visitor methods
	a.g1();
	a.g2();
	a.g3();
	a.accept(v1);
	a.accept(v2);
	a.accept(v3);
	a.accept(v4);
	
	// ba has 3 standard methods and 4 visitor methods
	b.g1();
	b.g2();
	b.g3();
	b.accept(v1);
	b.accept(v2);
	b.accept(v3);
	b.accept(v4);
	
	// c has 3 standard methods and 4 visitor methods
	c.g1();
	c.g2();
	c.g3();
	c.accept(v1);
	c.accept(v2);
	c.accept(v3);
	c.accept(v4);
}

