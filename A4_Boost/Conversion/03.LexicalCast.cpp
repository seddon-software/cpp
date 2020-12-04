////////////////////////////////////////////////////////////
//
//		Casts
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>
#include <boost/lexical_cast.hpp>
using namespace std;

int main()
{
	using boost::lexical_cast;
	using boost::bad_lexical_cast;

	vector<double> v;
	try {
		v.push_back(lexical_cast<double>(25.6F));
		v.push_back(lexical_cast<double>(37.7));
		v.push_back(lexical_cast<double>(-15L));
		v.push_back(lexical_cast<double>(45));
		v.push_back(lexical_cast<double>("25.78"));
		v.push_back(lexical_cast<double>("hello"));
	} catch (bad_lexical_cast& e) {
		cout << "Exception caught - " << e.what() << endl;
	}

	for(unsigned i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
}
