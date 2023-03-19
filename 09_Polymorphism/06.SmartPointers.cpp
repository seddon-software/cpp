/*
 * 	We can use unique pointers to avoid having to clean up the heap manually:
 *          vector<unique_ptr<Shape>> v;
 * 
 *  When the stack based vector is cleaned up by the compiler, the destructor for each unique_ptr is
 *  called.  Each unique_ptr destructor calls the destructor for its associated heap based Shape.
 */

#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Shape
{
public: // interface
	virtual void draw() = 0;
	virtual void show() = 0;
	virtual void hide() = 0;
	virtual ~Shape() { cout << "Shape::DTOR()" << endl; }
};

class Polygon : public Shape
{
public:
	virtual void draw() { cout << "Rectangle::draw()" << endl; }
	virtual void show()	{ cout << "Rectangle::show()" << endl; }
	virtual void hide() { cout << "Rectangle::hide()" << endl; }
	virtual ~Polygon() { cout << "Rectangle::DTOR()" << endl; }
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

typedef unique_ptr<Shape> SHAPE;
typedef vector<SHAPE> VECTOR;

void show_all(VECTOR& v)
{
	for(auto& ptr : v)
	{
		ptr->show();
	}
}

int main()
{
	// use unique pointers to avoid having to clean up the heap manually
	vector<unique_ptr<Shape>> v;
	v.push_back(unique_ptr<Shape>(new Rectangle()));
	v.push_back(unique_ptr<Shape>(new Ellipse()));
	v.push_back(unique_ptr<Shape>(new Polygon()));
	show_all(v);
}

