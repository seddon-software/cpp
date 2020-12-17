////////////////////////////////////////////////////////////
//
//		Visitor Pattern
//
////////////////////////////////////////////////////////////


// our class hierarchy - can't be modified
class MyA;
class MyB;
class MyC;

// Visitors effectively add methods to our hierarchy ...
// Vistors have methods for each class in our hierarchy 
class Visitor
{
public:
	virtual void f(MyA) = 0;
	virtual void f(MyB) = 0;
	virtual void f(MyC) = 0;
};

class IAccept
{
public:
	virtual void accept(Visitor* v) = 0;
};

class MyA : public IAccept
{
public:
	virtual void accept(Visitor* visitor) 
	{
	    visitor->f(*this);
	}
};

class MyB : public IAccept
{
public:
	virtual void accept(Visitor* visitor) 
	{
	    visitor->f(*this);
	}
};

class MyC : public IAccept
{
public:
	virtual void accept(Visitor* visitor) 
	{
	    visitor->f(*this);
	}
};

// each visitor effectively adds a new method to our hierarchy
class Visitor1 : public Visitor
{
public:
	void f(MyA) {}
	void f(MyB) {}
	void f(MyC) {}
};

class Visitor2 : public Visitor
{
public:
	void f(MyA) {}
	void f(MyB) {}
	void f(MyC) {}
};

class Visitor3 : public Visitor
{
public:
	void f(MyA) {}
	void f(MyB) {}
	void f(MyC) {}
};

class Visitor4 : public Visitor
{
public:
	void f(MyA) {}
	void f(MyB) {}
	void f(MyC) {}
};

/////

int main()
{
    MyA a;
    MyB b;
    MyC c;
    a.accept(new Visitor1());
    b.accept(new Visitor3());
    c.accept(new Visitor2());
    a.accept(new Visitor4());
}

