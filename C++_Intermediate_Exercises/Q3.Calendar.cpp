#include "boost/date_time/gregorian/gregorian.hpp"
#include <iostream>
using namespace std;
using namespace boost::gregorian;


void PrintMonth(int month, int year)
{
	try {
		// determine month extent
		date startOfMonth = date(year, month, 1);
		int last_day = gregorian_calendar::end_of_month_day(year, month);
		date endOfMonth(year, month, last_day);

		// set up facet for full month names
		date_facet* us_facet = new date_facet();
		std::cout.imbue(std::locale(std::locale::classic(), us_facet));
		us_facet->format("%B");

		// print month name
		cout << startOfMonth << endl;

		// print headings
		cout << " Mon Tue Wed Thu Fri Sat Sun" << endl;

		// insert spaces for start of month
		int spaces = (startOfMonth.day_of_week().as_number() - 1) * 4;
		cout << setw(spaces) << "";

		// loop round each day
		for (day_iterator iterator = startOfMonth; iterator <= endOfMonth; ++iterator)
		{
			cout << setw(4) << iterator->day();// << " [" << iterator->day_of_week() << "]";
			if ( iterator->day_of_week() == Sunday ) cout << endl;
		}
		cout << "\n" << endl;

	} catch (exception& e) {
		cout << "Error bad date: " << e.what() << endl;
	}
}

int main()
{
	int year = 2012;
	cout << year << endl;

	for(int month = 1; month <= 12; month++)
	{
		PrintMonth(month, year);
	}

}


