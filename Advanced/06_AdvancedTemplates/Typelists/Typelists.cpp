////////////////////////////////////////////////////////////
//
//      Test Typelists
//
////////////////////////////////////////////////////////////

#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#include <iostream>
#include <vector>
#include "Typelists.h"
using namespace std;


int main()
{	
	typedef Typelist<int> MyTypeList1;
	typedef Typelist<int, double> MyTypeList2;
	typedef Typelist<int, double, string> MyTypeList3;
	typedef Typelist<int, double, string, float> MyTypeList4;
	int n = 0;

// Length<typelist>
	n = Length<MyTypeList3>::value;
	n = Length<MyTypeList1>::value;
	n = Length<MyTypeList2>::value;

// TypeAt<typelist,index>
	typedef TypeAt<MyTypeList4, 1>::result MyType;
	[[ maybe_unused ]]
	MyType x = 24.75;	// should be a double
	
// IndexOf<typelist,type>
	n = IndexOf<Typelist<int,string>, int>::value;
	n = IndexOf<Typelist<int,double,string>, double>::value;
	n = IndexOf<Typelist<int,double,vector<string>>, vector<string>>::value;
	n = IndexOf<MyTypeList1, int>::value;
	n = IndexOf<MyTypeList4, string>::value;
	n = IndexOf<Typelist<>, MyTypeList3>::value;	// not found
	n = IndexOf<Typelist<int, MyTypeList4, double>, MyTypeList4>::value;
	n = IndexOf<Typelist<int, MyTypeList4, double, vector<MyTypeList4>>, vector<MyTypeList4>>::value;
	n = IndexOf<Typelist<int, int, int, int, int, int, int, int, int, int, double>, double>::value;
}

