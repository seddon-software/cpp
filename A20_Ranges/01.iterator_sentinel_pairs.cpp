#include <cstring>
#include <iostream>

/*
 * Many of the algorithms in the standard library work over a range defined by begin() 
 * and end() iterators.  In most cases these iterators are of the same type.  However sometimes
 * the end() has to be computed dynamically, for example with a null terminated C-string and end()
 * has to be defined differently. These an end-only iterators are called a sentinels.
 *
 * So, whenever you have a range where the end is some dynamic condition instead of a fixed position, 
 * we use an iterator and sentinel pair instead.  Ranges are simpler to use than iterator pairs
 * and this is why the STL algorithms have been extended to support ranges.
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
    // It's just there because `==` takes two parameters.
    class sentinel {};

    // Some iterator, with *, ++, etc.
private:
    friend bool operator==(iterator iter, sentinel)
    {
        return *iter == '\0'; /* is iter done? */
    }
    friend bool operator!=(iterator iter, sentinel)
    {
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
    while(begin != end)
    {
        std::cout << *begin;
        std::cout.flush();
        ++begin;
    }
    std::cout << std::endl;
}

template <typename R>  // this takes a range
void printAlgorithm(R& r)
{
    printAlgorithm(r.begin(), r.end());
}

class StringRange
{
public:
    StringRange(const String& s): s(s){}


    auto begin() const
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
    printAlgorithm(s.begin(), s.end());
    printAlgorithm(range);
}
