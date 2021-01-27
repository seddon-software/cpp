#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

/*
 *  By unpacking a variadic list into a tuple we can get access to each individual argument.
 */

template <class... Args>
void f(int i, Args... args) {  // parameter pack is usually at end of parameter list
	tuple<Args...> t{args...};

	cout << i << endl;
	cout << get<0>(t) << endl;
	cout << get<1>(t) << endl;
	cout << get<2>(t) << endl;
}


int main()
{
	string cyan("Cyan");
	f(100, 3.14159, "Red", cyan);
}
