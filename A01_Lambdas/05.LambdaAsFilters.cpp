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
	vector<int> mylist = range(14, 200);
	vector<int> primes;
	vector<int>::iterator i = mylist.begin();

	while (true)
	{
		i = find_if(
            i,					// start
			mylist.end(),       // end
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
			 [] (const int& item)
			 {
		         cout << " " << item << ",";
			 });
	cout << " " << endl;

	return 0;
}
