//////////////////////////////////////////////////////////////////////
//
//		Generators
//
//////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;


template <typename T2=int, typename T1 = T2(T2, T2, T2)>
auto f(T1 t) -> T2
{
	return t(1, 2, 3);
}

int average(int x1, int x2, int x3)
{
	return (x1 + x2 + x3) / 3;
}

int main()
{

	[[ maybe_unused ]] int result = f(average);
    return 0;
}
