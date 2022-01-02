////////////////////////////////////////////////////////////
//
//		Traits
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using namespace std;

/*  Following on from our previous example, we define our own trait that
 *  allows us to choose a return type from our "Max" function.  And, yes there
 *  is a much easier way to do this using decltype (discussed elsewhere) - this
 *  example is just for illustration of the general technique.
 * 
 *  First we define a generic traits template (which is never used) and then a series 
 *  of specializations.  We use this traits template in a policy template "promote_trait".
 *  This policy template is used to determine the return type of "Max".
 */

// generic template (not used)
template <typename T>
class checkReturnType {};

// specialization for double return types
template <>
struct checkReturnType<double>
{
	checkReturnType()
	{
		cout << "double" << endl;
	}
};

// specialization for float return types
template <>
struct checkReturnType<float>
{
	checkReturnType()
	{
		cout << "float" << endl;
	}
};

/////
//promote_trait<L,R>::T_promote

// generic case (not used)
template<class A, class B>
class promote_trait {
public:
};

// specializations
template<>
class promote_trait<int, double> {
public:
	typedef double T_promote;
};

template<>
class promote_trait<double, int> {
public:
	typedef double T_promote;
};

template<>
class promote_trait<int, float> {
public:
	typedef float T_promote;
};

template<>
class promote_trait<float, int> {
public:
	typedef float T_promote;
};

template<class A>
class promote_trait<A, A> {
public:
	typedef A T_promote;
};


/////

template <typename L, typename R>
typename promote_trait<L,R>::T_promote Max(L a, R b)
{
	checkReturnType<typename promote_trait<L,R>::T_promote> test;
	if (a > b)
		return a;
	else
		return b;
}

/////

int main()
{
	[[ maybe_unused]]
	double d1 = Max(5, 8.2);
	// call promote_trait<L,R>::T_promote Max(L a, R b)  // L=int, R=double
	// call promote_trait<int,double>::T_promote Max(int a, double b)  
		// typedef promote_trait<int,double>::T_promote = double
	// call double Max(int a, double b)

	[[ maybe_unused]]
	float f1 = Max(5, 7.3F);
	// call promote_trait<L,R>::T_promote Max(L a, R b)  // L=int, R=float
	// call promote_trait<int,float>::T_promote Max(int a, float b)  
		// typedef promote_trait<int,float>::T_promote = float
	// call float Max(int a, double b)

	[[ maybe_unused]]
	double d2 = Max(8.2, 5);
	[[ maybe_unused]]
	float f2 = Max(7.3F, 5);
}

