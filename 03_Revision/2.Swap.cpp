////////////////////////////////////////////////////////////
//
//      Passing by Reference
//
////////////////////////////////////////////////////////////

void swap(int&, int&);       // function prototypes
void swap(int*, int*);

/*
 *  Passing parameters by reference allows the Swap function access to the
 *  original variables x and y.  The references a and b are aliases for x 
 *  and y respectively.
 * 
 *  Using C, you have to pass pointers in order to swap.
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

    swap(x, y);
    swap(&x, &y);
}
