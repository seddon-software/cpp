/*
 * In this example we examine late binding with a polymorphic group of objects created on the stack.  
 * Groups of objects from an inheritance hierrachy are called polymophic collections.
 * 
 * STL classes do not allow you to add objects by reference.  If you wish to add objects to a vector (and not 
 * copies thereof) you must declare the collection with a pointer:
 *         vector<Shape*> theList;
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

void drawAnyShape(Shape* s)
{
    s->draw();    // late binding, runtime binding, dynamic binding
}

int main()
{
    Rectangle r1;
    Rectangle r2;
    Polygon p1; 
    Polygon p2;
    Ellipse e1;
    Ellipse e2;

    vector<Shape*> theList;
    theList.push_back(&r1);
    theList.push_back(&r2);
    theList.push_back(&p1);
    theList.push_back(&p2);
    theList.push_back(&e1);
    theList.push_back(&e2);

    for (size_t i = 0; i < theList.size(); ++i)
    {
        drawAnyShape(theList[i]);
    }
}

