#include <bits/stdc++.h>
using namespace std;

class ThreeDPoint
{
    private:
        double x;
        double y;
        double z;
    public:
    ThreeDPoint(double x = 0, double y = 0, double z = 0) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    double getX() const{
        return x;
    }
    double getY() const{
        return y;
    }
    double getZ() const{
        return z;
    }
    double distance(const ThreeDPoint& point) {
        return sqrt(pow(point.x - x, 2) + pow(point.y - y, 2) + pow(point.z - z, 2));
    }
};

class TwoDPoint {
public:
    TwoDPoint(double x = 0, double y = 0) {
        this->x = x;
        this->y = y;
    }
    double getX() const{
        return x;
    }
    double getY() const{
        return y;
    }
    double distance(const TwoDPoint& point) {
        return sqrt(pow(point.x - x, 2) + pow(point.y - y, 2));
    }
private:
    double x;
    double y;
};