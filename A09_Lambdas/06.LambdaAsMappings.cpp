#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

auto range(int lower, int upper) {
	vector<int> v(upper - lower);
	generate(v.begin(), v.end(), [=]() mutable { return lower++; });
	return v;
}

int main()
{
	vector<int> mylist = range(1, 20);

	for_each(mylist.begin(), mylist.end(),
			 [] (int& x) { x = x * x; });

	for_each(mylist.begin(), mylist.end(),
			 [] (int item) { cout << " " << item << ","; });
	cout << " " << endl;
}
