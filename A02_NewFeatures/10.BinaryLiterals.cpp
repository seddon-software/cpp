#include <iostream>
using namespace std;

/*  You can now use ' in numbers and define binary literals */

int main()
{
	auto integer_literal = 1'000'000;
	cout << integer_literal << endl;

	auto floating_point_literal = 0.000'015'3;
	cout << floating_point_literal << endl;

	auto binary_literal = 0b0100'1100'0110;
	cout << hex << binary_literal << endl;
}
