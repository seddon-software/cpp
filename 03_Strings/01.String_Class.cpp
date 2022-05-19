#include <iostream>
#include <string>
/*
 *  C++ introduced a templated String class to replace C's character arrays.  It is templated to allow for
 *  multiple String types, like ASCII strings and Unicode.  To simplify using ASCII strings the template defines
 *  the following typedef:
 *              typedef basic_string<char>    string;   
 * 
 *  This typedef is commonly used in most code.
 * 
 *  The string class has numerous methods, some of which we use below:
 */


using namespace std;

int main()
{
    // templated version
    basic_string<char> s1 = "Supercalifragilistic";

    // typedef version
    string s2 = "expialidocious";
    
    // adding strings
    string s;
    s = s1 + s2;
    cout << s << endl;
    
    // copying strings using =
    string copy;
    copy = s;

    // checking the start and end of Strings 
    string super("Super");
    string docious("docious");
    if(s.starts_with(super)) cout << s << " starts with " << super << endl;
    if(s.ends_with(docious)) cout << s << " ends with " << docious << endl;

    // popping characters from the end of a string
    while(!s.empty())
    {
        s.pop_back();
        cout << s << endl;
    }
}
