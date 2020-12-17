////////////////////////////////////////////////////////////
//
//		Spirit-Parser
//
////////////////////////////////////////////////////////////

#include <boost/config/warning_disable.hpp>
#include <boost/spirit/include/qi.hpp>

#include <iostream>
#include <string>
#include <vector>
using namespace std;


namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;

template <typename Iterator>
bool parse_numbers(Iterator first, Iterator last)
{
	using qi::double_;
	using qi::phrase_parse;
	using ascii::space;

	bool r = phrase_parse(
		first,                          /*< start iterator >*/
		last,                           /*< end iterator >*/
		double_ >> *(',' >> double_),   /*< the parser >*/
		space                           /*< the skip-parser >*/
	);
	if (first != last) // fail if we did not get a full match
		return false;
	return r;
}

void check(const string& test)
{
    if (parse_numbers(test.begin(), test.end()))
    {
        cout << test << " Parses OK: " << endl;
    }
    else
    {
        cout << test << " FAILED" << endl;;
    }
}

int main()
{
	check("23.56 , 67.83, 49.5,   2.223");
	check("23.56 , 67.83, ???? 49.5,   2.223");
	check("23..56 , 67.83, 49.5,   2.223");

    return 0;
}
