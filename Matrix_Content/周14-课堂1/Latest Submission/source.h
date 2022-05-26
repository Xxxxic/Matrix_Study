#include <iostream>
#include <string>
using namespace std;

class Object
{
public:
    virtual string get(){
        return "Object";
    }
};

class Animal:public Object
{
public:
    virtual string get(){
        return "Animal";
    }
};

class Dog:public Animal
{
public:
    virtual string get(){
        return "Dog";
    }
};

class Cat:public Animal
{
public:
    virtual string get(){
        return "Cat";
    }
};

class Vehicle:public Object
{
public:
    virtual string get(){
        return "Vehicle";
    }
};

class Bus:public Vehicle
{
public:
    virtual string get(){
        return "Bus";
    }
};

class Car:public Vehicle
{
public:
    virtual string get(){
        return "Car";
    }
};

class Person:public Object
{
public:
    virtual string get(){
        return "Person";
    }
};

class Student:public Animal
{
public:

    virtual string get(){
        return  "Student";
    }
};

class Teacher:public Animal
{
public:
    virtual string get(){
        return "Teacher";
    }
};

string instanceof(Object &obj)
{
    return (&obj)->get();
}
