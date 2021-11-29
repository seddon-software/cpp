////////////////////////////////////////////////////////////
//
//      Function Signatures
//
////////////////////////////////////////////////////////////


/*
 * We can have several functions with the same name as long as they 
 * have different signatures
 */

#include <iostream>
using namespace std;

void f(int a, int b, int c);
void f(int a, double b);

void f(int a, int b, int c)
{
	cout << "f(int,int,int)" << endl;
}

void f(int a, double b)
{
	cout << "f(int,double)" << endl;
}

int main()
{
    f(1, 2, 3);
    f(11, 12);		// second parameter gets converted to double
    f(11, 12.0);
}

