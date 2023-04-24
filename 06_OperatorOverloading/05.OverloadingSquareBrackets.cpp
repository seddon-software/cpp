/*
 *  The overload of the [] operator is simple enough for 1 dimensional arrays, but much more complicated for
 *  multidimensional arrays.  This is because the operator is only allowed to have a single parameter and
 *  you have arrange for multiple [] overloads in the multi-dimensional case.
 * 
 *  There is talk of allowing multiple parameters to operator [] in C++23.  This would greatly simplify
 *  defining multi-dimensional overloads.  Most people overload the () operator in this scenario, because
 *  operator() does allow multiple parameters (e.g. one for each dimension).
 * 
 *  Finally, operator [] has to be defined as a class method and not as a free function. 
 */

#include <vector>
#include <iostream>
#include <string>
using namespace std;


class MyContainer
{
public:
    MyContainer() {}
    void add(const string& name)
    {
        names.push_back(name);
    }
    string& operator[](int i)
    {
        return names[i];
    }
private:
    vector<string> names;
};

int main()
{
    MyContainer m;
    m.add("Peter");
    m.add("Paul");
    m.add("Mary");
    m.add("Adil");
    // overloading as an r-value
    cout << m[2] << endl;
    // overloading as an l-value (necessitates reference return)
    m[2] = "Jim";   // m.operator[](2) = string("Jim"), which becomes
                    // m.names[2] = string("Jim")
    cout << m[2] << endl;
}
