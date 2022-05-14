#include <iostream>

/*
 *
 *
 */


using namespace std;

void Swap(int* px, int* py)
{
    int temp;
    temp = *px;
    *px = *py;
    *py = temp;
}

void Swap(int& x, int& y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
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
