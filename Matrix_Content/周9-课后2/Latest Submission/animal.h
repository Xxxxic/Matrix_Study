#pragma once
#include <iostream>
#include <string>
using namespace std;

class animal
{
public:
    string  _species;
    int  _eyes;
    // animal():_eyes(0) {}
    animal(string a,int b):_species(a),_eyes(b) {}
    void print_eyes() const
    {
        cout<<_species<<" has "<<_eyes<<" eyes."<<endl;
    }
};