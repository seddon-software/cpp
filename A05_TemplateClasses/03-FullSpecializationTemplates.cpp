////////////////////////////////////////////////////////////
//
//		Specialisation
//
////////////////////////////////////////////////////////////


#include <iostream>
#include <string>
using namespace std;

// the generic template
template <typename T>
class collection
{
public:
	void f1() {}
	void f2() {}
	void f3() {}
};


// specialisation for bool
template <>
class collection<bool>
{
public:
	void f1() {}
	void f2() {}
	void f3() {}
};

/////

int main()
{
	collection<string> list1;
	collection<int>    list2;
	collection<bool>   list3;

	list1.f1();
	list2.f1();
	list3.f1();

	return 0;
}

