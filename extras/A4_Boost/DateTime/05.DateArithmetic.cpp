#include <boost/date_time/gregorian/gregorian.hpp>
#include <iostream>
using namespace std;


int main()
{
	// day/week arithmetic
	boost::gregorian::date_duration dd(10);
	boost::gregorian::weeks ws(4);
	dd = ws - dd;
	cout << dd.days() << endl;
	cout << ws.days() << endl;

	// month/year arithmetic
	boost::gregorian::months ms(9);
	boost::gregorian::years ys(10);
	ms = ys - ms;
	cout << ms.number_of_months() << endl;
}
