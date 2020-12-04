#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
using namespace std::placeholders;


bool salary_less_than_25K(const pair<string, int>& p)
{
	string name = p.first;
	int amount = p.second;
 	return amount < 25000;
}

bool salary_less_than(const pair<string, int>& p, int value)
{
	string name = p.first;
	int amount = p.second;
 	return amount < value;
}

class Query
{
public:
	Query(int salary): salary(salary) {}
	bool operator()(const pair<string, int>& p)
	{
		string name = get<0>(p);
		int amount = get<1>(p);
		return amount < 25000;
	}
private:
	__attribute__((unused)) int salary;
};

int main()
{
	map<string, int> salary;
	map<string, int>::iterator i;
	salary["john"] = 78000;
	salary["susan"] = 24000;
	salary["anne"] = 31000;
	salary["peter"] = 32500;
	salary["roger"] = 57000;
	for(i = salary.begin(); i != salary.end(); ++i)
	{
		pair<string, int> entry = *i;
		cout << entry.first << ", " << entry.second << endl;
	}

	i = find_if(salary.begin(), salary.end(), salary_less_than_25K);
	cout << i->first << ", " << i->second << endl;
	Query q(25000);
	i = find_if(salary.begin(), salary.end(), q);
	cout << i->first << ", " << i->second << endl;

	auto l = [](const pair<string, int>& p)
	{
		string name = get<0>(p);
		int amount = get<1>(p);
		return amount < 25000;
	};
	i = find_if(salary.begin(), salary.end(), l);
	cout << i->first << ", " << i->second << endl;

	auto f = bind(&salary_less_than, _1, 25000);
	i = find_if(salary.begin(), salary.end(), f);
	cout << i->first << ", " << i->second << endl;
}
