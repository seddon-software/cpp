#include <boost/date_time/gregorian/gregorian.hpp>
#include <iostream>
using namespace std;

int main()
{
	boost::gregorian::date d = boost::gregorian::day_clock::universal_day();
	cout << d.year() << "-" << d.month() << "-" << d.day() << endl;

	d = boost::gregorian::date_from_iso_string("20100131");
	cout << d.year() << "-" << d.month() << "-" << d.day() << endl;
}
