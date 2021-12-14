////////////////////////////////////////////////////////////
//
//		Bind and Function
//
////////////////////////////////////////////////////////////

#include <vector>
#include <iostream>
#include <boost/bind.hpp>
#include <boost/function.hpp>
using namespace std;


class A
{
private:
	int a;
public:
	A(int a) : a(a) {}
	A& Modify(int x, int y)
	{
		(*this).a = x + y;
		return *this;
	}
};


//////

int main()
{
	A result(0);
	
	// create function object pointers
	boost::function<A&(int,int)> f;
	boost::function<A&(int,int)> fref;

	A a1(100);
	A a2(200);

	// pass by value
	f = boost::bind(&A::Modify, a1, _1, _2);
	// pass by ref
	fref = boost::bind(&A::Modify, boost::ref(a2), _1, _2);


	result = f(2, 3);	  // invoke binder
	result = fref(4, 6);	  // invoke binder


	return 0;
}

