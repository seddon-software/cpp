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

string keys(const map<string, string>& map, const string& joiner)
{
	string result;

	for(auto& pair : map)
	{
		auto lastPair = *map.rbegin();
		result += get<0>(pair);
        if(pair != lastPair) result += "|";
	}
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
	string pattern = keys(days, "|");
	regex ex(pattern);

	// {-1,0} => iterator will point to {prefix, match, prefix, match, ...}
	regex_token_iterator<string::iterator> it(text.begin(), text.end(), ex, {-1,0});
	regex_token_iterator<string::iterator> end; // default CTOR creates end of sequence

	int count = 0;

	while(it != end)
	{
		count++;
		if(count % 2 == 1)
			cout << *it;
		else
			cout << days[*it];
		it++;
	}
	cout << endl;
}

