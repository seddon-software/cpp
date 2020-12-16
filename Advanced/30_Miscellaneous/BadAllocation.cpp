//////////////////////////////////////////////////////////////////////
//
//		Bad Allocation
//
//////////////////////////////////////////////////////////////////////

#include <new>
#include <iostream>
using namespace std;

struct Big
{
    char bytes[2 * 1000 * 1000 * 1000];	// 2 GB
};

/////

// memory can be allocated on the heap using two forms of new
//	1) new(nothrow) - returns 0 on error
//	2) new - throws bad_alloc on error

int main()
{
	void* p;
	try
	{
		p = new(nothrow) Big;		// returns p = 0
		cout << "p = " << p << endl;

		p = new Big;				// throws bad_alloc
		cout << "Shouldn't get here" << endl;
	}
	catch(bad_alloc)
	{
		cout << "Bad allocation" << endl;
	}

	return 0;
}
  
