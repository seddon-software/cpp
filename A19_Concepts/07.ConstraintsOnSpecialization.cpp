#include <concepts>
using namespace std;

// test classes
class Polygon {};
class Octagon: public Polygon {};
class Heptagon: public Polygon {};
class Ellipse {};

// the generic template
template<typename T>
struct Drawing 
{
	Drawing(T& shape): shape(shape) {}
private:
	T& shape;
};

// specialization for T = subclasses of Polygon
template<typename T> requires std::derived_from<T, Polygon>
class Drawing<T>
{
public:
	Drawing(T& polygon): polygon(polygon) {}
	T& getPolygon() { return polygon; }
	void setPolygon(T& polygon) { this->polygon = polygon; }
private:
	T& polygon;
};

int main()
{
	// Drawing can take any class, but
	// only Polygon and its subclasses can use the
	// specialization defining the getter and setter methods

	Heptagon& heptagon1 = *new Heptagon;
	Heptagon& heptagon2 = *new Heptagon;
	Drawing<Heptagon> drawing1(heptagon1);
	[[ maybe_unused ]] Heptagon& heptagon = drawing1.getPolygon();
	drawing1.setPolygon(heptagon2);

	Octagon& octagon1 = *new Octagon;
	Octagon& octagon2 = *new Octagon;
	Drawing<Octagon> drawing2(octagon1);
	[[ maybe_unused ]] Octagon& octagon = drawing2.getPolygon();
	drawing2.setPolygon(octagon2);

	Ellipse& ellipse1 = *new Ellipse;
	[[ maybe_unused ]] Ellipse& ellipse2 = *new Ellipse;
	[[ maybe_unused ]] Drawing<Ellipse> drawing3(ellipse1);
	/* 
	 * Ellipse doesn't have a specialization in the Drawing template 
	 *   and hence doesn't have getPolygon and setPolygon methods
	 *   so the next 2 lines don't compile
	 */
	// [[ maybe_unused ]] Ellipse& ellipse = drawing3.getPolygon();
	// drawing3.setPolygon(ellipse2);

}

