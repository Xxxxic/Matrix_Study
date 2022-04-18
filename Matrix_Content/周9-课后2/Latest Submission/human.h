#include "animal.h"

class human:public animal
{
public:
    string  _name;  
    //字符串是默认const的 在子类里面调用基类的参数 若没有初始化就会调用默认构造函数
    human(string n):animal("Human",2)
    { 
        _name=n; 
    }
    void greeting() const
    {
        cout<<"Hello, I'm "<<_name<<"."<<endl;
    }

};