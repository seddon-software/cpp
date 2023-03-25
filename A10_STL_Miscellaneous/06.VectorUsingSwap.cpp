#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
 *  It is surprisingly difficult to reduce the capacity of a vector.  Deleting all the elements 
 *  reduces its size, but not its capacity.  However, to reduce the capacity we can employ the 
 *  so called swap trick.
 *  
 *  This is where we create an temporary vector with zero capacity and swap it with our vector.
 *  The temporary will take on the contents of our vector, but will go out of scope immediately
 *  and be destroyed.  Our vector will now be the zero capacity vector.
 * 
 *  Recall:
 *	    size: 	  number of elements
 *      capacity: number of elements reserved in memory
 */

int main()
{
    // use the swap trick to reduce the capacity of a large vector, 
    // otherwise lots of empty slots are left in memory

	vector<double> v(10000);  // allocate a large vector
    cout << "capacity = " << v.capacity() << " size = " << v.size() << endl;

    v.clear();  // clears the size, but not the capacity
	cout << "CLEAR: ";
    cout << "capacity = " << v.capacity() << " size = " << v.size() << endl;

	// swap v with empty temporary vector of same type
	vector<double>().swap(v);
	cout << "SWAP: ";
    cout << "capacity = " << v.capacity() << " size = " << v.size() << endl;

	// assign data to each slot
	v.assign(10000, 27.87);
	cout << "ASSIGN: ";
    cout << "capacity = " << v.capacity() << " size = " << v.size() << endl;

	// just keep the first element
	vector<double> vv = {0.0};
	vv.swap(v);
	cout << "RESIZE: ";
    cout << "capacity = " << v.capacity() << " size = " << v.size() << endl;
}

