#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

class Query
{
public:
    bool operator()(const pair<string, int>& item)
    {
        auto& key = item.first;
        auto& value = item.second;
        if(value > salary)
            return true;
        else
            return false;
    }
    Query(int s): salary(s) {}
private:
    int salary;
};

bool moreThanK(const pair<string, int>& item)
{
    auto& key = item.first;
    auto& value = item.second;
    if(value > 31000)
        return true;
    else
        return false;
}

int main()
{
    map<string, int> salary;
    
    salary["Steven"] = 25000;
    salary["Mary"] = 18000;
    salary["John"] = 20000;
    salary["Susan"] = 36500;
    salary["Rose"] = 17500;
    //Query q(31000);
    // auto i = find_if(salary.begin(), salary.end(), q);
    // if(i != salary.end())
    //     cout << i->first << ", " << i->second << endl;
    // lambda:    [](){}
    int s = 31000;
    auto lambda = [s](const pair<string, int>& item)
        {        
            auto& key = item.first;
            auto& value = item.second;
            if(value > s)
                return true;
            else
                return false;
        };
    auto i = find_if(salary.begin(), salary.end(), lambda);
    if(i != salary.end())
        cout << i->first << ", " << i->second << endl;
}
