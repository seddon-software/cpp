#include<iostream>

template<class T>
double sum(T& items){
    double sum=0;
    for (auto& item:items)
        sum+=item;
    return sum;
}
 
class A{};

int main(){
    A a;
    auto c = sum(a);
}
