#include <iostream>
#include <bits/stdc++.h> 
using namespace std; 
  
struct Point 
{ 
    int x; 
    int y; 
    int z;
    auto operator()() 
    { 
        // returns a tuple to make it work with std::tie 
        return make_tuple(x, y, z);  
    }  
}; 
  
int main() 
{ 
    Point p = { 1,2,3 }; 
    int x, y, z;
    // return a tied tuple 
    tie (x, y, z) = p();   // overloaded () operator
      
    cout << "p = " << x << "," << y << "," << z << endl; 
} 