////////////////////////////////////////////////////////////
//
//		Keyword Casts
//
////////////////////////////////////////////////////////////

/*
 *  This example illustrates what happens when you use convential
 *  old style casts (bracket casts) instead of dynamic_casts.
 */

#pragma GCC diagnostic ignored "-Wunused-private-field"
#include <iostream>
#include <typeinfo>
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
// This class has 3 V-Tables

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

/// Casting Component objects using conventional casts
	Component x;

	// note that the pa pb and pc will point at their respective v-tables ptrs and
	// hence will be all different
	pa = (AAA*) &x;
	pb = (BBB*) &x;
	pc = (CCC*) &x;

	pa->fa2();
	pb->fb2();
	pc->fc2();

// Dynamic casting using pointers (behaves the same as convential casts)
    pa = 0, pb = 0, pc = 0;
	pa = dynamic_cast<AAA*> (&x);
	pb = dynamic_cast<BBB*> (&x);
	pc = dynamic_cast<CCC*> (&x);

	pa->fa2();
	pb->fb2();
	pc->fc2();

// Casting BBB objects using conventional, dynamic and static casts
	// note that BBB has only one v-table
	BBB  b;

// Conventional casts
	// pa pb and pc all point to the one and only v-table (the are all equal)
	pa = (AAA*) &b;
	pb = (BBB*) &b;
	pc = (CCC*) &b;

	// Dispatch is by the v-table pointer witch is incorrect for pa and pc
	pa->fa2();		// calls fb2() by mistake
	pb->fb2();		// calls correct function
	pc->fc2();		// calls fb2() by mistake

// Dynamic casting BBB objects using pointers
	pa = dynamic_cast<AAA*> (&b);
	pb = dynamic_cast<BBB*> (&b);
	pc = dynamic_cast<CCC*> (&b);

	if(pa) pa->fa2();	   // no call made
	if(pb) pb->fb2();	   // calls correct function
	if(pc) pc->fc2();	   // no call made

// Dynamic casting BBB objects using references (throw bad_cast on error)
	try {
		BBB& rb = dynamic_cast<BBB&> (b);
		rb.fb2();
		AAA& ra = dynamic_cast<AAA&> (b);
		ra.fa2();
		CCC& rc = dynamic_cast<CCC&> (b);
		rc.fc2();
	} catch(bad_cast& e) {
		cout << "bad cast" << endl;
	}
}

