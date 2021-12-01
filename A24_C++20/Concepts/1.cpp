#include <type_traits>
template<typename T>
T add(T a, T b)
{
  static_assert(std::is_integral_v<T>);
  return a + b;
}

int main()
{
    // uncomment the next line to see compiler error
    // add(5.0, 7.0); // fails to compile
    add(5, 7);

}