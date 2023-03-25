#include <cstring>
#include <iostream>
using namespace std;


/*
 *  Many of the algorithms in the standard library work over a range defined by begin() 
 *  and end() iterators.  In most cases these iterators are of the same type.  However sometimes
 *  the end() has to be computed dynamically, for example with a null terminated C-string and end()
 *  has to be defined differently. These an end-only iterators are called a sentinels.  Usually we define
 *  the sentinel as a nested empty class.  The only part of the sentinel that is relevent is its type (see
 *  below).
 *
 *  So, whenever you have a range where the end is some dynamic condition instead of a fixed position, 
 *  we use an iterator and sentinel pair, a.k.a. a range.  Ranges are simpler to use than iterator pairs
 *  and this is why the STL algorithms have now been extended to support ranges.
 * 
 *  The key part of this example is the loop incrementing the begin iterator:
 *          while(begin != end)
 *          {
 *              cout << *begin << flush;
 *              ++begin;
 *          }
 * 
 *  The exit condition for the loop is when we reach the null terminator at the end of the string.  This is
 *  a dynamic condition and we can only determine this at run-time.  Therefore we check for his exit condition
 *  in the first line:
 *          while(begin != end)
 * 
 *  which calls the friend function in the nested iterator class:
 *          String::iterator::operator!=(iterator iter, sentinel)
 * 
 *  because end is of type sentinel and begin is of type iterator.  So the loop prints characters from the string
 *  one by one until operator!= returns false.
 */

// our example collection class
class String
{
public:
    String(const char* s)
    {
        text = new char[strlen(s)+1];
        strcpy(text, s);
        pIterator = new iterator(text);
    }
    String(const String& s)
    {
        text = new char[strlen(s.text)+1];
        strcpy(text, s.text);
        pIterator = new iterator(text);
    }
    ~String()
    {
        delete[] text;
    }
private:
    // forward declarations of nested classes
    class sentinel;
    class iterator;
public:
    // return iterator and sentinel
    const char* begin() const { return text; }
    sentinel end() const { return sentinel{}; }
private:
    iterator* pIterator;
    char* text;

    // The special end-only iterator.
    // It is usually an empty type, we don't actually need any objects.
    // It's just there because `!=` takes two parameters.
    class sentinel {};

    // Some iterator, with *, ++, etc.
private:
    friend bool operator!=(iterator iter, sentinel)
    {
        cout << boolalpha << "\noperator!=(iterator iter, sentinel) returns " << (*iter != '\0') << endl;
        return *iter != '\0'; /* is iter not done? */
    }    
    class iterator
    {
    public:
        iterator(const char* text): text(text){}
        const char* operator++()
        {
            text++;
            return text;
        }
        const char operator*()
        {
            return *text;
        }        
    private:
        const char* text;
    };
};

// our example algorithms, one taking a pair of iterators, the other taking a range
template <typename I, typename S>
void printAlgorithm(I begin, S end) // this takes an iterator-sentinel pair
{
    cout << "printAlgorithm(Iterator begin, Sentinel end)" << endl;
    while(begin != end)
    {
        cout << *begin << flush;
        ++begin;
    }
    std::cout << std::endl;
}

template <typename R>  // this takes a range
void printAlgorithm(R& r)
{
    cout << "printAlgorithm(Range& r)" << endl;
    // r.begin() returns a const char*
    // r.end() returns a sentinel object
    printAlgorithm(r.begin(), r.end());
}

class StringRange
{
public:
    StringRange(const String& s): s(s){}


    auto begin() const  // returns const char*
    {
        return s.begin();
    }

    auto end() const // returns the sentinel
    {
        return s.end();
    }
private:
    const String& s;
};

int main()
{
    const String s{"ABCDEFGHIJKLM"};
    StringRange range(s);
    printAlgorithm(range);
}
