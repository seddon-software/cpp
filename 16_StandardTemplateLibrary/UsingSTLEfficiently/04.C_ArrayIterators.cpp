#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	const float cost[4] = { 4.78, 6.97, 8.81, 9.02 };
	vector<float> v(4);
	copy(cost, cost+4, ostream_iterator<float>(cout, ","));
	cout << endl;

	copy(cost, cost + 4, v.begin());

	for(unsigned i = 0; i < v.size(); ++i)
	{
		cout << v[i] << endl;
	}
}
