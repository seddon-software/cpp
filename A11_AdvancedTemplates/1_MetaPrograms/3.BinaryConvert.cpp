////////////////////////////////////////////////////////////
//
//      Factorials
//
////////////////////////////////////////////////////////////


#include <iostream>
using namespace std;

template<unsigned int N>
class Binary
{
public:
	static unsigned const value = Binary<N/10>::value << 1 | N % 10;
};

template<>
class Binary<0>
{
public:
	static unsigned const value = 0;
};

// e.g. Binary<1010101>
// ====================
//
// Binary<1010101> = Binary<101010>*2 | 1
// Binary<101010> = Binary<10101>*2 | 0
// Binary<10101> = Binary<1010>*2 | 1
// Binary<1010> = Binary<101>*2 | 0
// Binary<101> = Binary<10>*2 | 1
// Binary<10> = Binary<1>*2 | 0
// Binary<1> = Binary<0>*2 | 1
// Binary<0> = 0
// Binary<1> = 0 | 1 = 1
// Binary<10> = 1*2 | 0 = 2
// Binary<101> = 2*2 | 1 = 5
// Binary<1010> = 5*2 | 0 = 10
// Binary<10101> = 10*2 | 1 = 21
// Binary<101010> = 21*2 | 0 = 42
// Binary<1010101> = 42*2 | 1 = 85

int main()
{	
	[[ maybe_unused ]] unsigned int x[8] =
	{
		Binary<1010101>::value, // 64 + 16 + 4 + 1 = 85
		Binary<1010110>::value,
		Binary<1010111>::value,
		Binary<1011000>::value,
		Binary<1011001>::value,
		Binary<1011010>::value,
		Binary<1011011>::value,
		Binary<1011100>::value,
	};

	for(auto b : x)
	{
		cout << b << ", ";
	}
	cout << endl;
}

