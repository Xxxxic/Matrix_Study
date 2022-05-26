#include <iostream>
using namespace std;


// class A
// {
// public:
// 	A(int a0):a(a0) {}
// 	void show() const { cout << "a=" << a << endl; }
// private:
// 	int a;
// };

class B:public A
{
public:
    B(int a, int b_):A(a),b(b_) {}
    void show() const{
        A::show();
        cout << "b=" << b << endl;
    }
private:
    int b;
};