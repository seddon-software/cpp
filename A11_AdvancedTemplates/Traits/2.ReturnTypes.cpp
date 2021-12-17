////////////////////////////////////////////////////////////
//
//		Traits
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using namespace std;

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

// generic case
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

#pragma GCC diagnostic ignored "-Wunused-variable"

int main()
{
	double x = Max(5, 8.2);
	double y = Max(8.2, 5);
	float f1 = Max(5, 7.3F);
	float f2 = Max(7.3F, 5);
}

