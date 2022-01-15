#include <iostream>
using namespace std;

/*
 *  Concepts can include constraints on operations that can be performed on template types.  In this 
 *  example we define the addable concept as requiring the template type parameter be capable of 
 *  supporting the + operator.  Notice how the requirement is specified as:
 *
 *          template<typename T>
 *          concept addable = requires (T a, T b) { a + b; };
 *
 *  Despite appearances, the compiler does not compute a + b, it merely checks that a + b will compile
 *  for the template type T. 
 */

template<typename T>
concept addable = requires (T a, T b) { a + b; };


template<addable T>
T add(T a, T b)
{
    return a + b;
}

int main()
{
    cout << add(6.3, 7.8) << endl;
}
