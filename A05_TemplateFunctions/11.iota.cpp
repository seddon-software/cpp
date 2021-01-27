#include <iostream>
#include <numeric> //std::iota
#include <vector>

using namespace std;

int main()
{
    vector<int> v(10);
    iota(begin(v), end(v), 50); // 50, 51, 52, ...
    for(auto i : v)
    {
        cout << i << ", ";
    }
    cout << endl;
}