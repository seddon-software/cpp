#include <concepts>
#include <iostream>

/*
 *  In C++20 we can use concepts instead of traits.  Concepts document constraints on the code and often
 *  simplify error messages.  
 * 
 *  Our C++17 example can be rewritten as below:
*/

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


