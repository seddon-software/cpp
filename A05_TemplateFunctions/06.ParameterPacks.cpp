#include <tuple>
#include <string>
#include <iostream>
using namespace std;

// generic template
template <int N, typename T, typename ...Ts>
struct print_tuple
{
	static void print(tuple<T, Ts...> t)
	{
		print_tuple<N-1, T, Ts...>::print(t);
		cout << get<N>(t) << ", ";
	}
};

// specialization for N = 0
template <typename T, typename ...Ts>
struct print_tuple<0, T, Ts...>
{
	static void print(tuple<T, Ts...> t)
	{
		cout << get<0>(t) << ", ";
	}
};

// template to print tuple (calls print_tuple)
template <typename T, typename ...Ts>
void print(tuple<T, Ts...> t)
{
	print_tuple<sizeof...(Ts), T, Ts...>::print(t);
}

//////////

int main()
{
	tuple<int, double, int, string> t(5, 6.6, true, "abc");
	print(t);
}
