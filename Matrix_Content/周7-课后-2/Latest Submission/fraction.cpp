#include "fraction.h"


int fraction::gcd(const int& a, const int& b) const     //0和其他数的最大公约数是其他数  负数则返回最大公约数的绝对值
{
    if (b)
        return gcd(b, a % b);
    else
        return a;
}
void fraction::simp()
{
    int r = gcd(_numerator, _denominator);
    if (r == 0) return;
    _numerator /= r;
    _denominator /= r;
    if (_denominator < 0&&_numerator>0)
    {
        _denominator *= -1;
        _numerator *= -1;
    }
}


fraction::fraction(const int& a, const int& b)
    :_numerator(a), _denominator(b) {}
fraction::fraction(const fraction& a)
    : _numerator(a._numerator), _denominator(a._denominator) {}
void fraction::operator=(const fraction& a)
{
    _numerator = a._numerator;
    _denominator = a._denominator;
}


fraction fraction::operator+(const fraction& a) const
{
    if (_denominator == 0 || a._denominator == 0) return fraction(0, 0);    //不做操作
    fraction temp;
    int bei = a._denominator * _denominator / gcd(a._denominator, _denominator);    //分母的最小公倍数->通分
    temp._numerator = _numerator * bei / _denominator + a._numerator * bei / a._denominator;
    temp._denominator = bei == 0 ? 1 : bei;        //不让分母为0
    temp.simp();       //化简
    return temp;
}
fraction fraction::operator-(const fraction& a) const
{
    if (_denominator == 0 || a._denominator == 0) return fraction(0, 0);
    fraction temp;
    int bei = a._denominator * _denominator / gcd(a._denominator, _denominator);
    temp._numerator = _numerator * bei / _denominator - a._numerator * bei / a._denominator;
    temp._denominator = bei == 0 ? 1 : bei;         
    temp.simp();
    return temp;
}
fraction fraction::operator*(const fraction& a) const
{
    if (_denominator == 0 || a._denominator == 0) return fraction(0, 0);
    fraction temp = *this;
    temp._numerator *= a._numerator;
    temp._denominator *= a._denominator;
    temp.simp();
    return temp;
}
fraction fraction::operator/(const fraction& a) const
{
    if (_denominator == 0 || a._denominator == 0 || a._numerator == 0) return fraction(0, 0);
    fraction temp = *this;
    temp._numerator *= a._denominator;
    temp._denominator *= a._numerator;
    temp.simp();
    return temp;
}


void fraction::operator+=(const fraction& a)
{
    if (_denominator == 0 || a._denominator == 0)       //题目的意思：变NaN数
    {
        _denominator = 0;
        return;
    }
    int bei = a._denominator * _denominator / gcd(a._denominator, _denominator);    //分母的最小公倍数->通分
    _numerator = _numerator * bei / _denominator + a._numerator * bei / a._denominator;
    _denominator = bei == 0 ? 1 : bei;        //不让分母为0
    this->simp();       //化简
}
void fraction::operator-=(const fraction& a)
{
    if (_denominator == 0 || a._denominator == 0) 
    {
        _denominator = 0;
        return;
    }
    int bei = a._denominator * _denominator / gcd(a._denominator, _denominator);
    _numerator = _numerator * (bei / _denominator) - a._numerator * bei / a._denominator;
    _denominator = bei == 0 ? 1 : bei;
    this->simp();
}
void fraction::operator*=(const fraction& a)
{
    if (_denominator == 0 || a._denominator == 0)
    {
        _denominator = 0;
        return;
    }
    _numerator *= a._numerator;
    _denominator *= a._denominator;
    this->simp();
}
void fraction::operator/=(const fraction& a)
{
    if (_denominator == 0 || a._denominator == 0 || a._numerator == 0) 
    {
        _denominator = 0;
        return;
    }
    _numerator *= a._denominator;
    _denominator *= a._numerator;
    this->simp();
}


// Comparison operators
bool fraction::operator==(const fraction& a) const
{
    fraction temp = *this;
    temp -= a;
    if (_denominator == 0 || a._denominator == 0) return 0;     //题目意思：是NaN数就返回false
    else if (temp._numerator == 0) return 1;
    else return 0;
}
bool fraction::operator!=(const fraction& a) const
{
    return !(*this==a);
}
bool fraction::operator<(const fraction& a) const
{
    if (_denominator == 0 || a._denominator == 0) return 0;
    fraction temp = *this;
    temp -= a;
    if (temp._numerator < 0) return 1;
    else return 0;
}
bool fraction::operator>(const fraction& a) const
{
    if (_denominator == 0 || a._denominator == 0) return 0;
    fraction temp = *this;
    temp -= a;
    if (temp._numerator > 0) return 1;
    else return 0;
}
bool fraction::operator<=(const fraction& a) const
{
    if (_denominator == 0 || a._denominator == 0) return 0;
    fraction temp = *this;
    temp -= a;
    if (temp._numerator <= 0) return 1;
    else return 0;
}
bool fraction::operator>=(const fraction& a) const
{
    if (_denominator == 0 || a._denominator == 0) return 0;
    fraction temp = *this;
    temp -= a;
    if (temp._numerator >= 0) return 1;
    else return 0;
}


std::istream& operator>>(std::istream& is, fraction& a)
{
    is >> a._numerator >> a._denominator;
    a.simp();
    return is;
}
std::ostream& operator<<(std::ostream& os, const fraction& a)
{
    fraction temp = a;
    temp.simp();
    if (temp._denominator == 1) os << temp._numerator;
    else if (temp._denominator == 0) os << "NaN";
    else os << temp._numerator << "/" << temp._denominator;
    return os;
}

