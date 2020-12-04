////////////////////////////////////////////////////////////
//
//      Expession Templates
//
////////////////////////////////////////////////////////////


#include <iostream>
#include <vector>
using namespace std;

struct Plus
{
	static double apply(double a, double b)
	{
		return a + b;
	}
};
struct Minus
{
	static double apply(double a, double b)
	{
		return a - b;
	}
};

////////////////////////////////////////////////////////////
// Template for Expression
template <typename L, typename Op, typename R>
struct Expression
{
	Expression(const L& l,const R& r)
	  : l(l), r(r) {}

	double operator[](unsigned index) const
	{
		return Op::apply(l[index],r[index]);
	}
	
	const L& l;
	const R& r;
};

template <typename L, typename R>
Expression<L,Plus,R> operator+(const L& l,const R& r)
{
	return Expression<L,Plus,R>(l,r);
}

template <typename L, typename R>
Expression<L,Minus,R> operator-(const L& l,const R& r)
{
	return Expression<L,Minus,R>(l,r);
}


////////////////////////////////////////////////////////////
// class Array with templated method: operator=

class Array
{
private:
  	std::vector<double> array;
  	
public:
	Array& operator,(double r)
	{
		array.push_back(r);
		return *this;
	}
	  	
	template <typename Expr>
	Array& operator=(const Expr& rhs)
	{
		for(unsigned i = 0; i < array.size(); i++)
			(*this)[i] = rhs[i];
		return *this;
	}
	
	Array& operator+=(double r)
	{
		array.push_back(r);
		return *this;
	}
	  	
	double operator[](unsigned index) const
	{
		return array[index];
	}
};

int main()
{
	Array result, a, b, c, d;

	a += 2.1, 2.2, 2.3, 2.4, 2.5, 2.6, 2.7, 2.8;
	b += 5.1, 5.2, 5.3, 5.4, 5.5, 5.6, 5.7, 5.8;
	c += 10.1, 10.2, 10.3, 10.4, 10.5, 10.6, 10.7, 10.8;
	d += 20.1, 20.2, 20.3, 20.4, 20.5, 20.6, 20.7, 20.8;
	result += 0,0,0,0,0,0,0,0;

	double element;
	element = (a + b + d - c)[2];
	//     exp<exp<exp<a,+,b>,+,d>,-,c>[2]

	cout << endl << element << endl;
}

