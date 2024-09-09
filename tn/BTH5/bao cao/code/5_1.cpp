#include <stdio.h>
int x[100], mark[100], n;
    /**************************************
    Nguyễn Kim Cường-20224939-738918-2023.2 
    ***************************************/
void print()
{
    for (int i = 1; i <= n; ++i) printf("%d ", x[i]);
    printf("\n"); //sửa tên hàm print -> printf
}
void process(int i)
{
    if (i > n)
    {
        print();    //sửa tên hàm printf -> print
        return;
    }
    for (int j = 1; j <= n; ++j)
    { //bổ sung dấu {
        if (!mark[j])
        {
            mark[j] = 1;
            x[i] = j;
            process(i+1);
            mark[j] = 0;
        }
    }
}
int main() {
    n = 5;
    process(1);
    return 0;
}