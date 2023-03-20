/*
 *  tie binding allow you to return multiple results from a function by utilising a tuple in the called
 *  function.  The calling function uses std::tie to unpack the return values.
 * 
 *  Note: you must explicitly declare variable to be used in tie bindings.  As we will see in the next
 *  example this restriction is not present with structure bindings, so that most people will use them
 *  in preference to tie bindings.
 */

#include <iostream>
#include <tuple>
#include <string>

using namespace std; 

auto get_data()
{
    int a;
    double b;
    string c;
    cout << "Enter data (int, double, string): " << flush;
    cin >> a >> b >> c;
    return tuple{a, b, c};      // return 3 items
}  


int main() 
{
    int x; 
    double y; 
    string z;
    std::tie (x, y, z) = get_data(); // unpack the tied tuple  
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;
} 

