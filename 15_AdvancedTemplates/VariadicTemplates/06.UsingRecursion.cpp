#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

//Compute sum of all parameters
template <typename ...P>
auto sum(P... p)
{
	return (p + ...);		//
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
