#include <iostream>
#include <iomanip>
using namespace std;

/*
 *  Templates normally take typenames as parameter.  However templates can also take two other parameter
 *  types:
 *      Non type parameters
 *      Other templates as parameters
 * 
 *  This example focusses on the former.  A non-type template parameter can only one of the following:
 *      integral type (e.g. int or long;)
 *      enumeration type
 *      a pointer or a reference to a (static) object
 *      a pointer or a reference to a function
 *      a pointer to a member of a class.
 *
 *  Some examples are shown below: 
 */

template <auto value>   // this is called with variables (not functions)
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
