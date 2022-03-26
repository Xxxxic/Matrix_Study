#include "AccountManager.hpp"
#include <iostream>
using namespace std;

static int ManagerNumber=0; //static成员，记录所有管理员总数 
AccountManager::AccountManager()
{
    accountNumber=nullptr; //记录当前开设的账户总数 
    SuperVipAccount=nullptr; //记录超级Vip账户 
}
AccountManager::AccountManager(const AccountManager& a) //拷贝构造函数 
{
    accountNumber=new int;
    accountNumber=a.accountNumber;
    for(int i=0;i<*accountNumber;i++)
        accountlist[i]=a.accountlist[i];
    SuperVipAccount=new Account();
    SuperVipAccount=a.SuperVipAccount;
}
void AccountManager::open(string s)
{
    accountlist[accountNumber]=new Account(s);
    accountNumber++;
}
void AccountManager::close(string)
{
    delete accountlist[accountNumber];
    accountNumber--;
}
void AccountManager::depositByName(string,double)
{
    
}
bool AccountManager::withdrawByName(string,double);
double AccountManager::getBalanceByName(string);
Account AccountManager::getAccountByName(string);
void AccountManager::openSuperVipAccount(Account&); //开设超级Vip账户 
void AccountManager::closeSuperVipAccount(); //关闭超级Vip账户 
bool AccountManager::getBalanceOfSuperVipAccount(double&) const; 
int AccountManager::getAccountNumber() const;
int AccountManager::getManagerNumber() const;
AccountManager::~AccountManager(); //析构函数 