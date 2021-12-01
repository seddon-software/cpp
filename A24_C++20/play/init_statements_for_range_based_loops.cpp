#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() 
{
    for (auto vec = std::vector{1, 2, 3, 4, 5, 6}; auto v : vec) 
    {
        std::cout << v << " ";
    }

    cout << endl;

    for (auto initList = {1, 2, 3, 4, 5, 6}; auto n : initList) 
    {
        cout << n * n << " ";
    }

    cout << endl;

    using namespace std::string_literals;
    for (auto str = "Hello World"s; auto c: str)  // string literal type is string not char* 
    {
        cout << c << ".";
    }
    cout << endl;
}