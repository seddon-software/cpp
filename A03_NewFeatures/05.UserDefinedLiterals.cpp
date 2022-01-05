#include <iostream>
#include <sstream>
#include <string>
using namespace std;

/*
 *  User-defined literals (since C++11) are used to produce objects of a defined type by defining
 *  a user-defined suffix.  The idea to to make types more readable, for example:
 *      10_h
 *  Note that user-defined literals are now regular operator overloads, so you can also include any
 *  additional code in the overload.
 *  
 *  The ""s operator overload is part of the std namespace and converts a const char* to a mutable
 *  basic_string<char> automatically.
 */

 

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

    // built in support for strings
    auto hello = "Hello"s;   // s is a mutable string, not const char*
    hello  += "-world"s;  // modify mutable string
    cout << hello << endl;
}
