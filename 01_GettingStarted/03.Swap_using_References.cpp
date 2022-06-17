#include <iostream>

/*
 *  In C all arguments to functions are passed by copy.  This makes it difficult to swap two vaiables (its easy to swap copies).  To overcome this limitation, C uses pointers.
 *  C++ introduces the idea of references.  Because references act as aliases they can be used to effectively extend the scope of a variable.  In the declaration of Swap:
 *              void Swap(int& a, int& b)
 * 
 *  a and b are references to x and y defined in the main program (as passed by position).  So although x and y are not in scope in Swap(), their aliases a and b are in scope.
 * 
 *  Notice you can use C's pointer version of Swap and C++ reference version of Swap in the same program, because the compiler can easily differentiate the two function on account of
 *  the different parameters passed in the calls:
 *                  Swap(&x, &y);            // pass (int*, int*)
 *                  Swap(x, y);              // pass (int&, int&)
 */


using namespace std;

void Swap(int* px, int* py)
{
    int temp;
    temp = *px;
    *px = *py;
    *py = temp;
}

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

    Swap(&x, &y);            // pass (int*, int*)
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    Swap(x, y);              // pass (int&, int&)
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
}
