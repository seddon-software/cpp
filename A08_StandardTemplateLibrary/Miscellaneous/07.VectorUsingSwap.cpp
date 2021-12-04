#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	/* size: 	 number of elements
	 * capacity: number of elements reserved in memory
     *
	 * use the swap trick to reduce the capacity of a large vector, 
	 * otherwise lots of empty slots are left in memory
     */	

	vector<double> v(10000);
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

