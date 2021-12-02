#include <map>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <string>
using namespace std;


pair<string,int> addTenPercent(pair<string,int> item) // pass by copy so original unchanged
{ 
    item.second *= 1.1;  // add 10% to salary
    return item;
}

int main()
{
    unordered_map<string, int> salary;
    salary["John"] = 20000;
    salary["Susan"] = 36500;
    salary["Steven"] = 19000;
    salary["Mary"] = 28000;
    salary["Rose"] = 17500;

    // create inserter that specifies output object and its start
    unordered_map<string, int> newSalary;
    auto i = inserter(newSalary,newSalary.begin());

    // create a new unordered map with all salaries increased by 10%
    transform(salary.begin(),       // start of input range 
              salary.end(),         // end of input range  
              i,                    // inserter 
              addTenPercent);

    // print out new unordered map
    for(auto item : newSalary)
    {
        auto& key = item.first;
        auto& value = item.second;
        cout << key << "," << value << endl;
    }
}

