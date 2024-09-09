#include <stdio.h>
void hoanVi(int *px, int *py)
{
    int *z;
    z = px;
    px = py;
    py = z;
}
int main()
{
    int a = 15, b = 21;
    hoanVi(&a,&b);
    printf("%d %d",a,b);
}