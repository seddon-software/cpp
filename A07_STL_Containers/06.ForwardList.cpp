////////////////////////////////////////////////////////////
//
//      Forward List
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <forward_list>
#include <algorithm>
using namespace std;

/*
 *  The list class is implemented as a doubly linked list, the forward_list is the equivalent
 *  singly linked list that can only be traversed in one direction.
 */

int main()
{
    // c++11 initializer list syntax:
    forward_list<std::string> words1 {"red", "orange", "yellow", "green", "blue", "indigo", "violet"};

    // copy the list using begin() and end()  
    forward_list<std::string> words2(words1.begin(), words1.end());

    // print out words2 using the for_each algorithm and a lambda
    for_each(words2.begin(), words2.end(), [](const string& w) { cout << w << ","; });
    cout << endl;

    // copy the list implicitly using begin() and end()
    forward_list<std::string> words3(words1);

    // insert a new element at the beginning of the collection
    words3.emplace_front("infra-red");
    for_each(words3.begin(), words3.end(), [](const string& w) { cout << w << ","; });
    cout << endl;
}

