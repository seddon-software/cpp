#include <concepts>
#include <iostream>


template<typename T> requires std::integral<T> 
T add(T a, T b)
{
    return a + b;
}


int main()
{
    // add(5.0, 7.0); // T = NOT integral
    std::cout << add(5, 7) << std::endl;
}