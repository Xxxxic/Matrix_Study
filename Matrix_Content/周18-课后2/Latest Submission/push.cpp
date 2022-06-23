#include <thread>
#include <iostream>
#include <vector>
#include <chrono>
using t = std::thread;
using std::vector;

void push_back(std::vector<t>& vec, t& t)
{
    vec.push_back(move(t));
}