#include <iostream>
#include <string>
using namespace std;

constexpr long long int
operator"" _h(unsigned long long h)
{
	return h;
}

constexpr long long int
operator"" _m(unsigned long long m)
{
	return m;
}

class Time
{
public:
	Time(int h, int m) : hour(h), minute(m) {}
	void display()
	{
		cout << hour << ":" << minute << endl;
	}
private:
	int hour;
	int minute;
};

// typesafe literals are used for readability
int main()
{
	// without typesafe literals
	Time t1(10, 35);
	t1.display();

	// with typesafe literals
	Time t2(10_h, 35_m);
	t2.display();
}
