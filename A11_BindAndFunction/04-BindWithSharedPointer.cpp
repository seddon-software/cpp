////////////////////////////////////////////////////////////
//
//		Bind and Function
//
////////////////////////////////////////////////////////////

#include <vector>
#include <iostream>
#include <functional>
#include <memory>
using namespace std;


class A
{
private:
	int a;
public:
	A(int a) : a(a) {}
	A& Modify(int x, int y)
	{
		cout << "this=" << this << endl;
		(*this).a = x + y;
		return *this;
	}
};


//////

int main()
{
	using namespace std::placeholders;

	A a(100);
	std::shared_ptr<A> p(new A(200));
	cout << "&a=" << &a << endl;
	cout << "p=" << p << endl;
	
	// create function object pointers and call in one go
	// print out value of this to see which object or pointer is invoked
	bind(&A::Modify, ref(a), _1, _2)(10, 20);	// a.Modify(10, 20)
	bind(&A::Modify, &a, _1, _2)(11, 22);		// (&a)->Modify(10, 20)
	bind(&A::Modify, a, _1, _2)(12, 24);		// (copy of a).Modify(10, 20)
	bind(&A::Modify, p, _1, _2)(13, 26);		// (copy of p)->Modify(10, 20),
												// but this is same as
												// p->Modify(10, 20)

	return 0;
}

