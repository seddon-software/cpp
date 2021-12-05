#include <iostream>
#include <tuple>
#include <string>

using namespace std; 
  
struct Point 
{ 
    double x; 
    int y; 
    string z;
    auto f() 
    { 
        // returns a tuple to make it work with std::tie 
        // tie constructs a tuple object whose elements are references to the arguments in args 
        // and in the same order.  This allows a set of objects to act as a tuple, which is 
        // especially useful when returning multiple objects.
        return tuple(x, y, z);  
    }  
}; 
  
int main() 
{ 
    Point p = { 3.14159, 2, "hello" }; 
    double x; 
    int y; 
    string z;
    // return a tied tuple 
    tie (x, y, z) = p.f(); // unpack the tuple
      
    cout << "p = " << x << "," << y << "," << z << endl; 
} 