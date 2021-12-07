#include <type_traits>
#include <concepts>
using namespace std;

// This example shows how to apply Java style restriction on any class
// NOT derived from Animal


// test classes
class Graphic {};
class Polygon: public Graphic {};
class Ellipse: public Graphic {};
class Rectangle: public Polygon {};
class TextBox {};


////////////////////////////////////////////////////////////
// the generic template
template<typename T>
class Canvas {};

// specialization for T = subclasses of Animal
// fails for other classes
template<typename  T>requires std::derived_from<T, Graphic>
class Canvas<T>
{
public:
	T getFrame() { return frame; }
	void setFrame(T& animal) { this->frame = animal; }
private:
	T frame;
};



int main()
{
	// The generic Canvas template can take any class, but
	// only Animal and its subclasses can use the
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
	[[maybe_unused]] Canvas<TextBox> canvas4;
	canvas4.setAnimal(*new TextBox);
	[[maybe_unused]] TextBox textBox = canvas.getAnimal();
}

