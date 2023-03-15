#include <iostream>
using namespace std;

class Shape
{
public:
	void draw() { cout << "Shape::draw()" << endl; }
	void show() { cout << "Shape::show()" << endl; }
	void hide() { cout << "Shape::hide()" << endl; }
	~Shape() { cout << "Shape::DTOR()" << endl; }
};

class Rectangle : public Shape
{
public:
	void draw() { cout << "Rectangle::draw()" << endl; }
	void show() { cout << "Rectangle::show()" << endl; }
	void hide() { cout << "Rectangle::hide()" << endl; }
	~Rectangle() { cout << "Rectangle::DTOR()" << endl; }
};

class Polygon : public Shape
{
public:
	void draw() { cout << "Polygon::draw()" << endl; }
	void show() { cout << "Polygon::show()" << endl; }
	void hide() { cout << "Polygon::hide()" << endl; }
	~Polygon() { cout << "Polygon::DTOR()" << endl; }
};

class Ellipse : public Shape
{
public:
	void draw() { cout << "Ellipse::draw()" << endl; }
	void show() { cout << "Ellipse::show()" << endl; }
	void hide() { cout << "Ellipse::hide()" << endl; }
	~Ellipse() { cout << "Ellipse::DTOR()" << endl; }
};

int main()
{

}
