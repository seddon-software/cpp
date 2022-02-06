/*
 *  You often get mbiguities with multiple inheritance.  Here we show how to specify which method to call
 *  when multiple inheritance offers several candidate methods with the same name.  Note in some cases
 *  the compiler can't decide which function to call, in which case the code doesn't compile.
 * 
 *  Note we use struct and private inheritance to simplify this example.  The example would be the same
 *  with classes and public inheritance.
 */

#include <iostream>
using namespace std;


struct A
{ 
    void f() { cout << "A::f" << endl; }
    void g() { cout << "A::g" << endl; }
};

struct B
{
    void f() { cout << "B::f" << endl; }
    void g() { cout << "B::f" << endl; }
};

struct AB : A, B
{
	void f() { cout << "AB::f" << endl; }
};


/////

int main()
{
    AB ab;
    ab.f();             // calls AB::f()

    // this call is ambiguous
    // ab.g();          // doesn't compile

    // this call is unambiguous
    ab.B::g();          // B:: resolves ambiguity
}
