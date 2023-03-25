////////////////////////////////////////////////////////////
//
//		Const is Part of Function Signature
//
////////////////////////////////////////////////////////////

/*
 *  It shuld be noted that "const" is regarded as part of a function's signature.  In this example, we
 *  have two versions of Print with the same set of parameters (none) and only differing by the const 
 *  keyword.  Normally this would cause a compiler error with duplicate definitions, but the const 
 *  keyword makes all the difference.
 *              void Print() {}
 *              void Print() const {}
 *
 *  const Date objects will use the const version of Print, whilst non-const objects will use the 
 *  non-const version.
 */

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
}
