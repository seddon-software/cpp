#include <concepts>
template<std::integral T>
T add(T a, T b)
{
  return a + b;
}

int main()
{
    // uncomment the next line to see compiler error
    // add(5.0, 7.0);  // doesn't compile
    add(5, 7);
}