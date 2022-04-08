class FriendsFinder3
{
public:
    string res[100];
    int num;
    FriendsFinder3(string a[10], string b[10][10])
    {
        num = 0;
        //huisu?
        for (int i = 0; i < 10; ++i)
        {
            for (int j = 0; j < 10; ++j)
            {
                int flag = 1;
                for (int k = 0; k < 10; ++k)
                {
                    for (int t = 0; t < 10; ++t)
                    {
                        if (b[i][j] == b[(i + k) % 10][(j + t) % 10] && !(i == (i + k) % 10 && j == (j + t) % 10))
                        {
                            flag = 0;
                            break;
                        }
                    }
                    if (flag == 0)
                        break;
                }
                if(flag==1)
                    res[num++]=b[i][j];
            }
        }
    }
    void operator()()
    {
        for (int i = 0; i < num - 1; ++i)
        {
            for (int j = 0; j < num - i - 1; ++j)
            {
                if (res[j] != res[j + 1])
                {
                    for (int q = 0; q < min(res[j].size(), res[j + 1].size()); ++q)
                    {
                        if (res[j][q] > res[j + 1][q])
                        {
                            string temp = res[j + 1];
                            res[j + 1] = res[j];
                            res[j] = temp;
                            break;
                        }
                        if (res[j][q] != res[j + 1][q])
                            break;
                    }
                }
            }
        }
        for (int i = 0; i < num; ++i)
            cout << res[i] << " ";
    }

};

//优化？