/*
 *  Inlining a function is just a suggestion to the compiler. The Compiler may or may not inline the functions
 *  you marked as inline.  Further, the compiler may decide to inline functions NOT marked as inline at 
 *  compilation or linking time.
 * 
 *  Because if the above, it is best to avoid inlining functions altogether and let the compiler decide what
 *  to inline.
 */

void swap(int&, int&);       // function prototype

inline void swap(int& a, int& b)
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
