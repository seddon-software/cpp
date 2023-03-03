/*
 * Using a variation of the above program, calculate the
 * number of days in the inclusive date range
 * '1st January 2000' to '31st December 2999'
 */

#include <iostream>
using namespace std;

int daysInYear(int year)
{
    int days = 365;
    if(year %   4 == 0) days = 366;
    if(year % 100 == 0) days = 365;
    if(year % 400 == 0) days = 366;
    return days;
}

int main()
{
	int totalDays = 0;

	for(int year=2000; year < 3000; year++)
	{
        totalDays += daysInYear(year);
	}

	cout << "Total days: " << totalDays << endl;
}
