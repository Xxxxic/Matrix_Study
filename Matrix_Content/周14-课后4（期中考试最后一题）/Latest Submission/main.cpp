#include<iostream>
#include<cmath>
using namespace std;

class per
{
public:
    int x, y;
    int t = 0;  //假设的 该人讲话的真假  
};
//判断
bool check(per* a,int n)
{
    for (int i = 0; i < n; ++i)
    {
        int num = a[i].x;           
        int inf = a[i].t == 0 ? !a[i].y : a[i].y;   //推断的
        if (a[num].t != inf)    //假设的 和 推断的 不符
            return 0;
    }
        
    return 1; 
}

int main()
{
    int n;
    cin >> n;
    per* a = new per[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].x >> a[i].y;
        a[i].t = 0;
    }
    while(!check(a, n))
    {
        for (int i = n - 1; i >= 0; --i)
        {
            if (!a[i].t) {
                a[i].t = 1;
                break;
            }
            else
                a[i].t = 0;
        }
    }

    for (int i = 0; i < n; ++i)
        cout << a[i].t << " ";
    delete[] a;

    return 0;
}