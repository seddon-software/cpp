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

struct X {};
struct Y 
{
    friend auto& operator<<(ostream& out, const Y& rhs)
    {
        return out << rhs.a << "," << rhs.b << endl;
    }
    friend auto operator+(const Y& lhs, const Y& rhs)
    {
        Y result;
        result.a = lhs.a + rhs.a;
        result.b = lhs.b + rhs.b;       
        return result;
    }
    int a;
    int b;
};

template<typename T>
concept addable = requires (T a, T b) { a + b; };

template<addable T>
T add(T a, T b)
{
    return a + b;
}

int main()
{
    // call add<addable T> with T = double
    cout << add(6.3, 7.8) << endl;          // double supports +

    // call add<addable T> with T = Y
    Y y1{.a = 10, .b = 20};
    Y y2{.a = 15, .b = 25};
    cout << add(y1, y2) << endl;            // Y supports +

    [[ maybe_unused ]] X x1{};
    [[ maybe_unused ]] X x2{};
    // call add<addable T> with T = X
    // cout << add(x1, x2) << endl;  // doesn't compile because X doesn't support +
}
