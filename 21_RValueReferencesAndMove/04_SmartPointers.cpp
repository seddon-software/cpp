#include <iostream>
using namespace std;

template <typename T>
class MyUniquePtr
{
public:
	MyUniquePtr(T* p) : ptr(p) {}
	// can't copy or assign
	MyUniquePtr(const MyUniquePtr&) = delete;
	MyUniquePtr& operator=(const MyUniquePtr&) = delete;

	MyUniquePtr(MyUniquePtr&& rhs)
	{
		// steal body from rhs and disable rhs
		ptr = rhs.ptr;
		rhs.ptr = nullptr;
	}

	MyUniquePtr& operator=(MyUniquePtr<T>&& rhs)
	{
		// clean up our resource, then steal body from rhs and disable rhs
		delete ptr;
		ptr = rhs.ptr;
		rhs.ptr = 0;
		return *this;
	}
	~MyUniquePtr()
	{
		delete ptr;
	}
private:
	T* ptr;
};

struct X
{
	~X() { cout << "DTOR" << endl; }
};

MyUniquePtr<X> f()
{
	MyUniquePtr<X> temp(new X{});
	return temp;	// calls move CTOR
}
int main()
{
	// only 2 X's are created, so only 2 DTORs are called
	MyUniquePtr<X> p1(new X{});
	MyUniquePtr<X> p2(new X{});
//	MyUniquePtr<X> p3(p1);				// can't use COPY CTOR
	MyUniquePtr<X> p4(std::move(p1));    // move CTOR transfers ownership

//	p1 = p2;		// can't use assignment of l-values
	p1 = std::move(p2);	// transfers ownership: calls operator=(&&)
}
