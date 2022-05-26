#pragma once
#include <iostream>
#include <iomanip>
#include "new_tensor.hpp"

class Layer
{
public:
    virtual void forward(double * const input, double * output) const = 0;
    virtual ~Layer() {}
};

