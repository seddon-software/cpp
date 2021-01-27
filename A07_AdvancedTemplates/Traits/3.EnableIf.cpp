#include <cstddef>
#include <iostream>
#include <type_traits>


template<class T>
typename std::enable_if<std::is_floating_point<T>::value, T>::type
    foo(T t)
{
    std::cout << "float\n";
    return t;
}

template<class T>
typename std::enable_if<std::is_integral<T>::value, T>::type
    foo(T t)
{
    std::cout << "int\n";
    return t;
}

int main()
{
	foo(4.4);
	foo(66);
}
