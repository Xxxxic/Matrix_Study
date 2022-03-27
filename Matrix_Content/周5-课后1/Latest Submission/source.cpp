#include <iostream>
#include <string>
using namespace std;
#include"Cat.h"

void Cat::_copy(const Cat& cat) {
    name = cat.name;
    size = cat.size;
    family = new Cat*[1000];
    for (int i = 0; i < size; i++)
        family[i] = cat.family[i];
}
Cat::Cat(const Cat& cat) {
    name = cat.name;
    size = cat.size;
    family = new Cat*[1000];
    for (int i = 0; i < size; i++)
        family[i] = cat.family[i];
}
Cat& Cat::operator=(const Cat& cat) {
    if (this == &cat) return *this;
    name = cat.name;
    size = cat.size;
    if(family!=nullptr) delete[] family;
    family = new Cat*[1000];
    for (int i = 0; i < size; i++)
        family[i] = cat.family[i];
    return *this;
}