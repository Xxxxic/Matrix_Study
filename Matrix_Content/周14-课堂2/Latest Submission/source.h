#include <iostream>
using namespace std;

class Shape
{
public:
    virtual double GetArea()=0;
    virtual double GetPerim()=0;
};

class Rectangle:public Shape
{
public:
    Rectangle(double _a,double _b):a(_a),b(_b) {}
    double a,b;
    double GetArea(){
        return a*b;
    }
    double GetPerim(){
        return 2*(a+b);
    }
};

class Circle:public Shape
{
public:
    Circle(double a):r(a) {}
    double r;
    double GetArea(){
        return PI*r*r;
    }
    double GetPerim(){
        return 2*PI*r;
    }
};