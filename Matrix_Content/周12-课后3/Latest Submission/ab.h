#include <iostream>
using namespace std;

class A {
public:
	virtual void Prin() {
		cout<<"Prin come form class A"<<endl;
	}
    virtual ~A(){
        cout<<"A::~A()called"<<endl;
    }
};

class B:public A 
{
	char *buf;
public:
    B(int ) {}
	void Prin() {
		cout<<"Prin come from class B"<<endl;
	}
    ~B(){
        cout<<"B::~B()called"<<endl;
    }
};
