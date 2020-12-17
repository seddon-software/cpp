////////////////////////////////////////////////////////////
//
//		Perfect Forwarding
//
////////////////////////////////////////////////////////////

#include <utility>
#include <algorithm>
using namespace std;

template<class A1, class A2, class A3>
void f(A1&& a1, A2&& a2, A3&& a3)
{
	// put a breakpoint here and get the IDE to check types
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
	// This achieves perfect forwarding:
	//	l-vlues are forwarded as l-values
	//	r-vlues are forwarded as r-values
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
