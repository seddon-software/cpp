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
	vector<int> mylist = range(14, 200);
	vector<int> primes;
	vector<int>::iterator i = mylist.begin();

	while (true)
	{
		i = find_if(
            i,
			mylist.end(),
			[] (const int& item) -> bool
			{
			    if ((item % 2) == 0) {return false;}
			    if ((item % 3) == 0) {return false;}
			    if ((item % 5) == 0) {return false;}
			    if ((item % 7) == 0) {return false;}
			    if ((item % 11) == 0) {return false;}
			    if ((item % 13) == 0) {return false;}
				return true;
			});
		if(i == mylist.end()) break;
		primes.push_back(*i);
		++i;
	}

	cout << "Primes in range [15, 200)" << endl;
	for_each(primes.begin(), primes.end(),
			 [] (const int& item) -> void
			 {
		         cout << " " << item << ",";
			 });
	cout << " " << endl;

	return 0;
}
