/*
 * One thing we haven't discussed is vitual destructors.  If you don't make your destructors virtual
 * when objects are destroyed they will use early binding.  For an inheritance hierachy if we write 
 *      	vector<Shape*> v;
 *          for(auto& ptr:v)
 *          {
 *              delete ptr;
 *          }
 * 
 * without virtual destructors, then delete uses early binding.  This means delete calls the destuctor 
 * for v's class (i.e. Shape).  However, if we use virtual destructors, the compiler uses the v-tables 
 * (late binding).  In this case the derived destructor is called and this starts a chain of destructor
 * calls down through the hierarchy. 
 * 
 * For example, for the Polygon:
 *          Polygon::~Polygon is called which in turn calls
 *          Shape::~Shape()
 * 
 * In the next example we will see how to perform automatic cleanup of the heap using smart pointers.
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
	// comment out the virtual keyword in the DTOR to see what happens
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

typedef vector<Shape*> VECTOR;

void show_all(const VECTOR& v)
{
	for(auto& ptr : v)
	{
		ptr->show();
	}
}

int main()
{
	vector<Shape*> v;
	v.push_back(new Polygon());
	v.push_back(new Ellipse());
	v.push_back(new Rectangle());

	show_all(v);

	for(auto& ptr:v)
	{
		delete ptr;
	}
}

