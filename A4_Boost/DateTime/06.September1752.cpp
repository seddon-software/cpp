#include <boost/date_time/gregorian/gregorian.hpp>
#include <iostream>
using namespace std;


int main()
{
	boost::gregorian::date d1(1752, 9, 1);
	boost::gregorian::date d2(1752, 10, 1);

	// day/week arithmetic
	boost::gregorian::date_duration dd;
	dd = d2 - d1;
	cout << dd.days() << endl;
}
