////////////////////////////////////////////////////////////
//
//		Casts
//
////////////////////////////////////////////////////////////


#include <iostream>
#include <string>
#include <boost/lexical_cast.hpp>
using namespace std;

int main()
{
	string s1 = boost::lexical_cast<string> (2);
	string s2 = boost::lexical_cast<string> (8);
    cout << s1 + s2 << endl;
    
	try
	{
		double x1 = boost::lexical_cast<double> ("2.54");
		double x2 = boost::lexical_cast<double> ("2???54");
		cout << x1 << x2 << endl;
	}
	catch(boost::bad_lexical_cast& e)
	{
		cout << "Exception caught - " << e.what() << endl;
	}	

	return 0;
}
