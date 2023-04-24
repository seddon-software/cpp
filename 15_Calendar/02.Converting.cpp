#include <iostream>
#include <chrono>
using namespace std;
namespace C = std::chrono;

void printDate(const C::year_month_day& date)
{
    cout << "day = " << static_cast<unsigned>(date.day())
         << ", month = " << static_cast<unsigned>(date.month())
         << ", year = " << static_cast<int>(date.year())
         << endl;
}

void addTwentyDays(C::year_month_day& date)
{
    // convert to and from sys_days and add 20 days
    auto sd = static_cast<C::sys_days>(date);
    sd += C::days(20);
    date = static_cast<C::sys_days>(sd);
    printDate(date);
}

int main()
{
    C::year_month_day date{C::month(5)/C::day(8)/2024};
    printDate(date);

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



