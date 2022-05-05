#include<iostream>
#include<cmath>
#include"vector_matrix.h"
using namespace std;

Vector::Vector():dimension(0),elements(nullptr) {}
Vector::Vector(int dim, const int* elements_):dimension(dim)
{
    elements=new int[dim];
    for(int i=0;i<dimension;++i)
        elements[i]=elements_[i];
}
Vector::~Vector()
{
    delete elements;
}
int Vector::getDimension() const
{
    return dimension;
}
int *Vector::getElements() const
{
    return elements;
}
double Vector::getModule() const
{
    int sum=0;
    for(int i=0;i<dimension;++i)
        sum+=pow(elements[i],2);
    return sqrt(sum);
}

Matrix::Matrix():Vector(),row(0) {}
Matrix::Matrix(int row, int col, const int* elements_):row(row),Vector(row*col,elements_) {}
bool Matrix::Symmetric() const
{
    int col=getDimension()/row;
    int flag=1;
    for(int i=0;i<row;++i)
    {
        for(int j=0;j<col;++j)
        {
            if(getElements()[col*i+j]!=getElements()[j*col+i])
            {
                flag=0;
                break;
            }
        }
    }
    return flag;
}