/*
 *  If you want to compute the end of a week, month or year you can use the special "last" object.
 *  Thus
 *              C::weekday_last lastSundayOfAnyMonth {C::Sunday[C::last]};
 * 
 *  creates an object defining the last Sunday of a yet to be specified month.  When this object is
 *  combined with a specic month and year it will compute the last Sunday in that month:
 *              C::year_month_day lastSundayDate{lastSundayOfAnyMonth/12/2023};
 */

#include <iostream>
#include <format>
#include <chrono>

using namespace std;
namespace C = std::chrono;

int main()
{
    /* 
     * 'weekday' allows you to pick a day by name (e.g. Sunday).  When 'Sunday' is combined with 'last' it 
     * will define the last Sunday in a given month or year
     */
    C::weekday_last lastSundayOfAnyMonth {C::Sunday[C::last]};

    /*
     * define the last Sunday in December 2023 using the 'year_month_day' constructor with a date defined
     * using the overloaded "/" operator.
     */
    C::year_month_day lastSundayDate{lastSundayOfAnyMonth/12/2023};
    cout << "last Sunday in Dec 2023: " << format("{}\n", lastSundayDate);
    int dayOfMonth = static_cast<unsigned>(lastSundayDate.day());
    cout << "day of month: " << format("{}\n", dayOfMonth);
}
