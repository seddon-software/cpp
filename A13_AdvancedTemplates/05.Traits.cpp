////////////////////////////////////////////////////////////
//
//		Traits
//
////////////////////////////////////////////////////////////


#include <iostream>
using namespace std;

/*
 *  Traits are used to define compile time constraints.  These traits 
 *  can be utilised by an algorithm to determine policy (i.e. select 
 *  different versions of an algorithm). 
 *
 *  In this example we design our own trait to check if an entity is 
 *  a pointer.  This will show in principle how traits from the standard 
 *  library work.  In practice we would of course use the traits library 
 *  defined in the std namespace.
 * 
 *  Traits work by specialization of a generic template, in our case,
 *  for pointer types.
 */

////////////////////////////////////////
// define the generic traits template
template <typename T>
struct isPointer
{
	static const bool value = false;
};

// partial specialization of the traits template for pointers (isPointer::value = true for pointers)
// 
template <typename T>
struct isPointer<T*>
{
    static const bool value = true;  // false otherwise (see generic template)
};
////////////////////////////////////////

// now define a new template that has a policy applied
// the generic policy template is parameterized on the bool B
template <bool B>
struct algorithm_selector {

    template <typename T>
    static void implementation(T& object)
    {
        std::cout << "algorithm for non-pointer types" << std::endl;
    }
};

// the full specialization policy for B==true (if B==false the generic template will be chosen) 
template <>
struct algorithm_selector<true> {

    template <typename T>
    static void implementation(T& object)
    {
        std::cout << "algorithm for pointer types" << std::endl;
    }
};
////////////////////////////////////////

// now define the algorithm that depends on the algorithm_selector template
template <typename T>
void algorithm(T object)
{
    algorithm_selector<isPointer<T>::value>::implementation(object);
    // with T* (pointer type) the above evaluates to
    // algorithm_selector<isPointer<T*>::value>::implementation(object);
    // algorithm_selector<true>::implementation(object);

    // with T (not a pointer type) the above evaluates to
    // algorithm_selector<isPointer<T>::value>::implementation(object);
    // algorithm_selector<false>::implementation(object);
}

/////

class X {};  // class for testing

int main()
{
	X x;
	X* px = new X();

	algorithm(x);  // chooses non-pointer version
	algorithm(px); // chooses the pointer version
}

