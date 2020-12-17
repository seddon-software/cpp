#include <boost/numeric/conversion/cast.hpp>
#include <iostream>
using namespace std;

int main()
{
	try
	{
		{
			int i = 0x100;
			short s = boost::numeric_cast<short>(i);
			cout << s << endl;
		}
		{
			int i = 0x10000;
			short s = boost::numeric_cast<short>(i);
			cout << s << endl;
		}
	}
	catch (boost::numeric::bad_numeric_cast &e) {
		cout << e.what() << endl;
	}

	try
	{
		int i = -0x10000;
		short s = boost::numeric_cast<short>(i);
		cout << s << endl;
	}
	catch (boost::numeric::negative_overflow &e)
	{
		cout << e.what() << endl;
	}
}
