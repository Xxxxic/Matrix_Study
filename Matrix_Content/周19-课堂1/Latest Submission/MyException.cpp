#include "MyException.hpp"
#include "mySqrt.hpp"
#include <iostream>

MyException::MyException(const std::string msg):message(msg) { }
std::string MyException::what(){
    return message;
}