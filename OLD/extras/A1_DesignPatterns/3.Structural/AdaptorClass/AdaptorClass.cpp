////////////////////////////////////////////////////////////
//
//		Adaptor Pattern (class)
//
////////////////////////////////////////////////////////////


// this is the original class which we do not want to change
class ITarget
{
public:
	virtual void f1() = 0;
	virtual void f2() = 0;
};

class Target : public ITarget
{
public:
    virtual void f1() {}
    virtual void f2() {}
};


// this is the our class which uses the wrong interface
class OurClass
{
public:
	void g1() {}
	void g2() {}
	void g3() {}
	void g4() {}
};


// this is the Adapter class
class Adapter : public ITarget, private OurClass
{
public:
	void f1() { g1(); g2(); }
	void f2() { g3(); g4(); }
};

/////

void test(ITarget& target)
{
    target.f1();
    target.f2();
}

int main()
{
    Target t1;
    Target t2;
    Adapter adapter1;
    Adapter adapter2;

    // check we can use target and adapter objects
    test(t1);
    test(t2);
    test(adapter1);
    test(adapter2);
}
