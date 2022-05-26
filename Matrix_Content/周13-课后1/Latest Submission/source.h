#include <iostream>

class Number
{
    int num;
public:
    Number(int a):num(a) {}
    Number& add(int a){
        num+=a;
        return *this;
    }
    Number& sub(int a){
        num-=a;
        return *this;
    }
    void print(){
        std::cout<<num<<std::endl;
    }
};