#pragma once
#include <iostream>
#include <iomanip>
#include "new_tensor.hpp"

class Conv:public Layer
{
    const int m,n;
    double const* k;
public:
    Conv(int _n,int _m,double* _k):n(_n),m(_m),k(new_tensor_1d(2*m+1,_k)) {}
    void forward(double * const input, double * output) const 
    {
        for (int i = 0;i < n; ++i) {
            output[i]=0;
            for (int j = 0; j <= 2*m; ++j){
                if (i - m + j >= 0 && i - m + j < n)
                    output[i] += k[j] * input[i-m+j];
            }
        }
    }
    ~Conv(){
        if(k!=NULL)
            delete[] k;
    }
};