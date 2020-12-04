#include <iostream>
using namespace std;

/*
 *  decltype can simplify declarations, particularily when passing a function pointer
 */

int f(int a, int b)
{
	return a + b;
}

int g1(int a, int b, decltype(f)* pf)   // int g(int, int, int(*)(int,int))
{
	return a + pf(a, b);
}

using FP = decltype(f);
int g2(int a, int b, FP* pf)   // int g(int, int, int(*)(int,int))
{
	return a + pf(a, b);
}

int main()
{
	cout << f(30, 40) << endl;;
	cout << g1(100, 110, f) << endl;;
	cout << g2(200, 210, f) << endl;;
}
