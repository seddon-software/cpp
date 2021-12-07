#include <iostream>
using namespace std;

// Functions using trailing-return-type syntax behave as normal functions
// auto return type; often computed by compiler from decltype
auto f(int, int) -> int;
auto g(auto a, auto b) -> decltype(a + b);

int main()
{
	cout << f(5, 10) << endl;
	cout << g(20, 25) << endl;
	cout << g(35, 40.3) << endl;
}

auto f(int a, int b) -> int
{
	return a + b;
}

// the auto parameters get converted to template args
auto g(auto a, auto b) -> decltype(a + b)
{
	return a + b;
}

// compiler can automatically detect return type
auto h(int a, int b)
{
	return a + b;
}
