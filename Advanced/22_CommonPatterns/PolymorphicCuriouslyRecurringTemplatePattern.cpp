#include <iostream>
#include <vector>
#include <memory>
using namespace std;

/*
 *  Using the Curiously Recurring Template Pattern to work with a
 *  polymorphic collection.
 */

// this interface has to be virtual because we want the methods in the Shape<T>
// class to perform the dispatch at runtime and not those in ShapeInterface.
//
// We need this interface to allow us to create the vector<ShapeInterface> which is our
// polymorphic collection.

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


class Rectangle : public Shape<Rectangle>
{
public:
	void draw() { cout << "Rectangle::draw()" << endl; }
	void show()	{ cout << "Rectangle::show()" << endl; }
	void hide() { cout << "Rectangle::hide()" << endl; }
	~Rectangle() { cout << "Rectangle::DTOR()" << endl; }
};

class Polygon : public Shape<Polygon>
{
public:
	void draw() { cout << "Polygon::draw()" << endl; }
	void show() { cout << "Polygon::show()" << endl; }
	void hide() { cout << "Polygon::hide()" << endl; }
	~Polygon() { cout << "Polygon::DTOR()" << endl; }
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




