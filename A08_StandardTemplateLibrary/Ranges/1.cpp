#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <ranges>
using namespace std;


int main()
{
	vector<int> v(30);
	int start = 22;
	generate(v.begin(), v.end(), [&]() { return start++; });
    cout << "original range" << endl;
    for (auto i: v) std::cout << i << " ";
    cout << endl;

    {
        cout << "create a view of items in range divisible by 5" << endl;
        auto range = v | views::filter([](int x){return x % 5 == 0;});
        for (auto v: range) std::cout << v << " ";
        cout << endl;
    }
    {
        cout << "create a view of 5 * range" << endl;
        auto range = v | views::transform([](int x){return x * 5;});
        for (auto v: range) std::cout << v << " ";
        cout << endl;
    }
}

