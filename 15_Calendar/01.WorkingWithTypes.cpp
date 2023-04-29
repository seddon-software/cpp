/*
 *  The chrono library is used to manipulate dates.  Note that it helps to use <format> in connection
 *  with this library otherwise it is difficult to print dates (you have to use casts which is messy).
 *  The <format> library is only available in g++13.1.0 or later.
 * 
 *  Typically you can create basic types like day, month and year and this can be combined in various ways
 *  as shown below.
 */

#include <iostream>
#include <chrono>
#include <format>

using namespace std;
namespace C = std::chrono;

int main()
{
    C::day d{8};
    C::month m{5};
    C::year y{2024};
    cout << format("d = {}\n", d);
    cout << format("m = {}\n", m);
    cout << format("y = {}\n", y);

    // year_month objects can be formed in 2 ways:
    C::year_month my{y/m};      // operator/(year, month)
    C::year_month yi{y/8};      // operator/(year, int)
    cout << format("my = {}\n", my);
    cout << format("yi = {}\n", yi);

    // month_day objects in 5 ways
    C::month_day md{m/d};       // operator/(month, day)
    C::month_day mi{m/5};       // operator/(month, int)
    C::month_day id{m/d};       // operator/(int, day)
    C::month_day dm{d/m};       // operator/(day, month)
    C::month_day di{d/8};       // operator/(day, int)
    cout << format("md = {}\n", md);
    cout << format("mi = {}\n", mi);
    cout << format("id = {}\n", id);
    cout << format("dm = {}\n", dm);
    cout << format("di = {}\n", di);
    
    // year_month_day objects can be formed in various ways, e.g.:
    C:: year_month_day ymd1{my/d};      // CTOR(operator/(year_month, day))
    C:: year_month_day ymd2{my/8};     // CTOR(operator/(year_month, int))
    C:: year_month_day ymd3{2024/md};  // CTOR(operator/(int, month_day))
    C:: year_month_day ymd4{y/md};     // CTOR(operator/(year, month_day))
    cout << format("ymd1 = {}\n", ymd1);
    cout << format("ymd2 = {}\n", ymd2);
    cout << format("ymd3 = {}\n", ymd3);
    cout << format("ymd4 = {}\n", ymd4);

    // year_month_day objects constructed using two operator/() overloads
    C::year_month_day date1{y/m/d};
    C::year_month_day date2{d/m/y};
    C::year_month_day date3{y/5/d};
    C::year_month_day date4{m/d/y};
    cout << format("date1 = {}\n", date1);
    cout << format("date2 = {}\n", date2);
    cout << format("date3 = {}\n", date3);
    cout << format("date4 = {}\n", date4);

    // alternatively, use static_cast to extract components
    int day = static_cast<unsigned>(date1.day());
    int month = static_cast<unsigned>(date1.month());
    int year = static_cast<int>(date1.year());

    // print out components
    cout << "day, month, year: " << day << ", " << month << ", " << year << endl; 
}
