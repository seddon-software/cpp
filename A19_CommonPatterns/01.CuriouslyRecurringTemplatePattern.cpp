#include <iostream>
using namespace std;

/*
 *  This pattern has the facination name: Curiously Recurring Template Pattern.  This pattern uses
 *  a mixin Base class to provide static polymorphic behaviour in the derived classes, without recourse
 *  to virtual functions.
 * 
 *  This form of polymorphism is called parametric polymorphism (as opposed to the normal runtime 
 *  polymorphism using v-tables).
 * 
 *  The base class defines 3 methods, f1(), f2() and f3().  Our two derived classes Derived1 and
 *  Derived2 do not override these methods.  Instead they declare the same three implementation
 *  methods (hence parametric polymorphism): f1_impl(), f2_impl() and f3_impl(). 
 * 
 *  Now when we write:
 *              d1.f1()
 * 
 *  this calls the Base class method.  However the static_cast:
 *              static_cast<Child*>(this)
 *  is used to tell the compiler we wish to convert the this pointer from Base::this to Child::this, 
 *  where Child=Derived1.  The effect of this is that the compiler will now allow you to call methods
 *  of Derived1 instead of the Base class.   We then do call one of the parametric polymorphic methods,
 *  in this case:
 *              f1_impl()
 */

template <typename Child>
struct Base
{
	// Base calls are made with static bindings i.e. parametric polymorphism
    void f1() { static_cast<Child*>(this)->f1_impl(); }
    void f2() { static_cast<Child*>(this)->f2_impl(); }
    void f3() { static_cast<Child*>(this)->f3_impl(); }
};

// struct uses private inheritance, but everything is public anyway
struct Derived1 : public Base<Derived1>
{
    void f1_impl() { cout << "Derived1 f1 implementation" << endl; }
    void f2_impl() { cout << "Derived1 f2 implementation" << endl; }
    void f3_impl() { cout << "Derived1 f3 implementation" << endl; }
};

// struct uses private inheritance, but everything is public anyway
struct Derived2 : Base<Derived2>
{
    void f1_impl() { cout << "Derived2 f1 implementation" << endl; }
    void f2_impl() { cout << "Derived2 f2 implementation" << endl; }
    void f3_impl() { cout << "Derived2 f3 implementation" << endl; }
};

int main()
{
    Derived1 d1;	// conforms to Base (mixin) contract
    d1.f1();
    d1.f2();
    d1.f3();
    Derived2 d2;	// conforms to Base (mixin) contract
    d2.f1();
    d2.f2();
    d2.f3();
}
