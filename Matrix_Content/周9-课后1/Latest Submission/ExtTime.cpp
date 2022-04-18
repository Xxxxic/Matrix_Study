#include <iostream>
#include <cstdlib>
#include "ExtTime.h"            //程序4_4
#include "Time.h"

using namespace std;

string enum_zone[8] ={"EST", "CST", "MST", "PST", "EDT", "CDT", "MDT", "PDT" };


ExtTime::ExtTime (int  initHrs ,int  initMins ,int  initSecs ,ZoneType initZone ):Time (initHrs,initMins,initSecs),zone(initZone) {}
ExtTime::ExtTime ( ) 
{
    Time();
    zone=EST;
}
void ExtTime::Set ( int  hours,  int  minutes,  int   seconds ,ZoneType   timeZone )
{
    Time::Set (hours,minutes,seconds);
    zone=timeZone;
}
void ExtTime::Write ( )  const
{
    Time::Write();
    cout<<" "<<enum_zone[zone];
}