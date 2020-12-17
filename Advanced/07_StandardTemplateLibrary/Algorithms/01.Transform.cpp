#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

int main()
{
	{
		// like a Python comprehension
		vector<int> v = { 2, 4, 6, 8, 10, 12 };
		vector<int> v2(v.size());
		transform(v.begin(), v.end(),
				  v2.begin(),
				  [](int x){ return x * x * x; });
		copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
	{
		vector<double> v = { 2.5, 3.5, 4.5, 5.5, 6.5 };
		vector<double> v2(v.size());

		transform(v.begin(), v.end(),
				  v2.begin(),
				  [](int x){ return x * x;});
		copy(v2.begin(), v2.end(), ostream_iterator<double>(cout, " "));
		cout << endl;
	}
}

