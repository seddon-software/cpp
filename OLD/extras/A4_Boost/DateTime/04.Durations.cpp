#include <boost/date_time/gregorian/gregorian.hpp>
#include <iostream>
using namespace std;


int main()
{
	boost::gregorian::date d1(1900, 1, 1);
	boost::gregorian::date d2(2000, 1, 1);
	boost::gregorian::date_duration dd = d2 - d1;
	cout << dd.days() << endl;
}
