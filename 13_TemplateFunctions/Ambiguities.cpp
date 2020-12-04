////////////////////////////////////////////////////////////
//
//		Ambiguities
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using namespace std;


template <typename L, typename R, typename RET>
RET Max(L a, R b)
{
	if (a > b)
		return a;
	else
		return b;
}


/////

int main()
{
	//double x = Max(5.1, 8);			// ambiguous
	//double y = Max(8, 5.1);			// ambiguous
	 
	return 0;
}

