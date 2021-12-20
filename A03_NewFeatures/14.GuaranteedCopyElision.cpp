// The C++17 standard brings many exciting new features, including
// guaranteed copy elision. 

#include <iostream>
using namespace std;

struct X 
{
  X()          { cout << "Default CTOR" << endl; }
  X(const X &) { cout << "Copy CTOR" << endl; }
  X(X &&)      { cout << "Move CTOR" << endl; }
  ~X()         { cout << "DTOR" << endl; }
};

X f() 
{
    return X();   // copy CTOR not called for temporary : elision
}

X g() 
{
    X x;
    return x;  // copy CTOR not called : elision
}

void h(X x)    // copy CTOR not called for unbound temporary
{

}

int main()
{
    X x;
    f();
    g();
    h(X());     // passing an unbound temporary
    h(x);       // no elision for bound objects
    try
    {
        throw x;
    }
    catch(X x)  // elision when catch by copy 
    {
    }    
}