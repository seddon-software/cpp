#include <bits/stdc++.h> 
using namespace std; 
  
int main() 
{ 
    auto t = make_tuple(string("Hello"), 5, 10.7); 
      
    // Structure binding with l-values (references)
    auto& [t1, t2, t3] = t;
    cout << "t = " << t1 << "," << t2 << "," << t3 << endl; 
    t1 += " World";
    t2++;
    t3 += 0.4; 
    cout << "t = " << t1 << "," << t2 << "," << t3 << endl; 

    // Structure binding with r-values (doesn't change tuple)
    auto [t4, t5, t6] = t;
    t4 += " World";
    t5++;
    t6 += 0.4; 
    auto [t7, t8, t9] = t;
    cout << "t = " << t7 << "," << t8 << "," << t9 << endl; 
}
