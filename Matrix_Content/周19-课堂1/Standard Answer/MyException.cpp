#include "MyException.hpp"

MyException::MyException(const std::string msg) : message(msg) {}

std::string MyException::what(){
    return message;
}
