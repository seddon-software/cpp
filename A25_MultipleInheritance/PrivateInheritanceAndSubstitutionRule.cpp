///////////////////////////////////////////////////////////////
//
//		Private Inheritance and Substitution Rule
//
///////////////////////////////////////////////////////////////

class Base
{
public:
	virtual void f1() {}
};

// private inheritance restricts the interface
// and the substitution rule fails
class Derived : private Base
{
public:
	virtual void f1() {}
};

int main()
{
	Base* p = new Base;
	p->f1();

	// Derived objects do not substitute for Base objects with private inheritance
	// Base* q = new Derived;	// does not compile
	// q->f1();

	return 0;
}
