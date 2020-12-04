#include <iostream>
#include <thread>
using namespace std;

#pragma GCC diagnostic ignored "-Wunused-private-field"

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
