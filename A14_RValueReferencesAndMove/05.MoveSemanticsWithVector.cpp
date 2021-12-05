#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template <typename T>
class MyVector : public vector<T>
{
public:
	// Notes:
	// 1. It is not usually safe to derive from STL classes
	//		because vector<T> does NOT have a virtual DTOR
	// 2. Note the move CTOR must call std::move to invoke the base class move CTOR
	//      or else the vector<T> copy CTOR will be called

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
		// by giving rhs a name it is an l-value (its type is an r-value)
		// convert rhs to an r-value
		// before calling = in base class
		(*this).vector<T>::operator=(std::move(rhs));
		cout << "operator=(&&) called" << endl;
		return *this;
	}
};

template <typename T>
void Swap(T& a, T& b)
{
	T temp(std::move(a));
	a = std::move(b);
	b = std::move(temp);
//	T temp(a);
//	a = b;
//	b = temp;
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
