////////////////////////////////////////////////////////////
//
//      Narrowing
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <array>
#include <string>
#include <algorithm>

using namespace std;


int main()
{
	[[maybe_unused]] double d {42.0};   // no compiler warning
/*
 *  All of these initializers attempt to narrow and fail with a warning or error
 */

/*
	[[maybe_unused]]	int x1 {42.0};
	[[maybe_unused]]	int x2 = {42.1};
	[[maybe_unused]]	int x3 = {d};
*/
}

