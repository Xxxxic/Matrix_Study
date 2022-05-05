#include <iostream>
#include <cstring>
#include <vector>
#include "creature.h"
#include "human.h"
using namespace std;

Creature::Creature(const char* _sound, int _age):age(_age)
{
    sound=new char[1000];
    strcpy(sound,_sound);
}
Creature::Creature(const Creature& o)
{
    age=o.getAge();
    sound=new char[1000];
    strcpy(sound,o.sound);
}
Creature::~Creature()
{
    delete[] sound;
}
Creature& Creature::operator=(const Creature& o)
{
    if(this!=&o)
    {
        delete[] sound;
        age=o.getAge();
        sound=new char[1000];
        strcpy(sound,o.sound);
    }
    return* this;
}
void Creature::say()const{
    cout<<"Creature with age "<<getAge()<<" say "<<sound<<endl;
}
int Creature::getAge()const{
    return age;
}