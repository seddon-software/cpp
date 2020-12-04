////////////////////////////////////////////////////////////
//
//		Bind and Function
//
////////////////////////////////////////////////////////////

#include <vector>
#include <string>
#include <iostream>
#include <functional>
using namespace std;
using namespace std::placeholders;



class Operations
{
public:
	Operations(int n) : n(n) {}
	int Sum(int x, int y, int z) { return n + x + y + z; }
	int Product(int x, int y, int z) { return n * x * y * z; }
	int Average(int x, int y, int z) { return (n + x + y + z)/4; }
private:
	int n;
};

typedef function<int(int,int,int)> DT;

template <typename T>
struct Delegate
{
	vector<T> list;

	void operator+=(T item)
	{
		list.push_back(item);
	}

	void operator() ()
	{
		for(unsigned i = 0; i < list.size(); i++)
		{
			// _1 = 100, _2 = 200, _3 = 300
			cout << (list[i])(100, 200, 300) << endl;
		}
	}
};


//////

int main()
{
	using namespace std::placeholders;

	// create pointer to function objects
	Delegate<function<int(int,int,int)>> d;
	Operations x(2);
	Operations y(5);

	// load up multicast delegate
	auto f1 = std::bind(&Operations::Sum, x, 2, 4, _1);
	auto f2 = std::bind(&Operations::Product, y, 4, 2, _1);
	auto f3 = std::bind(&Operations::Average, y, 4, _2, _1);
	d += f1;
	d += f2;
	d += f3;

	// fire delegate
	d();
	
	return 0;
}

