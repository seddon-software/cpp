#include <iostream>

/*
constexpr: largely advisory; evaluate this function call at compile time 
           if possible

consteval: generate an error if you cannot evaluate this function call 
           at compile time
*/

// run-time function
int square1(int n) 
{
    return n * n;
}

// compile-time function
consteval int square2(int n) 
{
    return n * n;
}

// compile-time or run-time function
constexpr int square3(int n) 
{
    return n * n;
}

// constexpr functions can call other constexpr functions
constexpr int secsInHour()
{
	return 60 * 60 * 24;
}

constexpr int secsInDay()
{
	return secsInHour() * 24;
}

int main() 
{
    // this fails to compile
    // constexpr int x1 = square1(10);    // RHS can't be evaluated at compile-time
    [[ maybe_unused ]] constexpr int x2 = square2(10);
    [[ maybe_unused ]] constexpr int x3 = square3(10);

    // x is evaluated at run-time
    int x = 100;

    [[ maybe_unused ]] int x4 = square1(x); // RHS evaluated at compile-time
    // this fails to compile
    // int x5 = square2(x); // x can't be evaluated at compile-time
    [[ maybe_unused ]] int x6 = square3(x); // OK, will be evaluated at run-time

    // array size must be a compile time constant
	// so use a function to determine a constant expression
	[[ maybe_unused ]] int array[secsInDay()];
}
