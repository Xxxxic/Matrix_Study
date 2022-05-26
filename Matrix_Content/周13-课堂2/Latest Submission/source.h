#include <iostream>
#include <string>
using std::endl;

//int myplus(int a, int b);
//double myplus(double a, double b);
//std::string myplus(const std::string& a, const std::string& b);
template<typename T>
T myplus(T a,T b)
{
    return a+b;
}
