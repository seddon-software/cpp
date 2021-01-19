#include <iostream>
#include <functional>
#include <unordered_map>
using namespace std;


int do_operation1(string op, double a, double b)
{
	unordered_map<string, double(*)(double, double)> mymap;
	mymap["+"] = [](double a, double b) { return a + b; };
	mymap["-"] = [](double a, double b) { return a - b; };
	mymap["*"] = [](double a, double b) { return a * b; };
	mymap["/"] = [](double a, double b) { return a / b; };

	return mymap[op](a,b);
}

int do_operation2(string op, double a, double b)
{
	unordered_map<string, std::function<double()>> mymap;
	mymap["+"] = [&a, &b]() { return a + b; };
	mymap["-"] = [&a, &b]() { return a - b; };
	mymap["*"] = [&a, &b]() { return a * b; };
	mymap["/"] = [&a, &b]() { return a / b; };

	return mymap[op]();
}


int main()
{
	cout << do_operation1("+", 5, 7) << endl;
	cout << do_operation1("-", 15, 3) << endl;
	cout << do_operation1("*", 2, 6) << endl;
	cout << do_operation1("/", 24, 2) << endl;

	cout << do_operation2("+", 5, 7) << endl;
	cout << do_operation2("-", 15, 3) << endl;
	cout << do_operation2("*", 2, 6) << endl;
	cout << do_operation2("/", 24, 2) << endl;
}

