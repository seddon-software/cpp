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

using PAIR = pair<string, int>;
using HASH = unordered_map<string, int>;


void Print(const PAIR& p)
{
    cout << p.first << ", " << p.second << endl;
}

void traditionalForLoop(HASH& salary)
{
	cout << endl;
	cout << "traditional for loop" << endl;
	cout << "====================" << endl;
	for (HASH::iterator i = salary.begin(); i != salary.end(); ++i)
	{
		Print(*i);
	}
}

void newLoopSyntaxWithLambdas(HASH& salary)
{
	cout << endl;
	cout << "new syntax with lambdas" << endl;
	cout << "=======================" << endl;
	for (auto x : salary)
	{
		[](const PAIR& p)
		{
			cout << p.first << ", " << p.second << endl;
		}(x);
	}
}

void using_the_find_if_algorithm(HASH& salary)
{
	cout << endl;
	cout << "using the find_if algorithm" << endl;
	cout << "===========================" << endl;
	int top = 30000;
	auto q = [top](const PAIR& p)
		{
			return p.second > top;
		};
	auto i = find_if(salary.begin(), salary.end(), q);
	if(i != salary.end())
		cout << i->first << ", " << i->second << endl;
	else
		cout << "not found" << endl;
}
/////


int main()
{
    HASH salary;
    salary["Steven"] = 25000;
    salary["Mary"]   = 18000;
    salary["John"]   = 20000;
    salary["Susan"]  = 36500;
    salary["Rose"]   = 17500;

	traditionalForLoop(salary);
	newLoopSyntaxWithLambdas(salary);
	using_the_find_if_algorithm(salary);
}
