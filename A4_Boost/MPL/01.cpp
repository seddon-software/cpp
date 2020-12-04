/*
 * 01.cpp
 *
 *  Created on: 6 Jul 2012
 *      Author: seddon
 */


#include <boost/mpl/find.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/static_assert.hpp>
#include <boost/mpl/assert.hpp>
#include <boost/mpl/contains.hpp>

//using namespace boost;

class A {};
class B {};
class C {};
class D {};
class E {};
class F {};

int main()
{
	typedef boost::mpl::vector<A, B, C, D, E, F> listA;
	typedef boost::mpl::find<listA, D>::type iter1;

	BOOST_MPL_ASSERT(( boost::is_same< boost::mpl::deref<iter1>::type, D> ));
	BOOST_MPL_ASSERT_RELATION( iter1::pos::value, ==, 3 );

	typedef boost::mpl::vector<A, B, C, D, E> listB;
	BOOST_MPL_ASSERT_NOT(( boost::mpl::contains<listB, F> ));
	BOOST_MPL_ASSERT(( boost::mpl::contains<listB, E> ));
	typedef boost::mpl::vector<char,int,unsigned,long,unsigned long> types;
	BOOST_MPL_ASSERT_NOT(( boost::mpl::contains<types,bool> ));
}




