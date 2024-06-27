/*
 * Abstract classes can have methods, but if we make all the virtual methods pure virtual:
 *	            virtual void draw() = 0;
 *          	virtual void show() = 0;
 *              virtual void hide() = 0;
 * 
 * the class is called an interface.  Interfaces are use to deine methods that must be implemented
 * in derived classes and act as a specification thereof.  If any methods are not implemented in
 * derived classes they will inherit a zero in their V-Table and hence become abstract classes.
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

using VECTOR = vector<Shape*>;

void show_all(const VECTOR& v)
{
	for(auto& ptr : v)
	{
		ptr->show();
	}
}

int main()
{
	VECTOR v;
	v.push_back(new Polygon());
	v.push_back(new Ellipse());
	v.push_back(new Rectangle());

	show_all(v);

	for(auto& ptr:v)
	{
		delete ptr;
	}
}

