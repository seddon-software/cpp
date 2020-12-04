////////////////////////////////////////////////////////////
//
//		Traits
//
////////////////////////////////////////////////////////////


#include <iostream>
using namespace std;

////////////////////////////////////////
// the generic traits template
template <typename T>
struct isPointer
{
	static const bool value = false;
};

// partial specialization of the traits template for pointers
template <typename T>
struct isPointer<T*>
{
    static const bool value = true;
};
////////////////////////////////////////

template <bool b>
struct algorithm_selector {

    template <typename T>
    static void implementation(T& object)
    {
        // algorithm for non-pointer types
    }
};

template <>
struct algorithm_selector<true> {

    template <typename T>
    static void implementation(T& object)
    {
        // algorithm for pointer types
    }
};
////////////////////////////////////////


template <typename T>
void algorithm(T object)
{
    algorithm_selector<isPointer<T>::value>::implementation(object);
}

/////

class X {};

int main()
{
	X x;
	X* px = new X();

	algorithm(x);  // non-pointer
	algorithm(px); // pointer

	return 0;
}

