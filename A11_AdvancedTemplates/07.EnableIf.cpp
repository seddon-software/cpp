#include <iostream>
#include <type_traits>
using namespace std;

/*  Now we turn our attention to traits from the standard library.  enable_if is a good example.
 *  We are defining several templates for the function f, where the template parameter T decides
 *  which version to choose.  As you can see, we use a second trait to distinguish between floating
 *  types and integral types.  Note that floating types include float and double.  bool is an 
 *  integral type.
 */

template<class T>
std::enable_if<std::is_floating_point<T>::value, T>::type
    f(T t)
{
    cout << "f(floating) called" << endl;
    return t;
}

template<class T>
std::enable_if<std::is_integral<T>::value, T>::type
    f(T t)
{
    cout << "f(int) called" << endl;
    return t;
}


int main()
{
	cout << f(4.4) << endl;
	cout << f(4.4F) << endl;
	cout << f(66) << endl;
	cout << f(true) << endl;
}
