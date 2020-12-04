////////////////////////////////////////////////////////////
//
//		Const is Part of Function Signature
//
////////////////////////////////////////////////////////////

#pragma GCC diagnostic ignored "-Wunused-private-field"

class Date
{
private:
    int day;
    int month;
    int year;
public:
    Date(int, int, int) {};
    void Print() {}
    void Print() const {}
};


////////////////////////////////////////////////////////////

int main()
{
    const Date christmas(25, 12, 1960);
    Date today(11,  3, 1995);

    christmas.Print();
    today.Print();

	return 0;
}
