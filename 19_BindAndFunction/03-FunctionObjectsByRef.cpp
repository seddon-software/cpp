////////////////////////////////////////////////////////////
//
//		Bind and Function
//
////////////////////////////////////////////////////////////

#include <vector>
#include <iostream>
#include <functional>
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
	using namespace std::placeholders;
	A result(0);
	
	// create function object pointers
	std::function<A&(int,int)> f;
	std::function<A&(int,int)> fref;

	A a1(100);
	A a2(200);

	// pass by value
	f = std::bind(&A::Modify, a1, _1, _2);
	// pass by ref
	fref = std::bind(&A::Modify, std::ref(a2), _1, _2);


	// pass by value
	result = f(2, 3);	  // a1 not changed
	// pass by ref
	result = fref(4, 6);  // a2 is changed
}

