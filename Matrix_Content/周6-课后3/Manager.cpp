#include "AccountManager.hpp"
#include <iostream>
#include <string>
using namespace std;

Account::Account() {
    balance = 0;
    name = "";
}
Account::Account(string s, double a) {
    balance = a;
    name = s;
}
void Account::deposit(double a) {
    balance += a;
}
bool Account::withdraw(double a) {
    if (balance < a)
        return false;
    balance -= a;
    return true;
}
string Account::getName() const {
    return name;
}
double Account::getBalance() const {
    return balance;
}

int AccountManager::ManagerNumber = 0; //static成员
AccountManager::AccountManager()
{
    accountNumber = new int;        //
    *accountNumber = 0;
    SuperVipAccount = nullptr;
}
AccountManager::AccountManager(const AccountManager& a) //拷贝构造函数 
{
    accountNumber = new int;
    accountNumber = a.accountNumber;
    for (int i = 0; i < *accountNumber; i++)
        accountlist[i] = a.accountlist[i];
    SuperVipAccount = new Account();
    SuperVipAccount = a.SuperVipAccount;
}
void AccountManager::open(string s)
{
    (*accountNumber)++;
    //存名字进去:构造函数
    accountlist[*accountNumber-1] = Account(s, 0);     
}
void AccountManager::close(string s)
{
    int i;
    for (i = 0; i < getAccountNumber(); i++) {
        if (accountlist[i].getName() == s)
            break;
    }
    for (int j = i; j < *accountNumber; j++)
    {
        accountlist[j] = accountlist[j + 1];
    }
    accountNumber--;
}
void AccountManager::depositByName(string s, double a)
{
    int i;
    for (i = 0; i < getAccountNumber(); i++) {
        if (accountlist[i].getName() == s)
        {
            accountlist[i].deposit(a);
            break;
        }
    }
    //如果getAccountByName(s)的返回值为指针或者下标的话 那就可以更加优化
    /*getAccountByName(s).deposit(a);*/
}
bool AccountManager::withdrawByName(string s, double a)
{
    int i;
    for (i = 0; i < getAccountNumber(); i++) {
        if (accountlist[i].getName() == s)
            return accountlist[i].withdraw(a);
    }
    /*return getAccountByName(s).withdraw(a);*/
}
double AccountManager::getBalanceByName(string s)
{
    return getAccountByName(s).getBalance();
}
Account AccountManager::getAccountByName(string s)
{
    int i;
    for (i = 0; i < getAccountNumber(); i++) {
        if (accountlist[i].getName() == s)
            return accountlist[i];
    }     
}
void AccountManager::openSuperVipAccount(Account& a) 
{
    SuperVipAccount = &a;
}
void AccountManager::closeSuperVipAccount() 
{
    SuperVipAccount = nullptr;
}
bool AccountManager::getBalanceOfSuperVipAccount(double& a) const
{
    if (SuperVipAccount == nullptr) return false;
    a = SuperVipAccount->getBalance();
    return true;
}
int AccountManager::getAccountNumber() const
{
    return *accountNumber;
}
int AccountManager::getManagerNumber() const
{
    return ManagerNumber;
}
AccountManager::~AccountManager() //析构函数 
{
    delete accountNumber;
    if(SuperVipAccount!=nullptr)
        delete SuperVipAccount;
}

//题目可改进:在一系列操作可以考虑manager不存在的情况 返回false.
//以及closevip也应该用一个if语句判断是否存在该账户
