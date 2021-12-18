#include <iostream>
using namespace std;

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