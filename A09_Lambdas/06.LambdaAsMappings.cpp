#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> range(int lower, int upper, int increment = 1) {
	vector<int> values;

	for (int i = lower; i < upper; i += increment) {
		values.push_back(i);
	}
	return values;
}

int main()
{
	vector<int> mylist = range(1, 200);

	for_each(mylist.begin(), mylist.end(),
			 [] (int& x) -> void
			 {
				x = x * x;
			 });

	for_each(mylist.begin(), mylist.end(),
			 [] (int item) -> void
			 {
		         cout << " " << item << ",";
			 });

	cout << " " << endl;

	return 0;
}
