#include <iostream>
#include <iomanip>
using namespace std;

/*
A nontype template parameter can only one of the following:

integral type (e.g. int or long;)
enumeration type
a pointer or a reference to a (static) object
a pointer or a reference to a function
a pointer to a member of a class.
*/

template <auto value>   // this is called with non functions
bool variables() 
{
    cout << value << endl;
    return true;
}

template <auto fp>      // this is called with functions
void functions(int n) 
{
    cout << fp(n) << endl;
}

// introduce some statics
double x(3.5);
double* ptr = &x;
int f(int n) { return n; }
bool g(int n) { return n; }


int main() 
{
    variables<20>();    // integral type
    variables<&x>();    // pointer to a static
    functions<f>(7);
    functions<g>(3);    // gets converted to bool
}
