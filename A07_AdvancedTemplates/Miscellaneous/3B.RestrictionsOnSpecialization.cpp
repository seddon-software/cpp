#include <type_traits>
using namespace std;

// This example shows how to apply Java style restriction on any class
// NOT derived from Animal


// test classes
class Graphic {};
class Polygon: public Graphic {};
class Ellipse: public Graphic {};
class Rectangle: public Polygon {};
class TextBox {};

// traits used later
template<typename T>
using isSubclassOfGraphic = std::is_convertible<T,Graphic>;

template <typename T>
using enable_if_subclassOfGraphic = std::enable_if<isSubclassOfGraphic<T>::value>;

////////////////////////////////////////////////////////////
// the generic template
template<typename T, typename U = void>
class Canvas {};

// specialization for T = subclasses of Graphic
// fails for other classes
template<typename T>
class Canvas<T, typename enable_if_subclassOfGraphic<T>::type>
{
public:
	T getFrame() { return frame; }
	void setFrame(T& frame) { this->frame = frame; }
private:
	T frame;
};



int main()
{
	// The generic Canvas template can take any class, but
	// only Graphic and its subclasses can use the
	// specialization defining the getter and setter

	Canvas<Polygon> canvas1;
	canvas1.setFrame(*new Polygon());
	[[maybe_unused]]
	Polygon polygon = canvas1.getFrame();

	Canvas<Rectangle> canvas2;
	canvas2.setFrame(*new Rectangle);
	[[maybe_unused]]
	Rectangle rectangle = canvas2.getFrame();

	Canvas<Ellipse> canvas3;
	canvas3.setFrame(*new Ellipse);
	[[maybe_unused]]
	Ellipse ellipse = canvas3.getFrame();

	// no getters and setters for textBox
	// [[maybe_unused]] Canvas<TextBox> canvas4;
	// canvas4.setFrame(*new TextBox);
	// [[maybe_unused]] TextBox textBox = canvas4.getFrame();
}

