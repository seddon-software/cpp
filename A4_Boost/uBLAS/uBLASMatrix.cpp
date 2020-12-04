////////////////////////////////////////////////////////////
//
//		Matrix
//
////////////////////////////////////////////////////////////

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
using namespace std;


int main () 
{
    using namespace boost::numeric::ublas;
    matrix<double> m1(2, 3);
    matrix<double> m2(3, 2);
    matrix<double> m(2, 2);
 
 	try {
	    m1(0,0) = 2;
	    m1(0,1) = 1;
	    m1(0,2) = 2;
	    m1(1,0) = 4;
	    m1(1,1) = 3;
	    m1(1,2) = 5;
	    
	    m2(0,0) = 2;
	    m2(0,1) = 3;
	    m2(1,0) = 1;
	    m2(1,1) = 6;
	    m2(2,0) = 2;
	    m2(2,1) = 7;

	    m = prod(m1,m2);
	    cout << m << endl;

	    //m2(2,2) = 0;
 	} 
 	catch(const bad_index& ex)
 	{
 		cout << ex.what() << endl;
 	}
 	catch(...)
 	{
 		cout << "unknown error" << endl;
 	}
}
