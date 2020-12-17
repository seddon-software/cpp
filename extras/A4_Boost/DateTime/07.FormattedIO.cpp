#include <boost/date_time/gregorian/gregorian.hpp>
#include <iostream>
using namespace std;

#include <boost/date_time/gregorian/gregorian.hpp>
#include <iostream>
#include <locale>

int main()
{
	boost::gregorian::date d(2012, 6, 13);
	boost::gregorian::date_facet *df = new boost::gregorian::date_facet("%A, %d %B %Y");
	cout.imbue(locale(cout.getloc(), df));
	cout << d << endl;
}
