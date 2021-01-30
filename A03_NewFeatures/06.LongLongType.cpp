#include <iostream>
#include <limits>
using namespace std;


int main()
{
	unsigned long long very_big = numeric_limits<int>::max();
	cout << very_big << endl;

	cout << "largest int       = " << numeric_limits<int>::max() << endl;
	cout << "largest long      = " << numeric_limits<long>::max() << endl;
	cout << "largest long long = " << numeric_limits<long long>::max() << endl;
	cout << "Size of int       = " << sizeof(int) <<" bytes \n";
	cout << "Size of long      = " << sizeof(long) <<" bytes\n";
	cout << "Size of long long = " << sizeof(long long) <<" bytes\n";
}
