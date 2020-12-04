#include <iostream>
#include <list>
#include <string>

using namespace std;

int main()
{
    list<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    for(auto i = v.begin(); i != v.end(); ++i)
    {
    	cout << *i << endl;
    }
}
