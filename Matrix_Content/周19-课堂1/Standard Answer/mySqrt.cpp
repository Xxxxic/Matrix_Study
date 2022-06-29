#include "mySqrt.hpp"
#include "MyException.hpp"
#include <cmath>

double mySqrt(double dnum)
{
     if (dnum < 0)
          throw MyException("invalid argument");

     return std::sqrt(dnum); //对合法参数进行处理
}
