#include <iostream>
#include <string>
using namespace std;

/*
 *  C++11 introduced a second way to create a alias for a type: "using".  A typedef declaration and a 
 *  using declaration have different syntax, but are entirely equivalent.  However the using declaration
 *  is usually easier to understand and is my personal preference.
 */

// typedef string S;
using S = string;   
// typedef int (*FP)(int x, int y) 
using FP = int (*)(int, int);  



int f(int x, int y) 
{
    cout << "calling f(x, y) with x = " << x << " and y = " << y << endl;
    return x + y;
}

int main()
{
	string a("aaa");
    S b("bbb");
    S c("ccc");
    cout << a << b << c << endl;

    FP fp = f;
    fp(6, 9); 
}
