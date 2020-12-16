////////////////////////////////////////////////////////////
//
//		Partial Specialisation
//
////////////////////////////////////////////////////////////


#include <iostream>
#include <string>
using namespace std;

// some classes to use ...
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

// partial specialisation for same type
template <typename T>
class collection<T,T>
{
public:
	void f1() {}
	void f2() {}
	void f3() {}
};


// partial specialisation for pointers
template <typename T1, typename T2>
class collection<T1*,T2>
{
public:
	void f1() {}
	void f2() {}
	void f3() {}
};

// partial specialisation for const pointers
template <typename T1, typename T2>
class collection<const T1*,T2>
{
public:
	void f1() {}
	void f2() {}
	void f3() {}
};

// partial specialisation for Y
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
	collection<string,X>	   list1;
	collection<X, X> 	       list2;
	collection<double*, X>     list3;
	collection<const char*, X> list4;
	collection<int, Y>         list5;

	list1.f1();
	list2.f1();
	list3.f1();
	list4.f1();
	list5.f1();

	return 0;
}

