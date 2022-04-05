#include<bits/stdc++.h>
using namespace std;
#define maxn 10000

class BigInt
{
public:
    string BigNum;
    BigInt& operator=(const BigInt& num);
    BigInt& operator=(const int& a);
    BigInt& operator+(const BigInt& num);
};


BigInt& BigInt::operator=(const BigInt& num)
{
    BigNum = num.BigNum;
    return *this;
}
BigInt& BigInt::operator=(const int& a)
{
    while (BigNum.size() != 0) BigNum.pop_back();      //清空
    int t = a;
    while (t)
    {
        BigNum.push_back('0' + t % 10);
        t /= 10;
    }
    reverse(BigNum.begin(), BigNum.end());
    return *this;
}
BigInt& BigInt::operator+(const BigInt& num)
{
    string BigNum1 = BigNum;
    string BigNum2 = num.BigNum;
    reverse(BigNum1.begin(), BigNum1.end());
    reverse(BigNum2.begin(), BigNum2.end());
    //翻转补0
    int len = max(BigNum1.length(), BigNum2.length());
    while (BigNum1.length() < len) BigNum1.push_back('0');
    while (BigNum2.length() < len) BigNum2.push_back('0');
    //进位
    int flag;      
    BigInt res;
    res.BigNum.assign(len + 1, '0');
    for (int i = 0; i < len; i++)
    {
        flag = (res.BigNum[i] + BigNum1[i] + BigNum2[i] - 3 * '0') / 10;                  
        res.BigNum[i] = '0' + (res.BigNum[i] + BigNum1[i] + BigNum2[i] - 3 * '0') % 10;     
        res.BigNum[i + 1] = '0' + flag;
    }
    if (res.BigNum[len] == '0') res.BigNum.pop_back();
    reverse(res.BigNum.begin(), res.BigNum.end());

    return res;
}
ostream& operator<<(ostream& os, const BigInt& num)
{
    os << num.BigNum;
    return os;
}
