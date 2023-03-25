/*
 *  Sometimes it is useful to use a hash function in application code.  C++11 provides such function for 
 *  many different types.  In this example we hash from a string to an integer.  Note that if two input
 *  string are close lexically, the hash is not guaranteed to be close (this would be undesirable anyway).
 *  
 *  Because the hash map (<unordered_map>) is provided by C++11, hashing functions are not usually required.
 */

#include <iostream>
#include <string>
#include <string_view>
#include <functional>
#include <memory_resource>

using namespace std;
 
int main()
{
    string jon("Jon"s);
    string john("John");
    string johnny("Johnny");

    cout << hash<string>{}(jon) << endl;
    cout << hash<string>{}(john) << endl;
    cout << hash<string>{}(johnny) << endl;
}

