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
    m[2] = "Jim";
    cout << m[2] << endl;
}
