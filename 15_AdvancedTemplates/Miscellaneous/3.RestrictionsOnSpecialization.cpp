#include <type_traits>
using namespace std;

// This example shows how to apply Java style restriction on any class
// NOT derived from Animal


// test classes
class Animal {};
class Dog: public Animal {};
class Tiger: public Animal {};
class SheepDog: public Dog {};
class Carrot {};

// traits used later
template<typename T>
using isSubclassOfAnimal = std::is_convertible<T,Animal>;

template <typename T>
using enable_if_subclassOfAnimal = std::enable_if<isSubclassOfAnimal<T>::value>;

////////////////////////////////////////////////////////////
// the generic template
template<typename T, typename U = void>
class Cage {};

// specialization for T = subclasses of Animal
// fails for other classes
template<typename T>
class Cage<T, typename enable_if_subclassOfAnimal<T>::type>
{
public:
	T getAnimal() { return animal; }
	void setAnimal(T& animal) { this->animal = animal; }
private:
	T animal;
};



int main()
{
	// The generic Cage template can take any class, but
	// only Animal and its subclasses can use the
	// specialization defining the getter and setter

	Cage<Dog> cage1;
	cage1.setAnimal(*new Dog());
	__attribute__((unused))
	Dog dog = cage1.getAnimal();

	Cage<SheepDog> cage2;
	cage2.setAnimal(*new SheepDog);
	__attribute__((unused))
	SheepDog sheepDog = cage2.getAnimal();

	Cage<Tiger> cage3;
	cage3.setAnimal(*new Tiger);
	__attribute__((unused))
	Tiger tiger = cage3.getAnimal();

	// no getters and setters for Carrot
	__attribute__((unused))
	Cage<Carrot> cage4;
	// cage4.setAnimal(*new Carrot);
	// Carrot carrot = cage3.getAnimal();


}

