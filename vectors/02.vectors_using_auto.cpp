/*
 *  As of C++17 you can let the compiler figure out the type of the vector:
 *                  vector v = {2, 4, 6, 8, 10};
 * 
 *  In previous versions of C++ you had to be explicit:
 *                  vector<int> v = {2, 4, 6, 8, 10};
 * 
 *  When iterating using the for range loop you can use "auto" to declare the range variable:
 *                  for(auto i : v)
 *
 *  By using "auto" you let the compiler to determine the type of the range variable.  This is less error prone
 *  and handy if you later change the type of the vector (no need to change the code). 
 */

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector v = {2, 4, 6, 8, 10};
    for(auto i : v)
    {
	    cout << i << ", " << flush;
    }
    cout << endl;
}
