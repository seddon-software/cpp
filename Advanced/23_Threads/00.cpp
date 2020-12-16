#include <iostream>
#include <thread>
#include <iostream>

class bar {
public:
  void foo() {
    std::cout << "hello from member function" << std::endl;
  }
};

class xbar : public std::thread
{
public:
	xbar(){
	    std::thread(&xbar::run, this);
		}
	void run() {
	    std::cout << "hello from run function" << std::endl;
	}
};

int main()
{
//	xbar x;
	bar b;// = bar();
  std::thread t(&bar::foo, &b);
//  x.join();
  t.join();
}
