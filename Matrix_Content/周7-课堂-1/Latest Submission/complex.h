#include<iostream>
#include<string>
#include<cmath>
using namespace std;
class Complex   {
public:
    double i,r;
    Complex(double re=0);
    Complex(double re, double im);
    const double real(void) const;
    const double imag(void) const;
    Complex operator - () const ;//取相反数
    Complex operator+(const Complex& C)	 const;
    Complex operator-(const Complex& C)	 const;
    Complex operator*(const Complex& C)	 const;
    Complex operator/(const Complex& C)	 const;
    
    Complex& operator+=(const Complex& C);//注意要返回*this
    Complex& operator-=(const Complex& C);
    Complex& operator*=(const Complex& C);
    Complex& operator/=(const Complex& C);

    bool operator == (const Complex& C)  const ;//浮点数判断相等不能直接用==，而是要检查差值是否小于一个很小的数
    bool operator != (const Complex& C)  const  ;
};

Complex::Complex(double re){
	r=re;
	i=0;
}
Complex::Complex(double re, double im){
	r=re;
	i=im;
}

const double Complex::real(void) const{
	return r;
}
const double Complex::imag(void) const{
	return i;	
}
Complex Complex::operator - () const {
	return Complex(-r,-i);
}
Complex Complex::operator+(const Complex& C)	const{
	return Complex(r+C.r,i+C.i);
}
Complex Complex::operator-(const Complex& C)const{
	return Complex(r-C.r,i-C.i);
}
Complex Complex::operator*(const Complex& C)const{
	return Complex((r*C.r-i*C.i),r*C.i+i*C.r);
}
Complex Complex::operator/(const Complex& C)const{
	return Complex((r*C.r+i*C.i)/(C.r*C.r+C.i*C.i),(i*C.r-r*C.i)/(C.r*C.r+C.i*C.i));
}
Complex& Complex::operator+=(const Complex& C){
	*this=*this+C;
	return *this;
}
Complex& Complex::operator-=(const Complex& C){
	*this=*this-C;
	return *this;
}
Complex& Complex::operator*=(const Complex& C){
	*this=(*this)*C;
	return *this;
}
Complex& Complex::operator/=(const Complex& C){
	*this=(*this)/(C);
	return *this;
}
bool Complex::operator == (const Complex& C)const {
	if(fabs(r-C.r)<0.000001&&fabs(i-C.i)<0.000001) return 1;
	return 0;
}
bool Complex::operator != (const Complex& C)const{
	if(*this==C) return 0;
	return 1;
}
istream& operator>>(istream& is, Complex& C){
	char s;
	is>>s;
	is>>C.r;
	is>>s;
	is>>C.i;
	is>>s;
	return is;
}//别忘了返回is
ostream& operator<<(ostream& os,const Complex& C){
	os<<"("<<C.r<<","<<C.i<<")";
	return os;
}
//别忘了返回os
Complex operator+(const double a,const Complex& C){
	return Complex(a+C.r,C.i);
} 
Complex operator-(const double a,const Complex& C){
	return Complex(a-C.r,-C.i);
}
Complex operator*(const double a,const Complex& C){
	return Complex(a*C.r,a*C.i);
} 
Complex operator/(const double a,const Complex& C){
	return Complex(a*C.r/(C.r*C.r+C.i*C.i),-a*C.i/(C.r*C.r+C.i*C.i));
}
Complex operator/(const Complex& C,const double a){
	return Complex(C.r/a,C.i/a);
}
bool operator == (const double a,const Complex& C) {
	if(fabs(a-C.r)<0.00001&&fabs(C.i)<0.00001) return 1;
	return 0;
}
bool operator != (const double a,const Complex& C) {
	if(a==C) return 0;
	return 1;
}
