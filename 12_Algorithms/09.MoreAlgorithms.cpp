/*
 *  Here are a few more example of algorithms:
 *              for_each(collection.begin(), collection.end(), Print);
 *              find(collection.begin(), collection.end(), item4);
 *              find_if(collection.begin(), collection.end(), LessThan21K);
 *              replace(collection.begin(), collection.end(), item4, item2);
 */

#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

using Pair = pair<string, int>;

void Print(const Pair& p)
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
    list<pair<string,int>> salary = {
        {"Steven"s, 25000},
        {"Mary"s,   28000},
        {"John"s,   20000},
        {"Susan"s,  36500},
        {"Rose"s,   17500}
    };
    
    pair<string,int> susan{"Susan"s, 36500};
    pair<string,int> mary{"Mary"s, 28000};

    // print entire collection
    cout << "Printing Collection" << endl;
    for_each(salary.begin(), salary.end(), Print);

    // search for Susan
    cout << endl << "(desperately) Searching for susan" << endl;
    auto i = find(salary.begin(), salary.end(), susan);
    Print(*i);

    // search for first item that earns less than $21,000
    cout << endl << "Searching for first item that earns less than 21,000" << endl;
    i = find_if(salary.begin(), salary.end(), LessThan21K);
    Print(*i);

    // replace mary with susan
    cout << endl << "Replacing mary with susan" << endl;
    replace(salary.begin(), salary.end(), mary, susan);
    for_each(salary.begin(), salary.end(), Print);
}
