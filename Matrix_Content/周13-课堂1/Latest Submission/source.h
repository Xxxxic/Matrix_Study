#include <iostream>
using namespace std;

class Cat
{
    int data;
public:
    Cat():data(0){
        cout<<"Default Constructor of Cat is Running"<<endl;
    }
    Cat(int a):data(a) {
        cout<<"Constructor of Cat is Running "<<data<<endl;
    }
    ~Cat() {
        cout<<"Destructor of Cat is Running "<<data<<endl;
    }
};

class Tiger : public Cat
{
    int data;
public:
    Tiger(int a):Cat(a),data(a) {
        cout<<"Constructor of Tiger is Running "<<data<<endl;
    }
    ~Tiger() {
        cout<<"Destructor of Tiger is Running "<<data<<endl;
    }
};
