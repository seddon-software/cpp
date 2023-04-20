/*
 *  The problem we are trying to solve with perfect forwarding is: How can we write a function template
 *  that forwards calls to another function template without changing l-values into r-values.
 *
 *  In this third attempt we create every possible overload such that perfect forwarding occurs.  
 *  However this solution is not scalable and there has to be a better way!
 */

#include <type_traits>
#include <iostream>
using namespace std;

////////////////////////////////////// f templates //////////////////////////////
// 1
template<class A1, class A2, class A3>
void f(A1& a1, A2& a2, A3& a3)
{
}

// 2
template<class A1, class A2, class A3>
void f(A1 & a1, A2 & a2, A3 const & a3)
{
}

// 3
template<class A1, class A2, class A3>
void f(A1 & a1, A2 const & a2, A3 & a3)
{
}

// 4
template<class A1, class A2, class A3>
void f(A1 & a1, A2 const & a2, A3 const & a3)
{
}

// 5
template<class A1, class A2, class A3>
void f(A1 const & a1, A2 & a2, A3 & a3)
{
}

// 6
template<class A1, class A2, class A3>
void f(A1 const & a1, A2 & a2, A3 const & a3)
{
}

// 7
template<class A1, class A2, class A3>
void f(A1 const & a1, A2 const & a2, A3 & a3)
{
}

// 8
template<class A1, class A2, class A3>
void f(A1 const & a1, A2 const & a2, A3 const & a3)
{
}

////////////////////////////////////// fwd templates //////////////////////////////
// 1
template<class A1, class A2, class A3>
void fwd(A1 & a1, A2 & a2, A3 & a3)
{
    return f(a1, a2, a3);
}

// 2
template<class A1, class A2, class A3>
void fwd(A1 & a1, A2 & a2, A3 const & a3)
{
    return f(a1, a2, a3);
}

// 3
template<class A1, class A2, class A3>
void fwd(A1 & a1, A2 const & a2, A3 & a3)
{
    return f(a1, a2, a3);
}

// 4
template<class A1, class A2, class A3>
void fwd(A1 & a1, A2 const & a2, A3 const & a3)
{
    return f(a1, a2, a3);
}

// 5
template<class A1, class A2, class A3>
void fwd(A1 const & a1, A2 & a2, A3 & a3)
{
    return f(a1, a2, a3);
}

// 6
template<class A1, class A2, class A3>
void fwd(A1 const & a1, A2 & a2, A3 const & a3)
{
    return f(a1, a2, a3);
}

// 7
template<class A1, class A2, class A3>
void fwd(A1 const & a1, A2 const & a2, A3 & a3)
{
    return f(a1, a2, a3);
}

// 8
template<class A1, class A2, class A3>
void fwd(A1 const & a1, A2 const & a2, A3 const & a3)
{
    return f(a1, a2, a3);
}

////////////////////////////////////// main //////////////////////////////
int main()
{
	// This works, but we need 2^N overloads for N parameters
	// In our case we need 8 overloads for 3 parameters
	int x{1}, y{2}, z{3};
    fwd(x, y, z);       // 1
    fwd(x, y, 3);       // 2
    fwd(x, 2, z);       // 3
    fwd(x, 2, 3);       // 4
    fwd(1, y, z);       // 5
    fwd(1, y, 3);       // 6
    fwd(1, 2, z);       // 7
    fwd(1, 2, 3);       // 8
}
