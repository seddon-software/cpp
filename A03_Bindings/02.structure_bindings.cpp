#include <string> 
#include <tuple> 
#include <iostream> 
using namespace std; 

/*
 *  Structured bindings are very similar to tie bindings, but use a different syntax and can be used
 *  with auto to automatically declare vaiables in the calling program.  
 * 
 *  Note: you can't use std::ignore with structured bindings.
 */

struct Point 
{ 
    double x; 
    int y; 
    string z;
    auto get()
    {
        return tuple(x, y, z);
    } 
}; 
  
int main() 
{ 
    Point p {.x = 3.14159, .y = 2, .z = "hello" }; 

    // structure binding 
    auto [x, y, z] = p.get();   // x, y, z are declared implicitly and are copies of returned variables
    cout << "p = " << x << "," << y << "," << z << endl; 
}
