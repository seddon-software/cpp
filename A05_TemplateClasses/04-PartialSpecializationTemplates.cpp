////////////////////////////////////////////////////////////
//
//		Partial Specialisation
//
////////////////////////////////////////////////////////////


#include <iostream>
#include <string>
using namespace std;

// some example classes to use ...
class X {};
class Y {};

// the generic template
template <typename T1, typename T2>
class collection
{
public:
	void f1() {}
	void f2() {}
	void f3() {}
};

// partial specialisation for same type (T1==T2)
template <typename T>
class collection<T,T>
{
public:
	void f1() {}
	void f2() {}
	void f3() {}
};


// partial specialisation for pointers of T1
template <typename T1, typename T2>
class collection<T1*,T2>
{
public:
	void f1() {}
	void f2() {}
	void f3() {}
};

// partial specialisation for const pointers of T1
template <typename T1, typename T2>
class collection<const T1*,T2>
{
public:
	void f1() {}
	void f2() {}
	void f3() {}
};

// partial specialisation for T2==Y
template <typename T>
class collection<T,Y>
{
public:
	void f1() {}
	void f2() {}
	void f3() {}
};

/////

int main()
{
	collection<string,X>	   list1;   // uses the generic template
	collection<X, X> 	       list2;   // uses the template with T1==T2
	collection<double*, X>     list3;	// uses the template with T1 as a pointer
	collection<const char*, X> list4;	// uses the template with T1 as a const pointer
	collection<int, Y>         list5;   // uses the template with T2==Y

	list1.f1();		   	// calls the generic template
	list2.f1();   		// calls the template with T1==T2
	list3.f1();			// calls the template with T1 as a pointer
	list4.f1();			// calls the template with T1 as a const pointer
	list5.f1(); 		// calls the template with T2==Y
}

