////////////////////////////////////////////////////////////
//
//		RegEx
//
////////////////////////////////////////////////////////////

#include <cstring>
#include <string>
#include <iostream>
#include <iterator>
#include <exception>
#include <boost/regex/v4/regex.hpp>


using namespace std;
using namespace boost;

int main()
{
    string pattern;
    pattern += "^ 		 #? start of line\n";
    pattern += "(.*?)    #? 0 or more characters\n";
    pattern += "         #? non greedy\n";
    pattern += "(\\d+)   #? 1 or more digits\n";
    pattern += "(.*)     #? 0 or more characters\n";
    pattern += "$        #? end of line\n";

	regex reg(pattern.c_str(), regex::mod_x);
	string test = "AAAA1111BBBB2222CCCC3333DDDD";
	boost::match_results<string::const_iterator> matcher;
	boost::match_flag_type flags = boost::match_default;

	regex_search(test, matcher, reg, flags);

	for(unsigned i = 0; i < matcher.size(); i++)
	{
		cout << " " << i << ":" << matcher[i] << endl;
	}

    return 0;
}

