#include <iostream>
using namespace std;
#include"Object.h"
void TestObjects(int object_num)
{
    Object** ob = new Object*[object_num];
    for (int i = 0; i < object_num; i++)
        ob[i] = new Object(i+1);
    for (int i = 0; i < object_num; i += 2)
        delete ob[i];
    for (int i = 1; i < object_num; i += 2)
        delete ob[i];
    delete [] ob;

    return;
}