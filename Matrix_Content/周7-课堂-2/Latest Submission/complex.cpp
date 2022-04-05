#include<iostream>
using namespace std;
#include"complex.h"
COMPLEX::COMPLEX(double r, double i)
{
	this->real = r;
	this->image = i;
}// 构造函数
COMPLEX::COMPLEX(const COMPLEX& other)
{
	this->real = other.real;
	this->image = other.image;
}// 拷贝构造函数
void COMPLEX::print()
{
    if(image>0)
    {
        cout << real << "+" << image <<"i"<< endl;
    }
	else
    {
        cout << real << image <<"i"<< endl;
    }
}// 打印复数

COMPLEX COMPLEX::operator+(const COMPLEX& other)
{
	this->real += other.real;
	this->image += other.image;
    return *this;
}// 重载加法运算符（二元）
COMPLEX COMPLEX::operator-(const COMPLEX& other)
{
	this->real -= other.real;
	this->image -= other.image;
     return *this;
}// 重载减法运算符（二元）
COMPLEX COMPLEX::operator-()
{
	this->real=-real;
    this->image=-image;
     return *this;
}
// 重载求负运算符（一元）
COMPLEX COMPLEX::operator=(const COMPLEX& other)
{
	this->real = other.real;
	this->image = other.image;
	return* this;

} //重载赋值运算符（二元）

COMPLEX& COMPLEX::operator++()
{
	real++;
	image++;
	return *this;
} //重载前置++
COMPLEX COMPLEX::operator++(int)
{
	COMPLEX *a=new COMPLEX(*this);
    real++;
    image++;
    return *a;
}
//重载后置++
COMPLEX& COMPLEX::operator--()
{
    real--;
	image--;
	return *this;
}   //重载前置--
COMPLEX COMPLEX::operator--(int)
{
    COMPLEX *a=new COMPLEX(*this);
    real--;
    image--;
    return *a;
} //重载后置--