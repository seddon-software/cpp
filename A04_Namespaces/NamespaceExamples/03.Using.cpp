#include <iostream>
using namespace std;

/*
 *  Here are some further examples of using directives.  They have the advantage of removing clutter
 *  from the code, but the disadvantage that they effectively pollute the global namespace (often 
 *  called the no-namespace namespace).  Opinions differ on best practice.
 */

namespace A {
    void g(){ cout << "calling A::g()" << endl; };
    void h(){ cout << "calling A::h()" << endl; };
}
namespace B {
    int k;
    void f(){ cout << "in B::f() with B::k= " << k << endl; };
    void g(){};
}

using B::k;  // make symbol accessible for unqualified lookup
using B::f;  // make symbol accessible for unqualified lookup
using namespace A; // make all symbols from A accessible for unqualified lookup (i.e. g and h)

int main()
{
    // unqualified lookup because of "using B::k"
    k = 77;             // B::k = 77
    cout << "B::k= " << k << endl;


    // unqualified lookup  because of "using B::f"
    f();                // B::f()

    // unqualified lookup because of "using namespace A"
    g();                // namespace B is not searched for g()
    h();
}
