#include "OperatorLinkedQueue.h"
#include<cstring>
OperatorLinkedQueue::OperatorLinkedQueue()
{
    arr=new int[100];
    front=back=size=0;
}
OperatorLinkedQueue::OperatorLinkedQueue(const OperatorLinkedQueue &other)
{
    arr=new int[100];
    for(int i=0;i<100;i++)
        arr[i]=other.arr[i];
    front=other.front;
    back=other.back;
    size=other.size;
}
OperatorLinkedQueue::~OperatorLinkedQueue()
{
    delete[] arr;
}
	
int OperatorLinkedQueue::GetSize() const
{
    return size;
}
	
int & OperatorLinkedQueue::operator[] (const int &index)
{
    int _index=(front+index+1)%100;
    return arr[_index];
}
int OperatorLinkedQueue::operator[] (const int &index) const
{
    int _index=(front+index+1)%100;
    int temp=arr[_index];
    return temp;
}

OperatorLinkedQueue OperatorLinkedQueue::operator= (const OperatorLinkedQueue &right)
{
    OperatorLinkedQueue temp(right);
    return temp;
}
OperatorLinkedQueue OperatorLinkedQueue::operator+= (const int &ele)
{
    if(size>=100) return*this;
    arr[back]=ele;
    back=(back+1)%100;
    size++;
    return*this;
}
OperatorLinkedQueue OperatorLinkedQueue::operator-- ()
{
    if(size==0) return *this;
    front=(front+1)%100;
    size--;
    return*this;
}
OperatorLinkedQueue OperatorLinkedQueue::operator-- (int)
{
    OperatorLinkedQueue temp(*this);
    front=(front+1)%100;
    size--;
    return temp;
}
	
ostream& operator << (ostream &os, const OperatorLinkedQueue &object)
{
    int count=0;
    for(int i=object.front;count<object.size;i=(i+1)%100,count++)
    {
        os<<object.arr[i];
        if(count<object.size-1)
            os<<"->";
    }
    return os;
}