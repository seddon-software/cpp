#include "boost/date_time/posix_time/posix_time.hpp"
#include <iostream>

using namespace std;

int main()
{
	using namespace boost::posix_time;
	using namespace boost::gregorian;

	//get the current time from the clock -- one second resolution
	ptime now = second_clock::local_time();

	//Get the date part out of the time
	date today = now.date();
	date tommorrow = today + days(1);
	ptime tommorrow_start(tommorrow); //midnight
	time_duration remaining = tommorrow_start - now;
	cout << "Time left till midnight: " << remaining << endl;

	//iterator adds by one hour
	for(time_iterator iterator(now, hours(1)); iterator < tommorrow_start; ++iterator)
	{
		cout << *iterator << endl;
	}
}
