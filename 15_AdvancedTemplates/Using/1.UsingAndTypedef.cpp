#include <iostream>
#include <string>
using namespace std;

/*
 *  C++11 introduce a second way to create a alias for a type: "using"
 *  typedef and using have different syntax, but are entirely equivalent
 */

typedef string S1;
using S2 = string;

int main()
{
	string a("aaa");
    S1 b("bbb");
    S2 c("ccc");

    cout << a << b << c << endl;
}
