#include <iostream>
#include <functional>
using namespace std;

#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#pragma GCC diagnostic ignored "-Wunused-variable"

int main()
{
	int a = 1, b = 2, c = 3, d = 4;
	using intlink = std::reference_wrapper<int>;
	intlink arr[] =
	{ a, b, c, d };
	a++;
	d++;

	{
		int i;
		auto r = std::ref(i); // r is of type std::reference_wrapper<int>
		auto r2 = std::cref(i); // r is of type std::reference_wrapper<const int>
	}

	{
		int i;
		auto t1 = std::make_tuple(i); // Copies I. Type of t1 is tuple<int>
		auto t2 = std::make_tuple(std::ref(i)); // Saves a reference to i.
												// Type of t2 is tuple<int&>
	}
	return 0;
}
