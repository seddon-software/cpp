#include <iostream>
using namespace std;

void swap(int&, int&);       // function prototypes
void swap(int*, int*);

/*
 *  Passing parameters by reference allows the Swap function access to the original variables x and y.  
 *  The references a and b are aliases for x and y respectively.  Normally you can't refer to local 
 *  variables defined in a different function, but references can be thought of extending the scope of a 
 *  storage location from one function to another.
 * 
 *  In C, where there are no references, you have to use pointers to achieve the same effect.  As you can
 *  see from this example, references are cleaner and more concise.  Furthermore, the compiler can see 
 *  that the two swap functions are distinct, because one works with pointers and the other with 
 *  references.
 */

void swap(int* pa, int* pb)
{
    int temp;
     
    temp = *pa;
    *pa    = *pb;
    *pb    = temp;
}

void swap(int& a, int& b)
{
    int temp;
     
    temp = a;
    a    = b;
    b    = temp;
}


int main()
{
    int x = 100;
    int y = 200;

    swap(x, y);     // pass int's
    cout << "x,y = " << x << "," << y << endl;
    swap(&x, &y);   // pass int*'s (references)
    cout << "x,y = " << x << "," << y << endl;
}
