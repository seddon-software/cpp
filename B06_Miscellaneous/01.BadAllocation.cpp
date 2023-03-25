//////////////////////////////////////////////////////////////////////
//
//		Bad Allocation
//
//////////////////////////////////////////////////////////////////////

#include <new>
#include <iostream>
using namespace std;

/*
 *  Memory can be allocated on the heap using two forms of the new operator
 *	    1) new(nothrow) - returns 0 on error
 *	    2) new - throws bad_alloc on error
 *
 *  We investigate both forms of allocation in the code below.  The second form is probly best since
 *  it obviates the need to test the return value from new. 
 */


 
int main()
{
	int* p = new int(1);  // non zero p

    while (p) 
    {
        p = new(nothrow) int[100000000ul];
    }
    cout << "Allocation failed (nothrow)" << endl;

    try
    {
        while (true) 
        {
            p = new int[100000000ul];
        }
    } 
    catch (const std::bad_alloc& e) 
    {
        cout << "Allocation failed: " << e.what() << endl;
    }
}

  
