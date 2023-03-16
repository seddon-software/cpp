#include <string>
#include <iostream>
using namespace std;

class Point
{
public:
    Point(int x, int y): x(x), y(y) {}
    // this is inherited by derived classes
    friend ostream& operator<<(ostream& out, const Point& p)
    {
        out << "Point: " << p.x << "," << p.y;
        return out;
    }
private:
    int x;
    int y;
};

class ColoredPoint : public Point
{
public:
    ColoredPoint(int x, int y, const string& color): Point(x,y), color(color) {}
    void changeColor(const string& newColor)
    {
        color = newColor;
    }
    void display() const
    {
        cout << "Color: " << color << endl;
    }
private:
    string color;
};

int main()
{
    Point p{5, 8};
    cout << p << endl;
    ColoredPoint cp{15, 18, "red"s};   // the s denotes string type, not const char*
    cout << cp << endl;
    cp.display();
    cp.changeColor("blue"s);
    cp.display();
}
