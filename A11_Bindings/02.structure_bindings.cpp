#include <string> 
#include <tuple> 
#include <iostream> 
using namespace std; 
  
struct Point 
{ 
    double x; 
    int y; 
    string z;
    auto f()
    {
        return tuple(x, y, z);
    } 
}; 
  
int main() 
{ 
    Point p = {  3.14159, 2, "hello"s }; 

    // Structure binding 
    auto [x, y, z] = p.f();
    cout << "p = " << x << "," << y << "," << z << endl; 
}
