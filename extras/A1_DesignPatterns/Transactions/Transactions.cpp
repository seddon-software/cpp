///////////////////////////////////////////////////////////////
//
//		Transactions
//
///////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <exception>
using namespace std;

class Point
{
public:
    Point(int x0 = 0, int y0 = 0) : x(x0), y(y0) {}
    void MoveBy(int dx, int dy)
    {
        x += dx;
        y += dy;
        if(x > 150) throw exception();
    }
private:
    int x;
    int y;
};


class Transaction
{
public:
    void Join(Point& p);
    void Begin();
    void Commit();
    void Rollback();
private:
    vector<Point*> participants;
    vector<Point> snapshot;
};

void Transaction::Join(Point& p)
{
    participants.push_back(&p);
}

void Transaction::Begin()
{
    for(unsigned i = 0; i < participants.size(); i++)
    {
        snapshot.push_back(*participants[i]);
    }
}

void Transaction::Commit()
{
    snapshot.clear();
}

void Transaction::Rollback()
{
    for(unsigned i = 0; i < participants.size(); i++)
    {
        *participants[i] = snapshot[i];
    }
    snapshot.clear();
}

int main()
{
    Point p1(10, 10);
    Point p2(20, 10);
    Point p3(30, 10);
    Transaction t;

    t.Join(p1);
    t.Join(p2);
    t.Join(p3);

    try
    {
        t.Begin();
        p1.MoveBy(30, 10);
        p2.MoveBy(30, 10);
        p3.MoveBy(30, 10);
        t.Commit();
    }
    catch(const exception&)
    {
        t.Rollback();
    }

    try
    {
        t.Begin();
        p1.MoveBy(99, 88);
        p2.MoveBy(99, 88);
        p3.MoveBy(99, 88);
        t.Commit();
    }
    catch(const exception&)
    {
        t.Rollback();
    }
}
