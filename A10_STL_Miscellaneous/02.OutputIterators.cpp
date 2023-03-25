#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

/*
 *  The ostream_iterator is often used to produce output in conjunction with the copy algorithm.
 *  The ostream_iterator is parameterized on the type of the collection and the template is 
 *  essentially defined as:
 *          template <typename InputIterator, typename OutputIterator>
 *          copy (InputIterator first, InputIterator last, OutputIterator result);
 */

int main( )
{
    // output collection separated with commas 
    vector<int> v = {2,3,5,7,11,13,17,19};
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, ","));
    cout << endl;

    // output collection separated with new lines
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, "\n"));
    cout << endl;

    // output collection (individual characters) separated with hyphens 
    string s( "Supercalifragilisticexpialidocious");
    copy(s.begin(), s.end(), ostream_iterator<char>(cout, "-"));
    cout << endl;
}
