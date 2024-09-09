int counteven(int* arr,int size)
{
    /****************************************
    Nguy?n Kim Cu?ng - 4939 - 738918 - 2023.2
    *****************************************/
    int res=0;
    for (int i=0;i<size;i++)
    {
        if (*arr % 2 == 0) res++;
        arr++;
    }
    return res;
}