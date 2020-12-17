////////////////////////////////////////////////////////////
//
//      Non Templated Functions
//
////////////////////////////////////////////////////////////


#include <iostream>
#include <string>

using namespace std;

template <typename RET, typename T1, typename T2>
RET Max(T1 a, T2 b)
{
    if (a > b)
        return a;
    else
        return b;
}


int main()
{
	Max<double>(5, 8.3);
    cout << Max<double>(5, 8.3)      << endl;

    return 0;
}

