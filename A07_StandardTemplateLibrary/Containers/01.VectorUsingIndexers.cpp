////////////////////////////////////////////////////////////
//
//      Vector  - using []
//
////////////////////////////////////////////////////////////

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

