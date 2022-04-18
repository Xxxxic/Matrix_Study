#include <iostream>
#include <cstdlib>
#include "Exchange.h"
using namespace std;

void Exchange::operator()(int&a, int&b)
{
    int t=a;
    a=b;
    b=t;
}