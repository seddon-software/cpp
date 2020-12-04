#include <iostream>
//using namespace std;


/*
 * This SFINAE example shows how the enable_if traits works
 * see the <type_traits> header file for similar standard definitions
 */

///// enable_if template
//
// generic template
template<bool B, class T = void>
struct enableIf {};

// specialization on B = true
template<class T>
struct enableIf<true, T>
{
	typedef T type;
};


///// template f()
//
// Notes:
// 1. the intention is to never supply the second template parameter
// 2. a typical call is f<11>()
// 3. hence T can be defaulted to anything other than void (we choose int)
// 4. since f() will always be called with 0 parameters, we default parameter 1 (e.g. = 0)
template <int N, typename T = int>
// N % 2 == 0 will evaluate to true (N = 0, 2, 4 ...) or false (N = 1, 3, 5 ...)
// enableIf template only specializes on true
// substition only works for N = 0, 2, 4, ...
void f(typename enableIf<N % 2 == 0, T>::type = 0)
{
	std::cout << N << " is EVEN" << std::endl;
}

template <int N, typename T = int>
// N % 2 == 1 will evaluate to true (N = 1, 3, 5 ...) or false (N = 0, 2, 4 ...)
// enableIf template only specializes on true
// substition only works for N = 1, 3, 5, ...
void f(typename enableIf<N % 2 == 1, T>::type = 0)
{
	std::cout << N << " is ODD" << std::endl;
}



int main()
{
	f<11>();
	f<44>();
	return 0;
}
