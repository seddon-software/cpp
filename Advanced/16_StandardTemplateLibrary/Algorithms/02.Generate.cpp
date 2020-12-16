#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;


int main()
{
	// generate a vector of integers in range 1..50
	vector<int> v(50);
	int n = 22;
	generate(v.begin(), v.end(), [&]() { return n++; });

	copy(v.begin(), v.end(), ostream_iterator<int>(cout, ","));
	cout << endl;
}

