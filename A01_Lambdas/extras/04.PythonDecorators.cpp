#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <ctime>
#include <functional>
#include <chrono>
using namespace std;

// decorators á la Python

auto us =
    [] (std::function<string()> fn)
	{
		auto decorate = [fn]()
		{
			string date = fn();
			// swap day and month
			string day = date.substr(0, 2);
			string month = date.substr(3, 2);
			string year = date.substr(6, 4);
			return month + "/" + day + "/" + year;
		};
		return decorate;
	};

auto bold =
    [] (std::function<string()> fn)
	{
		auto decorate = [fn]()
		{
			// surround with bold tags before calling original function
			return "<b>" + fn() + "</b>";
		};
		return decorate;
	};

auto getDate()
{
	auto now = chrono::system_clock::now();
	time_t now_c = chrono::system_clock::to_time_t(now);
	struct tm t = *std::localtime(&now_c);
	stringstream ss;
	ss << setfill('0') << setw(2) << t.tm_mday << "/"
	   << setfill('0') << setw(2) << 1 + t.tm_mon  << "/"
	   << 1900 + t.tm_year;
	return ss.str();
}

int main()
{
	cout << "date:           " << getDate()           << endl;
	cout << "bold date:      " << bold(getDate)()     << endl;
	cout << "US date:        " << us(getDate)()       << endl;
	cout << "bold US date(): " << bold(us(getDate))() << endl;
}

