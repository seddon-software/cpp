#include <iostream>
using namespace std;

/* 
 *  C++17 introduced the idea of using auto to define templates.  The following code:
 *
 *      auto f(auto x, auto y)
 *      {
 *          auto result = x + y;
 *          return result;
 *      }
 * 
 *  is equivalent to:
 * 
 *      template <typename T>
 *      T f(T x, T y)
 *      {
 *          T result = x + y;
 *          return result;
 *      }
 */

auto f(auto x, auto y)
{
    auto result = x + y;
    return result;
}

ostream& operator<<(ostream& os, auto x)
{
    os << x;
    return os;
}

int main()
{
    cout << f(8, 5) << endl;
    cout << f(8.8, 5.5) << endl;
}
