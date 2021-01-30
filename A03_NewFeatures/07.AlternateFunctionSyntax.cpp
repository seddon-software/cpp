#include <iostream>
using namespace std;

// auto introduces trailing-return-type syntax
auto f(int, int) -> int;
auto g(int a, int b) -> decltype(a + b);

int main()
{
	cout << f(5, 10) << endl;
	cout << g(20, 25) << endl;
	cout << g(35, 40) << endl;
}

auto f(int a, int b) -> int
{
	return a + b;
}

auto g(int a, int b) -> decltype(a + b)
{
	return a + b;
}

// compiler can automatically detect return type
auto h(int a, int b)
{
	return a + b;
}
