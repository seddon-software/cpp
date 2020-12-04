///////////////////////////////////////////////////////////////
//
//		Down Casts
//
///////////////////////////////////////////////////////////////


class A 
{
public:
    virtual void f() {}
};

class B : public A 
{
public:
    virtual void f() {}
};

class C : public B 
{
public:
    virtual void f() {}
};

int main()
{
	A* pa = new A;                  // legal: *pa <IS A KIND OF> A
    A* pb = new B;                  // legal: *pb <IS A KIND OF> A
    A* pc = new C;                  // legal: *pc <IS A KIND OF> A

	B* qa = dynamic_cast<B*>(pa);	// error: pa does not point  to a <KIND OF> B
	B* qb = dynamic_cast<B*>(pb);	// ok:    pb          points to a <KIND OF> B
	B* qc = dynamic_cast<B*>(pc);	// ok:    pc          points to a <KIND OF> B

    if (qa != 0) qa->f();
    if (qb != 0) qb->f();
    if (qc != 0) qc->f();

	return 0;
}
