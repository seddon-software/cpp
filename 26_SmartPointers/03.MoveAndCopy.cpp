#include <iostream>
#include <vector>
using namespace std;

struct MyClass
{
    MyClass() { }
    MyClass(MyClass&&) noexcept
    {
    	cout << "Move" << endl;
    }
    MyClass(const MyClass&)
    {
    	cout << "Copy" << endl;
    }
};


int main()
{
    vector<MyClass> v;
    v.resize(3);
    cout << "---" << endl;
    v.push_back(MyClass());
    v.push_back(MyClass());
    v.push_back(MyClass());
}
