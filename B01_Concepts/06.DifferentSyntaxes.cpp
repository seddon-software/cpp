#include <concepts>
#include <iostream>
using namespace std;

/*
 *  When using concepts there are several ways of adding constraints:
 *          
 *      1. requirement on the template parameter
 *          template<typename T> requires std::integral<T>
 *
 *      2. requirement on the type of the function parameters
 *          auto average(T t1, T t2, T t3) requires std::integral<T> 
 * 
 *      3. using a trait on the template parameter
 *          template<std::integral T>
 *
 *      4. using traits on the function parameters
 *          auto average(std::integral auto t1, ...
 */

// requirement on the template parameter T
template<typename T> requires std::integral<T>
auto average(T t1, T t2) {
    return (t1 + t2)/2.0; 
}

// requirement on the type of the function parameters
template<typename T>
auto average(T t1, T t2, T t3) requires std::integral<T> 
{
    return (t1 + t2 + t3)/3.0; 
}

// using a trait on the template parameter
template<std::integral T>
auto average(T t1, T t2, T t3, T t4) 
{
    return (t1 + t2 + t3 + t4)/4.0; 
}

// using traits on the function parameters
auto average(std::integral auto t1, 
             std::integral auto t2, 
             std::integral auto t3,
             std::integral auto t4, 
             std::integral auto t5) 
{
    return (t1 + t2 + t3 + t4 + t5)/5.0; 
}

int main()
{
    cout << average(10, 20) << endl;
    cout << average(10, 20, 30) << endl;
    cout << average(10, 20, 30, 40) << endl;
    cout << average(10, 20, 30, 40, 50) << endl;
}
