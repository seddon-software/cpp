#include "boost/date_time/gregorian/gregorian.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"
#include <iostream>
using namespace std;

int main()
{
	boost::gregorian::date start(1952, 6, 2);
	boost::gregorian::date today = boost::gregorian::day_clock::local_day();
	boost::gregorian::date_period reign(start, today);
	boost::gregorian::date_duration dd = reign.length();
	cout << "The Queens reign has been for: ";
	cout << dd.days() << " days" << endl;
}
