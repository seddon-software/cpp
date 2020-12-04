////////////////////////////////////////////////////////////
//
//		RegEx-SampleExpressions
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
	boost::regex pattern("(a.*)");
	boost::regex_match("This is a test expression", pattern);
    string str1("abc__(456)__123__(123)__cde");

    string s = "aaa bbb cc";
    boost::regex expr(".+");
    cout << "aaa" << boost::regex_search(s, expr) << std::endl;


    cout << endl;

    return 0;
}
