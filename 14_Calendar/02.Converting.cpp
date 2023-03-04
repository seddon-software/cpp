#include <iostream>
#include <chrono>
using namespace std;
namespace C = std::chrono;

int main()
{
    C::year_month_day date{C::month(5)/C::day(8)/2024};
    auto numberOfDays = C::local_days(date);
    auto days = numberOfDays.time_since_epoch().count();
    cout << "days since start of epoch: " << days << endl;
}



