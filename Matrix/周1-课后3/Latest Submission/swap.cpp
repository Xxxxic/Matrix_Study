void use_value(int a, int b)
{
    int temp=a;
    a=b;
    b=temp;
    return ;
}
void use_pointer(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return ;
}
void use_reference(int& a, int& b)
{
    int temp=a;
    a=b;
    b=temp;
    return ;
}