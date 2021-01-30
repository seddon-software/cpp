#include <bits/stdc++.h> 
using namespace std; 
  
struct Point 
{ 
    int x; 
    int y; 
    int z; 
}; 
  
int main() 
{ 
    Point p = { 1,2,3 }; 
      
    // Structure binding 
    auto [x, y, z] = p;
    cout << "p = " << x << "," << y << "," << z << endl; 
}
