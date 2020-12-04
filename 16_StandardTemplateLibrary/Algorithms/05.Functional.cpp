#include <iostream>
#include <functional>
#include <unordered_map>
#include <functional>
using namespace std;

template <typename T>
T do_operation(string op, T a, T b)
{
	// can't use a lambda type in template. but can use std::function
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
	cout << do_operation("-", 22, 3) << endl;
	cout << do_operation("*", 2, 9) << endl;
	cout << do_operation("/", 51, 3) << endl;

	cout << do_operation("+", 14.5, 1.9) << endl;
	cout << do_operation("-", 18.5, 2.2) << endl;
	cout << do_operation("*", 2.5, 6.5) << endl;
	cout << do_operation("/", 40.5, 2.5) << endl;
}

