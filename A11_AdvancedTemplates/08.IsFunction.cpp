#include <iostream>
#include <type_traits>
using namespace std;

/*  Here is a further example, where we use a trait to check if something is a function.
 *  std::is_function<T>::value 
 *      will return true or false depending on whether or not the type T represents a function.
 */

struct A {}; // for testing

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
