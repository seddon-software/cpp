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
 *  run-time, the polymorphic classes must define at least one virtual function (to generate the V-Tables).
 * 
 *  The reinterpret_cast only works on pointers, and can also be applied to both polymorphic and non 
 *  polymorphic types.  If you try reinterpret_cast on non pointers or references the cast will fail to compile.  
 *  If this cast is used between non polymorphic types then the compiler assumes you know what you doing; 
 *  this often an indication of a hack or programming error.
 
 *  The const_cast is used to remove the const nature of an object.  Note this should be used with caution;
 *  the constness of an object id there for a reason.  Overriding constness is usually only necessary when
 *  working with library code where the author has erroneously made something constant that shouldn't be
 *  and you don't wish to modify the library code.
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
    [[maybe_unused]]
    X* p1 = reinterpret_cast<X*>(&y);   // polymorphic (p1 can only see the X part of y)
    [[maybe_unused]]
    X* p2 = reinterpret_cast<X*>(&z);   // non polymorphic (this is a hack and may produce strange results)

    // static_cast
    // static_cast only works on objects ...
    // ... both polymorphic and non polymorphic types
    [[maybe_unused]]
    X x1 = static_cast<X>(y);       // polymorphic (x1 is a slice of y - bad!)
    [[maybe_unused]]
    X x2 = static_cast<X>(z);       // non polymorphic (should work: compatible types)

    // dynamic_casts
    // dynamic_cast only works on polymorphic types (classes with V-Tables)
    // pointer types: returns null pointer on failure
    // reference types: throws bad_cast on failure
    [[maybe_unused]]
    X* p3 = dynamic_cast<X*>(&y);   // upcasting from Y to X (p3 points at base part of y)
    [[maybe_unused]]
    Y* p4 = dynamic_cast<Y*>(&x);   // downcasting from X to Y (fails: returns null pointer)
    cout << endl;                   // dummy line for the debugger

    try
    {
        [[maybe_unused]]
        X& ref1 = dynamic_cast<X&>(y);  // upcasting from Y to X (ref1 refers to base part of y)
        [[maybe_unused]]
        Y& ref2 = dynamic_cast<Y&>(x);  // downcasting from X to Y (fails: throws bad_cast)
        cout << endl;                   // dummy line for the debugger
    }
    catch (const bad_cast&)
    {
        cout << "dynamic_cast fails" << endl;
    }
}


