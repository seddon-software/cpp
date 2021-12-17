#include <iostream>
using namespace std;

auto Sum(){
    return 0;
}

template<typename T1, typename... T>
auto Sum(T1 s, T... ts)
{
    return s + Sum(ts...);
}

int main()
{
    cout << Sum(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << endl;

}