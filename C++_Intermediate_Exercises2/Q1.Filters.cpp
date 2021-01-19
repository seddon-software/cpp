#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;


bool not_even(int n)
{
    return n % 2 != 0;
}

int Next()
{
	static int n = 1;
	return n++;
}
int main()
{
	// generate a vector of integers in range 1..50
	// filter out the odd numbers
	vector<int> v(50);
	generate(v.begin(), v.end(), Next);
	auto end = remove_if(v.begin(), v.end(), not_even);   // return iterator to end of useable data
	copy(v.begin(), end, ostream_iterator<int>(cout, ","));
	cout << endl;
}

