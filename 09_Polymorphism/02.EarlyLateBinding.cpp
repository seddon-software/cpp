/* 
 * Polymorphism is where we have many (poly) forms (morphic) of a given method in an inheritance hierarchy.
 *
 * With inheritance the compiler has 2 different ways of binding an object to a method:
 *      Early binding is when the compiler determines which method to call at compile time.
 *      Late binding is when the compiler defers the decision until run time.
 * 
 * Because of the SUBSTITUTION RULE the compiler can't detrmine which object is passed to a function if
 * a reference is used.  The rule states that and derived object could be passed as a substitute for the 
 * base class objec.  This in turn means the compiler can't determine witch polymorphic method to call
 * at compile time and needs to defer a decision on object/function binding until run time.
 * 
 * As we have seen, passing a polymorphic object by reference to a function is not sufficient to ensure
 * late binding is used; C++ requires methods to be also marked as 'virtual' before late binding occurs.
 * It may seem that declaring a method virtual is excessive, but at the time when Bjarne Stroustrup
 * introduced polymorphic functions, he was worried that late binding might be too inefficient.  Languages
 * that followed C++'s lead have dispensed with virtual functions and only require a reference to employ 
 * late binding.
 * 
 * Nevertheless we have to use virtual functions in C++.  It should be noted that the term virtual function
 * is a misnomer - there is nothing virtual about these functions. 
 * 
 * In this example we again create a free function that takes a polymorhic object by reference, but this
 * time all the class methods are marked virtual.  As we will see shortly this results in the compiler 
 * employing late binding in the function below:
 *
 *          void drawAnyShape(Shape& s)
 *          {
 *              s.draw();    // late binding, runtime binding, dynamic binding
 *          }
 * 
 * With early binding, the base class method always gets called, which is normally not what is desired.  
 * Why else would we write a polymorphic version of the method in the derived classes?
 * 
 * Note that:
 *  early binding can also be called 1) compile time binding or 2) static binding
 *  late binding  can also be called 1) runtime binding or      2) dynamic binding
 */

#include <vector>
#include <iostream>
using namespace std;


class Shape
{
public:
	virtual void draw() { cout << "Shape::draw()" << endl; }
	virtual void show() { cout << "Shape::show()" << endl; }
	virtual void hide() { cout << "Shape::hide()" << endl; }
	virtual ~Shape() { cout << "Shape::DTOR()" << endl; }
};

class Rectangle : public Shape
{
public:
	virtual void draw() { cout << "Rectangle::draw()" << endl; }
	virtual void show() { cout << "Rectangle::show()" << endl; }
	virtual void hide() { cout << "Rectangle::hide()" << endl; }
	virtual ~Rectangle() { cout << "Rectangle::DTOR()" << endl; }
};

class Polygon : public Shape
{
public:
	virtual void draw() { cout << "Polygon::draw()" << endl; }
	virtual void show() { cout << "Polygon::show()" << endl; }
	virtual void hide() { cout << "Polygon::hide()" << endl; }
	virtual ~Polygon() { cout << "Polygon::DTOR()" << endl; }
};

class Ellipse : public Shape
{
public:
	virtual void draw() { cout << "Ellipse::draw()" << endl; }
	virtual void show() { cout << "Ellipse::show()" << endl; }
	virtual void hide() { cout << "Ellipse::hide()" << endl; }
	virtual ~Ellipse() { cout << "Ellipse::DTOR()" << endl; }
};

//////
// pass Shape by reference
// the compiler can't tell if its a Rectangle, Polygon or Ellipse
// hence s and draw() are bound at runtime
void drawAnyShape(Shape& s)
{
    s.draw();    // late binding, runtime binding, dynamic binding
}

int main()
{
    Rectangle r1;
    Rectangle r2;
    Polygon p1; 
    Polygon p2;
    Ellipse e1;
    Ellipse e2;
    
    drawAnyShape(r1);
    drawAnyShape(r2);
    drawAnyShape(p1);
    drawAnyShape(p2);
    drawAnyShape(e1);
    drawAnyShape(e2);

    p1.hide();         // early binding, compile time binding, static binding
    p2.Shape::hide();  // early binding, compile time binding, static binding
}

