#include <iostream>
using namespace std;



int main()
{
	int x = 10;
	int y = 5;

	// capture everything by value
	auto add = [=](){ return x + y; };

	// capture x and y by value
	auto subtract = [x, y](){ return x - y; };

	cout << add() << endl;
	cout << subtract() << endl;
}
