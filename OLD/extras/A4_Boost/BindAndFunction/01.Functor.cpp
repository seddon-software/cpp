////////////////////////////////////////////////////////////
//
//		Bind and Function
//
////////////////////////////////////////////////////////////

#include <vector>
#include <iostream>
using namespace std;


class A		// functor
{
private:
	int x;
public:
	A(int x) : x(x) {}

	int operator()(int y, int z) 
	{ 
		return x + y + z; 
	}	
};

//////

int main()
{
	int x = 5;
	int y = 7;
	int result;
	
	A a(100);			// intialize functor
	result = a(x, y);	// invoke functor


	return 0;
}

