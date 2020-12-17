#include "boost/date_time/posix_time/posix_time.hpp"
#include <iostream>
using namespace std;

int main()
{
	using namespace boost::posix_time;
	using namespace boost::gregorian;

	date d(2002, Feb, 1);

	ptime t1(d, hours(5) + minutes(4) + seconds(2) + millisec(1));
	ptime t2 = t1 + hours(5) - minutes(4) - seconds(2) - millisec(1);
	ptime t3(d, seconds(0));

	time_duration td1 = t2 - t1;
	cout << td1 << endl;

	time_duration td2 = t1 - t3;
	cout << td2 << endl;
}
