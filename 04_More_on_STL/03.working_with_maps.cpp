/*
 *
 */

#include <iostream>
#include <string> 
#include <unordered_map>
using namespace std;

void increase_salary(auto& salaries)
{
    for(auto& [name, salary] : salaries)
    {
        salary += 250;          // $250 rise
    }
}

int main()
{
    unordered_map<string, int> salaries;
    salaries["Steven"] = 25000;
    salaries["Mary"]   = 18000;
    salaries["John"]   = 20000;
    salaries["Susan"]  = 36500;
    salaries["Rose"]   = 17500;

    increase_salary(salaries);

    cout << "unordered map: " << endl;
    for(auto [name, salary] : salaries)
    {
        cout << name << ", " << salary << endl;
    }
}
