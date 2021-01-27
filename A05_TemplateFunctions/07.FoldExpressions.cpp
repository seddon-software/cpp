/*
 *  Fold Expressions (C++17) are an alternative to recursive variadic templates
 */

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class I
{
friend ostream& operator<<(ostream& os, const I& i);
public:
    I(const string& s): s(s) {}
    I(int i=0): s() 
    {
        stringstream ss; 
        ss << i;
        s = ss.str();
    }
public:
    string s;
};
ostream& operator<<(ostream& os, const I& i)
{
    return os << i.s;
}

auto operator+(const I& s1, const I& s2)
{
    string s;
    s = s + "(" + s1.s + "+" + s2.s + ")";
    // cout << s << endl; 
    return I(s);
}

template<typename... T>
auto right_fold(T... s)
{
    cout << "right_fold" << endl;
    return (s + ...);
}
template<typename... T>
auto right_fold_with_initializer(int a, T... s)
{
    cout << "right_fold with initializer: " << a << endl;
    return (s + ... + I(a));
}

template<typename... T>
auto left_fold(T... s){
    cout << "left_fold" << endl;
    return (... + s);
}
template<typename... T>
auto left_fold_with_initializer(int a, T... s){
    cout << "left_fold with initializer:" << a << endl;
    return (I(a) + ... + s);        // fold over +
}

int main()
{
    cout << right_fold(I(1), I(2), I(3), I(4), I(5)) << endl;
    cout << right_fold_with_initializer(88, I(1), I(2), I(3), I(4), I(5)) << endl;
    cout << left_fold(I(1), I(2), I(3), I(4), I(5)) << endl;
    cout << left_fold_with_initializer(99, I(1), I(2), I(3), I(4), I(5)) << endl;
}