#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

/*  Here we use a lambda with the for_each algorithm to compute the squares of a range of ints */

int main()
{
	vector<int> mylist(20);
	std::iota(mylist.begin(), mylist.end(), 1); // fill vector with succesive ints starting at 1

	for_each(mylist.begin(), mylist.end(),
			 [] (int& x) { x = x * x; });

	for(auto i : mylist) { cout << " " << i << ","; };
	cout << " " << endl;
}
