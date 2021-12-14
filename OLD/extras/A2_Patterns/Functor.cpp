///////////////////////////////////////////////////////////////
//
//		Functors
//
///////////////////////////////////////////////////////////////


#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<string, int> PAIR;
typedef map<string, int, less<string> > MAP;


////////////////////////////////////////////////////////////

void Print(const PAIR& p)
{
    cout << p.first << ", " << p.second << endl;
}

class Query
{
private:
	int salary;
public:
	Query(int s) : salary(s) {}

	bool operator()(const PAIR& p)
	{
		int salary = p.second;

	    if (salary < this->salary)
	        return true;
	    else
	        return false;
	}
};

////////////////////////////////////////////////////////////

int main()
{
    MAP theList;
    MAP::iterator i;

    theList["Steven"] = 25000;
    theList["Mary"]   = 18000;
    theList["Rose"]   = 17500;
    theList["John"]   = 20000;
    theList["Susan"]  = 36500;

    // search for people who earn less than £18,000
    Query q(19000);

	i = theList.begin();

	while(true)
	{
		i = find_if(i, theList.end(), q);
		if(i == theList.end()) break;
		Print(*i);
		++i;
	}

    return 0;
}
