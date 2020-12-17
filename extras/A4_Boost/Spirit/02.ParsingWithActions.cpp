////////////////////////////////////////////////////////////
//
//		Spirit-Parser
//
////////////////////////////////////////////////////////////

#include <boost/config/warning_disable.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix_core.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <boost/spirit/include/phoenix_stl.hpp>

#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;
namespace phoenix = boost::phoenix;

template <typename Iterator>
bool parse_numbers(Iterator first, Iterator last, std::vector<double>& v)
{
	using qi::double_;
	using qi::phrase_parse;
	using qi::_1;
	using ascii::space;
	using phoenix::push_back;
	using phoenix::ref;

	bool r = phrase_parse(first, last,

		//  Begin grammar
		(
			double_[push_back(ref(v), _1)]
				>> *(',' >> double_[push_back(ref(v), _1)])
		)
		,
		//  End grammar

		space);

	if (first != last) // fail if we did not get a full match
		return false;
	return r;
}

#define cout cout << " "	// for CDT bug
void check(const string& test)
{
	vector<double> v;
    if (parse_numbers(test.begin(), test.end(), v))
    {
        cout << test << " Parses OK: " << endl;
    }
    else
    {
        cout << test << " FAILED" << endl;;
    }
    for(unsigned i = 0; i < v.size(); i++)
    {
    	cout << i << ": " << v[i] << endl;
    }
}

int main()
{
	check("23.56 , 67.83, 49.5,   2.223");
	check("23.56 , 67.83, ???? 49.5,   2.223");
	check("23..56 , 67.83, 49.5,   2.223");

    return 0;
}


