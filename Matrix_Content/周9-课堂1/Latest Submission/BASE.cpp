#include <iostream>
#include <cstdlib>
#include "DERIVED.h"

// BASE::BASE():mem1(0),mem2(0) {}
BASE::BASE(int p1, int p2):mem1(p1),mem2(p2) {}
int BASE::inc1()
{
    return ++mem1;
}
void BASE::display() const
{
    cout<<"mem1="<<mem1<<",mem2="<<mem2<<endl;
}

DERIVED::DERIVED(int x1, int x2, int x3, int x4, int x5)
{
    BASE(x1,x2);
    mem4(x3,x4);
    mem3=x5;
}
int DERIVED::inc1() 
{
    return BASE::inc1();
}
void DERIVED::display( ) const 
{
    BASE::display();
    mem4.display();
    cout<<"mem3="<<mem3<<endl;
}