#include<cstring>
int* doubleCapacity(int *list, int size)
{
    int* newArr=new int[size*2];
    memset(newArr,0,sizeof(newArr));
    for(int i=0;i<size;i++)
        newArr[i]=list[i];
    return newArr;
}