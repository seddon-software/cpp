#include <iostream>
#include <functional>
#include <unordered_map>
#include <functional>
using namespace std;

/*
 *  Technically do_operation is not a std algorithm, but nevertheless shows how to use a lambda to 
 *  implement a custom arithmetic operation, namely + - * / with operands a and b.
 *
 *  Inside the do_operation template we create an unordered_map.  The keys are the arithmetic operation
 *  and the values are lambdas.  However you can't easily use a lambda type in template unordered_map,
 *  but you can use std::function instead.
 */

template <typename T>
T do_operation(string op, T a, T b)
{
	// use std::function to define type of lambda
	unordered_map<string, function<T(T,T)>> mymap;
	mymap["+"] = [](T a, T b) { return a + b; };
	mymap["-"] = [](T a, T b) { return a - b; };
	mymap["*"] = [](T a, T b) { return a * b; };
	mymap["/"] = [](T a, T b) { return a / b; };
	return mymap[op](a,b);
}



int main()
{
	cout << do_operation("+", 11, 9) << endl;
	cout << do_operation("-", 23, 3) << endl;
	cout << do_operation("*",  4, 5) << endl;
	cout << do_operation("/", 60, 3) << endl;

	cout << do_operation("+", 10.6, 9.6) << endl;
	cout << do_operation("-", 26.3, 6.1) << endl;
	cout << do_operation("*", 10.1, 2.0) << endl;
	cout << do_operation("/", 50.5, 2.5) << endl;
}

