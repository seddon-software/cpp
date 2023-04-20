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
 *  that forwards calls to another function template without changing l-values into r-values.
 *
 *  In this next attempt we make each parameter const (r-value reference).  This time everything compiles,
 *  but l-value refs get changed to r-value refs (not perfect forwarding).
 */

template<class A1, class A2, class A3>
void f(const A1& a1, const A2& a2, const A3& a3)
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

int main()
{
	// This time the forwarding works for all cases, but l-values get
	// changed into r-values (undesirable)
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
