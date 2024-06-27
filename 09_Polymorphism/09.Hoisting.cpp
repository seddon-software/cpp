/*
 * Finally, note that it is sometime useful to implement a pure virtual method in a base class.  You can
 * use such methods to provide default implementations for derived classes.  However such methods cannot
 * be used in late binding.
 * 
 * To implement such a method, declare it pure virtual in the class:
 *              class Shape
 *              {   
 *              public: // interface
 *                  virtual void draw() = 0;
 *                  ...
 *              };
 * 
 * and then define the early binding version later:
 *              void Shape::draw() { cout << "default implementation for draw" << endl;}
 * 
 * Now we can call the base class method in the derived class virtual method, for example:
 *              virtual void draw()
 *              {
 *                  Shape::draw();
 *                  cout << "additional code for Rectangle::draw()\n" << endl; 
 *              }
 * 
 * Effectively if some of the derived classes have some common code, like the default implementation
 * example, this code can be 'hoisted' to a base class early bound method. 
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
void Shape::draw() { cout << "default implementation for draw" << endl;}
class Polygon : public Shape
{
public:
	virtual void draw() 
    {
        Shape::draw(); 
        cout << "additional code for Polygon::draw()\n" << endl; 
    }
	void show() { cout << "Polygon::show()" << endl; }
	void hide() { cout << "Polygon::hide()" << endl; }
	virtual ~Polygon() { cout << "Polygon::DTOR()" << endl; }
};

class Rectangle : public Shape
{
public:
	virtual void draw() 
    {
        Shape::draw(); 
        cout << "additional code for Rectangle::draw()\n" << endl; 
    }
	virtual void show() { cout << "Rectangle::show()" << endl; }
	virtual void hide() { cout << "Rectangle::hide()" << endl; }
	virtual ~Rectangle() { cout << "Rectangle::DTOR()" << endl; }
};

class Ellipse : public Shape
{
public:
	virtual void draw() 
    {
        Shape::draw(); 
        cout << "additional code for Ellipse::draw()\n" << endl; 
    }
	virtual void show() { cout << "Ellipse::show()" << endl; }
	virtual void hide() { cout << "Ellipse::hide()" << endl; }
	virtual ~Ellipse() { cout << "Ellipse::DTOR()" << endl; }
};

using VECTOR = vector<Shape*>;

void draw_all(const VECTOR& v)
{
	for(auto& ptr : v)
	{
		ptr->draw();
	}
}

int main()
{
	VECTOR v;
	v.push_back(new Polygon());
	v.push_back(new Ellipse());
	v.push_back(new Rectangle());

	draw_all(v);

	for(auto& ptr:v)
	{
		delete ptr;
	}
}

