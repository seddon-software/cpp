#include <iostream>
#include <limits>
using namespace std;


// long long introduced in 2011 when many implementations were 32 bit (long was only 4 bytes)

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
