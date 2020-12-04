#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

/*
 *  Here we have a recursive, variadic template to determine memory footprint of
 *  a function's parameter list.
 */

template <typename T>
int footprint(void (*)(T))
{
	T t;
	return sizeof(t);
}

template <typename T, typename ...P>
int footprint(void (*)(T, P... p))
{
	typedef void(*FP)(P...);
	return sizeof(T) + footprint(FP());
}

struct X {int x1, x2, x3, x4, x5;};
struct Y {double x1, x2, x3, x4, x5;};
void f(X, int){}
void g(X, int, double, X){}
void h(X, int, double, Y){}

//Test it
int main()
{
	cout << "f is " << footprint(f) << " bytes in size" << endl;
	cout << "g is " << footprint(g) << " bytes in size" << endl;
	cout << "h is " << footprint(h) << " bytes in size" << endl;
}
