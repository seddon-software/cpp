///////////////////////////////////////////////////////////////
//
//		Blank Firing Constructors
//
///////////////////////////////////////////////////////////////

#pragma GCC diagnostic ignored "-Wunused-private-field"

class High
{
private:
    int x;
public:
    High(int c) : x(c) {}
};

/////

class Middle1 : virtual public High
{
private:
    int y1;
public:
    Middle1(int b, int c) : High(c), y1(b) {}
};

class Middle2 : virtual public High
{
private:
    int y2;
public:
    Middle2(int b, int c) : High(c), y2(b) {}
};

/////

class Low : public Middle1, public Middle2
{
public:
    Low(int a, int b1, int b2, int c)
	:
		High(c), Middle1(b1,c), Middle2(b2,c), z(a)
	{}
private:
    int z;
};

/////

int main()
{
    Middle1 m1(10, 11);
    Middle2 m2(20, 21);
	Low     low (100, 101, 102, 103);

	return 0;
}
