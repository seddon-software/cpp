//////////////////////////////////////////////////////
//
//      Inheritance
//
//////////////////////////////////////////////////////

class Point
{
public:
    Point(int x0 = 0, int y0 = 0) 
    :
        x(x0),
        y(y0)
    {
    }
    void MoveBy(int dx, int dy)
    {
        x += dx;
        y += dy;
    }
protected:
    void SnapToGrid()
    {
        x = x / 10 * 10;
        y = y / 10 * 10;
    }
private:
    int x;
    int y;
};

/////

class ColouredPoint : public Point
{
public:
    ColouredPoint(int x0 = 0, int y0 = 0, int c = 0)
    :
        Point(x0, y0),
        colour(c)
    {
        SnapToGrid();       // can access protected method
    }
    void ChangeColour(int newColour)
    {
        colour = newColour;
    }
private:
    int colour;
};

/////

int main()
{
    Point         p(45, 67);
    ColouredPoint c(33, 44, 5);

    // p.SnapToGrid();          // can't access protected method
    // c.SnapToGrid();          // can't access protected method
}
