////////////////////////////////////////////////////////////
//
//      List - algorithms
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

typedef pair<string, int> Pair;

void Print(Pair& p)
{
    cout << p.first << ", " << p.second << endl; 
}


bool LessThan21K(const Pair& p)
{
    if (p.second < 21000)
        return true;
    else
        return false;
}

/////

int main()
{
    list<Pair> collection;
    list<Pair>::iterator i;

    Pair item1 = make_pair("Steven", 25000);
    Pair item2 = make_pair("Mary",   28000);
    Pair item3 = make_pair("John",   20000);
    Pair item4 = make_pair("Susan",  36500);
    Pair item5 = make_pair("Rose",   17500);

    collection.push_back(item1);
    collection.push_back(item2);
    collection.push_back(item3);
    collection.push_back(item4);
    collection.push_back(item5);
    
    // print entire collection
    cout << "Printing Collection" << endl;
    for_each(collection.begin(), collection.end(), Print);

    // search for item4
    cout << endl << "Searching for item4" << endl;
    i = find(collection.begin(), collection.end(), item4);
    Print(*i);

    // search for first item that earns less than �21,000
    cout << endl << "Searching for first item that earns less than 21,000" << endl;
    i = find_if(collection.begin(), collection.end(), LessThan21K);
    Print(*i);

    // replace item2 with item4
    cout << endl << "Replacing item4 with item2" << endl;
    replace(collection.begin(), collection.end(), item4, item2);
    for_each(collection.begin(), collection.end(), Print);
}
