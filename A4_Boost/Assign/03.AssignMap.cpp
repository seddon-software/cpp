////////////////////////////////////////////////////////////
//
//		Complex List
//
////////////////////////////////////////////////////////////

#include <boost/assign/list_inserter.hpp> // for 'insert()'
#include <boost/assert.hpp> 
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
using namespace boost::assign; // bring 'insert()' into scope
 
void Print(const pair<string,int>& mypair)
{
	cout << mypair.first << "," << mypair.second << endl;
}

int main()
{
    map<string,int> months;  
    insert( months )
        ( "january",   31 )( "february", 28 )
        ( "march",     31 )( "april",    30 )
        ( "may",       31 )( "june",     30 )
        ( "july",      31 )( "august",   31 )
        ( "september", 30 )( "october",  31 )
        ( "november",  30 )( "december", 31 );

    BOOST_ASSERT( months.size() == 12 );
    BOOST_ASSERT( months["january"] == 31 );

	for_each(months.begin(), months.end(), Print);
	return 0;
}
