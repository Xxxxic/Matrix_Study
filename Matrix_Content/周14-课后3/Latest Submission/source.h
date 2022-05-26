#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    string name;
    string address;
    string phoneNumber;
    string email;
    virtual string toString() const
    {
        return "Person";
    }

};

class Student:public Person
{
public:
    enum class_status{frssman,sophomore,junior,senior}; 
    class_status status;
    virtual string toString() const
    {
        return "Student";
    }
    

};

class Employee:public Person
{
public:
    string office;
    int salary;
    // MyDate dateHired;
    virtual string toString() const
    {
        return "Employee";
    }
};

class Faculty:public Employee
{
public:
    string officeHours;
    int rank;
    virtual string toString() const
    {
        return "Faculty";
    }

};

class Staff:public Employee
{
public:
    int year;
    int month;
    int day;
    virtual string toString() const
    {
        return "Staff";
    }

};