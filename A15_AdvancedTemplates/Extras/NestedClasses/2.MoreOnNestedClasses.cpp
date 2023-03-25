#include <iostream>
#include <string>
using namespace std;

template <class T>
struct Outer {
  template <class N> struct Nested {};
};
// typenames are: Outer<T> and Outer<T>::Nested<N>

template <class T1, class T2>
void f1( typename Outer<T1>::template Nested<T2>) {}

template <class T1, class T2>
void f2(typename T1::template Nested<T2>) {}

template < template <class> class T1, class T2 >
void f3(T1<T2>) {}

// The following causes the compiler error: No type named T in Outer
// This is because Outer<void> is already a typename and you can't add anything to it
// If Outer<void>::T was a typename that would imply T was a nested type of Outer and not a template parameter
/*
template <class T>
void f4(typename Outer<void>::T) {}
*/

int main()
{
	Outer<int>::Nested<string> x;
	f1<int,string>(x);
	f1<int>(x);
	// f1(x);				// Error: couldn't infer template argument 'T1'

	f2<Outer<int>,string>(x);
	f2<Outer<int>>(x);
	// f2(x);				// Error: couldn't infer template argument 'T1'


	f3<Outer<int>::Nested,string>(x);
	f3<Outer<int>::Nested>(x);
	f3(x);


}
