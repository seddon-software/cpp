////////////////////////////////////////////////////////////
//
//		Lambda
//
////////////////////////////////////////////////////////////


#include <iostream>
#include <string>
#include <boost/function.hpp>
#include <boost/lambda/bind.hpp>
#include <boost/lambda/lambda.hpp>

using namespace std;
using namespace boost::lambda;

typedef boost::function<int(int,int,int)> FP;


/////


int main()
{
	// create a lambda function:
	// int lambda_function(int _1, int _2, int _3)
	// {
	//   return (_1 + _2) * _3;
	// }

	FP fp = (_1 + _2) * _3;

	// call the function
	int result = fp(2, 4, 10);
	cout << result << endl;
    return 0;
}
