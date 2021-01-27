#include <iostream>
using namespace std;

//	A constexpr function has some very rigid rules it must follow:
//
//	It must consist of single return statement (with a few exceptions)
//	It can call only other constexpr functions
//	It can reference only constexpr global variables

// use functions (nested) to define constants
constexpr int secsInHour()
{
	return 60 * 60 * 24;
}

constexpr int secsInDay()
{
	return secsInHour() * 24;
}

constexpr int multiply (int x, int y)
{
    return x * y;
}

int main()
{
	// the compiler may evaluate this at compile time
	__attribute__((unused))
	const int val = multiply( 10, 10 );

	// array size must be a compile time constant
	// so use a function to determine a constant expression
	const int size = secsInDay();
	__attribute__((unused))	int array[size];


	const int minutes = 10000;
	if constexpr(minutes/(24*60) > 1)
		cout << "10000 minutes > 1 day" << endl;

	return 0;
}
