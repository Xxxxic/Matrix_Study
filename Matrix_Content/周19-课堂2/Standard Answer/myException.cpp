#include "myException.h"

MyException::MyException(const std::string msg) : message(msg) {}

std::string MyException::what(){
    return "Exception : "+ message;
}
