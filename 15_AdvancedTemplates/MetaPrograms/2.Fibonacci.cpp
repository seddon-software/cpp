////////////////////////////////////////////////////////////
//
//      Factorials
//
////////////////////////////////////////////////////////////


#include <iostream>
using namespace std;

template<int N>
class Fibonacci {
public:
    enum { value = Fibonacci<N-1>::value + Fibonacci<N-2>::value };
};

template<>
class Fibonacci<2> 
{
public:
    enum { value = 1 };
};
template<>

class Fibonacci<1> 
{
public:
    enum { value = 1 };
};


int main()
{	
	int x[8];
	x[0] = Fibonacci<1>::value;
	x[1] = Fibonacci<2>::value;
	x[2] = Fibonacci<3>::value;
	x[3] = Fibonacci<4>::value;
	x[4] = Fibonacci<5>::value;
	x[5] = Fibonacci<6>::value;
	x[6] = Fibonacci<7>::value;
	x[7] = Fibonacci<8>::value;

    return 0;
}

