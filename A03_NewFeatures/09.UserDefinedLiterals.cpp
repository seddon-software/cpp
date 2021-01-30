#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// double is not allowed as input parameter here (banned bt C++ standard)
double operator "" _deg(long double d)
{
	// returns radians
	return d * 3.14159 / 180.0;
}
const string operator "" _degrees(long double d)
{
	stringstream ss;
	ss << d * 3.14159 / 180.0 << " radians";
	return ss.str();
}

int main()
{
	double right_angle = 90.0_deg;
	string full_circle = 360.0_degrees;
	cout << right_angle << endl;
	cout << full_circle << endl;
}
