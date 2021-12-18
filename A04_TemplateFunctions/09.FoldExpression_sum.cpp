#include <iostream>
#include <numeric> //std::iota
#include <vector>

using namespace std;

template<typename... T>
auto sum(T... s)
{
    return (s + ...);  // using a right fold expression
}

int main()
{
    cout << sum(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << endl;
}