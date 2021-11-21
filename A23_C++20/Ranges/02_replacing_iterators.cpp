#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    { // sort using iterators
        vector<int> vect{-3, 5, 0, 7, -4};
        sort(vect.begin(), vect.end());
        for (auto v: vect) cout << v << ",";
        cout << endl;
    }
    { // sort using ranges
        vector<int> vect{-3, 5, 0, 7, -4};
        std::ranges::sort(vect);
        for (auto v: vect) cout << v << ",";
        cout << endl;
    }
}