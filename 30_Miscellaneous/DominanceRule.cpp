///////////////////////////////////////////////////////////////
//
//		Dominance Rule
//
///////////////////////////////////////////////////////////////

// A <--- B <--- D <--- E
// A <------- C <------ E

class A
{ 
public: 
    virtual void f1() {}
};

class B : public A
{
};

class C : public A
{
public:
	void f2() { f1(); }   // f1() is virtual
};

class D : public B
{
public:
    virtual void f1() {}
};

class E : public C, public D
{
public:
    void f4() { f2(); }   // f2() is not virtual
};

/////

int main()
{
    E e;
    e.f4();		// calls f1

	return 0;
}
