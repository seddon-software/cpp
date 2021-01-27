#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;


int main()
{
	// generate a vector of integers in range 1..50
	vector<int> v(50);
	int start = 22;
	generate(v.begin(), v.end(), [&]() { return start++; });
	// use a for loop to print the vector
	for(auto i:v) cout << i << ", "; 
	    cout << endl;
	// use copy to print the vector
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", "));
	cout << endl;
}

