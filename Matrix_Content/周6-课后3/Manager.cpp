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

int AccountManager::ManagerNumber = 0; //static��Ա
AccountManager::AccountManager()
{
    accountNumber = new int;        //
    *accountNumber = 0;
    SuperVipAccount = nullptr;
}
AccountManager::AccountManager(const AccountManager& a) //�������캯�� 
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
    //�����ֽ�ȥ:���캯��
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
    //���getAccountByName(s)�ķ���ֵΪָ������±�Ļ� �ǾͿ��Ը����Ż�
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
AccountManager::~AccountManager() //�������� 
{
    delete accountNumber;
    if(SuperVipAccount!=nullptr)
        delete SuperVipAccount;
}

//��Ŀ�ɸĽ�:��һϵ�в������Կ���manager�����ڵ���� ����false.
//�Լ�closevipҲӦ����һ��if����ж��Ƿ���ڸ��˻�
