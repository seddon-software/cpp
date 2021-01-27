#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
using namespace std;

void print(vector<int> v)
{
	for(auto n:v) cout << n << " ";
	cout << endl;
}

/*
 * std::begin		returns an iterator to the beginning of container
 * std::end			returns an iterator to the end of container
 */

int main()
{
	vector<int> source{2, 4, 6, 8, 10};

	// copy using CTOR
	vector<int> target1{begin(source), end(source)};
	print(target1);

	// use copy algorithm
	vector<int> target2(size(source));		// must pre-allocate space
	copy(begin(source), end(source), begin(target2));
	print(target2);

	// use copy algorithm with back_inserter
	vector<int> target3;		// no need to pre-allocate space
	copy(begin(source), end(source), back_inserter(target3));
	print(target3);
}
