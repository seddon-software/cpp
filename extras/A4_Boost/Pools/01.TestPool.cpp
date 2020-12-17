////////////////////////////////////////////////////////////
//
//		Pools
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
using namespace std;

#include <boost/pool/object_pool.hpp>


class MyString
{
public:
	MyString() { cout << "CTOR" << endl; }  // never called
	~MyString() { cout << "DTOR:" << x << endl; } // always called
	void init(int x) { this->x = x; }
	void f() { cout << "f():" << x << endl; }
private:
	int x;
};


int main()
{
	{
		boost::object_pool<MyString> pool;
		vector<MyString*> array;

		// allocate memory and store in a vector
		for (int i = 0; i < 10; ++i)
		{
			MyString* const ptr = pool.malloc();
			ptr->init(i);	// two phase construction (CTOR not used)
			array.push_back(ptr);
		}

		// use objects
		for (int i = 0; i < 10; ++i)
		{
			array[i]->f();
		}
	} // automatic cleanup
}

