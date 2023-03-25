#include <iostream>
using namespace std;

/*
 *  As discussed ealier, when you constrain a template parameter or function templates using concepts, 
 *  you should use named concepts or combinations of them. What you shouldn't do is to use
 *  syntactic constraints as in this example (only given to illustrate bad practice):
 *
 *              template <unsigned int x, unsigned int y>
 *              requires (x <= 20) && requires (y <= 20)
 *
 *  Notice that the Sum template parameters A and B can't also be used as parameters to the Sum function.
 *  This means you can't write: 
 *              unsigned int Sum(int A, int B)
 */

template <int A, int B> requires (A <= 100 && B >= 100)
unsigned int Sum()
{
    return A + B;
}

int main() 
{
    cout << "sum: " << Sum<26, 121>() << endl;
}
