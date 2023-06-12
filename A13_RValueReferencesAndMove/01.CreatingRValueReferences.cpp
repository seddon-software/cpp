/*
Every C++ expression has a type, and belongs to a value category. The value categories are the basis for rules that compilers must follow when creating, copying, and moving temporary objects during expression evaluation.

The C++17 standard defines expression value categories as follows:

    A glvalue is an expression whose evaluation determines the identity of an object, bit-field, or function.
    A prvalue is an expression whose evaluation initializes an object or a bit-field, or computes the value of the operand of an operator, as specified by the context in which it appears.
    An xvalue is a glvalue that denotes an object or bit-field whose resources can be reused (usually because it is near the end of its lifetime). Example: Certain kinds of expressions involving rvalue references (8.3.2) yield xvalues, such as a call to a function whose return type is an rvalue reference or a cast to an rvalue reference type.
    An lvalue is a glvalue that isn't an xvalue.
    An rvalue is a prvalue or an xvalue.
*/
/*
r values are:
=============
a)  constants
b)  value return from function (i.e. a temporary)
c)  an expression on the RHS of an equals

R-value references
==================
	                    ┌─────────────────────────┬────────────┐
                        │ can be initialized with │ can modify │
                        ├─────────────────────────┼────────────┤
Modifiable l-values	    │           No            │     No     │
Non-modifiable l-values	│           No            │     No     │
R-values	            │           Yes           │     Yes    │
                        └─────────────────────────┴────────────┘
const R-value references
========================
	                    ┌─────────────────────────┬────────────┐
                        │ can be initialized with │ can modify │
                        ├─────────────────────────┼────────────┤
Modifiable l-values	    │           No            │     No     │
Non-modifiable l-values	│           No            │     No     │
R-values	            │           Yes           │     No     │
                        └─────────────────────────┴────────────┘

R-value references have two properties that are useful. 
First, r-value references extend the lifespan of the object they are initialized with to the lifespan of 
    the r-value reference (l-value references to const objects can do this too). 
Second, non-const r-value references allow you to modify the r-value!
*/

#include<iostream>
#include<string>
using namespace std;




template <typename T>
void checkArg(T&& parameter, const string& name)
{
	if (std::is_lvalue_reference<T>::value)
		cout << name + " is a T&" << endl;
	else
		cout << name + " is a T&&" << endl;
}


struct X
{
    X(int i=0): i(i) {}
    ~X() { cout << "DTOR: " << i << endl; }
    int i;
};
X operator+(const X& lhs, const X& rhs)
{
    return X{lhs.i + rhs.i};
}



X f()
{
    return X{200};
}

int main()
{
    X x1{1};                    // l-value
    X x2{2};
    // https://www.learncpp.com/cpp-tutorial/rvalue-references/
    {
        checkArg(X{101}, "X{101}");   // temporary
        checkArg(f(), "f()");         // value return from function
        checkArg(x1 + x2, "x1 + x2"); // expression
        cout << endl;
    }
    {
        X&& rr1 = X{100};             // initialise with temporary
        X&& rr2 = f();                // initialise with value return from function
        const X&& rr3 = x1 + x2;            // initialise with expression

        // all the above r-value references are l-values
        checkArg(rr1, "rr1");
        checkArg(rr2, "rr2");
        checkArg(rr3, "rr3");

        // modify these l-values
        rr1.i = 300;
        rr2.i = 301;
        // rr3.i = 302;  // can't modify rr3 (const)
        cout << "rr1, rr2, rr3: end of lifetime" << endl;
    }
    cout << "x1, x2: end of lifetime" << endl;
}
