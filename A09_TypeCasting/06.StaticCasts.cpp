////////////////////////////////////////////////////////////
//
//		Static Casts
//
////////////////////////////////////////////////////////////

/*
 *  Similar example to the pevious one, but this time using static casts
 *  which detect errors at compile time
 */

//#pragma GCC diagnostic ignored "-Wunused-private-field"
#include <iostream>
using namespace std;


// Declare 3 base classes
class AAA
{
public:
	virtual void fa1() { cout << "fa1" << endl; }
	virtual void fa2() { cout << "fa2" << endl; }
	virtual void fa3() { cout << "fa3" << endl; }
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
private:
	int c1;
	int c2;
	int c3;
};

//////

int main()
{
// Casting base class objects using conventional, dynamic and static casts
	BBB  b;

// Conventional casts
	AAA* pa = (AAA*) &b;
	BBB* pb = (BBB*) &b;
	CCC* pc = (CCC*) &b;

	pa->fa2();		// calls fb2() by mistake
	pb->fb2();		// calls correct function
	pc->fc2();		// calls fb2() by mistake

// Static casting BBB objects

	//pa = static_cast<AAA*> (&b);	 // compiler detects error
	pb = static_cast<BBB*> (&b);
	//pc = static_cast<CCC*> (&b);	 // compiler detects error

	pb->fb2();
	
	return 0;
}

