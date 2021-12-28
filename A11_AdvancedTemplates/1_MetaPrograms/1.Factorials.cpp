////////////////////////////////////////////////////////////
//
//      Factorials
//
////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;


template<int N>
class Factorial {
public:
    enum { value = N * Factorial<N-1>::value };
};

template<>
class Factorial<1> 
{
public:
    enum { value = 1 };
};


int main()
{	
	int x;
	x = Factorial<6>::value;
    cout << x << endl;
}

