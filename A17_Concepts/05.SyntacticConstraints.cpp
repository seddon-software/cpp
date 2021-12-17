#include <iostream>
using namespace std;

// template <unsigned int x, unsigned int y>
// requires (x <= 20) && requires (y <= 20)
// int xySum() 
// {
//     return x + y;
// }

// this works, but a <= 100 && b >= 100 is not a semantic category 
// and hence is not regarded as good practice
template <int a, int b>
requires (a <= 100 && b >= 100)
unsigned int Sum()  // note a and b are template parameters (types), so you can't write: Sum(int a, int b) 
{
    return a + b;
}

int main() 
{
    cout << "sum: " << Sum<26, 121>() << endl;
}
