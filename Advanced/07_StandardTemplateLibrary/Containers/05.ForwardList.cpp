////////////////////////////////////////////////////////////
//
//      Forward List
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <forward_list>
#include <algorithm>
#pragma GCC diagnostic ignored "-Wunused-variable"
using namespace std;


int main()
{
    // c++11 initializer list syntax:
    forward_list<std::string> words1 {"red", "orange", "yellow", "green", "blue", "indigo", "violet"};

    // words2(words1)
    forward_list<std::string> words2(words1.begin(), words1.end());

    // words3(words1)
    forward_list<std::string> words3(words1);

    // print out words1 and words2
    for_each(words2.begin(), words2.end(), [](const string& w)
    {
        cout << w << ",";
    });
    cout << endl;

    // inserts a new element at the beginning of the collection
    words3.emplace_front("infra-red");
    for_each(words3.begin(), words3.end(), [](const string& w)
    {
        cout << w << ",";
    });
    cout << endl;
}

