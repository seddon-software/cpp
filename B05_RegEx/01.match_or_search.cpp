//////////////////////////////////////////////////
//
//   Advanced pattern matching ...
//
//////////////////////////////////////////////////

/*
 *  When we work with regular expressions we can "match"or "search".  The difference is that:
 *      matches have to match the entire string
 *      searches match on substrings
 * 
 *  Note that in this example we are looking for the pattern "ABC" which is a substring of s.  Therefore
 *  the matcher will fail to find any matches (works with the whole string, not substrings), but the
 *  searcher will succeed.
 * 
 *  The RegEx used has one set of capture parentheses; searcher returns 2 results - the first result is 
 *  the entire match and the second result (which ends up the same) is the first parenthesized match.
 */

#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <regex>

using namespace std;

int main()
{
    string s("-------ABC------------");
    regex re("(ABC)");
    match_results<string::const_iterator> matcher;
    match_results<string::const_iterator> searcher;

    regex_match(s, matcher, re);
    regex_search(s, searcher, re);

    // match
    cout << "Matches are:" << endl;
    for (size_t i = 0; i < matcher.size(); ++i) 
        cout << i << ": " << matcher[i] << endl;

    // search
    cout << "Searches are:" << endl;
    for (size_t i = 0; i < searcher.size(); ++i) 
        cout << i << ": " << searcher[i] << endl;
}
