#include <iostream>
#include <string>
using namespace std;

class Hour
{
friend ostream& operator<<(ostream& os, const Hour& rhs);
public:
	constexpr explicit Hour(int h) : hour(h) {}
private:
	int hour;
};

ostream& operator<<(ostream& os, const Hour& rhs)
{
	return os << rhs.hour;
}


class Minute
{
friend ostream& operator<<(ostream& os, const Minute& rhs);
public:
	constexpr explicit Minute(int m) : minute(m) {}
private:
	int minute;
};

ostream& operator<<(ostream& os, const Minute& rhs)
{
	return os << rhs.minute;
}

constexpr Hour
operator"" _h(unsigned long long h)
{
	return static_cast<Hour>(h);
}

constexpr Minute
operator"" _m(unsigned long long m)
{
	return static_cast<Minute>(m);
}

class Time
{
public:
	Time(Hour h, Minute m) : hour(h), minute(m) {}
	void display()
	{
		cout << hour << ":" << minute << endl;
	}
private:
	Hour hour;
	Minute minute;
};

int main()
{
	// without typesafe literals
	Hour h10(10);
	Minute m35(35);
	Time c1(h10, m35);
	c1.display();

	// with typesafe literals
	Time c2(10_h, 35_m);
	c2.display();
}
