#include <iostream>
#include <tuple>
#include <string>

using namespace std; 

/*  
 *  std::tie was introduced to allow functions to return multiple return values.  Functions can
 *  now return a tuple and the caller can use std::tie to unpack the return values.  std::tie 
 *  constructs a tuple object whose elements are references to the returned arguments
 *  and in the same order.  
 * 
 *  Notes: 
 *      1) You can use std::ignore placeholder to skip an element when unpacking the returned tuple.
 *      2) Structured bindings largely replace std::tie (see later examples). 
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
    double x; 
    int y; 
    string z;
    std::tie (x, y, z) = p.get(); // unpack the tied tuple  
    cout << "p = " << x << "," << y << "," << z << endl; 
    std::tie(x, std::ignore, z) = p.get(); // ignore parameter 2  
} 