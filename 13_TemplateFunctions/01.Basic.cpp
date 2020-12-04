////////////////////////////////////////////////////////////
//
//		Template Functions
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using namespace std;


int Max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

double Max(double a, double b)
{
	if (a > b)
		return a;
	else
		return b;
}

string Max(string a, string b)
{
	if (a > b)
		return a;
	else
		return b;
}


/////

int main()
{
	cout << Max(5, 8) << endl;
	cout << Max(5.1, 8.3) << endl;
	cout << Max("Red", "Blue") << endl;
	 
	return 0;
}

