#include <iostream>
#include <concepts>
using namespace std;

/*
 *  Concepts can check if a template parameter T representing a class supports named methods.  In this
 *  example we first define concepts called "has_f_and_g" and "then a simpler concept call "has_h".  
 *  Note the syntax:
 *          concept <concept-name> = <requires-expression>
 * 
 *  The requires-expression looks like a function called "requires" without a return statement.
 * 
 *  Clearly objects of class X and class Y will satisfy the "has_f_and_g" concept and those of class Z
 *  satisfy the "has_h" concept.  Once the concepts have been defined, we can create dependent templates:
 *          void compute_fg(T t) requires has_f_and_g<T>
 *          void compute_h(T t) requires has_h<T>
 */


// define some classes to use with templates
class X
{
public:
    void f() {}
    void g() {}
};
class Y
{
public:
    void f() {}
    void g() {}
};
class Z
{
public:
    void f() {}
    void h() {}
    void k() {}
};

// define concepts
template<typename T>
concept has_f_and_g = requires(T t) { t.f(); t.g(); };

template<typename T>
concept has_h = requires(T t) { t.h(); };


// define templates dependent on the above concepts
template <typename T>
void compute_fg(T t) requires has_f_and_g<T>
{
    t.f();
    t.g();
}

template <typename T>
void compute_h(T t) requires has_h<T>
{
    t.h();
}

//////

int main()
{
    X x;
    Y y;
    Z z;
    compute_fg(x);
    compute_fg(y);
    compute_h(z);
}
