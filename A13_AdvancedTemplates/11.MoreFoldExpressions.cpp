#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

/*
 *  In general there are 4 different types of fold expressions.  They work from right to left or 
 *  vice versa and optionally can include an initial value (INIT).  Symbolically the expansions 
 *  are as follows:
 *
 *      Unary right fold:  (E op ...)         expands to (E<1> op (E<2> op (E<3> op E<4>))) etc
 *      Unary left fold:   (... op E)         expands to (((E<1> op E<2>) op E<3>) op E<4>) etc
 *      Binary right fold: (E op ... op INIT) expands to (E<1> op (E<2> op (E<3> op (E<4> op INIT)))) etc
 *      Binary left fold:  (INIT op ... op E) expands to ((((INIT op E<1>) op E<2>) op E<3>) op E<4>) etc
 *
 *  where op represents almost any operator (see cppreference.com).  We are using - as op in the 
 *  examples below.
 */


template<typename... P>
auto unaryRightFold(P... p) 
{
    return (p - ...);
}

template<typename... P>
auto unaryLeftFold(P... p) 
{
    return (... - p);
}

template<typename... P, typename I>
auto binaryRightFold(I i, P... p) 
{
    return (p - ... - i);
}

template<typename... P, typename I>
auto binaryLeftFold(I i, P... p) 
{
    return (i - ... - p);
}

int main() 
{
    cout << unaryRightFold(1, 2, 3, 4) << endl;
    // (1 - (2 - (3 - 4))) = 1 - 2 + 3 - 4 = -2
	
	cout << unaryLeftFold(1, 2, 3, 4) << endl;
    // (((1 - 2) - 3) - 4) = 1 - 2 - 3 - 4 = -8
	
    cout << binaryRightFold(100, 1, 2, 3, 4) << endl; 
    // (1 - (2 - (3 - (4 - 100)))) = 1 - 2 + 3 - 4 + 100 = 98
	
    cout << binaryLeftFold(100, 1, 2, 3, 4) << endl;  
    // ((((100 - 1) - 2) - 3) - 4) = 100 - 1 - 2 - 3 - 4 = 90 
}
