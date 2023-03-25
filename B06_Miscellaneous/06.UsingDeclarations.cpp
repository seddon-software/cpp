/*
 *  In this example we are using private inheritance.  Normally, the methods in the Base class would
 *  be reclassified as private in the derived class, however the using statements:
 *              using Base::f1;
 *              using Base::f2;
 *  make the f1 and f2 methods visible in the derived class.
 */

#include <iostream>
using namespace std;


class Base
{ 
public:
    void f1(int) { cout << "Base::f1(int)" << endl; }
    void f2(int) { cout << "Base::f2(int)" << endl; }
};

class Derived : private Base
{
public:
    using Base::f1;    // republish to make visible
    using Base::f2;    // republish to make visible
};

/////

int main()
{
    Derived d;
    d.f1(4); // doesn't compile without using declaration
    d.f2(5);
}
