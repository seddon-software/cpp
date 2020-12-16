#include <iostream>
#include <string>
using namespace std;

double operator "" _deg(long double d)
{
	// returns radians
	return d * 3.14159 / 180.0;
}

int main()
{
	double right_angle = 90.0_deg;
	cout << right_angle << endl;
}
