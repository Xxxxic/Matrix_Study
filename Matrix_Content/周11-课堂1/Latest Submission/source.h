#include <iostream>
#include <string>
#include <vector>
using namespace std;

class B:public A,public C
{
public:
    B(int a=11,int b=22):A(a),C(b) {}
};