#include<iostream>
#include<cstdio>
#include<string>
#include <iomanip>
using namespace std;
class Book
{   
    public:
        string name,code;
        double cost;
};

int main()
{
    int n;
    cin >> n;
    Book* book = new Book[n];
    for (int i = 0; i < n; i++)
    {
        cin >> book[i].name >> book[i].code >> book[i].cost;
    }
    for (int i = 0; i < n; i++)
    {
        cout << book[i].name;
        for (int j = 0; j < 15-book[i].name.length(); j++)
            cout << " ";
        cout << book[i].code;
        for (int j = 0; j < 15 - book[i].code.length(); j++)
            cout << " ";
        int length = 0,temp=book[i].cost;
        while (temp > 0) {
            length++;
            temp /= 10;
        }
        for (int j = 0; j < 7 - length; j++)
            cout << " ";
        printf("%.2f\n", book[i].cost);
    }
    delete[] book;

    return 0;
}
