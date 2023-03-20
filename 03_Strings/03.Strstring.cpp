/*
 *  It's often the case that you want to manipulate strings in memory before output and it would
 *  be very convenient if you could use the same syntax as used with cout.  The stringstream 
 *  class provides this facility.  We can now use the extraction operators >> and << as with
 *  cout and cin, thereby simplifying code.
 * 
 *  In this example we create a stringstream object and extract words from a test string (s)
 *  using:
 *              s >> word
 *  These words are then appended to a vector before outputting.
 */

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include <cstdio>
#include <cstring>

using namespace std;

// split a string into individual words

int main() 
{
    string str("The quick brown fox jumped over the lazy dog");
    string word;
    stringstream s(str);
    vector<string> words;
    
    while (s >> word) 
    {
        words.push_back(word);
    }

    for(auto word : words)
    {
        cout << word << ", " << flush;
    }
    cout << endl;
}

