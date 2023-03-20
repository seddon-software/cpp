/*
 *  In C, all arguments to functions are passed by copy.  This makes it difficult to swap two variables (its 
 *  easy to swap copies).  To overcome this limitation, C uses pointers, but C++ has an alternative strategy.
 * 
 *  C++ introduces the idea of references.  References are used to pass aliases of variables to a function
 *  instead of copies.  Because references act as aliases, they can be used to effectively extend the 
 *  scope of a variable.  In the declaration of Swap:
 *              void Swap(int& a, int& b)
 * 
 *  a and b are references to the x and y defined in the main program.  So although x and y are not in scope
 *  in Swap(), their aliases a and b are.  Any changes to a and b will result in x and y being changed.  
 *  This is called call by reference.  If you don't use references (i.e. use copies) it is called pass by value.
 *  Both call by reference and call by value are available in C++.
 * 
 *  Notice you can use C's pointer version of Swap and the C++ reference version of Swap in the same program, 
 *  because the compiler can easily differentiate the two functions on account of
 *  the different parameters passed in the calls:
 *                  Swap(&x, &y);            // pass (int*, int*)
 *                  Swap(x, y);              // pass (int&, int&)
 */


#include <iostream>
using namespace std;

// the old C way of passing original values
void Swap(int* px, int* py)
{
    int temp;
    temp = *px;
    *px = *py;
    *py = temp;
}

// C++ preferred method of passing original values
void Swap(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}


int main()
{
    int x = 100;
    int y = 200;

    // swap the C way using pointers
    Swap(&x, &y);            // pass (int*, int*)
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    // swap the C++ way using references
    Swap(x, y);              // pass (int&, int&)
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
}
