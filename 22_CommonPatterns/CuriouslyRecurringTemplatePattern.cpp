#include <iostream>
using namespace std;

// Curiously Recurring Template Pattern
// use a mixin class (Base) to provide static polymorphic behaviour
// in the derived classes, without the use of virtual functions

// Curiously Recurring Template Pattern
//	uses parametric polymorphism (rather than runtime polymorphism)

template <typename Child>
struct Base
{
	// Base calls are made with static bindings i.e. parametric polymorphism
    void f1() { static_cast<Child*>(this)->f1_impl(); }
    void f2() { static_cast<Child*>(this)->f2_impl(); }
    void f3() { static_cast<Child*>(this)->f3_impl(); }
};

struct Derived1 : public Base<Derived1>
{
    void f1_impl() { cout << "Derived1 f1 implementation" << endl; }
    void f2_impl() { cout << "Derived1 f2 implementation" << endl; }
    void f3_impl() { cout << "Derived1 f3 implementation" << endl; }
};

// struct uses public inheritance by default
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
