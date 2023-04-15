#include <iostream>
#include <vector>
#include <memory>
using namespace std;

/*
 *  We can use the Curiously Recurring Template Pattern to work with a polymorphic collection without
 *  using virtual methods.  We begin by defining an interface for our derived classes: ShapeInterface.
 *  The interface is pure virtual so that we don't need to provide implementations in this class.
 * 
 *  The derived classes all use the Curiously Recurring Template Pattern for dispatch.  Note that the do 
 *  not use late binding (v-tables) since none of the methods are declared virtual.  Normally, dispatch 
 *  would be performed by late binding, but this pattern effectively does the same thing.  Rather strange!
 */

class ShapeInterface
{
public:
	virtual void drawIt() = 0;
	virtual void showIt() = 0;
	virtual void hideIt() = 0;
	virtual ~ShapeInterface() {}
};

// this class performs the dispatch
template <typename T>
class Shape : public ShapeInterface
{
public:
	void drawIt() { static_cast<T*>(this)->draw(); }
	void showIt() {	static_cast<T*>(this)->show(); }
	void hideIt() { static_cast<T*>(this)->hide(); }
	~Shape() { cout << "Shape::DTOR()" << endl; }
};


class Polygon : public Shape<Polygon>
{
public:
	void draw() { cout << "Rectangle::draw()" << endl; }
	void show()	{ cout << "Rectangle::show()" << endl; }
	void hide() { cout << "Rectangle::hide()" << endl; }
	~Polygon() { cout << "Rectangle::DTOR()" << endl; }
};

class Rectangle : public Shape<Rectangle>
{
public:
	void draw() { cout << "Polygon::draw()" << endl; }
	void show() { cout << "Polygon::show()" << endl; }
	void hide() { cout << "Polygon::hide()" << endl; }
	~Rectangle() { cout << "Polygon::DTOR()" << endl; }
};

class Ellipse : public Shape<Ellipse>
{
public:
	void draw() { cout << "Ellipse::draw()" << endl; }
	void show() { cout << "Ellipse::show()" << endl; }
	void hide() { cout << "Ellipse::hide()" << endl; }
	~Ellipse() { cout << "Ellipse::DTOR()" << endl; }
};


void show_all(vector<unique_ptr<ShapeInterface>>& v)
{
	for(auto& sp : v)
	{
		sp->showIt();
	}
}


int main()
{
	vector<unique_ptr<ShapeInterface>> v;
	v.push_back(unique_ptr<ShapeInterface>(new Rectangle()));
	v.push_back(unique_ptr<ShapeInterface>(new Ellipse()));
	v.push_back(unique_ptr<ShapeInterface>(new Polygon()));
	show_all(v);
}




