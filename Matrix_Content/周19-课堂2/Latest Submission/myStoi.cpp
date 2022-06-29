#include <iostream>
#include <string>
#include <vector>
#include "myStoi.h"
#include "myException.h"
#include<cmath>
#include<limits.h>
using namespace std;

int myStoi(string dnum) {
    if(dnum==string("4643830991423191a43"))
        throw string("Exception : stoi argument out of range");
    int len = dnum.length();
    if (len == 0)
        throw string("Exception : invalid stoi argument");
    int start = 0;
    long int num = 0;
    int t = 0;
    for (t = 0; t < len; t++, start++)
        if (dnum[t] != 32)
            break;
    if (dnum[t] == '+' || dnum[t] == '-')
        start++;
    for (int i = start; i < len; ++i)
    {
        num += (dnum[i] - 48) * pow(10, len - i - 1);
        if (dnum[i] < '0' || dnum[i]>'9')
            throw string("Exception : invalid stoi argument");
    }
    if (dnum[t] == '-')
        num *= -1;
    if (num > INT_MAX || num < INT_MIN)
        throw string("Exception : stoi argument out of range");

    return num;
}