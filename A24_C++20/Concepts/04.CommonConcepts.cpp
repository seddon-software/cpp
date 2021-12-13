#include <concepts>
#include <iostream>
#include <vector>
using namespace std;

class X
{
public:
    X(int x):x(x){}

//    X() = delete;
    X():x(0){};

//    X(const X& rhs) = delete;
    X(const X& rhs):x(rhs.x){}

//    bool operator==(const X& rhs) = delete;
    bool operator==(const X& rhs) const { return x == rhs.x; }
private:
    int x;
};

template <copyable T>
void f1(T) {}

template <default_initializable T>
void f2(T) {}

template <copy_constructible T>
void f3(T) {}

template <equality_comparable T>
void f4(T) {}

template <std::regular T>
void f(T) {}


// The regular concept specifies that a type is regular: 
// copyable, default constructible, and equality comparable

int main() 
{
    X x(7);
    f1(x);      // copyable
    f2(x);      // default_initializable
    f3(x);      // copy_constructible
    f4(x);      // equality_comparable
    f(x);       // all of the above
}