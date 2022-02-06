///////////////////////////////////////////////////////////////
//
//		Private Inheritance and Dynamic Binding
//
///////////////////////////////////////////////////////////////

/*
 *  C++ supports protected and private inheritance.  However, it is important to realise that nowadays
 *  calling this inheritance is largely historical; these two forms were an experiment in the early days 
 *  of C++.
 * 
 *  To be true inheritance, classes must follow the ISA relationship and the substituition rule whereby
 *  a derived class object can always substitute for a base class object.  With protected and private
 *  inheritance some of the base class methods are not propgated to the derived class and the substition
 *  rule therefore fails.  Thes forms are closely related to aggregation.
 * 
 *  Nevertheless, you can still use dynamic binding for these forms of inheritance because the compiler
 *  will still generate V-Tables for virtual functions.
 * 
 *  In this example, we make some early binding calls which susequr=ently make late binding calls, 
 *  resulting in the calls yoyoing up and down the inheritance hierarchy.
 */

class Base
{
public:
	void f1() { f2(); }
	void f2() { f3(); }   // call to f3() is virtual
	virtual void f3() {}
};

class Derived: private Base
{
public:
	void f1() { f2(); }
	virtual void f3() {}
};

/////

int main()
{
	Base	b;
	Derived d;

	d.f1(); 	// calls Derived::f1() => Base::f2() => Derived::f3()
	b.f1(); 	// calls Base	::f1() => Base::f2() => Base   ::f3()

	return 0;
}
