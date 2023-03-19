#include <iostream>
using namespace std;

/* 
 *  What happens if we make a function call and there is a choice between a template function
 *  and a normal function, but the parameters do not match exactly?
 * 
 *  The compiler will try to call the function in preference to the template.  It will perform type
 *  conversion and call the function in preference to calling the template.
 */

template <typename T>
void f(T t1, T t2) 
{
    cout << "template called with t1 = " << t1 << ", t2 =" << t2 << endl;
}

void f(int t1, int t2) 
{
    cout << "function called with t1 = " << t1 << ", t2 =" << t2 << endl;
}

int main()
{
    f(1, 2);                // this calls the function in preference to the template
    f(1.2345, 2);           // this converts the first parameter to int and again calls the function
    f(1.2345, 2.3456);      // this calls the template
}