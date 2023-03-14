/*
 * C++ compilers generate several methods automatically:
 *      default CTOR:       X()
 *      copy CTOR:          X(const X&)
 *      copy assignment:    X& operator=(X const& other)
 *      default DTOR:       ~X()
 *      move constructor:   X(X&& other)
 *      move assignment:    X& operator=(X&& other)
 *
 * If you don't want the compiler to generate some of hese function you can mark them as deleted:
 *      X() = delete
 *      X(const X&) = delete
 *      X& operator=(X const& other) = delete
 *      ~X() = delete
 *      X(X&& other) = delete
 *      X& operator=(X&& other) = delete
 * 
 * One of the most common idioms is to delete the copy constructor to make sure objects of the 
 * class can't be copied.  A good example of this idiom would be removing the copy constructor
 * from a mutex lock class to avoid copying mutexs (the copy would be an entirely seperate 
 * mutex - generally undesirable).  
 */

class Point
{
public:
//    Point() = delete;
    Point() : x(0), y(0) {}
    Point(int x, int y): x(x), y(y) {}
private:
    int x;
    int y;
};


int main()
{
    // this will be disallowed if the compliler generated default 
    // CTOR is deleted
    Point p1;
    Point p2(5, 10);
}