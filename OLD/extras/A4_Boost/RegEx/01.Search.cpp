////////////////////////////////////////////////////////////
//
//		RegEx
//
////////////////////////////////////////////////////////////

#include <string>
#include <iostream>
#include <iterator>
#include <boost/regex/v4/regex.hpp>
//#include <boost/algorithm/string/regex.hpp>

using namespace std;
using namespace boost;

int main()
{  
	string text1 = "This line contains the number 8.73 and 4.67";
	string text2 = "This line does not contains any numbers";
	boost::regex pattern("\\d+\\.\\d+");
	bool match;

	match = boost::regex_search(text1, pattern);
	if(match)
	    cout << "Pattern found in text1" << endl;
	else
	    cout << "Pattern NOT found in text1" << endl;

	match = boost::regex_search(text2, pattern);
	if(match)
	    cout << "Pattern found in text2" << endl;
	else
	    cout << "Pattern NOT found in text2" << endl;

    return 0;
}

