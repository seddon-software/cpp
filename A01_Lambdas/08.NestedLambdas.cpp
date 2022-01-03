#include <iostream>
using namespace std;

/*  
 *  C++ doesn't allow nested functions (unlike functional languages), but it is now easy to simulate
 *  nested functions (of any depth) with lambdas.  Since lambdas are expressions, they can appear 
 *  inside a function and assigned to a variable, as with g1, g2, g3 or called directly by appending (),
 *  as in the two lambdas defined inside the lambda assigned to g4.
 */

void f()
{
    auto g1 = [](){ cout << "nested lambda 1" << endl; };
    auto g2 = [](){ cout << "nested lambda 2" << endl; };
    auto g3 = [](){ cout << "nested lambda 3" << endl; };
    auto g4 = [](){ 
                    []() { cout << "\tdoubly nested lambda A" << endl; }();
                    []() { cout << "\tdoubly nested lambda B" << endl; }();
                  };
    g1();
    g2();
    g3();
    g4();
}
int main()
{
    f();
}