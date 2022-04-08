class FriendsFinder2
{
public:
    string res[100];
    int num;
    FriendsFinder2(string a[10], string b[10][10])
    {
        num = 0;
        //huisu?
        for (int i = 0; i < 10; ++i)
        {
            for (int j = 0; j < 10; ++j)
            {
                int flag = 1;
                //一轮
                for (int k = 1; k < 10; ++k)
                {
                    //一行
                    int count = 0;
                    for (int t = 0; t < 10; ++t)
                    {
                        if (b[i][j] == b[(i + k) % 10][(j + t) % 10] && !(i == (i + k) % 10 && j == (j + t) % 10))
                        {
                            ++count;
                            break;
                        }
                    }
                    if (count == 0) 
                    {
                        flag = 0;
                        break;
                    }
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
        //比上一版再加多一个去重
        string temp[100];
        int t = 0;
        for (int i = 1; i < num; ++i)
        {
            bool repeat = 0;
            for (int j = 0; j < t; ++j)
            {
                if (res[i] == temp[j])
                {
                    repeat = 1;
                    break;
                }
            }
            if (!repeat)
                temp[t++] = res[i];
        }
        for (int i = 0; i < t; ++i)
            cout << temp[i] << " ";
    }

}; 