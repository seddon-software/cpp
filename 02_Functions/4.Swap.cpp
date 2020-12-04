////////////////////////////////////////////////////////////
//
//      Passing by Reference
//
////////////////////////////////////////////////////////////

void swap(int&, int&);       // function prototype

/*
 *  Passing parameters by reference allows the Swap function access to the
 *  original variables x and y.  The references a and b are aliases for x and y respectively.
 */

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
}
