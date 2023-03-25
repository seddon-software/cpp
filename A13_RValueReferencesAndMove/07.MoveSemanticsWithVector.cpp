#include <iostream>
#include <type_traits>
#include <initializer_list>
#include <algorithm>
#include <vector>

using namespace std;

/*  In this example we wrap a vector in our own "MyVector" class and subsequently swap the contents
 *  of two such objects using move constructors.
 *
 * 	Notes:
 *		1. It is usually NOT safe to derive from STL classes such as vector because vector<T> does 
 *         NOT have a virtual DTOR.
 *		2. The move CTOR must call std::move to invoke the base class move CTOR
 *	       or else the copy CTOR of vector<T> will be called.
 *      3. We use the initializer_list template to cope with multiple initalizers for our class.
 */

template <typename T>
void checkArg(T&& parameter, const string& name)
{
	if (std::is_lvalue_reference<T&&>::value)
		cout << name + " is an l-value ref" << endl;
	else
		cout << name + " is an r-value ref" << endl;
}

template <typename T>
class MyVector : public vector<T>
{
public:

	MyVector() : vector<T>()
	{
		cout << "Default CTOR";
	}
	MyVector(std::initializer_list<T> list) : vector<T>(list)
	{
		cout << "Initializer CTOR" << endl;
	}
	MyVector(const MyVector& rhs) : vector<T>(rhs)
	{
		cout << "COPY CTOR" << endl;
	}
	// convert rhs to an r-value to call move CTOR in base class
	MyVector(MyVector&& rhs) : vector<T>(std::move(rhs))
	{
		cout << "MOVE CTOR" << endl;
	}
	MyVector& operator=(const MyVector& rhs) noexcept
	{
		(*this).vector<T>::operator=(rhs);
		cout << "operator=(&) called" << endl;
		return *this;
	}
	MyVector& operator=(MyVector&& rhs) noexcept
	{
		checkArg(rhs, "rhs");
		// by giving rhs a name it is an l-value (because of r-value ref collapsing rules)
		// so convert rhs to an r-value
		// before calling = in base class
		MyVector&& r{std::move(rhs)};
		checkArg(std::move(rhs), "std::move(rhs)");
		// base class is vector<T>
		// method to call is operator=()
		// to call method in base class => base::method() => vector<T>::operator()
		vector<T>::operator=(r);
		cout << "operator=(&&) called" << endl;
		return *this;
	}
};

template <typename T>
void Swap(T& a, T& b)
{
	//	T temp(a);
	//	a = b;
	//	b = temp;
	T temp(std::move(a));
	a = std::move(b);
	b = std::move(temp);
}

int main()
{
	MyVector<int> v1{0, 1, 2, 3, 4};
	MyVector<int> v2{9, 8, 7, 6, 5};
	Swap(v1, v2);
	for (auto i : v1) cout << i << ",";
	cout << endl;
	for (auto i : v2) cout << i << ",";
	cout << endl;
}
