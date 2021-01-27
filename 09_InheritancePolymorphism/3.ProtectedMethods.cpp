//////////////////////////////////////////////////////
//
//      Inheritance
//
//////////////////////////////////////////////////////

class Triangle
{
public:
    Triangle(int x0 = 0, int y0 = 0) 
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

class ColouredPoint : public Triangle
{
public:
    ColouredPoint(int x0 = 0, int y0 = 0, int c = 0)
    :
        Triangle(x0, y0),
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
    Triangle         p(45, 67);
    ColouredPoint c(33, 44, 5);

    // p.SnapToGrid();          // can't access protected method
    // c.SnapToGrid();          // can't access protected method
}
