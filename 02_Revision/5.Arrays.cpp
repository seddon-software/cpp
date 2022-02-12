////////////////////////////////////////////////////////////
//
//      Using vector instead of C arrays
//
////////////////////////////////////////////////////////////

#include <vector>
#include <iostream>
using namespace std;

/*  
 *  C++ uses the vector class in place of C style arrays.  In C, arrays were of fixed size, 
 *  whereas the vector grows as you add more items.  You initialise vectors in the ame way as
 *  C arrays, i.e. use {}.  To dynamically add elements, use the push_back() method.
 */

int main()
{
    // C++ vectors are variable size
    vector<int> numbers = {2, 3, 5, 7, 11};
    for(auto number : numbers)
    {
        cout << number << "," << flush;
    }
    cout << endl;

    // dynamically add numbers
    numbers.push_back(13);
    numbers.push_back(17);
    
    for(auto number : numbers)
    {
        cout << number << "," << flush;
    }
    cout << endl;
}
