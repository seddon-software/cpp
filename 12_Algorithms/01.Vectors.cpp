/*
 *  Vectors are dynamic arrays.  That is they are variable sized and can be expanded or contracted at
 *  runtime.  The most common method of a vector is push_back() which adds a new entry to the end of the
 *  vector.
 * 
 *  You can then use [] brackets to extract values from the vector. 
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

