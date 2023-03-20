/*
 *  Structured bindings are very similar to tie bindings, but use a different syntax and can be used
 *  with auto to automatically declare vaiables in the calling program.  
 * 
 *  Note: you can't use std::ignore with structured bindings.
 */

#include <string> 
#include <tuple> 
#include <iostream> 

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

/*
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
*/
  
int main() 
{ 
    // using structure bindings 
    auto [x, y, z] = get_data();   // x, y, z are declared implicitly and are copies of returned variables
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;
}
