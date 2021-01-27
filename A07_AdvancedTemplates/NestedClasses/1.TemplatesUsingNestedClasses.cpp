#include <iostream>
#include <vector>
#include <list>

/*
 *  Explore templates using nested types as template parameters.
 *  Note that type deduction is not attempted for templates like:
 *  	template <typename T1, typename T2>
 *  	void f(typename T1::T2 x) {}
 *  because although T1 is a typename and can accept a nested class
 *  we can't use T2 because it is a separate type.  Thus for classes X and Y
 *  if T1=X and T2=Y then X::Y is a totally different type and would need to be
 *  specified as an additional template parameter:
 *  	template <typename T1, typename T2, typename NESTED>
 *  	void f(typename NESTED x) { ... }
 */

using namespace std;

// when you define this nested class:
//    X is a typename
//    X::Y is a typename
//    Y is NOT a typename and cannot be used as a template parameter

struct X
{
	struct Y{};
};

// this template has a nested class as a template parameter
template <template<typename,typename> class V, class T, class A=allocator<T>>
void printOneElement(typename V<T,A>::iterator iter)
{
    cout << *iter << endl;
}

template <typename T>
void printSize(T)
{
	cout << sizeof(T) << endl;
}

template <typename T1, typename T2>
void printSize(T2 t2)
{
	T1 t1;
	cout << sizeof(t1) + sizeof(t2) << endl;
}

template <typename T>
void printSize(typename T::Y ty)  // Y is not a typename, but T::Y is
{
    cout << sizeof(ty) << endl;
}


int main()
{
	// create an object of nested class
	X::Y xy;

	// use several similar templates that use nested classes
	printSize(xy);		     // T=X::Y (recall Y is not a typename)
	printSize<X,X::Y>(xy);   // template requires 2 parameters, T1=X, T2=X::Y
	printSize<X>(xy);        // T=X and the function parameter is T::Y=X::Y

	vector<int> v = {2,4,6};
	printOneElement<vector,int>(v.begin());
	// type deduction not attempted for nested class:  vector<int>::iterator
	//k(v.begin());
}
