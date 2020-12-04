#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

//Since variadic templates are recursive, must have a base case
template <typename T>
T sum(T t) { return(t); }

//Compute sum of all parameters
template <typename T, typename ...P>		// P is a parameter pack
T sum(T t, P... p)
{
	if (sizeof...(p) > 0)			// if size of parameter pack non zero
	{
		t += sum(p...);			// recurse with one less parameter
	}
	return(t);
}


//Test it
int main()
{
	cout << sum(1) << endl;
	cout << sum(1, 2) << endl;
	cout << sum(1, 2, 3) << endl;
	cout << sum(1, 2, 3, 4) << endl;
	cout << sum(1, 2, 3, 4, 5) << endl;

	cout << endl;

	cout << sum(1.1) << endl;
	cout << sum(1.1, 2.2) << endl;
	cout << sum(1.1, 2.2, 3.3) << endl;

	cout << endl;
}
