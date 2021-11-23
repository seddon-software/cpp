#include <iostream>
#include <ranges>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() 
{
    std::unordered_map<std::string, int> salary
    {
        {"tom", 25000}, {"zoe", 33000}, {"peter", 37000}, {"sandra", 28000}, {"vicky", 43000}
    };
    auto keys = std::views::keys(salary);
    auto values = std::views::values(salary);
    for(auto k : keys) cout << k << endl;
    for(auto v : values) cout << v << endl;
    auto sum = 0.0;
    for(auto v : values) 
    {
        sum += v;
    }
    cout << "Average salary is: " << sum/values.size() << endl;
}