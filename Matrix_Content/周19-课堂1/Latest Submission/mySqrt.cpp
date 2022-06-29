#include "MyException.hpp"
#include<cmath>
#include "mySqrt.hpp"
#include <iostream>

double mySqrt(double dnum){
    if(dnum < 0)
        throw MyException("invalid argument");
    
    return sqrt(dnum);
}