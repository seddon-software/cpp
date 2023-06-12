#include <iostream>
using namespace std;

/*
 *  Here we define our own smart pointer to illustrate how the std::unique_ptr works.
 *  Recall that the idea is to provide a unique handle to a heap based object (the body) 
 *  such that when the handle goes out of scope naturally or if an exception is thrown, 
 *  the handle's DTOR will delete the body, ensuring no resourse leaks.
 * 
 *  Because the smart pointer tracks a unique body we have to make sure we can't copy
 *  or assign our pointers:  
 * 		MyUniquePtr(const MyUniquePtr&) = delete;
 *		MyUniquePtr& operator=(const MyUniquePtr&) = delete;
 *
 *  The interesting parts of the code are in the move CTOR and the move operator=(&&).  In both
 *  methods, resources are stolen from the temporary that is going out of scope and the 
 *  temporary's pointer is nulled to avoid a double deallocation of the body.
 */

template <typename T>
class MyUniquePtr
{
public:
	MyUniquePtr(T* p) : ptr(p) 
	{
		cout << "MyUniquePtr stores pointer to body: " << p << endl << endl;
	}
	// can't copy or assign
	MyUniquePtr(const MyUniquePtr&) = delete;
	MyUniquePtr& operator=(const MyUniquePtr&) = delete;

	MyUniquePtr(MyUniquePtr&& rhs)
	{
		cout << "Move CTOR" << endl;
		ptr = rhs.ptr;
		cout << "stealing body of RHS: " << ptr << endl;
		rhs.ptr = nullptr;
		cout << "setting old pointer to null: " << rhs.ptr << endl << endl;
	}

	MyUniquePtr& operator=(MyUniquePtr<T>&& rhs)
	{
		cout << "operator=(MyUniquePtr&&)" << endl;
		cout << "deleting our body: " << ptr << endl;
		delete ptr;
		ptr = rhs.ptr;
		cout << "stealing body of RHS: "  << ptr << endl;
		rhs.ptr = nullptr;
		cout << "setting old pointer to null: " << rhs.ptr << endl << endl;
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
	X() { cout << "body on heap at: " << this << endl; }
	~X() { cout << "body::DTOR: " << this << endl; }
};

MyUniquePtr<X> f()
{
	MyUniquePtr<X> temp(new X{});
	return temp;	// calls move CTOR
}
int main()
{
	// only 2 smart pointers are created, so only 2 X::DTORs will be called
	MyUniquePtr<X> p1(new X{});
	MyUniquePtr<X> p2(new X{});
//	MyUniquePtr<X> p3(p1);				// can't use COPY CTOR
	MyUniquePtr<X> p4(std::move(p1));    // move CTOR transfers ownership

//	p1 = p2;		// can't use assignment of l-values
	p1 = std::move(p2);	// transfers ownership: calls operator=(&&)
}
