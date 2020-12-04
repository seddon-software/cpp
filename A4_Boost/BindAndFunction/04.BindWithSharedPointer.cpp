////////////////////////////////////////////////////////////
//
//		Bind and Function
//
////////////////////////////////////////////////////////////

#include <vector>
#include <iostream>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/shared_ptr.hpp>
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
	A a(100);
	boost::shared_ptr<A> p(new A(200));
	
	// create function object pointers and bind in one go
	bind(&A::Modify, boost::ref(a), _1, _2)(10, 20);	// a.f(10, 20)
	bind(&A::Modify, &a, _1, _2)(10, 20);				// (&a)->f(i)
	bind(&A::Modify, a, _1, _2)(10, 20);				// (internal copy of a).f(i)
	bind(&A::Modify, p, _1, _2)(10, 20);				// (internal copy of p)->f(i)

	return 0;
}

