#include <memory>
using namespace std;
class A {};
class B : public A {};
class C : public B {};


int main()
{
	shared_ptr<C> h(new C);
	{
		shared_ptr<A> r2 = std::static_pointer_cast<A>(h);
	}
}

