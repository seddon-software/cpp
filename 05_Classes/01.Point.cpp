/*
 *  In this tutorial we will create a single class called Point; we will use this class to create 3 Point objects.
 *  Each of the Point objects will be able to move around a screen.
 * 
 *  This Point class has 3 functions (usually called member funcions or methods).  The methods can be introduced
 *  in the class definition:
 *              class Point
 *              {
 *              public:
 *                  void Initialise(int, int);
 *                  void MoveBy(int, int);
 *                  void WhereAreYou();
 * 
 *  and the methods are flushed out later in the code, e.g. Initialize:
 * 
 *                  void Point::Initialise(int theX, int theY)  // method OR member function
 *                  {
 *                      x = theX;
 *                      y = theY;
 *                  }
 * 
 *  Notes:
 *  1. Classes normally have attributes.  With our Point class we define two private attibutes:
 *                  private:
 *                      int x;
 *                      int y;
 * 
 *     Attributes are declared private as part of data encapsulation.  The idea being that the attributes are 
 *     only accessible inside the class via its methods.
 * 
 *  2. You must qualify the method name with its class, so that the compiler can marry the two together:
 *                  void Point::Initialise(...) { ... }
 * 
 *  3. Each method has a built in pointer called "this".  The this pointer can be used to access the private
 *     attributes.  The this pointer can be omitted if there is no ambiguity.  Thus in the MoveBy method we
 *     can access the private attribute "x" by any of:
 *                  (*this).x = (*this).x + dx;
 *                  this->x = this->x + dx;
 *                  x = x + dx;
 * 
 *     Since x is not used anywhere else in the method the last form is commonly used.
 * 
 *  4. The class is instantiated using the following syntax:
 *                  Point p1;       // p1 IS AN object
 *                  Point p2;
 *                  Point p3;
 *     An instance of a class is called an object.
 */

#include <iostream>
using namespace std;

class Point
{
public:
    void Initialise(int, int);
    void MoveBy(int, int);
    void WhereAreYou();
private:
    int x;
    int y;
};

void Point::Initialise(int theX, int theY)  // method OR member function
{
    x = theX;
    y = theY;
}

void Point::MoveBy(int dx, int dy)
{
    // (*this).x = (*this).x + dx;
    // this->x = this->x + dx;
    x = x + dx;
    y = y + dy;
}

void Point::WhereAreYou()
{
    cout << "Point is at: " << x
         << ", "            << y
         << endl;
}

int main()
{
    Point p1;       // p1 IS AN object
    Point p2;
    Point p3;

    p1.Initialise(700, 100);
    p2.Initialise(100, 300);
    p3.Initialise(600, 600);

    p1.WhereAreYou();
    p2.WhereAreYou();
    p3.WhereAreYou();

    p1.MoveBy(10, 10);
    p2.MoveBy(10, 10);
    p3.MoveBy(10, 10);

    p1.WhereAreYou();
    p2.WhereAreYou();
    p3.WhereAreYou();
}