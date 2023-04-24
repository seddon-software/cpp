#include <iostream>
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
    int lastSundayInDec2023 = static_cast<unsigned>(lastSundayDate.day());
    cout << "last Sunday in Dec 2023: " << lastSundayInDec2023 << endl;
}



