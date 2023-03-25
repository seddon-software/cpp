#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
 *  vectors usually allocate more space than required to store the current items.  The additional space
 *  is to cope with expansion.  You can check on the number of slots actually in use (size) and the 
 *  number reserved (capacity).
 * 
 *  Note how the capacity changes as the vector fills up. 
 */

class Point
{
public:
	Point(int x, int y) : x(x), y(y) {}
private:
	int x;
	int y;
};

template <typename T>
void allocate(vector<T>& v, const T& t)
{
	v.push_back(t);
	cout << "size=" << v.size() << "\t" << "capacity=" << v.capacity() << endl;
}


int main()
{
// note how capacity doubles when vector is full
	{
		// use reserve
		vector<Point> v;
		v.reserve(10);
		for(int i = 0; i < 33; i++)
			allocate(v, Point(i, 2*i));
	}
	cout << "--------" << endl;
	{
		// use default (no initial reserved space)
		vector<Point> v;
    	cout << "size=" << v.size() << "\t" << "capacity=" << v.capacity() << endl;

		for(int i = 0; i < 33; i++)
			allocate(v, Point(i, 2*i));
	}
}

