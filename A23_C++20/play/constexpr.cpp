#include <iostream>
using namespace std;

consteval int cube(int x)       // this function is used to calculate compile time constants
{
    return x * x * x;
}

constexpr auto n(cube(10));     // n evaluated at compile time

int main()
{
    cout << n << endl;
    const int n(5);
    int result1 = cube(n);
    int m(5);
    // int result2 = cube(m); // doesn't compile becuse m is not a compile time constant 
}