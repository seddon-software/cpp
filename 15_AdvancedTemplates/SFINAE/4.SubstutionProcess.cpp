#include <type_traits>
#include <iostream>

/*
 * This SFINAE example uses the traits library to select a particular template
 * dependent on the type of a function arguement
 */


// foo overloads are enabled via the return type
template<class T>
typename std::enable_if<std::is_floating_point<T>::value, T>::type foo(T t)
{
    std::cout << "foo: float" << std::endl;
    T remainder = t;
    while(remainder > 3)
    {
    	remainder -= 3;
    }
    return remainder;
}

template<class T>
typename std::enable_if<std::is_integral<T>::value, T>::type foo(T t)
{
    std::cout << "foo: int" << std::endl;
    return t % 3;
}


int main()
{
	int r1 = foo(10);
    std::cout << r1 << std::endl;
	// T=int
	// template 1 => typename std::enable_if<std::is_floating_point<T>::value, T>::type foo(T t) { ... }
	//               typename std::enable_if<std::is_floating_point<int>::value, int>::type foo(int t) { ... }
	//               typename std::enable_if<false, int>::type foo(int t) { ... }
	//			     substitution failure
	// template 2 => typename std::enable_if<std::is_integral<T>::value, T>::type foo(T t) { ... }
	//               typename std::enable_if<std::is_integral<int>::value, int>::type foo(int t) { ... }
	//               typename std::enable_if<true, int>::type foo(int t) { ... }
	//               int foo1(int t) { ... }
	//			     substitution works

    double r2 = foo(34.56);
    std::cout << r2 << std::endl;
	// T=double
	// template 1 => typename std::enable_if<std::is_floating_point<T>::value, T>::type foo(T t) { ... }
	//               typename std::enable_if<std::is_floating_point<double>::value, double>::type foo(double t) { ... }
	//               typename std::enable_if<true, double>::type foo(double t) { ... }
	//               double foo1(double t) { ... }
	//			     substitution works
	// template 2 => typename std::enable_if<std::is_integral<T>::value, T>::type foo(T t) { ... }
	//               typename std::enable_if<std::is_integral<double>::value, double>::type foo(double t) { ... }
	//               typename std::enable_if<false, double>::type foo(double t) { ... }
	//			     substitution failure
}
