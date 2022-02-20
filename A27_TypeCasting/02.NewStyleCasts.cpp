#include <iostream>
#include <typeinfo>
using namespace std;


/*  
 *  C++11 introduced 4 new cast operators:
 *          static_cast<T>(U)
 *          dynamic_cast<T>(U)
 *          reinterpret_cast<T>(U)
 *          const_cast<T>(U)
 * 
 *  These cast operators do the same job as the old fashioned casts, but were introduced to make it
 *  more obvious what was intended by the cast.
 *
 *  The static_cast only works on objects, and can be applied to both polymorphic and non polymorphic types.
 *  If the cast is invalid then the code will fail to compile.
 
 *  The dynamic_cast only works on polymorphic types (classes with V-Tables).  If the cast is invalid
 *  (incompatible polymorphic types) then casting from a pointer returns a null pointer on failure and
 *  casting from a reference throws bad_cast on failure.  Note that because dynamic_casts are checked at
 *  run-time, the polymorphic classes must a least one virtual function (to generate the V-Tables).
 * 
 *  The reinterpret_cast only works on pointers, and can also be applied to both polymorphic and non 
 *  polymorphic types.  If the cast is invalid then the code will fail to compile.  If this cast is used
 *  between non polymorphic types then the compiler assumes you know what you doing; this often an indication
 *  of a hack or programming error.
 
 *  The const_cast is used to remove the const nature of an object.  Note this should be used with caution;
 *  the constness of an object id there for a reason.  Overriding constness is usually only necessary when
 *  working with library code where the author has erroneously make something constant that shouldn't be
 *  and you don't have access to the library code.
 */

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
    // static_cast only works on objects ...
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


