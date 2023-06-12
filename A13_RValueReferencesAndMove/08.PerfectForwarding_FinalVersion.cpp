/*
 *  The problem we are trying to solve with perfect forwarding is: How can we write a function template
 *  that forwards calls to another function template without changing l-vaues into r-values.
 *
 *  In this final attempt we use r-value references and rely on the collapsing rules discussed earlier
 *  to make sure l-values don't get changed to r-values.
 */

#include <type_traits>
#include <iostream>
using namespace std;

#define CHECK(object)                                \
    if(is_lvalue_reference<decltype(object)>::value) \
        cout << boolalpha << "l";                    \
    else                                             \
        cout << boolalpha << "r";


template<class A1, class A2, class A3>
void f(A1&& a1, A2&& a2, A3&& a3)
{
    CHECK(a1)
    CHECK(a2)
    CHECK(a3)
    cout << endl;
}


template<class A1, class A2, class A3>
void fwd(A1 && a1, A2 && a2, A3 && a3)
{
	// std::forward is syntactic suger for a static cast
	//    return f(static_cast<A1 &&>(a1), static_cast<A2 &&>(a2), static_cast<A3 &&>(a3));
    return f(std::forward<A1>(a1), std::forward<A2>(a2), std::forward<A3>(a3));
}

int main()
{
	// The above achieves perfect forwarding:
	//	l-values are forwarded as l-values
	//	r-values are forwarded as r-values
	int x{1}, y{2}, z{3};
    fwd(x, y, z);
    fwd(x, y, 3);
    fwd(x, 2, z);
    fwd(x, 2, 3);
    fwd(1, y, z);
    fwd(1, y, 3);
    fwd(1, 2, z);
    fwd(1, 2, 3);
}
