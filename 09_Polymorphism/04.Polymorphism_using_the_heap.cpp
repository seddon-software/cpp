/*
 * This is the same example, but with heap based objects.  As with all heap base objects it is the programmers
 * responsibility to clean up the heap at the end of the program, hence:  
 *          for(auto& ptr : theList)
 *          {
 *              delete ptr;   
 *          }
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
    // create all our controls on the heap
    vector<Shape*> theList;
    theList.push_back(new Rectangle());
    theList.push_back(new Rectangle());
    theList.push_back(new Polygon());
    theList.push_back(new Polygon());
    theList.push_back(new Ellipse());
    theList.push_back(new Ellipse());

    for (unsigned i = 0; i < theList.size(); ++i)
    {
        drawAnyShape(theList[i]);
    }

    // clean up the heap
    for(auto& ptr : theList)
    {
        delete ptr;   
    }
}

