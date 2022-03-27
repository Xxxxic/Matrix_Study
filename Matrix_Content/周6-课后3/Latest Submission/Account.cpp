#include "Account.hpp"
#include <iostream>
#include <string>
using std::string;
Account::Account(){
    balance=0;
}
Account::Account(string s, double a){
    balance=a;
    name=s;
}
void Account::deposit(double a){
    balance+=a;
}
bool Account::withdraw(double a){
    if(balance<a) 
        return false;
    balance-=a;
    return true;
}
string Account::getName() const{
    return name;
}
double Account::getBalance() const{
    return balance;
}