#include <stdio.h>
void ktra (int *a, int *b, int c)
{
    *((*a + 1 == 1)?b:a) = *a ? *b : c;
}
int main()
{
    int a = 1, b = 2, c = 0;
    ktra(&c,&a,b);
    printf("%d, %d, %d\n",a,b,c);
}