#include <iostream>
using namespace std;



int main()
{
	int x = 10;
	int y = 5;

	// capture everything by reference
	auto add = [&](){ return x++ + y++; };

	// capture x and y by reference
	auto subtract = [&x, &y](){ return x-- - y--; };

	auto print = [&](){ cout << "x=" << x << " y=" << y << endl;};

	cout << add() << endl;
	print();
	cout << subtract() << endl;
	print();
}
