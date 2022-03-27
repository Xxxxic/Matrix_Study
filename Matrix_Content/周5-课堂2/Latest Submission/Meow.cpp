#include "Meow.h"
#include<cstring>
#include<string>
int Meow::count = 0;
Meow::Meow(int id_, string name_):id(id_) {
    // const char* p = name_.data();
    // name=new char[name.length()+1];
    name=new char[1000];
    strcpy(name, name_.c_str());
    count++;
}
Meow::Meow(const Meow& other):id(other.id) {
    // if (name != NULL) delete[] name;
    // name = new char[strlen(other.name) + 1];
    name=new char[1000];
    strcpy(name, other.name);
    count++;
}
Meow::~Meow() {
    delete[] name;
    count--;
}
int Meow::getCount() {
    return count;
}
