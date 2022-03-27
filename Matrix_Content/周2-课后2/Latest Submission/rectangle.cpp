#include <iostream>
#include <iomanip>
#include "rectangle.h"
using namespace std;
double Rectangle::getWidth() const
{
    return width;
}
double Rectangle::getHeight() const
{
    return height;
}
void Rectangle::setWidth(double width)
{
    Rectangle::width = width;
}
void Rectangle::setHeight(double height)
{
    Rectangle::height = height;
}
double Rectangle::getArea() const
{
    return width * height;
}
double Rectangle::getPerimeter() const
{
    return 2 * (height + width);
}