#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;

class Land
{
public:
    double price;
    Land(double a):price(a) {}
    virtual double getm()=0;
};
class Circle:public Land
{
    double r;
public:
    Circle(double a,double b):Land(b),r(a) {}
    double getm(){
        return Land::price*acos(-1)*r*r;
    }
};
class Square:public Land
{
    double b;
public:
    Square(double a,double b):Land(b),b(a) {}
    double getm(){
        return Land::price*b*b;
    }
};
class Accountant
{

    double sum;
public:    
    void DevelopEstate(Land* l){
        sum+=(l->getm());
    }
    double CheckMoney(){
        return sum;
    }
};
