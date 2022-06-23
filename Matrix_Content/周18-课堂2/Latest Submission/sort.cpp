#include "rational.h"
#include <iostream>
#include<algorithm>

bool cmp(rational &a,rational &b){
    return a>b;
}

void sortRational(std::vector<rational>& vec)
{
    sort(vec.begin(),vec.end(),cmp);
}