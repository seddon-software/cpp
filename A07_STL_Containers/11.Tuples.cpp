#include <tuple>
#include <string>
#include <iostream>
using namespace std;

/*  
 *  The tuple template was introduce in C++11 and is a fixed-size collection of heterogeneous values,
 *  with the tpes thereof specified as template parameters.
 * 
 *  This example focusses on some of the common methods of tuple template.
 */

int main()
{
    tuple<string, int, string> t1{"abc"s, 99, "xyz"s};
    // extract components (note: get<> must be compile time evaluation)
    cout << get<0>(t1) << endl;
    cout << get<1>(t1) << endl;
    cout << get<2>(t1) << endl;

    tuple<string, string, double, double> t2{"hello"s, "world"s, 3.14159, 2.71828};

    // concatenate two tuples
	auto t = tuple_cat(t1, t2);
    {
        auto [a, b, c, d, e, f, g] = t;
        cout << a << ", " << b << ", " << c << ", " << d << ", " << e << ", " << f << ", " << g <<  endl;
    }

    // swap tuples (must be of same size and types)
    tuple a{1, 2.22, 3};
    tuple b{9, 8.88, 7};
    a.swap(b);
    cout << get<0>(a) << ", " << get<1>(a) << ", " << get<2>(a) <<  endl;
    cout << get<0>(b) << ", " << get<1>(b) << ", " << get<2>(b) <<  endl;

    // assign tuples
    auto c = a;
    cout << get<0>(c) << ", " << get<1>(c) << ", " << get<2>(c) <<  endl;
}
