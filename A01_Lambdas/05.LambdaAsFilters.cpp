#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

/*
 *  In this example we compute primes in the range [14, 200).  Note the use of std::iota to fill
 *  mylist with the ints 14 .. 199. 
 */


int main()
{
	vector<int> mylist(200-14);
	std::iota(mylist.begin(), mylist.end(), 14); // fill vector with succesive ints starting at 14
	vector<int> primes;

	auto isPrime = [] (const int& item) -> bool
	{
		if ((item % 2) == 0) {return false;}
		if ((item % 3) == 0) {return false;}
		if ((item % 5) == 0) {return false;}
		if ((item % 7) == 0) {return false;}
		if ((item % 11) == 0) {return false;}
		if ((item % 13) == 0) {return false;}
		return true;
	};

	auto i = mylist.begin();
	while (true)
	{
		i = find_if(
            i,					// start
			mylist.end(),       // end
			isPrime);

		if(i == mylist.end()) break;
		primes.push_back(*i);
		++i;
	}

	cout << "Primes in range [15, 200)" << endl;
	for(auto p : primes)
	{
		cout << " " << p << ",";
	};
	cout << " " << endl;
}
