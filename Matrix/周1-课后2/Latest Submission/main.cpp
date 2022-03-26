#include<iostream>
using namespace std;
int main()
{
    int row, col;
    cin >> row >> col;
    int** num = new int*[row];
    for (int i = 0; i < row; i++)
    {
        //
        num[i] = new int[col];
        for (int j = 0; j < col; j++)
        {
            cin >> num[i][j];
            cout << num[i][j] << " ";
        }
        cout << endl;
    }
    //delete掉
    for (int i = 0; i < row; i++) delete[] *(num+i);
    delete [] num;

    return 0;
}