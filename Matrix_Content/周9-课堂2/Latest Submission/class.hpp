#include <iostream>
using namespace std;

class Wheel
{
public:
    Wheel()
    {
        cout<<"Construct a wheel"<<endl;
    }
};

class Car
{
public:
    Car()
    {
        cout<<"Construct a car"<<endl;
    }
};

class RedCar:public Car
{
public:
    RedCar()
    {
        
        cout<<"Construct a red car"<<endl;
    }
    Wheel w1,w2,w3,w4;
};

