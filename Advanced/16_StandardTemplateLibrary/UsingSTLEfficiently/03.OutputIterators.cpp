#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

int main( )
{
   vector<int> v = {2,3,5,7,11,13,17,19};
   copy(v.begin(), v.end(), ostream_iterator<int>(cout, ","));
   cout << endl;

   copy(v.begin(), v.end(), ostream_iterator<int>(cout, "\n"));
   cout << endl;

   string s( "Supercalifragilisticexpialidocious");
   copy(s.begin(), s.end(), ostream_iterator<char>(cout, "-"));
   cout << endl;
}
