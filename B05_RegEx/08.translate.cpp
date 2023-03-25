///////////////////////////////////////////////////////
//
//       translate
//
///////////////////////////////////////////////////////

#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <map>
#include <regex>

using namespace std;

/*
 *  Sometimes we need to replace abbreviations in text.  In this example we use regExs to iterate through
 *  some text replacing weekday abbreviations with full weekday names.  The abbreviations and replacements
 *  are stored in a map.  This map is used to generate a regEx that will perform the substitutions:
 *              fri|mon|thur|tue|wed
 * 
 *  To perform the substitutions we will need to know which abbreviation is to be substituted at each 
 *  stage.  We use a regex_token_iterator<string::iterator> with the flags {-1, 0} so that the iterator
 *  returns a succession of prefixes(-1), and matches(0).
 */

string generatePattern(const map<string, string>& map, const string& joiner)
{
	string result;

	for(auto& pair : map)
	{
		auto lastPair = *map.rbegin();
		result += get<0>(pair);
        if(pair != lastPair) result += "|";
	}
    cout << "RegEx: " << result << endl;
	return result;
}

int main()
{
	map<string, string> days = {
		{ "mon" , "Monday"    },
		{ "tue" , "Tuesday"   },
		{ "wed" , "Wednesday" },
	    { "thur" , "Thursday"  },
	    { "fri" , "Friday"    }
	};

	string text = "The course starts on mon,"
			      " continues on tue, wed and thur"
	              " and fri is the last day.";
	string pattern = generatePattern(days, "|");
	regex re(pattern);

	// {-1,0} => are the submatches.  
    // The iterator will point to {prefix(-1), match(0), prefix(-1), match(0), ...}
	regex_token_iterator<string::iterator> it(text.begin(), text.end(), re, {-1,0});
	regex_token_iterator<string::iterator> end; // default CTOR creates end of sequence

	int count = 0;

	while(it != end)
	{
		count++;
		if(count % 2 == 1)      // check if prefix or match
			cout << *it;
		else
			cout << days[*it];
		it++;
	}
	cout << endl;
}

