////////////////////////////////////////////////////////////
//
//      Factorials
//
////////////////////////////////////////////////////////////

/* 
 *  Meta programs were discovered by accident by looking at some compiler error messages.  This led to
 *  formal programs that performed algorithms at compile time.  These prorams are called meta-programs
 *  and led to the deveopment of the traits library.  The traits library is a the heart of the new C++20
 *  concepts.
 *  
 *  These programs are of little practical use, but historically important because of their connection 
 *  to traits and concepts.
 * 
 *  Here we look at one of the simplest meta-programs - calculating Factorials.  Note the use 
 *  of enums - meta-programs are compile time artifacts. 
 *
 */

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

