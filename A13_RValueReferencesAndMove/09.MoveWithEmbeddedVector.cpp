/*  
 *  In this example we wrap a vector in our own "MyVector" class and subsequently swap the contents
 *  of two such objects using move constructors and move assignments.
 */

#include <iostream>
#include <type_traits>
#include <initializer_list>
#include <algorithm>
#include <vector>

using namespace std;

template <typename T>
class MyVector
{
private:
    vector<T> v;
public:
	MyVector() : v()
	{
		cout << "Default CTOR";
	}
	MyVector(std::initializer_list<T> list) : v(list)
	{
		cout << "Initializer CTOR" << endl;
	}
	MyVector(const MyVector& rhs) : v(rhs.v)
	{
		cout << "COPY CTOR" << endl;
	}
	// convert rhs to an r-value ref to call move CTOR in base class
	MyVector(MyVector&& rhs) : v(std::move(rhs.v))
	{
		cout << "MOVE CTOR" << endl;
	}
	MyVector& operator=(const MyVector& rhs) noexcept
	{
		v = rhs.v;
		cout << "operator=(&) called" << endl;
		return *this;
	}
	MyVector& operator=(MyVector&& rhs) noexcept
	{
		v = rhs.v;
    	cout << "operator=(&&) called" << endl;
		return *this;
	}
    vector<T>::iterator begin()
    {
        return v.begin();
    }
    vector<T>::iterator end()
    {
        return v.end();
    }
};

template <typename T>
void SwapWithMove(T& a, T& b)
{
    // use move semantics (efficient)
	T temp(std::move(a));
	a = std::move(b);
	b = std::move(temp);
}

template <typename T>
void SwapWithCopy(T& a, T& b)
{
    // use copy semantics (inefficient)
    T temp2(a);
    a = b;
    b = temp2;
}

int main()
{
	MyVector<int> v1{0, 1, 2, 3, 4};
	MyVector<int> v2{9, 8, 7, 6, 5};
	SwapWithMove(v1, v2);
	for (auto i : v1) cout << i << ",";
	cout << endl;
	for (auto i : v2) cout << i << ",";
	cout << endl;
	SwapWithCopy(v1, v2);
}
