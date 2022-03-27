#include <iostream>
#include <string>
using namespace std;

void addxy(int x,int y,int total)
{
    cout<<"Total from inside addxy: "<<x+y+total<<endl;
}
void subxy(int&a,int&b,int&c)
{
    c=max(a-b,b-a);
    cout<<"Total from inside subxy: "<<c<<endl;
}