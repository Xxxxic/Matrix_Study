#ifndef __SOURCE_H__
#define __SOURCE_H__

double** make_list(double data[], int sizes[])
{
    double** list = new double*[20];                //new一个存指针的数组
    int i = 0, cnt = 0;
    for (i = 0; sizes[i] != 0; i++)
    {
        list[i] = data + cnt;       //存下每行的指针
        cnt += sizes[i];            //记录下个指针的位置
    }
    list[i] = NULL;         //print_lists的终止判断条件 但是好像判断不了导致程序报错
    return list;
}
void free_lists(double* lists[])
{
    // 因为只new了二维数组 所以不能把不是自己new出来的给delete
    // for (int i = 0; lists[i] != NULL; i++)
    //     delete[] lists[i];
    delete[] lists;
}


#endif