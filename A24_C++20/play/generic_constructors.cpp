#include <iostream>
using namespace std;

template <typename T>
struct Generic 
{
    T t;
    Generic(T t): t(t) {     // invoke with any type
        cout << t << '\n';
    }
};

int main()
{
    Generic x = 23;
    cout << x.t << endl;
    Generic y{"Hello"};
    cout << y.t << endl;
}
