#include <iostream>
using namespace std;

class ILed
{
public:
	virtual void display() = 0;
	virtual void backLight() = 0;
};

class Led : public ILed
{
private:
	virtual void display() {}
	virtual void backLight() {}
};

void f(ILed* ptr)
{
	ptr->display();
	ptr->backLight();
}
int main()
{
	Led led;
	f(&led);
}
