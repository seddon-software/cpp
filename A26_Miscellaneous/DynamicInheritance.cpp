///////////////////////////////////////////////////////////////
//
//		Dynamic Inheritance
//
///////////////////////////////////////////////////////////////

class A
{ 
public:
    A() {}
    void f1() {}
    void f2() {}
    void f3() {}
};

class B
{
private:
    A* ptr;
public:
    void g1() {}
    void g2() {}
    void g3() {}
    B(A* p) : ptr(p) {}
    A* operator->();
};

A* B::operator->()
{
    return ptr;
}

/////

int main()
{
    B b(new A);

    b->f1();
    b->f2();
    b->f3();
    b.g1();
    b.g2();
    b.g3();
}
