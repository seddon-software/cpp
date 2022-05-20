/*
 *
 */

#include <iostream>
#include <string> 
#include <map>
using namespace std;

int main()
{
    map<string, int> salaries =
    {
        {"Steven", 25000},
        {"Mary",   18000}
    };
    salaries["John"]   = 20000;
    salaries["Susan"]  = 36500;
    salaries["Rose"]   = 17500;

    cout << "ordered map: " << endl;
    for(auto [name, salary] : salaries)
    {
        cout << name << ", " << salary << endl;
    }
}
