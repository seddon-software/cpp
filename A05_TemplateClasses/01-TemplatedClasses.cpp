////////////////////////////////////////////////////////////
//
//      Classes using templates
//
////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;


// define templated class
template <typename T = int, int N = 3>
class Array
{
private:
    T array[N];
public:
    Array(T t);
    void Print();
};

// define implementation of generic template for Array(T)
template <typename T, int N>
Array<T,N>::Array(T t)
{
    for(int i = 0; i < N; i++)
        array[i] = t;
}


// define implementation of generic template for Print()
template <typename T, int N>
void Array<T,N>::Print()
{
    for(int i = 0; i < N; i++)
        cout << array[i] << "\t";
    cout << endl;
}

/////

int main()
{
    Array<> a(15);  // use defaults for T and N
    Array<double,6> b(27.96);

    a.Print();
    b.Print();
}

