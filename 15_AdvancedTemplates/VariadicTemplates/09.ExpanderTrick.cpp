#include <iostream>
using namespace std;

/*
 *  Pack expansion can occur is inside a braced-init-list.
 *  You can take advantage of this by putting the expansion inside the initializer list of a dummy array.
 */

template <typename T>
void f(T t) { std::cout << t << '\n'; }

template<typename... Args>
void expand(Args &&... args)
{
	__attribute__((unused))
    int dummy[] = { 0, ( (void) f(std::forward<Args>(args)), 0) ... };
    // 1. The 0 ensures array not empty
    // 2. (void) cast to void to ensure that regardless of bar()'s return type
    //    the built-in comma operator is used rather than an overloaded one
	// 3. forward for perfect forwarding
    // 4. comma operator before 0
    // 5. pack with ...
    // 6. {} ensures left to right evaluation
}

template <class... Ts>
void print_all(std::ostream& os, Ts const&... args)
{
	// note the elements of the dummy array can be expressions
	__attribute__((unused))
    int dummy[] {0, (void(os << args << ", "), 0)... };
}

int main()
{
	string cyan("Cyan");
	string def("def");
    expand();
	expand(100, 3.14159, "Red", cyan);
    print_all(cout, 100, 3.14159, "Red", cyan);
}
