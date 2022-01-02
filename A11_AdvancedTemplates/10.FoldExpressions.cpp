#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

/*  Variadic template are frequently used with fold expressions.  In this example we use a fold 
 *  expression to compute the sum of a set of numbers.  The key part of this code is the return 
 *  expression in the sum template.  This is a fold expression: 
 * 		p + ...
 * 
 *  and it expanded by the compiler recursively.  Lets suppose for example that there are 5 parameters
 *  in our parameter pack, such that
 *		p === P1, P2, P3, P4, P5
 *
 *  then the above fold expression is expanded by the compiler as:
 *  	p + ... = P1 + (P2 + (P3 + (P4 + P5)))
 * 
 *  and since + is commutable this reduces to
 * 		p + ... = P1 + P2 + P3 + P4 + P5
 * 
 *  Other fold expressions are available and you can replace + with almost any valid  operator; examples
 *  to follow.
 */

//Compute sum of all parameters
template <typename ...P>
auto sum(P... p)
{
	return (p + ...);   // fold expression
}


//Test it
int main()
{
	// with int
	cout << sum(1) << endl;
	cout << sum(1, 2) << endl;
	cout << sum(1, 2, 3) << endl;
	cout << sum(1, 2, 3, 4) << endl;
	cout << sum(1, 2, 3, 4, 5) << endl;
	cout << endl;

    // with double
	cout << sum(1.1) << endl;
	cout << sum(1.1, 2.2) << endl;
	cout << sum(1.1, 2.2, 3.3) << endl;
	cout << endl;
}
