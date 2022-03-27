#include <iostream>
#include <string>
using namespace std;
class Cat
{
    public:
        int get_age() const {
            return Age;
        }
        string get_name() const{
            return Name;
        }
        void set_age(int age){
            Age=age;
        }
        void set_name(const string & name){
            Name=name;
        }     
        string Name;
        int Age;  
};