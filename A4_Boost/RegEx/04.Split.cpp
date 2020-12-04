////////////////////////////////////////////////////////////
//
//		RegEx
//
////////////////////////////////////////////////////////////

#include <string>
#include <iostream>
#include <iterator>
#include <boost/xpressive/xpressive.hpp>

using namespace boost::xpressive;
using namespace std;

int main()
{
	string input("The quick brown fox jumped over the lazy dog");
	sregex re = +_w;                      // find a word
	
	// iterate over all the words in the input
	sregex_token_iterator begin(input.begin(), input.end(), re);
	sregex_token_iterator end;
	
	// write all the words to std::cout
	ostream_iterator<string> out_iter(cout, "\n");
	copy(begin, end, out_iter);
}

