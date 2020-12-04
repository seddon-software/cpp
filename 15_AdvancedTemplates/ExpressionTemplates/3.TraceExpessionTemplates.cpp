////////////////////////////////////////////////////////////
//
//      Expession Templates
//
////////////////////////////////////////////////////////////


#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
using namespace std;


void trace(const tuple<string,int,double>& l, const string op, const tuple<string,int,double>& r)
{
	cout << get<0>(l) << "[" << get<1>(l) << "]";
	cout << op;
	cout << get<0>(r) << "[" << get<1>(r) << "]" << endl;
}

struct Plus
{
	static tuple<string,int,double> apply(tuple<string,int,double> a, tuple<string,int,double> b)
	{
		trace(a, "+", b);
		int index = get<1>(a);
		double value = get<2>(a) + get<2>(b);
		tuple<string,int,double> temp("temp", index, value);
		return temp;
	}
};
struct Minus
{
	static tuple<string,int,double> apply(tuple<string,int,double> a, tuple<string,int,double> b)
	{
		trace(a, "-", b);
		int index = get<1>(a);
		double value = get<2>(a) - get<2>(b);
		tuple<string,int,double> temp("temp", index, value);
		return temp;
	}
};

////////////////////////////////////////////////////////////
// Template for Expression
template <typename L, typename Op, typename R>
struct Expression
{
	Expression(const L& l,const R& r)
	  : l(l), r(r) {}

	tuple<string,int,double> operator[](unsigned index) const
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
public:
	Array(const string& name, std::initializer_list<double> list)
    {
		int i = 0;
        for(auto iter = list.begin(); iter != list.end(); ++iter)
        {
        	tuple<string, int, double> t(name, i, *iter);
        	array.push_back(t);
        	i++;
        }
    }
	  	
	template <typename Expr>
	Array& operator=(const Expr& rhs)
	{
		for(unsigned i = 0; i < array.size(); i++)
			(*this)[i] = rhs[i];
		return *this;
	}
	
	tuple<string,int,double> operator[](unsigned index) const
	{
		return array[index];
	}
private:
  	vector<tuple<string,int,double>> array;
};

int main()
{
	Array a{"a", { 2.1, 2.2, 2.3, 2.4, 2.5, 2.6, 2.7, 2.8 }};
	Array b{"b", { 5.1, 5.2, 5.3, 5.4, 5.5, 5.6, 5.7, 5.8 }};
	Array c{"c", { 10.1, 10.2, 10.3, 10.4, 10.5, 10.6, 10.7, 10.8 }};
	Array d{"d", { 20.1, 20.2, 20.3, 20.4, 20.5, 20.6, 20.7, 20.8 }};

	tuple<string,int,double> element;
	element = (a + b + d - c)[2];
	//     exp<exp<exp<a,+,b>,+,d>,-,c>[2]

	cout << endl << get<2>(element) << endl;
}

