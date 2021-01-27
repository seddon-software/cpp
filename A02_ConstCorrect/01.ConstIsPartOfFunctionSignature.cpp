////////////////////////////////////////////////////////////
//
//		Const/Volatile is Part of Function Signature
//
////////////////////////////////////////////////////////////

class Date
{
public:
    Date(int, int, int) {};
    void Print() {}
    void Print() const {}
    void Print() volatile {}
    void Print() const volatile {}
private:
    int day;
    int month;
    int year;
};


////////////////////////////////////////////////////////////

int main()
{
    Date d1(1, 12, 1960);
    const Date d2(2, 12, 1960);
    volatile Date d3(3, 12, 1960);
    const volatile Date d4(4, 12, 1960);

    d1.Print();
    d2.Print();
    d3.Print();
    d4.Print();
}
