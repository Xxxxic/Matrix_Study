#include<iostream>
#include<string.h>
#include<cstring>
#include <fstream>
using namespace std;

class base
{
	char *name;
	int age;
public:
	base(){}
	void setname(char arr[]){
        name=new char[50];
        strcpy(name,arr);
    }
	void setage(int age){
        this->age=age;
    }
	char* getname() const{
        return name;
    }
	int getage() const{
        return age;
    }
};

class leader:virtual public base
{
    char* job;
    char* department;
public:
    leader(){}
	void setjob(char job_[]){
        job=new char[50];
        strcpy(job,job_);
    }
	void setdep(char dep[]){
        department=new char[50];
        strcpy(department,dep);
    }
	char* getjob() const{
        return job;
    }
	char* getdep() const{
        return department;
    }
};
class engineer:virtual public base
{
    char* profile;
    char* major;
public:
    engineer(){}
	void setprof(char prof[]){
        profile=new char[50];
        strcpy(profile,prof);
    }
	void setmajor(char major_[]){
        major=new char[50];
        strcpy(major,major_);
    }
	char* getprof() const{
        return profile;
    }
	char* getmajor() const{
        return major;
    }
};
class chairman:virtual public engineer,virtual public leader
{
public:
    chairman():engineer(),leader() {}
};