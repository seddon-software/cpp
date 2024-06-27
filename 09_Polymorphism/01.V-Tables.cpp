/*
    C++ uses v-tables to implement late binding.  If a method is marked as virtual in the base class, the 
    compiler creates one V-Table per class and places a pointer to the V-Table in every object:

          r1                   Rectangle V-Table
     ┌──────────┐      ┌───────────────────────────────┐
     │  _vptr   │----->│ Rectangle::show() {...}       │
     │   ...    │  │   │ Rectangle::hide() {...}       │
     └──────────┘  │   │ Rectangle::draw() {...}       │
          r2       │   │ Rectangle::~Rectangle() {...  │
     ┌──────────┐  │   └───────────────────────────────┘
     │  _vptr   │--┘
     │   ...    │ 
     └──────────┘

          p1                   Polygon V-Table
     ┌──────────┐      ┌───────────────────────────────┐
     │  _vptr   │----->│ Polygon::show() {...}         │
     │   ...    │  │   │ Polygon::hide() {...}         │
     └──────────┘  │   │ Polygon::draw() {...}         │
          p2       │   │ Polygon::~Polygon() {...}     │
     ┌──────────┐  │   └───────────────────────────────┘
     │  _vptr   │--┘
     │   ...    │ 
     └──────────┘

          e1                   Ellipse V-Table
     ┌──────────┐      ┌───────────────────────────────┐
     │  _vptr   │----->│ Ellipse::show() {...}         │
     │   ...    │  │   │ Ellipse::hide() {...}         │
     └──────────┘  │   │ Ellipse::draw() {...}         │
          e2       │   │ Ellipse::~Ellipse() {...}     │
     ┌──────────┐  │   └───────────────────────────────┘
     │  _vptr   │--┘
     │   ...    │ 
     └──────────┘
 * 
 * This effectively produces a dynamic switch statement and insures the approriate method is called
 * at run time when late binding is used as in:
 *
 *          void drawAnyShape(Shape& s)
 *          {
 *              s.draw();    // late binding, runtime binding, dynamic binding
 *          }
 */

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

int main()
{
    Rectangle r1;
    Rectangle r2;
    Polygon p1; 
    Polygon p2;
    Ellipse e1;
    Ellipse e2;
}

/* 
 * Note: to view VTables in vscode you need to use the Debug Console:
 *      -exec info vtbl s1
 *      -exec info vtbl s2
 *      -exec info vtbl b1 etc
 * to view the pointer to the VTable embedded in each object
 *      -exec p s1
 */
