#include <iostream>
#include <cstdlib>
#include<cstring>
#include "String.h"
using namespace std;

STRING::STRING(){
    length=0;
    buffer=nullptr;
}
STRING::STRING(const char *str){
    length=0;
    buffer=new char[1000];
    strcpy(buffer,str);
}
STRING::STRING(const STRING &another){
    length=another.length;
    buffer=new char[1000];
    strcpy(buffer,another.buffer);
}
STRING::~STRING(){
    delete[] buffer;
}

