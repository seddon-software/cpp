////////////////////////////////////////////////////////////
//
//      Classes using templates
//
////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

/*
 *  Templated classes are really just a group of templated functions wrapped up in a class.  Consider
 *  the Array class in this example.  It is templated on the typename T and an int N.  Interestingly
 *  T and N can have default values:
 *      template <typename T = int, int N = 3>
 *
 *  In the calling program, you can use these default values as in:
 *          Array<> a(15);  // use defaults for T and N, the <> are required
 *
 *  Note that the class definition and each member function have to be templated.  This example shows
 *  all the templates defined separarely, but it is more common to define all the templates in one 
 *  place (inline).  We will look at this alternative form in subsequent examples.
 * 
 *  Note that after the class definition, in the member function templates, only the class name is
 *  parameterised, not the method name: 
 *          Array<T,N>::Array(T t)
 *          void Array<T,N>::Print()
 * 
 *  Parameterizing method names is reserved for specialization (see later examples).
 */

// define templated class definition
template <typename T = int, int N = 3>
class Array
{
private:
    T array[N];
public:
    Array(T t);
    void Print();
};

// define template for CTOR method
template <typename T, int N>
Array<T,N>::Array(T t)
{
    for(int i = 0; i < N; i++)
        array[i] = t;
}


// define template for Print method
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
    Array<> a(15);  // use defaults for T and N, the <> are required
    Array<double,6> b(27.96);

    a.Print();
    b.Print();
}

