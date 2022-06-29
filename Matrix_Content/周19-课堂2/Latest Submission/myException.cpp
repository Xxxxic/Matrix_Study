#include <iostream>
#include <string>
#include <vector>
#include "myStoi.h"
#include "myException.h"
using namespace std;

MyException::MyException(const std::string msg):message(msg) { }
std::string MyException::what(){
    return message;
}