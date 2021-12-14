#include "boost/date_time/gregorian/gregorian.hpp"
#include <iostream>
using namespace std;

int main() {
	int year = 2012;
	int month = 6;		// June

	using namespace boost::gregorian;
	try {
		date startOfMonth = date(year, month, 1);
		int last_day = gregorian_calendar::end_of_month_day(year, month);
		date endOfMonth(year, month, last_day);

		for (day_iterator iterator = startOfMonth; iterator <= endOfMonth; ++iterator)
		{
			cout << *iterator << " [" << iterator->day_of_week() << "]" << endl;
		}
	} catch (exception& e) {
		cout << "Error bad date: " << e.what() << endl;
	}
}
