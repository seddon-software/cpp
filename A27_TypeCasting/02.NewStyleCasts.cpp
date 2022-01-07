////////////////////////////////////////////////////////////
//
//		Static Casts
//
////////////////////////////////////////////////////////////

#pragma GCC diagnostic ignored "-Wunused-variable"
#include <iostream>
#include <typeinfo>
using namespace std;

struct X    // class must have a V-Table (for dynamic casts)
{
    X(int x): x(x) {}
    virtual ~X() {}
    int x;
};

struct Y : X
{
    Y(int x, int y) : X(x), y(y) {}
    int y;
};

struct Z
{
    operator X() { return z; }
    Z(int z) : z(z) {}
    int z;
};

//////

int main()
{
    X x(10);
    Y y(20, 21);
    Z z(30);

    // reinterpret_cast
    // reinterpret_cast only works on pointers ...
    // ... both polymorphic and non polymorphic types
    X* p1 = reinterpret_cast<X*>(&y);   // polymorphic
    X* p2 = reinterpret_cast<X*>(&z);   // non polymorphic

    // static_cast
    // static_cast only works on pointers ...
    // ... both polymorphic and non polymorphic types
    X x1 = static_cast<X>(y);       // polymorphic
    X x2 = static_cast<X>(z);       // non polymorphic

    // dynamic_casts
    // dynamic_cast only works on polymorphic types (classes with V-Tables)
    // pointer types: returns null pointer on failure
    // reference types: throws bad_cast on failure
	X* p3 = dynamic_cast<X*>(&y);   // upcasting (p1 points at derived part of y)
	y.y = 99;                       // p4 sees this change
	Y* p4 = dynamic_cast<Y*>(&x);   // downcast  (fails)
	cout << endl;                   // dummy line for the debugger

    try
    {
        X& ref1 = dynamic_cast<X&>(y);  // upcasting (p1 refers to derived part of y)
        y.y = 99;                       // ref1 sees this change
        Y& ref2 = dynamic_cast<Y&>(x);
        cout << endl;                   // dummy line for the debugger
    }
    catch (const bad_cast&)
    {
        cout << "dynamic_cast fails" << endl;
    }
}


