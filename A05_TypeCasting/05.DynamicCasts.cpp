/*
 *  Old style casts will still work as expected in most cases.  The only time you run into trouble is when
 *  you are using multiple inheritance.
 * 
 *  In this example convential old style casts (bracket casts) work fine in the single inheritance cases
 *  but unlike dynamic_casts, they fail with multiple inheritance.  Study the detailed comments and diagrams 
 *  below.
 */

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

	Component x;
/*
	How the x object is laid out in memory is compiler dependent.  However, most compilers
	will lay out this object as below.  Note the compiler creates 3 V-Table pointers inside
	the object:

                Component           V-Tables
               ┌──────────┐      ┌───────────┐
    pa, x ---> │_vptr.AAA │----->│fa1() {...}│
               │a1        │      │fa2() {...}│
               │a2        │      │fa3() {...}│
               │a3        │      │           │
               ├──────────┤      ├───────────┤
    pb ------> │_vptr.BBB │----->│fb1() {...}│
               │b1        │      │fb2() {...}│
               │b2        │      │fb3() {...}│
               │b3        │      │           │
               ├──────────┤      ├───────────┤
    pc-------> │_vptr.CCC │----->│fc1() {...}│
               │b1        │      │fc2() {...}│
               │b2        │      │fc3() {...}│
               │b3        │      │           │
               │d1        │      └───────────┘
               │d2        │
               │d3        │
               └──────────┘

*/
/// Casting Component objects using conventional casts
	// note that the pa pb and pc will point at their respective v-tables ptrs (see above diagram)
	// and hence will have different values

	pa = (AAA*) &x;
	pb = (BBB*) &x;
	pc = (CCC*) &x;
	cout << "pa=" << pa << ": pb=" << pb << ": pc=" << pc << endl;
	pa->fa2();
	pb->fb2();
	pc->fc2();

// Dynamic casting using pointers (behaves the same as conventional casts)
    pa = 0, pb = 0, pc = 0;
	pa = dynamic_cast<AAA*> (&x);
	pb = dynamic_cast<BBB*> (&x);
	pc = dynamic_cast<CCC*> (&x);
	cout << "pa=" << pa << ": pb=" << pb << ": pc=" << pc << endl;

	pa->fa2();
	pb->fb2();
	pc->fc2();

// Casting BBB objects using conventional, dynamic and static casts
	// note that BBB has only one v-table
	BBB  b;
/*
	The b object has only one V-Table and is probably laid out as below:

                    BBB                 V-Table
                   ┌──────────┐      ┌───────────┐
    pa,pb,pc ----> │_vptr.BBB │----->│fb1() {...}│
                   │b1        │      │fb2() {...}│
                   │b2        │      │fb3() {...}│
                   │b3        │      └───────────┘
                   └──────────┘
*/

// Conventional casts
	// pa pb and pc all point to the one and only v-table (hence all end up equal)
	pa = (AAA*) &b;
	pb = (BBB*) &b;
	pc = (CCC*) &b;
	cout << "pa=" << pa << ": pb=" << pb << ": pc=" << pc << endl;

	// Dispatch is by the v-table pointer and this gives incorrect results for pa and pc
	pa->fa2();		// calls fb2() by mistake (would crash if parameters different)
	pb->fb2();		// calls correct function
	pc->fc2();		// calls fb2() by mistake (would crash if parameters different)

// Dynamic casting BBB objects using pointers
	pa = dynamic_cast<AAA*> (&b);   // returns 0
	pb = dynamic_cast<BBB*> (&b);   // succeeds
	pc = dynamic_cast<CCC*> (&b);   // returns 0
	cout << "pa=" << pa << ": pb=" << pb << ": pc=" << pc << endl;

	if(pa) pa->fa2();	   // no call made
	if(pb) pb->fb2();	   // calls correct function
	if(pc) pc->fc2();	   // no call made

// Dynamic casting BBB objects using references (throw bad_cast on error)
	try {
		BBB& rb = dynamic_cast<BBB&> (b); // valid
		rb.fb2();
		AAA& ra = dynamic_cast<AAA&> (b); // bad cast, this throws
		ra.fa2();
	} catch(bad_cast& e) {
		cout << "bad cast" << endl;
	}
}

