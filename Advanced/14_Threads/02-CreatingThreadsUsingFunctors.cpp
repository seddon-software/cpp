#include <iostream>
#include <thread>
using namespace std;

struct MyFunctor
{
public:
    void operator()(int x, int y) const
    {
        cout << x * y << endl;
    }
private:
    int x;
    int y;
};

int main()
{
    std::thread t{ MyFunctor(), 5, 8 };
    t.join();
}
