////////////////////////////////////////////////////////////
//
//		Specialisation
//
////////////////////////////////////////////////////////////

/*
 *  When providing specialisations for template classes you must start by
 *  defining a generic template.  Specialisations must have the same name,
 *  but some (partial specialization) or all (full specialization) of the 
 *  template parameters will have constraint applied.
 */

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


// full specialization for T=bool
template <>					// note the <> are required
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
	collection<string> list1;		// calls the generic template
	collection<int>    list2;		// calls the generic template
	collection<bool>   list3;		// calls the specialized template

	list1.f1();
	list2.f1();
	list3.f1();
}

