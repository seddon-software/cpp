#include <iostream>
#include "boost/date_time/gregorian/gregorian.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"

int main() {
    using namespace boost::posix_time; /* put that in functions where you work with time (namespace) */

    ptime now = microsec_clock::local_time(); // current *LOCAL TIMEZONE* time/date

    std::cout << now.time_of_day().hours() << std::endl;
    // time_od_day gets the time of day in time "now"
    // hours extract as integer the hours part

    time_duration tod = now.time_of_day();

    std::cout
        << tod.hours() << ':'
        << tod.minutes() << ':'
        << tod.seconds()
        << std::endl;

    std::cout << tod << std::endl; // also works
}

