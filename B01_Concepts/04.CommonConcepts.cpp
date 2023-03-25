#include <concepts>
#include <iostream>
#include <vector>
using namespace std;


/* 
 *  The regular concept specifies that a type is regular: copyable, default constructible, and equality 
 *  comparable.  We explore a number of functions that support each of these sub concepts in turn,
 *  culminating in a function that takes a regular type.
 * 
 *  Experiment with switching in the comments to see various lines fail to compile.  Since we are using
 *  concepts, the compiler error messages should be easier to understand.  If you still object to reams
 *  of error messages try just picking out the key lines with grep:
 *         make 2>&1 | grep requires
 */


class X
{
public:
    X(int x):x(x){}

//    X() = delete;
    X():x(0){};     // default constructable

//    X(const X& rhs) = delete;
    X(const X& rhs):x(rhs.x){}      // copyable

//    bool operator==(const X& rhs) = delete;
    bool operator==(const X& rhs) const { return x == rhs.x; }  // equality comparble
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

// change the comments around in class X and then comment out all but one of the function calls below

int main() 
{
    X x(7);
    f1(x);      // copyable
    // f2(x);      // default_initializable
    // f3(x);      // copy_constructible
    // f4(x);      // equality_comparable
    // f(x);       // all of the above
}