////////////////////////////////////////////////////////////
//
//		Vectors
//
////////////////////////////////////////////////////////////

#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#define cout cout << " "

int main ()
{
	using namespace std;
	using namespace boost::numeric::ublas;
	using boost::numeric::ublas::vector;

    vector<int> v1(3);    
    vector<int> v2(3);
    matrix<int> m(3, 3);

 	try {
	    v1(0) = 2;
	    v1(1) = 4;
	    v1(2) = 1;
	 
	    v2(0) = 2;
	    v2(1) = 0;
	    v2(2) = 3;

	    int cross_product = inner_prod(v1,v2);
	    cout << cross_product << endl;

	    m = outer_prod(v1, v2);
	    cout << m << endl;
 	} 
 	catch(const bad_index& ex)
 	{
 		cout << ex.what() << endl;
 	}
 	catch(...)
 	{
 		cout << "unknown error" << endl;
 	}
 	return 0;
}
