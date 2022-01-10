#include <functional>
#include <iostream>
using namespace std;

/*
 *  C++20 introduces bind_front as a replacement for bind.  The idea is that you don't need to use 
 *  placeholders - you can bind and make the callback immediately.
 * 
 *  There are a few use cases where bind_front doesn't replace bind, but in most cases its much simpler
 *  to use and is clearer than using lambda expressions.
 */

class A 
{
private:
    int x;
public:
    A(int x) :x(x) {}
    int f(int y)
    {
        return x + y;
    }
    int g(int y, int z)
    {
        return x + y + z;
    }
};

int main() 
{
    A a1(10);
    A a2(20);
    cout << std::bind_front(&A::f, &a1)(3) << endl;
    cout << std::bind_front(&A::f, &a2)(3) << endl;
    cout << std::bind_front(&A::g, &a1)(3, 4) << endl;
    cout << std::bind_front(&A::g, &a2)(3, 4) << endl;
}
