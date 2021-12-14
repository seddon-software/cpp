#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

class Query
{
public:
    bool operator()(const pair<string, int>& item)
    {
        return item.second > salary;
    }
    Query(int s): salary(s) {}
private:
    int salary;
};

bool moreThan31K(const pair<string, int>& item)
{
    return item.second > 31000;
}

int main()
{
    map<string, int> salary;
    
    salary["Steven"] = 25000;
    salary["Mary"] = 18000;
    salary["John"] = 20000;
    salary["Susan"] = 36500;
    salary["Rose"] = 17500;
    {   // use a function pointer
        auto i = find_if(salary.begin(), salary.end(), moreThan31K);
        if(i != salary.end())
            cout << i->first << ", " << i->second << endl;
    }
    {
        // use a functor
        Query q(31000);
        auto i = find_if(salary.begin(), salary.end(), q);
        if(i != salary.end())
            cout << i->first << ", " << i->second << endl;
    }
    {
        // use a lambda
        // C++11 introduced lambdas of the form: [captures](parameters){function body}
        // lambdas are equivalent to functors    
        int s = 31000;
        auto mylambda = [s](const pair<string, int>& item) { return item.second > s; };
        auto i = find_if(salary.begin(), salary.end(), mylambda);
        if(i != salary.end())
            cout << i->first << ", " << i->second << endl;
    }
}
