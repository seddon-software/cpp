/*
 * Write a function to calculate Factorials.  Try out
 *     factorial(1)
 *     factorial(10)
 *     factorial(40)
 *     factorial(100)
 */

#include <iostream>
using namespace std;

double factorial(int n)
{
    if(n == 1)
        return 1.0;
    else
        return n * factorial(n - 1);
}

int main()
{
    cout << factorial(1) << endl;
    cout << factorial(10) << endl;
    cout << factorial(40) << endl;
    cout << factorial(100) << endl;
}
