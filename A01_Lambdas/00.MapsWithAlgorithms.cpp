
/*
 *  Demo to show the equivalence of a functor and lambdas.  A functor is an object that behaves like a 
 *  function (i.e. overloads the operator()), but being an object also has attributes (unlike a function).
 * 
 *  A functor requires defining a specialised class whereas with a lambda the compiler creates this class
 *  implicitly. 
 */

 #include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
using namespace std::placeholders;

bool salary_less_than_25K(const pair<string, int>& p)
{
//	const string& name = p.first;
	const int& amount = p.second;
 	return amount < 25000;
}

int main()
{
	map<string, int> salary;
	map<string, int>::iterator i;
	salary["john"] = 78000;
	salary["susan"] = 24000;
	salary["anne"] = 31000;
	salary["peter"] = 32500;
	salary["roger"] = 57000;

	i = find_if(salary.begin(), salary.end(), salary_less_than_25K);
	cout << i->first << ", " << i->second << endl;
}
