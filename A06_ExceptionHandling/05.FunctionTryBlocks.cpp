////////////////////////////////////////////////////////////
//
//		Function Try Blocks
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <stdexcept>
using namespace std;

/*  This example is adapted from cppreference.com
 *  According to cppreference.com, the primary purpose of function-try-blocks is to respond to an 
 *  exception thrown from the member initializer list in a CTOR.  These try blocks are rarely used
 *  with other functions.
 */

#include <iostream>
#include <exception>
#include <string>
using namespace std;


// The MySubstring CTOR uses the following CTOR of the std:string class ...
//     string(const string& other, size_type pos)

// ... which creates a substring of "other" starting at pos

struct MySubstring
{
    MySubstring(const string& s, int n)
        try : substring(s, n)   // initialization list may throw 
        {
        } 
        catch(const exception& e) 
        {
            cout << "CTOR throws: " << e.what() << endl; // implicitly rethrows
        }
    void display() 
    {
        cout << substring << endl; 
    }
private:
    string substring;
};
int main() 
{
    try
    {
    
        MySubstring s1{"ABC_XYZ", 4}; // does not throw (index is in bounds)
        s1.display();

        MySubstring s2{"ABC_XYZ", 9};     // throws (out of bounds)
        s2.display();
    }
    catch(const exception& e)
    {
        std::cerr << "Handler: " << e.what() << endl;
    }   
}