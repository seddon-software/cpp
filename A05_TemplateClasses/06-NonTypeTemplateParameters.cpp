////////////////////////////////////////////////////////////
//
//      Non Type Parameters
//
////////////////////////////////////////////////////////////


/* Some templates are not parameterized on types as in this example.
 * The template has one non-type parameter SIZE and no generic types defined.
 */

#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;


template<int SIZE>
class Bitset
{
public:
    void print()
    {
        for(int i = 0; i <= SIZE; i++)
        {
            cout << bits[i] << endl;
        }
    }

    void set(int i, int value)
    {
        if (i <  0)    throw runtime_error("Underflow");
        if (i > SIZE) throw runtime_error("Overflow");
        bits[i] = value;
    }

private:
    int bits[SIZE+1];
};

/////

int main()
{
    Bitset<8> fibonacci;

    try
    {
        fibonacci.set(0, 1);
        fibonacci.set(1, 1);
        fibonacci.set(2, 2);
        fibonacci.set(3, 3);
        fibonacci.set(4, 5);
        fibonacci.set(5, 8);
        fibonacci.set(6, 13);
        fibonacci.set(7, 21);
        fibonacci.set(8, 34);
        fibonacci.set(9, 55);   // generates overflow
    }
    catch(const exception& e)
    {
        cout << e.what() << endl;
    }

    fibonacci.print();
}
