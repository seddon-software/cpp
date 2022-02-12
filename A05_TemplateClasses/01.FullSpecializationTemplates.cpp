////////////////////////////////////////////////////////////
//
//		Specialisation
//
////////////////////////////////////////////////////////////

/*
 *  As shown previously, we often need to cater for special cases with templates.  The
 *  template is a generic formulation of a class, but sometimes the template is not appropriate
 *  for some types.  Because of this fact, templates are aloud to provide special cases called
 *  specializations.
 *  
 *  When providing specialisations for template classes you must start by defining a generic template.
 *  Specialisations must have the same name, but some (partial specialization) or all (full 
 *  specialization) of the template parameters will have constraints applied.  Note the use of the <>
 *  in the specialized templates (not present in the generic template):
 *      class collection<bool>
 * 
 *  Here we see an example of a full secialization whereby the parameter T of the generic template
 *  has been replaced by bool.  The compiler will choose the specialized template in preference to
 *  the generic template if appropriate.
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

