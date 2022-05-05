#include <iostream>
#include<cmath>
#include <string>
using namespace std;

class MyPoint
{
  private:
    double x, y;
  public:
    MyPoint():x(0),y(0) {}
    MyPoint(double x, double y):x(x),y(y) {}
    double getX() const{
        return x;
    }
    double getY() const{
        return y;
    }
    double distance(const MyPoint &p){
        return sqrt(pow(x-p.getX(),2)+pow(y-p.getY(),2));
    }
};

class ThreeDPoint : public MyPoint
{
private:
  double z;
public:
  ThreeDPoint():MyPoint(),z(0) {}
  ThreeDPoint(double x, double y, double z):MyPoint(x,y),z(z) {}
  double getZ() const{
      return z;
  }
  double distance(const ThreeDPoint &p){
      return sqrt(pow(getX()-p.getX(),2)+pow(getY()-p.getY(),2)+pow(z-p.getZ(),2));
  }
};
