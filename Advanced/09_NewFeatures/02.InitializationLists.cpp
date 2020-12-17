#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// instance variables can be set to an initial value directly
// to save on duplication in constructors

class A {
public:
    A(int c) : c(c), d(0) {}
    A(int c, int d) : c(c), d(d) {}
    void print()
    {
    	cout << a << "," << b << "," << c << "," << d << endl;
    }
private:
    int a = 1;
    int b = 2;
    int c;
    int d;
};

// the above would be equivalent to

/*
class A {
public:
    A(int c) : c(c) : a(1), b(2), c(c) {}		// redundundant initialisers
    A(int c, int d) : a(1), b(2), c(c), d(d) {}
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


