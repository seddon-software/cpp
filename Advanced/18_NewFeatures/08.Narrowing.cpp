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
	__attribute__((unused)) double d {42.0};
/*
 *  All of these initializers attempt to narrow and fail to compile
 */

//	__attribute__((unused))
//	int x1 {42.0};
//	__attribute__((unused))
//	int x2 = {42.1};
//	__attribute__((unused))
//	int x3 = {d};

	// but this is OK
	__attribute__((unused)) float h = {42.7};
}

