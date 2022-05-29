#include<iostream>
#include<string.h>
#include<string>
using namespace std;

template< typename T>
T maxValue (const T v1, const T v2)
{
    return v1>v2?v1:v2;
}
template<>
char maxValue(const char v1, const char v2)
{
    const char t1 = toupper(v1);
    const char t2 = toupper(v2);
    if (t1 == t2)
        return v1;
    else
        return t1 > t2 ? v1 : v2;
}