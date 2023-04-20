#include <functional>
#include <iostream>
using namespace std;

/*
 *  C++20 introduces bind_front as a replacement for bind.  The idea is that you don't need to use 
 *  placeholders.
 * 
 *  Its called bind_front because you only specify the binding parameters that appear at the front
 *  of the function pointer subsequently tag the missing parameters (formerly the placeholders) on when 
 *  the function pointer is called.
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
    auto f1 = std::bind_front(&A::f, &a1);
    auto f2 = std::bind_front(&A::f, &a2);
    auto g1 = std::bind_front(&A::g, &a1);
    auto g2 = std::bind_front(&A::g, &a2);
    cout << f1(3) << endl;
    cout << f2(3) << endl;
    cout << g1(3, 4) << endl;
    cout << g2(3, 4) << endl;
}
