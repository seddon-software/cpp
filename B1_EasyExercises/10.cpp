/*
 * Create a dictionary consisting of people's names and salaries; choose an
 * appropriate container from the STL.
 * Initialise the dictionary with at least 5 pairs of names and salaries.
 * Now print the dictionary sorted by salary.
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

bool compare(const pair<string, int>& a, const pair<string, int>& b)
{
	return get<1>(a) < get<1>(b);
}


int main()
{
	vector<pair<string, int>> salaries =
	{
		{ "John"   , 45000 },
		{ "Sheila" , 48000 },
		{ "Vivien" , 31000 },
		{ "Roy"    , 37000 },
		{ "Ruth"   , 50000 }
    };
	sort(salaries.begin(), salaries.end(), compare);

	for(const auto& pair : salaries)
	{
	    cout << get<0>(pair) << ",";
	    cout << get<1>(pair) << endl;
	}
}
