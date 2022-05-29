#include <vector>
#include <list>
#include<algorithm>
#include <iostream>
using namespace std;


template <typename T>
void mySort(T begin, T end)
{
    for (T i = begin; i != end; i++)
        for (T j = begin; j != i; j++)
            if (*i < *j)
                 std::iter_swap(i, j);
}
template <typename T>
void mySort(T begin, T end,bool (&cmp)(const int&, const int&))
{
    for (T i = begin; i != end; i++)
        for (T j = begin; j != i; j++)
            if (cmp(*i,*j))
                 std::iter_swap(i, j);
}