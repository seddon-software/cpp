/*
 *  C++ uses the vector class to replace C's array type.  However, because the vector is dynamic, it is not
 *  as efficient as a fixed size array.  C++11 introduced a fixed size template array class to remidy this as
 *  a drop in replacement for fixed size vectors.
 */

#include <iostream>
#include <array>
using namespace std;

int main()
{
    array v = {2, 4, 6, 8, 10};   // fixed size
    
    for(auto i : v)
    {
	    cout << i << ", " << flush;
    }
    cout << endl;
}
