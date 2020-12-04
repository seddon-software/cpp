////////////////////////////////////////////////////////////
//
//		Keyword Casts
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <boost/cast.hpp>
using namespace std;


// Declare 3 base classes
class AAA
{
public:
	virtual void fa1() { cout << "fa1" << endl; }
	virtual void fa2() { cout << "fa2" << endl; }
	virtual void fa3() { cout << "fa3" << endl; }
	virtual ~AAA() {}
private:
	int a1;
	int a2;
	int a3;
};

class BBB
{
public:
	virtual void fb1() { cout << "fb1" << endl; }
	virtual void fb2() { cout << "fb2" << endl; }
	virtual void fb3() { cout << "fb3" << endl; }
	virtual ~BBB() {}
private:
	int b1;
	int b2;
	int b3;
};

class CCC
{
public:
	virtual void fc1() { cout << "fc1" << endl; }
	virtual void fc2() { cout << "fc2" << endl; }
	virtual void fc3() { cout << "fc3" << endl; }
	virtual ~CCC() {}
private:
	int c1;
	int c2;
	int c3;
};

// Declare a class multiply derived from the 3 base classes

class Component : public AAA, public BBB, public CCC
{
public:
	virtual void fa1() { cout << "fa1" << endl; }
	virtual void fa2() { cout << "fa2" << endl; }
	virtual void fa3() { cout << "fa3" << endl; }

	virtual void fb1() { cout << "fb1" << endl; }
	virtual void fb2() { cout << "fb2" << endl; }
	virtual void fb3() { cout << "fb3" << endl; }

	virtual void fc1() { cout << "fc1" << endl; }
	virtual void fc2() { cout << "fc2" << endl; }
	virtual void fc3() { cout << "fc3" << endl; }
private:
	int d1;
	int d2;
	int d3;
};

//////

int main()
{
	AAA* pa;
	BBB* pb;
	CCC* pc;
	Component x;
	AAA a;

// Polymorphic cast always throws on illegal cast
    pa = 0, pb = 0, pc = 0;
	pa = boost::polymorphic_cast<AAA*> (&x);
	pb = boost::polymorphic_cast<BBB*> (&x);
	pc = boost::polymorphic_cast<CCC*> (&x);

	pa->fa2();
	pb->fb2();
	pc->fc2();

	pa = boost::polymorphic_cast<AAA*> (&a);
	pa->fa1();
	try
	{
		// this will throw
		pb = boost::polymorphic_cast<BBB*> (&a);
		pb->fb1();
	}
	catch(const bad_cast& e)
	{
		cout << e.what() << endl;
	}

	return 0;
}

