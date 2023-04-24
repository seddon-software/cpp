/*  
 *  CTORs may throw exceptions.  If a composite object throws, then DTORs are only called on the 
 *  parts that were constructed before the throw.  
 * 
 *  In this example we have a and X object consisting of 4 sub objects: A, B, C and D; the example 
 *  shows what happens when various CTORs throw.  Note that as soon as a sub object CTOR throws, the
 *  catch handler is called and the other constructors don't have a chance to execute.
 */

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

struct A 
{
    A(int a): a(a) { 
        if (a < 0) 
            throw runtime_error("CTOR A failed"); 
        else 
            cout << "CTOR A succeeded\n";
    }
    ~A() { cout << "DTOR A called\n"; }
    int a;
};
struct B
{
    B(int b): b(b) { 
        if (b < 0) 
            throw runtime_error("CTOR B failed"); 
        else 
            cout << "CTOR B succeeded\n";
    }
    ~B() { cout << "DTOR B called\n"; }
    int b;
};
struct C 
{
    C(int c): c(c) { 
        if (c < 0) 
            throw runtime_error("CTOR C failed"); 
        else 
            cout << "CTOR C succeeded\n";
    }
    ~C() { cout << "DTOR C called\n"; }
    int c;
};
struct D 
{
    D(int d): d(d) { 
        if (d < 0) 
            throw runtime_error("CTOR D failed"); 
        else 
            cout << "CTOR D succeeded\n";
    }
    ~D() { cout << "DTOR D called\n"; }
    int d;
};

struct X
{
    X(int a, int b, int c, int d): a(a), b(b), c(c), d(d) {}
    A a;
    B b;
    C c;
    D d;
};

int main()
{
	// exceptions are thrown in various CTORs
	// note that DTORs are only called (in reverse order) for objects fully constructed
    try
    {
        cout << endl << "1 2 3 4" << endl;
        X(1, 2, 3, 4);   cout << "\n";  // OK
        cout << endl << "1 2 3 -4" << endl;
        X(1, 2, 3, -4);  cout << "\n";  // fails
    }
    catch(const runtime_error& e) 
    {
        cout << e.what() << endl;
    }
    try
    {
        cout << endl << "1 2 -3 4" << endl;
        X(1, 2, -3, 4); cout << "\n";  // fails
    }
    catch(const runtime_error& e) 
    {
        cout << e.what() << endl;
    }
    try
    {
        cout << endl << "1 -2 3 4" << endl;
        X(1, -2, 3, 4); cout << "\n";  // fails
    }
    catch(const runtime_error& e) 
    {
        cout << e.what() << endl;
    }
    try
    {
        cout << endl << "-1 2 3 4" << endl;
        X(-1, 2, 3, 4); cout << "\n";  // fails
    }
    catch(const runtime_error& e) 
    {
        cout << e.what() << endl;
    }
}
