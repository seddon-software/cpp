#include <boost/date_time/gregorian/gregorian.hpp>
#include <iostream>
using namespace std;

int main()
{
	boost::gregorian::date d(2010, 1, 30);
	cout << d.year() << endl;
	cout << d.month() << endl;
	cout << d.day() << endl;
	cout << d.day_of_week() << endl;
	cout << d.end_of_month() << endl;
}
