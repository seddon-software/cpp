////////////////////////////////////////////////////////////
//
//      BubbleSort
//
////////////////////////////////////////////////////////////

/*  The bubble sort meta program is even more complicated than previous examples.  A detailed discussion 
 *  of this meta-program can be found at:
 *      https://www.cs.rpi.edu/~musser/design/blitz/meta-art.html
 *
 *  Note: in practice you would use a run time version of this program, rather than use this meta-program.
 */

#include <iostream>
#include <vector>
using namespace std;

// forward declarations
template<int I, int J> class IntBubbleSortLoop;
template<int I, int J> struct IntSwap; 


////////////////////////////////////////////////////////////
//	IntBubbleSort

template<int N>
struct IntBubbleSort 
{
    static inline void sort(int* data)
    {
        IntBubbleSortLoop<N-1,0>::loop(data);
        IntBubbleSort<N-1>::sort(data);
    }
};

template<>
struct IntBubbleSort<1> {
    static inline void sort(int* data)
    { }
};

////////////////////////////////////////////////////////////
//	IntBubbleSortLoop

template<int I, int J>
class IntBubbleSortLoop 
{
private:
    enum { go = (J <= I-2) };
public:
    static inline void loop(int* data)
    {
        IntSwap<J,J+1>::compareAndSwap(data);
        IntBubbleSortLoop<go ? I : 0, go ? (J+1) : 0>::loop(data);
    }
};

template<>
struct IntBubbleSortLoop<0,0> {
    static inline void loop(int*)
    { }
};

////////////////////////////////////////////////////////////
//	IntSwap

template<int I, int J>
struct IntSwap 
{
    static inline void compareAndSwap(int* data)
    {
        if (data[I] > data[J])
            swap(data[I], data[J]);
    }
};

////////////////////////////////////////////////////////////
//	swap

inline void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

/////

int main()
{	
	int a[] = { 21, 2, 33, 44, 25 };
	IntBubbleSort<5>::sort(a);
	
	for(auto b : a)
	{
		cout << b << ", ";
	}
	cout << endl;
}

