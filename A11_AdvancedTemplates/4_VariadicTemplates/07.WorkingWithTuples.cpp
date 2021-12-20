#include <iostream>
#include <tuple>
#include <stdexcept>
#include <string>
using namespace std;

// generic template
template <typename T>
void f(T t) 
{ 
	cout << t << endl;
}

// specialization
template <typename T, typename ...P>		// P is a parameter pack
void f(T t, P... p)
{
	if (sizeof...(p) > 0)	// if size of parameter pack non zero
	{
		cout << t << ", ";
		f(p...);			// recurse with one less parameter
	}
}


int main()
{
	f(3.14159, "Red", "Cyan"s);
	f(100, 200, "Yellow", "Blue", "January"s);
}
