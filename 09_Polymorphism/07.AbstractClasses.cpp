/*
 * The Shape class in all our examples was introduce to allow us to define all the polymorphic methods
 * used by the derived classes.  In practice such classes are artificial and never intended to be 
 * instantiated. For example, if we created a Shape object, how would be implement draw?  We don't
 * know enough about a Shape object to draw it!
 * 
 * Such classes are abstract and to ensure we can instantiate objects in these classes all you need to 
 * do is set one or more virtual functions to 0 (call pure virtual functions).  When the compiler sees
 * a 0 (null pointer) in the V-Table it realises it is not safe to instantiate objects of this class.
 * Hence the line:
 *          Shape s;
 * 
 * doesn't compile.
 */

#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Shape
{
public: // interface
	virtual void draw() = 0;        // this makes the class abstract
	virtual void show() {}
	virtual void hide() {}
	virtual ~Shape() { cout << "Shape::DTOR()" << endl; }
};

class Polygon : public Shape
{
public:
	void draw() { cout << "Polygon::draw()" << endl; }
	void show() { cout << "Polygon::show()" << endl; }
	void hide() { cout << "Polygon::hide()" << endl; }
	virtual ~Polygon() { cout << "Polygon::DTOR()" << endl; }
};

class Rectangle : public Shape
{
public:
	virtual void draw() { cout << "Polygon::draw()" << endl; }
	virtual void show() { cout << "Polygon::show()" << endl; }
	virtual void hide() { cout << "Polygon::hide()" << endl; }
	virtual ~Rectangle() { cout << "Polygon::DTOR()" << endl; }
};

class Ellipse : public Shape
{
public:
	virtual void draw() { cout << "Ellipse::draw()" << endl; }
	virtual void show() { cout << "Ellipse::show()" << endl; }
	virtual void hide() { cout << "Ellipse::hide()" << endl; }
	virtual ~Ellipse() { cout << "Ellipse::DTOR()" << endl; }
};


int main()
{
	// Shape s;   // doesn't compile
}

