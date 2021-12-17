#include <iostream>
using namespace std;

// note this concept does not compute a + b, rather it deduces
template<typename T>
concept addable = requires (T a, T b) { a + b; };


template<addable T>
T add(T a, T b)
{
    return a + b;
}

int main()
{
    cout << add(6.3, 7.8) << endl;
}