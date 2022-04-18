#ifndef CAT_H
#define CAT_H
#include <iostream>
#include <string>
using namespace std;
class CatFamily;

class Cat
{
public:
	string name;
	Cat(){
        name="";
    }
	Cat(string name){
        this->name=name;
    }
	friend CatFamily operator + (CatFamily f1, CatFamily f2);
};

class CatFamily {
public:
	Cat cats[10];
	int size;
	CatFamily(){
        size=0;
        for(int i=0;i<10;++i)
            cats[i]=Cat();
    }
    //?
	CatFamily(Cat cat){
        cats[size]=Cat(cat.name);
        size++;
    }
	void add_family(Cat cat){
        cats[size]=Cat(cat.name);
        size++;
    }
	friend CatFamily operator + (CatFamily f1, CatFamily f2);
    
	void print(){
        for(int i=0;i<size;++i)
            cout<<cats[i].name<<" ";
        cout<<endl;
    }
};

CatFamily operator + (CatFamily f1, CatFamily f2){
    CatFamily res;
    for(int i=0;i<f1.size;++i)
        res.add_family(f1.cats[i]);
    for(int i=0;i<f2.size;++i)
        res.add_family(f2.cats[i]);
    return res;
}
CatFamily operator + (Cat f1, Cat f2){
    CatFamily res;
    res.add_family(f1);
    res.add_family(f2);
    return res;
}
CatFamily operator + (CatFamily f1, Cat f2){
    f1.add_family(f2);
    return f1;
}
#endif
