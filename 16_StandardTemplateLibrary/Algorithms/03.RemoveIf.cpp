#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

int main()
{
	vector<int> v{10,11,12,13,14,15,16,17,18,19,20};
	// filter out the odd numbers
	auto end = remove_if(v.begin(), v.end(), [](int n){ return n % 2 != 0; });
	copy(v.begin(), end, ostream_iterator<int>(cout, ","));
	cout << endl;
}

