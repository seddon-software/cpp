#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*  A simple example that calculates the sum of ints from a vector */

int main()
{
	vector<int> mylist = { 2, 3, 5, 7, 11, 13, 17, 19 };
	int total = 0;

	for_each(mylist.begin(),
			 mylist.end(),
			 [&total] (int x) { total += x; });
	cout << total << endl;
}
