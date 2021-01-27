//////////////////////////////////////////////////////////////////////
//
//      Reference Counting Objects
//
//////////////////////////////////////////////////////////////////////

// class to apply reference counting
// ... this class is unaware of the reference counting
class anything
{
public:
    anything(int x0) : x(x0) {}
    void f1() {}
    void f2() {}
private:
    int x;
};

/////

template <typename T>
class handle
{
public:
// default CTOR
    handle()
    {
        pBody = 0;
        pCount = new int(1);     // initial reference count
    }

// CTOR
    template <typename DATA>     // note extra template parameter
    handle(DATA theData)
    {
        pBody = new T(theData);
        pCount = new int(1);     // initial reference count
    }

// copy CTOR
    handle(const handle<T>& h)
    {
        pBody = h.pBody;
        pCount = h.pCount;
        increment();
    }

// DTOR
    ~handle()
    {
        decrement();
    }

// assignment
    handle<T>& operator=(const handle<T>& h)
    {
        if (this == &h) return *this;
    
        decrement();
        pBody = h.pBody;
        pCount = h.pCount;
        increment();
        return *this;
    }

// delegation
    T* operator->()
    {
        return pBody;
    }

private:
    void increment()
    {
        int& count = *pCount;
        count++;
    }

    void decrement()
    {
        int& count = *pCount;
        count--;
        if (count == 0)
        {
            delete pBody;
            delete pCount;
        }
    }
private:
    T*   pBody;
    int* pCount;
};



/////

int main()
{
    handle<anything> x1(100);
    handle<anything> x2(200);
    handle<anything> x3;
    handle<anything> x4;
    x4 = x3;
    x3 = x2 = x1;
    x3->f2();
    x1->f1();
    x1.operator->();
}
  
