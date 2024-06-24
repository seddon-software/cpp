#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

#define GAPS 4

vector<string> monthNames { "", 
                        "January", "February", "March",
                        "April", "May", "June",
                        "July", "August", "September",
                        "October", "November", "December" };

void PrintMonth(int theMonth, int theYear)
{
    // print headings
    string monthName = monthNames[theMonth];
    cout << endl << monthName << endl;
    cout << string(monthName.size(), '=') << endl;
    cout << " Mon Tue Wed Thu Fri Sat Sun" << endl;

    // calculate and print leading spaces
    weekday_last lastSundayOfAMonth {Sunday[last]};
    year_month_day lastSundayDate{lastSundayOfAMonth/theMonth/theYear};
    year_month_day lastDayInMonthDate{last/theMonth/theYear};
    int lastSunday = static_cast<unsigned>(lastSundayDate.day());
    int numberOfDaysInMonth = static_cast<unsigned>(lastDayInMonthDate.day());
    int spaces = (35 - lastSunday) % 7;
    if(spaces > 0) cout << string(GAPS * spaces, ' ');

    // print out each day
    for(int i = 1; i <= numberOfDaysInMonth; i++)
    {
        cout << setw(GAPS) << i;
        // newline after Sunday
        if((i + spaces)%7 == 0) cout << endl;
    }
    cout << endl;
}

int main()
{   
    int theYear = 2023;
    cout << "CALENDAR for " << theYear << endl << endl;
    
    for(unsigned month = 1; month <= 12; month++)
    {
        PrintMonth(month, 2023);
    }
}


