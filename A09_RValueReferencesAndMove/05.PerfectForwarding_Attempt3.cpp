////////////////////////////////////////////////////////////
//
//		Perfect Forwarding
//
////////////////////////////////////////////////////////////

#include <utility>
#include <algorithm>
using namespace std;

/*
 *  The problem we are trying to solve with perfect forwarding is: How can we write a function template
 *  that forwards calls to another function template without changing l-vaues into r-values.
 *
 *  In this third attempt we create every possible overload such that perfect forwarding occurs.  
 *  However this solution is not scalable and there has to be a better way!
 */

template<class A1, class A2, class A3>
void f(A1& a1, A2& a2, A3& a3)
{
	// put a breakpoint here and get gdb to check types
    // enter the following in the debug console:
    //    -exec ptype a1
    //    -exec ptype a2
    //    -exec ptype a3    
}

template<class A1, class A2, class A3>
void fwd(A1 const & a1, A2 const & a2, A3 const & a3)
{
    return f(a1, a2, a3);
}

template<class A1, class A2, class A3>
void fwd(A1 & a1, A2 const & a2, A3 const & a3)
{
    return f(a1, a2, a3);
}

template<class A1, class A2, class A3>
void fwd(A1 const & a1, A2 & a2, A3 const & a3)
{
    return f(a1, a2, a3);
}

template<class A1, class A2, class A3>
void fwd(A1 & a1, A2 & a2, A3 const & a3)
{
    return f(a1, a2, a3);
}

template<class A1, class A2, class A3>
void fwd(A1 const & a1, A2 const & a2, A3 & a3)
{
    return f(a1, a2, a3);
}

template<class A1, class A2, class A3>
void fwd(A1 & a1, A2 const & a2, A3 & a3)
{
    return f(a1, a2, a3);
}

template<class A1, class A2, class A3>
void fwd(A1 const & a1, A2 & a2, A3 & a3)
{
    return f(a1, a2, a3);
}

template<class A1, class A2, class A3>
void fwd(A1 & a1, A2 & a2, A3 & a3)
{
    return f(a1, a2, a3);
}

int main()
{
	// This works, but we need 2^N overloads for N parameters
	// In our case we need 8 overloads for 3 parameters
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
