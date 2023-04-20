/*
 *  The problem we are trying to solve with perfect forwarding is: How can we write a function template
 *  that forwards calls to another function template without changing l-values into r-values.
 *
 *  In this next attempt we make each parameter const (r-value reference).  This time everything compiles,
 *  but l-values get changed to const (r-values) and this is not perfect forwarding.
 */

#include <type_traits>
#include <iostream>
using namespace std;

template<class A1, class A2, class A3>
void f(const A1& a1, const A2& a2, const A3& a3)
{
}

template<class A1, class A2, class A3>
void fwd(A1 const & a1, A2 const & a2, A3 const & a3)
{
    return f(a1, a2, a3);
}

int main()
{
	// This time the forwarding compiles for all cases, 
    // but all parameters are changed into const (undesirable)
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
