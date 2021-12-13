/*
   In C++, constraints on type parameters can also be specified as static_assert statements 
   inside a function call or class definition. A function that adds two integral types will 
   look like this in C++17:
*/
#include <type_traits>
template<typename T>
T add(T a, T b)
{
  static_assert(std::is_integral_v<T>);  // is_integral_v<T> is equivalent to is_integral<T>::value
  return a + b;
}

int main()
{
    add(4, 5);
}
