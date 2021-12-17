#include <iostream>
#include <vector>

struct Integer  // converter
{
	Integer(int i) : i(i) {}
	int i;
};

template<typename T>
struct X
{
	void f(T t)
	{
		std::cout << "f(T)" << std::endl;
	}
};

template<>
struct X<int> : public X<Integer>
{
	void f(int t)
	{
		std::cout << "f(int)" << std::endl;
		// specialization calling generic version
		X<Integer>::f(t);		// uses conversion of int to Integer
	}
};

int main()
{
	X<int> x;
	x.f(20);
}

