//////////////////////////////////////////////////
//
//   Advanced pattern matching ...
//
//////////////////////////////////////////////////

/*
 *  When we work with regular expressions we can "match"or "search".
 *  matches have to match the entire string
 *  searches match on substrings
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
    for (smatch::iterator it = matcher.begin(); it != matcher.end(); ++it) {
        cout << *it << ", ";
    }
    cout << endl;

    // search
    cout << "Searches are:" << endl;
    for (smatch::iterator it = searcher.begin(); it != searcher.end(); ++it) {
        cout << *it << ", ";
    }
    cout << endl;
}
