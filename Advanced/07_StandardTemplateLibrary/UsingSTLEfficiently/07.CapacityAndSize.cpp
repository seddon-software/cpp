#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	vector<double> v(10000);
    cout << "capacity = " << v.capacity() << " size = " << v.size() << endl;

    v.clear();
	cout << "CLEAR: ";
    cout << "capacity = " << v.capacity() << " size = " << v.size() << endl;

	// swap v with temporary vector of same type
	vector<double>().swap(v);
	cout << "SWAP: ";
    cout << "capacity = " << v.capacity() << " size = " << v.size() << endl;

	// assign data to each slot
	v.assign(10000, 27.87);
	cout << "ASSIGN: ";
    cout << "capacity = " << v.capacity() << " size = " << v.size() << endl;

    v.resize(1);
	cout << "RESIZE: ";
    cout << "capacity = " << v.capacity() << " size = " << v.size() << endl;

    vector<double>(v).swap(v);
	cout << "SWAP: ";
    cout << "capacity = " << v.capacity() << " size = " << v.size() << endl;
}

