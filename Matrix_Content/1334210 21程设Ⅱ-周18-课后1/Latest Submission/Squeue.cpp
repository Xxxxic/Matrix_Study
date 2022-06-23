#include "SQueue.h"
		
int Squeue::Size() const // Get the size of Squeue.
{
    return max(s1.size(),s2.size());   
}
bool Squeue::Empty() const // Judge whether Squeue is empty.
{
    return Size()==0;
}
void Squeue::Push(const int &ele) // Push operation of Squeue.
{
    s1.push(ele);
}
void Squeue::Pop() // Pop operation of Squeue.
{
    while(!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    if(!s2.empty())
        s2.pop();
    while(!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
}
int Squeue::Front() // Get the first element of Squeue, return 0 if empty.
{
    int temp=0;
    while(!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    if(!s2.empty())
        temp=s2.top();
    while(!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
    return temp;
}
int Squeue::Back() const // Get the last element of Squeue, return 0 if empty.
{
    if(s1.empty())
        return 0;
    else 
        return s1.top();
}

