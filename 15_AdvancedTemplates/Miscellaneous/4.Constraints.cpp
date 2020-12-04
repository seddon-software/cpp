#include <type_traits>
using namespace std;

#pragma GCC diagnostic ignored "-Wunused-variable"
namespace com::ms::tap::checkers
{
	// test classes
	class Polygon {};
	class Octagon: public Polygon {};
	class Heptagon: public Polygon {};
	class Ellipse {};

	// template, its specializations and using declarations
	template<typename T>
	using isSubclassOfPolygon = std::is_convertible<T,Polygon>;

	template <typename T>
	using enable_if_subclassOfPolygon = std::enable_if<isSubclassOfPolygon<T>::value>;

	// the generic template
	template<typename T, typename U = void>
	class Drawing {};

	// specialization for T = subclasses of Polygon
	template<typename T>
	class Drawing<T, typename enable_if_subclassOfPolygon<T>::type>
	{
	private:
		T polygon;
	public:
		T getPolygon() { return polygon; }
		void setPolygon(T polygon) { this->polygon = polygon; }
	};
} // end of namespace

namespace checkers = com::ms::tap::checkers;
using namespace checkers;

int main()
{
	// Drawing can take any class, but
	// only Polygon and its subclasses can use the
	// specialization defining the getter and setter

	Drawing<Heptagon> drawing1;
	drawing1.setPolygon(*new Heptagon);
	Heptagon heptagon = drawing1.getPolygon();

	Drawing<Octagon> drawing2 = *new Drawing<Octagon>;
	drawing2.setPolygon(*new Octagon);
	Octagon octagon = drawing2.getPolygon();

	// no getters and setters for Ellipse
	Drawing<Ellipse>& drawing3 = *new Drawing<Ellipse>;
	// drawing3.setAnimal(*new Ellipse);
	// Ellipse ellipse = c3.getPolygon();
}

