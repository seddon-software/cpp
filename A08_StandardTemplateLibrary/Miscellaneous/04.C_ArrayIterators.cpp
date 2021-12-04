#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	const float cost[4] = { 4.78, 6.97, 8.81, 9.02 };
	vector<float> v(4);
	
	copy(cost, cost+4, ostream_iterator<float>(cout, ","));  // "," is delimeter
	cout << endl;

	copy(cost, cost + 4, v.begin());

	for(auto x : v)
	{
		cout << x << " ";
	}
	cout << endl;
}
