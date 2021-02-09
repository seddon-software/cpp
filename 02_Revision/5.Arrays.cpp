////////////////////////////////////////////////////////////
//
//      Using vector instead of C arrays
//
////////////////////////////////////////////////////////////

#include <vector>
#include <iostream>
using namespace std;

void c_version()
{
    // C arrays are fixed size
    const int size = 5;
    int numbers[] = {2, 5, 7, 3, 9};
    for(int i = 0; i < size; i++)
    {
        cout << numbers[i] << ",";
    }
    cout << endl;
}

void cpp_version()
{
    // C++ vectors are variable size
    vector<int> numbers = {2, 5, 7, 3, 9};
    for(unsigned i = 0; i < numbers.size(); i++)
    {
        cout << numbers[i] << ",";
    }
    cout << endl;
}

int main()
{
    c_version();
    cpp_version();
}