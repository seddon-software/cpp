/*
 *  When you want to perform arithmetic on dates you need to convert dates to sys_days using casts.  We
 *  have used "auto" instead of explicitly using sys_days in the code below.
 * 
 *  Once you have a sys_days object you can easily add 20 days to it:
 *                  sd += C::days(20);
 */

#include <iostream>
#include <chrono>
#include <format>

using namespace std;
namespace C = std::chrono;

void addTwentyDays(C::year_month_day& date)
{
    // convert to and from sys_days and add 20 days
    C::sys_days sd = static_cast<C::sys_days>(date);
    sd += C::days(20);
    date = static_cast<C::sys_days>(sd);
    cout << format("{}\n", date);
}

int main()
{
    C::year_month_day date{C::month(5)/C::day(8)/2024};
    cout << format("{}\n", date);

    // increment the date
    addTwentyDays(date);
    addTwentyDays(date);
    addTwentyDays(date);
    addTwentyDays(date);
    addTwentyDays(date);

    // calculate days since start of epoch 
    auto numberOfDays = C::local_days(date);
    auto days = numberOfDays.time_since_epoch().count();
    cout << "days since start of epoch: " << days << endl;
}



