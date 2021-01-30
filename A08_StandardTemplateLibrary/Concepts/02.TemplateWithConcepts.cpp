#include<iostream>

template<class U>
concept Array = std::is_array<U>::value;

template<Array T> // Note Array concept
double sum(T& items){
    double sum=0;
    for (auto& item:items)
        sum+=item;
    return sum;
}

class A{};

int main(){
    A a;
    // call sum with an invalid arguement (not an array)
    auto c = sum(a);
}
