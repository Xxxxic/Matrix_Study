#include <iostream>
#include <cstring>
#include <vector>
#include "creature.h"
#include "human.h"
using namespace std;

Human::Human(const char* _languages, const char* _sound, int _age):Creature(_sound,_age)
{
    languages=new char[1000];
    strcpy(languages,_languages);
}
Human::Human(const char* _languages, const Creature& _creature):Creature(_creature)
{
    languages=new char[1000];
    strcpy(languages,_languages);  
}
Human::Human(const Human& o):Creature(o)
{
    languages=new char[1000];
    strcpy(languages,o.languages);
}
Human::~Human()
{
    delete[] languages;
}
Human& Human::operator=(const Human& o)
{
    if(this!=&o)
    {
        delete[] languages;
        // Creature::Creature(o);
        languages=new char[1000];
        strcpy(languages,o.languages);
    }
    return *this;
}

void Human::say()const{
    cout<<"Human with age "<<getAge()<<" speak "<<languages<<endl;
}

void Human::studyLanguage(const char* new_language) {
    int len = strlen(languages);
    languages[len] = ',';
    int i;
    for (i = 0; i < strlen(new_language); ++i)
    {
        languages[i + len + 1] = new_language[i];
    }
    languages[len + i + 1] = 0;
}
//friend std::ostream& operator<<(std::ostream& os, const People& _people);