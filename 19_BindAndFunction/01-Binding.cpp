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
	int x;
public:
	A(int x) : x(x) {}
	int Add(int y, int z) { return x + y + z; }	
	int Subtract(int y, int z) { return x - y - z; }
};

class B
{
private:
	int x;
public:
	B(int x) : x(x) {}
	int Add(int y, int z) { return x + y + z; }
	int Subtract(int y, int z) { return x - y - z; }
};

int Add(int a, int b) { return a + b; }
int Subtract(int a, int b) { return a - b; }
int Multiply(int a, int b) { return a * b; }

//////

int main()
{
	using namespace std::placeholders;
	int result = 0;
	
	// create pointer to function objects
	std::function<int(int,int)> f;

	// bind to global functions and invoke
	f = std::bind(&Add, _1, _2);
	result = f(50, 60);
	result = f(40, 30);
	f = std::bind(&Subtract, _1, _2);
	result = f(50, 20);
	result = f(40, 30);

	// reduce number of parameters
	std::function<int(int)> g;
	g = std::bind(&Multiply, 10, _1);
	result = g(2);
	result = g(5);

	// bind to a member functions
	A a1(100);
	A a2(200);
	B b1(10);
	B b2(20);

	f = std::bind(&A::Add, a1, _1, _2);
	result = f(2, 3);
	result = f(4, 6);

	// create function object pointers specifying 1st parameter
	std::function<int(A&,int,int)> fa;
	std::function<int(B&,int,int)> fb;
	fa = std::bind(&A::Add, _1, _2, _3);
	fb = std::bind(&B::Subtract, _1, _2, _3);
	result = fa(a1, 4, 7);
	result = fa(a2, 4, 7);
	result = fb(b1, 4, 7);
	result = fb(b2, 4, 7);

	return 0;
}

