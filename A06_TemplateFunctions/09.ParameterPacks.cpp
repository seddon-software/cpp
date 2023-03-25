#include <tuple>
#include <string>
#include <iostream>
using namespace std;

/*
 *  This example was modified from an example on cppreference.com and shows how to use parameter packs 
 *  to print the values of a tuple.  Note the generic class template "print_tuple" uses the parameter N
 *  to keep track of the size of the parameter pack.  The real work is done by the method 
 *  print_tuple<N,T,...Ts>::print() which is recursive and needs a specialization template method to end
 *  the recursion when N=0.
 *  
 *  The value of N in the generic template is initialized with sizeof...(Ts):
 * 	    print_tuple<sizeof...(Ts), T, Ts...>::print(t);
 *
 *  The different tuples are output with the compile time expression: 
 * 		cout << get<N>(t) << ", ";
 */

// generic class template
template <int N, typename T, typename ...Ts>
struct print_tuple
{
	static void print(tuple<T, Ts...> t)
	{
		print_tuple<N-1, T, Ts...>::print(t);
		cout << endl << N << ": " << get<N>(t) << ", ";
	}
};

// specialization of class template for N = 0
template <typename T, typename ...Ts>
struct print_tuple<0, T, Ts...>
{
	static void print(tuple<T, Ts...> t)
	{
		cout << endl << "0: " << get<0>(t) << ", ";
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
    cout << "Individual tuple values";
	tuple<string, int, double, bool, string> t("first", 5, 6.66666, true, "abc");
	print(t);
    cout << endl;
}
