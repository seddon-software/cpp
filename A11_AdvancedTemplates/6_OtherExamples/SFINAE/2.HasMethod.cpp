#include <iostream>

/*
 * SFINAE stands for "substitution failure is not an error"
 *
 * This example shows how to check if a class has a given method
 * see the <type_traits> header file for similar standard definitions
 */

struct MyClassA
{
	int compute() { return 0; }
	void f1() {}
	void f2() {}
};

struct MyClassB
{
	void g1() {}
	void g2() {}
};

// SFINAE template
// called with T=MyClassA and T=MyClassB
template<typename T>
class has_compute
{
	typedef char one;
	typedef struct {char a; char b;} two;

	// this template fails (not an error) if compute is not a method of U
	template<typename U> static one test(decltype(&U::compute));

	// this template is more general, but always available
	template<typename U> static two test(...);

	// if both templates succeed (MyClassA) we end up with
	//		static one test<U>(	int(MyClassA::*)() )   <--- chosen
	//  	static two test<U>(...)
	// otherwise (MyClassB) we just get
	//  	static two test<U>(...)                    <--- chosen

public:
	enum
	{
		// sizeof trick
		// sizeof(...) checks the size of the return type of each expression
		value = sizeof(test<T>(0)) == sizeof(one)
		//          LHS                  RHS

		// in the first case:
		//     T = MyClassA
		//     LHS = sizeof(test<T>(0))
		//         = sizeof(one test<T>(int(MyClassA::*)(0)))
		//         = sizeof(one test<T>(0))
		//         = sizeof(one) = 1
		//     RHS = sizeof(one) = 1
		//     and hence value = true

		// in the second case:
		//     T = MyClassB
		//     LHS = sizeof(two test<T>(...))
		//         = sizeof(two test<T>(0))
		//         = sizeof(two) = 2
		//     RHS = sizeof(one) = 1
		//     and hence value = false
	};
};

int main()
{
	std::cout << has_compute<MyClassA>::value << std::endl;
	std::cout << has_compute<MyClassB>::value << std::endl;
	return 0;
}
