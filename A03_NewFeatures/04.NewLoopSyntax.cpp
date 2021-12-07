#include <iostream>
#include <algorithm>
using namespace std;

void print(int a[], int size)
{
	copy(a, a + size, ostream_iterator<int>(cout, ","));
	cout << endl;
}

int a[6] = { 2, 3, 5, 7, 11, 13 };

int main()
{
	for(auto x: a)		// capture by value so you don't change the underlying array
	{
		x = x * 10;		// changes made to temporaries
	}
	print(a, 6);
	for(auto& x: a)		// capture by reference so you can change the underlying array
	{
		x = x * 10;
	}
	print(a, 6);
}
