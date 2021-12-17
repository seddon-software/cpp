#include <iostream>
#include <vector>
using namespace std;

struct MyClass
{
    MyClass() { }
    MyClass(MyClass&&) noexcept
    {
    	cout << "Move" << this << endl;
    }
    MyClass(const MyClass&)
    {
    	cout << "Copy" << this << endl;
    }
};


int main()
{
    vector<MyClass> v(6);
    MyClass m1, m2, m3;
    v.push_back(m1);
    v.push_back(m2);
    v.push_back(m3);
    v.push_back(MyClass());
    v.push_back(MyClass());
    v.push_back(MyClass());
}
