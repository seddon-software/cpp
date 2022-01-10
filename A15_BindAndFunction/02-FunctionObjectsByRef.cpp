////////////////////////////////////////////////////////////
//
//		Bind and Function
//
////////////////////////////////////////////////////////////

#include <vector>
#include <iostream>
#include <functional>
using namespace std;

/*
 *  When we use the bindings library with objects, we can pass an object by value or by reference.  When
 *  we pass by value, a copy of the object is passed to the binding function, meaning the original object
 *  will be left unchanged by any callback:
 *      	f = std::bind(&A::Modify, a1, _1, _2);
 * 
 *  If we really want to change the original object it needs to be passed by reference:
 *	        f = std::bind(&A::Modify, std::ref(a2), _1, _2);
 */

class A
{
private:
	int a;
public:
    friend ostream& operator<<(ostream& os, const A& rhs)
    {
        return os << rhs.a;
    }
	A() : a() {}
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
	A result;
	
	// create function object pointer
	std::function<A&(int,int)> f;

	A a1(999);
	A a2(999);

	// pass by value: A::Modify(copy_of_a1, _1, _2)
	f = std::bind(&A::Modify, a1, _1, _2);

	// pass by ref:   A::Modify(a2, _1, _2)
	f = std::bind(&A::Modify, std::ref(a2), _1, _2);


	// pass by value:
	result = f(2, 3);	  
    cout << "result = " << result << ", a1 = " << a1 << endl;   // a1 not changed

	// pass by ref:
	result = f(2, 3);
    cout << "result = " << result << ", a2 = " << a2 << endl;   // a2 is changed
}

