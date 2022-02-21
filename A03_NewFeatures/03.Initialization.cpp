#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*  
 *  When a class has several attributes, its constructors may have duplicate initializations of these 
 *  attributes.  With C++11 it is now possible to move commmon initialization to the instance variables
 *  themselves, instead of using the constructor's initialization list.
 */

class A 
{
public:
    A(int c) : c(c), d(0) {}
    A(int c, int d) : c(c), d(d) {}
    void print()
    {
    	cout << a << "," << b << "," << c << "," << d << endl;
    }
private:
    int a = 1;   // instead of initializing in CTOR
    int b = 2;   // instead of initializing in CTOR
    int c;
    int d;
};

// the above would be equivalent to

/*
class A {
public:
    A(int c) : c(c) : a(1), b(2), c(c) {}		
    A(int c, int d) : a(1), b(2), c(c), d(d) {} // duplicate initialisers
private:
    int a;
    int b;
    int c;
    int d;
};
*/


int main()
{
	A a1(10);
	A a2{33,44};
	a1.print();
	a2.print();
}


