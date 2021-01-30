#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;


unordered_map<string, int> get_key_value_pairs()
{
    return {
        { "Monday",    1 },
        { "Tuesday",   2 },
        { "Wednesday", 3 },
        { "Thursday",  4 },
        { "Friday",    5 },
    };
}

int main()
{
    // auto&& will resolve to auto& for l-value references
    //             resolve to auto&& for r-value references.
    for (auto&& [ key, value ] : get_key_value_pairs())
        std::cout << "key=" << key << " value=" << value << endl;
}
