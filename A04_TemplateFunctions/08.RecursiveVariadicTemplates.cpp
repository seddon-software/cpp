#include <iostream>
using namespace std;

/*
 *  C++11 introduced variadic templates.  These templates use parameter packs to support templates 
 *  with a variable number of parameters.
 */

//generic template
template<typename T>
T Sum(T t){
    return t;
}

//specialized template with at least two parameters
template<typename T, typename... P>
auto Sum(T s, P... pp)
{
    return s + Sum(pp...);
}

int main()
{
    cout << Sum(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << endl;
}
