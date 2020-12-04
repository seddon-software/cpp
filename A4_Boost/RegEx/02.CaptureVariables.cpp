////////////////////////////////////////////////////////////
//
//		RegEx
//
////////////////////////////////////////////////////////////

#include <cstring>
#include <string>
#include <iostream>
#include <iterator>
#include <boost/regex/v4/regex.hpp>


using namespace std;
using namespace boost;

int main()
{
	string test = "---111122223333333333334444555566667777---";
	boost::match_results<string::const_iterator> results;
	boost::regex pattern("2+(3+)4+(5+)6+");
	boost::match_flag_type flags = boost::match_default;

	regex_search(test, results, pattern, flags);

	for(unsigned i = 0; i < results.size(); i++)
	{
		cout << " " << i << ":" << results[i] << endl;
	}

    return 0;
}

