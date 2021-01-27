#include <iostream>
#include <vector>
#include <string>

using namespace std;

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
	cout << v.size() << "\t" << v.capacity() << endl;
}

int main()
{
	{
		vector<Point> v;
		v.reserve(10);
		for(int i = 0; i < 33; i++)
			allocate(v, Point(i, 2*i));
	}
	cout << "--------" << endl;
	{
		vector<Point> v;
		// no reserve
		for(int i = 0; i < 33; i++)
			allocate(v, Point(i, 2*i));
	}
}

