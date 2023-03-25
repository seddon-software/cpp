#include <concepts>
#include <iostream>
using namespace std;

/*
 *  When you constrain a template parameter or function templates using concepts, you should use named
 *  concepts or combinations of them. Concepts are meant to be semantic categories, but not syntactic 
 *  constraints like i <= 20. Giving concepts a name enables their reuse.
 * 
 *  Once you've defined a concept you can use it to constrain template parameters as in:
 *          template <isNumber T1, isNumber T2>
 */

// defining a concept
template <typename T>
concept isNumber = is_integral<T>::value || is_floating_point<T>::value;

template <isNumber T1, isNumber T2>
auto average (T1 t1, T2 t2)
{
    return (t1 + t2)/2.0;
}

int main()
{
    cout << average(5, 8) << endl;
    cout << average(5, 8.8) << endl;
    cout << average(3.0, 8.8) << endl;
}
