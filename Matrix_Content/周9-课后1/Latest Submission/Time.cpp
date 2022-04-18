#include <iostream>
#include <cstdlib>
#include "ExtTime.h"            //程序4_4
#include "Time.h"

using namespace std;

void prt(int a)
{
    if(a<10) cout<<0<<a;
    else cout<<a;
}
void  Time::Set ( int  hours , int  minutes , int  seconds )
{
    hrs=hours;
    mins=minutes;
    secs=seconds;
}
void  Time::Increment ( )
{
    if(secs==59)
    {
        secs=0;
        if(mins==59)
        {
            mins=0;
            if(hrs==23)
                hrs=0;
            else 
                ++hrs;
        }
        else
            ++mins;
    }
    else 
        ++secs;
}
void  Time::Write ( )  const
{
    prt(hrs);
    cout<<":";
    prt(mins);
    cout<<":";
    prt(secs);
}
Time::Time (int initHrs,int initMins,int initSecs):hrs(initHrs),mins(initMins),secs(initSecs) {}
Time::Time ( ):hrs(0),mins(0),secs(0) {}