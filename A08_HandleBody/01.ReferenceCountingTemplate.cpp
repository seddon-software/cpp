//////////////////////////////////////////////////////////////////////
//
//      Reference Counting Objects
//
//////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

/* 
 *  The handle-body pattern is a very famous software pattern.  The handle is usually
 *  a small object encompassing a pointer to the body which the handle manages.  The
 *  handle may have additional attributes such as a reference count.
 * 
 *  In this example we use the handle-body pattern to implement reference counting on
 *  an arbitrary class.  Let's also suppose that the body class has already been written 
 *  such that we can't change it by adding reference counting.  We will have to add the
 *  reference count to the handle somehow.
 * 
 *  Thus the handle needs to keep a record of both the reference count and the pointer to
 *  its body.  Then, when a handle-body pair is copied, assigned or deleted, the reference 
 *  count is adjusted accordingly.
 * 
 *  The simplest way to acieve this is to keep the reference count and the body on the heap and 
 *  store pointers to both in the handle.  Then when a copy or assignment is attempted only
 *  the handle needs to be duplicated.  This in turn saves on a possibly expensive copy 
 *  operation involving the body.  
 * 
 *  When a handle-body pair goes out of scope we only need to decrement the reference count 
 *  via the handle, leaving the body alone.  Except of course when the count becomes zero.  
 *  That's when the handle-body commits suicide!
 */

// class to which we apply reference counting
// ... this class is unaware of the reference counting
class anything
{
public:
    anything(int x0) : x(x0) {}
    void f1() {}
    void f2() {}
    ~anything()
    {
        cout << "body DTOR called" << endl;
    }
private:
    int x;
};

/////
template <typename T>
class handle
{
private:
    // the handle points to the body and reference count (both on the heap)
    T*   pBody;
    int* pCount;
public:
// CTOR
    template <typename DATA>     // note extra template parameter
    handle(DATA theData)
    {
        pBody = new T(theData);
        pCount = new int(1);     // initial reference count; 
        // note not using []. new int(1) means initialize a single int with the value 1
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
        cout << "handle DTOR: ";
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
    friend ostream& operator<<(ostream& os, const handle<T>& h)
    {
        return os << "ref count = " << *(h.pCount) << ", body at: " << h.pBody << endl;
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
        cout << *this;
        if (count == 0)
        {
            delete pBody;
            delete pCount;
        }
    }
};



/////

int main()
{
    handle<anything> x1(100);
    handle<anything> x2(200);
    handle<anything> x3(300);
    cout << x1 << x2 << x3 << endl;

    handle<anything> x4(x1);
    cout << x1 << x4 << endl;

    x3 = x2 = x1;
    cout << x1 << x2 << x3 << x4 << endl;

    x3->f2();   // note use of -> to call methods in body
    x1->f1();
}
  
