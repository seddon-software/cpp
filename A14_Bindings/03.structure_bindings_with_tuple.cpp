#include <tuple> 
#include <string> 
#include <iostream> 
using namespace std; 

/*  
 *  Structured bindings can be used to unpack tuples.  You can unpack into references or into copies.
 *  When unpacking into references, any update in the reference will be reflected in the original
 *  tuple.  
 */

int main() 
{ 
      
    // Structure binding with references
    {
        auto t = tuple("Hello"s, 5, 10.7); 
        auto& [a1, a2, a3] = t;   // bind to references
        cout << "t = " << a1 << "," << a2 << "," << a3 << endl; 
        a1 += " World";
        a2++;
        a3 += 0.4; 
        auto [b1, b2, b3] = t;
        cout << "t = " << b1 << "," << b2 << "," << b3 << endl << endl; 
    }
    // Structure binding with copies (doesn't change tuple)
    {
        auto t = tuple("Hello"s, 5, 10.7); 
        auto [a1, a2, a3] = t;   // bind to copies
        cout << "t = " << a1 << "," << a2 << "," << a3 << endl; 
        a1 += " World";
        a2++;
        a3 += 0.4; 
        auto [b1, b2, b3] = t;
        cout << "t = " << b1 << "," << b2 << "," << b3 << endl << endl; 
    }
}
