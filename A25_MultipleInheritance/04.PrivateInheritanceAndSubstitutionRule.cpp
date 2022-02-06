///////////////////////////////////////////////////////////////
//
//		Private Inheritance and Substitution Rule
//
///////////////////////////////////////////////////////////////

/*
 *  In this example of private inheritance, we show that the substitution rule fails.  If you uncomment
 *  the lines in main(), this exapmple will fail to compile.  This is because the method f1() defined
 *  in the base class does not propogate to the derive class because Base is inherited privately.
 */

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
}
