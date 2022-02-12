////////////////////////////////////////////////////////////
//
//      Classes using templates
//
////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

/*
 *  Here is the same example, but with the implementations of the template member functions written
 *  inline.  As you can see this is much more concise and is often the preferred approach.
 *
 *  Note, by separating the class definition from the the member functions, you can place their 
 *  implementations in source files and keep the class declaration in a header file.  Before the
 *  advent of templates, implementation code was always separated from class definitions in this way,
 *  but because writing templates inline is so concise, programmers frequently use the inline approach
 *  and implementation code ends up in header files.  Suffice to say, this is now the recommended
 *  practice.
 */

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
    Array<> a(15);
    Array<double,6> b(27.96);

    a.Print();
    b.Print();
}

