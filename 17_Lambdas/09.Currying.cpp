#include <iostream>
#include <tuple>
using namespace std;

using TUPLE = std::tuple<int, int, int, int, int>;

auto f(int a)
{
	auto g = [=](int b)
	{
		auto h = [=](int c)
		{
			auto i = [=](int d)
			{
				auto j = [=](int e)
				{
					return std::make_tuple(a, b, c, d, e);
				};
				return j;
			};
			return i;
		};
		return h;
	};
	return g;
}

auto func(int a, int b, int c, int d, int e)
{
	return std::make_tuple(a, b, c, d, e);
}

void print(TUPLE t)
{
	cout << std::get<0>(t) << ", " <<
	    	std::get<1>(t) << ", " <<
			std::get<2>(t) << ", " <<
			std::get<3>(t) << ", " <<
			std::get<4>(t) << endl;
}
int main()
{
	// conventional function that takes 5 args
	print(func(1, 2, 3, 4, 5));

	// curried version that splits args
	auto a = f(1);
	auto b = f(1)(2);
	auto c = f(1)(2)(3);
	auto d = f(1)(2)(3)(4);
	auto e = f(1)(2)(3)(4)(5);

	print( a(2)(3)(4)(5) );
	print( b(3)(4)(5) );
	print( c(4)(5) );
	print( d(5) );
	print( e );
}

