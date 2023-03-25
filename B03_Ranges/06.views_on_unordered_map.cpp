#include <iostream>
#include <ranges>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
 *  A key feature of views is that whatever transformation they apply, they do so at the moment you request an 
 *  element, and not when the view is created.
 * 
 *  Here we create a hash of key value pairs.  Next, we create separate views on the keys and the values.  We 
 *  print the views and then use the values view to calculate the average salary.
 */
int main() 
{
    std::unordered_map<std::string, int> salary
    {
        {"tom", 25000}, {"zoe", 33000}, {"peter", 37000}, {"sandra", 28000}, {"vicky", 43000}
    };
    // create views
    auto keys = std::views::keys(salary);
    auto values = std::views::values(salary);

    // print their contents
    for(auto k : keys) cout << k << endl;
    for(auto v : values) cout << v << endl;

    // use the values view to calculate average salary
    auto sum = 0.0;
    for(auto v : values) 
    {
        sum += v;
    }
    cout << "Average salary is: " << sum/values.size() << endl;
}