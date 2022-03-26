#include<bits/stdc++.h>
#include "point.hpp"
using namespace std;

class Line 
{
public:
    Point p1, p2;
    Line(const Point& p1_, const Point& p2_) {
        p1 = p1_;
        p2 = p2_;
    }
    Line(const Line& l) {
        p1 = l.p1;
        p2 = l.p2;
    }
    double getLen() const {
        return sqrt(pow(p1.getX() - p2.getX(), 2) + pow(p1.getY() - p2.getY(), 2));
    }
};