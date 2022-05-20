#include <iostream>
#include <tuple>
#include <string>

using namespace std; 

/*
 *  When working with tuples you can use get<N> to extract the Nth element of the tuple.  Unfortunately, N has
 *  to be determined at compile time, so you can't write something like:
 *              int n;
 *              tuple t = {100, 2.71828, "Euler"}; 
 *              cin >> n
 *              auto x = get<n>(t)
 * 
 *  This is probably because the compiler won't know the return type of get<n>(t) at compile time and hence
 *  can't declare x.
 */

int main() 
{
    tuple t = {100, 2.71828, "Euler"}; 
    cout << "int = " << get<0>(t) << endl;
    cout << "double = " << get<1>(t) << endl;
    cout << "string = " << get<2>(t) << endl;
} 

