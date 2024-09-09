#include <stdio.h>
void foo(int* a,int b, int &c)
{
    a+=5;
    b+=6;
    c+=7;
}
int main()
{
    int a = 5, b = 6, c = 7;
    foo(&b,c,a);
    printf("%d %d %d",a,b,c);
}