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
    cout << "started" << endl;
    collection.push_back("Rome");

    for (unsigned i = 0; i < collection.size(); i++)
    {
        cout << collection[i] << endl;
    }
}

