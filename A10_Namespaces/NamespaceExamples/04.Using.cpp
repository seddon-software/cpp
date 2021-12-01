#include <iostream>
using namespace std;

namespace A {
  void g(){ cout << "A::g()" << endl; };
  void h(){ cout << "A::h()" << endl; };
}
namespace B {
  int k;
  void f(){ cout << k << endl; };
  void g(){};
}

using B::k;  // make symbol  accessible for unqualified lookup
using B::f;  // make symbol  accessible for unqualified lookup
using namespace A; // make all symbols from A accessible for unqualified lookup (i.e. g and h)

int main()
{
    k = 77;    // B::k = 77
    cout << k << endl;
    f();       // B::f()
    g();
    h();
}
