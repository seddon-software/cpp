// final - 	specifies that a virtual function cannot be overridden in a
//			derived class or that a class cannot be inherited from.

struct A
{
    virtual void foo() final;
    // void bar() final; // Error: non-virtual function cannot be final
};

struct B final : public A
{
    // virtual void foo(); // Error: foo cannot be overridden as it's final in A
};

/*
struct C : public B			// Error: B is final
{
};
*/

int main()
{
}
