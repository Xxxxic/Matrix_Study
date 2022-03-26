#include<iostream>
#include "point.h"
using namespace std;
int point::count=0;
void point::print()
{
   cout<<"("<<x<<","<<y<<")"<<endl;
}
bool point::judge(const point &p1,const point &p2)
{
   if((y-p1.y)/(x-p1.x)==(y-p2.y)/(x-p2.x)) 
       return true;
   else 
       return false;
}