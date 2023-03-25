//////////////////////////////////////////////////
//
//   Advanced pattern matching ...
//
//////////////////////////////////////////////////

#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <regex>

/*
 *  In this example we iterate through a test string, matching successive text between a given regular 
 *  expression (re).  The regular expression effectively becomes the delimeter between results.
 */

using namespace std;

int main()
{
	string text("AB1CD34EF56GH");
	regex re("(\\d+)");     // one or more digits as a delimeter

	std::cout << "iterating:";
	std::regex_token_iterator<std::string::iterator> it(text.begin(), text.end(), re, -1);
	std::regex_token_iterator<std::string::iterator> end; // default CTOR creates end of sequence
    while(it != end)
	{
        // this will match up to the next occurance of the pattern ex
		cout << " [" << *it << "]" << flush;
		it++;       // move to next match
	}
	cout << endl;
}



