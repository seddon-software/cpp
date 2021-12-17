////////////////////////////////////////////////////////////
//
//		Perfect Forwarding
//
////////////////////////////////////////////////////////////

/*
 * The problem we are trying to solve with perfect forwarding is: How can we write a function template
 * that forwards calls to another function template without changing l-vaues into r-values.
 *
 * It turns out this is very difficult with using the new r-value references.
 * We'll make several attempts without r-value references to see why this is difficult
 * and then show the r-value reference solution.
 */

#include <string>
#include <iostream>
using namespace std;

int main()
{
    string s =
     "The problem we are trying to solve with perfect forwarding is: How can we write a function template \n"
     " that forwards calls to another function template without changing l-vaues into r-values. \n"
     "\n"
     " It turns out this is very difficult with using the new r-value references. \n"
     " We'll make several attempts without r-value references to see why this is difficult \n"
     " and then show the r-value reference solution. \n";
	cout << s << endl;
	cout.flush();
}
