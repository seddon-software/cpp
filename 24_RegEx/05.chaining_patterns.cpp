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

using namespace std;

int main()
{
	string text("AB12CD34EF56GH");
	regex ex("(\\d+)");

	std::cout << "chaining:";
	std::regex_token_iterator<std::string::iterator> it(text.begin(), text.end(), ex, -1);
	std::regex_token_iterator<std::string::iterator> end; // default CTOR creates end of sequence
	while(it != end)
	{
		cout << " [" << *it++ << "]";
	}
	cout << endl;
}



