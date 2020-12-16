#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#include <iostream>
#include <functional>
using namespace std;



int f(int a, int b)
{
    return a + b;
}


int x;

// define a variable with the same type as x
decltype(x) y;

int main()
{
	using namespace std::placeholders;
	int x = 100;
	decltype(x) y = x;

	// if you are not too sure of a type, let the compile figure it out for you
	auto functionPointer = bind(&f, _1, _2);
	int result = functionPointer(x, y);

	auto fp = &f;			// int (*fp)(int, int) = &f;
	result = fp(10, 20);

	return 0;
}
