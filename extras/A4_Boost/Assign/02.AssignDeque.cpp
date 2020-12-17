////////////////////////////////////////////////////////////
//
//		Deque
//
////////////////////////////////////////////////////////////

#include <boost/assign/list_inserter.hpp> // for 'insert()'
#include <boost/assert.hpp> 
#include <iostream>
#include <string>
#include <algorithm>
#include <deque>
using namespace std;
using namespace boost::assign; // bring 'insert()' into scope
 
void Print(const pair<string,string>& mypair)
{
	cout << mypair.first << ", " << mypair.second << endl;
}

int main()
{
	deque<pair<string, string> > deq;
	push_front(deq)( "john", "07863215")( "bob", "07961446")( "zoe", "07856123");

	for_each(deq.begin(), deq.end(), Print);
	return 0;
}
