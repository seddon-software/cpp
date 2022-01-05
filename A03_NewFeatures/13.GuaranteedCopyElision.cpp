
/*  
 *  The C++17 standard brings many exciting new features, including guaranteed copy elision.
 *  This is a slight misnomer, because elision is not really guaranteed, rather the creation
 *  of temporaries is avoided in cases where an unnecessary copy of the temporary would result.
 *  
 *  This avoid unnecessary calls to Copy CTORs and move CTORs.  See:
 *      https://devblogs.microsoft.com/cppblog/guaranteed-copy-elision-does-not-elide-copies/
 *  for a more detailed explanation.
 */ 

#include <iostream>
using namespace std;

struct X 
{
    X()          { cout << "Default CTOR" << endl; }
    X(const X &) { cout << "Copy CTOR" << endl; }
    X(X &&)      { cout << "Move CTOR" << endl; }
    int x = 5;
};

X f() 
{
    return X();   // copy CTOR not called for temporary : elision
}

X g() 
{
    X x;
    return x;  // copy CTOR not called : return value optimization
}

void h(X x)    // copy CTOR not called for unbound temporary
{

}

int main()
{
    X x;
    cout << "\ncall f(): returns a temporary by value, but Copy CTOR not called (elision)" << endl;
    f();
    cout << "\ncall g(): returns a bound object by value, but Copy CTOR not called (RVO)" << endl;
    g();
    cout << "\ncall h(): passing a temporary by value, but Copy CTOR not called (elision)" << endl;
    h(X());     // passing an unbound temporary

    cout << "\ncall h(): passing a bound object by value; this time Copy CTOR is called" << endl;
    h(x);       // no elision for bound objects (Copy CTOR will be called)
    try
    {
        cout << "\nthrow temporary and catch by reference; Copy CTOR not called (elision)" << endl;
        throw X();   // throw unbound temporary
    }
    catch(const X& e)  // elision when catch unbound temporary by reference 
    {
        cout << e.x << endl;
    }    
}