/*
 *
 */

#include <iostream>
#include <string> 
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int> salaries = 
    {
        {"Steven", 25000},
        {"Mary",   18000}
    };
    salaries["John"]   = 20000;
    salaries["Susan"]  = 36500;
    salaries["Rose"]   = 17500;

    cout << "unordered map: " << endl;
    for(auto [name, salary] : salaries)
    {
        cout << name << ", " << salary << endl;
    }
}
