////////////////////////////////////////////////////////////
//
//		Template Functions
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using namespace std;

template<typename RET, typename T1, typename T2>
RET add(T1 x, T2 y)   // can't deduce return type in C++98
{
	return x + y;
}

void stage1()
{
	cout << add<int>(10, 20) << endl;
	cout << add<double>(10.7, 20) << endl;
	cout << add<string>(string("Hello"), string("World")) << endl;
}

template<typename T1, typename T2>
auto add2(T1 x, T2 y) -> decltype(x + y)   // in C++11 this is called "tail type inference"
{
	return x + y;
}

void stage2()
{

	cout << add2(10, 20) << endl;
	cout << add2(10.7, 20) << endl;
	cout << add2(string("Hello"), string("World")) << endl;
}

template<typename T1, typename T2>
auto add3(T1 x, T2 y)  // C++14 can deduce return type automatically
{
	return x + y;
}

void stage3()
{

	cout << add3(10, 20) << endl;
	cout << add3(10.7, 20) << endl;
	cout << add3(string("Hello"), string("World")) << endl;
}

/////

int main()
{
	stage1();
	stage2();
	stage3();
}

