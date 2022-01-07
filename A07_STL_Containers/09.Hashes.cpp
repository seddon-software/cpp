////////////////////////////////////////////////////////////
//
//      Hashes
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*  
 *  When the container classes were introduced with C++11, the only key-value pair container class
 *  was map.  As stated earlier, this is based around a binary tree and provides ordering of the 
 *  container.  Later, a new hash based container was introduced called unordered_map.  The 
 *  container is slightly more efficient for searches, O(1) compared to the binary tree, O(logN) 
 *  at the expense of not maintaining an order of the constituents.
 */

using PAIR = pair<string, int>;
using HASH = unordered_map<string, int>;


void Print(const PAIR& p)
{
    cout << p.first << ", " << p.second << endl;
}

int main()
{
    HASH salary;
    salary["Steven"] = 25000;
    salary["Mary"]   = 18000;
    salary["John"]   = 20000;
    salary["Susan"]  = 36500;
    salary["Rose"]   = 17500;

    // traditional loop
	for (auto i = salary.begin(); i != salary.end(); ++i)
	{
		Print(*i);
	}
    cout << endl;

    // range based loop with lambda
	for (auto kvPair : salary)
	{
		[](const PAIR& p)
		{
			cout << p.first << ", " << p.second << endl;
		}(kvPair);
	}
    cout << endl;

    // using the find_if algorithm
	int salaryAbove = 30000;                    
	auto query = [salaryAbove](const PAIR& p)   // capture the salaryAbove criteria 
		{
			return p.second > salaryAbove;
		};
	auto i = find_if(salary.begin(), salary.end(), query);
	if(i != salary.end())  // check if found
		cout << i->first << ", " << i->second << endl;
	else
		cout << "not found" << endl;
}
