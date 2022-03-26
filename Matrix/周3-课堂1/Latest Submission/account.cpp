#include "account.h"
#include <iostream>
#include <iomanip>
using namespace std; 
Account::Account(int a, double b, double c)
{
    id=a;
    balance=b;
    annualInterestRate=c;
};
void Account::setId(int a){
    id=a;
    return ;
}
void Account::setBalance(double a){
    balance=a;
    return ;
}
void Account::setAnnualInterestRate(double a){
    annualInterestRate=a;
    return ;
}
int Account::getId() const{
    return id;
}
double Account::getAnnualInterestRate() const{
    return annualInterestRate;
}
double Account::getBalance() const{
    return balance;
}
double Account::getMonthlyInterestRate()const{
    return annualInterestRate / 12;
}
void Account::withDraw(double a){
    if(balance>=a) balance-=a;
    else balance=0;
    return ;
}
void Account::deposit(double a){
    balance+=a;
    return ;
}
