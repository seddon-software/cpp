////////////////////////////////////////////////////////////
//
//      Classes using templates
//
////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;


// define generic template for Array<T,N>
template <typename T = int, int N = 3>
class Array
{
private:
    T array[N];
public:
    Array(T x)
    {
        for(int i = 0; i < N; i++)
            array[i] = x;
    }
    void Print()
    {
        for(int i = 0; i < N; i++)
            cout << array[i] << "\t";
        cout << endl;
    }
};

/////

int main()
{
    Array<>    a(15);
    Array<double,6> b(27.96);

    a.Print();
    b.Print();
}

