////////////////////////////////////////////////////////////
//
//      Vector  - using []
//
////////////////////////////////////////////////////////////

/*  
 *  Vectors are templated sequence containers representing arrays that can change in size.  vectors 
 *  use contiguous storage locations for their elements, which means that their elements can also be 
 *  accessed using offsets on regular pointers to its elements, and just as efficiently as in arrays; 
 *  we say a vector supports "random-access".  Unlike arrays, vectors can change their size dynamically, 
 *  with their storage being handled automatically by the container.
 * 
 *  Because vectors support random access, it is natural that they overload the [] operator.  The 
 *  example below is based on [] access.  The push_back() method allows the vector to grow dynamically.
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> collection;

    collection.push_back("London");
    collection.push_back("Madrid");
    collection.push_back("New York");
    collection.push_back("Tokyo");
    collection.push_back("Rome");

    for (unsigned i = 0; i < collection.size(); i++)
    {
        cout << collection[i] << endl;
    }
}

