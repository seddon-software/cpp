////////////////////////////////////////////////////////////
//
//		Function Try Blocks
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <stdexcept>
using namespace std;


// not very useful in practice
int f(int x)
try		// function try block
{
    if(x < 0) throw range_error("must be >= 0");
    return x;
}
catch(range_error& e)
{
	cout << e.what() << endl;
	return 0;
}

/////

int main()
{
	int result = 0;
	result = f(100);
	result = f(200);
	result = f(-77);
	return result;
}
