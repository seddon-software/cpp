#include <iostream>
#include <type_traits>
using namespace std;

struct A {};

int f()
{
    return 1;
}

int main()
{
    cout << std::boolalpha;		// display bools properly (not as 0/1)
    cout << std::is_function<A>::value << endl;
    cout << std::is_function<int(int)>::value << endl;
    cout << std::is_function<decltype(f)>::value << endl;
    cout << std::is_function<int>::value << endl;
}
