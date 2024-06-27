/*
 * 	We can use unique pointers to avoid having to clean up the heap manually:
 *          vector<unique_ptr<Shape>> v;
 * 
 *  When the stack based vector is cleaned up by the compiler, the destructor for each unique_ptr is
 *  called.  Each unique_ptr destructor calls the destructor for its associated heap based Shape.
 * 
 *  Note the use of 'using' to define aliases for types (doesn't create a new type):
 *              using SHAPE = unique_ptr<Shape>;
 *              using VECTOR = vector<SHAPE>;
 * 
 *  The old way of doing this was with 'typedefs', but 'using' is easier to understand
 *              typedef unique_ptr<Shape> SHAPE;
 *              typedef vector<SHAPE> VECTOR;
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
	void draw() { cout << "Polygon::draw()" << endl; }
	void show() { cout << "Polygon::show()" << endl; }
	void hide() { cout << "Polygon::hide()" << endl; }
	~Polygon() { cout << "Polygon::DTOR()" << endl; }
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

using SHAPE = unique_ptr<Shape>;   // typedef unique_ptr<Shape> SHAPE;
using VECTOR = vector<SHAPE>;      // typedef vector<SHAPE> VECTOR;

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
    // add some more objects using the type alias
	v.push_back(SHAPE(new Rectangle()));
	v.push_back(SHAPE(new Ellipse()));
	v.push_back(SHAPE(new Polygon()));
	show_all(v);
}

