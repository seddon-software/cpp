///////////////////////////////////////////////////////////////
//
//		Private Inheritance and Dynamic Binding
//
///////////////////////////////////////////////////////////////

// substitution rule fails for private inheritance
// but dynamic binding still works

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
