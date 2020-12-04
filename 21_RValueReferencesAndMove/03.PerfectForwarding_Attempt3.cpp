////////////////////////////////////////////////////////////
//
//		Perfect Forwarding
//
////////////////////////////////////////////////////////////

#include <utility>
#include <algorithm>
using namespace std;

template<class A1, class A2, class A3>
void f(A1& a1, A2& a2, A3& a3)
{
	// put a breakpoint here and get the IDE to check types
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
