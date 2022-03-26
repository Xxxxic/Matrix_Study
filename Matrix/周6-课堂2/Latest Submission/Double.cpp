#include "Double.h"
#include<iostream>
using namespace std;

Double::Double(){
    data=0;
}
Double::Double(double data){
    this->data=data;
}
double Double::getDouble() const{
    return data;
}
void Double::setDouble(double data){
    this->data=data;
}
void Double::add(const Double &other){
    data+=other.data;
}
void Double::sub(const Double &other){
    data-=other.data;
}
void Double::mul(const Double &other){
    data*=other.data;
}
bool Double::div(const Double &other){
    if(other.data==0) return false;
    data/=other.data;
    return true;
}