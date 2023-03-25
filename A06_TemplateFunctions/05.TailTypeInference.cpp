////////////////////////////////////////////////////////////
//
//		Template Functions
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using namespace std;

/*
 *  Successive versions of the C++ standard have reflected advances in compiler technology.  Over time
 *  compilers have perfected type inference to such an extent that they can now use auto in many cases
 *  instead of requiring the programmer to explicitly declare types.
 * 
 *  In this example we look at 3 versions of a template as used in the C++98, C++11 and C++14 standards.
 */

template<typename RET, typename T1, typename T2>
RET add98(T1 x, T2 y)   // can't deduce return type in C++98, RET must be explicitly declared
{
	return x + y;
}

template<typename T1, typename T2>
auto add11(T1 x, T2 y) -> decltype(x + y)   // in C++11 this is called "tail type inference"
{
	return x + y;
}

template<typename T1, typename T2>
auto add14(T1 x, T2 y)  // C++14 can deduce return type automatically
{
	return x + y;
}

void cpp98()
{
	cout << add98<int>(10, 20) << endl;       // RET = int
	cout << add98<double>(10.7, 20) << endl;  // RET = double
	cout << add98<string>(string("Hello"), string(" World")) << endl; // RET = string
}


void cpp11()
{
	cout << add11(10, 20) << endl;
	cout << add11(10.7, 20) << endl;
	cout << add11(string("Hello"), string(" World")) << endl;
}


void cpp14()
{
	cout << add14(10, 20) << endl;
	cout << add14(10.7, 20) << endl;
	cout << add14(string("Hello"), string(" World")) << endl;
}

/////

int main()
{
	cpp98();
	cpp11();
	cpp14();
}

